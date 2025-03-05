/*
Created by: Emily (Em_iIy) Winnink
Created on: 4/3/2025
*/
#include "App.hpp"

void	App::delete_text()
{
	if (this->initialized.text == false)
		return;
	std::cout << "Deleting text renderer..." << std::endl;
	delete_text_renderer();
}

void	App::delete_shaders()
{
	if (this->initialized.shaders == false)
		return;
	std::cout << "Deleting shaders..." << std::endl;
	this->particle_render.del();
	this->particle_init.del();
	this->particle_physics.del();
	if (this->settings.post_processing == true)
	{
		this->post_proc_shader.del();
	}
}

void	App::delete_buffers()
{
	if (this->initialized.buffers == false)
		return;
	std::cout << "Deleting buffers..." << std::endl;
	this->particle_vao.del();
	this->particle_ssbo.del();
	if (this->settings.post_processing == true)
	{
		this->post_proc_frame_buffer.del();
		this->post_proc_vao.del();
		this->post_proc_vbo.del();
	}
}

void	App::delete_gl()
{
	if (this->initialized.window == true)
	{
		std::cout << "Deleting window..." << std::endl;
		glfwDestroyWindow(this->window);
	}
	if (this->initialized.gl)
	{
		std::cout << "Deleting GLFW & OpenGL..." << std::endl;
		glfwTerminate();
	}
}

/*
//	Delete everything that has been initialized
*/
App::~App()
{
	this->delete_text();
	this->delete_shaders();
	this->delete_buffers();
	this->delete_gl();
}
