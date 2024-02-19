#include <check.h>
#include <math.h>
#include <stdlib.h>

#include "s21_math.h"

START_TEST(abs_tests) {
  ck_assert_float_eq(abs(-13), s21_abs(-13));
  ck_assert_float_eq(abs(13), s21_abs(13));
  ck_assert_float_eq(abs(-1000), s21_abs(-1000));
  ck_assert_float_eq(abs(32346234), s21_abs(32346234));
  ck_assert_float_eq(abs(0), s21_abs(0));
}
END_TEST

START_TEST(fabs_tests) {
  ck_assert_float_eq(fabs(-13.21313), s21_fabs(-13.21313));
  ck_assert_float_eq(fabs(13.21313), s21_fabs(13.21313));
  ck_assert_float_eq(fabs(-1000.21313), s21_fabs(-1000.21313));
  ck_assert_float_eq(fabs(32346234.21313), s21_fabs(32346234.21313));
  ck_assert_float_eq(fabs(0.0), s21_fabs(0.0));
}
END_TEST

START_TEST(fmod_tests) {
  ck_assert_float_eq(fmod(-13.21313, 2.5), s21_fmod(-13.21313, 2.5));
  ck_assert_float_eq(fmod(13.21313, 2.5), s21_fmod(13.21313, 2.5));
  ck_assert_float_eq(fmod(-1000.21313, 2.5), s21_fmod(-1000.21313, 2.5));
  ck_assert_float_eq(fmod(32346234.21313, 2.5), s21_fmod(32346234.21313, 2.5));
  ck_assert_float_eq(fmod(0, 2.5), s21_fmod(0, 2.5));
  ck_assert_float_eq(fmod(2.5, 2.5), s21_fmod(2.5, 2.5));
  ck_assert_int_eq(fmod(4324, 0), s21_fmod(4324, 0));
  ck_assert_float_eq(fmod(5342, S21_INF), s21_fmod(5342, S21_INF));
}
END_TEST

START_TEST(pow_tests) {
  ck_assert_int_eq(pow(-13.21313, 2.5), s21_pow(-13.21313, 2.5));
  ck_assert_float_eq(pow(13.21313, 2.5), s21_pow(13.21313, 2.5));
  ck_assert_int_eq(pow(-1000.21313, 2.5), s21_pow(-1000.21313, 2.5));
  ck_assert_float_eq(pow(32346234.21313, 2.5), s21_pow(32346234.21313, 2.5));
  ck_assert_float_eq(pow(0, 2.5), s21_pow(0, 2.5));
  ck_assert_float_eq(pow(123, -2), s21_pow(123, -2));
  ck_assert_float_eq(pow(4235.123, 0), s21_pow(4235.123, 0));
  ck_assert_float_eq(pow(0, -3.32), s21_pow(0, -3.32));
  ck_assert_float_eq(pow(-23.156, 3), s21_pow(-23.156, 3));
  ck_assert_float_eq(pow(0, S21_INF), s21_pow(0, S21_INF));
}
END_TEST

START_TEST(ceil_tests) {
  ck_assert_float_eq(ceil(-13.54), s21_ceil(-13.54));
  ck_assert_float_eq(ceil(13.54), s21_ceil(13.54));
  ck_assert_float_eq(ceil(1000), s21_ceil(1000));
  ck_assert_float_eq(ceil(102.0000002), s21_ceil(102.0000002));
}
END_TEST

START_TEST(floor_tests) {
  ck_assert_float_eq(floor(-13.54), s21_floor(-13.54));
  ck_assert_float_eq(floor(13.54), s21_floor(13.54));
  ck_assert_float_eq(floor(-0.54), s21_floor(-0.54));
  ck_assert_float_eq(floor(1000), s21_floor(1000));
  ck_assert_float_eq(floor(102.0000002), s21_floor(102.0000002));
  ck_assert_float_eq(floor(0), s21_floor(0));
}
END_TEST

