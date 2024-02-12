#include "unit_tests.h"

START_TEST(test_s21_sprintf_1) {
  char buf[BUFFERSIZE];
  char buf2[BUFFERSIZE];
  ck_assert_int_eq(s21_sprintf(buf, "Aloha!%d", 21),
                   sprintf(buf2, "Aloha!%d", 21));
  ck_assert_str_eq(buf, buf2);
}
END_TEST

START_TEST(test_s21_sprintf_2) {
  char buf[BUFFERSIZE];
  char buf2[BUFFERSIZE];
  ck_assert_int_eq(s21_sprintf(buf, "%6d", 210000000),
                   sprintf(buf2, "%6d", 210000000));
  ck_assert_str_eq(buf, buf2);
}
END_TEST

START_TEST(test_s21_sprintf_3) {
  char buf[BUFFERSIZE];
  char buf2[BUFFERSIZE];
  ck_assert_int_eq(s21_sprintf(buf, "%+10d", 21), sprintf(buf2, "%+10d", 21));
  ck_assert_str_eq(buf, buf2);
}
END_TEST

START_TEST(test_s21_sprintf_4) {
  char buf[BUFFERSIZE];
  char buf2[BUFFERSIZE];
  char *format = "%0.*i";
  int val = 69;
  ck_assert_int_eq(s21_sprintf(buf, format, 5, val),
                   sprintf(buf2, format, 5, val));
  ck_assert_str_eq(buf, buf2);
}
END_TEST

START_TEST(test_s21_sprintf_5) {
  char buf[BUFFERSIZE];
  char buf2[BUFFERSIZE];
  ck_assert_int_eq(s21_sprintf(buf, "%.0d", 21), sprintf(buf2, "%.0d", 21));
  ck_assert_str_eq(buf, buf2);
}
END_TEST

START_TEST(test_s21_sprintf_6) {
  char buf[BUFFERSIZE];
  char buf2[BUFFERSIZE];
  ck_assert_int_eq(s21_sprintf(buf, "%d%d%d", -21, 0, 21),
                   sprintf(buf2, "%d%d%d", -21, 0, 21));
  ck_assert_str_eq(buf, buf2);
}
END_TEST

START_TEST(test_s21_sprintf_7) {
  char buf[BUFFERSIZE];
  char buf2[BUFFERSIZE];
  char *format = "%c";
  char val = 'X';
  ck_assert_int_eq(s21_sprintf(buf, format, val), sprintf(buf2, format, val));
  ck_assert_str_eq(buf, buf2);
}
END_TEST

START_TEST(test_s21_sprintf_8) {
  char buf[BUFFERSIZE];
  char buf2[BUFFERSIZE];
  char *format = "%.2c";
  char val = 'a';
  ck_assert_int_eq(s21_sprintf(buf, format, val), sprintf(buf2, format, val));
  ck_assert_str_eq(buf, buf2);
}
END_TEST

START_TEST(test_s21_sprintf_9) {
  char buf[BUFFERSIZE];
  char buf2[BUFFERSIZE];
  char *format = "% -2c";
  char val = 'a';
  ck_assert_int_eq(s21_sprintf(buf, format, val), sprintf(buf2, format, val));
  ck_assert_str_eq(buf, buf2);
}
END_TEST

START_TEST(test_s21_sprintf_10) {
  char buf[BUFFERSIZE];
  char buf2[BUFFERSIZE];
  char *format = "%-5.3c";
  char val = 'a';
  ck_assert_int_eq(s21_sprintf(buf, format, val), sprintf(buf2, format, val));
  ck_assert_str_eq(buf, buf2);
}
END_TEST

START_TEST(test_s21_sprintf_11) {
  char buf[BUFFERSIZE];
  char buf2[BUFFERSIZE];
  char *format = "%0.*i";
  int val = 21;
  ck_assert_int_eq(s21_sprintf(buf, format, 2, val),
                   sprintf(buf2, format, 2, val));
  ck_assert_str_eq(buf, buf2);
}
END_TEST

START_TEST(test_s21_sprintf_12) {
  char buf[BUFFERSIZE];
  char buf2[BUFFERSIZE];
  char *format = "%i%i%i";
  ck_assert_int_eq(s21_sprintf(buf, format, -21, 0, 21),
                   sprintf(buf2, format, -21, 0, 21));
  ck_assert_str_eq(buf, buf2);
}
END_TEST

START_TEST(test_s21_sprintf_13) {
  char buf[BUFFERSIZE];
  char buf2[BUFFERSIZE];
  char *format = "% f";
  long int val = 0;
  ck_assert_int_eq(s21_sprintf(buf, format, val), sprintf(buf2, format, val));
  ck_assert_str_eq(buf, buf2);
}
END_TEST

