#include "unit_tests.h"

START_TEST(test_s21_strstr_1) {
  char str_1[50] = "0123456789";
  char str_2[50] = "345";
  ck_assert_str_eq(s21_strstr(str_1, str_2), strstr(str_1, str_2));
}
END_TEST

START_TEST(test_s21_strstr_2) {
  char str_1[50] = "0123450189";
  char str_2[50] = "01";
  ck_assert_str_eq(s21_strstr(str_1, str_2), strstr(str_1, str_2));
}
END_TEST

START_TEST(test_s21_strstr_3) {
  char str_1[50] = "0123456789";
  char str_2[50] = " ";
  ck_assert_ptr_null(s21_strstr(str_1, str_2));
  ck_assert_ptr_null(strstr(str_1, str_2));
}
END_TEST

Suite *make_strstr_suite(void) {
  Suite *s = suite_create("strstr");
  TCase *tc_strings = tcase_create("strings");
  suite_add_tcase(s, tc_strings);
  tcase_add_test(tc_strings, test_s21_strstr_1);
  tcase_add_test(tc_strings, test_s21_strstr_2);
  tcase_add_test(tc_strings, test_s21_strstr_3);
  return s;
}
