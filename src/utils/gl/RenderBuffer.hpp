/*
Created by: Emily (Em_iIy) Winnink
Created on: 16/01/2025
*/

#pragma once

#include <GLAD/glad.h>

class RenderBuffer
{
public:
	GLuint id;

	RenderBuffer();
	void	generate();
	void	bind();
	void	storage(GLenum internal_format, GLsizei width, GLsizei height);
	void	unbind();
	void	del();

};
