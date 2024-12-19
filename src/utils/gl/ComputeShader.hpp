/*
Created by: Emily (Em_iIy) Winnink
Created on: 16/12/2024
*/

#pragma once

#include <GLAD/glad.h>
#include <string>

class ComputeShader
{
	public:
		GLuint ID;

		ComputeShader();
		ComputeShader(const char *file_name);
		~ComputeShader();
		void	load(const char *compute_source);
		void	use();
		void	del();

		void set_float(const std::string &name, float value) const;
};