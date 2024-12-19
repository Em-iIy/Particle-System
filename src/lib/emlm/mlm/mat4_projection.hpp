#pragma once

#include "../mlm/mat4.hpp"

namespace mlm {

// perspective
mat4	perspective(const float &fov, const float &near, const float &far);
mat4	perspective(const float &fov, const float &aspect, const float &near, const float &far);

}
