/*
Created by: Emily (Em_iIy) Winnink
Created on: 07/09/2024
*/
#pragma once

#include <GLAD/glad.h>

#include "VBO.hpp"
#include "SSBO.hpp"

class VAO
{
public:
	// id reference for the Vertex Array Object
	GLuint id;
	// Constructor that generates a VAO id
	VAO();
	VAO(GLsizei size);

	// Generates the Vertex array
	void init();
	void init(GLsizei size);
	// Links a VBO to the VAO using a certain layout
	void link_attr(VBO& VBO, GLuint layout, GLuint n, GLenum type, GLsizeiptr stride, void *offset);
	// Links a VBO to the VAO using a certain layout
	void link_attr_ssbo(SSBO& ssbo, GLuint layout, GLuint n, GLenum type, GLsizeiptr stride, void *offset);
	// Binds the VAO
	void bind();
	// Unbinds the VAO
	void unbind();
	// Deletes the VAO
	void del();
};
