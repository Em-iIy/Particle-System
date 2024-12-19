#include "../mlm/mat4.hpp"
#include <cassert>

namespace mlm {


mat4::mat4(
	const vec1 &x0, const vec1 &y0, const vec1 &z0, const vec1 &w0,
	const vec1 &x1, const vec1 &y1, const vec1 &z1, const vec1 &w1,
	const vec1 &x2, const vec1 &y2, const vec1 &z2, const vec1 &w2,
	const vec1 &x3, const vec1 &y3, const vec1 &z3, const vec1 &w3)
	: value{
		vec4(x0, y0, z0, w0),
		vec4(x1, y1, z1, w1),
		vec4(x2, y2, z2, w2),
		vec4(x3, y3, z3, w3)} {}


mat4::mat4(const vec4 &v0, const vec4 &v1, const vec4 &v2, const vec4 &v3): value{v0, v1, v2, v3} {}

mat4::mat4(const vec1 &s)
	: value{
		vec4(s, 0, 0, 0),
		vec4(0, s, 0, 0),
		vec4(0, 0, s, 0),
		vec4(0, 0, 0, s)} {}

mat4::mat4(const mat4 &m)
	: value{
		m[0],
		m[1],
		m[2],
		m[3]} {}

mat4::mat4() {}
mat4::~mat4() {}

vec4	&mat4::operator[](unsigned int i)
{
	assert(i < 4);
	return (this->value[i]);
}
const vec4	&mat4::operator[](unsigned int i) const
{
	assert(i < 4);
	return (this->value[i]);
}

mat4	&mat4::operator=(const mat4 &m)
{
	this->value[0] = m[0];
	this->value[1] = m[1];
	this->value[2] = m[2];
	this->value[3] = m[3];
	return (*this);
}

bool	mat4::operator==(const mat4 &m)
{
	return (this->value[0] == m[0] && this->value[1] == m[1] && this->value[2] == m[2] && this->value[3] == m[3]);
}

bool	mat4::operator!=(const mat4 &m)
{
	return (this->value[0] != m[0] && this->value[1] != m[1] && this->value[2] != m[2] && this->value[3] != m[3]);
}


mat4	&mat4::operator-=(const vec1 &s)
{
	this->value[0] -= s;
	this->value[1] -= s;
	this->value[2] -= s;
	this->value[3] -= s;
	return (*this);
}

mat4	&mat4::operator-=(const mat4 &m)
{
	this->value[0] -= m[0];
	this->value[1] -= m[1];
	this->value[2] -= m[2];
	this->value[3] -= m[3];
	return (*this);
}


mat4	&mat4::operator+=(const vec1 &s)
{
	this->value[0] += s;
	this->value[1] += s;
	this->value[2] += s;
	this->value[3] += s;
	return (*this);
}

mat4	&mat4::operator+=(const mat4 &m)
{
	this->value[0] += m[0];
	this->value[1] += m[1];
	this->value[2] += m[2];
	this->value[3] += m[3];
	return (*this);
}


mat4	&mat4::operator*=(const vec1 &s)
{
	this->value[0] *= s;
	this->value[1] *= s;
	this->value[2] *= s;
	this->value[3] *= s;
	return (*this);
}

mat4	&mat4::operator*=(const mat4 &m)
{
	return (*this = *this * m);
}


mat4	&mat4::operator/=(const vec1 &s)
{
	this->value[0] /= s;
	this->value[1] /= s;
	this->value[2] /= s;
	this->value[3] /= s;
	return (*this);
}



mat4	operator-(const mat4 &m1, const mat4 &m2)
{
	return (
		mat4(
			m1[0] - m2[0],
			m1[1] - m2[1],
			m1[2] - m2[2],
			m1[3] - m2[3]
		)
	);
}

mat4	operator-(const mat4 &m1, const vec1 &scalar)
{
	return (
		mat4(
			m1[0] - scalar,
			m1[1] - scalar,
			m1[2] - scalar,
			m1[3] - scalar
		)
	);
}

mat4	operator-(const vec1 &scalar, const mat4 &m1)
{
	return (
		mat4(
			scalar - m1[0],
			scalar - m1[1],
			scalar - m1[2],
			scalar - m1[3]
		)
	);
}

mat4	operator+(const mat4 &m1, const mat4 &m2)
{
	return (
		mat4(
			m1[0] + m2[0],
			m1[1] + m2[1],
			m1[2] + m2[2],
			m1[3] + m2[3]
		)
	);
}

mat4	operator+(const mat4 &m1, const vec1 &scalar)
{
	return (
		mat4(
			m1[0] + scalar,
			m1[1] + scalar,
			m1[2] + scalar,
			m1[3] + scalar
		)
	);
}

mat4	operator+(const vec1 &scalar, const mat4 &m1)
{
	return (
		mat4(
			scalar + m1[0],
			scalar + m1[1],
			scalar + m1[2],
			scalar + m1[3]
		)
	);
}

mat4	operator*(const vec1 &scalar, const mat4 &m1)
{
	return (
		mat4(
			scalar * m1[0],
			scalar * m1[1],
			scalar * m1[2],
			scalar * m1[3]
		)
	);
}


mat4	operator*(const mat4 &m1, const vec1 &scalar)
{
	return (
		mat4(
			m1[0] * scalar,
			m1[1] * scalar,
			m1[2] * scalar,
			m1[3] * scalar
		)
	);
}

mat4	operator*(const mat4 &m1, const mat4 &m2)
{
	return (
		mat4(
			m1[0] * m2[0][0] + m1[1] * m2[0][1] + m1[2] * m2[0][2] + m1[3] * m2[0][3],
			m1[0] * m2[1][0] + m1[1] * m2[1][1] + m1[2] * m2[1][2] + m1[3] * m2[1][3],
			m1[0] * m2[2][0] + m1[1] * m2[2][1] + m1[2] * m2[2][2] + m1[3] * m2[2][3],
			m1[0] * m2[3][0] + m1[1] * m2[3][1] + m1[2] * m2[3][2] + m1[3] * m2[3][3]
		)
	);
}

vec4	operator*(const mat4 &m, const vec4 &v)
{
	vec4 ret;
	ret = v.x * m[0] + v.y * m[1] + v.z * m[2] + v.w * m[3];
	return (ret);
}

mat4	operator/(const vec1 &scalar, const mat4 &m1)
{
	return (
		mat4(
			scalar / m1[0],
			scalar / m1[1],
			scalar / m1[2],
			scalar / m1[3]
		)
	);
}


mat4	operator/(const mat4 &m1, const vec1 &scalar)
{
	return (
		mat4(
			m1[0] / scalar,
			m1[1] / scalar,
			m1[2] / scalar,
			m1[3] / scalar
		)
	);
}

// mat4	operator/(const mat4 &m1, const mat4 &m2)
// {
// 	return (
// 		mat4(
// 		)
// 	);
// }

}
