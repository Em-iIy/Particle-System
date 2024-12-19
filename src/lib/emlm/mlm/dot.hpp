#pragma once

#include "vec1.hpp"
#include "vec2.hpp"
#include "vec3.hpp"
#include "vec4.hpp"

namespace mlm {

float	dot(const vec1 &v1, const vec1 &v2);

float	dot(const vec2 &v1, const vec2 &v2);

float	dot(const vec3 &v1, const vec3 &v2);

float	dot(const vec4 &v1, const vec4 &v2);

}
