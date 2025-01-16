#version 430 core

layout (location = 0) in vec3 particle_pos;
layout (location = 1) in vec3 particle_dir;

out	vec3 pos;
out	vec3 dir;
out float	len;

uniform mat4 model;
uniform mat4 projection;

void main()
{
	gl_Position = projection * model * vec4(particle_pos, 1.0);
	pos = particle_pos;
	dir = particle_dir;
}
