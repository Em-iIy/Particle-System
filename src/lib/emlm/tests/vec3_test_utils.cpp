#include <iostream>
#include "../emlm.hpp"
#include "utils.hpp"

// Arithmatic operator tests
void	vec3_test_op_v3_f(mlm::vec3 v, float s, int op)
{
	mlm::vec3 result;
	mlm::vec3 temp;

	std::cout << "test v3 " << op_str(op) << " f\t";
	switch (op)
	{
	case ADD:
		temp = mlm::vec3(v.x + s, v.y + s, v.z + s);
		result = v + s;
		break ;
	case SUB:
		temp = mlm::vec3(v.x - s, v.y - s, v.z - s);
		result = v - s;
		break ;
	case DIV:
		temp = mlm::vec3(v.x / s, v.y / s, v.z / s);
		result = v / s;
		break ;
	case MULT:
		temp = mlm::vec3(v.x * s, v.y * s, v.z * s);
		result = v * s;
		break ;
	default:
		std::cout << BG_RED << "OPERATOR ERROR" << RESET << std::endl;
		return ;
	}
	test(result == temp);
}

void vec3_test_op_f_v3(float s, mlm::vec3 v, int op)
{
    mlm::vec3 result;
    mlm::vec3 temp;

	std::cout << "test f " << op_str(op) << " v3\t";
    switch (op)
	{
        case ADD:
            temp = mlm::vec3(s + v.x, s + v.y, s + v.z);
            result = s + v;
            break ;
        case SUB:
            temp = mlm::vec3(s - v.x, s - v.y, s - v.z);
            result = s - v;
            break ;
        case DIV:
            temp = mlm::vec3(s / v.x, s / v.y, s / v.z);
            result = s / v;
            break ;
        case MULT:
            temp = mlm::vec3(s * v.x, s * v.y, s * v.z);
            result = s * v;
            break ;
        default:
			std::cout << BG_RED << "OPERATOR ERROR" << RESET << std::endl;
            return ;
    }
	test(result == temp);
}

void	vec3_test_op_v3_v1(mlm::vec3 v, mlm::vec1 s, int op)
{
	mlm::vec3 result;
	mlm::vec3 temp;

	std::cout << "test v3 " << op_str(op) << " v1\t";
	switch (op)
	{
	case ADD:
		temp = mlm::vec3(v.x + s.x, v.y + s.x, v.z + s.x);
		result = v + s;
		break ;
	case SUB:
		temp = mlm::vec3(v.x - s.x, v.y - s.x, v.z - s.x);
		result = v - s;
		break ;
	case DIV:
		temp = mlm::vec3(v.x / s.x, v.y / s.x, v.z / s.x);
		result = v / s;
		break ;
	case MULT:
		temp = mlm::vec3(v.x * s.x, v.y * s.x, v.z * s.x);
		result = v * s;
		break ;
	default:
		std::cout << BG_RED << "OPERATOR ERROR" << RESET << std::endl;
		return ;
	}
	test(result == temp);
}

void vec3_test_op_v1_v3(mlm::vec1 s, mlm::vec3 v, int op)
{
    mlm::vec3 result;
    mlm::vec3 temp;

	std::cout << "test v1 " << op_str(op) << " v3\t";
    switch (op)
	{
        case ADD:
            temp = mlm::vec3(s.x + v.x, s.x + v.y, s.x + v.z);
            result = s + v;
            break ;
        case SUB:
            temp = mlm::vec3(s.x - v.x, s.x - v.y, s.x - v.z);
            result = s - v;
            break ;
        case DIV:
            temp = mlm::vec3(s.x / v.x, s.x / v.y, s.x / v.z);
            result = s / v;
            break ;
        case MULT:
            temp = mlm::vec3(s.x * v.x, s.x * v.y, s.x * v.z);
            result = s * v;
            break ;
        default:
			std::cout << BG_RED << "OPERATOR ERROR" << RESET << std::endl;
            return ;
    }
    test(result == temp);
}

