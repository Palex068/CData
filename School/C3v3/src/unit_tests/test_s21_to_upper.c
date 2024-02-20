#include "unit_tests.h"

START_TEST(test_s21_to_upper_1) {
  char *str_1 = "abc";
  char *str_2 = s21_to_upper(str_1);
  ck_assert_str_eq(str_2, "ABC");
  if (str_2) free(str_2);
}
END_TEST

START_TEST(test_s21_to_upper_2) {
  char *str_1 = "29ea6ad";
  char *str_2 = s21_to_upper(str_1);
  ck_assert_str_eq(str_2, "29EA6AD");
  if (str_2) free(str_2);
}
END_TEST

START_TEST(test_s21_to_upper_3) {
  char *str_1 = "AbC";
  char *str_2 = s21_to_upper(str_1);
  ck_assert_str_eq(str_2, "ABC");
  if (str_2) free(str_2);
}
END_TEST

START_TEST(test_s21_to_upper_4) {
  char *str_1 = "MNBQW!{Empo";
  char *str_2 = s21_to_upper(str_1);
  ck_assert_str_eq(str_2, "MNBQW!{EMPO");
  if (str_2) free(str_2);
}
END_TEST

START_TEST(test_s21_to_upper_5) {
  char *str_1 = "";
  char *str_2 = s21_to_upper(str_1);
  ck_assert_ptr_null(str_2);
  if (str_2) free(str_2);
}
END_TEST

START_TEST(test_s21_to_upper_6) {
  char s1[30] = "Hello, world!";
  char *s2 = s21_to_upper(s1);
  char s3[] = "HELLO, WORLD!";
  ck_assert_pstr_eq(s3, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_s21_to_upper_7) {
  char s1[30] = "\nh\t\\g123123";
  char *s2 = s21_to_upper(s1);
  char s3[] = "\nH\t\\G123123";
  ck_assert_pstr_eq(s3, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_s21_to_upper_8) {
  char s1[30] = "ALREADY UPPER";
  char *s2 = s21_to_upper(s1);
  char s3[] = "ALREADY UPPER";
  ck_assert_pstr_eq(s3, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_s21_to_upper_9) {
  char s1[30] = "abcdefghijklmnopqrstuvwxyz";
  char *s2 = s21_to_upper(s1);
  char s3[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  ck_assert_pstr_eq(s3, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_s21_to_upper_10) {
  char s1[30] = "_?};!234";
  char *s2 = s21_to_upper(s1);
  char s3[] = "_?};!234";
  ck_assert_pstr_eq(s3, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_s21_to_upper_11) {
  char *s1 = s21_NULL;
  char *s2 = s21_to_upper(s1);
  char *s3 = s21_NULL;
  ck_assert_pstr_eq(s3, s2);
  if (s2) free(s2);
}
END_TEST

Suite *make_to_upper_suite(void) {
  Suite *s = suite_create("to_upper");
  TCase *tc_strings = tcase_create("strings");
  suite_add_tcase(s, tc_strings);
  tcase_add_test(tc_strings, test_s21_to_upper_1);
  tcase_add_test(tc_strings, test_s21_to_upper_2);
  tcase_add_test(tc_strings, test_s21_to_upper_3);
  tcase_add_test(tc_strings, test_s21_to_upper_4);
  tcase_add_test(tc_strings, test_s21_to_upper_5);
  tcase_add_test(tc_strings, test_s21_to_upper_6);
  tcase_add_test(tc_strings, test_s21_to_upper_7);
  tcase_add_test(tc_strings, test_s21_to_upper_8);
  tcase_add_test(tc_strings, test_s21_to_upper_9);
  tcase_add_test(tc_strings, test_s21_to_upper_10);
  tcase_add_test(tc_strings, test_s21_to_upper_11);
  return s;
}