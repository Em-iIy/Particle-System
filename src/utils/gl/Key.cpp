/*
Created by: Emily (Em_iIy) Winnink
Created on: 16/12/2024
*/
#include "Key.hpp"

Key::Key(): window(NULL), type(GLFW_KEY_UNKNOWN), state(GLFW_RELEASE), prev_state(GLFW_RELEASE) {}

Key::Key(GLFWwindow *in_window, int in_type): window(in_window), type(in_type), state(GLFW_RELEASE), prev_state(GLFW_RELEASE) {}

Key::~Key() {}


void	Key::set_window(GLFWwindow *in_window)
{
	this->window = in_window;
}

void	Key::set_type(int in_type)
{
	this->type = in_type;
}

void	Key::update()
{
	this->prev_state = this->state;
	this->state = glfwGetKey(this->window, this->type);
}


bool	Key::is_pressed() const
{
	if (this->state == GLFW_PRESS && this->prev_state == GLFW_RELEASE)
		return (true);
	return (false);
}

bool	Key::is_down() const
{
	if (this->state == GLFW_PRESS || this->state == GLFW_REPEAT)
		return (true);
	return (false);
}

bool	Key::is_released() const
{
	if (this->state == GLFW_RELEASE && this->prev_state == GLFW_PRESS)
		return (true);
	return (false);
}
