/*
Created by: Emily (Em_iIy) Winnink
Created on: 19/02/2025
*/
#pragma once

#include <string>
#include <map>
#include <optional>
#include <filesystem>

#include "emlm/emlm.hpp"

#define WORKGROUP_SIZE 16

class Config {
	private:
		void	parse_line(const std::string &line);
		void	parse(const char *data);
		void	verify();

	public:
		// Window/screen settings
		std::optional<std::string>	title;
		std::optional<float>		fov;
		std::optional<bool>			fullscreen;
		std::optional<int>			width;
		std::optional<int>			height;
		std::optional<float>		view_box_dimensions;
		std::optional<bool>			vsync;
		std::optional<bool>			post_processing;
		std::optional<float>		sim_speed;

		// Particle settings
		std::optional<mlm::vec3>	color1;
		std::optional<mlm::vec3>	color2;

		std::optional<int>			particle_count;
		std::optional<float>		particle_mass;
		std::optional<float>		particle_size;

		std::optional<mlm::vec3>	particle_init_pos;
		std::optional<float>		particle_init_radius;

		// Gravity settings
		std::optional<float>		gravity_mass;
		std::optional<bool>			gravity_static;

		// Font
		std::optional<std::filesystem::path>	font;

		// Shaders
		std::optional<std::filesystem::path>	particle_vert;
		std::optional<std::filesystem::path>	particle_frag;

		std::optional<std::filesystem::path>	font_vert;
		std::optional<std::filesystem::path>	font_frag;

		std::optional<std::filesystem::path>	post_processing_vert;
		std::optional<std::filesystem::path>	post_processing_frag;

		std::optional<std::filesystem::path>	particle_init_comp;
		std::optional<std::filesystem::path>	particle_physics_comp;
	
		void	load(std::filesystem::path path);
};
