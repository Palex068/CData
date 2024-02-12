#include "test_me.h"

START_TEST(sprintf_1_percent) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "%%Test %o Test";
  int val = 012;
  ck_assert_int_eq(sprintf(str1, str3, val), s21_sprintf(str2, str3, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_2_percent) {
  char str1[100];
  char str2[100];
  char *str3 = "Test %o Tes%%%%t %o";
  int val = 012;
  int val2 = 017;
  ck_assert_int_eq(sprintf(str1, str3, val, val2),
                   s21_sprintf(str2, str3, val, val2));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_3_percent) {
  char str1[100];
  char str2[100];
  char *str3 = "%o Te%%st %o Test %o";
  int val = 3015;
  int val2 = 712;
  int val3 = 99;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   s21_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

Suite *test_sprintf_percent(void) {
  Suite *s = suite_create("\033[45m-=S21_SPRINTF_PERCENT=-\033[0m");
  TCase *tc = tcase_create("sprintf_tc");

  tcase_add_test(tc, sprintf_1_percent);
  tcase_add_test(tc, sprintf_2_percent);
  tcase_add_test(tc, sprintf_3_percent);

  suite_add_tcase(s, tc);
  return s;
}
