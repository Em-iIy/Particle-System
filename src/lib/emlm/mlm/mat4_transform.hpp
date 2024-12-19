#pragma once

#include "../mlm/mat4.hpp"
#include "../mlm/vec3.hpp"

namespace mlm {

mat4	rotate(const mat4 &m, const float &θ, const vec3 &v);

mat4	translate(const mat4 &m, const vec3 &v);

mat4	scale(const mat4 &m, const vec3 &v);


}