START_TEST(exp_tests) {
  ck_assert_float_eq(exp(-13.54), s21_exp(-13.54));
  ck_assert_float_eq(exp(13.54), s21_exp(13.54));
  ck_assert_float_eq(exp(-0.54), s21_exp(-0.54));
  ck_assert_float_eq(exp(1000), s21_exp(1000));
  ck_assert_float_eq(exp(1), s21_exp(1));
  ck_assert_float_eq(exp(2), s21_exp(2));
  ck_assert_float_eq(exp(-1), s21_exp(-1));
  ck_assert_float_eq(exp(0), s21_exp(0));
  ck_assert_int_eq(exp(S21_NAN), s21_exp(S21_NAN));
  ck_assert_float_eq(exp(710), s21_exp(710));
  ck_assert_float_eq(exp(1.2345), s21_exp(1.2345));
  ck_assert_float_eq(exp(1.23454656768), s21_exp(1.23454656768));
  ck_assert_float_eq(exp(S21_INF), s21_exp(S21_INF));
}
END_TEST

START_TEST(sin_tests) {
  ck_assert_float_eq(sin(-13.54), s21_sin(-13.54));
  ck_assert_float_eq(sin(13.54), s21_sin(13.54));
  ck_assert_float_eq(sin(0.0), s21_sin(0.0));
  ck_assert_float_eq(sin(1.0), s21_sin(1.0));
  ck_assert_float_eq(sin(2.5), s21_sin(2.5));
  ck_assert_float_eq(sin(6.28), s21_sin(6.28));
  ck_assert_float_eq(sin(2.2343), s21_sin(2.2343));
  ck_assert_float_eq(sin(0.1234), s21_sin(0.1234));
  ck_assert_int_eq(sin(S21_INF), s21_sin(S21_INF));
  ck_assert_float_eq_tol(sin(-S21_PI), s21_sin(-S21_PI), 1e6);
  ck_assert_float_eq(sin(-S21_PI - 1), s21_sin(-S21_PI - 1));
}
END_TEST

START_TEST(cos_tests) {
  ck_assert_float_eq(cos(-13.54), s21_cos(-13.54));
  ck_assert_float_eq(cos(13.54), s21_cos(13.54));
  ck_assert_float_eq(cos(0.0), s21_cos(0.0));
  ck_assert_float_eq(cos(1.0), s21_cos(1.0));
  ck_assert_float_eq(cos(3.14), s21_cos(3.14));
  ck_assert_float_eq(cos(6.28), s21_cos(6.28));
  ck_assert_float_eq(cos(2.2343), s21_cos(2.2343));
  ck_assert_float_eq(cos(0.1234), s21_cos(0.1234));
  ck_assert_int_eq(cos(S21_INF), s21_cos(S21_INF));
  ck_assert_float_eq(cos(S21_PI), s21_cos(S21_PI));
}
END_TEST

START_TEST(tan_tests) {
  ck_assert_float_eq(tan(-13.54), s21_tan(-13.54));
  ck_assert_float_eq(tan(13.54), s21_tan(13.54));
  ck_assert_float_eq(tan(0), s21_tan(0));
  ck_assert_float_eq(tan(1), s21_tan(1));
  ck_assert_float_eq(tan(2.5), s21_tan(2.5));
  ck_assert_float_eq(tan(6.28), s21_tan(6.28));
  ck_assert_float_eq(tan(2.2343), s21_tan(2.2343));
  ck_assert_float_eq(tan(0.1234), s21_tan(0.1234));
}
END_TEST

START_TEST(sqrt_tests) {
  ck_assert_float_eq(sqrt(0.0), s21_sqrt(0.0));
  ck_assert_float_eq(sqrt(1.0), s21_sqrt(1.0));
  ck_assert_float_eq(sqrt(3.14), s21_sqrt(3.14));
  ck_assert_float_eq(sqrt(6.28), s21_sqrt(6.28));
  ck_assert_float_eq(sqrt(2.2343), s21_sqrt(2.2343));
  ck_assert_int_eq(sqrt(-123), s21_sqrt(-123));
  ck_assert_float_eq(sqrt(S21_INF), s21_sqrt(S21_INF));
}

START_TEST(log_tests) {
  ck_assert_int_eq(log(-13.54), s21_log(-13.54));
  ck_assert_float_eq(log(13.54), s21_log(13.54));
  ck_assert_float_eq(log(0.0), s21_log(0.0));
  ck_assert_float_eq(log(1.0), s21_log(1.0));
  ck_assert_float_eq(log(3.14), s21_log(3.14));
  ck_assert_float_eq(log(6.28), s21_log(6.28));
  ck_assert_float_eq(log(2.2343), s21_log(2.2343));
  ck_assert_float_eq(log(0.1234), s21_log(0.1234));
  ck_assert_int_eq(log(S21_INF), s21_log(S21_INF));
}
END_TEST

