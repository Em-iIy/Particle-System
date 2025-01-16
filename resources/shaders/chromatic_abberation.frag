#version 430 core
out vec4 FragColor;

in vec2 tex;

uniform sampler2D screen_tex;

void main()
{
	float offset = distance(vec2(0.5, 0.5), tex) * (1.0 / 250.0);
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

	float red_color = texture(screen_tex, tex.st + offsets[6]).r;
	float green_color = texture(screen_tex, tex.st + offsets[8]).g;
	float blue_color = texture(screen_tex, tex.st + offsets[1]).b;
	FragColor = vec4(red_color, green_color, blue_color, 1.0);
}
