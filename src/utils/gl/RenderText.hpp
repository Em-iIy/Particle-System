#pragma once

// Holds all state information relevant to a character as loaded using FreeType
struct Character {
    unsigned int TextureID; // ID handle of the glyph texture
    mlm::vec2   Size;      // Size of glyph
    mlm::vec2   Bearing;   // Offset from baseline to left/top of glyph
    unsigned int Advance;   // Horizontal offset to advance to next glyph
};

#include <GLAD/glad.h>
#include <map>

typedef std::map<GLchar, Character> Font;

Font	init_font(const char *font_file);
void	init_text_renderer(const char *vertex_shader, const char *fragment_shader, int &width, int &height);
void	RenderText(Font &font, std::string text, float x, float y, float scale, mlm::vec3 color);
