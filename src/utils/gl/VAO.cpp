/*
Created by: Emily (Em_iIy) Winnink
Created on: 07/09/2024
*/

#include "VAO.hpp"

// Constructor that generates a VAO ID
VAO::VAO() {}

VAO::VAO(GLsizei size)
{
	// remove this if this should create multiple vertex arrays
	if (size != 1)
		size = 1;
	glGenVertexArrays(size, &this->ID);
}

// Generates the Vertex array
void VAO::init()
{
	glGenVertexArrays(1, &this->ID);
}

void VAO::init(GLsizei size)
{
	glGenVertexArrays(size, &this->ID);
}

// Links a VBO to the VAO using a certain layout
void VAO::link_attr(VBO& VBO, GLuint layout, GLuint n, GLenum type, GLsizeiptr stride, void *offset)
{
	VBO.bind();
	glVertexAttribPointer(layout, n, type, GL_FALSE, stride, offset);
	glEnableVertexAttribArray(layout);
	VBO.unbind();
}

// Links a VBO to the VAO using a certain layout
void VAO::link_attr_ssbo(SSBO& ssbo, GLuint layout, GLuint n, GLenum type, GLsizeiptr stride, void *offset)
{
	glBindBuffer(GL_ARRAY_BUFFER, ssbo.ID);
	glVertexAttribPointer(layout, n, type, GL_FALSE, stride, offset);
	glEnableVertexAttribArray(layout);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

// Binds the VAO
void VAO::bind()
{
	glBindVertexArray(ID);
}

// Unbinds the VAO
void VAO::unbind()
{
	glBindVertexArray(0);
}

// Deletes the VAO
void VAO::del()
{
	glDeleteVertexArrays(1, &ID);
}
