#include <iostream>
#include "../emlm.hpp"
#include "utils.hpp"

// Arithmatic operator tests
void	vec2_test_op_v2_f(mlm::vec2 v, float s, int op)
{
	mlm::vec2 result;
	mlm::vec2 temp;

	std::cout << "test v2 " << op_str(op) << " f\t";
	switch (op)
	{
	case ADD:
		temp = mlm::vec2(v.x + s, v.y + s);
		result = v + s;
		break ;
	case SUB:
		temp = mlm::vec2(v.x - s, v.y - s);
		result = v - s;
		break ;
	case DIV:
		temp = mlm::vec2(v.x / s, v.y / s);
		result = v / s;
		break ;
	case MULT:
		temp = mlm::vec2(v.x * s, v.y * s);
		result = v * s;
		break ;
	default:
		std::cout << BG_RED << "OPERATOR ERROR" << RESET << std::endl;
		return ;
	}
	test(result == temp);
}

void vec2_test_op_f_v2(float s, mlm::vec2 v, int op)
{
    mlm::vec2 result;
    mlm::vec2 temp;

	std::cout << "test f " << op_str(op) << " v2\t";
    switch (op)
	{
        case ADD:
            temp = mlm::vec2(s + v.x, s + v.y);
            result = s + v;
            break ;
        case SUB:
            temp = mlm::vec2(s - v.x, s - v.y);
            result = s - v;
            break ;
        case DIV:
            temp = mlm::vec2(s / v.x, s / v.y);
            result = s / v;
            break ;
        case MULT:
            temp = mlm::vec2(s * v.x, s * v.y);
            result = s * v;
            break ;
        default:
			std::cout << BG_RED << "OPERATOR ERROR" << RESET << std::endl;
            return ;
    }
	test(result == temp);
}

void	vec2_test_op_v2_v1(mlm::vec2 v, mlm::vec1 s, int op)
{
	mlm::vec2 result;
	mlm::vec2 temp;

	std::cout << "test v2 " << op_str(op) << " v1\t";
	switch (op)
	{
	case ADD:
		temp = mlm::vec2(v.x + s.x, v.y + s.x);
		result = v + s;
		break ;
	case SUB:
		temp = mlm::vec2(v.x - s.x, v.y - s.x);
		result = v - s;
		break ;
	case DIV:
		temp = mlm::vec2(v.x / s.x, v.y / s.x);
		result = v / s;
		break ;
	case MULT:
		temp = mlm::vec2(v.x * s.x, v.y * s.x);
		result = v * s;
		break ;
	default:
		std::cout << BG_RED << "OPERATOR ERROR" << RESET << std::endl;
		return ;
	}
	test(result == temp);
}

void vec2_test_op_v1_v2(mlm::vec1 s, mlm::vec2 v, int op)
{
    mlm::vec2 result;
    mlm::vec2 temp;

	std::cout << "test v1 " << op_str(op) << " v2\t";
    switch (op)
	{
        case ADD:
            temp = mlm::vec2(s.x + v.x, s.x + v.y);
            result = s + v;
            break ;
        case SUB:
            temp = mlm::vec2(s.x - v.x, s.x - v.y);
            result = s - v;
            break ;
        case DIV:
            temp = mlm::vec2(s.x / v.x, s.x / v.y);
            result = s / v;
            break ;
        case MULT:
            temp = mlm::vec2(s.x * v.x, s.x * v.y);
            result = s * v;
            break ;
        default:
			std::cout << BG_RED << "OPERATOR ERROR" << RESET << std::endl;
            return ;
    }
    test(result == temp);
}

void	vec2_test_op_v2_v2(mlm::vec2 v1, mlm::vec2 v2, int op)
{
	mlm::vec2 result;
	mlm::vec2 temp;

	std::cout << "test v2 " << op_str(op) << " v2\t";
	switch (op)
	{
	case ADD:
		temp = mlm::vec2(v1.x + v2.x, v1.y + v2.y);
		result = v1 + v2;
		break ;
	case SUB:
		temp = mlm::vec2(v1.x - v2.x, v1.y - v2.y);
		result = v1 - v2;
		break ;
	case DIV:
		temp = mlm::vec2(v1.x / v2.x, v1.y / v2.y);
		result = v1 / v2;
		break ;
	case MULT:
		temp = mlm::vec2(v1.x * v2.x, v1.y * v2.y);
		result = v1 * v2;
		break ;
	default:
		std::cout << BG_RED << "OPERATOR ERROR" << RESET << std::endl;
		return ;
	}
	test(result == temp);
}



// Arithmatic assignment operator tests
void	vec2_test_op_assignment_v2_f(mlm::vec2 v, float s, int op)
{
	mlm::vec2 temp;

	std::cout << "test v2 " << op_str(op) << " f\t";
	switch (op)
	{
	case ADD_EQ:
		temp = mlm::vec2(v.x + s, v.y + s);
		v += s;
		break ;
	case SUB_EQ:
		temp = mlm::vec2(v.x - s, v.y - s);
		v -= s;
		break ;
	case DIV_EQ:
		temp = mlm::vec2(v.x / s, v.y / s);
		v /= s;
		break ;
	case MULT_EQ:
		temp = mlm::vec2(v.x * s, v.y * s);
		v *= s;
		break ;
	default:
		std::cout << BG_RED << "OPERATOR ERROR" << RESET << std::endl;
		return ;
	}
	test(v == temp);
}

void	vec2_test_op_assignment_v2_v1(mlm::vec2 v, mlm::vec1 s, int op)
{
	mlm::vec2 temp;

	std::cout << "test v2 " << op_str(op) << " v1\t";
	switch (op)
	{
	case ADD_EQ:
		temp = mlm::vec2(v.x + s.x, v.y + s.x);
		v += s;
		break ;
	case SUB_EQ:
		temp = mlm::vec2(v.x - s.x, v.y - s.x);
		v -= s;
		break ;
	case DIV_EQ:
		temp = mlm::vec2(v.x / s.x, v.y / s.x);
		v /= s;
		break ;
	case MULT_EQ:
		temp = mlm::vec2(v.x * s.x, v.y * s.x);
		v *= s;
		break ;
	default:
		std::cout << BG_RED << "OPERATOR ERROR" << RESET << std::endl;
		return ;
	}
	test(v == temp);
}

void	vec2_test_op_assignment_v2_v2(mlm::vec2 v1, mlm::vec2 v2, int op)
{
	mlm::vec2 temp;

	std::cout << "test v2 " << op_str(op) << " v2\t";
	switch (op)
	{
	case ADD_EQ:
		temp = mlm::vec2(v1.x + v2.x, v1.y + v2.y);
		v1 += v2;
		break ;
	case SUB_EQ:
		temp = mlm::vec2(v1.x - v2.x, v1.y - v2.y);
		v1 -= v2;
		break ;
	case DIV_EQ:
		temp = mlm::vec2(v1.x / v2.x, v1.y / v2.y);
		v1 /= v2;
		break ;
	case MULT_EQ:
		temp = mlm::vec2(v1.x * v2.x, v1.y * v2.y);
		v1 *= v2;
		break ;
	default:
		std::cout << BG_RED << "OPERATOR ERROR" << RESET << std::endl;
		return ;
	}
	test(v1 == temp);
}
