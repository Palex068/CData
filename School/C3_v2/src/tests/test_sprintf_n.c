#include "test_me.h"

START_TEST(sprintf_1_n) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "Test %n Test";
  int valn1 = 0, valn2 = 0;
  ck_assert_int_eq(sprintf(str1, str3, &valn1),
                   s21_sprintf(str2, str3, &valn2));
  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(valn1, valn2);
}
END_TEST

START_TEST(sprintf_2_n) {
  char str1[100];
  char str2[100];
  char *str3 = "Test %o T%nest %o%n";
  int val = 012;
  int val2 = 017;
  int valn1 = 0, valn2 = 0, valn3 = 0, valn4 = 0;
  ck_assert_int_eq(sprintf(str1, str3, val, &valn1, val2, &valn3),
                   s21_sprintf(str2, str3, val, &valn2, val2, &valn4));
  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(valn1, valn2);
  ck_assert_int_eq(valn3, valn4);
}
END_TEST

// START_TEST(sprintf_3_n) {
//   char str1[100];
//   char str2[100];
//   char *str3 = "%o Test %o Te%-+#nst %o";
//   int val = 3015;
//   int val2 = 712;
//   int val3 = 99;
//   int valn1 = 0, valn2 = 0;
//   ck_assert_int_eq(sprintf(str1, str3, val, val2, &valn1, val3),
//                    s21_sprintf(str2, str3, val, val2, &valn2, val3));
//   ck_assert_pstr_eq(str1, str2);
//   ck_assert_int_eq(valn1, valn2);
// }
// END_TEST

// START_TEST(sprintf_4_n) {
//   char str1[100];
//   char str2[100];
//   char *str3 = "%lo Test %lo Test %ho%34.23n";
//   long int val = 3088675747373646;
//   unsigned long int val2 = 33030030303;
//   unsigned short int val3 = 22600;
//   int valn1 = 0, valn2 = 0;

//   ck_assert_int_eq(
//       sprintf(str1, str3, val, val2, (unsigned short)val3, &valn1),
//       s21_sprintf(str2, str3, val, val2, (unsigned short)val3, &valn2));
//   ck_assert_pstr_eq(str1, str2);
//   ck_assert_int_eq(valn1, valn2);
// }
// END_TEST

Suite *test_sprintf_n(void) {
  Suite *s = suite_create("\033[45m-=S21_SPRINTF_N=-\033[0m");
  TCase *tc = tcase_create("sprintf_tc");

  tcase_add_test(tc, sprintf_1_n);
  tcase_add_test(tc, sprintf_2_n);
  // tcase_add_test(tc, sprintf_3_n);
  // tcase_add_test(tc, sprintf_4_n);

  suite_add_tcase(s, tc);
  return s;
}
