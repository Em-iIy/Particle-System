#version 430 core

out vec4 FragColor;

in vec3 pos;
in vec3 dir;

uniform vec3 gravity;

void main()
{
	FragColor = vec4(1.0, 0.5, 0.0, 1.0);
	vec3	gravity_dir = gravity - pos.xyz;
	float	dist = length(gravity_dir);
	// FragColor *= dist * 2.0;
	FragColor = vec4(pos * 0.5 + 0.5, 1.0);
}