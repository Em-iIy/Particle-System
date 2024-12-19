#pragma once

#include "../emlm.hpp"

// Arithmatic operator tests
void	vec4_test_op_v4_f(mlm::vec4 v, float s, int op);
void	vec4_test_op_f_v4(float s, mlm::vec4 v, int op);
void	vec4_test_op_v4_v1(mlm::vec4 v, mlm::vec1 s, int op);
void	vec4_test_op_v1_v4(mlm::vec1 s, mlm::vec4 v, int op);
void	vec4_test_op_v4_v4(mlm::vec4 v1, mlm::vec4 v2, int op);

// Arithmatic assignment operator tests
void	vec4_test_op_assignment_v4_f(mlm::vec4 v, float s, int op);
void	vec4_test_op_assignment_v4_v1(mlm::vec4 v, mlm::vec1 s, int op);
void	vec4_test_op_assignment_v4_v4(mlm::vec4 v1, mlm::vec4 v2, int op);
