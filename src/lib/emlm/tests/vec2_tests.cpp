#include "vec2_test_utils.hpp"
#include "colour.h"
#include "utils.hpp"
#include <iostream>

void	vec2_test(void)
{
	std::cout << BG_ORANGE << "Testing vec2" << RESET << std::endl;
	mlm::vec2 temp(1.1f, 2.2f);
	mlm::vec2 temp2(1.1f, -4.4f);

	std::cout << YELLOW << "\nArithmatic Operators" << RESET << std::endl;
	vec2_test_op_v2_f(temp, 5.31f, ADD);
	vec2_test_op_v2_f(temp2, 1235.31f, ADD);
	vec2_test_op_v2_f(temp, 5.31f, SUB);
	vec2_test_op_v2_f(temp2, 1235.31f, SUB);
	vec2_test_op_v2_f(temp, 5.31f, DIV);
	vec2_test_op_v2_f(temp2, 1235.31f, DIV);
	vec2_test_op_v2_f(temp, 5.31f, MULT);
	vec2_test_op_v2_f(temp2, 1235.31f, MULT);

	vec2_test_op_f_v2(5.31f, temp, ADD);
	vec2_test_op_f_v2(1235.31f, temp2, ADD);
	vec2_test_op_f_v2(5.31f, temp, SUB);
	vec2_test_op_f_v2(1235.31f, temp2, SUB);
	vec2_test_op_f_v2(5.31f, temp, DIV);
	vec2_test_op_f_v2(1235.31f, temp2, DIV);
	vec2_test_op_f_v2(5.31f, temp, MULT);
	vec2_test_op_f_v2(1235.31f, temp2, MULT);

	vec2_test_op_v2_v1(temp, 5.31f, ADD);
	vec2_test_op_v2_v1(temp2, 1235.31f, ADD);
	vec2_test_op_v2_v1(temp, 5.31f, SUB);
	vec2_test_op_v2_v1(temp2, 1235.31f, SUB);
	vec2_test_op_v2_v1(temp, 5.31f, DIV);
	vec2_test_op_v2_v1(temp2, 1235.31f, DIV);
	vec2_test_op_v2_v1(temp, 5.31f, MULT);
	vec2_test_op_v2_v1(temp2, 1235.31f, MULT);

	vec2_test_op_v1_v2(5.31f, temp, ADD);
	vec2_test_op_v1_v2(1235.31f, temp2, ADD);
	vec2_test_op_v1_v2(5.31f, temp, SUB);
	vec2_test_op_v1_v2(1235.31f, temp2, SUB);
	vec2_test_op_v1_v2(5.31f, temp, DIV);
	vec2_test_op_v1_v2(1235.31f, temp2, DIV);
	vec2_test_op_v1_v2(5.31f, temp, MULT);
	vec2_test_op_v1_v2(1235.31f, temp2, MULT);

	vec2_test_op_v2_v1(temp, 5.31f, ADD);
	vec2_test_op_v2_v1(temp2, 1235.31f, ADD);
	vec2_test_op_v2_v1(temp, 5.31f, SUB);
	vec2_test_op_v2_v1(temp2, 1235.31f, SUB);
	vec2_test_op_v2_v1(temp, 5.31f, DIV);
	vec2_test_op_v2_v1(temp2, 1235.31f, DIV);
	vec2_test_op_v2_v1(temp, 5.31f, MULT);
	vec2_test_op_v2_v1(temp2, 1235.31f, MULT);

	vec2_test_op_v2_v2(temp, 5.31f, ADD);
	vec2_test_op_v2_v2(temp2, 1235.31f, ADD);
	vec2_test_op_v2_v2(temp, 5.31f, SUB);
	vec2_test_op_v2_v2(temp2, 1235.31f, SUB);
	vec2_test_op_v2_v2(temp, 5.31f, DIV);
	vec2_test_op_v2_v2(temp2, 1235.31f, DIV);
	vec2_test_op_v2_v2(temp, 5.31f, MULT);
	vec2_test_op_v2_v2(temp2, 1235.31f, MULT);

	std::cout << YELLOW << "\nArithmatic Assignment Operators" << RESET << std::endl;
	vec2_test_op_assignment_v2_f(temp, 5.31f, ADD_EQ);
	vec2_test_op_assignment_v2_f(temp2, 1235.31f, ADD_EQ);
	vec2_test_op_assignment_v2_f(temp, 5.31f, SUB_EQ);
	vec2_test_op_assignment_v2_f(temp2, 1235.31f, SUB_EQ);
	vec2_test_op_assignment_v2_f(temp, 5.31f, DIV_EQ);
	vec2_test_op_assignment_v2_f(temp2, 1235.31f, DIV_EQ);
	vec2_test_op_assignment_v2_f(temp, 5.31f, MULT_EQ);
	vec2_test_op_assignment_v2_f(temp2, 1235.31f, MULT_EQ);

	vec2_test_op_assignment_v2_v1(temp, 5.31f, ADD_EQ);
	vec2_test_op_assignment_v2_v1(temp2, 1235.31f, ADD_EQ);
	vec2_test_op_assignment_v2_v1(temp, 5.31f, SUB_EQ);
	vec2_test_op_assignment_v2_v1(temp2, 1235.31f, SUB_EQ);
	vec2_test_op_assignment_v2_v1(temp, 5.31f, DIV_EQ);
	vec2_test_op_assignment_v2_v1(temp2, 1235.31f, DIV_EQ);
	vec2_test_op_assignment_v2_v1(temp, 5.31f, MULT_EQ);
	vec2_test_op_assignment_v2_v1(temp2, 1235.31f, MULT_EQ);

	vec2_test_op_assignment_v2_v2(temp, 5.31f, ADD_EQ);
	vec2_test_op_assignment_v2_v2(temp2, 1235.31f, ADD_EQ);
	vec2_test_op_assignment_v2_v2(temp, 5.31f, SUB_EQ);
	vec2_test_op_assignment_v2_v2(temp2, 1235.31f, SUB_EQ);
	vec2_test_op_assignment_v2_v2(temp, 5.31f, DIV_EQ);
	vec2_test_op_assignment_v2_v2(temp2, 1235.31f, DIV_EQ);
	vec2_test_op_assignment_v2_v2(temp, 5.31f, MULT_EQ);
	vec2_test_op_assignment_v2_v2(temp2, 1235.31f, MULT_EQ);
}