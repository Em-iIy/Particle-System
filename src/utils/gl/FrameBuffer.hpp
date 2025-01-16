/*
Created by: Emily (Em_iIy) Winnink
Created on: 16/01/2025
*/

#pragma once

#include <GLAD/glad.h>

#include "utils.hpp"

class FrameBuffer
{
public:
	GLuint ID;

	FrameBuffer();
	void	generate();
	void	bind();
	void	unbind();
	void	del();

	void	link_render_buffer(RenderBuffer &rbo);
	bool	check_status();
};