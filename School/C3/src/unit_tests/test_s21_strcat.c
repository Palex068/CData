#include "unit_tests.h"

START_TEST(test_s21_strcat_1) {
  char str_1[50] = "Hello";
  char str_2[50] = " World";
  ck_assert_pstr_eq(s21_strcat(str_1, str_2), strcat(str_1, str_2));
}
END_TEST

START_TEST(test_s21_strcat_2) {
  char str_1[50] = "21312\0";
  char str_2[50] = "123";
  ck_assert_pstr_eq(s21_strcat(str_1, str_2), strcat(str_1, str_2));
}
END_TEST

START_TEST(test_s21_strcat_3) {
  char str_1[50] = "\0";
  char str_2[50] = "";
  ck_assert_pstr_eq(s21_strcat(str_1, str_2), strcat(str_1, str_2));
}
END_TEST

Suite *make_strcat_suite(void) {
  Suite *s = suite_create("strcat");
  TCase *tc_strings = tcase_create("strings");
  suite_add_tcase(s, tc_strings);
  tcase_add_test(tc_strings, test_s21_strcat_1);
  tcase_add_test(tc_strings, test_s21_strcat_2);
  tcase_add_test(tc_strings, test_s21_strcat_3);
  return s;
}
