#include "unit_tests.h"

START_TEST(test_s21_strncat_1) {
  char str_1[50] = "000";
  char str_2[50] = "12345";
  s21_size_t n = 3;
  ck_assert_str_eq(s21_strncat(str_1, str_2, n), strncat(str_1, str_2, n));
}
END_TEST

START_TEST(test_s21_strncat_2) {
  char str_1[50] = "000";
  char str_2[50] = "12345";
  s21_size_t n = 7;
  ck_assert_str_eq(s21_strncat(str_1, str_2, n), strncat(str_1, str_2, n));
}
END_TEST

START_TEST(test_s21_strncat_3) {
  char str_1[50] = "12345";
  char str_2[50] = "";
  s21_size_t n = 1;
  ck_assert_str_eq(s21_strncat(str_1, str_2, n), strncat(str_1, str_2, n));
}
END_TEST

Suite *make_strncat_suite(void) {
  Suite *s = suite_create("strncat");
  TCase *tc_strings = tcase_create("strings");
  suite_add_tcase(s, tc_strings);
  tcase_add_test(tc_strings, test_s21_strncat_1);
  tcase_add_test(tc_strings, test_s21_strncat_2);
  tcase_add_test(tc_strings, test_s21_strncat_3);
  return s;
}
