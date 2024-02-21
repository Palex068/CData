#include "s21_tests.h"

START_TEST(test_s21_log) {
  ck_assert_ldouble_eq_tol(s21_log(1), log(1), 1e-6);
  ck_assert_ldouble_nan(s21_log(-1));
  ck_assert_ldouble_eq_tol(s21_log(123456), log(123456), 1e-6);
  ck_assert_ldouble_eq_tol(s21_log(987565.9874641213656),
                           log(987565.9874641213656), 1e-6);
  ck_assert_ldouble_eq_tol(s21_log(799415.5649), log(799415.5649), 1e-6);
  ck_assert_ldouble_eq_tol(s21_log(0.9876), log(0.9876), 1e-6);
  ck_assert_ldouble_infinite(s21_log(S21_INF_NEG));
  ck_assert_ldouble_infinite(s21_log(S21_INF_POS));
  ck_assert_ldouble_infinite(-s21_log(0));
}
END_TEST

Suite *log_suite(void) {
  Suite *s = suite_create("log");
  TCase *tc_log = tcase_create("math");

  suite_add_tcase(s, tc_log);
  tcase_add_test(tc_log, test_s21_log);
  return s;
}
