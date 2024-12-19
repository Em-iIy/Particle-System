/*
Created by: Emily (Em_iIy) Winnink
Created on: 07/09/2024
*/
#pragma once

#include <GLAD/glad.h>
#include <vector>
#include <sys/types.h>

class EBO
{
public:
	// ID reference of Elements Buffer Object
	GLuint ID;

	EBO(void);
	// Constructor that generates a Elements Buffer Object and links it to indices
	EBO(GLuint* indices, GLsizeiptr size);
	EBO(std::vector<uint> &indices);
	// Binds the EBO
	void bind();
	// Unbinds the EBO
	void unbind();
	// Deletes the EBO
	void del();
};
