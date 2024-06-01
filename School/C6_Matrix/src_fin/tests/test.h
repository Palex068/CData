#ifndef TEST_H_SENTRY
#define TEST_H_SENTRY

#include <check.h>
#include <math.h>

#include "../s21_matrix.h"
#include "../s21_other.h"

void runtest(Suite *make_suite, int *result);

Suite *s21_tests_create_matrix();
Suite *s21_tests_eq_matrix();
Suite *s21_tests_sum_matrix();
Suite *s21_tests_sub_matrix();
Suite *s21_tests_mult_number();
Suite *s21_tests_mult_matrix();
Suite *s21_tests_transpose();
Suite *s21_tests_calc_complements();
Suite *s21_tests_determinant();
Suite *s21_tests_inverse_matrix();

#endif