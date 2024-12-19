#include "../mlm/vec1.hpp"
#include <cassert>

namespace mlm {

vec1::vec1(const float &_n): x(_n) {}
vec1::vec1(const vec1 &src): x(src.x) {}

vec1::vec1() {}
vec1::~vec1() {}

float	&vec1::operator[](unsigned int i)
{
	assert(1 < 3);
	switch (i)
	{
	default:
	case 0:
		return (this->x);
	}
}

const float	&vec1::operator[](unsigned int i) const
{
	assert(1 < 3);
	switch (i)
	{
	default:
	case 0:
		return (this->x);
	}
}


vec1	&vec1::operator=(const vec1 &v)
{
	this->x = v.x;
	return (*this);
}

vec1	&vec1::operator=(const float &scalar)
{
	this->x = scalar;
	return (*this);
}

bool	vec1::operator==(const vec1 &v)
{
	return (this->x == v.x);
}

bool	vec1::operator==(const float &scalar)
{
	return (this->x == scalar);
}

bool	vec1::operator!=(const vec1 &v)
{
	return (this->x != v.x);
}

bool	vec1::operator!=(const float &scalar)
{
	return (this->x != scalar);
}

vec1	&vec1::operator-=(const vec1 &v)
{
	this->x -= v.x;
	return (*this);
}

vec1	&vec1::operator-=(const float &scalar)
{
	this->x -= scalar;
	return (*this);
}

vec1	&vec1::operator+=(const vec1 &v)
{
	this->x += v.x;
	return (*this);
}

vec1	&vec1::operator+=(const float &scalar)
{
	this->x += scalar;
	return (*this);
}

vec1	&vec1::operator*=(const vec1 &v)
{
	this->x *= v.x;
	return (*this);
}

vec1	&vec1::operator*=(const float &scalar)
{
	this->x *= scalar;
	return (*this);
}

vec1	&vec1::operator/=(const vec1 &v)
{
	this->x /= v.x;
	return (*this);
}

vec1	&vec1::operator/=(const float &scalar)
{
	this->x /= scalar;
	return (*this);
}

vec1	operator-(const vec1 &v, const float scalar)
{
	return (
		vec1(
			v.x - scalar
		)
	);
}

vec1	operator-(const float &scalar, const vec1 &v)
{
	return (
		vec1(
			scalar - v.x
		)
	);
}

vec1	operator-(const vec1 &v1, const vec1 &v2)
{
	return (
		vec1(
			v1.x - v2.x
		)
	);

}

vec1	operator+(const vec1 &v, const float scalar)
{
	return (
		vec1(
			v.x + scalar
		)
	);
}

vec1	operator+(const float &scalar, const vec1 &v)
{
	return (
		vec1(
			scalar + v.x
		)
	);
}

vec1	operator+(const vec1 &v1, const vec1 &v2)
{
	return (
		vec1(
			v1.x + v2.x
		)
	);

}

vec1	operator*(const vec1 &v, const float scalar)
{
	return (
		vec1(
			v.x * scalar
		)
	);
}

vec1	operator*(const float &scalar, const vec1 &v)
{
	return (
		vec1(
			scalar * v.x
		)
	);
}


vec1	operator*(const vec1 &v1, const vec1 &v2)
{
	return (
		vec1(
			v1.x * v2.x
		)
	);

}

vec1	operator/(const vec1 &v, const float scalar)
{
	return (
		vec1(
			v.x / scalar
		)
	);
}

vec1	operator/(const float &scalar, const vec1 &v)
{
	return (
		vec1(
			scalar / v.x
		)
	);
}

vec1	operator/(const vec1 &v1, const vec1 &v2)
{
	return (
		vec1(
			v1.x / v2.x
		)
	);

}

}
