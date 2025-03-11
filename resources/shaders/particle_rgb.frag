#version 430 core

out vec4 FragColor;

in vec3 pos;
in vec3 dir;

layout (location = 1) uniform vec3 gravity;
layout (location = 2) uniform vec3 color1;
layout (location = 3) uniform vec3 color2;
layout (location = 4) uniform float dimensions;

void main()
{
	vec3	gravity_dir = gravity - pos;
	float	dist = clamp(1.0f - length(gravity_dir) / dimensions, 0.0, 1.0);
	FragColor = vec4(mix(color1, color2, dist * dist * dist), 1.0);
}