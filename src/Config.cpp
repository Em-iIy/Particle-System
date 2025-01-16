#include "Config.hpp"
#include "utils.hpp"

enum e_conf_tok {
	TITLE,
	SCALE,
	FOV,
	WIDTH,
	HEIGHT,
	SHADER,
	TEXTURE,
	OBJECT,
	COMMENT,
	ERROR
};

std::map<std::string, std::string>							Config::textures;
std::map<std::string, std::pair<std::string, std::string>>	Config::shaders;
std::map<std::string, std::string>							Config::objects;

std::string	Config::title = "";
float		Config::fov = 0.0f;
float		Config::scale = 0.0f;


/*
possible configurable variables:
- sim speed
- shape
- shape radius
- gravity strength
- color inner
- color outer
- resolution
- fov
- particle count
- fps on screen

*/

static e_conf_tok	check_token(std::string &data)
{
	if (data == "object")
		return (OBJECT);
	if (data == "texture")
		return (TEXTURE);
	if (data == "shader")
		return (SHADER);
	if (data == "scale")
		return (SCALE);
	if (data == "fov")
		return (FOV);
	if (data == "title")
		return (TITLE);
	if (data == "#")
		return (COMMENT);
	return (ERROR);
}

void	Config::print()
{
	std::cout << "title: " << Config::title << "\n";
	std::cout << "fov: " << Config::fov << "\n";
	std::cout << "scale: " << Config::scale << "\n\n";
	std::cout << "Shaders:\n";
	for (std::pair<const std::string, std::pair<std::string, std::string>> &shader : Config::shaders)
	{
		std::cout << shader.first << ": vertex shader: " << shader.second.first << " fragment shader: " << shader.second.second << "\n";
	}
	std::cout << "\nObjects:\n";
	for (std::pair<const std::string, std::string> &object : Config::objects)
	{
		std::cout << object.first << ": " << object.second << "\n";
	}
	std::cout << "\nTextures:\n";
	for (std::pair<const std::string, std::string> &texture : Config::textures)
	{
		std::cout << texture.first << ": " << texture.second << "\n";
	}
	std::cout << std::endl;
}

