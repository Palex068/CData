#include "s21_tests.h"

START_TEST(test_s21_sqrt) {
  ck_assert_ldouble_eq_tol(s21_sqrt(1), sqrt(1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sqrt(123456789), sqrt(123456789), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sqrt(0.123456), sqrt(0.123456), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sqrt(0), sqrt(0), 1e-6);
  ck_assert_ldouble_nan(s21_sqrt(-1.234567));
  ck_assert_ldouble_infinite(s21_sqrt(S21_INF_POS));
}
END_TEST

Suite *sqrt_suite(void) {
  Suite *s = suite_create("sqrt");
  TCase *tc_sqrt = tcase_create("math");

  suite_add_tcase(s, tc_sqrt);
  tcase_add_test(tc_sqrt, test_s21_sqrt);
  return s;
}
