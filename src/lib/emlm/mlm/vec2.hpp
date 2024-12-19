#pragma once

#include "vec1.hpp"

namespace mlm {

struct vec2 {
	float x;
	float y;

	vec2(const float &_x, const float &_y);
	vec2(const float &_x, const vec1 &_y);
	vec2(const vec1 &_x, const float &_y);
	vec2(const vec1 &_x, const vec1 &_y);

	vec2(const float &scalar);
	vec2(const vec1 &scalar);
	vec2(const vec2 &v);

	vec2();
	~vec2();

	float	&operator[](unsigned int i);
	const float	&operator[](unsigned int i) const;

	vec2	&operator=(const vec2 &v);

	bool	operator==(const vec2 &v);
	bool	operator!=(const vec2 &v);

	vec2	&operator-=(const vec2 &v);
	vec2	&operator-=(const vec1 &scalar);
	vec2	&operator-=(const float &scalar);

	vec2	&operator+=(const vec2 &v);
	vec2	&operator+=(const vec1 &scalar);
	vec2	&operator+=(const float &scalar);

	vec2	&operator*=(const vec2 &v);
	vec2	&operator*=(const vec1 &scalar);
	vec2	&operator*=(const float &scalar);

	vec2	&operator/=(const vec2 &v);
	vec2	&operator/=(const vec1 &scalar);
	vec2	&operator/=(const float &scalar);
};

vec2	operator-(const vec2 &v1, const vec2 &v2);
vec2	operator-(const float &scalar, const vec2 &v);
vec2	operator-(const vec1 &scalar, const vec2 &v);
vec2	operator-(const vec2 &v, const float &scalar);
vec2	operator-(const vec2 &v, const vec1 &scalar);

vec2	operator+(const vec2 &v1, const vec2 &v2);
vec2	operator+(const float &scalar, const vec2 &v);
vec2	operator+(const vec1 &scalar, const vec2 &v);
vec2	operator+(const vec2 &v, const float &scalar);
vec2	operator+(const vec2 &v, const vec1 &scalar);

vec2	operator*(const vec2 &v1, const vec2 &v2);
vec2	operator*(const float &scalar, const vec2 &v);
vec2	operator*(const vec1 &scalar, const vec2 &v);
vec2	operator*(const vec2 &v, const float &scalar);
vec2	operator*(const vec2 &v, const vec1 &scalar);

vec2	operator/(const vec2 &v1, const vec2 &v2);
vec2	operator/(const float &scalar, const vec2 &v);
vec2	operator/(const vec1 &scalar, const vec2 &v);
vec2	operator/(const vec2 &v, const float &scalar);
vec2	operator/(const vec2 &v, const vec1 &scalar);

}
