#include "unit_tests.h"

START_TEST(test_s21_strncmp_1) {
  char str_1[50] = "1234567890";
  char str_2[50] = "1234507890";
  s21_size_t n = 5;
  ck_assert_int_eq(s21_strncmp(str_1, str_2, n), strncmp(str_1, str_2, n));
}
END_TEST

START_TEST(test_s21_strncmp_2) {
  char str_1[50] = "1234567890";
  char str_2[50] = "1234507890";
  s21_size_t n = 7;
  ck_assert_int_eq(s21_strncmp(str_1, str_2, n), strncmp(str_1, str_2, n));
}
END_TEST

START_TEST(test_s21_strncmp_3) {
  char str_1[50] = "1234567890";
  char str_2[50] = "12345";
  s21_size_t n = 6;
  ck_assert_int_eq(s21_strncmp(str_1, str_2, n), strncmp(str_1, str_2, n));
}
END_TEST

Suite *make_strncmp_suite(void) {
  Suite *s = suite_create("strncmp");
  TCase *tc_strings = tcase_create("strings");
  suite_add_tcase(s, tc_strings);
  tcase_add_test(tc_strings, test_s21_strncmp_1);
  tcase_add_test(tc_strings, test_s21_strncmp_2);
  tcase_add_test(tc_strings, test_s21_strncmp_3);
  return s;
}
