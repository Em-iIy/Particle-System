#include "../mlm/vec3.hpp"
#include <cassert>

namespace mlm {

vec3::vec3(const float &_x, const float &_y, const float &_z): x(_x), y(_y), z(_z) {}
vec3::vec3(const float &_x, const float &_y, const vec1 &_z): x(_x), y(_y), z(_z.x) {}
vec3::vec3(const float &_x, const vec1 &_y, const float &_z): x(_x), y(_y.x), z(_z) {}
vec3::vec3(const float &_x, const vec1 &_y, const vec1 &_z): x(_x), y(_y.x), z(_z.x) {}
vec3::vec3(const vec1 &_x, const float &_y, const float &_z): x(_x.x), y(_y), z(_z) {}
vec3::vec3(const vec1 &_x, const float &_y, const vec1 &_z): x(_x.x), y(_y), z(_z.x) {}
vec3::vec3(const vec1 &_x, const vec1 &_y, const float &_z): x(_x.x), y(_y.x), z(_z) {}
vec3::vec3(const vec1 &_x, const vec1 &_y, const vec1 &_z): x(_x.x), y(_y.x), z(_z.x) {}

vec3::vec3(const vec2 &src, const float &_z): x(src.x), y(src.y), z(_z)  {}
vec3::vec3(const vec2 &src, const vec1 &_z): x(src.x), y(src.y), z(_z.x)  {}
vec3::vec3(const float &_x, const vec2 &src): x(_x), y(src.x), z(src.y) {}
vec3::vec3(const vec1 &_x, const vec2 &src): x(_x.x), y(src.x), z(src.y) {}

vec3::vec3(const float &scalar): x(scalar), y(scalar), z(scalar) {}
vec3::vec3(const vec1 &scalar): x(scalar.x), y(scalar.x), z(scalar.x) {}
vec3::vec3(const vec3 &v): x(v.x), y(v.y), z(v.z) {}

vec3::vec3() {}
vec3::~vec3() {}

vec3	&vec3::operator=(const vec3 &v)
{
	this->x = v.x;
	this->y = v.y;
	this->z = v.z;
	return (*this);
}

float	&vec3::operator[](unsigned int i)
{
	assert(i < 3);
	switch(i)
	{
	default:
	case 0:
		return (this->x);
	case 1:
		return (this->y);
	case 2:
		return (this->z);
	}
}

const float	&vec3::operator[](unsigned int i) const
{
	assert(i < 3);
	switch(i)
	{
	default:
	case 0:
		return (this->x);
	case 1:
		return (this->y);
	case 2:
		return (this->z);
	}
}

bool	vec3::operator==(const vec3 &v)
{
	return (this->x == v.x && this->y == v.y && this->z == v.z);
}

bool	vec3::operator!=(const vec3 &v)
{
	return (this->x != v.x && this->y != v.y && this->z != v.z);
}

vec3	&vec3::operator-=(const vec3 &v)
{
	this->x -= v.x;
	this->y -= v.y;
	this->z -= v.z;
	return (*this);
}

vec3	&vec3::operator-=(const vec1 &scalar)
{
	this->x -= scalar.x;
	this->y -= scalar.x;
	this->z -= scalar.x;
	return (*this);
}

vec3	&vec3::operator-=(const float &scalar)
{
	this->x -= scalar;
	this->y -= scalar;
	this->z -= scalar;
	return (*this);
}

vec3	&vec3::operator+=(const vec3 &v)
{
	this->x += v.x;
	this->y += v.y;
	this->z += v.z;
	return (*this);
}

vec3	&vec3::operator+=(const vec1 &scalar)
{
	this->x += scalar.x;
	this->y += scalar.x;
	this->z += scalar.x;
	return (*this);
}

vec3	&vec3::operator+=(const float &scalar)
{
	this->x += scalar;
	this->y += scalar;
	this->z += scalar;
	return (*this);
}

vec3	&vec3::operator*=(const vec3 &v)
{
	this->x *= v.x;
	this->y *= v.y;
	this->z *= v.z;
	return (*this);
}

vec3	&vec3::operator*=(const vec1 &scalar)
{
	this->x *= scalar.x;
	this->y *= scalar.x;
	this->z *= scalar.x;
	return (*this);
}

vec3	&vec3::operator*=(const float &scalar)
{
	this->x *= scalar;
	this->y *= scalar;
	this->z *= scalar;
	return (*this);
}

vec3	&vec3::operator/=(const vec3 &v)
{
	this->x /= v.x;
	this->y /= v.y;
	this->z /= v.z;
	return (*this);
}

vec3	&vec3::operator/=(const vec1 &scalar)
{
	this->x /= scalar.x;
	this->y /= scalar.x;
	this->z /= scalar.x;
	return (*this);
}

vec3	&vec3::operator/=(const float &scalar)
{
	this->x /= scalar;
	this->y /= scalar;
	this->z /= scalar;
	return (*this);
}

vec3	operator-(const vec3 &v1, const vec3 &v2)
{
	return (
		vec3(
			v1.x - v2.x,
			v1.y - v2.y,
			v1.z - v2.z
		)
	);
}

vec3	operator-(const float &scalar, const vec3 &v)
{
	return (
		vec3(
			scalar - v.x,
			scalar - v.y,
			scalar - v.z
		)
	);
}

vec3	operator-(const vec3 &v, const float &scalar)
{
	return (
		vec3(
			v.x - scalar,
			v.y - scalar,
			v.z - scalar
		)
	);
}

vec3	operator-(const vec1 &scalar, const vec3 &v)
{
	return (
		vec3(
			scalar.x - v.x,
			scalar.x - v.y,
			scalar.x - v.z
		)
	);
}

vec3	operator-(const vec3 &v, const vec1 &scalar)
{
	return (
		vec3(
			v.x - scalar.x,
			v.y - scalar.x,
			v.z - scalar.x
		)
	);
}

vec3	operator+(const vec3 &v1, const vec3 &v2)
{
	return (
		vec3(
			v1.x + v2.x,
			v1.y + v2.y,
			v1.z + v2.z
		)
	);
}

vec3	operator+(const float &scalar, const vec3 &v)
{
	return (
		vec3(
			scalar + v.x,
			scalar + v.y,
			scalar + v.z
		)
	);
}

vec3	operator+(const vec3 &v, const float &scalar)
{
	return (
		vec3(
			v.x + scalar,
			v.y + scalar,
			v.z + scalar
		)
	);
}

vec3	operator+(const vec1 &scalar, const vec3 &v)
{
	return (
		vec3(
			scalar.x + v.x,
			scalar.x + v.y,
			scalar.x + v.z
		)
	);
}

vec3	operator+(const vec3 &v, const vec1 &scalar)
{
	return (
		vec3(
			v.x + scalar.x,
			v.y + scalar.x,
			v.z + scalar.x
		)
	);
}

vec3	operator*(const vec3 &v1, const vec3 &v2)
{
	return (
		vec3(
			v1.x * v2.x,
			v1.y * v2.y,
			v1.z * v2.z
		)
	);
}

vec3	operator*(const float &scalar, const vec3 &v)
{
	return (
		vec3(
			scalar * v.x,
			scalar * v.y,
			scalar * v.z
		)
	);
}

vec3	operator*(const vec3 &v, const float &scalar)
{
	return (
		vec3(
			v.x * scalar,
			v.y * scalar,
			v.z * scalar
		)
	);
}

vec3	operator*(const vec1 &scalar, const vec3 &v)
{
	return (
		vec3(
			scalar.x * v.x,
			scalar.x * v.y,
			scalar.x * v.z
		)
	);
}

vec3	operator*(const vec3 &v, const vec1 &scalar)
{
	return (
		vec3(
			v.x * scalar.x,
			v.y * scalar.x,
			v.z * scalar.x
		)
	);
}

vec3	operator/(const vec3 &v1, const vec3 &v2)
{
	return (
		vec3(
			v1.x / v2.x,
			v1.y / v2.y,
			v1.z / v2.z
		)
	);
}

vec3	operator/(const float &scalar, const vec3 &v)
{
	return (
		vec3(
			scalar / v.x,
			scalar / v.y,
			scalar / v.z
		)
	);
}

vec3	operator/(const vec3 &v, const float &scalar)
{
	return (
		vec3(
			v.x / scalar,
			v.y / scalar,
			v.z / scalar
		)
	);
}

vec3	operator/(const vec1 &scalar, const vec3 &v)
{
	return (
		vec3(
			scalar.x / v.x,
			scalar.x / v.y,
			scalar.x / v.z
		)
	);
}

vec3	operator/(const vec3 &v, const vec1 &scalar)
{
	return (
		vec3(
			v.x / scalar.x,
			v.y / scalar.x,
			v.z / scalar.x
		)
	);
}

}
