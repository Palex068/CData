#include "unit_tests.h"

START_TEST(test_s21_strlen_1) {
  char str_1[50] = "Hello";
  ck_assert_int_eq(s21_strlen(str_1), strlen(str_1));
}
END_TEST

START_TEST(test_s21_strlen_2) {
  char str_1[50] = "\0dlks;ldk;ldskf";
  ck_assert_int_eq(s21_strlen(str_1), strlen(str_1));
}
END_TEST

START_TEST(test_s21_strlen_3) {
  char str_1[50] = "";
  ck_assert_int_eq(s21_strlen(str_1), strlen(str_1));
}
END_TEST

Suite *make_strlen_suite(void) {
  Suite *s = suite_create("strlen");
  TCase *tc_strings = tcase_create("strings");
  suite_add_tcase(s, tc_strings);
  tcase_add_test(tc_strings, test_s21_strlen_1);
  tcase_add_test(tc_strings, test_s21_strlen_2);
  tcase_add_test(tc_strings, test_s21_strlen_3);
  return s;
}
