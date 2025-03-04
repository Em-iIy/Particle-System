/*
Created by: Emily (Em_iIy) Winnink
Created on: 3/3/2025
*/
#include "App.hpp"

extern float	g_delta_time;

void	App::update_fps()
{
	if (this->metrics.frame_time > 1.0f)
	{
		this->metrics.fps = 1.0f / (this->metrics.frame_time / this->metrics.frame_counter);
		this->metrics.frame_counter = 0;
		this->metrics.frame_time = 0.0f;
		return ;
	}
	this->metrics.frame_counter++;
	this->metrics.frame_time += g_delta_time;
}

void	App::update()
{
	float		mass = 0.0f;

	this->state.gravity = this->mouse_to_screen();
	g_delta_time = delta_time_update();
	this->update_fps();
	this->process_input();

	timer::start();
	if (this->state.pause == false)
	{
		if (this->state.grav == true)
			mass = this->settings.gravity_mass;
		this->particle_physics.use();
		this->particle_ssbo.bind();
		glUniform3f(0, this->state.gravity.x, this->state.gravity.y, this->state.gravity.z);
		glUniform1f(1, g_delta_time);
		glUniform1f(2, this->settings.sim_speed);
		glUniform1f(3, mass);
		glUniform1f(4, this->settings.particle_mass);
		glDispatchCompute((GLuint)this->settings.particle_count / WORKGROUP_SIZE, 1, 1);
		glMemoryBarrier(GL_VERTEX_ATTRIB_ARRAY_BARRIER_BIT);
	}
	this->metrics.compute_timer = timer::u_elapsed();
}

void	App::post_processing()
{
	this->post_proc_frame_buffer.unbind();
	glDisable(GL_DEPTH_TEST);

	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	this->post_proc_shader.use();
	this->post_proc_frame_buffer.render_texture.bind();
	this->post_proc_vao.bind();
	glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
}

void	App::render_text()
{
	std::string info = "";
	if (this->state.pause)
		info += "Paused\n";

	info += "Fps: " + std::to_string((int)this->metrics.fps);
	info += "\nCompute: " + std::to_string(this->metrics.compute_timer) + "us";
	info += "\nRender: " + std::to_string(this->metrics.render_timer) + "us";
	info += "\nPost processing: " + std::to_string(this->metrics.post_processing_timer) + "us";
	info += "\nParticles: " + std::to_string(this->settings.particle_count);
	info += "\nGravity: "; this->state.grav ? info += "on": info += "off";
	info += "\nColor1 = R(" + std::to_string(int(this->state.color1.x * 255.0f)) + ") G(" + std::to_string(int(this->state.color1.y * 255.0f)) + ") B(" + std::to_string(int(this->state.color1.z * 255.0f)) + ")";
	info += "\nColor2 = R(" + std::to_string(int(this->state.color2.x * 255.0f)) + ") G(" + std::to_string(int(this->state.color2.y * 255.0f)) + ") B(" + std::to_string(int(this->state.color2.z * 255.0f)) + ")";
	RenderText(this->font, info, 0.0f, this->settings.height - 40.0f, 0.5f, mlm::vec3(1.0));
}

void	App::render()
{
	timer::start();
	if (this->settings.post_processing)
	{
		this->post_proc_frame_buffer.bind();
		glEnable(GL_DEPTH_TEST);
	}
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	mlm::mat4	projection = mlm::perspective(
		mlm::radians(this->settings.fov),
		(float)this->settings.width / (float)this->settings.height,
		0.1f,
		2.0f * this->settings.view_box_dimensions
	);
	this->particle_render.use();
	glUniformMatrix4fv(0, 1, GL_FALSE, &(projection[0][0]));
	glUniform3f(1, this->state.gravity.x, this->state.gravity.y, this->state.gravity.z);
	glUniform3f(2, this->state.color1.x, this->state.color1.y, this->state.color1.z);
	glUniform3f(3, this->state.color2.x, this->state.color2.y, this->state.color2.z);
	glUniform1f(4, this->settings.view_box_dimensions);
	this->particle_vao.bind();
	glDrawArrays(GL_POINTS, 0, this->settings.particle_count);
	this->metrics.render_timer = timer::u_elapsed();
	
	timer::start();
	if (this->settings.post_processing)
		this->post_processing();
	this->metrics.post_processing_timer = timer::u_elapsed();
	if (this->state.debug)
		this->render_text();
	glfwSwapBuffers(window);
	glfwPollEvents();
}

bool	App::is_running()
{
	return (!glfwWindowShouldClose(this->window));
}