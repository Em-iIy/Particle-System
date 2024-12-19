#version 330 core
out vec4 FragColor;

uniform sampler2D	tex0;
uniform float		tex_mix;

in vec3	color;
in vec3	normal;
in vec2	tex;

void main()
{
	vec4 tex_color = texture(tex0, tex);
	FragColor = mix(vec4(color, 1.0f), vec4(normal, 1.0f), 0.4f);
	FragColor = mix(FragColor, tex_color, tex_mix);
	if (FragColor.a < 0.1f)
		discard;
	// https://en.wikipedia.org/wiki/Grayscale#Luma_coding_in_video_systems
	float gray_scale = 0.299f * FragColor.r + 0.587f * FragColor.g + 0.114f * FragColor.b;
	FragColor = vec4(vec3(gray_scale), 1.0f);
}
