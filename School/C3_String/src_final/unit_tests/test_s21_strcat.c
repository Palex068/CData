#include "unit_tests.h"

START_TEST(test_s21_strcat_1) {
  char str_1[50] = "Hello";
  char str_2[50] = " World";
  ck_assert_pstr_eq(s21_strcat(str_1, str_2), strcat(str_1, str_2));
}
END_TEST

START_TEST(test_s21_strcat_2) {
  char str_1[50] = "21312\0";
  char str_2[50] = "123";
  ck_assert_pstr_eq(s21_strcat(str_1, str_2), strcat(str_1, str_2));
}
END_TEST

START_TEST(test_s21_strcat_3) {
  char str_1[50] = "\0";
  char str_2[50] = "";
  ck_assert_pstr_eq(s21_strcat(str_1, str_2), strcat(str_1, str_2));
}
END_TEST

START_TEST(test_s21_strcat_4) {
  char s1[30] = "Hello, world!";
  char s2[30] = "Hello, world!";
  char s3[] = "";
  ck_assert_pstr_eq(strcat(s1, s3), s21_strcat(s2, s3));
}
END_TEST

START_TEST(test_s21_strcat_5) {
  char s1[30] = "";
  char s2[30] = "";
  char s3[] = "Hello, world!";
  ck_assert_pstr_eq(strcat(s1, s3), s21_strcat(s2, s3));
}
END_TEST

START_TEST(test_s21_strcat_6) {
  char s1[100] = "Hello, world!";
  char s2[100] = "Hello, world!";
  char s3[] =
      "My name is Polina. I hate this, maybe I'm not supposed for this.";
  ck_assert_pstr_eq(strcat(s1, s3), s21_strcat(s2, s3));
}
END_TEST

START_TEST(test_s21_strcat_7) {
  char s1[100] = "Hello\0world!";
  char s2[100] = "Hello\0world!";
  char s3[] =
      "My name is Polina. I hate this, maybe I'm not supposed for this.";
  ck_assert_pstr_eq(strcat(s1, s3), s21_strcat(s2, s3));
}
END_TEST

START_TEST(test_s21_strcat_8) {
  char s1[100] = "\0";
  char s2[100] = "\0";
  char s3[] =
      "My name is Polina. I hate this\0, maybe I'm not supposed for this.";
  ck_assert_pstr_eq(strcat(s1, s3), s21_strcat(s2, s3));
}
END_TEST

START_TEST(test_s21_strcat_9) {
  char s1[100] = "";
  char s2[100] = "";
  char s3[] = "\0";
  ck_assert_pstr_eq(strcat(s1, s3), s21_strcat(s2, s3));
}
END_TEST

START_TEST(test_s21_strcat_10) {
  char s1[100] = "Hell0000\0";
  char s2[100] = "Hell0000\0";
  char s3[] = "";
  ck_assert_pstr_eq(strcat(s1, s3), s21_strcat(s2, s3));
}
END_TEST

START_TEST(test_s21_strcat_11) {
  char s1[30] = "Hello, world!";
  char s2[30] = "Hello, world!";
  char s3[] = "Hello, world!";
  ck_assert_pstr_eq(strcat(s1, s3), s21_strcat(s2, s3));
}
END_TEST

START_TEST(test_s21_strcat_12) {
  char s1[30] = "Hello, world!";
  char s2[30] = "Hello, world!";
  char s3[] = "\0";
  ck_assert_pstr_eq(strcat(s1, s3), s21_strcat(s2, s3));
}
END_TEST

START_TEST(test_s21_strcat_13) {
  char s1[30] = "Hello, world!";
  char s2[30] = "Hello, world!";
  char s3[] = "\n\0\\d\f\\g\7";
  ck_assert_pstr_eq(strcat(s1, s3), s21_strcat(s2, s3));
}
END_TEST

Suite *make_strcat_suite(void) {
  Suite *s = suite_create("strcat");
  TCase *tc_strings = tcase_create("strings");
  suite_add_tcase(s, tc_strings);
  tcase_add_test(tc_strings, test_s21_strcat_1);
  tcase_add_test(tc_strings, test_s21_strcat_2);
  tcase_add_test(tc_strings, test_s21_strcat_3);
  tcase_add_test(tc_strings, test_s21_strcat_4);
  tcase_add_test(tc_strings, test_s21_strcat_5);
  tcase_add_test(tc_strings, test_s21_strcat_6);
  tcase_add_test(tc_strings, test_s21_strcat_7);
  tcase_add_test(tc_strings, test_s21_strcat_8);
  tcase_add_test(tc_strings, test_s21_strcat_9);
  tcase_add_test(tc_strings, test_s21_strcat_10);
  tcase_add_test(tc_strings, test_s21_strcat_11);
  tcase_add_test(tc_strings, test_s21_strcat_12);
  tcase_add_test(tc_strings, test_s21_strcat_13);
  return s;
}
