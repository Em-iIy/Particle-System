/*
Created by: Emily (Em_iIy) Winnink
Created on: 16/12/2024
*/
#pragma once

#include <GLFW/glfw3.h>

class Key {
	private:
		GLFWwindow	*window;
		int			type;
		int			state;
		int			prev_state;

	public:
		Key();
		Key(GLFWwindow *in_window, int in_type);
		~Key();

		void	set_window(GLFWwindow *in_window);
		void	set_type(int in_type);

		void	update();

		bool	is_pressed() const;
		bool	is_down() const;
		bool	is_released() const;
};
