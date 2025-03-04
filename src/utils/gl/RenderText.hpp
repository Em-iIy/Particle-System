#pragma once

// Holds all state information relevant to a character as loaded using FreeType
struct Character {
    unsigned int	tex_id; // ID handle of the glyph texture
    mlm::vec2		size;      // Size of glyph
    mlm::vec2		bearing;   // Offset from baseline to left/top of glyph
    unsigned int	advance;   // Horizontal offset to advance to next glyph
};

#include <GLAD/glad.h>
#include <map>

typedef std::map<GLchar, Character> Font;

Font	init_font(const char *font_file);
void	delete_text_renderer();
void	init_text_renderer(const char *vertex_shader, const char *fragment_shader, int &width, int &height);
void	render_text(Font &font, std::string text, float x, float y, float scale, mlm::vec3 color);
