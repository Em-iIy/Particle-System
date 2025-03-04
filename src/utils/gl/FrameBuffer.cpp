/*
Created by: Emily (Em_iIy) Winnink
Created on: 16/01/2025
*/

#include "FrameBuffer.hpp"

FrameBuffer::FrameBuffer()
{
	this->render_texture = Tex2d(GL_CLAMP_TO_BORDER, GL_LINEAR);
}

void	FrameBuffer::generate(GLsizei in_width, GLsizei in_height)
{
	this->width = in_width;
	this->height = in_height;
	glGenFramebuffers(1, &this->ID);
	this->bind();

	this->render_texture.load_render_texture(width, height, GL_RGB, GL_UNSIGNED_BYTE);
	glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, this->render_texture.get_ID(), 0);

	this->render_buffer.generate();
	this->render_buffer.bind();
	this->render_buffer.storage(GL_DEPTH24_STENCIL8, this->width, this->height);
	this->render_buffer.unbind();
	this->link_render_buffer(this->render_buffer);
	if (!this->check_status())
		throw std::runtime_error("Framebuffer incomplete");
}

void	FrameBuffer::bind()
{
	glBindFramebuffer(GL_FRAMEBUFFER, this->ID);
}

void	FrameBuffer::unbind()
{
	glBindFramebuffer(GL_FRAMEBUFFER, 0);

}

void	FrameBuffer::del()
{
	this->render_buffer.del();
	this->render_texture.del();
	glDeleteFramebuffers(1, &this->ID);
}

void	FrameBuffer::link_render_texture(GLenum attachment)
{
	glFramebufferTexture2D(GL_FRAMEBUFFER, attachment, GL_TEXTURE_2D, this->render_texture.get_ID(), 0);
}

void	FrameBuffer::link_render_buffer(RenderBuffer &rbo)
{
	glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, GL_RENDERBUFFER, rbo.ID);
}

bool	FrameBuffer::check_status()
{

	if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE)
	{
		return (false);
	}
	return (true);
}

