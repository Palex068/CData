#include "unit_tests.h"

START_TEST(test_s21_memmove_1) {
  char str_1[50] = "1234567890";
  char str_2[50] = "456";
  s21_size_t n = 3;
  ck_assert_pstr_eq(s21_memmove(str_1, str_2, n), memmove(str_1, str_2, n));
}
END_TEST

START_TEST(test_s21_memmove_2) {
  char str_1[50] = "1234567890";
  char str_2[50] = "";
  s21_size_t n = 1;
  ck_assert_pstr_eq(s21_memmove(str_1, str_2, n), memmove(str_1, str_2, n));
}
END_TEST

START_TEST(test_s21_memmove_3) {
  char str_1[50] = "";
  char str_2[50] = "1234567890";
  s21_size_t n = 0;
  ck_assert_pstr_eq(s21_memmove(str_1, str_2, n), memmove(str_1, str_2, n));
}
END_TEST

Suite *make_memmove_suite(void) {
  Suite *s = suite_create("memmove");
  TCase *tc_strings = tcase_create("strings");
  suite_add_tcase(s, tc_strings);
  tcase_add_test(tc_strings, test_s21_memmove_1);
  tcase_add_test(tc_strings, test_s21_memmove_2);
  tcase_add_test(tc_strings, test_s21_memmove_3);
  return s;
}
