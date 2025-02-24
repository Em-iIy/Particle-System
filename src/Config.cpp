/*
Created by: Emily (Em_iIy) Winnink
Created on: 19/02/2025
*/
#include "Config.hpp"
#include "utils.hpp"

enum e_conf_tok {
	TITLE,
	FOV,
	FULLSCREEN,
	WIDTH,
	HEIGHT,
	VIEW_BOX_DIMENSIONS,
	VSYNC,
	POST_PROCESSING,

	COLOR1,
	COLOR2,

	PARTICLE_COUNT,
	PARTICLE_MASS,
	PARTICLE_SIZE,
	PARTICLE_INIT_POSITION,
	PARTICLE_INIT_RADIUS,

	GRAVITY_MASS,
	GRAVITY_STATIC,

	FONT,

	VERTEX_SHADER_PARTICLE,
	FRAGMENT_SHADER_PARTICLE,

	VERTEX_SHADER_FONT,
	FRAGMENT_SHADER_FONT,

	VERTEX_SHADER_POST_PROCESSING,
	FRAGMENT_SHADER_POST_PROCESSING,

	COMPUTE_SHADER_INIT,
	COMPUTE_SHADER_PHYSICS,

	COMMENT,
	ERROR
};

static e_conf_tok	check_token(std::string &data)
{
	if (data == "title")	
		return (TITLE);
	if (data == "fov")	
		return (FOV);
	if (data == "fullscreen")	
		return (FULLSCREEN);
	if (data == "width")	
		return (WIDTH);
	if (data == "height")	
		return (HEIGHT);
	if (data == "view_box_dimensions")	
		return (VIEW_BOX_DIMENSIONS);
	if (data == "vsync")	
		return (VSYNC);
	if (data == "post_processing")	
		return (POST_PROCESSING);
	if (data == "color1")	
		return (COLOR1);
	if (data == "color2")	
		return (COLOR2);
	if (data == "particle_count")	
		return (PARTICLE_COUNT);
	if (data == "particle_mass")	
		return (PARTICLE_MASS);
	if (data == "particle_size")	
		return (PARTICLE_SIZE);
	if (data == "particle_init_pos")	
		return (PARTICLE_INIT_POSITION);
	if (data == "particle_init_radius")	
		return (PARTICLE_INIT_RADIUS);
	if (data == "gravity_mass")	
		return (GRAVITY_MASS);
	if (data == "gravity_static")	
		return (GRAVITY_STATIC);
	if (data == "font")	
		return (FONT);
	if (data == "particle_vert")	
		return (VERTEX_SHADER_PARTICLE);
	if (data == "particle_frag")	
		return (FRAGMENT_SHADER_PARTICLE);
	if (data == "font_vert")	
		return (VERTEX_SHADER_FONT);
	if (data == "font_frag")	
		return (FRAGMENT_SHADER_FONT);
	if (data == "post_processing_vert")	
		return (VERTEX_SHADER_POST_PROCESSING);
	if (data == "post_processing_frag")	
		return (FRAGMENT_SHADER_POST_PROCESSING);
	if (data == "particle_init_comp")	
		return (COMPUTE_SHADER_INIT);
	if (data == "particle_physics_comp")	
		return (COMPUTE_SHADER_PHYSICS);
	if (data == "#" || data == "")
		return (COMMENT);
	return (ERROR);
}

void	parse_1f(std::vector<std::string> &params, std::optional<float> &dst)
{
	if (params.size() != 2)
		throw std::runtime_error(params[0] + " invalid parameters");
	if (dst.has_value())
		throw std::runtime_error(params[0] + " already set");
	try
	{
		dst = std::stof(params[1]);
	}
	catch(...)
	{
		throw std::runtime_error(params[0] + " invalid parameters");
	}
	
}

void	parse_1i(std::vector<std::string> &params, std::optional<int> &dst)
{
	if (params.size() != 2)
		throw std::runtime_error(params[0] + " invalid parameters");
	if (dst.has_value())
		throw std::runtime_error(params[0] + " already set");
	try
	{
		dst = std::stoi(params[1]);
	}
	catch(...)
	{
		throw std::runtime_error(params[0] + " invalid parameters");
	}
}

