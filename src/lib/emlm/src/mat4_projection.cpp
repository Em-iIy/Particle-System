#include <cmath>

#include "../mlm/mat4.hpp"

namespace mlm {

// perspective
// http://www.songho.ca/opengl/gl_projectionmatrix.html#perspective
// https://www.scratchapixel.com/lessons/3d-basic-rendering/perspective-and-orthographic-projection-matrix/building-basic-perspective-projection-matrix.html
mat4	perspective(const float &fov, const float &near, const float &far)
{
	float scale = 1 / tan(fov * 0.5 * M_PI / 180);
	float diff = far - near;
	return (mat4(
		scale, 0.0f, 0.0f, 0.0f,
		0.0f, scale, 0.0f, 0.0f,
		0.0f, 0.0f, -(far / diff), -1.0f,
		0.0f, 0.0f, -((far * near) / diff), 0.0f
	));
}


mat4	perspective(const float &fov, const float &aspect, const float &near, const float &far)
{
	float tan_fov = tan(fov / 2);
	float diff = far - near;
	return (mat4(
		1 / (aspect * tan_fov), 0.0f, 0.0f, 0.0f,
		0.0f, 1 / tan_fov, 0.0f, 0.0f,
		0.0f, 0.0f, -(far / diff), -1.0f,
		0.0f, 0.0f, -(far * near)  / diff, 0.0f
	));
}

}
