#include "../mlm/vec1.hpp"
#include "../mlm/vec2.hpp"
#include "../mlm/vec3.hpp"
#include "../mlm/vec4.hpp"
#include "../mlm/abs.hpp"

namespace mlm {

vec1	normalize(const vec1 &v)
{
	return (v / abs(v));
}

vec2	normalize(const vec2 &v)
{
	return (v / abs(v));
}

vec3	normalize(const vec3 &v)
{
	return (v / abs(v));
}

vec4	normalize(const vec4 &v)
{
	return (v / abs(v));
}

}
