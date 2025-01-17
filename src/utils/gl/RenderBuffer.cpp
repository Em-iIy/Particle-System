#include "RenderBuffer.hpp"

RenderBuffer::RenderBuffer()
{
}

void	RenderBuffer::generate()
{
	glGenRenderbuffers(1, &this->ID);
}

void	RenderBuffer::bind()
{
	glBindRenderbuffer(GL_RENDERBUFFER, this->ID);
}

void	RenderBuffer::storage(GLenum internal_format, GLsizei width, GLsizei height)
{
	glRenderbufferStorage(GL_RENDERBUFFER, internal_format, width, height);
}

void	RenderBuffer::unbind()
{
	glBindRenderbuffer(GL_RENDERBUFFER, 0);
}

void	RenderBuffer::del()
{
	glDeleteRenderbuffers(1, &this->ID);
}
