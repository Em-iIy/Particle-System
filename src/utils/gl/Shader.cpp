/*
Created by: Emily (Em_iIy) Winnink
Created on: 07/09/2024
*/

#include <stdlib.h>
#include <GLAD/glad.h>
#include <iostream>
#include <emlm/emlm.hpp>

#include "Shader.hpp"
#include "utils.hpp"

Shader::Shader() {}

Shader::Shader(const char *vertex_file_name, const char *fragment_file_name)
{
	char *vertex_source = read_file(vertex_file_name);
	if (!vertex_source)
		return ;
	char *fragment_source = read_file(fragment_file_name);
	if (!fragment_source)
	{
		free(vertex_source);
		return ;
	}
	this->load(vertex_source, fragment_source);
	free(vertex_source);
	free(fragment_source);

}

Shader::~Shader()
{
	// glDeleteProgram(this->_id);
}

void	Shader::load(const char *vertex_source, const char *fragment_source)
{
	int		success;
	char	infoLog[512];
	GLuint vertex_shader;
	GLuint fragment_shader;

	vertex_shader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertex_shader, 1, &vertex_source, NULL);
	glCompileShader(vertex_shader);
	glGetShaderiv(vertex_shader, GL_COMPILE_STATUS, &success);
	if(!success)
	{
		glGetShaderInfoLog(vertex_shader, 512, NULL, infoLog);
		std::cerr << "vertex shader compilation error:\n" << infoLog << std::endl;
		throw std::exception();
	}
	fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragment_shader, 1, &fragment_source, NULL);
	glCompileShader(fragment_shader);
	glGetShaderiv(fragment_shader, GL_COMPILE_STATUS, &success);
	if(!success)
	{
		glGetShaderInfoLog(fragment_shader, 512, NULL, infoLog);
		glDeleteShader(vertex_shader);
		std::cerr << "fragment shader compilation error:\n" << infoLog << std::endl;
		throw std::exception();
	}
	this->_id = glCreateProgram();
	glAttachShader(this->_id, vertex_shader);
	glAttachShader(this->_id, fragment_shader);
	glLinkProgram(this->_id);
	glGetProgramiv(this->_id, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(this->_id, 512, NULL, infoLog);
		std::cerr << "shader linking error:\n" << infoLog << std::endl;
		glDeleteShader(vertex_shader);
		glDeleteShader(fragment_shader);
		throw std::exception();
    }
	glDeleteShader(vertex_shader);
	glDeleteShader(fragment_shader);
}

void	Shader::use()
{
	glUseProgram(this->_id);
}

void	Shader::del()
{
	glDeleteProgram(this->_id);
}

void Shader::set_bool(const std::string &name, bool value) const
{
	glUniform1i(glGetUniformLocation(this->_id, name.c_str()), (int)value);
}

void Shader::set_float(const std::string &name, float value) const
{
	glUniform1f(glGetUniformLocation(this->_id, name.c_str()), value);
}

void Shader::set_int(const std::string &name, int value) const
{
	glUniform1i(glGetUniformLocation(this->_id, name.c_str()), value);
}

void Shader::set_mat4(const std::string &name, mlm::mat4 &value) const
{
	glUniformMatrix4fv(glGetUniformLocation(this->_id, name.c_str()), 1, GL_FALSE, &(value[0][0]));
}
