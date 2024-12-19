/*
Created by: Emily (Em_iIy) Winnink
Created on: 09/09/2024
*/

#pragma once

#include <iostream>

#include "bmp/bmp.h"

uint	load_texture(const char *img);
void	delete_texture(uint texture);

class Tex2d
{
private:
	GLuint	ID;

	GLint	wrap_s;
	GLint	wrap_t;
	GLint	filter_min;
	GLint	filter_mag;

	GLint	format;
public:
	Tex2d();
	~Tex2d();

	void	load(const char *img);
	void	load(const bmp_t &bmp);
	void	load(const std::string &img);

	const GLuint	&get_ID() const; 

	void	bind();
	void	del();
};
