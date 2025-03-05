/*
Created by: Emily (Em_iIy) Winnink
Created on: 25/02/2025
*/
#pragma once

#include <string>

#include "utils.hpp"
#include "emlm/emlm.hpp"
#include "Config.hpp"


struct Settings {
	// Constructor
	Settings();
	Settings(Config &config);

	// Window/screen settings
	std::string	title;
	float		fov;
	int			width;
	int			height;
	float		view_box_dimensions;
	bool		vsync;
	bool		post_processing;
	bool		fullscreen;
	float		sim_speed;
	
	// Particle settings
	int			particle_count;
	float		particle_mass;
	float		particle_size;

	mlm::vec3	particle_init_pos;
	float		particle_init_radius;

	// Gravity settings
	float		gravity_mass;
	bool		gravity_static;
};

struct State {
	// Constructor
	State();
	State(Config &config);

	mlm::vec2	mouse_coords;


	bool		pause;
	bool		debug;
	bool		grav;
	mlm::vec3	gravity;

	mlm::vec3	color1;
	mlm::vec3	color2;
};

struct Initialized {
	// Constructor
	Initialized();

	bool	gl;
	bool	window;
	bool	shaders;
	bool	buffers;
	bool	text;
};

struct Metrics {
	Metrics();
	int		frame_counter;
	float	frame_time;
	float	fps;

	float	render_timer;
	float	compute_timer;
	float	post_processing_timer;
};

class App {
	private:
		Settings			settings;
		State				state;
		Initialized			initialized;
		Metrics				metrics;

		VAO					post_proc_vao;
		VBO					post_proc_vbo;

		VAO					particle_vao;
		SSBO				particle_ssbo;

		Shader				particle_render;
		ComputeShader		particle_init;
		ComputeShader		particle_physics;

		Shader				post_proc_shader;
		FrameBuffer			post_proc_frame_buffer;

		Font				font;

		void				init_gl();
		void				init_shaders(Config &config);
		void				init_text(const char *font_file, const char *shader_vert, const char *shader_frag);
		void				init_buffers();
		void				init_particles();

		void				update_gravity();
		void				update_fps();
		mlm::vec3			mouse_to_screen();
		void				process_input();

		void				post_processing();
		void				render_info();

		void				delete_text();
		void				delete_shaders();
		void				delete_buffers();
		void				delete_gl();

	public:
		GLFWwindow			*window;
		
		App();
		~App();

		void				init(Config &config);
		void				update();
		void				render();
		bool				is_running();
};