void	Config::parse_line(const std::string &line)
{
	static std::vector<std::string> params;
	params.reserve(5);
	split(params, line, " ");
	switch (check_token(params[0]))
	{
	case COMMENT:
		break;
	case TITLE:
		if (params.size() != 2)
			throw std::runtime_error("title: invalid parameters");
		if (Config::title != "")
			throw std::runtime_error("title already set");
		Config::title = params[1];
		break;
	case FOV:
		if (params.size() != 2)
			throw std::runtime_error("fov: invalid parameters");
		if (Config::fov != 0.0f)
			throw std::runtime_error("fov already set");
		Config::fov = std::stof(params[1]);
		if (Config::fov < 0.01f || Config::fov > 179.99f)
			throw std::runtime_error("fov out of range");
		break;
	case SCALE:
		if (params.size() != 2)
			throw std::runtime_error("scale: invalid parameters");
		if (Config::scale != 0.0f)#include "Config.hpp"
#include "utils.hpp"

enum e_conf_tok {
	TITLE,
	SCALE,
	FOV,
	WIDTH,
	HEIGHT,
	SHADER,
	TEXTURE,
	OBJECT,
	COMMENT,
	ERROR
};

std::map<std::string, std::string>							Config::textures;
std::map<std::string, std::pair<std::string, std::string>>	Config::shaders;
std::map<std::string, std::string>							Config::objects;

std::string	Config::title = "";
float		Config::fov = 0.0f;
float		Config::scale = 0.0f;

static e_conf_tok	check_token(std::string &data)
{
	if (data == "object")
		return (OBJECT);
	if (data == "texture")
		return (TEXTURE);
	if (data == "shader")
		return (SHADER);
	if (data == "scale")
		return (SCALE);
	if (data == "fov")
		return (FOV);
	if (data == "title")
		return (TITLE);
	if (data == "#")
		return (COMMENT);
	return (ERROR);
}

void	Config::print()
{
	std::cout << "title: " << Config::title << "\n";
	std::cout << "fov: " << Config::fov << "\n";
	std::cout << "scale: " << Config::scale << "\n\n";
	std::cout << "Shaders:\n";
	for (std::pair<const std::string, std::pair<std::string, std::string>> &shader : Config::shaders)
	{
		std::cout << shader.first << ": vertex shader: " << shader.second.first << " fragment shader: " << shader.second.second << "\n";
	}
	std::cout << "\nObjects:\n";
	for (std::pair<const std::string, std::string> &object : Config::objects)
	{
		std::cout << object.first << ": " << object.second << "\n";
	}
	std::cout << "\nTextures:\n";
	for (std::pair<const std::string, std::string> &texture : Config::textures)
	{
		std::cout << texture.first << ": " << texture.second << "\n";
	}
	std::cout << std::endl;
}

void	Config::parse_line(const std::string &line)
{
	static std::vector<std::string> params;
	params.reserve(5);
	split(params, line, " ");
	switch (check_token(params[0]))
	{
	case COMMENT:
		break;
	case TITLE:
		if (params.size() != 2)
			throw std::runtime_error("title: invalid parameters");
		if (Config::title != "")
			throw std::runtime_error("title already set");
		Config::title = params[1];
		break;
	case FOV:
		if (params.size() != 2)
			throw std::runtime_error("fov: invalid parameters");
		if (Config::fov != 0.0f)
			throw std::runtime_error("fov already set");
		Config::fov = std::stof(params[1]);
		if (Config::fov < 0.01f || Config::fov > 179.99f)
			throw std::runtime_error("fov out of range");
		break;
	case SCALE:
		if (params.size() != 2)
			throw std::runtime_error("scale: invalid parameters");
		if (Config::scale != 0.0f)
			throw std::runtime_error("scale already set");
		Config::scale = std::stof(params[1]);
		// limits on scale?
		break;
	case SHADER:
		if (params.size() != 4)
			throw std::runtime_error("shader: invalid parameters");
		// Check if the shader name is already taken
		if (Config::shaders.find(params[1]) != Config::shaders.end())
			throw std::runtime_error("shader: name already taken");
		Config::shaders[params[1]] = std::pair<std::string, std::string>(params[2], params[3]);
		break;
	case OBJECT:
		if (params.size() != 3)
			throw std::runtime_error("object: invalid parameters");
		// Check if the object name is already taken
		if (Config::objects.find(params[1]) != Config::objects.end())
			throw std::runtime_error("object: name already taken");
		Config::objects[params[1]] = params[2];
		break;
	case TEXTURE:
		if (params.size() != 3)
			throw std::runtime_error("texture: invalid parameters");
		// Check if the texture name is already taken
		if (Config::textures.find(params[1]) != Config::textures.end())
			throw std::runtime_error("texture: name already taken");
		Config::textures[params[1]] = params[2];
		break;
	default:
		break;
	}
	params.clear();
}

void	Config::parse(const char *data)
{
	std::vector<std::string> lines = split(data, "\n");
	for (std::string &line : lines)
	{
		Config::parse_line(line);
	}
	if (Config::title == "")
		throw std::runtime_error("title not set");
	if (Config::fov == 0.0f)
		throw std::runtime_error("fov not set");
	if (Config::scale == 0.0f)
		throw std::runtime_error("scale not set");
	if (Config::textures.size() == 0)
		throw std::runtime_error("textures not set");
	if (Config::shaders.size() == 0)
		throw std::runtime_error("shaders not set");
	if (Config::objects.size() == 0)
		throw std::runtime_error("objects not set");
}

// Loads the given config file
void	Config::load(const char *file_name)
{
	std::cout << "loading " << file_name << "..." << std::endl;
	Config::objects["quad"] = "./resources/objects/quad.obj";
	Config::shaders["quad"] = std::pair<std::string, std::string>(
		"./resources/shaders/quad.vert",
		"./resources/shaders/quad.frag"
	);
	char *data = read_file(file_name);
	if (!data)
	{
		std::cerr << "Config: Could not open " << file_name << std::endl;
		throw std::exception();
	}
	try
	{
		Config::parse(data);
	}
	catch(const std::runtime_error& e)
	{
		std::cerr << "error: " << file_name << ": " << e.what() << '\n';
		free(data);
		throw std::exception();
	}
	free(data);
}

// Loads just an .obj file and a texture and sets default values for the others
void	Config::load(const char *object, const char *texture)
{
	Config::fov = 60.0f;
	Config::title = "scop";
	Config::scale = 1.0f;
	Config::objects["quad"] = "./resources/objects/quad.obj";
	Config::shaders["quad"] = std::pair<std::string, std::string>(
		"./resources/shaders/quad.vert",
		"./resources/shaders/quad.frag"
	);
	Config::objects["input"] = object;
	Config::textures["input"] = texture;
	Config::shaders["default"] = std::pair<std::string, std::string>(
		"./resources/shaders/default.vert",
		"./resources/shaders/default.frag"
	);
}
			throw std::runtime_error("scale already set");
		Config::scale = std::stof(params[1]);
		// limits on scale?
		break;
	case SHADER:
		if (params.size() != 4)
			throw std::runtime_error("shader: invalid parameters");
		// Check if the shader name is already taken
		if (Config::shaders.find(params[1]) != Config::shaders.end())
			throw std::runtime_error("shader: name already taken");
		Config::shaders[params[1]] = std::pair<std::string, std::string>(params[2], params[3]);
		break;
	case OBJECT:
		if (params.size() != 3)
			throw std::runtime_error("object: invalid parameters");
		// Check if the object name is already taken
		if (Config::objects.find(params[1]) != Config::objects.end())
			throw std::runtime_error("object: name already taken");
		Config::objects[params[1]] = params[2];
		break;
	case TEXTURE:
		if (params.size() != 3)
			throw std::runtime_error("texture: invalid parameters");
		// Check if the texture name is already taken
		if (Config::textures.find(params[1]) != Config::textures.end())
			throw std::runtime_error("texture: name already taken");
		Config::textures[params[1]] = params[2];
		break;
	default:
		break;
	}
	params.clear();
}

