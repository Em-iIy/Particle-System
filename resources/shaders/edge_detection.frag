#version 430 core
out vec4 FragColor;

in vec2 tex;

uniform sampler2D screen_tex;

void main()
{
	float offset = 0.0005f;
	vec2 offsets[9] = vec2[] (
		vec2(-offset, offset),
		vec2(0.0, offset),
		vec2(offset, offset),
		vec2(-offset, 0.0),
		vec2(0.0, 0.0),
		vec2(offset, 0.0),
		vec2(-offset, -offset),
		vec2(0.0, -offset),
		vec2(offset, -offset)
	);

	float kernel[9] = float[] (
		1, 1, 1,
		1, -8, 1,
		1, 1, 1
	);
	vec3 color = vec3(0.0);
	for (int i = 0; i < 9; i++)
	{
		color += vec3(texture(screen_tex, tex.st + offsets[i])) * kernel[i];
	}
	FragColor = vec4(color, 1.0);
}
