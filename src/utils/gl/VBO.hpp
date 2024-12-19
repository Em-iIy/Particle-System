/*
Created by: Emily (Em_iIy) Winnink
Created on: 07/09/2024
*/
#pragma once

#include <GLAD/glad.h>
#include <vector>
#include <emlm/emlm.hpp>
#include <cstring>

struct Vertex
{
	mlm::vec3 pos;
	mlm::vec3 normal;
	mlm::vec3 color;
	mlm::vec2 texUV;

	bool operator<(const Vertex &vert) const {
		return (memcmp((void *)this, (void *)&vert, sizeof(Vertex)) > 0);
	}
};


class VBO
{
public:
	// Reference ID of the Vertex Buffer Object
	GLuint ID;

	VBO(void);
	// Constructor that generates a Vertex Buffer Object and links it to vertices

	VBO(GLfloat* vertices, GLsizeiptr size);
	// Binds the VBO
	void bind();
	// Unbinds the VBO
	void unbind();
	// Deletes the VBO
	void del();
};
