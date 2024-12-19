/*
Created by: Emily (Em_iIy) Winnink
Created on: 07/09/2024
*/
#pragma once

#include <GLAD/glad.h>

#include "VBO.hpp"

class VAO
{
public:
	// ID reference for the Vertex Array Object
	GLuint ID;
	// Constructor that generates a VAO ID
	VAO();
	VAO(GLsizei size);

	// Links a VBO to the VAO using a certain layout
	void link_attr(VBO& VBO, GLuint layout, GLuint n, GLenum type, GLsizeiptr stride, void *offset);
	// Binds the VAO
	void bind();
	// Unbinds the VAO
	void unbind();
	// Deletes the VAO
	void del();
};
