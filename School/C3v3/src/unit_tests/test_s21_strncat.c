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

START_TEST(test_s21_strncat_4) {
  char s1[30] = "Hello, world!";
  char s2[30] = "Hello, world!";
  char s3[] = "";
  s21_size_t n = 0;
  ck_assert_pstr_eq(strncat(s1, s3, n), s21_strncat(s2, s3, n));
}
END_TEST

START_TEST(test_s21_strncat_5) {
  char s1[30] = "";
  char s2[30] = "";
  char s3[] = "Hello, world!";
  s21_size_t n = 13;
  ck_assert_pstr_eq(strncat(s1, s3, n), s21_strncat(s2, s3, n));
}
END_TEST

START_TEST(test_s21_strncat_6) {
  char s1[100] = "Hello, world!";
  char s2[100] = "Hello, world!";
  char s3[] =
      "My name is Polina. I hate this, maybe I'm not supposed for this.";
  s21_size_t n = 6;
  ck_assert_pstr_eq(strncat(s1, s3, n), s21_strncat(s2, s3, n));
}
END_TEST

START_TEST(test_s21_strncat_7) {
  char s1[30] = "";
  char s2[30] = "";
  char s3[] = "Hello, world!";
  s21_size_t n = 3;
  ck_assert_pstr_eq(strncat(s1, s3, n), s21_strncat(s2, s3, n));
}
END_TEST

START_TEST(test_s21_strncat_8) {
  char s1[100] = "Hello, world!";
  char s2[100] = "Hello, world!";
  char s3[] = "My name is Polina.";
  s21_size_t n = 2;
  ck_assert_pstr_eq(strncat(s1, s3, n), s21_strncat(s2, s3, n));
}
END_TEST

START_TEST(test_s21_strncat_9) {
  char s1[100] = "";
  char s2[100] = "";
  char s3[] = "";
  s21_size_t n = 10;
  ck_assert_pstr_eq(strncat(s1, s3, n), s21_strncat(s2, s3, n));
}
END_TEST

START_TEST(test_s21_strncat_10) {
  char s1[100] = "Hello\0, world!";
  char s2[100] = "Hello\0, world!";
  char s3[] = "My name is\0 Polina.";
  s21_size_t n = 15;
  ck_assert_pstr_eq(strncat(s1, s3, n), s21_strncat(s2, s3, n));
}
END_TEST

START_TEST(test_s21_strncat_11) {
  char s1[100] = "Hello, world!";
  char s2[100] = "Hello, world!";
  char s3[] = "\0";
  s21_size_t n = 1;
  ck_assert_pstr_eq(strncat(s1, s3, n), s21_strncat(s2, s3, n));
}
END_TEST

START_TEST(test_s21_strncat_12) {
  char s1[100] = "Hello, world!";
  char s2[100] = "Hello, world!";
  char s3[] = "\0";
  s21_size_t n = 0;
  ck_assert_pstr_eq(strncat(s1, s3, n), s21_strncat(s2, s3, n));
}
END_TEST

START_TEST(test_s21_strncat_13) {
  char s1[100] = "Hello, world!";
  char s2[100] = "Hello, world!";
  char s3[] = "\0\0\0\0";
  s21_size_t n = 4;
  ck_assert_pstr_eq(strncat(s1, s3, n), s21_strncat(s2, s3, n));
}
END_TEST

START_TEST(test_s21_strncat_14) {
  char s1[100] = "Hello, world!";
  char s2[100] = "Hello, world!";
  char s3[] = "";
  s21_size_t n = 2;
  ck_assert_pstr_eq(strncat(s1, s3, n), s21_strncat(s2, s3, n));
}
END_TEST

START_TEST(test_s21_strncat_15) {
  char s1[100] = "Hello, world!\0\0\0";
  char s2[100] = "Hello, world!\0\0\0";
  char s3[] = "My name is Polina.";
  s21_size_t n = 0;
  ck_assert_pstr_eq(strncat(s1, s3, n), s21_strncat(s2, s3, n));
}
END_TEST

START_TEST(test_s21_strncat_16) {
  char s1[30] = "Hello, world!";
  char s2[30] = "Hello, world!";
  char s3[] = "Hello, world!";
  s21_size_t n = 1;
  ck_assert_pstr_eq(strncat(s1, s3, n), s21_strncat(s2, s3, n));
}
END_TEST

START_TEST(test_s21_strncat_17) {
  char s1[30] = "Hello, world!";
  char s2[30] = "Hello, world!";
  char s3[] = "\0";
  s21_size_t n = 1;
  ck_assert_pstr_eq(strncat(s1, s3, n), s21_strncat(s2, s3, n));
}
END_TEST

START_TEST(test_s21_strncat_18) {
  char s1[30] = "Hello, world!";
  char s2[30] = "Hello, world!";
  char s3[] = "\n\0\\d\f\\g\7";
  s21_size_t n = 3;
  ck_assert_pstr_eq(strncat(s1, s3, n), s21_strncat(s2, s3, n));
}
END_TEST

Suite *make_strncat_suite(void) {
  Suite *s = suite_create("strncat");
  TCase *tc_strings = tcase_create("strings");
  suite_add_tcase(s, tc_strings);
  tcase_add_test(tc_strings, test_s21_strncat_1);
  tcase_add_test(tc_strings, test_s21_strncat_2);
  tcase_add_test(tc_strings, test_s21_strncat_3);
  tcase_add_test(tc_strings, test_s21_strncat_4);
  tcase_add_test(tc_strings, test_s21_strncat_5);
  tcase_add_test(tc_strings, test_s21_strncat_6);
  tcase_add_test(tc_strings, test_s21_strncat_7);
  tcase_add_test(tc_strings, test_s21_strncat_8);
  tcase_add_test(tc_strings, test_s21_strncat_9);
  tcase_add_test(tc_strings, test_s21_strncat_10);
  tcase_add_test(tc_strings, test_s21_strncat_11);
  tcase_add_test(tc_strings, test_s21_strncat_12);
  tcase_add_test(tc_strings, test_s21_strncat_13);
  tcase_add_test(tc_strings, test_s21_strncat_14);
  tcase_add_test(tc_strings, test_s21_strncat_15);
  tcase_add_test(tc_strings, test_s21_strncat_16);
  tcase_add_test(tc_strings, test_s21_strncat_17);
  tcase_add_test(tc_strings, test_s21_strncat_18);
  return s;
}
