/*
Created by: Emily (Em_iIy) Winnink
Created on: 16/12/2024
*/
#include <GLFW/glfw3.h>

float delta_time_update(void)
{
	static float last_frame = 0.0f;
	float current_frame = static_cast<float>(glfwGetTime());
	float delta_time = current_frame - last_frame;
	last_frame = current_frame;
	return (delta_time);
}
