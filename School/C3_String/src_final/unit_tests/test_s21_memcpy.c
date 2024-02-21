#include "unit_tests.h"

START_TEST(test_s21_memcpy_1) {
  char s1[] = "Hello, world!";
  char s2[] = "Hello, world!";
  char s3[] = "Good";
  s21_size_t n = 4;
  ck_assert_str_eq(memcpy(s1, s3, n), s21_memcpy(s2, s3, n));
}
END_TEST

START_TEST(test_s21_memcpy_2) {
  char s1[] = "Hello, world!";
  char s2[] = "Hello, world!";
  char s3[] = "\0";
  s21_size_t n = 1;
  ck_assert_str_eq(memcpy(s1, s3, n), s21_memcpy(s2, s3, n));
}
END_TEST

START_TEST(test_s21_memcpy_3) {
  char s1[] = "Hello, world!";
  char s2[] = "Hello, world!";
  char s3[] = "f";
  s21_size_t n = 0;
  ck_assert_str_eq(memcpy(s1, s3, n), s21_memcpy(s2, s3, n));
}
END_TEST

START_TEST(test_s21_memcpy_4) {
  char s1[] = "Hello, world!";
  char s2[] = "Hello, world!";
  char s3[] = "Hi";
  s21_size_t n = 3;
  ck_assert_str_eq(memcpy(s1, s3, n), s21_memcpy(s2, s3, n));
}
END_TEST

START_TEST(test_s21_memcpy_5) {
  char s1[] = "Hello, world!";
  char s2[] = "Hello, world!";
  char s3[] = "Hi";
  s21_size_t n = 2;
  ck_assert_str_eq(memcpy(s1, s3, n), s21_memcpy(s2, s3, n));
}
END_TEST

START_TEST(test_s21_memcpy_6) {
  char s1[] = "";
  char s2[] = "";
  char s3[] = "love";
  s21_size_t n = 0;
  ck_assert_str_eq(memcpy(s1, s3, n), s21_memcpy(s2, s3, n));
}
END_TEST

START_TEST(test_s21_memcpy_7) {
  char s1[] = "new_strnew_string";
  char s2[] = "new_strnew_string";
  char s3[] = "new_string";
  s21_size_t n = strlen(s3);
  ck_assert_str_eq(memcpy(s1, s3, n), s21_memcpy(s2, s3, n));
}
END_TEST

START_TEST(test_s21_memcpy_8) {
  char s1[] = "699\017020";
  char s2[] = "699\017020";
  char s3[] = "com";
  s21_size_t n = 3;
  ck_assert_str_eq(memcpy(s1, s3, n), s21_memcpy(s2, s3, n));
}
END_TEST

START_TEST(test_s21_memcpy_9) {
  char s1[] = "69917020";
  char s2[] = "69917020";
  char s3[] = "c";
  s21_size_t n = 1;
  ck_assert_str_eq(memcpy(s1, s3, n), s21_memcpy(s2, s3, n));
}
END_TEST

START_TEST(test_s21_memcpy_10) {
  char s1[] = "69917020";
  char s2[] = "69917020";
  char s3[] = "com";
  s21_size_t n = 3;
  ck_assert_str_eq(memcpy(s1, s3, n), s21_memcpy(s2, s3, n));
}
END_TEST

START_TEST(test_s21_memcpy_11) {
  char str_1[50] = "";
  char str_2[50] = "Hello";
  s21_size_t n = 5;
  ck_assert_pstr_eq(s21_memcpy(str_1, str_2, n), memcpy(str_1, str_2, n));
}
END_TEST

START_TEST(test_s21_memcpy_12) {
  char str_1[50] = "abcdefghij0123456789";
  char str_2[50] = "*****";
  s21_size_t n = 5;
  ck_assert_pstr_eq(s21_memcpy(str_1, str_2, n), memcpy(str_1, str_2, n));
}
END_TEST

START_TEST(test_s21_memcpy_13) {
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
  tcase_add_test(tc_strings, test_s21_memcpy_4);
  tcase_add_test(tc_strings, test_s21_memcpy_5);
  tcase_add_test(tc_strings, test_s21_memcpy_6);
  tcase_add_test(tc_strings, test_s21_memcpy_7);
  tcase_add_test(tc_strings, test_s21_memcpy_8);
  tcase_add_test(tc_strings, test_s21_memcpy_9);
  tcase_add_test(tc_strings, test_s21_memcpy_10);
  tcase_add_test(tc_strings, test_s21_memcpy_11);
  tcase_add_test(tc_strings, test_s21_memcpy_12);
  tcase_add_test(tc_strings, test_s21_memcpy_13);
  return s;
}
