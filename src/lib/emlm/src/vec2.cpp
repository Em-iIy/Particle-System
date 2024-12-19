#include "../mlm/vec2.hpp"
#include <cassert>

namespace mlm {

vec2::vec2(const float &_x, const float &_y): x(_x), y(_y) {}
vec2::vec2(const float &_x, const vec1 &_y): x(_x), y(_y.x) {}
vec2::vec2(const vec1 &_x, const float &_y): x(_x.x), y(_y) {}
vec2::vec2(const vec1 &_x, const vec1 &_y): x(_x.x), y(_y.x) {}

vec2::vec2(const float &scalar): x(scalar), y(scalar) {}
vec2::vec2(const vec1 &scalar): x(scalar.x), y(scalar.x) {}
vec2::vec2(const vec2 &v): x(v.x), y(v.y) {}

vec2::vec2() {}
vec2::~vec2() {}

float	&vec2::operator[](unsigned int i)
{
	assert(i < 2);
	switch(i)
	{
	default:
	case 0:
		return (this->x);
	case 1:
		return (this->y);
	}
}

const float	&vec2::operator[](unsigned int i) const
{
	assert(i < 2);
	switch(i)
	{
	default:
	case 0:
		return (this->x);
	case 1:
		return (this->y);
	}
}

vec2	&vec2::operator=(const vec2 &v)
{
	this->x = v.x;
	this->y = v.y;
	return (*this);
}

bool	vec2::operator==(const vec2 &v)
{
	return (this->x == v.x && this->y == v.y);
}

bool	vec2::operator!=(const vec2 &v)
{
	return (this->x != v.x && this->y != v.y);
}

vec2	&vec2::operator-=(const vec2 &v)
{
	this->x -= v.x;
	this->y -= v.y;
	return (*this);
}

vec2	&vec2::operator-=(const float &scalar)
{
	this->x -= scalar;
	this->y -= scalar;
	return (*this);
}

vec2	&vec2::operator-=(const vec1 &scalar)
{
	this->x -= scalar.x;
	this->y -= scalar.x;
	return (*this);
}

vec2	&vec2::operator+=(const vec2 &v)
{
	this->x += v.x;
	this->y += v.y;
	return (*this);
}

vec2	&vec2::operator+=(const float &scalar)
{
	this->x += scalar;
	this->y += scalar;
	return (*this);
}

vec2	&vec2::operator+=(const vec1 &scalar)
{
	this->x += scalar.x;
	this->y += scalar.x;
	return (*this);
}

vec2	&vec2::operator*=(const vec2 &v)
{
	this->x *= v.x;
	this->y *= v.y;
	return (*this);
}

vec2	&vec2::operator*=(const float &scalar)
{
	this->x *= scalar;
	this->y *= scalar;
	return (*this);
}

vec2	&vec2::operator*=(const vec1 &scalar)
{
	this->x *= scalar.x;
	this->y *= scalar.x;
	return (*this);
}

vec2	&vec2::operator/=(const vec2 &v)
{
	this->x /= v.x;
	this->y /= v.y;
	return (*this);
}

vec2	&vec2::operator/=(const float &scalar)
{
	this->x /= scalar;
	this->y /= scalar;
	return (*this);
}

vec2	&vec2::operator/=(const vec1 &scalar)
{
	this->x /= scalar.x;
	this->y /= scalar.x;
	return (*this);
}

vec2	operator-(const vec2 &v1, const vec2 &v2)
{
	return (
		vec2(
			v1.x - v2.x,
			v1.y - v2.y
		)
	);
}

vec2	operator-(const float &scalar, const vec2 &v)
{
	return (
		vec2(
			scalar - v.x,
			scalar - v.y
		)
	);
}

vec2	operator-(const vec1 &scalar, const vec2 &v)
{
	return (
		vec2(
			scalar.x - v.x,
			scalar.x - v.y
		)
	);
}

vec2	operator-(const vec2 &v, const float &scalar)
{
	return (
		vec2(
			v.x - scalar,
			v.y - scalar
		)
	);
}

vec2	operator-(const vec2 &v, const vec1 &scalar)
{
	return (
		vec2(
			v.x - scalar.x,
			v.y - scalar.x
		)
	);
}


vec2	operator+(const vec2 &v1, const vec2 &v2)
{
	return (
		vec2(
			v1.x + v2.x,
			v1.y + v2.y
		)
	);
}

vec2	operator+(const float &scalar, const vec2 &v)
{
	return (
		vec2(
			scalar + v.x,
			scalar + v.y
		)
	);
}

vec2	operator+(const vec1 &scalar, const vec2 &v)
{
	return (
		vec2(
			scalar.x + v.x,
			scalar.x + v.y
		)
	);
}

vec2	operator+(const vec2 &v, const float &scalar)
{
	return (
		vec2(
			v.x + scalar,
			v.y + scalar
		)
	);
}

vec2	operator+(const vec2 &v, const vec1 &scalar)
{
	return (
		vec2(
			v.x + scalar.x,
			v.y + scalar.x
		)
	);
}


vec2	operator*(const vec2 &v1, const vec2 &v2)
{
	return (
		vec2(
			v1.x * v2.x,
			v1.y * v2.y
		)
	);
}

vec2	operator*(const float &scalar, const vec2 &v)
{
	return (
		vec2(
			scalar * v.x,
			scalar * v.y
		)
	);
}

vec2	operator*(const vec1 &scalar, const vec2 &v)
{
	return (
		vec2(
			scalar.x * v.x,
			scalar.x * v.y
		)
	);
}

vec2	operator*(const vec2 &v, const float &scalar)
{
	return (
		vec2(
			v.x * scalar,
			v.y * scalar
		)
	);
}

vec2	operator*(const vec2 &v, const vec1 &scalar)
{
	return (
		vec2(
			v.x * scalar.x,
			v.y * scalar.x
		)
	);
}


vec2	operator/(const vec2 &v1, const vec2 &v2)
{
	return (
		vec2(
			v1.x / v2.x,
			v1.y / v2.y
		)
	);
}

vec2	operator/(const float &scalar, const vec2 &v)
{
	return (
		vec2(
			scalar / v.x,
			scalar / v.y
		)
	);
}

vec2	operator/(const vec1 &scalar, const vec2 &v)
{
	return (
		vec2(
			scalar.x / v.x,
			scalar.x / v.y
		)
	);
}

vec2	operator/(const vec2 &v, const float &scalar)
{
	return (
		vec2(
			v.x / scalar,
			v.y / scalar
		)
	);
}

vec2	operator/(const vec2 &v, const vec1 &scalar)
{
	return (
		vec2(
			v.x / scalar.x,
			v.y / scalar.x
		)
	);
}


}
