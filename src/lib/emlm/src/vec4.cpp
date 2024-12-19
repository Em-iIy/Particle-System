#include "../mlm/vec4.hpp"
#include <cassert>

namespace mlm {

vec4::vec4(const float &_x, const float &_y, const float &_z, const float &_w): x(_x), y(_y), z(_z), w(_w) {}
vec4::vec4(const float &_x, const float &_y, const float &_z, const vec1 &_w): x(_x), y(_y), z(_z), w(_w.x) {}
vec4::vec4(const float &_x, const float &_y, const vec1 &_z, const float &_w): x(_x), y(_y), z(_z.x), w(_w) {}
vec4::vec4(const float &_x, const float &_y, const vec1 &_z, const vec1 &_w): x(_x), y(_y), z(_z.x), w(_w.x) {}
vec4::vec4(const float &_x, const vec1 &_y, const float &_z, const float &_w): x(_x), y(_y.x), z(_z), w(_w) {}
vec4::vec4(const float &_x, const vec1 &_y, const float &_z, const vec1 &_w): x(_x), y(_y.x), z(_z), w(_w.x) {}
vec4::vec4(const float &_x, const vec1 &_y, const vec1 &_z, const float &_w): x(_x), y(_y.x), z(_z.x), w(_w) {}
vec4::vec4(const float &_x, const vec1 &_y, const vec1 &_z, const vec1 &_w): x(_x), y(_y.x), z(_z.x), w(_w.x) {}
vec4::vec4(const vec1 &_x, const float &_y, const float &_z, const float &_w): x(_x.x), y(_y), z(_z), w(_w) {}
vec4::vec4(const vec1 &_x, const float &_y, const float &_z, const vec1 &_w): x(_x.x), y(_y), z(_z), w(_w.x) {}
vec4::vec4(const vec1 &_x, const float &_y, const vec1 &_z, const float &_w): x(_x.x), y(_y), z(_z.x), w(_w) {}
vec4::vec4(const vec1 &_x, const float &_y, const vec1 &_z, const vec1 &_w): x(_x.x), y(_y), z(_z.x), w(_w.x) {}
vec4::vec4(const vec1 &_x, const vec1 &_y, const float &_z, const float &_w): x(_x.x), y(_y.x), z(_z), w(_w) {}
vec4::vec4(const vec1 &_x, const vec1 &_y, const float &_z, const vec1 &_w): x(_x.x), y(_y.x), z(_z), w(_w.x) {}
vec4::vec4(const vec1 &_x, const vec1 &_y, const vec1 &_z, const float &_w): x(_x.x), y(_y.x), z(_z.x), w(_w) {}
vec4::vec4(const vec1 &_x, const vec1 &_y, const vec1 &_z, const vec1 &_w): x(_x.x), y(_y.x), z(_z.x), w(_w.x) {}

vec4::vec4(const vec2 &_xy, const float &_z, const float &_w): x(_xy.x), y(_xy.y), z(_z), w(_w) {}
vec4::vec4(const vec2 &_xy, const vec1 &_z, const float &_w): x(_xy.x), y(_xy.y), z(_z.x), w(_w) {}
vec4::vec4(const vec2 &_xy, const float &_z, const vec1 &_w): x(_xy.x), y(_xy.y), z(_z), w(_w.x) {}
vec4::vec4(const vec2 &_xy, const vec1 &_z, const vec1 &_w): x(_xy.x), y(_xy.y), z(_z.x), w(_w.x) {}
vec4::vec4(const float &_x, const vec2 &_yz, const float &_w): x(_x), y(_yz.x), z(_yz.y), w(_w) {}
vec4::vec4(const vec1 &_x, const vec2 &_yz, const float &_w): x(_x.x), y(_yz.x), z(_yz.y), w(_w) {}
vec4::vec4(const float &_x, const vec2 &_yz, const vec1 &_w): x(_x), y(_yz.x), z(_yz.y), w(_w.x) {}
vec4::vec4(const vec1 &_x, const vec2 &_yz, const vec1 &_w): x(_x.x), y(_yz.x), z(_yz.y), w(_w.x) {}
vec4::vec4(const float &_x, const float &_y, const vec2 &_zw): x(_x), y(_y), z(_zw.x), w(_zw.y) {}
vec4::vec4(const vec1 &_x, const float &_y, const vec2 &_zw): x(_x.x), y(_y), z(_zw.x), w(_zw.y) {}
vec4::vec4(const float &_x, const vec1 &_y, const vec2 &_zw): x(_x), y(_y.x), z(_zw.x), w(_zw.y) {}
vec4::vec4(const vec1 &_x, const vec1 &_y, const vec2 &_zw): x(_x.x), y(_y.x), z(_zw.x), w(_zw.y) {}

vec4::vec4(const vec2 &_xy, const vec2 &_zw): x(_xy.x), y(_xy.y), z(_zw.x), w(_zw.y) {}
vec4::vec4(const vec3 &_xyz, const float &_w): x(_xyz.x), y(_xyz.y), z(_xyz.z), w(_w) {}
vec4::vec4(const vec3 &_xyz, const vec1 &_w): x(_xyz.x), y(_xyz.y), z(_xyz.z), w(_w.x) {}
vec4::vec4(const float &_x, const vec3 &_yzw): x(_x), y(_yzw.x), z(_yzw.y), w(_yzw.z) {}
vec4::vec4(const vec1 &_x, const vec3 &_yzw): x(_x.x), y(_yzw.x), z(_yzw.y), w(_yzw.z) {}

vec4::vec4(const float &scalar): x(scalar), y(scalar), z(scalar), w(scalar) {}
vec4::vec4(const vec1 &scalar): x(scalar.x), y(scalar.x), z(scalar.x), w(scalar.x) {}
vec4::vec4(const vec4 &v): x(v.x), y(v.y), z(v.z), w(v.w) {}

vec4::vec4() {};
vec4::~vec4() {};


float	&vec4::operator[](unsigned int i)
{
	assert(i < 4);
	switch (i)
	{
	default:
	case 0:
		return (this->x);
	case 1:
		return (this->y);
	case 2:
		return (this->z);
	case 3:
		return (this->w);
	}
}
const float	&vec4::operator[](unsigned int i) const
{
	assert(i < 4);
	switch (i)
	{
	default:
	case 0:
		return (this->x);
	case 1:
		return (this->y);
	case 2:
		return (this->z);
	case 3:
		return (this->w);
	}
}

vec4	&vec4::operator=(const vec4 &v)
{
	this->x = v.x;
	this->y = v.y;
	this->z = v.z;
	this->w = v.w;
	return (*this);
}

bool	vec4::operator==(const vec4 &v)
{
	return (this->x == v.x && this->y == v.y && this->z == v.z && this->w == v.w);
}
bool	vec4::operator!=(const vec4 &v)
{
	return (this->x != v.x && this->y != v.y && this->z != v.z && this->w != v.w);
}

vec4	&vec4::operator-=(const vec4 &v)
{
	this->x -= v.x;
	this->y -= v.y;
	this->z -= v.z;
	this->w -= v.w;
	return (*this);
}

vec4	&vec4::operator-=(const vec1 &scalar)
{
	this->x -= scalar.x;
	this->y -= scalar.x;
	this->z -= scalar.x;
	this->w -= scalar.x;
	return (*this);
}

vec4	&vec4::operator-=(const float &scalar)
{
	this->x -= scalar;
	this->y -= scalar;
	this->z -= scalar;
	this->w -= scalar;
	return (*this);
}

vec4	&vec4::operator+=(const vec4 &v)
{
	this->x += v.x;
	this->y += v.y;
	this->z += v.z;
	this->w += v.w;
	return (*this);
}

vec4	&vec4::operator+=(const vec1 &scalar)
{
	this->x += scalar.x;
	this->y += scalar.x;
	this->z += scalar.x;
	this->w += scalar.x;
	return (*this);
}

vec4	&vec4::operator+=(const float &scalar)
{
	this->x += scalar;
	this->y += scalar;
	this->z += scalar;
	this->w += scalar;
	return (*this);
}

vec4	&vec4::operator*=(const vec4 &v)
{
	this->x *= v.x;
	this->y *= v.y;
	this->z *= v.z;
	this->w *= v.w;
	return (*this);
}

vec4	&vec4::operator*=(const vec1 &scalar)
{
	this->x *= scalar.x;
	this->y *= scalar.x;
	this->z *= scalar.x;
	this->w *= scalar.x;
	return (*this);
}

vec4	&vec4::operator*=(const float &scalar)
{
	this->x *= scalar;
	this->y *= scalar;
	this->z *= scalar;
	this->w *= scalar;
	return (*this);
}

vec4	&vec4::operator/=(const vec4 &v)
{
	this->x /= v.x;
	this->y /= v.y;
	this->z /= v.z;
	this->w /= v.w;
	return (*this);
}

vec4	&vec4::operator/=(const vec1 &scalar)
{
	this->x /= scalar.x;
	this->y /= scalar.x;
	this->z /= scalar.x;
	this->w /= scalar.x;
	return (*this);
}

vec4	&vec4::operator/=(const float &scalar)
{
	this->x /= scalar;
	this->y /= scalar;
	this->z /= scalar;
	this->w /= scalar;
	return (*this);
}

vec4	operator-(const vec4 &v1, const vec4 &v2)
{
	return (
		vec4(
			v1.x - v2.x,
			v1.y - v2.y,
			v1.z - v2.z,
			v1.w - v2.w
		)
	);
}

vec4	operator-(const float &scalar, const vec4 &v)
{
	return (
		vec4(
			scalar - v.x,
			scalar - v.y,
			scalar - v.z,
			scalar - v.w
		)
	);
}

vec4	operator-(const vec4 &v, const float &scalar)
{
	return (
		vec4(
			v.x - scalar,
			v.y - scalar,
			v.z - scalar,
			v.w - scalar
		)
	);
}

vec4	operator-(const vec1 &scalar, const vec4 &v)
{
	return (
		vec4(
			scalar.x - v.x,
			scalar.x - v.y,
			scalar.x - v.z,
			scalar.x - v.w
		)
	);
}

vec4	operator-(const vec4 &v, const vec1 &scalar)
{
	return (
		vec4(
			v.x - scalar.x,
			v.y - scalar.x,
			v.z - scalar.x,
			v.w - scalar.x
		)
	);
}

vec4	operator+(const vec4 &v1, const vec4 &v2)
{
	return (
		vec4(
			v1.x + v2.x,
			v1.y + v2.y,
			v1.z + v2.z,
			v1.w + v2.w
		)
	);
}

vec4	operator+(const float &scalar, const vec4 &v)
{
	return (
		vec4(
			scalar + v.x,
			scalar + v.y,
			scalar + v.z,
			scalar + v.w
		)
	);
}

vec4	operator+(const vec4 &v, const float &scalar)
{
	return (
		vec4(
			v.x + scalar,
			v.y + scalar,
			v.z + scalar,
			v.w + scalar
		)
	);
}

vec4	operator+(const vec1 &scalar, const vec4 &v)
{
	return (
		vec4(
			scalar.x + v.x,
			scalar.x + v.y,
			scalar.x + v.z,
			scalar.x + v.w
		)
	);
}

vec4	operator+(const vec4 &v, const vec1 &scalar)
{
	return (
		vec4(
			v.x + scalar.x,
			v.y + scalar.x,
			v.z + scalar.x,
			v.w + scalar.x
		)
	);
}

vec4	operator*(const vec4 &v1, const vec4 &v2)
{
	return (
		vec4(
			v1.x * v2.x,
			v1.y * v2.y,
			v1.z * v2.z,
			v1.w * v2.w
		)
	);
}

vec4	operator*(const float &scalar, const vec4 &v)
{
	return (
		vec4(
			scalar * v.x,
			scalar * v.y,
			scalar * v.z,
			scalar * v.w
		)
	);
}

vec4	operator*(const vec4 &v, const float &scalar)
{
	return (
		vec4(
			v.x * scalar,
			v.y * scalar,
			v.z * scalar,
			v.w * scalar
		)
	);
}

vec4	operator*(const vec1 &scalar, const vec4 &v)
{
	return (
		vec4(
			scalar.x * v.x,
			scalar.x * v.y,
			scalar.x * v.z,
			scalar.x * v.w
		)
	);
}

vec4	operator*(const vec4 &v, const vec1 &scalar)
{
	return (
		vec4(
			v.x * scalar.x,
			v.y * scalar.x,
			v.z * scalar.x,
			v.w * scalar.x
		)
	);
}

vec4	operator/(const vec4 &v1, const vec4 &v2)
{
	return (
		vec4(
			v1.x / v2.x,
			v1.y / v2.y,
			v1.z / v2.z,
			v1.w / v2.w
		)
	);
}

vec4	operator/(const float &scalar, const vec4 &v)
{
	return (
		vec4(
			scalar / v.x,
			scalar / v.y,
			scalar / v.z,
			scalar / v.w
		)
	);
}

vec4	operator/(const vec4 &v, const float &scalar)
{
	return (
		vec4(
			v.x / scalar,
			v.y / scalar,
			v.z / scalar,
			v.w / scalar
		)
	);
}

vec4	operator/(const vec1 &scalar, const vec4 &v)
{
	return (
		vec4(
			scalar.x / v.x,
			scalar.x / v.y,
			scalar.x / v.z,
			scalar.x / v.w
		)
	);
}

vec4	operator/(const vec4 &v, const vec1 &scalar)
{
	return (
		vec4(
			v.x / scalar.x,
			v.y / scalar.x,
			v.z / scalar.x,
			v.w / scalar.x
		)
	);
}


}
