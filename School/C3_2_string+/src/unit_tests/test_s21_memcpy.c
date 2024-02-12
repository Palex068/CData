#include "unit_tests.h"

START_TEST(test_s21_memcpy_1) {
  char str_1[50] = "";
  char str_2[50] = "Hello";
  s21_size_t n = 5;
  ck_assert_pstr_eq(s21_memcpy(str_1, str_2, n), memcpy(str_1, str_2, n));
}
END_TEST

START_TEST(test_s21_memcpy_2) {
  char str_1[50] = "abcdefghij0123456789";
  char str_2[50] = "*****";
  s21_size_t n = 5;
  ck_assert_pstr_eq(s21_memcpy(str_1, str_2, n), memcpy(str_1, str_2, n));
}
END_TEST

START_TEST(test_s21_memcpy_3) {
  char str_1[50] = "Hello";
  char str_2[50] = "";
  s21_size_t n = 1;
  ck_assert_pstr_eq(s21_memcpy(str_1, str_2, n), memcpy(str_1, str_2, n));
}
END_TEST

Suite *make_memcpy_suite(void) {
  Suite *s = suite_create("memcpy");
  TCase *tc_strings = tcase_create("strings");
  suite_add_tcase(s, tc_strings);
  tcase_add_test(tc_strings, test_s21_memcpy_1);
  tcase_add_test(tc_strings, test_s21_memcpy_2);
  tcase_add_test(tc_strings, test_s21_memcpy_3);
  return s;
}
