#include "unit_tests.h"

START_TEST(test_s21_strcmp_1) {
  char str_1[50] = "";
  char str_2[50] = "123445";
  ck_assert_int_eq(s21_strcmp(str_1, str_2), strcmp(str_1, str_2));
}
END_TEST

START_TEST(test_s21_strcmp_2) {
  char str_1[50] = "12345";
  char str_2[50] = "123456asd";
  ck_assert_int_eq(s21_strcmp(str_1, str_2), strcmp(str_1, str_2));
}
END_TEST

START_TEST(test_s21_strcmp_3) {
  char str_1[50] = "   ";
  char str_2[50] = " ";
  ck_assert_int_eq(s21_strcmp(str_1, str_2), strcmp(str_1, str_2));
}
END_TEST

START_TEST(test_s21_strcmp_4) {
  char str_1[50] = "asdasdasdasd";
  char str_2[50] = "!__!";
  ck_assert_int_eq(s21_strcmp(str_1, str_2), strcmp(str_1, str_2));
}
END_TEST

START_TEST(test_s21_strcmp_5) {
  char str_1[50] = "";
  char str_2[50] = "";
  ck_assert_int_eq(s21_strcmp(str_1, str_2), strcmp(str_1, str_2));
}
END_TEST

Suite *make_strcmp_suite(void) {
  Suite *s = suite_create("strcmp");
  TCase *tc_strings = tcase_create("strings");
  suite_add_tcase(s, tc_strings);
  tcase_add_test(tc_strings, test_s21_strcmp_1);
  tcase_add_test(tc_strings, test_s21_strcmp_2);
  tcase_add_test(tc_strings, test_s21_strcmp_3);
  tcase_add_test(tc_strings, test_s21_strcmp_4);
  tcase_add_test(tc_strings, test_s21_strcmp_5);
  return s;
}
