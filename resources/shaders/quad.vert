#version 330 core

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aNormal;
layout (location = 2) in vec3 aColor;
layout (location = 3) in vec2 aTex;

out vec2 tex;

void main()
{
	gl_Position = vec4(aPos.xy, 0.0f, 1.0f);
	tex = aTex;
}