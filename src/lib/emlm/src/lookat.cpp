#include "../mlm/mat4_transform.hpp"
#include "../mlm/normalize.hpp"
#include "../mlm/cross.hpp"
#include "../mlm/dot.hpp"
#include "../mlm/vec3.hpp"
#include "../mlm/mat4.hpp"

namespace mlm {

mat4	lookat(const vec3 &pos, const vec3 &front, const vec3 &in_up)
{
	vec3 dir(normalize(front - pos));
	vec3 right(normalize(cross(dir, in_up)));
	vec3 up(cross(right, dir));

	return (mat4(
		right.x, up.x, -dir.x, 0.0f,
		right.y, up.y, -dir.y, 0.0f,
		right.z, up.z, -dir.z, 0.0f,
		-dot(right, pos), -dot(up, pos), dot(dir, pos), 1.0f
	));
}

}
