#include "vec3_test_utils.hpp"
#include "colour.h"
#include "utils.hpp"
#include <iostream>

void	vec3_test(void)
{
	std::cout << BG_ORANGE << "Testing vec3" << RESET << std::endl;
	mlm::vec3 temp(1.1f, 2.2f, 3.3f);
	mlm::vec3 temp2(1.1f, -2.2f,-4.4f);

	std::cout << YELLOW << "\nArithmatic Operators" << RESET << std::endl;
	vec3_test_op_v3_f(temp, 5.31f, ADD);
	vec3_test_op_v3_f(temp2, 1235.31f, ADD);
	vec3_test_op_v3_f(temp, 5.31f, SUB);
	vec3_test_op_v3_f(temp2, 1235.31f, SUB);
	vec3_test_op_v3_f(temp, 5.31f, DIV);
	vec3_test_op_v3_f(temp2, 1235.31f, DIV);
	vec3_test_op_v3_f(temp, 5.31f, MULT);
	vec3_test_op_v3_f(temp2, 1235.31f, MULT);

	vec3_test_op_f_v3(5.31f, temp, ADD);
	vec3_test_op_f_v3(1235.31f, temp2, ADD);
	vec3_test_op_f_v3(5.31f, temp, SUB);
	vec3_test_op_f_v3(1235.31f, temp2, SUB);
	vec3_test_op_f_v3(5.31f, temp, DIV);
	vec3_test_op_f_v3(1235.31f, temp2, DIV);
	vec3_test_op_f_v3(5.31f, temp, MULT);
	vec3_test_op_f_v3(1235.31f, temp2, MULT);

	vec3_test_op_v3_v1(temp, 5.31f, ADD);
	vec3_test_op_v3_v1(temp2, 1235.31f, ADD);
	vec3_test_op_v3_v1(temp, 5.31f, SUB);
	vec3_test_op_v3_v1(temp2, 1235.31f, SUB);
	vec3_test_op_v3_v1(temp, 5.31f, DIV);
	vec3_test_op_v3_v1(temp2, 1235.31f, DIV);
	vec3_test_op_v3_v1(temp, 5.31f, MULT);
	vec3_test_op_v3_v1(temp2, 1235.31f, MULT);

	vec3_test_op_v1_v3(5.31f, temp, ADD);
	vec3_test_op_v1_v3(1235.31f, temp2, ADD);
	vec3_test_op_v1_v3(5.31f, temp, SUB);
	vec3_test_op_v1_v3(1235.31f, temp2, SUB);
	vec3_test_op_v1_v3(5.31f, temp, DIV);
	vec3_test_op_v1_v3(1235.31f, temp2, DIV);
	vec3_test_op_v1_v3(5.31f, temp, MULT);
	vec3_test_op_v1_v3(1235.31f, temp2, MULT);

	vec3_test_op_v3_v1(temp, 5.31f, ADD);
	vec3_test_op_v3_v1(temp2, 1235.31f, ADD);
	vec3_test_op_v3_v1(temp, 5.31f, SUB);
	vec3_test_op_v3_v1(temp2, 1235.31f, SUB);
	vec3_test_op_v3_v1(temp, 5.31f, DIV);
	vec3_test_op_v3_v1(temp2, 1235.31f, DIV);
	vec3_test_op_v3_v1(temp, 5.31f, MULT);
	vec3_test_op_v3_v1(temp2, 1235.31f, MULT);

	vec3_test_op_v3_v3(temp, 5.31f, ADD);
	vec3_test_op_v3_v3(temp2, 1235.31f, ADD);
	vec3_test_op_v3_v3(temp, 5.31f, SUB);
	vec3_test_op_v3_v3(temp2, 1235.31f, SUB);
	vec3_test_op_v3_v3(temp, 5.31f, DIV);
	vec3_test_op_v3_v3(temp2, 1235.31f, DIV);
	vec3_test_op_v3_v3(temp, 5.31f, MULT);
	vec3_test_op_v3_v3(temp2, 1235.31f, MULT);

	std::cout << YELLOW << "\nArithmatic Assignment Operators" << RESET << std::endl;
	vec3_test_op_assignment_v3_f(temp, 5.31f, ADD_EQ);
	vec3_test_op_assignment_v3_f(temp2, 1235.31f, ADD_EQ);
	vec3_test_op_assignment_v3_f(temp, 5.31f, SUB_EQ);
	vec3_test_op_assignment_v3_f(temp2, 1235.31f, SUB_EQ);
	vec3_test_op_assignment_v3_f(temp, 5.31f, DIV_EQ);
	vec3_test_op_assignment_v3_f(temp2, 1235.31f, DIV_EQ);
	vec3_test_op_assignment_v3_f(temp, 5.31f, MULT_EQ);
	vec3_test_op_assignment_v3_f(temp2, 1235.31f, MULT_EQ);

	vec3_test_op_assignment_v3_v1(temp, 5.31f, ADD_EQ);
	vec3_test_op_assignment_v3_v1(temp2, 1235.31f, ADD_EQ);
	vec3_test_op_assignment_v3_v1(temp, 5.31f, SUB_EQ);
	vec3_test_op_assignment_v3_v1(temp2, 1235.31f, SUB_EQ);
	vec3_test_op_assignment_v3_v1(temp, 5.31f, DIV_EQ);
	vec3_test_op_assignment_v3_v1(temp2, 1235.31f, DIV_EQ);
	vec3_test_op_assignment_v3_v1(temp, 5.31f, MULT_EQ);
	vec3_test_op_assignment_v3_v1(temp2, 1235.31f, MULT_EQ);

	vec3_test_op_assignment_v3_v3(temp, 5.31f, ADD_EQ);
	vec3_test_op_assignment_v3_v3(temp2, 1235.31f, ADD_EQ);
	vec3_test_op_assignment_v3_v3(temp, 5.31f, SUB_EQ);
	vec3_test_op_assignment_v3_v3(temp2, 1235.31f, SUB_EQ);
	vec3_test_op_assignment_v3_v3(temp, 5.31f, DIV_EQ);
	vec3_test_op_assignment_v3_v3(temp2, 1235.31f, DIV_EQ);
	vec3_test_op_assignment_v3_v3(temp, 5.31f, MULT_EQ);
	vec3_test_op_assignment_v3_v3(temp2, 1235.31f, MULT_EQ);
}