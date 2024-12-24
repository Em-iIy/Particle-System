/*
Created by: Emily (Em_iIy) Winnink
Created on: 16/12/2024
*/
#include "ComputeShader.hpp"
#include "utils.hpp"


ComputeShader::ComputeShader() {}

ComputeShader::ComputeShader(const char *file_name)
{
	char *compute_source = read_file(file_name);
	if (!compute_source)
		return ;
	this->load(compute_source);
	free(compute_source);
}


ComputeShader::~ComputeShader()
{

}

void	ComputeShader::load(const char *compute_source)
{
	int		success;
	char	info_log[512];
	GLuint	compute_shader;

	compute_shader = glCreateShader(GL_COMPUTE_SHADER);
	glShaderSource(compute_shader, 1, &compute_source, NULL);
	glCompileShader(compute_shader);
	glGetShaderiv(compute_shader, GL_COMPILE_STATUS, &success);
	if(!success)
	{
		glGetShaderInfoLog(compute_shader, 512, NULL, info_log);
		std::cerr << "compute shader compilation error:\n" << info_log << std::endl;
		throw std::exception();
	}
	this->ID = glCreateProgram();
	glAttachShader(this->ID, compute_shader);
	glLinkProgram(this->ID);
	glGetProgramiv(this->ID, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(this->ID, 512, NULL, info_log);
		std::cerr << "shader linking error:\n" << info_log << std::endl;
		glDeleteShader(compute_shader);
		throw std::exception();
    }
	glDeleteShader(compute_shader);
}

void	ComputeShader::use()
{
	glUseProgram(this->ID);
}

void	ComputeShader::del()
{
	glDeleteProgram(this->ID);
}

void ComputeShader::set_int(const std::string &name, int value) const
{
	glUniform1i(glGetUniformLocation(this->ID, name.c_str()), value);
}

void ComputeShader::set_uint(const std::string &name, uint value) const
{
	glUniform1ui(glGetUniformLocation(this->ID, name.c_str()), value);
}

void ComputeShader::set_float(const std::string &name, float value) const
{
	glUniform1f(glGetUniformLocation(this->ID, name.c_str()), value);
}

void ComputeShader::set_vec3(const std::string &name, const mlm::vec3 &value) const
{
	glUniform3f(glGetUniformLocation(this->ID, name.c_str()), value.x, value.y, value.z);
}

void ComputeShader::set_vec4(const std::string &name, const mlm::vec4 &value) const
{
	glUniform4f(glGetUniformLocation(this->ID, name.c_str()), value.x, value.y, value.z, value.w);
}
