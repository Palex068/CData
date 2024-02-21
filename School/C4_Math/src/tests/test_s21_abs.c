#include "s21_tests.h"

START_TEST(test_s21_abs) {
  ck_assert_int_eq(s21_abs(-1), abs(-1));
  ck_assert_int_eq(s21_abs(5), abs(5));
  ck_assert_int_eq(s21_abs(-2147483647), abs(-2147483647));
  ck_assert_int_eq(s21_abs(-0xA13), abs(-0xA13));
  ck_assert_int_eq(s21_abs(13), abs(13));
  ck_assert_int_eq(s21_abs(-0), abs(-0));
  ck_assert_int_eq(s21_abs(-05), abs(-05));
  ck_assert_int_eq(s21_abs(-00002345670), abs(-00002345670));
  ck_assert_int_eq(s21_abs(123456789), abs(123456789));
  ck_assert_int_eq(s21_abs(100), abs(100));
  ck_assert_int_eq(s21_abs(-100), abs(-100));
  ck_assert_int_eq(s21_abs(0), abs(0));
}
END_TEST

Suite *abs_suite(void) {
  Suite *s = suite_create("abs");
  TCase *tc_abs = tcase_create("math");
  suite_add_tcase(s, tc_abs);
  tcase_add_test(tc_abs, test_s21_abs);
  return s;
}