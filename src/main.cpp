/*
Created by: Emily (Em_iIy) Winnink
Created on: 16/12/2024
*/

#include "utils.hpp"
#include "emlm/emlm.hpp"
#include <cmath>
#include <ctime>

#include "Config.hpp"

// #define WIDTH 1920
// #define HEIGHT 1080
#define WIDTH 3840
#define HEIGHT 2160
#define FOV 100.0f


#define VIEW_BOX_DIMENSIONS 2000.0f
#define START_DISTANCE 1000.0f
#define SPEED 5.f
// #define SPEED 20.f

#define RADIUS 250.0f

#define POSTPROCESSING false
#define VSYNC false

Config 		config;
float		g_delta_time = 0.0f;
int			particle_count = 0;
mlm::vec2	mouse_coords(WIDTH / 2.0f, HEIGHT / 2.0f);
bool		g_pause = false;
GLuint		fbo;
GLuint		rbo;
GLuint		rtex;
int			width = WIDTH;
int			height = HEIGHT;
float		mass = 0.0000001f;
mlm::vec3	color1;
mlm::vec3	color2;

void APIENTRY glDebugOutput(GLenum source, GLenum type, GLuint id, GLenum severity,
                            GLsizei length, const GLchar* message, const void* userParam) {
    std::cerr << "GL CALLBACK: " << message << std::endl;
}

static void cursor_position_callback(GLFWwindow* window, double xpos, double ypos)
{
    mouse_coords = mlm::vec2(xpos, ypos);
}

mlm::vec3 mouse_to_gravity()
{
	float gravityZ = -0.5f * *(config.view_box_dimensions);

	// Compute half-width and half-height at this depth
	float halfHeight = tan(mlm::radians(*(config.fov)) / 2.0f) * fabs(gravityZ);
	float halfWidth = halfHeight * ((float)width / (float)height); // Aspect ratio scaling

	// Convert mouse coordinates to normalized device coordinates (NDC)
	float ndcX = 2.0f * mouse_coords.x / width - 1.0f;
	float ndcY = 1.0f - 2.0f * mouse_coords.y / height; // Flip Y for OpenGL

	// Map NDC coordinates to world space
	float worldX = ndcX * halfWidth;
	float worldY = ndcY * halfHeight;

	// Gravity point in world space
	return (mlm::vec3(worldX, worldY, gravityZ));
}

mlm::vec3	rand_vec3()
{
	return (mlm::vec3(rand() / 2147483648.0f, rand() / 2147483648.0f, rand() / 2147483648.0f));
}

GLfloat	vertices[] = {
	1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
	-1.0f, 1.0f, 1.0f, 0.0f, 1.0f,
	1.0f, -1.0f, 1.0f, 1.0f, 0.0f,
	-1.0f, -1.0f, 1.0f, 0.0f, 0.0f
};

GLuint indices[] = {
	0, 1, 3,
	0, 2, 3
};

