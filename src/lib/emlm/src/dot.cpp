#include "../mlm/vec1.hpp"
#include "../mlm/vec2.hpp"
#include "../mlm/vec3.hpp"
#include "../mlm/vec4.hpp"

namespace mlm {

float	dot(const vec1 &v1, const vec1 &v2)
{
	return (v1.x * v2.x);
}

float	dot(const vec2 &v1, const vec2 &v2)
{
	return (v1.x * v2.x + v1.y * v2.y);
}

float	dot(const vec3 &v1, const vec3 &v2)
{
	return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
}

float	dot(const vec4 &v1, const vec4 &v2)
{
	return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z + v1.w * v2.w);
}

}
