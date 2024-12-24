#version 430 core

layout (location = 0) in vec4 particle_pos;
layout (location = 1) in vec4 particle_dir;

out	vec3 pos;
out	vec3 dir;

uniform mat4 model;
uniform mat4 projection;

void main()
{
	gl_Position = projection * model * vec4(particle_pos);
	// gl_Position = vec4(particle_pos, 1.0);
	pos = normalize(particle_pos.xyz);
	dir = particle_dir.xyz;
}
