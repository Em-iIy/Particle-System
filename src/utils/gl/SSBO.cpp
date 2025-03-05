/*
Created by: Emily (Em_iIy) Winnink
Created on: 23/12/2024
*/

#include "SSBO.hpp"

SSBO::SSBO(void) {}


SSBO::SSBO(mlm::vec3 *data, GLsizeiptr data_size, GLenum usage)
{
	this->size = data_size;
	glGenBuffers(1, &this->id);
	this->bind();

	glBufferData(GL_SHADER_STORAGE_BUFFER, this->size, data, usage);
	this->bind_base(0);
	this->unbind();
}

SSBO::SSBO(std::vector<mlm::vec3> &data, GLenum usage)
{
	this->size = data.size() * sizeof(mlm::vec3);
	glGenBuffers(1, &this->id);
	this->bind();

	glBufferData(GL_SHADER_STORAGE_BUFFER, this->size, data.data(), usage);
	this->bind_base(0);
	this->unbind();
}

void	SSBO::bind()
{
	glBindBuffer(GL_SHADER_STORAGE_BUFFER, this->id);
}

void	SSBO::bind_base(GLuint index)
{
	this->bind();
	glBindBufferBase(GL_SHADER_STORAGE_BUFFER, index, this->id);
	this->unbind();
}

void	SSBO::unbind()
{
	glBindBuffer(GL_SHADER_STORAGE_BUFFER, 0);
}

void	SSBO::del()
{
	glDeleteBuffers(1, &this->id);
}
