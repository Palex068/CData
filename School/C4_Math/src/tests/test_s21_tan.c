#include "s21_tests.h"

START_TEST(test_s21_tan) {
  ck_assert_ldouble_eq_tol(s21_tan(0), tan(0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_tan(2 * S21_PI / 3), tan(2 * S21_PI / 3), 1e-6);
  ck_assert_ldouble_eq_tol(s21_tan(S21_PI / 3), tan(S21_PI / 3), 1e-6);
  ck_assert_ldouble_eq_tol(s21_tan(0), tan(0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_tan(S21_PI), tan(S21_PI), 1e-6);
  ck_assert_ldouble_eq_tol(s21_tan(S21_PI / 2), tan(S21_PI / 2), 1e-6);
  ck_assert_ldouble_eq_tol(s21_tan(126.8647465), tan(126.8647465), 1e-6);
  ck_assert_ldouble_eq_tol(s21_tan(-235.3456458), tan(-235.3456458), 1e-6);
}
END_TEST

Suite *tan_suite(void) {
  Suite *s = suite_create("tan");
  TCase *tc_tan = tcase_create("math");

  suite_add_tcase(s, tc_tan);
  tcase_add_test(tc_tan, test_s21_tan);
  return s;
}
