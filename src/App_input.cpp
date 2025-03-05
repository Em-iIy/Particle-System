/*
Created by: Emily (Em_iIy) Winnink
Created on: 3/3/2025
*/
#include "App.hpp"
#include <cmath>

mlm::vec2 mouse_coords;

/*
//	Prints color1 and color2 in the format for the config file for reuse
*/
static void	print_colors(mlm::vec3 &color1, mlm::vec3 &color2)
{
	std::cout << "color1 " << color1.x << " " << color1.y << " " << color1.z << std::endl;
	std::cout << "color2 " << color2.x << " " << color2.y << " " << color2.z << std::endl;
}

/*
//	Updates mouse postion on cursor movement
*/
void	cursor_position_callback(GLFWwindow *window, double x_pos, double y_pos)
{
	(void)window; // haha funny
	mouse_coords.x = x_pos;
	mouse_coords.y = y_pos;
}

/*
//	Translates pixel coords to world coords at half the depth of the viewbox
*/
mlm::vec3	App::mouse_to_screen()
{
	float		world_z;
	mlm::vec2	half;
	mlm::vec2	ndc;
	mlm::vec2	world;

	world_z = -0.5f * this->settings.view_box_dimensions;

	half.y = tan(mlm::radians(this->settings.fov) / 2.0f) * fabs(world_z);
	half.x = half.y * ((float)this->settings.width / (float)this->settings.height);

	ndc.x = 2.0f * mouse_coords.x / (float)this->settings.width - 1.0f;
	ndc.y = 1.0f - 2.0f * mouse_coords.y / (float)this->settings.height;

	world = ndc * half;
	return (mlm::vec3(world, world_z));
}

/*
//	Processes and keeps track of key presses
*/
void	App::process_input()
{
	static Key esc(this->window, GLFW_KEY_ESCAPE);
	static Key tab(this->window, GLFW_KEY_TAB);
	static Key space(this->window, GLFW_KEY_SPACE);
	static Key c(this->window, GLFW_KEY_C);
	static Key c1(this->window, GLFW_KEY_1);
	static Key c2(this->window, GLFW_KEY_2);
	static Key r(this->window, GLFW_KEY_R);
	static Key ctrl(this->window, GLFW_KEY_LEFT_CONTROL);

	// Update key status
	esc.update();
	tab.update();
	space.update();
	c.update();
	c1.update();
	c2.update();
	r.update();
	ctrl.update();

	// Closes the program
	if (esc.is_pressed())
	{
		glfwSetWindowShouldClose(this->window, true);
		// Prints the last colors used to potentially reuse
		print_colors(this->state.color1, this->state.color2);
	}
	// Turns the gravity point on and off
	if (tab.is_pressed())
	{
		// If the gravity point has to be static and the gravity is off, update the gravity position
		if (this->settings.gravity_static == true && this->state.grav == false)
		{
			this->state.gravity = this->mouse_to_screen();
		}
		this->state.grav = !this->state.grav;
	}
	// Pauses the simulation
	if (space.is_pressed())
	{
		this->state.pause = !this->state.pause;
	}
	// Updates both colors
	if (c.is_pressed())
	{
		this->state.color1 = rand_vec3();
		this->state.color2 = rand_vec3();
	}
	// Updates color1
	if (c1.is_pressed())
	{
		this->state.color1 = rand_vec3();
	}
	// Updates color2
	if (c2.is_pressed())
	{
		this->state.color2 = rand_vec3();
	}
	// Resets the particles using the init compute shader
	if (r.is_pressed())
	{
		this->init_particles();
	}
	// Shows debug info on screen
	if (ctrl.is_pressed())
	{
		this->state.debug = !this->state.debug;
	}
}
