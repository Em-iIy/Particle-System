#pragma once

#include "vec1.hpp"
#include "vec2.hpp"
#include "vec3.hpp"
// #include "mat4.hpp"

namespace mlm {

struct vec4 {
	float x;
	float y;
	float z;
	float w;

	vec4(const float &_x, const float &_y, const float &_z, const float &_w);
	vec4(const float &_x, const float &_y, const float &_z, const vec1 &_w);
	vec4(const float &_x, const float &_y, const vec1 &_z, const float &_w);
	vec4(const float &_x, const float &_y, const vec1 &_z, const vec1 &_w);
	vec4(const float &_x, const vec1 &_y, const float &_z, const float &_w);
	vec4(const float &_x, const vec1 &_y, const float &_z, const vec1 &_w);
	vec4(const float &_x, const vec1 &_y, const vec1 &_z, const float &_w);
	vec4(const float &_x, const vec1 &_y, const vec1 &_z, const vec1 &_w);
	vec4(const vec1 &_x, const float &_y, const float &_z, const float &_w);
	vec4(const vec1 &_x, const float &_y, const float &_z, const vec1 &_w);
	vec4(const vec1 &_x, const float &_y, const vec1 &_z, const float &_w);
	vec4(const vec1 &_x, const float &_y, const vec1 &_z, const vec1 &_w);
	vec4(const vec1 &_x, const vec1 &_y, const float &_z, const float &_w);
	vec4(const vec1 &_x, const vec1 &_y, const float &_z, const vec1 &_w);
	vec4(const vec1 &_x, const vec1 &_y, const vec1 &_z, const float &_w);
	vec4(const vec1 &_x, const vec1 &_y, const vec1 &_z, const vec1 &_w);


	vec4(const vec2 &_xy, const float &_z, const float &_w);
	vec4(const vec2 &_xy, const vec1 &_z, const float &_w);
	vec4(const vec2 &_xy, const float &_z, const vec1 &_w);
	vec4(const vec2 &_xy, const vec1 &_z, const vec1 &_w);
	vec4(const float &_x, const vec2 &_yz, const float &_w);
	vec4(const vec1 &_x, const vec2 &_yz, const float &_w);
	vec4(const float &_x, const vec2 &_yz, const vec1 &_w);
	vec4(const vec1 &_x, const vec2 &_yz, const vec1 &_w);
	vec4(const float &_x, const float &_y, const vec2 &_zw);
	vec4(const vec1 &_x, const float &_y, const vec2 &_zw);
	vec4(const float &_x, const vec1 &_y, const vec2 &_zw);
	vec4(const vec1 &_x, const vec1 &_y, const vec2 &_zw);

	vec4(const vec2 &_xy, const vec2 &_zw);
	vec4(const vec3 &_xyz, const float &_w);
	vec4(const vec3 &_xyz, const vec1 &_w);
	vec4(const float &_x, const vec3 &_yzw);
	vec4(const vec1 &_x, const vec3 &_yzw);

	vec4(const float &scalar);
	vec4(const vec1 &scalar);
	vec4(const vec4 &v);


	vec4();
	~vec4();

	float	&operator[](unsigned int i);
	const float	&operator[](unsigned int i) const;

	vec4	&operator=(const vec4 &v);

	bool	operator==(const vec4 &v);
	bool	operator!=(const vec4 &v);

	vec4	&operator-=(const vec4 &v);
	vec4	&operator-=(const vec1 &scalar);
	vec4	&operator-=(const float &scalar);

	vec4	&operator+=(const vec4 &v);
	vec4	&operator+=(const vec1 &scalar);
	vec4	&operator+=(const float &scalar);

	vec4	&operator*=(const vec4 &v);
	vec4	&operator*=(const vec1 &scalar);
	vec4	&operator*=(const float &scalar);

	vec4	&operator/=(const vec4 &v);
	vec4	&operator/=(const vec1 &scalar);
	vec4	&operator/=(const float &scalar);
};

vec4	operator-(const vec4 &v1, const vec4 &v2);
vec4	operator-(const float &scalar, const vec4 &v);
vec4	operator-(const vec4 &v, const float &scalar);
vec4	operator-(const vec1 &scalar, const vec4 &v);
vec4	operator-(const vec4 &v, const vec1 &scalar);

vec4	operator+(const vec4 &v1, const vec4 &v2);
vec4	operator+(const float &scalar, const vec4 &v);
vec4	operator+(const vec4 &v, const float &scalar);
vec4	operator+(const vec1 &scalar, const vec4 &v);
vec4	operator+(const vec4 &v, const vec1 &scalar);

vec4	operator*(const vec4 &v1, const vec4 &v2);
vec4	operator*(const float &scalar, const vec4 &v);
vec4	operator*(const vec4 &v, const float &scalar);
vec4	operator*(const vec1 &scalar, const vec4 &v);
vec4	operator*(const vec4 &v, const vec1 &scalar);

vec4	operator/(const vec4 &v1, const vec4 &v2);
vec4	operator/(const float &scalar, const vec4 &v);
vec4	operator/(const vec4 &v, const float &scalar);
vec4	operator/(const vec1 &scalar, const vec4 &v);
vec4	operator/(const vec4 &v, const vec1 &scalar);


}
