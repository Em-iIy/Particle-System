/*
Created by: Emily (Em_iIy) Winnink
Created on: 5/3/2025
*/
#include "emlm/emlm.hpp"
#include <stdlib.h>

/*
//	Returns a vec3 with random values between 0 and 1
*/
mlm::vec3	rand_vec3()
{
	return (mlm::vec3(rand() / 2147483648.0f, rand() / 2147483648.0f, rand() / 2147483648.0f));
}
