#version 430 core

out vec4 FragColor;

in vec3 pos;
in vec3 dir;

layout (location = 1) uniform vec3 gravity;
layout (location = 2) uniform vec3 color1;
layout (location = 3) uniform vec3 color2;
layout (location = 4) uniform float dimensions;


// The MIT License
// Copyright © 2020 Inigo Quilez
// Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions: The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software. THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
// https://www.shadertoy.com/view/ttcyRS
vec3 oklab_mix( vec3 colA, vec3 colB, float h )
{
	// https://bottosson.github.io/posts/oklab
	const mat3 kCONEtoLMS = mat3(
		 0.4121656120,  0.2118591070,  0.0883097947,
		 0.5362752080,  0.6807189584,  0.2818474174,
		 0.0514575653,  0.1074065790,  0.6302613616);
	const mat3 kLMStoCONE = mat3(
		 4.0767245293, -1.2681437731, -0.0041119885,
		-3.3072168827,  2.6093323231, -0.7034763098,
		 0.2307590544, -0.3411344290,  1.7068625689);
					
	// rgb to cone (arg of pow can't be negative)
	vec3 lmsA = pow( kCONEtoLMS*colA, vec3(1.0/3.0) );
	vec3 lmsB = pow( kCONEtoLMS*colB, vec3(1.0/3.0) );
	// lerp
	vec3 lms = mix( lmsA, lmsB, h );
	// gain in the middle (no oaklab anymore, but looks better?)
	// lms *= 1.0+0.2*h*(1.0-h);
	// cone to rgb
	return kLMStoCONE*(lms*lms*lms);
}

void main()
{
	vec3	gravity_dir = gravity - pos;
	float	dist = clamp(1.0f - length(gravity_dir) / dimensions, 0.0, 1.0);
	FragColor = vec4(oklab_mix(color1, color2, dist * dist * dist), 1.0);
}