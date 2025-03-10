/*
Created by: Emily (Em_iIy) Winnink
Created on: 25/02/2025
*/
#include "App.hpp"

void	cursor_position_callback(GLFWwindow *window, double x_pos, double y_pos);

Settings::Settings() {}

/*
//////////////////////////////////////////////////////////////
//	Transfer the config data into structs for easier access	//
//////////////////////////////////////////////////////////////
*/
Settings::Settings(Config &config)
{
	// Window/screen settings
	this->title = *(config.title);
	this->fov = *(config.fov);
	this->width = *(config.width);
	this->height = *(config.height);
	this->view_box_dimensions = *(config.view_box_dimensions);
	this->vsync = *(config.vsync);
	this->post_processing = *(config.post_processing);
	this->fullscreen = *(config.fullscreen);
	this->sim_speed = *(config.sim_speed);

	// Particle settings
	this->particle_count = *(config.particle_count);
	this->particle_mass = *(config.particle_mass);
	this->particle_size = *(config.particle_size);

	this->particle_init_pos = *(config.particle_init_pos);
	this->particle_init_radius = *(config.particle_init_radius);

	// Gravity settings
	this->gravity_mass = *(config.gravity_mass);
	this->gravity_static = *(config.gravity_static);
}

State::State() {}

State::State(Config &config): pause(true), debug(false), grav(true)
{
	this->mouse_coords = mlm::vec2(*(config.width) / 2.0f, *(config.height) / 2.0f);
	this->color1 = *(config.color1);
	this->color2 = *(config.color2);
	this->post_processing = *(config.post_processing);
	if (config.gravity_static == true)
		grav = false;
}

Initialized::Initialized(): gl(false), window(false), shaders(false), buffers(false), text(false)
{}

Metrics::Metrics(): frame_counter(0), frame_time(0.0f), fps(0.0f), render_timer(0.0f), compute_timer(0.0f), post_processing_timer(0.0f)
{}

App::App()
{

}

/*
//	Init GLFW then load opengl then create a window
*/
void	App::init_gl()
{
	std::cout << "Initializing GLFW & OpenGL..." << std::endl;
	// Initialize GLFW and set version to 4.3
	init_glfw();
	this->initialized.gl = true;

	GLFWmonitor	*monitor = glfwGetPrimaryMonitor();
	if (this->settings.fullscreen == true)
	{
		this->window = init_fullscreen_window(
			this->settings.title.c_str(),
			this->settings.vsync
		);
		const GLFWvidmode	*vid_mode = glfwGetVideoMode(monitor);
		this->settings.width = vid_mode->width;
		this->settings.height = vid_mode->height;
	}
	else
	{
		this->window = init_window(
			&this->settings.width,
			&this->settings.height,
			this->settings.title.c_str(),
			NULL,
			NULL,
			this->settings.vsync
		);
	}
	this->initialized.window = true;
}

/*
//	Compile all the compute and render shaders
*/
void	App::init_shaders(Config &config)
{
	std::cout << "Initializing shaders..." << std::endl;
	this->particle_render = Shader(config.particle_vert->c_str(), config.particle_frag->c_str());
	this->particle_init = ComputeShader(config.particle_init_comp->c_str());
	this->particle_physics = ComputeShader(config.particle_physics_comp->c_str());
	if (this->settings.post_processing == true)
		this->post_proc_shader = Shader(config.post_processing_vert->c_str(), config.post_processing_frag->c_str());
	
	this->initialized.shaders = true;
}

/*
//	Read in the font file and initialize the text render buffers/shaders
*/
void	App::init_text(const char *font_file, const char *shader_vert, const char *shader_frag)
{
	std::cout << "Initializing font..." << std::endl;
	this->font = init_font(font_file);
	std::cout << "Initializing text renderer..." << std::endl;
	init_text_renderer(shader_vert, shader_frag, this->settings.width, this->settings.height);

	this->initialized.text = true;
}

/*
//	Create all the buffers for rendering and setup their data attributes
*/
void	App::init_buffers()
{
	std::cout << "Initializing buffers..." << std::endl;
	GLfloat vertices[] = {
		1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
		-1.0f, 1.0f, 1.0f, 0.0f, 1.0f,
		1.0f, -1.0f, 1.0f, 1.0f, 0.0f,
		-1.0f, -1.0f, 1.0f, 0.0f, 0.0f
	};
	if (this->settings.post_processing)
	{
		this->post_proc_vao.init();
		this->post_proc_vao.bind();
		this->post_proc_vbo = VBO(vertices, sizeof(vertices));
		this->post_proc_vao.link_attr(this->post_proc_vbo, 0, 3, GL_FLOAT, sizeof(GLfloat) * 5, (void *)0);
		this->post_proc_vao.link_attr(this->post_proc_vbo, 1, 2, GL_FLOAT, sizeof(GLfloat) * 5, (void *)(sizeof(GLfloat) * 3));
		this->post_proc_vao.unbind();

		this->post_proc_frame_buffer.generate(this->settings.width, this->settings.height);
	}

	this->particle_vao.init();
	this->particle_vao.bind();
	this->particle_ssbo = SSBO(NULL, sizeof(mlm::vec4) * 2 * this->settings.particle_count, GL_DYNAMIC_DRAW);
	this->particle_vao.link_attr_ssbo(this->particle_ssbo, 0, 3, GL_FLOAT, sizeof(GLfloat) * 8, (void *)0);
	this->particle_vao.link_attr_ssbo(this->particle_ssbo, 1, 3, GL_FLOAT, sizeof(GLfloat) * 8, (void *)(sizeof(GLfloat) * 4));
	this->particle_vao.unbind();

	this->initialized.buffers = true;
}

/*
//	Initialize the particles to the start position using the init compute shader
*/
void	App::init_particles()
{
	std::cout << "Initializing particles..." << std::endl;
	// Setup shader
	this->particle_init.use();
	this->particle_ssbo.bind();
	this->particle_init.set_float("radius", this->settings.particle_init_radius);
	this->particle_init.set_uint("frame", (uint)((float)rand() / 2147483647.0f * 10000.0f));
	this->particle_init.set_vec3("pos", this->settings.particle_init_pos);

	// Run shader
	glDispatchCompute((GLuint)this->settings.particle_count / WORKGROUP_SIZE, 1, 1);
	glMemoryBarrier(GL_VERTEX_ATTRIB_ARRAY_BARRIER_BIT);
}

/*
//	Initializes the necessary buffers/shaders and data for the simulation to run
*/
void	App::init(Config &config)
{
	// Init settings from config
	this->settings = Settings(config);
	this->state = State(config);

	// Initialize GLFW and the window
	this->init_gl();

	// Initialize the font and text renderer
	this->init_text(
		config.font->c_str(),
		config.font_vert->c_str(),
		config.font_frag->c_str()
	);

	this->init_buffers();
	this->init_shaders(config);
	this->init_particles();

	// Set correct render settings
	glEnable(GL_CULL_FACE);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glPointSize(this->settings.particle_size);

	// Set cursor callback function
	glfwSetCursorPosCallback(this->window, cursor_position_callback);
}
