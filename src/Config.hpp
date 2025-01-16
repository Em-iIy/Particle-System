#pragma once

#include <string>
#include <map>

class Config {
	private:
		static void	parse_line(const std::string &line);
		static void	parse(const char *data);

	public:
		static std::map<std::string, std::string>							textures;
		static std::map<std::string, std::pair<std::string, std::string>>	shaders;
		static std::map<std::string, std::string>							objects;
	
		static std::string	title;
		static float		fov;
		static float		scale;

		static void	load(const char *file_name);
		static void	load(const char *object, const char *texture);
		static void	print();
};
