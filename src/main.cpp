/*
Created by: Emily (Em_iIy) Winnink
Created on: 16/12/2024
*/

#include "utils.hpp"
#include "emlm/emlm.hpp"
#include <cmath>
#include <ctime>

// #define WIDTH 1920
// #define HEIGHT 1080
#define WIDTH 3840
#define HEIGHT 2160
#define FOV 100.0f

#define PARTICLE_COUNT 1048576
// #define PARTICLE_COUNT 2000

#define VIEW_BOX_DIMENSIONS 100.0f

#define SPEED 15.0f

#define RADIUS 20.0f

float		g_delta_time = 0.0f;
float		g_pause = 1.0f;
GLuint		fbo;
GLuint		rbo;
GLuint		rtex;
int width = WIDTH;
int height = HEIGHT;

mlm::vec3 color1;
mlm::vec3 color2;

void APIENTRY glDebugOutput(GLenum source, GLenum type, GLuint id, GLenum severity,
                            GLsizei length, const GLchar* message, const void* userParam) {
    std::cerr << "GL CALLBACK: " << message << std::endl;
}

mlm::vec3	rand_vec3()
{
	return (mlm::vec3(rand() / 2147483648.0f, rand() / 2147483648.0f, rand() / 2147483648.0f));
}

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

int main(int argc, char **argv)
{
	srand(std::time(NULL));
	init_glfw();
	// GLFWwindow *window = init_window(&width, &height, "particle-system", NULL, NULL);
	GLFWwindow *window = init_fullscreen_window("test");
	// return (1);
	uint	random = (uint)((float)rand() / 2147483647.0f * 10000.0f);
    // Enable OpenGL debug output
    // glEnable(GL_DEBUG_OUTPUT);
    // glDebugMessageCallback(glDebugOutput, nullptr);

	color1 = mlm::vec3(1.0f, 0.0f, 0.1f);
	color2 = mlm::vec3(1.0f, 1.0f, 0.0f);

	VAO quad_vao(1);
	quad_vao.bind();
	VBO quad_vbo(vertices, sizeof(vertices));
	quad_vao.link_attr(quad_vbo, 0, 3, GL_FLOAT, sizeof(GLfloat) * 5, (void *)0);
	quad_vao.link_attr(quad_vbo, 1, 2, GL_FLOAT, sizeof(GLfloat) * 5, (void *)(sizeof(GLfloat) * 3));
	quad_vao.unbind();

	VAO particle_vao(1);
	particle_vao.bind();
	SSBO ssbo(NULL, sizeof(mlm::vec4) * 2 * PARTICLE_COUNT, GL_DYNAMIC_DRAW);
	particle_vao.link_attr_ssbo(ssbo, 0, 3, GL_FLOAT, sizeof(GLfloat) * 8, (void *)0);
	particle_vao.link_attr_ssbo(ssbo, 1, 3, GL_FLOAT, sizeof(GLfloat) * 8, (void *)(sizeof(GLfloat) * 4));
	particle_vao.unbind();

	// ComputeShader	init_sphere("resources/shaders/cube_init.comp");
	ComputeShader	init_sphere("resources/shaders/sphere_init.comp");
	ComputeShader	physics("resources/shaders/physics.comp");
	Shader			particle_shader("resources/shaders/particle.vert", "resources/shaders/particle.frag");
	// Shader			quad_shader("resources/shaders/quad.vert", "resources/shaders/postprocessing/quad.frag");
	Shader			quad_shader("resources/shaders/quad.vert", "resources/shaders/postprocessing/edge_detection.frag");
	// Shader			quad_shader("resources/shaders/quad.vert", "resources/shaders/postprocessing/chromatic_abberation.frag");
	// Shader			quad_shader("resources/shaders/quad.vert", "resources/shaders/postprocessing/blur.frag");
	init_sphere.use();
	ssbo.bind();
	init_sphere.set_float("radius", RADIUS);
	init_sphere.set_uint("frame", random);
	glDispatchCompute((GLuint)PARTICLE_COUNT / 16, 1, 1);
	glMemoryBarrier(GL_VERTEX_ATTRIB_ARRAY_BARRIER_BIT);

	int		fCounter = 0;
	float	ftime = 0.0f;
	float	run_time = 0.0f;

	FrameBuffer bla;
	bla.generate(width, height);

	glPointSize(1);
	while (!glfwWindowShouldClose(window))
	{
		// Bind to the frame buffer
		bla.bind();
		glEnable(GL_DEPTH_TEST);

		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		float	speed = SPEED;
		float time = glfwGetTime();
		mlm::vec3 gravity;
		input::process(window);
		g_delta_time = delta_time_update();
		if(fCounter > 500) {
				std::cout << "FPS: " << 1 / (ftime / fCounter) << std::endl;
				fCounter = 0;
				ftime = 0.0f;
		} else {
			fCounter++;
			ftime += g_delta_time;
		}	

		if (g_pause > 0.1f)
		{
			run_time += g_delta_time * speed;
			gravity = mlm::vec3(20.0f * sinf(run_time * .2f), 20.0f * cosf(run_time * .2f), -50.0f);
			gravity += (rand_vec3() * 2 - 1.0f) * 0.5f;
		}

		physics.use();
		ssbo.bind();
		physics.set_vec3("gravity", gravity);
		physics.set_float("delta_time", g_delta_time * speed);
		if (g_pause > 0.1f)
			glDispatchCompute((GLuint)PARTICLE_COUNT / 16, 1, 1);
		glMemoryBarrier(GL_VERTEX_ATTRIB_ARRAY_BARRIER_BIT);


		mlm::mat4	model(1.0f);
		model = mlm::translate(model, mlm::vec3(0.0f, 0.0f, -25.0f));
		particle_shader.use();
		mlm::mat4	projection = mlm::perspective(mlm::radians(FOV), (float)width / (float)height, 0.1f, 2.0f * VIEW_BOX_DIMENSIONS);
		mlm::mat4	view(1.0f);
		particle_shader.set_float("time", std::abs(sinf(time)));
		particle_shader.set_float("dimensions", VIEW_BOX_DIMENSIONS);
		particle_shader.set_mat4("model", model);
		particle_shader.set_mat4("view", view);
		particle_shader.set_mat4("projection", projection);
		particle_shader.set_vec3("gravity", gravity);
		particle_shader.set_vec3("color1", color1);
		particle_shader.set_vec3("color2", color2);
		particle_vao.bind();
		// glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		// glDrawArrays(GL_TRIANGLE_STRIP, 0, PARTICLE_COUNT);
		// glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		glDrawArrays(GL_POINTS, 0, PARTICLE_COUNT);

		bla.unbind();
		glDisable(GL_DEPTH_TEST);

		glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		quad_shader.use();

		bla.render_texture.bind();
		quad_vao.bind();
		glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}
}