START_TEST(asin_tests) {
  ck_assert_int_eq(asin(-13.54), s21_asin(-13.54));
  ck_assert_int_eq(asin(13.54), s21_asin(13.54));
  ck_assert_int_eq(asin(6.28), s21_asin(6.28));
  ck_assert_float_eq(asin(S21_EPS), s21_asin(S21_EPS));
  ck_assert_float_eq_tol(asin(0.1234), s21_asin(0.1234), 1e6);
  ck_assert_float_eq(asin(0), s21_asin(0));
  ck_assert_float_eq_tol(asin(1), s21_asin(1), 1e6);
  ck_assert_float_eq_tol(asin(-1), s21_asin(-1), 1e6);
  ck_assert_float_eq(asin(0.5), s21_asin(0.5));
  ck_assert_float_eq(asin(-0.5), s21_asin(-0.5));
}
END_TEST

START_TEST(acos_tests) {
  ck_assert_int_eq(acos(-13.54), s21_acos(-13.54));
  ck_assert_int_eq(acos(13.54), s21_acos(13.54));
  ck_assert_int_eq(acos(2.2343), s21_acos(2.2343));
  ck_assert_float_eq(acos(0.1234), s21_acos(0.1234));
  ck_assert_float_eq(acos(0), s21_acos(0));
  ck_assert_float_eq(acos(1), s21_acos(1));
  ck_assert_float_eq_tol(acos(-1), s21_acos(-1), 1e6);
  ck_assert_float_eq(acos(0.5), s21_acos(0.5));
  ck_assert_float_eq(acos(-0.5), s21_acos(-0.5));
}
END_TEST

START_TEST(atan_tests) {
  ck_assert_float_eq(atan(-13.54), s21_atan(-13.54));
  ck_assert_float_eq(atan(13.54), s21_atan(13.54));
  ck_assert_float_eq(atan(3.14), s21_atan(3.14));
  ck_assert_float_eq(atan(6.28), s21_atan(6.28));
  ck_assert_float_eq_tol(atan(2.234), s21_atan(2.234), 1e6);
  ck_assert_float_eq(atan(0.1234), s21_atan(0.1234));
  ck_assert_float_eq(atan(0), s21_atan(0));
  ck_assert_float_eq_tol(atan(1), s21_atan(1), 1e6);
  ck_assert_float_eq_tol(atan(-1), s21_atan(-1), 1e6);
  ck_assert_float_eq(atan(3.5), s21_atan(3.5));
  ck_assert_float_eq(atan(-3.5), s21_atan(-3.5));
}
END_TEST

Suite *s21_math_tests_create() {
  Suite *s21_math = suite_create("s21_math");
  TCase *s21_math_tests = tcase_create("S21_MATH");
  tcase_add_test(s21_math_tests, ceil_tests);
  tcase_add_test(s21_math_tests, floor_tests);
  tcase_add_test(s21_math_tests, exp_tests);
  tcase_add_test(s21_math_tests, sin_tests);
  tcase_add_test(s21_math_tests, cos_tests);
  tcase_add_test(s21_math_tests, tan_tests);
  tcase_add_test(s21_math_tests, abs_tests);
  tcase_add_test(s21_math_tests, fabs_tests);
  tcase_add_test(s21_math_tests, fmod_tests);
  tcase_add_test(s21_math_tests, pow_tests);
  tcase_add_test(s21_math_tests, sqrt_tests);
  tcase_add_test(s21_math_tests, log_tests);
  tcase_add_test(s21_math_tests, asin_tests);
  tcase_add_test(s21_math_tests, acos_tests);
  tcase_add_test(s21_math_tests, atan_tests);
  suite_add_tcase(s21_math, s21_math_tests);
  return s21_math;
}

int main() {
  Suite *s21_math = s21_math_tests_create();
  SRunner *s21_math_runner = srunner_create(s21_math);
  float number_failed;
  srunner_run_all(s21_math_runner, CK_NORMAL);
  number_failed = srunner_ntests_failed(s21_math_runner);
  srunner_free(s21_math_runner);

  return number_failed == 0 ? 0 : 1;
}