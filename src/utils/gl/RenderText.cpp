#include <map>
#include <string>
#include <iostream>

#include "utils.hpp"
#include "emlm/emlm.hpp"
#include "RenderText.hpp"

#include <ft2build.h>
#include FT_FREETYPE_H


mlm::mat4 projection(1.0f);
Shader shader;

GLuint vao;
GLuint vbo;

Font	init_font(const char *font_file)
{
	Font characters;
	
	FT_Library ft;
	if (FT_Init_FreeType(&ft))
	{
		std::cerr << "FreeType Error: Could not initialize FreeType";
		exit(EXIT_FAILURE);
	}

	FT_Face face;
	if (FT_New_Face(ft, font_file, 0, &face))
	{
		std::cerr << "FreeType Error: Could not load font: " << font_file << std::endl;
		FT_Done_FreeType(ft);
		exit(EXIT_FAILURE);
	}

	FT_Set_Pixel_Sizes(face, 256, 256);

	// disable byte-alignment restriction
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

	for (u_char c = 0; c < 128; c++)
	{
		if (FT_Load_Char(face, c, FT_LOAD_RENDER))
		{
			std::cerr << "FreeType Error: Could not load char: " << c << std::endl;
			FT_Done_Face(face);
			FT_Done_FreeType(ft);
			exit(EXIT_FAILURE);
		}
		GLuint texture;
		glGenTextures(1, &texture);
			glBindTexture(GL_TEXTURE_2D, texture);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RED, face->glyph->bitmap.width, face->glyph->bitmap.rows, 0, GL_RED, GL_UNSIGNED_BYTE, face->glyph->bitmap.buffer);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		Character character = {
			texture,
			mlm::vec2(face->glyph->bitmap.width, face->glyph->bitmap.rows),
			mlm::vec2(face->glyph->bitmap_left, face->glyph->bitmap_top),
			static_cast<unsigned int>(face->glyph->advance.x)
		};
		characters.insert(std::pair<char, Character>(c, character));
	}
	glBindTexture(GL_TEXTURE_2D, 0);
	FT_Done_Face(face);
	FT_Done_FreeType(ft);
	return (characters);
}

void	delete_text_renderer()
{
	shader.del();
	glDeleteBuffers(1, &vao);
	glDeleteBuffers(1, &vbo);
}

void	init_text_renderer(const char *vertex_shader, const char *fragment_shader, int &width, int &height)
{
	shader = Shader(vertex_shader, fragment_shader);
	projection = mlm::ortho(0.0f, static_cast<float>(width), 0.0f, static_cast<float>(height));
	shader.use();
	shader.set_mat4("projection", projection);

	glGenVertexArrays(1, &vao);
	glGenBuffers(1, &vbo);
	glBindVertexArray(vao);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 6 * 4, NULL, GL_DYNAMIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(float), 0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

void RenderText(Font &font, std::string text, float x, float y, float scale, mlm::vec3 color)
{
	float x_copy = x;
	shader.use();
	shader.set_vec3("text_color", color);

	glActiveTexture(GL_TEXTURE0);
	glBindVertexArray(vao);
	scale = scale / 256.0f * 48.0f;
	std::string::const_iterator c;
	for (c = text.begin(); c != text.end(); c++) 
	{
		Character ch = font[*c];
		if (*c == '\n')
		{
			y -= ch.Size.y * 1.3 * scale;
			x = x_copy;
		}
		else if (std::isspace(*c))
		{
			x += (ch.Advance >> 6) * scale;
		}
		else
		{
			float xpos = x + ch.Bearing.x * scale;
			float ypos = y - (ch.Size.y - ch.Bearing.y) * scale;

			float w = ch.Size.x * scale;
			float h = ch.Size.y * scale;
			// update VBO for each character
			float vertices[6][4] = {
				{ xpos,	 ypos + h,   0.0f, 0.0f },			
				{ xpos,	 ypos,	   0.0f, 1.0f },
				{ xpos + w, ypos,	   1.0f, 1.0f },

				{ xpos,	 ypos + h,   0.0f, 0.0f },
				{ xpos + w, ypos,	   1.0f, 1.0f },
				{ xpos + w, ypos + h,   1.0f, 0.0f }		   
			};
			// render glyph texture over quad
			glBindTexture(GL_TEXTURE_2D, ch.TextureID);
			// update content of VBO memory
			glBindBuffer(GL_ARRAY_BUFFER, vbo);
			glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(vertices), vertices); // be sure to use glBufferSubData and not glBufferData

			glBindBuffer(GL_ARRAY_BUFFER, 0);
			// render quad
			glDrawArrays(GL_TRIANGLES, 0, 6);
			// now advance cursors for next glyph (note that advance is number of 1/64 pixels)
			x += (ch.Advance >> 6) * scale; // bitshift by 6 to get value in pixels (2^6 = 64 (divide amount of 1/64th pixels by 64 to get amount of pixels))

		}
	}
	glBindVertexArray(0);
	glBindTexture(GL_TEXTURE_2D, 0);
}