int main(int argc, char **argv)
{

	if (argc != 3)
	{
		std::cerr << "Invalid input!\n";
		std::cerr << "Usage:\n";
		std::cerr << "particle-system -c,--config <config file>\n";
		return (1);
	}
	try
	{
		config.load(argv[2]);
	}
	catch(...)
	{
		return (1);
	}
	
	srand(std::time(NULL));
	init_glfw();
	width = *(config.width);
	height = *(config.height);
	// GLFWwindow *window = init_window(&width, &height, "particle-system", NULL, NULL, VSYNC);
	GLFWwindow *window = init_fullscreen_window(config.title->c_str(), *(config.vsync));
	glfwSetCursorPosCallback    (window, cursor_position_callback);
	// return (1);
	uint	random = (uint)((float)rand() / 2147483647.0f * 10000.0f);
    // Enable OpenGL debug output
    // glEnable(GL_DEBUG_OUTPUT);
    // glDebugMessageCallback(glDebugOutput, nullptr);
	std::map<GLchar, Character> font = init_font(config.font->c_str());
	init_text_renderer(config.font_vert->c_str(), config.font_frag->c_str());

	particle_count = *(config.particle_count);
	color1 = *(config.color1);
	color2 = *(config.color2);
	VAO quad_vao(1);
	quad_vao.bind();
	VBO quad_vbo(vertices, sizeof(vertices));
	quad_vao.link_attr(quad_vbo, 0, 3, GL_FLOAT, sizeof(GLfloat) * 5, (void *)0);
	quad_vao.link_attr(quad_vbo, 1, 2, GL_FLOAT, sizeof(GLfloat) * 5, (void *)(sizeof(GLfloat) * 3));
	quad_vao.unbind();

	VAO particle_vao(1);
	particle_vao.bind();
	SSBO ssbo(NULL, sizeof(mlm::vec4) * 2 * particle_count, GL_DYNAMIC_DRAW);
	particle_vao.link_attr_ssbo(ssbo, 0, 3, GL_FLOAT, sizeof(GLfloat) * 8, (void *)0);
	particle_vao.link_attr_ssbo(ssbo, 1, 3, GL_FLOAT, sizeof(GLfloat) * 8, (void *)(sizeof(GLfloat) * 4));
	particle_vao.unbind();

	ComputeShader	particle_init_shader(config.particle_init_comp->c_str());
	ComputeShader	physics(config.particle_physics_comp->c_str());
	Shader			particle_shader(config.particle_vert->c_str(), config.particle_frag->c_str());
	Shader			quad_shader;
	FrameBuffer 	post_proc_frame_buffer;
	if (*(config.post_processing))
	{
		quad_shader = Shader(config.post_processing_vert->c_str(), config.post_processing_frag->c_str());
		post_proc_frame_buffer.generate(width, height);
	}
	particle_init_shader.use();
	ssbo.bind();
	particle_init_shader.set_float("radius", *(config.particle_init_radius));
	particle_init_shader.set_uint("frame", random);
	particle_init_shader.set_vec3("pos", *(config.particle_init_pos));
	glDispatchCompute((GLuint)particle_count / WORKGROUP_SIZE, 1, 1);
	glMemoryBarrier(GL_VERTEX_ATTRIB_ARRAY_BARRIER_BIT);
	int		fCounter = 0;
	float	ftime = 0.0f;
	float	run_time = 0.0f;

	std::string fps = "";

	glEnable(GL_CULL_FACE);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glPointSize(*(config.particle_size));
	while (!glfwWindowShouldClose(window))
	{
		if (*(config.post_processing))
		{
			// Bind to the frame buffer
			post_proc_frame_buffer.bind();
			glEnable(GL_DEPTH_TEST);
		}
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		float	speed = SPEED;
		float time = glfwGetTime();
		mlm::vec3 gravity;
		input::process(window);
		g_delta_time = delta_time_update();
		if (ftime > 1.0f)
		{
				float f_fps = 1.0f / (ftime / fCounter);
				fps = std::to_string((int)f_fps);
				std::cout << "FPS: " << fps << std::endl;
				fCounter = 0;
				ftime = 0.0f;
		}
		else
		{
			fCounter++;
			ftime += g_delta_time;
		}	

		if (g_pause == false)
		{

			float frame_time = g_delta_time * speed;
			run_time += frame_time;
			// mlm::vec3 point = mlm::vec3(sinf(run_time * 0.1f), cosf(run_time * 0.1f), 0.0f);
			gravity = mouse_to_gravity();
			// gravity = mlm::vec3(0.0f, 0.0f, -START_DISTANCE) + 500.0f * point;
		}

		physics.use();
		ssbo.bind();
		physics.set_vec3("gravity", gravity);
		physics.set_float("delta_time", g_delta_time);
		physics.set_float("speed", speed);
		physics.set_float("mass", mass);
		if (g_pause == false)
		{
			glDispatchCompute((GLuint)particle_count / WORKGROUP_SIZE, 1, 1);
			glMemoryBarrier(GL_VERTEX_ATTRIB_ARRAY_BARRIER_BIT);
		}


		mlm::mat4	projection = mlm::perspective(mlm::radians(*(config.fov)), (float)width / (float)height, 0.1f, 2.0f * *(config.view_box_dimensions));
		mlm::mat4	model(1.0f);
		model = mlm::translate(model, mlm::vec3(0.0f, 5.0f, -25.0f));
		particle_shader.use();
		mlm::mat4	view(1.0f);
		particle_shader.set_float("time", std::abs(sinf(time)));
		particle_shader.set_float("dimensions", *(config.view_box_dimensions));
		particle_shader.set_mat4("model", model);
		particle_shader.set_mat4("view", view);
		particle_shader.set_mat4("projection", projection);
		particle_shader.set_vec3("gravity", gravity);
		particle_shader.set_vec3("color1", color1);
		particle_shader.set_vec3("color2", color2);
		particle_vao.bind();
		glDrawArrays(GL_POINTS, 0, particle_count);
		if (*(config.post_processing))
		{
			post_proc_frame_buffer.unbind();
			glDisable(GL_DEPTH_TEST);

			glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);
			quad_shader.use();

			post_proc_frame_buffer.render_texture.bind();
			quad_vao.bind();
			glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);

		}

		{
			std::string info_to_render = "Fps: " + fps;
			info_to_render += "\nParticles: " + std::to_string(particle_count);
			info_to_render += "\nMass: " + std::to_string(mass);
			info_to_render += "\ngravity = x(" + std::to_string(float(gravity.x)) + ") y(" + std::to_string(float(gravity.y)) + ") z(" + std::to_string(float(gravity.z)) + ")";
			info_to_render += "\nColor1 = R(" + std::to_string(int(color1.x * 255.0f)) + ") G(" + std::to_string(int(color1.y * 255.0f)) + ") B(" + std::to_string(int(color1.z * 255.0f)) + ")";
			info_to_render += "\nColor2 = R(" + std::to_string(int(color2.x * 255.0f)) + ") G(" + std::to_string(int(color2.y * 255.0f)) + ") B(" + std::to_string(int(color2.z * 255.0f)) + ")";
			RenderText(font, info_to_render, 0.0f, height - 40.0f, 0.5f, mlm::vec3(1.0f));
		}
		if (g_pause == true)
		{
			RenderText(font, "PAUSED", 0.0f, height - 400.0f, 5.f, mlm::vec3(1.0f));
		}

		glfwSwapBuffers(window);
		glfwPollEvents();
	}
}