START_TEST(test_s21_sprintf_14) {
  char buf[BUFFERSIZE];
  char buf2[BUFFERSIZE];
  char *format = "% .0f %.lf %Lf %f %lf %Lf";
  float val = 0;
  double val1 = 0;
  long double val2 = 3515315.153151;
  float val3 = 5.5;
  double val4 = 9851.51351;
  long double val5 = 95919539159.53151351131;
  ck_assert_int_eq(s21_sprintf(buf, format, val, val1, val2, val3, val4, val5),
                   sprintf(buf2, format, val, val1, val2, val3, val4, val5));
  ck_assert_str_eq(buf, buf2);
}
END_TEST

START_TEST(test_s21_sprintf_15) {
  char buf[BUFFERSIZE];
  char buf2[BUFFERSIZE];
  char *format = "%f%f%f";
  ck_assert_int_eq(s21_sprintf(buf, format, -222.111, 0.0001, 222.111),
                   sprintf(buf2, format, -222.111, 0.0001, 222.111));
  ck_assert_str_eq(buf, buf2);
}
END_TEST

START_TEST(test_s21_sprintf_16) {
  char buf[BUFFERSIZE];
  char buf2[BUFFERSIZE];
  char *format = "%s%s%s";
  char *s1 = "";
  char *s2 = "78137489137498713";
  char *s3 = "CAPYBARASRULE";
  ck_assert_int_eq(s21_sprintf(buf, format, s1, s2, s3),
                   sprintf(buf2, format, s1, s2, s3));
  ck_assert_str_eq(buf, buf2);
}
END_TEST

START_TEST(test_s21_sprintf_17) {
  char buf[BUFFERSIZE];
  char buf2[BUFFERSIZE];
  char *format = "% s";
  char *s = "capybaras rule";
  ck_assert_int_eq(s21_sprintf(buf, format, s), sprintf(buf2, format, s));
  ck_assert_str_eq(buf, buf2);
}
END_TEST

START_TEST(test_s21_sprintf_18) {
  char buf[BUFFERSIZE];
  char buf2[BUFFERSIZE];
  char *format = "%u";
  unsigned int u = 2142;
  unsigned int u2 = 0;
  ck_assert_int_eq(s21_sprintf(buf, format, u, u2),
                   sprintf(buf2, format, u, u2));
  ck_assert_str_eq(buf, buf2);
}
END_TEST

START_TEST(test_s21_sprintf_19) {
  char buf[BUFFERSIZE];
  char buf2[BUFFERSIZE];
  ck_assert_int_eq(s21_sprintf(buf, "%%"), sprintf(buf2, "%%"));
  ck_assert_str_eq(buf, buf2);
}
END_TEST

START_TEST(test_s21_sprintf_20) {
  char buf[BUFFERSIZE];
  char buf2[BUFFERSIZE];
  char *format = "%g";
  double g = 0.111111;
  ck_assert_int_eq(s21_sprintf(buf, format, g), sprintf(buf2, format, g));
  ck_assert_str_eq(buf, buf2);
}
END_TEST

START_TEST(test_s21_sprintf_21) {
  char buf[BUFFERSIZE];
  char buf2[BUFFERSIZE];
  char *format = "%g %G %Lg %.5g";
  double hex1 = 41.1341;
  double hex2 = 848.9000;
  long double hex3 = 0.0843;
  double hex4 = 0.0005;
  ck_assert_int_eq(s21_sprintf(buf, format, hex1, hex2, hex3, hex4),
                   sprintf(buf2, format, hex1, hex2, hex3, hex4));

  ck_assert_str_eq(buf, buf2);
}
END_TEST

START_TEST(test_s21_sprintf_22) {
  char buf[BUFFERSIZE];
  char buf2[BUFFERSIZE];
  char format[] = "%e";
  double e = 111;
  ck_assert_int_eq(s21_sprintf(buf, format, e), sprintf(buf2, format, e));
  ck_assert_str_eq(buf, buf2);
}
END_TEST

START_TEST(test_s21_sprintf_23) {
  char buf[BUFFERSIZE];
  char buf2[BUFFERSIZE];
  ck_assert_int_eq(s21_sprintf(buf, "%x", 43951789),
                   sprintf(buf2, "%x", 43951789));
  ck_assert_str_eq(buf, buf2);
  ck_assert_int_eq(s21_sprintf(buf, "%x", 0), sprintf(buf2, "%x", 0));
  ck_assert_str_eq(buf, buf2);
}
END_TEST

