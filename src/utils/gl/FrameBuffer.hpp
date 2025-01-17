/*
Created by: Emily (Em_iIy) Winnink
Created on: 16/01/2025
*/

#pragma once

#include <vector>
#include <GLAD/glad.h>

#include "../utils.hpp"


class FrameBuffer
{
public:
	GLuint			ID;
	GLsizei 		width;
	GLsizei 		height;
	Tex2d			render_texture;
	RenderBuffer	render_buffer;

	FrameBuffer();
	void	generate(GLsizei in_width, GLsizei in_height);
	void	bind();
	void	unbind();
	void	del();

	void	link_render_texture(GLenum attachment);
	void	link_render_buffer(RenderBuffer &rbo);
	bool	check_status();
};