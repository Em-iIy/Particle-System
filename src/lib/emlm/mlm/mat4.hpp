#pragma once

#include "vec4.hpp"

namespace mlm {


struct mat4 {
	vec4 value[4];

	mat4(
		const vec1 &x0, const vec1 &y0, const vec1 &z0, const vec1 &w0,
		const vec1 &x1, const vec1 &y1, const vec1 &z1, const vec1 &w1,
		const vec1 &x2, const vec1 &y2, const vec1 &z2, const vec1 &w2,
		const vec1 &x3, const vec1 &y3, const vec1 &z3, const vec1 &w3);


	mat4(const vec4 &v0, const vec4 &v1, const vec4 &v2, const vec4 &v3);

	mat4(const vec1 &s);
	mat4(const mat4 &m);

	mat4();
	~mat4();

	vec4	&operator[](unsigned int i);
	const vec4	&operator[](unsigned int i) const;

	mat4	&operator=(const mat4 &m);

	bool	operator==(const mat4 &m);
	bool	operator!=(const mat4 &m);

	mat4	&operator-=(const vec1 &s);
	mat4	&operator-=(const mat4 &m);

	mat4	&operator+=(const vec1 &s);
	mat4	&operator+=(const mat4 &m);

	mat4	&operator*=(const vec1 &s);
	mat4	&operator*=(const mat4 &m);
	
	mat4	&operator/=(const vec1 &s);
	// mat4	&operator/=(const mat4 &m);
};

mat4	operator-(const mat4 &m1, const mat4 &m2);
mat4	operator-(const mat4 &m1, const vec1 &scalar);
mat4	operator-(const vec1 &scalar, const mat4 &m1);

mat4	operator+(const mat4 &m1, const mat4 &m2);
mat4	operator+(const mat4 &m1, const vec1 &scalar);
mat4	operator+(const vec1 &scalar, const mat4 &m1);

mat4	operator*(const mat4 &m1, const mat4 &m2);
mat4	operator*(const mat4 &m1, const vec1 &scalar);
mat4	operator*(const vec1 &scalar, const mat4 &m1);

vec4	operator*(const mat4 &m, const vec4 &v);

mat4	operator/(const mat4 &m1, const mat4 &m2);
mat4	operator/(const mat4 &m1, const vec1 &scalar);
// mat4	operator/(const vec1 &scalar, const mat4 &m1);


}
