#ifndef TEST_MAIN_H_SENTRY
#define TEST_MAIN_H_SENTRY

#include <check.h>
#include <math.h>

#include "../s21_decimal.h"

void runtest(Suite *make_suite, int *result);

Suite *s21_print_suite();
Suite *s21_arithmetic_add_suite();
Suite *s21_arithmetic_sub_suite();
Suite *s21_arithmetic_mul_suite();
Suite *s21_arithmetic_div_suite();
Suite *s21_convertations_int_to_decimal();

#endif