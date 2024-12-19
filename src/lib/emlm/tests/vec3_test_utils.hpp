#pragma once

#include "../emlm.hpp"

// Arithmatic operator tests
void	vec3_test_op_v3_f(mlm::vec3 v, float s, int op);
void	vec3_test_op_f_v3(float s, mlm::vec3 v, int op);
void	vec3_test_op_v3_v1(mlm::vec3 v, mlm::vec1 s, int op);
void	vec3_test_op_v1_v3(mlm::vec1 s, mlm::vec3 v, int op);
void	vec3_test_op_v3_v3(mlm::vec3 v1, mlm::vec3 v2, int op);

// Arithmatic assignment operator tests
void	vec3_test_op_assignment_v3_f(mlm::vec3 v, float s, int op);
void	vec3_test_op_assignment_v3_v1(mlm::vec3 v, mlm::vec1 s, int op);
void	vec3_test_op_assignment_v3_v3(mlm::vec3 v1, mlm::vec3 v2, int op);
