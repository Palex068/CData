#include "unit_tests.h"

START_TEST(test_s21_strcspn_1) {
  char str_1[50] = "0123456789";
  char str_2[50] = "9876";
  ck_assert_uint_eq(s21_strcspn(str_1, str_2), strcspn(str_1, str_2));
}
END_TEST

START_TEST(test_s21_strcspn_2) {
  char str_1[50] = "xyzbxz";
  char str_2[50] = "abc";
  ck_assert_uint_eq(s21_strcspn(str_1, str_2), strcspn(str_1, str_2));
}
END_TEST

START_TEST(test_s21_strcspn_3) {
  char str_1[50] = "";
  char str_2[50] = "";
  ck_assert_uint_eq(s21_strcspn(str_1, str_2), strcspn(str_1, str_2));
}
END_TEST

START_TEST(test_s21_strcspn_4) {
  char str_1[50] = "";
  char str_2[50] = "abc";
  ck_assert_uint_eq(s21_strcspn(str_1, str_2), strcspn(str_1, str_2));
}
END_TEST

Suite *make_strcspn_suite(void) {
  Suite *s = suite_create("strcspn");
  TCase *tc_strings = tcase_create("strings");
  suite_add_tcase(s, tc_strings);
  tcase_add_test(tc_strings, test_s21_strcspn_1);
  tcase_add_test(tc_strings, test_s21_strcspn_2);
  tcase_add_test(tc_strings, test_s21_strcspn_3);
  tcase_add_test(tc_strings, test_s21_strcspn_4);
  return s;
}
