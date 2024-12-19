#include <iostream>
#include "../emlm.hpp"
#include "utils.hpp"

// Arithmatic operator tests
void	vec4_test_op_v4_f(mlm::vec4 v, float s, int op)
{
	mlm::vec4 result;
	mlm::vec4 temp;

	std::cout << "test v4 " << op_str(op) << " f\t";
	switch (op)
	{
	case ADD:
		temp = mlm::vec4(v.x + s, v.y + s, v.z + s, v.w + s);
		result = v + s;
		break ;
	case SUB:
		temp = mlm::vec4(v.x - s, v.y - s, v.z - s, v.w - s);
		result = v - s;
		break ;
	case DIV:
		temp = mlm::vec4(v.x / s, v.y / s, v.z / s, v.w / s);
		result = v / s;
		break ;
	case MULT:
		temp = mlm::vec4(v.x * s, v.y * s, v.z * s, v.w * s);
		result = v * s;
		break ;
	default:
		std::cout << BG_RED << "OPERATOR ERROR" << RESET << std::endl;
		return ;
	}
	test(result == temp);
}

void vec4_test_op_f_v4(float s, mlm::vec4 v, int op)
{
    mlm::vec4 result;
    mlm::vec4 temp;

	std::cout << "test f " << op_str(op) << " v4\t";
    switch (op)
	{
        case ADD:
            temp = mlm::vec4(s + v.x, s + v.y, s + v.z, s + v.w);
            result = s + v;
            break ;
        case SUB:
            temp = mlm::vec4(s - v.x, s - v.y, s - v.z, s - v.w);
            result = s - v;
            break ;
        case DIV:
            temp = mlm::vec4(s / v.x, s / v.y, s / v.z, s / v.w);
            result = s / v;
            break ;
        case MULT:
            temp = mlm::vec4(s * v.x, s * v.y, s * v.z, s * v.w);
            result = s * v;
            break ;
        default:
			std::cout << BG_RED << "OPERATOR ERROR" << RESET << std::endl;
            return ;
    }
	test(result == temp);
}

void	vec4_test_op_v4_v1(mlm::vec4 v, mlm::vec1 s, int op)
{
	mlm::vec4 result;
	mlm::vec4 temp;

	std::cout << "test v4 " << op_str(op) << " v1\t";
	switch (op)
	{
	case ADD:
		temp = mlm::vec4(v.x + s.x, v.y + s.x, v.z + s.x, v.w + s.x);
		result = v + s;
		break ;
	case SUB:
		temp = mlm::vec4(v.x - s.x, v.y - s.x, v.z - s.x, v.w - s.x);
		result = v - s;
		break ;
	case DIV:
		temp = mlm::vec4(v.x / s.x, v.y / s.x, v.z / s.x, v.w / s.x);
		result = v / s;
		break ;
	case MULT:
		temp = mlm::vec4(v.x * s.x, v.y * s.x, v.z * s.x, v.w * s.x);
		result = v * s;
		break ;
	default:
		std::cout << BG_RED << "OPERATOR ERROR" << RESET << std::endl;
		return ;
	}
	test(result == temp);
}

void vec4_test_op_v1_v4(mlm::vec1 s, mlm::vec4 v, int op)
{
    mlm::vec4 result;
    mlm::vec4 temp;

	std::cout << "test v1 " << op_str(op) << " v4\t";
    switch (op)
	{
        case ADD:
            temp = mlm::vec4(s.x + v.x, s.x + v.y, s.x + v.z, s.x + v.w);
            result = s + v;
            break ;
        case SUB:
            temp = mlm::vec4(s.x - v.x, s.x - v.y, s.x - v.z, s.x - v.w);
            result = s - v;
            break ;
        case DIV:
            temp = mlm::vec4(s.x / v.x, s.x / v.y, s.x / v.z, s.x / v.w);
            result = s / v;
            break ;
        case MULT:
            temp = mlm::vec4(s.x * v.x, s.x * v.y, s.x * v.z, s.x * v.w);
            result = s * v;
            break ;
        default:
			std::cout << BG_RED << "OPERATOR ERROR" << RESET << std::endl;
            return ;
    }
    test(result == temp);
}

