#include "s21_tests.h"

START_TEST(test_s21_atan) {
  ck_assert_ldouble_eq_tol(s21_atan(1.000000), atan(1.000000), 1e-6);
  ck_assert_ldouble_eq_tol(s21_atan(0.866025), atan(0.866025), 1e-6);
  ck_assert_ldouble_eq_tol(s21_atan(-0.500000), atan(-0.500000), 1e-6);
  ck_assert_ldouble_eq_tol(s21_atan(0), atan(0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_atan(-1), atan(-1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_atan(-500000), atan(-500000), 1e-6);
  ck_assert_ldouble_eq_tol(s21_atan(500001), atan(500001), 1e-6);
  ck_assert_ldouble_eq_tol(s21_atan(S21_PI), atan(S21_PI), 1e-6);
  ck_assert_ldouble_eq_tol(s21_atan(S21_PI / 2), atan(S21_PI / 2), 1e-6);
}
END_TEST

Suite *atan_suite(void) {
  Suite *s = suite_create("atan");
  TCase *tc_atan = tcase_create("math");

  suite_add_tcase(s, tc_atan);
  tcase_add_test(tc_atan, test_s21_atan);
  return s;
}
