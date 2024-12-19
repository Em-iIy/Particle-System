#pragma once

#include <string>
#include "colour.h"

#define MSG_OK GREEN "OK" RESET 
#define MSG_KO RED "KO" RESET 

enum {
	ADD,
	SUB,
	DIV,
	MULT,
	ADD_EQ,
	SUB_EQ,
	DIV_EQ,
	MULT_EQ
};

void test(bool b);
std::string	op_str(int op);
