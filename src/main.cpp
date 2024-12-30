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
// #define WIDTH 3840
// #define HEIGHT 2160
#define WIDTH 1024
#define HEIGHT 1024
#define TEXTURE_WIDTH WIDTH
#define TEXTURE_HEIGHT HEIGHT
#define FOV 60.0f

#define PARTICLE_COUNT 3048576
// #define PARTICLE_COUNT 2000
// #define PARTICLE_COUNT 15
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
		physics.set_vec3("gravity", mlm::vec3(0.2f * sinf(time * 20.0f), 0.3f, 0.2f));
		// physics.set_vec3("gravity", mlm::vec3(0.2f * sinf(time * 2.0f), 0.3f, 0.2f * cosf(time * 2.0f)));
		physics.set_float("delta_time", g_delta_time * 2);
		glDispatchCompute((GLuint)PARTICLE_COUNT / 16, 1, 1);
		glMemoryBarrier(GL_VERTEX_ATTRIB_ARRAY_BARRIER_BIT);

		mlm::mat4	model(1.0f);
		model = mlm::translate(model, mlm::vec3(0.0f, 0.0f, -5.0f));
		particle_shader.use();
		mlm::mat4 projection = mlm::perspective(mlm::radians(FOV), WIDTH / HEIGHT, 0.1f, 100.0f);
		particle_shader.set_mat4("model", model);
		particle_shader.set_mat4("projection", projection);
		particle_shader.set_vec3("gravity", mlm::vec3(0.2f * sinf(time * 2.0f), 0.3f, 0.2f * cosf(time * 2.0f)));
		particle_vao.bind();
		glDrawArrays(GL_POINTS, 0, PARTICLE_COUNT);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}
}

