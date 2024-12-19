/*
Created by: Emily (Em_iIy) Winnink
Created on: 16/12/2024
*/

#include "utils.hpp"

#define WIDTH 1000
#define HEIGHT 1000
#define TEXTURE_WIDTH 1000
#define TEXTURE_HEIGHT 1000

float		g_delta_time = 0.0f;

// int	main(int argc, char **argv)
// {
// 	if (argc != 3)
// 	{
// 		std::cerr << "Invalid input!\n";
// 		std::cerr << "Usage:\n";
// 		std::cerr << "scop -c,--config <config file>\n";
// 		std::cerr << "scop <object file> <texture file>" << std::endl;
// 		return (1);
// 	}
// 	try
// 	{

// 		if (std::string(argv[1]) == "-c" || std::string(argv[1]) == "--config")
// 			Config::load(argv[2]);
// 		else
// 			Config::load(argv[1], argv[2]);
// 		scop.init_gl(WIDTH, HEIGHT);
// 		scop.init_resources();
// 		print_controls();

// 		glGenFramebuffers(1, &fbo);
// 		glBindFramebuffer(GL_FRAMEBUFFER, fbo);
	
// 		init_render_texture(rtex);
// 		glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, rtex, 0);

// 		glGenRenderbuffers(1, &rbo);
// 		glBindRenderbuffer(GL_RENDERBUFFER, rbo);
// 		glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH24_STENCIL8, WIDTH, HEIGHT);
// 		glBindRenderbuffer(GL_RENDERBUFFER, 0);
// 		glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, GL_RENDERBUFFER, rbo);


// 		if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE)
// 		{
// 			std::cerr << "Frame buffer incomplete!" << std::endl;
// 			throw std::exception();
// 		}
// 		glBindFramebuffer(GL_FRAMEBUFFER, 0);
// 		while (!glfwWindowShouldClose(scop.window))
// 		{
// 			scop.update();
// 			scop.draw_current();
// 		}
// 		clean();
// 	}
// 	catch(const std::exception& e)
// 	{
// 		clean();
// 		return (1);
// 	}
// 	return (0);
// }

int main(int argc, char **argv)
{
	if (argc != 2)
		return (1);
	init_glfw();
	GLFWwindow *window = init_window(800, 600, "particle-system", NULL, NULL);


	GLfloat	vertices[] = {
		1.0f, 1.0f, 0.0f, 1.0f, 1.0f,
		-1.0f, 1.0f, 0.0f, 0.0f, 1.0f,
		1.0f, -1.0f, 0.0f, 1.0f, 0.0f,
		-1.0f, -1.0f, 0.0f, 0.0f, 0.0f
	};

	GLuint indices[] = {
		0, 1, 3,
		0, 2, 3
	};

	VAO	vao(1);
	vao.bind();
	VBO	vbo(vertices, sizeof(vertices));
	EBO	ebo(indices, sizeof(indices));
	vao.link_attr(vbo, 0, 3, GL_FLOAT, sizeof(GLfloat) * 5, (void *)0);
	vao.link_attr(vbo, 1, 2, GL_FLOAT, sizeof(GLfloat) * 5, (void *)(sizeof(GLfloat) * 3));
	vao.unbind();
	vbo.unbind();

	ComputeShader	comp_shader(argv[1]);
	Shader			shader("resources/shaders/default.vert", "resources/shaders/default.frag");

	GLuint texture;
	glGenTextures(1, &texture);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, texture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA32F, TEXTURE_WIDTH, TEXTURE_HEIGHT, 0, GL_RGBA, GL_FLOAT, NULL);

	glBindImageTexture(0, texture, 0, GL_FALSE, 0, GL_READ_ONLY, GL_RGBA32F);

	glMemoryBarrier(GL_SHADER_IMAGE_ACCESS_BARRIER_BIT);

	// timing 
	float deltaTime = 0.0f; // time between current frame and last frame
	float lastFrame = 0.0f; // time of last frame
	int fCounter = 0;
	float ftime = 0.0f;

	// Set frame time

	while (!glfwWindowShouldClose(window))
	{
		float currentFrame = glfwGetTime();
		input::process(window);
		deltaTime = currentFrame - lastFrame;
		lastFrame = currentFrame;
		if(fCounter > 500) {
				std::cout << "FPS: " << 1 / deltaTime << "\t";
				std::cout << "FPS: " << 1 / (ftime / fCounter) << std::endl;
				fCounter = 0;
				ftime = 0.0f;
		} else {
			fCounter++;
			ftime += deltaTime;
		}	
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		comp_shader.use();
		comp_shader.set_float("t", currentFrame);
		glDispatchCompute((GLuint)TEXTURE_WIDTH/10, (GLuint)TEXTURE_HEIGHT/10, 1);
		shader.use();
		vao.bind();
		glDrawElements(GL_TRIANGLES, sizeof(indices), GL_UNSIGNED_INT, NULL);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}
}