START_TEST(test_s21_sprintf_24) {
  char buf[BUFFERSIZE];
  char buf2[BUFFERSIZE];
  ck_assert_int_eq(s21_sprintf(buf, "%X", 43951789),
                   sprintf(buf2, "%X", 43951789));
  ck_assert_str_eq(buf, buf2);
}
END_TEST

START_TEST(test_s21_sprintf_25) {
  char buf[BUFFERSIZE];
  char buf2[BUFFERSIZE];
  ck_assert_int_eq(s21_sprintf(buf, "%#o%o", 57175, 0),
                   sprintf(buf2, "%#o%o", 57175, 0));
  ck_assert_str_eq(buf, buf2);
  ck_assert_int_eq(s21_sprintf(buf, "%x", 0), sprintf(buf2, "%x", 0));
  ck_assert_str_eq(buf, buf2);
}
END_TEST

START_TEST(test_s21_sprintf_26) {
  char buf[BUFFERSIZE];
  char buf2[BUFFERSIZE];
  int ret = 0;
  char *format = "We are capybaras %n";
  ck_assert_int_eq(s21_sprintf(buf, format, &ret), sprintf(buf2, format, &ret));
  ck_assert_str_eq(buf, buf2);
}
END_TEST

START_TEST(test_s21_sprintf_27) {
  char buf[BUFFERSIZE];
  char buf2[BUFFERSIZE];
  char *format = "%p";
  char *nul = NULL;
  ck_assert_int_eq(s21_sprintf(buf, format, nul), sprintf(buf2, format, nul));
  ck_assert_str_eq(buf, buf2);
}
END_TEST

START_TEST(test_s21_sprintf_28) {
  char buf[BUFFERSIZE];
  char buf2[BUFFERSIZE];
  char format[] = "%0.*i %d %4.*i %013d %d";
  int val = 69;
  ck_assert_int_eq(
      s21_sprintf(buf, format, 5, val, -10431, 13, 5311, 0, -581813581),
      sprintf(buf2, format, 5, val, -10431, 13, 5311, 0, -581813581));

  ck_assert_str_eq(buf, buf2);
}
END_TEST

START_TEST(test_s21_sprintf_29) {
  char buf[BUFFERSIZE];
  char buf2[BUFFERSIZE];
  char format[] = "%0.*i %d %4.*i %013d %d";
  int val = 69;
  ck_assert_int_eq(
      s21_sprintf(buf, format, 5, val, -10431, 13, 5311, 0, -581813581),
      sprintf(buf2, format, 5, val, -10431, 13, 5311, 0, -581813581));

  ck_assert_str_eq(buf, buf2);
}
END_TEST

