/*
Created by: Emily (Em_iIy) Winnink
Created on: 18/12/2024
*/

#include <iostream>
#include <cmath>

#include "input.hpp"
#include "Config.hpp"
#include "gl/Key.hpp"

#include "emlm/emlm.hpp"

extern bool			g_pause;
extern float		mass;
extern Config		config;

extern mlm::vec3	color1;
extern mlm::vec3	color2;

mlm::vec3	rand_vec3();

static void	print_colors()
{
	std::cout << "color1 = mlm::vec3(" << color1.x << "f, " << color1.y << "f, " << color1.z << "f);" << std::endl;
	std::cout << "color2 = mlm::vec3(" << color2.x << "f, " << color2.y << "f, " << color2.z << "f);" << std::endl;
}

namespace input {
	void	process(GLFWwindow *window)
	{
		static Key esc(window, GLFW_KEY_ESCAPE);
		static Key tab(window, GLFW_KEY_TAB);
		static Key space(window, GLFW_KEY_SPACE);
		static Key c(window, GLFW_KEY_C);
		static Key c1(window, GLFW_KEY_1);
		static Key c2(window, GLFW_KEY_2);


		esc.update();
		tab.update();
		space.update();
		c.update();
		c1.update();
		c2.update();

		if (esc.is_pressed())
		{
			glfwSetWindowShouldClose(window, true);
			std::cout << "Goodbye!" << std::endl;
			print_colors();
		}
		if (tab.is_pressed())
		{
			if (mass < 0.1f)
				mass = *(config.gravity_mass);
			else
				mass = 0.0000001f;
		}
		if (space.is_pressed())
		{
			g_pause = !g_pause;
		}
		if (c.is_pressed())
		{
			color1 = rand_vec3();
			color2 = rand_vec3();
			// print_colors();
		}
		if (c1.is_pressed())
		{
			color1 = rand_vec3();
			// print_colors();
		}
		if (c2.is_pressed())
		{
			color2 = rand_vec3();
			// print_colors();
		}
	}
};