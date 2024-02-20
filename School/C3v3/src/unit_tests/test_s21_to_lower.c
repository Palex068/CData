#include "unit_tests.h"

START_TEST(test_s21_to_lower_1) {
  char *str_1 = "ABC";
  char *str_2 = s21_to_lower(str_1);
  ck_assert_str_eq(str_2, "abc");
  if (str_2) free(str_2);
}
END_TEST

START_TEST(test_s21_to_lower_2) {
  char *str_1 = "AbC";
  char *str_2 = s21_to_lower(str_1);
  ck_assert_str_eq(str_2, "abc");
  if (str_2) free(str_2);
}
END_TEST

START_TEST(test_s21_to_lower_3) {
  char *str_1 = "aBc";
  char *str_2 = s21_to_lower(str_1);
  ck_assert_str_eq(str_2, "abc");
  if (str_2) free(str_2);
}
END_TEST

START_TEST(test_s21_to_lower_4) {
  char *str_1 = "";
  char *str_2 = s21_to_lower(str_1);
  ck_assert_ptr_null(str_2);
  if (str_2) free(str_2);
}
END_TEST

START_TEST(test_s21_to_lower_5) {
  char s1[30] = "hello, world!";
  char s3[] = "hELLO, WORLD!";
  char *s2 = s21_to_lower(s3);
  ck_assert_pstr_eq(s1, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_s21_to_lower_6) {
  char s1[30] = "\nh\t\\g123123";
  char s3[] = "\nH\t\\G123123";
  char *s2 = s21_to_lower(s3);
  ck_assert_pstr_eq(s1, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_s21_to_lower_7) {
  char s1[30] = "already lower";
  char s3[] = "already lower";
  char *s2 = s21_to_lower(s3);
  ck_assert_pstr_eq(s1, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_s21_to_lower_8) {
  char s1[30] = "abcdefghijklmnopqrstuvwxyz";
  char s3[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  char *s2 = s21_to_lower(s3);
  ck_assert_pstr_eq(s1, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_s21_to_lower_9) {
  char s1[30] = "_?};!234";
  char s3[] = "_?};!234";
  char *s2 = s21_to_lower(s3);
  ck_assert_pstr_eq(s1, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_s21_to_lower_10) {
  char *s1 = s21_NULL;
  char *s3 = s21_NULL;
  char *s2 = s21_to_lower(s3);
  ck_assert_pstr_eq(s1, s2);
  if (s2) free(s2);
}
END_TEST

Suite *make_to_lower_suite(void) {
  Suite *s = suite_create("to_lower");
  TCase *tc_strings = tcase_create("strings1");
  suite_add_tcase(s, tc_strings);
  tcase_add_test(tc_strings, test_s21_to_lower_1);
  tcase_add_test(tc_strings, test_s21_to_lower_2);
  tcase_add_test(tc_strings, test_s21_to_lower_3);
  tcase_add_test(tc_strings, test_s21_to_lower_4);
  tcase_add_test(tc_strings, test_s21_to_lower_5);
  tcase_add_test(tc_strings, test_s21_to_lower_6);
  tcase_add_test(tc_strings, test_s21_to_lower_7);
  tcase_add_test(tc_strings, test_s21_to_lower_8);
  tcase_add_test(tc_strings, test_s21_to_lower_9);
  tcase_add_test(tc_strings, test_s21_to_lower_10);
  return s;
}
