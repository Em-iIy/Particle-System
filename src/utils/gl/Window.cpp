/*
Created by: Emily (Em_iIy) Winnink
Created on: 16/12/2024
*/

#include <GLAD/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

void	init_glfw(void)
{
	if (!glfwInit())
	{
		std::cerr << "Glfw init error" << std::endl;
		exit(EXIT_FAILURE);
	}
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif
}

GLFWwindow	*init_window(int *width, int *height, const char *title, GLFWmonitor *monitor, GLFWwindow *share)
{
	int x, y;
	GLFWwindow	*window = glfwCreateWindow(*width, *height, title, monitor, share);
	if (!window)
	{
		std::cerr << "Glfw window error" << std::endl;
		glfwTerminate();
		exit(EXIT_FAILURE);
	}
	glfwMakeContextCurrent(window);
	if (!gladLoadGL())
	{
		std::cerr << "Glad couldn't load GL" << std::endl;
		glfwTerminate();
		glfwDestroyWindow(window);
		exit(EXIT_FAILURE);
	}
	// glfwGetFramebufferSize(window, width, height);
	// std::cout << *width << " " << *height << std::endl;
	// glfwGetWindowSize(window, width, height);
	// std::cout << *width << " " << *height << std::endl;

	glViewport(0, 0, *width, *height);

	glfwSwapInterval(0);

	return (window);
}

GLFWwindow	*init_fullscreen_window(const char *title)
{
	GLFWmonitor *monitor = glfwGetPrimaryMonitor();
	const GLFWvidmode *vid_mode = glfwGetVideoMode(monitor);
	GLFWwindow	*window = glfwCreateWindow(vid_mode->width, vid_mode->height, title, monitor, NULL);
	if (!window)
	{
		std::cerr << "Glfw window error" << std::endl;
		glfwTerminate();
		exit(EXIT_FAILURE);
	}
	glfwMakeContextCurrent(window);
	if (!gladLoadGL())
	{
		std::cerr << "Glad couldn't load GL" << std::endl;
		glfwTerminate();
		glfwDestroyWindow(window);
		exit(EXIT_FAILURE);
	}
	glViewport(0, 0, vid_mode->width, vid_mode->height);
	return (window);
}