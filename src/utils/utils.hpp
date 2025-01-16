/*
Created by: Emily (Em_iIy) Winnink
Created on: 16/12/2024
*/
#pragma once

#include <vector>

#include "gl/VAO.hpp"
#include "gl/VBO.hpp"
#include "gl/EBO.hpp"
#include "gl/SSBO.hpp"
#include "gl/RenderBuffer.hpp"
#include "gl/FrameBuffer.hpp"
#include "gl/Shader.hpp"
#include "gl/ComputeShader.hpp"
#include "gl/Window.hpp"
#include "gl/Key.hpp"
#include "gl/textures.hpp"
#include "input.hpp"

char 						*read_file(const char *file_name);

std::vector<std::string>	split(const std::string &str, const std::string &d);
void						split(std::vector<std::string> &vect, const std::string &str, const std::string &d);

float						delta_time_update(void);

void						print_controls(void);
