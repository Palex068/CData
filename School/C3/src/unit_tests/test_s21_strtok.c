#include "unit_tests.h"

START_TEST(test_s21_strtok_1) {
  char str_1[50] = "test1/test2/test3/test4";
  char str_2[50] = "/";
  ck_assert_pstr_eq(s21_strtok(str_1, str_2), strtok(str_1, str_2));
}
END_TEST

START_TEST(test_s21_strtok_2) {
  char str_1[50] = "A string\tof ,,tokens\nand some  more tokens";
  char str_2[50] = " ,\t\n";
  ck_assert_pstr_eq(s21_strtok(str_1, str_2), strtok(str_1, str_2));
}
END_TEST

START_TEST(test_s21_strtok_3) {
  char str_1[50] = "";
  char str_2[50] = " ,\t\n";
  ck_assert_pstr_eq(strtok(str_1, str_2), s21_strtok(str_1, str_2));
}
END_TEST

START_TEST(test_s21_strtok_4) {
  char str_1[50] = "1test1/test2/test3/test4";
  char str_2[50] = "";
  ck_assert_pstr_eq(s21_strtok(str_1, str_2), strtok(str_1, str_2));
}
END_TEST

START_TEST(test_s21_strtok_5) {
  char str_1[50] = "testlolo/test2/test3/lolotloloest4";
  char str_2[50] = "lolo";
  ck_assert_pstr_eq(strtok(str_1, str_2), s21_strtok(str_1, str_2));
}
END_TEST

START_TEST(test_s21_strtok_6) {
  char str_1[50] = "testlolo/test2/test3/lolotloloest4";
  char str_2[50] = "test";
  ck_assert_pstr_eq(strtok(str_1, str_2), s21_strtok(str_1, str_2));
}
END_TEST

START_TEST(test_s21_strtok_7) {
  char str1[] = "1test1/test2/test3/test4\\";
  char str2[] = "1test1/test2/test3/test4\\";
  char simbols[] = "/";
  char *nstr_1, *nstr_2;
  nstr_1 = strtok(str1, simbols);
  nstr_2 = s21_strtok(str2, simbols);
  while (nstr_1 != s21_NULL) {
    ck_assert_pstr_eq(nstr_1, nstr_2);
    nstr_1 = strtok(s21_NULL, simbols);
    nstr_2 = s21_strtok(s21_NULL, simbols);
  }
}
END_TEST

Suite *make_strtok_suite(void) {
  Suite *s = suite_create("strtok");
  TCase *tc_strings = tcase_create("strings");
  suite_add_tcase(s, tc_strings);
  tcase_add_test(tc_strings, test_s21_strtok_1);
  tcase_add_test(tc_strings, test_s21_strtok_2);
  tcase_add_test(tc_strings, test_s21_strtok_3);
  tcase_add_test(tc_strings, test_s21_strtok_4);
  tcase_add_test(tc_strings, test_s21_strtok_5);
  tcase_add_test(tc_strings, test_s21_strtok_6);
  tcase_add_test(tc_strings, test_s21_strtok_7);
  return s;
}
