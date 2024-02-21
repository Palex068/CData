#include "unit_tests.h"

START_TEST(test_s21_strspn_1) {
  char str_1[50] = "0123456789";
  char str_2[50] = "210";
  ck_assert_uint_eq(s21_strspn(str_1, str_2), strspn(str_1, str_2));
}
END_TEST

START_TEST(test_s21_strspn_2) {
  char str_1[50] = "cabbage";
  char str_2[50] = "abc";
  ck_assert_uint_eq(s21_strspn(str_1, str_2), strspn(str_1, str_2));
}
END_TEST

START_TEST(test_s21_strspn_3) {
  char str_1[50] = "";
  char str_2[50] = "abc";
  ck_assert_uint_eq(s21_strspn(str_1, str_2), strspn(str_1, str_2));
}
END_TEST

START_TEST(test_s21_strspn_4) {
  char str_1[50] = "testivan";
  char str_2[50] = "ivan";
  ck_assert_uint_eq(s21_strspn(str_1, str_2), strspn(str_1, str_2));
}
END_TEST

Suite *make_strspn_suite(void) {
  Suite *s = suite_create("strspn");
  TCase *tc_strings = tcase_create("strings");
  suite_add_tcase(s, tc_strings);
  tcase_add_test(tc_strings, test_s21_strspn_1);
  tcase_add_test(tc_strings, test_s21_strspn_2);
  tcase_add_test(tc_strings, test_s21_strspn_3);
  tcase_add_test(tc_strings, test_s21_strspn_4);
  return s;
}
