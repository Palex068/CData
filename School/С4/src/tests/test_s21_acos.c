#include "s21_tests.h"

START_TEST(test_s21_acos) {
  ck_assert_ldouble_eq_tol(s21_acos(1.000000), acos(1.000000), 1e-6);
  ck_assert_ldouble_eq_tol(s21_acos(0.707107), acos(0.707107), 1e-6);
  ck_assert_ldouble_eq_tol(s21_acos(1), acos(1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_acos(-1), acos(-1), 1e-6);
  ck_assert_ldouble_nan(s21_acos(10000));
  ck_assert_ldouble_nan(s21_acos(-1.0011));
}
END_TEST

Suite *acos_suite(void) {
  Suite *s = suite_create("acos");
  TCase *tc_acos = tcase_create("math");

  suite_add_tcase(s, tc_acos);
  tcase_add_test(tc_acos, test_s21_acos);
  return s;
}