void	vec3_test_op_v3_v3(mlm::vec3 v1, mlm::vec3 v2, int op)
{
	mlm::vec3 result;
	mlm::vec3 temp;

	std::cout << "test v3 " << op_str(op) << " v3\t";
	switch (op)
	{
	case ADD:
		temp = mlm::vec3(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z);
		result = v1 + v2;
		break ;
	case SUB:
		temp = mlm::vec3(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z);
		result = v1 - v2;
		break ;
	case DIV:
		temp = mlm::vec3(v1.x / v2.x, v1.y / v2.y, v1.z / v2.z);
		result = v1 / v2;
		break ;
	case MULT:
		temp = mlm::vec3(v1.x * v2.x, v1.y * v2.y, v1.z * v2.z);
		result = v1 * v2;
		break ;
	default:
		std::cout << BG_RED << "OPERATOR ERROR" << RESET << std::endl;
		return ;
	}
	test(result == temp);
}



// Arithmatic assignment operator tests
void	vec3_test_op_assignment_v3_f(mlm::vec3 v, float s, int op)
{
	mlm::vec3 temp;

	std::cout << "test v3 " << op_str(op) << " f\t";
	switch (op)
	{
	case ADD_EQ:
		temp = mlm::vec3(v.x + s, v.y + s, v.z + s);
		v += s;
		break ;
	case SUB_EQ:
		temp = mlm::vec3(v.x - s, v.y - s, v.z - s);
		v -= s;
		break ;
	case DIV_EQ:
		temp = mlm::vec3(v.x / s, v.y / s, v.z / s);
		v /= s;
		break ;
	case MULT_EQ:
		temp = mlm::vec3(v.x * s, v.y * s, v.z * s);
		v *= s;
		break ;
	default:
		std::cout << BG_RED << "OPERATOR ERROR" << RESET << std::endl;
		return ;
	}
	test(v == temp);
}

void	vec3_test_op_assignment_v3_v1(mlm::vec3 v, mlm::vec1 s, int op)
{
	mlm::vec3 temp;

	std::cout << "test v3 " << op_str(op) << " v1\t";
	switch (op)
	{
	case ADD_EQ:
		temp = mlm::vec3(v.x + s.x, v.y + s.x, v.z + s.x);
		v += s;
		break ;
	case SUB_EQ:
		temp = mlm::vec3(v.x - s.x, v.y - s.x, v.z - s.x);
		v -= s;
		break ;
	case DIV_EQ:
		temp = mlm::vec3(v.x / s.x, v.y / s.x, v.z / s.x);
		v /= s;
		break ;
	case MULT_EQ:
		temp = mlm::vec3(v.x * s.x, v.y * s.x, v.z * s.x);
		v *= s;
		break ;
	default:
		std::cout << BG_RED << "OPERATOR ERROR" << RESET << std::endl;
		return ;
	}
	test(v == temp);
}

void	vec3_test_op_assignment_v3_v3(mlm::vec3 v1, mlm::vec3 v2, int op)
{
	mlm::vec3 temp;

	std::cout << "test v3 " << op_str(op) << " v3\t";
	switch (op)
	{
	case ADD_EQ:
		temp = mlm::vec3(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z);
		v1 += v2;
		break ;
	case SUB_EQ:
		temp = mlm::vec3(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z);
		v1 -= v2;
		break ;
	case DIV_EQ:
		temp = mlm::vec3(v1.x / v2.x, v1.y / v2.y, v1.z / v2.z);
		v1 /= v2;
		break ;
	case MULT_EQ:
		temp = mlm::vec3(v1.x * v2.x, v1.y * v2.y, v1.z * v2.z);
		v1 *= v2;
		break ;
	default:
		std::cout << BG_RED << "OPERATOR ERROR" << RESET << std::endl;
		return ;
	}
	test(v1 == temp);
}