void	Config::parse(const char *data)
{
	std::vector<std::string> lines = split(data, "\n");
	for (std::string &line : lines)
	{
		Config::parse_line(line);
	}
	if (Config::title == "")
		throw std::runtime_error("title not set");
	if (Config::fov == 0.0f)
		throw std::runtime_error("fov not set");
	if (Config::scale == 0.0f)
		throw std::runtime_error("scale not set");
	if (Config::textures.size() == 0)
		throw std::runtime_error("textures not set");
	if (Config::shaders.size() == 0)
		throw std::runtime_error("shaders not set");
	if (Config::objects.size() == 0)
		throw std::runtime_error("objects not set");
}

// Loads the given config file
void	Config::load(const char *file_name)
{
	std::cout << "loading " << file_name << "..." << std::endl;
	Config::objects["quad"] = "./resources/objects/quad.obj";
	Config::shaders["quad"] = std::pair<std::string, std::string>(
		"./resources/shaders/quad.vert",
		"./resources/shaders/quad.frag"
	);
	char *data = read_file(file_name);
	if (!data)
	{
		std::cerr << "Config: Could not open " << file_name << std::endl;
		throw std::exception();
	}
	try
	{
		Config::parse(data);
	}
	catch(const std::runtime_error& e)
	{
		std::cerr << "error: " << file_name << ": " << e.what() << '\n';
		free(data);
		throw std::exception();
	}
	free(data);
}

// Loads just an .obj file and a texture and sets default values for the others
void	Config::load(const char *object, const char *texture)
{
	Config::fov = 60.0f;
	Config::title = "scop";
	Config::scale = 1.0f;
	Config::objects["quad"] = "./resources/objects/quad.obj";
	Config::shaders["quad"] = std::pair<std::string, std::string>(
		"./resources/shaders/quad.vert",
		"./resources/shaders/quad.frag"
	);
	Config::objects["input"] = object;
	Config::textures["input"] = texture;
	Config::shaders["default"] = std::pair<std::string, std::string>(
		"./resources/shaders/default.vert",
		"./resources/shaders/default.frag"
	);
}