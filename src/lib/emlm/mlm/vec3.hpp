#pragma once

#include "vec1.hpp"
#include "vec2.hpp"

namespace mlm {

struct vec3 {
	float x;
	float y;
	float z;

	vec3(const float &_x, const float &_y, const float &_z);
	vec3(const float &_x, const float &_y, const vec1 &_z);
	vec3(const float &_x, const vec1 &_y, const float &_z);
	vec3(const float &_x, const vec1 &_y, const vec1 &_z);
	vec3(const vec1 &_x, const float &_y, const float &_z);
	vec3(const vec1 &_x, const float &_y, const vec1 &_z);
	vec3(const vec1 &_x, const vec1 &_y, const float &_z);
	vec3(const vec1 &_x, const vec1 &_y, const vec1 &_z);

	vec3(const vec2 &v, const float &_z);
	vec3(const vec2 &v, const vec1 &_z);
	vec3(const float &_x, const vec2 &v);
	vec3(const vec1 &_x, const vec2 &v);

	vec3(const float &scalar);
	vec3(const vec1 &scalar);
	vec3(const vec3 &v);

	vec3();
	~vec3();

	float	&operator[](unsigned int i);
	const float	&operator[](unsigned int i) const;

	vec3	&operator=(const vec3 &v);

	bool	operator==(const vec3 &v);
	bool	operator!=(const vec3 &v);

	vec3	&operator-=(const vec3 &v);
	vec3	&operator-=(const vec1 &scalar);
	vec3	&operator-=(const float &scalar);

	vec3	&operator+=(const vec3 &v);
	vec3	&operator+=(const vec1 &scalar);
	vec3	&operator+=(const float &scalar);

	vec3	&operator*=(const vec3 &v);
	vec3	&operator*=(const vec1 &scalar);
	vec3	&operator*=(const float &scalar);

	vec3	&operator/=(const vec3 &v);
	vec3	&operator/=(const vec1 &scalar);
	vec3	&operator/=(const float &scalar);
};

vec3	operator-(const vec3 &v1, const vec3 &v2);
vec3	operator-(const float &scalar, const vec3 &v);
vec3	operator-(const vec3 &v, const float &scalar);
vec3	operator-(const vec1 &scalar, const vec3 &v);
vec3	operator-(const vec3 &v, const vec1 &scalar);

vec3	operator+(const vec3 &v1, const vec3 &v2);
vec3	operator+(const float &scalar, const vec3 &v);
vec3	operator+(const vec3 &v, const float &scalar);
vec3	operator+(const vec1 &scalar, const vec3 &v);
vec3	operator+(const vec3 &v, const vec1 &scalar);

vec3	operator*(const vec3 &v1, const vec3 &v2);
vec3	operator*(const float &scalar, const vec3 &v);
vec3	operator*(const vec3 &v, const float &scalar);
vec3	operator*(const vec1 &scalar, const vec3 &v);
vec3	operator*(const vec3 &v, const vec1 &scalar);

vec3	operator/(const vec3 &v1, const vec3 &v2);
vec3	operator/(const float &scalar, const vec3 &v);
vec3	operator/(const vec3 &v, const float &scalar);
vec3	operator/(const vec1 &scalar, const vec3 &v);
vec3	operator/(const vec3 &v, const vec1 &scalar);


}