void	vec4_test_op_v4_v4(mlm::vec4 v1, mlm::vec4 v2, int op)
{
	mlm::vec4 result;
	mlm::vec4 temp;

	std::cout << "test v4 " << op_str(op) << " v4\t";
	switch (op)
	{
	case ADD:
		temp = mlm::vec4(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z, v1.w + v2.w);
		result = v1 + v2;
		break ;
	case SUB:
		temp = mlm::vec4(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z, v1.w - v2.w);
		result = v1 - v2;
		break ;
	case DIV:
		temp = mlm::vec4(v1.x / v2.x, v1.y / v2.y, v1.z / v2.z, v1.w / v2.w);
		result = v1 / v2;
		break ;
	case MULT:
		temp = mlm::vec4(v1.x * v2.x, v1.y * v2.y, v1.z * v2.z, v1.w * v2.w);
		result = v1 * v2;
		break ;
	default:
		std::cout << BG_RED << "OPERATOR ERROR" << RESET << std::endl;
		return ;
	}
	test(result == temp);
}



// Arithmatic assignment operator tests
void	vec4_test_op_assignment_v4_f(mlm::vec4 v, float s, int op)
{
	mlm::vec4 temp;

	std::cout << "test v4 " << op_str(op) << " f\t";
	switch (op)
	{
	case ADD_EQ:
		temp = mlm::vec4(v.x + s, v.y + s, v.z + s, v.w + s);
		v += s;
		break ;
	case SUB_EQ:
		temp = mlm::vec4(v.x - s, v.y - s, v.z - s, v.w - s);
		v -= s;
		break ;
	case DIV_EQ:
		temp = mlm::vec4(v.x / s, v.y / s, v.z / s, v.w / s);
		v /= s;
		break ;
	case MULT_EQ:
		temp = mlm::vec4(v.x * s, v.y * s, v.z * s, v.w * s);
		v *= s;
		break ;
	default:
		std::cout << BG_RED << "OPERATOR ERROR" << RESET << std::endl;
		return ;
	}
	test(v == temp);
}

void	vec4_test_op_assignment_v4_v1(mlm::vec4 v, mlm::vec1 s, int op)
{
	mlm::vec4 temp;

	std::cout << "test v4 " << op_str(op) << " v1\t";
	switch (op)
	{
	case ADD_EQ:
		temp = mlm::vec4(v.x + s.x, v.y + s.x, v.z + s.x, v.w + s.x);
		v += s;
		break ;
	case SUB_EQ:
		temp = mlm::vec4(v.x - s.x, v.y - s.x, v.z - s.x, v.w - s.x);
		v -= s;
		break ;
	case DIV_EQ:
		temp = mlm::vec4(v.x / s.x, v.y / s.x, v.z / s.x, v.w / s.x);
		v /= s;
		break ;
	case MULT_EQ:
		temp = mlm::vec4(v.x * s.x, v.y * s.x, v.z * s.x, v.w * s.x);
		v *= s;
		break ;
	default:
		std::cout << BG_RED << "OPERATOR ERROR" << RESET << std::endl;
		return ;
	}
	test(v == temp);
}

void	vec4_test_op_assignment_v4_v4(mlm::vec4 v1, mlm::vec4 v2, int op)
{
	mlm::vec4 temp;

	std::cout << "test v4 " << op_str(op) << " v4\t";
	switch (op)
	{
	case ADD_EQ:
		temp = mlm::vec4(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z, v1.w + v2.w);
		v1 += v2;
		break ;
	case SUB_EQ:
		temp = mlm::vec4(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z, v1.w - v2.w);
		v1 -= v2;
		break ;
	case DIV_EQ:
		temp = mlm::vec4(v1.x / v2.x, v1.y / v2.y, v1.z / v2.z, v1.w / v2.w);
		v1 /= v2;
		break ;
	case MULT_EQ:
		temp = mlm::vec4(v1.x * v2.x, v1.y * v2.y, v1.z * v2.z, v1.w * v2.w);
		v1 *= v2;
		break ;
	default:
		std::cout << BG_RED << "OPERATOR ERROR" << RESET << std::endl;
		return ;
	}
	test(v1 == temp);
}
