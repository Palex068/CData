#include "test_me.h"

START_TEST(memcpy_1) {
  char s1[] = "Hello, world!";
  char s2[] = "Hello, world!";
  char s3[] = "Good";
  s21_size_t n = 4;
  ck_assert_str_eq(memcpy(s1, s3, n), s21_memcpy(s2, s3, n));
}
END_TEST

START_TEST(memcpy_2) {
  char s1[] = "Hello, world!";
  char s2[] = "Hello, world!";
  char s3[] = "\0";
  s21_size_t n = 1;
  ck_assert_str_eq(memcpy(s1, s3, n), s21_memcpy(s2, s3, n));
}
END_TEST

START_TEST(memcpy_3) {
  char s1[] = "Hello, world!";
  char s2[] = "Hello, world!";
  char s3[] = "f";
  s21_size_t n = 0;
  ck_assert_str_eq(memcpy(s1, s3, n), s21_memcpy(s2, s3, n));
}
END_TEST

START_TEST(memcpy_4) {
  char s1[] = "Hello, world!";
  char s2[] = "Hello, world!";
  char s3[] = "Hi";
  s21_size_t n = 3;
  ck_assert_str_eq(memcpy(s1, s3, n), s21_memcpy(s2, s3, n));
}
END_TEST

START_TEST(memcpy_5) {
  char s1[] = "Hello, world!";
  char s2[] = "Hello, world!";
  char s3[] = "Hi";
  s21_size_t n = 2;
  ck_assert_str_eq(memcpy(s1, s3, n), s21_memcpy(s2, s3, n));
}
END_TEST

START_TEST(memcpy_6) {
  char s1[] = "";
  char s2[] = "";
  char s3[] = "love";
  s21_size_t n = 0;
  ck_assert_str_eq(memcpy(s1, s3, n), s21_memcpy(s2, s3, n));
}
END_TEST

START_TEST(memcpy_7) {
  char s1[] = "new_strnew_string";
  char s2[] = "new_strnew_string";
  char s3[] = "new_string";
  s21_size_t n = strlen(s3);
  ck_assert_str_eq(memcpy(s1, s3, n), s21_memcpy(s2, s3, n));
}
END_TEST

START_TEST(memcpy_8) {
  char s1[] = "699\017020";
  char s2[] = "699\017020";
  char s3[] = "com";
  s21_size_t n = 3;
  ck_assert_str_eq(memcpy(s1, s3, n), s21_memcpy(s2, s3, n));
}
END_TEST

START_TEST(memcpy_9) {
  char s1[] = "69917020";
  char s2[] = "69917020";
  char s3[] = "c";
  s21_size_t n = 1;
  ck_assert_str_eq(memcpy(s1, s3, n), s21_memcpy(s2, s3, n));
}
END_TEST

START_TEST(memcpy_10) {
  char s1[] = "69917020";
  char s2[] = "69917020";
  char s3[] = "com";
  s21_size_t n = 3;
  ck_assert_str_eq(memcpy(s1, s3, n), s21_memcpy(s2, s3, n));
}
END_TEST

Suite *test_memcpy(void) {
  Suite *s = suite_create("\033[45m-=S21_MEMCPY=-\033[0m");
  TCase *tc = tcase_create("memcpy_tc");

  tcase_add_test(tc, memcpy_1);
  tcase_add_test(tc, memcpy_2);
  tcase_add_test(tc, memcpy_3);
  tcase_add_test(tc, memcpy_4);
  tcase_add_test(tc, memcpy_5);
  tcase_add_test(tc, memcpy_6);
  tcase_add_test(tc, memcpy_7);
  tcase_add_test(tc, memcpy_8);
  tcase_add_test(tc, memcpy_9);
  tcase_add_test(tc, memcpy_10);

  suite_add_tcase(s, tc);
  return s;
}
