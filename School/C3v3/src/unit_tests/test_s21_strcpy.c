#include "unit_tests.h"

START_TEST(test_s21_strcpy_1) {
  char str_1[50] = "";
  char str_2[50] = "строка\0 вторая строка";
  ck_assert_str_eq(s21_strcpy(str_1, str_2), strcpy(str_1, str_2));
}
END_TEST

START_TEST(test_s21_strcpy_2) {
  char str_1[50] = "123";
  char str_2[50] = "345\0";
  ck_assert_str_eq(s21_strcpy(str_1, str_2), strcpy(str_1, str_2));
}
END_TEST

START_TEST(test_s21_strcpy_3) {
  char str_1[50] = "";
  char str_2[50] = "\0";
  ck_assert_str_eq(s21_strcpy(str_1, str_2), strcpy(str_1, str_2));
}
END_TEST

Suite *make_strcpy_suite(void) {
  Suite *s = suite_create("strcpy");
  TCase *tc_strings = tcase_create("strings");
  suite_add_tcase(s, tc_strings);
  tcase_add_test(tc_strings, test_s21_strcpy_1);
  tcase_add_test(tc_strings, test_s21_strcpy_2);
  tcase_add_test(tc_strings, test_s21_strcpy_3);
  return s;
}
