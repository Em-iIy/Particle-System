#version 430 core
out vec4 FragColor;

in vec2 tex;

uniform sampler2D screen_tex;

void main()
{
	FragColor = texture(screen_tex, tex);
}
