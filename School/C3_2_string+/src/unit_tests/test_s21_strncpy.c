#include "unit_tests.h"

START_TEST(test_s21_strncpy_1) {
  char str_1[10] = "";
  char str_2[50] = "String";
  s21_size_t n = 3;
  ck_assert_str_eq(s21_strncpy(str_1, str_2, n), strncpy(str_1, str_2, n));
}
END_TEST

START_TEST(test_s21_strncpy_2) {
  char str_1[10] = "";
  char str_2[50] = "";
  s21_size_t n = 1;
  ck_assert_str_eq(s21_strncpy(str_1, str_2, n), strncpy(str_1, str_2, n));
}
END_TEST

START_TEST(test_s21_strncpy_3) {
  char str_1[50] = "Hello";
  char str_2[50] = "";
  s21_size_t n = 1;
  ck_assert_str_eq(s21_strncpy(str_1, str_2, n), strncpy(str_1, str_2, n));
}
END_TEST

Suite *make_strncpy_suite(void) {
  Suite *s = suite_create("strncpy");
  TCase *tc_strings = tcase_create("strings");
  suite_add_tcase(s, tc_strings);
  tcase_add_test(tc_strings, test_s21_strncpy_1);
  tcase_add_test(tc_strings, test_s21_strncpy_2);
  tcase_add_test(tc_strings, test_s21_strncpy_3);
  return s;
}
