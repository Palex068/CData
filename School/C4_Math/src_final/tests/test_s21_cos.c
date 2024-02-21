#include "s21_tests.h"

START_TEST(test_s21_cos) {
  ck_assert_ldouble_eq_tol(s21_cos(2), cos(2), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(0.123456), cos(0.123456), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(-0.123456), cos(-0.123456), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(0x123), cos(0x123), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(-0x123), cos(-0x123), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(0), cos(0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(126.8647465), cos(126.8647465), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(-235.3456458), cos(-235.3456458), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(75846.8647465), cos(75846.8647465), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(-92553.3456458), cos(-92553.3456458), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(S21_PI), cos(S21_PI), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(S21_PI / 2.0), cos(S21_PI / 2.0), 1e-6);
}
END_TEST

Suite *cos_suite(void) {
  Suite *s = suite_create("cos");
  TCase *tc_cos = tcase_create("math");

  suite_add_tcase(s, tc_cos);
  tcase_add_test(tc_cos, test_s21_cos);
  return s;
}