void	parse_1bool(std::vector<std::string> &params, std::optional<bool> &dst)
{
	if (params.size() != 2)
		throw std::runtime_error(params[0] + " invalid parameters");
	if (dst.has_value())
		throw std::runtime_error(params[0] + " already set");
	if (params[1] == "true")
		dst = true;
	else if (params[1] == "false")
		dst = false;
	else
		throw std::runtime_error(params[0] + " invalid parameters");
}

void	parse_vec3(std::vector<std::string> &params, std::optional<mlm::vec3> &dst)
{
	if (params.size() != 4)
		throw std::runtime_error(params[0] + " invalid parameters");
	if (dst.has_value())
		throw std::runtime_error(params[0] + " already set");
	try
	{
		dst = mlm::vec3(
			std::stof(params[1]),
			std::stof(params[2]),
			std::stof(params[3])
		);
	}
	catch(...)
	{
		throw std::runtime_error(params[0] + " invalid parameters");
	}
}

void	parse_filename(std::vector<std::string> &params, std::optional<std::filesystem::path> &dst)
{
	if (params.size() != 2)
		throw std::runtime_error(params[0] + " invalid parameters");
	if (dst.has_value())
		throw std::runtime_error(params[0] + " already set");
	std::filesystem::path path = params[1];
	if (!exists(path))
		throw std::runtime_error(params[0] + ": " + params[1] + " does not exist");
	std::error_code code;
	std::filesystem::perms perms = std::filesystem::status(path, code).permissions();
	if (code) {
		throw std::runtime_error(params[0] + ": " + params[1] + " could not check permissions");
	}
	if ((perms & std::filesystem::perms::owner_read) == std::filesystem::perms::none &&
           (perms & std::filesystem::perms::group_read) == std::filesystem::perms::none &&
           (perms & std::filesystem::perms::others_read) == std::filesystem::perms::none)
		throw std::runtime_error(params[0] + ": " + params[1] + " invalid permissions");
	dst = path;
}