START_TEST(test_s21_sprintf_30) {
  char buf[BUFFERSIZE];
  char buf2[BUFFERSIZE];
  char *format = "we are capybaras %s";
  wchar_t w[] = L"我们是水豚";
  int a = s21_sprintf(buf, format, w);
  int b = sprintf(buf2, format, w);
  ck_assert_str_eq(buf, buf2);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(test_s21_sprintf_31) {
  char buf[BUFFERSIZE];
  char buf2[BUFFERSIZE];
  char *format = "% f";
  int16_t val = 43;
  ck_assert_int_eq(s21_sprintf(buf, format, val), sprintf(buf2, format, val));
  ck_assert_str_eq(buf, buf2);
}
END_TEST

START_TEST(test_s21_sprintf_32) {
  char buf[BUFFERSIZE];
  char buf2[BUFFERSIZE];
  char *format = "%-16u";
  unsigned int val = 14140;
  ck_assert_int_eq(s21_sprintf(buf, format, val), sprintf(buf2, format, val));
  ck_assert_str_eq(buf, buf2);
}
END_TEST

START_TEST(test_s21_sprintf_33) {
  char buf[BUFFERSIZE];
  char buf2[BUFFERSIZE];
  char *format = "%hd";
  unsigned short int length = 10;
  ck_assert_int_eq(s21_sprintf(buf, format, length),
                   sprintf(buf2, format, length));
  ck_assert_str_eq(buf, buf2);
}
END_TEST

START_TEST(test_s21_sprintf_34) {
  char buf[BUFFERSIZE];
  char buf2[BUFFERSIZE];
  char *format = "%*d";
  int length = 10000;
  ck_assert_int_eq(s21_sprintf(buf, format, 3, length),
                   sprintf(buf2, format, 3, length));
  ck_assert_str_eq(buf, buf2);
}
END_TEST

START_TEST(test_s21_sprintf_35) {
  char buf[BUFFERSIZE];
  char buf2[BUFFERSIZE];
  wchar_t *wstring = L"Unicode";
  ck_assert_int_eq(s21_sprintf(buf, "%25.3ls\n", wstring),
                   sprintf(buf2, "%25.3ls\n", wstring));
  ck_assert_str_eq(buf, buf2);
}
END_TEST

START_TEST(test_s21_sprintf_36) {
  char buf[BUFFERSIZE];
  char buf2[BUFFERSIZE];
  char wstring = 'c';
  ck_assert_int_eq(s21_sprintf(buf, "%-8lc\n", wstring),
                   sprintf(buf2, "%-8lc\n", wstring));
  ck_assert_str_eq(buf, buf2);
}
END_TEST

START_TEST(test_s21_sprintf_37) {
  char buf[BUFFERSIZE];
  char buf2[BUFFERSIZE];
  char wstring = 'c';
  ck_assert_int_eq(s21_sprintf(buf, "%lc\n", wstring),
                   sprintf(buf2, "%lc\n", wstring));
  ck_assert_str_eq(buf, buf2);
}
END_TEST

START_TEST(test_s21_sprintf_38) {
  char buf[BUFFERSIZE];
  char buf2[BUFFERSIZE];
  char wstring = L' ';
  ck_assert_int_eq(s21_sprintf(buf, "%8lc\n", wstring),
                   sprintf(buf2, "%8lc\n", wstring));
  ck_assert_str_eq(buf, buf2);
}
END_TEST

START_TEST(test_s21_sprintf_39) {
  char buf[BUFFERSIZE];
  char buf2[BUFFERSIZE];
  long int i = 213;
  ck_assert_int_eq(s21_sprintf(buf, "%ld", i), sprintf(buf2, "%ld", i));
  ck_assert_str_eq(buf, buf2);
}
END_TEST

Suite *make_sprintf_suite(void) {
  Suite *s = suite_create("sprintf");
  TCase *tc_strings = tcase_create("strings");
  suite_add_tcase(s, tc_strings);
  tcase_add_test(tc_strings, test_s21_sprintf_1);
  tcase_add_test(tc_strings, test_s21_sprintf_2);
  tcase_add_test(tc_strings, test_s21_sprintf_3);
  tcase_add_test(tc_strings, test_s21_sprintf_4);
  tcase_add_test(tc_strings, test_s21_sprintf_5);
  tcase_add_test(tc_strings, test_s21_sprintf_6);
  tcase_add_test(tc_strings, test_s21_sprintf_7);
  tcase_add_test(tc_strings, test_s21_sprintf_8);
  tcase_add_test(tc_strings, test_s21_sprintf_9);
  tcase_add_test(tc_strings, test_s21_sprintf_10);
  tcase_add_test(tc_strings, test_s21_sprintf_11);
  tcase_add_test(tc_strings, test_s21_sprintf_12);
  tcase_add_test(tc_strings, test_s21_sprintf_13);
  tcase_add_test(tc_strings, test_s21_sprintf_14);
  tcase_add_test(tc_strings, test_s21_sprintf_15);
  tcase_add_test(tc_strings, test_s21_sprintf_16);
  tcase_add_test(tc_strings, test_s21_sprintf_17);
  tcase_add_test(tc_strings, test_s21_sprintf_18);
  tcase_add_test(tc_strings, test_s21_sprintf_19);
  tcase_add_test(tc_strings, test_s21_sprintf_20);
  tcase_add_test(tc_strings, test_s21_sprintf_21);
  tcase_add_test(tc_strings, test_s21_sprintf_22);
  tcase_add_test(tc_strings, test_s21_sprintf_23);
  tcase_add_test(tc_strings, test_s21_sprintf_24);
  tcase_add_test(tc_strings, test_s21_sprintf_25);
  tcase_add_test(tc_strings, test_s21_sprintf_26);
  tcase_add_test(tc_strings, test_s21_sprintf_27);
  tcase_add_test(tc_strings, test_s21_sprintf_28);
  tcase_add_test(tc_strings, test_s21_sprintf_29);
  tcase_add_test(tc_strings, test_s21_sprintf_30);
  tcase_add_test(tc_strings, test_s21_sprintf_31);
  tcase_add_test(tc_strings, test_s21_sprintf_32);
  tcase_add_test(tc_strings, test_s21_sprintf_33);
  tcase_add_test(tc_strings, test_s21_sprintf_34);
  tcase_add_test(tc_strings, test_s21_sprintf_35);
  tcase_add_test(tc_strings, test_s21_sprintf_36);
  tcase_add_test(tc_strings, test_s21_sprintf_37);
  tcase_add_test(tc_strings, test_s21_sprintf_38);
  tcase_add_test(tc_strings, test_s21_sprintf_39);
  return s;
}
