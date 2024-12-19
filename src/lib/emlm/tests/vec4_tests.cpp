#include "vec4_test_utils.hpp"
#include "colour.h"
#include "utils.hpp"
#include <iostream>

void	vec4_test(void)
{
	std::cout << BG_ORANGE << "Testing vec4" << RESET << std::endl;
	mlm::vec4 temp(1.1f, 2.2f, 3.3f, 4.4f);
	mlm::vec4 temp2(1.1f, -2.2f, 3.3f, -4.4f);

	std::cout << YELLOW << "\nArithmatic Operators" << RESET << std::endl;
	vec4_test_op_v4_f(temp, 5.31f, ADD);
	vec4_test_op_v4_f(temp2, 1235.31f, ADD);
	vec4_test_op_v4_f(temp, 5.31f, SUB);
	vec4_test_op_v4_f(temp2, 1235.31f, SUB);
	vec4_test_op_v4_f(temp, 5.31f, DIV);
	vec4_test_op_v4_f(temp2, 1235.31f, DIV);
	vec4_test_op_v4_f(temp, 5.31f, MULT);
	vec4_test_op_v4_f(temp2, 1235.31f, MULT);

	vec4_test_op_f_v4(5.31f, temp, ADD);
	vec4_test_op_f_v4(1235.31f, temp2, ADD);
	vec4_test_op_f_v4(5.31f, temp, SUB);
	vec4_test_op_f_v4(1235.31f, temp2, SUB);
	vec4_test_op_f_v4(5.31f, temp, DIV);
	vec4_test_op_f_v4(1235.31f, temp2, DIV);
	vec4_test_op_f_v4(5.31f, temp, MULT);
	vec4_test_op_f_v4(1235.31f, temp2, MULT);

	vec4_test_op_v4_v1(temp, 5.31f, ADD);
	vec4_test_op_v4_v1(temp2, 1235.31f, ADD);
	vec4_test_op_v4_v1(temp, 5.31f, SUB);
	vec4_test_op_v4_v1(temp2, 1235.31f, SUB);
	vec4_test_op_v4_v1(temp, 5.31f, DIV);
	vec4_test_op_v4_v1(temp2, 1235.31f, DIV);
	vec4_test_op_v4_v1(temp, 5.31f, MULT);
	vec4_test_op_v4_v1(temp2, 1235.31f, MULT);

	vec4_test_op_v1_v4(5.31f, temp, ADD);
	vec4_test_op_v1_v4(1235.31f, temp2, ADD);
	vec4_test_op_v1_v4(5.31f, temp, SUB);
	vec4_test_op_v1_v4(1235.31f, temp2, SUB);
	vec4_test_op_v1_v4(5.31f, temp, DIV);
	vec4_test_op_v1_v4(1235.31f, temp2, DIV);
	vec4_test_op_v1_v4(5.31f, temp, MULT);
	vec4_test_op_v1_v4(1235.31f, temp2, MULT);

	vec4_test_op_v4_v1(temp, 5.31f, ADD);
	vec4_test_op_v4_v1(temp2, 1235.31f, ADD);
	vec4_test_op_v4_v1(temp, 5.31f, SUB);
	vec4_test_op_v4_v1(temp2, 1235.31f, SUB);
	vec4_test_op_v4_v1(temp, 5.31f, DIV);
	vec4_test_op_v4_v1(temp2, 1235.31f, DIV);
	vec4_test_op_v4_v1(temp, 5.31f, MULT);
	vec4_test_op_v4_v1(temp2, 1235.31f, MULT);

	vec4_test_op_v4_v4(temp, 5.31f, ADD);
	vec4_test_op_v4_v4(temp2, 1235.31f, ADD);
	vec4_test_op_v4_v4(temp, 5.31f, SUB);
	vec4_test_op_v4_v4(temp2, 1235.31f, SUB);
	vec4_test_op_v4_v4(temp, 5.31f, DIV);
	vec4_test_op_v4_v4(temp2, 1235.31f, DIV);
	vec4_test_op_v4_v4(temp, 5.31f, MULT);
	vec4_test_op_v4_v4(temp2, 1235.31f, MULT);

	std::cout << YELLOW << "\nArithmatic Assignment Operators" << RESET << std::endl;
	vec4_test_op_assignment_v4_f(temp, 5.31f, ADD_EQ);
	vec4_test_op_assignment_v4_f(temp2, 1235.31f, ADD_EQ);
	vec4_test_op_assignment_v4_f(temp, 5.31f, SUB_EQ);
	vec4_test_op_assignment_v4_f(temp2, 1235.31f, SUB_EQ);
	vec4_test_op_assignment_v4_f(temp, 5.31f, DIV_EQ);
	vec4_test_op_assignment_v4_f(temp2, 1235.31f, DIV_EQ);
	vec4_test_op_assignment_v4_f(temp, 5.31f, MULT_EQ);
	vec4_test_op_assignment_v4_f(temp2, 1235.31f, MULT_EQ);

	vec4_test_op_assignment_v4_v1(temp, 5.31f, ADD_EQ);
	vec4_test_op_assignment_v4_v1(temp2, 1235.31f, ADD_EQ);
	vec4_test_op_assignment_v4_v1(temp, 5.31f, SUB_EQ);
	vec4_test_op_assignment_v4_v1(temp2, 1235.31f, SUB_EQ);
	vec4_test_op_assignment_v4_v1(temp, 5.31f, DIV_EQ);
	vec4_test_op_assignment_v4_v1(temp2, 1235.31f, DIV_EQ);
	vec4_test_op_assignment_v4_v1(temp, 5.31f, MULT_EQ);
	vec4_test_op_assignment_v4_v1(temp2, 1235.31f, MULT_EQ);

	vec4_test_op_assignment_v4_v4(temp, 5.31f, ADD_EQ);
	vec4_test_op_assignment_v4_v4(temp2, 1235.31f, ADD_EQ);
	vec4_test_op_assignment_v4_v4(temp, 5.31f, SUB_EQ);
	vec4_test_op_assignment_v4_v4(temp2, 1235.31f, SUB_EQ);
	vec4_test_op_assignment_v4_v4(temp, 5.31f, DIV_EQ);
	vec4_test_op_assignment_v4_v4(temp2, 1235.31f, DIV_EQ);
	vec4_test_op_assignment_v4_v4(temp, 5.31f, MULT_EQ);
	vec4_test_op_assignment_v4_v4(temp2, 1235.31f, MULT_EQ);
}