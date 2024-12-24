/*
Created by: Emily (Em_iIy) Winnink
Created on: 16/12/2024
*/

#pragma once

#include <GLAD/glad.h>
#include <emlm/emlm.hpp>
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

		void set_int(const std::string &name, int value) const;
		void set_uint(const std::string &name, uint value) const;
		void set_float(const std::string &name, float value) const;
		void set_vec3(const std::string &name, const mlm::vec3 &value) const;
		void set_vec4(const std::string &name, const mlm::vec4 &value) const;
};