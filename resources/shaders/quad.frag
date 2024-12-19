#version 330 core
out vec4 FragColor;

in vec2 tex;

uniform sampler2D screen_tex;

uniform float wave;

void main()
{
	// float offset = distance(vec2(0.5, 0.5), tex) * 1.0 / 135.0 * (wave / 2.0f + 0.5);
	float offset = distance(vec2(0.5, 0.5), tex) * 1.0 / 135.0;
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

	// float kernel[9] = float[] (
	// 	2, 2, 2,
	// 	2, -15, 2,
	// 	2, 2, 2
	// );

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
	// color = color * step(0.9, color) * vec3(1.0, 0.0, 0.0);
	FragColor = vec4(color, 1.0);
	// FragColor += texture(screen_tex, tex);
	float red_color = texture(screen_tex, tex.st + offsets[6]).r;
	float green_color = texture(screen_tex, tex.st + offsets[8]).g;
	float blue_color = texture(screen_tex, tex.st + offsets[1]).b;
	FragColor = vec4(red_color, green_color, blue_color, 1.0);
}

// void main()
// {
// 	FragColor = texture(screen_tex, tex);
// }
// void main()
// {
// 	FragColor = vec4(vec3(1.0 - texture(screen_tex, tex)), 1.0);
// }