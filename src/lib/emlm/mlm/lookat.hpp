#pragma once

#include "../mlm/mat4.hpp"
#include "../mlm/vec3.hpp"

namespace mlm {


mat4	lookat(const vec3 &pos, const vec3 &front, const vec3 &up);

}