void	Config::parse_line(const std::string &line)
{
	static std::vector<std::string> params;
	params.reserve(16);
	split(params, line, " ");
	switch (check_token(params[0]))
	{
	case ERROR:
		throw std::runtime_error(params[0] + " invalid identifier");
		break;
	case COMMENT:
		break;
	case TITLE:
		if (params.size() != 2)
			throw std::runtime_error("title: invalid parameters");
		if (this->title.has_value())
			throw std::runtime_error("title already set");
		this->title = params[1];
		break;
	case FOV:
		parse_1f(params, this->fov);
		break;
	case FULLSCREEN:
		parse_1bool(params, this->fullscreen);
		break;
	case WIDTH:
		parse_1i(params, this->width);
		break;
	case HEIGHT:
		parse_1i(params, this->height);
		break;
	case VIEW_BOX_DIMENSIONS:
		parse_1f(params, this->view_box_dimensions);
		break;
	case VSYNC:
		parse_1bool(params, this->vsync);
		break;
	case POST_PROCESSING:
		parse_1bool(params, this->post_processing);
		break;
	case COLOR1:
		parse_vec3(params, this->color1);
		break;
	case COLOR2:
		parse_vec3(params, this->color2);
		break;
	case PARTICLE_COUNT:
		parse_1i(params, this->particle_count);
		break;
	case PARTICLE_MASS:
		parse_1f(params, this->particle_mass);
		break;
	case PARTICLE_SIZE:
		parse_1f(params, this->particle_size);
		break;
	case PARTICLE_INIT_POSITION:
		parse_vec3(params, this->particle_init_pos);
		break;
	case PARTICLE_INIT_RADIUS:
		parse_1f(params, this->particle_init_radius);
		break;
	case GRAVITY_MASS:
		parse_1f(params, this->gravity_mass);
		break;
	case GRAVITY_STATIC:
		parse_1bool(params, this->gravity_static);
		break;
	case FONT:
		parse_filename(params, this->font);
		break;
	case VERTEX_SHADER_PARTICLE:
		parse_filename(params, this->particle_vert);
		break;
	case FRAGMENT_SHADER_PARTICLE:
		parse_filename(params, this->particle_frag);
		break;
	case VERTEX_SHADER_FONT:
		parse_filename(params, this->font_vert);
		break;
	case FRAGMENT_SHADER_FONT:
		parse_filename(params, this->font_frag);
		break;
	case VERTEX_SHADER_POST_PROCESSING:
		parse_filename(params, this->post_processing_vert);
		break;
	case FRAGMENT_SHADER_POST_PROCESSING:
		parse_filename(params, this->post_processing_frag);
		break;
	case COMPUTE_SHADER_INIT:
		parse_filename(params, this->particle_init_comp);
		break;
	case COMPUTE_SHADER_PHYSICS:
		parse_filename(params, this->particle_physics_comp);
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
}

void	Config::verify()
{
	const std::string msg = ": invalid value";

	if (!this->title.has_value())
		throw std::runtime_error("title" + msg);
	if (!this->fov.has_value() || (this->fov < 1.0f || this->fov > 179.0f))
		throw std::runtime_error("fov" + msg);
	if (!this->fullscreen.has_value())
		throw std::runtime_error("fullscreen" + msg);
	if (!this->width.has_value() || this->width <= 0)
		throw std::runtime_error("width" + msg);
	if (!this->height.has_value() || this->height <= 0)
		throw std::runtime_error("height" + msg);
	if (!this->view_box_dimensions.has_value() || this->view_box_dimensions <= 0)
		throw std::runtime_error("view_box_dimensions" + msg);
	if (!this->vsync.has_value())
		throw std::runtime_error("vsync" + msg);
	if (!this->post_processing.has_value())
		throw std::runtime_error("post_processing" + msg);

	if (!this->color1.has_value() ||
		(this->color1->x < 0.0f || this->color1->x > 1.0f) ||
		(this->color1->y < 0.0f || this->color1->y > 1.0f) ||
		(this->color1->z < 0.0f || this->color1->z > 1.0f))
		throw std::runtime_error("color1" + msg);
	if (!this->color2.has_value() ||
		(this->color2->x < 0.0f || this->color2->x > 1.0f) ||
		(this->color2->y < 0.0f || this->color2->y > 1.0f) ||
		(this->color2->z < 0.0f || this->color2->z > 1.0f))
		throw std::runtime_error("color2" + msg);

	if (!this->particle_count.has_value() || this->particle_count <= 0)
	{
		throw std::runtime_error("particle_count" + msg);
	}
	else
	{
		// Due to workgroup sizes, the particle count must be a multiple of the workgroup size
		const int	round_min_1 = WORKGROUP_SIZE - 1;
		this->particle_count = (*(this->particle_count) + round_min_1) & ~round_min_1;
	}
	if (!this->particle_mass.has_value())
		throw std::runtime_error("particle_mass" + msg);
	if (!this->particle_size.has_value())
		throw std::runtime_error("particle_size" + msg);
	if (!this->particle_init_pos.has_value())
		throw std::runtime_error("particle_init_pos" + msg);
	if (!this->particle_init_radius.has_value())
		throw std::runtime_error("particle_init_radius" + msg);

	if (!this->gravity_mass.has_value())
		throw std::runtime_error("gravity_mass" + msg);
	if (!this->gravity_static.has_value())
		throw std::runtime_error("gravity_static" + msg);
	
	if (!this->font.has_value())
		throw std::runtime_error("font" + msg);

	if (!this->particle_vert.has_value())
		throw std::runtime_error("particle_vert" + msg);
	if (!this->particle_frag.has_value())
		throw std::runtime_error("particle_frag" + msg);

	if (!this->font_vert.has_value())
		throw std::runtime_error("font_vert" + msg);
	if (!this->font_frag.has_value())
		throw std::runtime_error("font_frag" + msg);
	
	if (*(this->post_processing))
	{
		if (!this->post_processing_vert.has_value())
			throw std::runtime_error("post_processing_vert" + msg);
		if (!this->post_processing_frag.has_value())
			throw std::runtime_error("post_processing_frag" + msg);
	}

	if (!this->particle_init_comp.has_value())
		throw std::runtime_error("particle_init_comp" + msg);
	if (!this->particle_physics_comp.has_value())
		throw std::runtime_error("particle_physics_comp" + msg);

	
	
	

}

void	Config::load(std::filesystem::path path)
{
	if (std::filesystem::exists(path) == false)
		throw std::runtime_error("Invalid config file");
	char *data = read_file(path.c_str());
	if (!data)
	{
		std::cerr << "Config: Could not open " << path.filename() << std::endl;
		throw std::exception();
	}
	try
	{
		this->parse(data);
		this->verify();
	}
	catch(const std::runtime_error& e)
	{
		std::cout << "Config: " << path.filename() << ": " << e.what() << '\n';
		free(data);
		throw std::exception();
	}
	free(data);
}