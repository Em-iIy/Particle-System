#pragma once

#include "../emlm.hpp"

// Arithmatic operator tests
void	vec2_test_op_v2_f(mlm::vec2 v, float s, int op);
void	vec2_test_op_f_v2(float s, mlm::vec2 v, int op);
void	vec2_test_op_v2_v1(mlm::vec2 v, mlm::vec1 s, int op);
void	vec2_test_op_v1_v2(mlm::vec1 s, mlm::vec2 v, int op);
void	vec2_test_op_v2_v2(mlm::vec2 v1, mlm::vec2 v2, int op);

// Arithmatic assignment operator tests
void	vec2_test_op_assignment_v2_f(mlm::vec2 v, float s, int op);
void	vec2_test_op_assignment_v2_v1(mlm::vec2 v, mlm::vec1 s, int op);
void	vec2_test_op_assignment_v2_v2(mlm::vec2 v1, mlm::vec2 v2, int op);
