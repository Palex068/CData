#include "test_me.h"

START_TEST(strcat_1) {
  char s1[30] = "Hello, world!";
  char s2[30] = "Hello, world!";
  char s3[] = "Hello, world!";
  ck_assert_pstr_eq(strcat(s1, s3), s21_strcat(s2, s3));
}
END_TEST

START_TEST(strcat_2) {
  char s1[30] = "Hello, world!";
  char s2[30] = "Hello, world!";
  char s3[] = "\0";
  ck_assert_pstr_eq(strcat(s1, s3), s21_strcat(s2, s3));
}
END_TEST

START_TEST(strcat_3) {
  char s1[30] = "Hello, world!";
  char s2[30] = "Hello, world!";
  char s3[] = "\n\0\\d\f\\g\7";
  ck_assert_pstr_eq(strcat(s1, s3), s21_strcat(s2, s3));
}
END_TEST

START_TEST(strcat_4) {
  char s1[30] = "Hello, world!";
  char s2[30] = "Hello, world!";
  char s3[] = "";
  ck_assert_pstr_eq(strcat(s1, s3), s21_strcat(s2, s3));
}
END_TEST

START_TEST(strcat_5) {
  char s1[30] = "";
  char s2[30] = "";
  char s3[] = "Hello, world!";
  ck_assert_pstr_eq(strcat(s1, s3), s21_strcat(s2, s3));
}
END_TEST

START_TEST(strcat_6) {
  char s1[100] = "Hello, world!";
  char s2[100] = "Hello, world!";
  char s3[] =
      "My name is Polina. I hate this, maybe I'm not supposed for this.";
  ck_assert_pstr_eq(strcat(s1, s3), s21_strcat(s2, s3));
}
END_TEST

START_TEST(strcat_7) {
  char s1[100] = "Hello\0world!";
  char s2[100] = "Hello\0world!";
  char s3[] =
      "My name is Polina. I hate this, maybe I'm not supposed for this.";
  ck_assert_pstr_eq(strcat(s1, s3), s21_strcat(s2, s3));
}
END_TEST

START_TEST(strcat_8) {
  char s1[100] = "\0";
  char s2[100] = "\0";
  char s3[] =
      "My name is Polina. I hate this\0, maybe I'm not supposed for this.";
  ck_assert_pstr_eq(strcat(s1, s3), s21_strcat(s2, s3));
}
END_TEST

START_TEST(strcat_9) {
  char s1[100] = "";
  char s2[100] = "";
  char s3[] = "\0";
  ck_assert_pstr_eq(strcat(s1, s3), s21_strcat(s2, s3));
}
END_TEST

START_TEST(strcat_10) {
  char s1[100] = "Hell0000\0";
  char s2[100] = "Hell0000\0";
  char s3[] = "";
  ck_assert_pstr_eq(strcat(s1, s3), s21_strcat(s2, s3));
}
END_TEST

Suite *test_strcat(void) {
  Suite *s = suite_create("\033[45m-=S21_STRCAT=-\033[0m");
  TCase *tc = tcase_create("strcat_tc");

  suite_add_tcase(s, tc);
  tcase_add_test(tc, strcat_1);
  tcase_add_test(tc, strcat_2);
  tcase_add_test(tc, strcat_3);
  tcase_add_test(tc, strcat_4);
  tcase_add_test(tc, strcat_5);
  tcase_add_test(tc, strcat_6);
  tcase_add_test(tc, strcat_7);
  tcase_add_test(tc, strcat_8);
  tcase_add_test(tc, strcat_9);
  tcase_add_test(tc, strcat_10);

  suite_add_tcase(s, tc);
  return s;
}
