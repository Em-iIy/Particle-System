/*
Created by: Emily (Em_iIy) Winnink
Created on: 23/12/2024
*/

#pragma once

#include <GLAD/glad.h>
#include <vector>

#include "emlm/emlm.hpp"

class SSBO
{
public:
	GLuint		id;
	GLsizeiptr	size;

	SSBO(void);

	SSBO(mlm::vec3 *data, GLsizeiptr data_size, GLenum usage);
	SSBO(std::vector<mlm::vec3> &data, GLenum usage);

	void	bind();
	void	bind_base(GLuint index);
	void	unbind();
	void	del();
};
