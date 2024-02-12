#include "unit_tests.h"

START_TEST(test_s21_strchr_1) {
  char str_1[50] = "this is a test\0";
  char str_2 = ' ';
  ck_assert_str_eq(s21_strchr(str_1, str_2), strchr(str_1, str_2));
}
END_TEST

START_TEST(test_s21_strchr_2) {
  char str_1[50] = "21312\0";
  char str_2 = '5';
  ck_assert_ptr_null(s21_strchr(str_1, str_2));
  ck_assert_ptr_null(strchr(str_1, str_2));
}
END_TEST

START_TEST(test_s21_strchr_3) {
  char str_1[50] = "123\0 4";
  char str_2 = '3';
  ck_assert_str_eq(s21_strchr(str_1, str_2), strchr(str_1, str_2));
}
END_TEST

Suite *make_strchr_suite(void) {
  Suite *s = suite_create("strchr");
  TCase *tc_strings = tcase_create("strings");
  suite_add_tcase(s, tc_strings);
  tcase_add_test(tc_strings, test_s21_strchr_1);
  tcase_add_test(tc_strings, test_s21_strchr_2);
  tcase_add_test(tc_strings, test_s21_strchr_3);
  return s;
}
