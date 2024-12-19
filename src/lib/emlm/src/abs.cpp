#include <cmath>

#include "../mlm/vec1.hpp"
#include "../mlm/vec2.hpp"
#include "../mlm/vec3.hpp"
#include "../mlm/vec4.hpp"
#include "../mlm/dot.hpp"

namespace mlm {

float	abs(const vec1 &v)
{
	return (sqrt(dot(v, v)));
}

float	abs(const vec2 &v)
{
	return (sqrt(dot(v, v)));
}

float	abs(const vec3 &v)
{
	return (sqrt(dot(v, v)));
}

float	abs(const vec4 &v)
{
	return (sqrt(dot(v, v)));
}

}
