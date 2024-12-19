#version 430 core

out vec4 FragColor;

in vec2	tex;

uniform sampler2D	tex0;

void main()
{
	FragColor = vec4(texture(tex0, tex).rgb, 1.0);
}
