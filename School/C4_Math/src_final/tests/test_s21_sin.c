#include "s21_tests.h"

START_TEST(test_s21_sin) {
  ck_assert_ldouble_eq_tol(s21_sin(2), sin(2), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(0.123456), sin(0.123456), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(-0.123456), sin(-0.123456), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(0x123), sin(0x123), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(-0x123), sin(-0x123), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(0), sin(0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(126.8647465), sin(126.8647465), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(-235.3456458), sin(-235.3456458), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(75846.8647465), sin(75846.8647465), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(-92553.3456458), sin(-92553.3456458), 1e-6);
}
END_TEST

Suite *sin_suite(void) {
  Suite *s = suite_create("sin");
  TCase *tc_sin = tcase_create("math");

  suite_add_tcase(s, tc_sin);
  tcase_add_test(tc_sin, test_s21_sin);
  return s;
}
