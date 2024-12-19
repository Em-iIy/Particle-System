#include <iostream>
#include "utils.hpp"
#include <cassert>

void test(bool b)
{
	if (b)
		std::cout << MSG_OK << std::endl;
	else
		std::cout << MSG_KO << std::endl;
	assert(b);
}

std::string	op_str(int op)
{
	switch (op)
	{
	case ADD:
		return ("+");
	case SUB:
		return ("-");
	case DIV:
		return ("/");
	case MULT:
		return ("*");
	case ADD_EQ:
		return ("+=");
	case SUB_EQ:
		return ("-=");
	case DIV_EQ:
		return ("/=");
	case MULT_EQ:
		return ("*=");
	default:
		break;
	}
	return ("");
}