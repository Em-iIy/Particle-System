// /*
// Created by: Emily (Em_iIy) Winnink
// Created on: 16/12/2024
// */

#include "utils.hpp"
#include "emlm/emlm.hpp"
#include <cmath>
#include <ctime>

// #define WIDTH 1920
// #define HEIGHT 1080
#define WIDTH 1024
#define HEIGHT 1024
#define TEXTURE_WIDTH WIDTH
#define TEXTURE_HEIGHT HEIGHT
#define FOV 90.0f

#define PARTICLE_COUNT 3048576
// #define PARTICLE_COUNT 2000
float		g_delta_time = 0.0f;

void APIENTRY glDebugOutput(GLenum source, GLenum type, GLuint id, GLenum severity,
                            GLsizei length, const GLchar* message, const void* userParam) {
    std::cerr << "GL CALLBACK: " << message << std::endl;
}


int main(int argc, char **argv)
{
	srand(std::time(NULL));
	if (argc != 2)
		return (1);
	init_glfw();
	GLFWwindow *window = init_window(WIDTH, HEIGHT, "particle-system", NULL, NULL);

	uint	random = (uint)((float)rand() / 2147483647.0f * 10000.0f);
    // Enable OpenGL debug output
    glEnable(GL_DEBUG_OUTPUT);
    glDebugMessageCallback(glDebugOutput, nullptr);

	GLfloat	vertices[] = {
		1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
		-1.0f, 1.0f, 1.0f, 0.0f, 1.0f,
		1.0f, -1.0f, 1.0f, 1.0f, 0.0f,
		-1.0f, -1.0f, 1.0f, 0.0f, 0.0f
	};

	GLuint indices[] = {
		0, 1, 3,
		0, 2, 3
	};


	VAO particle_vao(1);
	particle_vao.bind();
	SSBO ssbo(NULL, sizeof(mlm::vec4) * 2 * PARTICLE_COUNT, GL_DYNAMIC_DRAW);
	particle_vao.link_attr_ssbo(ssbo, 0, 4, GL_FLOAT, sizeof(GLfloat) * 8, (void *)0);
	particle_vao.link_attr_ssbo(ssbo, 1, 4, GL_FLOAT, sizeof(GLfloat) * 8, (void *)(sizeof(GLfloat) * 4));
	particle_vao.unbind();


	// VAO	vao(1);
	// vao.bind();
	// VBO	vbo(vertices, sizeof(vertices));
	// EBO	ebo(indices, sizeof(indices));
	// vao.link_attr(vbo, 0, 3, GL_FLOAT, sizeof(GLfloat) * 5, (void *)0);
	// vao.link_attr(vbo, 1, 2, GL_FLOAT, sizeof(GLfloat) * 5, (void *)(sizeof(GLfloat) * 3));
	// vao.unbind();
	// vbo.unbind();



	ComputeShader	comp_shader(argv[1]);
	Shader			shader("resources/shaders/default.vert", "resources/shaders/default.frag");
	ComputeShader	init_sphere("resources/shaders/sphere_init.comp");
	ComputeShader	physics("resources/shaders/physics.comp");
	Shader			particle_shader("resources/shaders/particle.vert", "resources/shaders/particle.frag");

	init_sphere.use();
	ssbo.bind();
	init_sphere.set_float("radius", 0.5f);
	init_sphere.set_uint("frame", random);
	glDispatchCompute((GLuint)PARTICLE_COUNT / 16, 1, 1);
	glMemoryBarrier(GL_VERTEX_ATTRIB_ARRAY_BARRIER_BIT);

	// GLuint texture;
	// glGenTextures(1, &texture);
	// glActiveTexture(GL_TEXTURE0);
	// glBindTexture(GL_TEXTURE_2D, texture);
	// glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	// glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	// glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	// glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	// glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA32F, TEXTURE_WIDTH, TEXTURE_HEIGHT, 0, GL_RGBA, GL_FLOAT, NULL);

	// glBindImageTexture(0, texture, 0, GL_FALSE, 0, GL_READ_ONLY, GL_RGBA32F);

	// timing 
	int fCounter = 0;
	float ftime = 0.0f;

	while (!glfwWindowShouldClose(window))
	{
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		float time = glfwGetTime();
		input::process(window);
		g_delta_time = delta_time_update();
		if(fCounter > 500) {
				std::cout << "FPS: " << 1 / (ftime / fCounter) << " " << random << std::endl;
				fCounter = 0;
				ftime = 0.0f;
		} else {
			fCounter++;
			ftime += g_delta_time;
		}	
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		physics.use();
		ssbo.bind();
		physics.set_vec3("gravity", mlm::vec3(0.2f * sinf(time * 2.0f), 0.3f, 0.2f * cosf(time * 2.0f)));
		physics.set_float("delta_time", g_delta_time);
		glDispatchCompute((GLuint)PARTICLE_COUNT / 16, 1, 1);
		glMemoryBarrier(GL_VERTEX_ATTRIB_ARRAY_BARRIER_BIT);
		// comp_shader.use();
		// comp_shader.set_float("fov", FOV);
		// comp_shader.set_vec3("light", mlm::vec3(10.0f * sinf(time * 2.0f), 5.0f, -10.0f + 10.0f * cosf(time * 2.0f)));
		// comp_shader.set_vec3("sphere_c", mlm::vec3(0.0f, 0.0f, -10.0f));
		// comp_shader.set_vec3("sphere_c", mlm::vec3(2.0f * sinf(time), 1.0f * sinf(time * 2.0f), -10.0f + 2.0f * cosf(time)));
		// glDispatchCompute((GLuint)TEXTURE_WIDTH / 16, (GLuint)TEXTURE_HEIGHT / 16, 1);
		// shader.use();
		// glActiveTexture(GL_TEXTURE0);
		// glBindTexture(GL_TEXTURE_2D, texture);
		// vao.bind();
		// glMemoryBarrier(GL_SHADER_IMAGE_ACCESS_BARRIER_BIT);
		// glDrawElements(GL_TRIANGLES, sizeof(indices), GL_UNSIGNED_INT, NULL);

		mlm::mat4	model(1.0f);
		// model = mlm::rotate(model, mlm::radians(10.0f * time), mlm::vec3(1.0, 0.0, 0.0));
		model = mlm::translate(model, mlm::vec3(0.0f, 0.0f, -10.0f));
		particle_shader.use();
		mlm::mat4 projection = mlm::perspective(mlm::radians(FOV), WIDTH / HEIGHT, 0.1f, 100.0f);
		particle_shader.set_mat4("model", model);
		particle_shader.set_mat4("projection", projection);
		particle_shader.set_vec3("gravity", mlm::vec3(0.2f * sinf(time * 2.0f), 0.3f, 0.2f * cosf(time * 2.0f)));
		particle_vao.bind();
		// glDrawArraysInstanced(GL_POINTS, 0, 1, PARTICLE_COUNT);
		glDrawArrays(GL_POINTS, 0, PARTICLE_COUNT);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}
}

