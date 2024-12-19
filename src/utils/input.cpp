/*
Created by: Emily (Em_iIy) Winnink
Created on: 18/12/2024
*/

#include "input.hpp"
#include "gl/Key.hpp"


namespace input {
	void	process(GLFWwindow *window)
	{
		static Key esc(window, GLFW_KEY_ESCAPE);

		esc.update();

		if (esc.is_pressed())
		{
			glfwSetWindowShouldClose(window, true);
		}
	}
};