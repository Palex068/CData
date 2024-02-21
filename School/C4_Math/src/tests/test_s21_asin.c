#include "s21_tests.h"

START_TEST(test_s21_asin) {
  ck_assert_ldouble_eq_tol(s21_asin(0.707107), asin(0.707107), 1e-6);
  ck_assert_ldouble_eq_tol(s21_asin(0.000000), asin(0.000000), 1e-6);
  ck_assert_ldouble_eq_tol(s21_asin(-0.500000), asin(-0.500000), 1e-6);
  ck_assert_ldouble_eq_tol(s21_asin(0.707107), asin(0.707107), 1e-6);
  ck_assert_ldouble_eq_tol(s21_asin(1), asin(1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_asin(-1), asin(-1), 1e-6);
}
END_TEST

Suite *asin_suite(void) {
  Suite *s = suite_create("asin");
  TCase *tc_asin = tcase_create("math");

  suite_add_tcase(s, tc_asin);
  tcase_add_test(tc_asin, test_s21_asin);
  return s;
}
