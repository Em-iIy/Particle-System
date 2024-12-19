#include "colour.h"
#include "test.hpp"
#include <iostream>

#include "../mlm/print/vectorPrint.hpp"
#include "../emlm.hpp"
// #include "../glm/glm/glm.hpp"
// g++ tests/*.cpp libmlm.a && ./a.out

#include <cstring>

void	m4print(const mlm::mat4 &m)
{
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
			std::cout << m[j][i] << " ";
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

// void	m4print(const glm::mat4 &m)
// {
// 	for (int i = 0; i < 4; ++i)
// 	{
// 		for (int j = 0; j < 4; ++j)
// 			std::cout << m[j][i] << " ";
// 		std::cout << std::endl;
// 	}
// 	std::cout << std::endl;
// }

#include <ctime>

void mat4test(void)
{
	srand(std::time(NULL));
	mlm::mat4 testm1;
	mlm::mat4 testm2;
	// glm::mat4 testg1;
	// glm::mat4 testg2;

	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			testm1[j][i] = rand();
		}
	}
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			testm2[j][i] = rand();
		}
	}

	// for (int i = 0; i < 4; ++i)
	// {
	// 	for (int j = 0; j < 4; ++j)
	// 	{
	// 		testg1[j][i] = testm1[j][i];
	// 		testg2[j][i] = testm2[j][i];
	// 	}
	// }
	m4print(testm1);
	// m4print(testg1);
	m4print(testm2);
	// m4print(testg2);
	mlm::mat4 resultm = testm1 * testm2;
	// glm::mat4 resultg = testg1 * testg2;
	m4print(resultm);
	// m4print(resultg);

	// std::cout << memcmp(&resultg, &resultm, sizeof(resultm)) << std::endl;
}

// float dot(const mlm::vec3 &v1,const mlm::vec3 &v2)
// {
// 	return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
// }

// float vabs(const mlm::vec3 &v)
// {
// 	return (fsqrt(dot(v, v)));
// }

// mlm::vec3 normalize(const mlm::vec3 &v)
// {
// 	return (v / vabs(v));
// }

int main()
{
	mlm::vec3 v(4.2f, -1.6f, 3.0f);

	// std::cout << "sqrt\t" << vabs(normalize(v)) << std::endl;
	
	// return (0);
	mat4test();
	// vec2_test();
	// vec3_test();
	// vec4_test();
	// mlm::mat4 value;
	mlm::mat4 value(1.0f);
	// glm::mat4 glm_value;
	// value[0] = mlm::vec4(1.0f, 0.0f, 0.0f, 0.0f);
	// value[1] = mlm::vec4(0.0f, 1.0f, 0.0f, 0.0f);
	// value[2] = mlm::vec4(0.0f, 0.0f, 1.0f, 0.0f);
	value[3] = mlm::vec4(3.0f, 3.0f, 3.0f, 1.0f);
	mlm::vec4 vector(0.f, 0.f, 0.f, 1.0f);
	
	// glm_value[0] = glm::vec4(1.0f, 0.0f, 0.0f, 0.0f);
	// glm_value[1] = glm::vec4(0.0f, 1.0f, 0.0f, 0.0f);
	// glm_value[2] = glm::vec4(0.0f, 0.0f, 1.0f, 0.0f);
	// glm_value[3] = glm::vec4(3.0f, 3.0f, 3.0f, 1.0f);

	// std::cout << sizeof(value) << " " << sizeof(glm_value) << std::endl;


	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
			std::cout << value[j][i] << " ";
		std::cout << std::endl;
	}
	std::cout << std::endl;
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
			// std::cout << glm_value[j][i] << " ";
		std::cout << std::endl;
	}
	// std::cout << memcmp(&value, &glm_value, sizeof(value)) << std::endl;

}