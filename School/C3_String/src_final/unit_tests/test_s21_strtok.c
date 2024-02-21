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

START_TEST(test_s21_strtok_8) {
  char s1[] = "\0ABABABABABBABABABBABABABABABBA";
  char s2[] = "\0ABABABABABBABABABBABABABABABBA";
  char s3[] = "A";
  ck_assert_pstr_eq(strtok(s1, s3), s21_strtok(s2, s3));
}
END_TEST

START_TEST(test_s21_strtok_9) {
  char s1[] = "\0Hello, world!";
  char s2[] = "\0Hello, world!";
  char s3[] = "\0";
  ck_assert_pstr_eq(strtok(s1, s3), s21_strtok(s2, s3));
}
END_TEST

START_TEST(test_s21_strtok_10) {
  char s1[] = "\0Hello, world!";
  char s2[] = "\0Hello, world!";
  char s3[] = "";
  ck_assert_pstr_eq(strtok(s1, s3), s21_strtok(s2, s3));
}
END_TEST

START_TEST(test_s21_strtok_12) {
  char s1[] = "tuz-tuz-tuz";
  char s2[] = "tuz-tuz-tuz";
  char s3[] = "z-tuz-tuz";
  ck_assert_pstr_eq(strtok(s1, s3), s21_strtok(s2, s3));
}
END_TEST

START_TEST(test_s21_strtok_13) {
  char s1[] = "Hello, world! And other people";
  char s2[] = "Hello, world! And other people";
  char s3[] = "\0Come here";
  char s4[] = "\0Come here";
  char s5[] = "";

  ck_assert_pstr_eq(strtok(s1, s5), s21_strtok(s2, s5));
  for (int i = 0; i < 5; i++) {
    ck_assert_pstr_eq(strtok(s21_NULL, s5), s21_strtok(s21_NULL, s5));
  }
  ck_assert_pstr_eq(strtok(s3, s5), s21_strtok(s4, s5));
  ck_assert_pstr_eq(strtok(s21_NULL, s5), s21_strtok(s21_NULL, s5));
  ck_assert_pstr_eq(strtok(s21_NULL, s5), s21_strtok(s21_NULL, s5));
}
END_TEST

START_TEST(test_s21_strtok_14) {
  char s1[] = "Hello,       world! And other people";
  char s2[] = "Hello,       world! And other people";
  char s3[] = "Come here";
  char s4[] = "Come here";
  char s5[] = " o";

  ck_assert_pstr_eq(strtok(s1, s5), s21_strtok(s2, s5));
  for (int i = 0; i < 5; i++) {
    ck_assert_pstr_eq(strtok(s21_NULL, s5), s21_strtok(s21_NULL, s5));
  }
  ck_assert_pstr_eq(strtok(s3, s5), s21_strtok(s4, s5));
  ck_assert_pstr_eq(strtok(s21_NULL, s5), s21_strtok(s21_NULL, s5));
  ck_assert_pstr_eq(strtok(s21_NULL, s5), s21_strtok(s21_NULL, s5));
}
END_TEST

START_TEST(test_s21_strtok_15) {
  char s1[] = "Hello,      worllllllllllld! And lother people      ";
  char s2[] = "Hello,      worllllllllllld! And lother people      ";
  char s3[] = "Come here";
  char s4[] = "Come here";
  char s5[] = " l";

  ck_assert_pstr_eq(strtok(s1, s5), s21_strtok(s2, s5));
  for (int i = 0; i < 5; i++) {
    ck_assert_pstr_eq(strtok(s21_NULL, s5), s21_strtok(s21_NULL, s5));
  }
  ck_assert_pstr_eq(strtok(s3, s5), s21_strtok(s4, s5));
  ck_assert_pstr_eq(strtok(s21_NULL, s5), s21_strtok(s21_NULL, s5));
  ck_assert_pstr_eq(strtok(s21_NULL, s5), s21_strtok(s21_NULL, s5));
}
END_TEST

START_TEST(test_s21_strtok_16) {
  char s1[] = "Helllllllo,      worllllllllllld! And lother people      ";
  char s2[] = "Helllllllo,      worllllllllllld! And lother people      ";
  char s3[] = "Come here";
  char s4[] = "Come here";
  char s5[] = "l";
  char s6[] = " ";

  ck_assert_str_eq(strtok(s1, s5), s21_strtok(s2, s5));
  for (int i = 0; i < 5; i++) {
    ck_assert_pstr_eq(strtok(s21_NULL, s6), s21_strtok(s21_NULL, s6));
  }
  ck_assert_pstr_eq(strtok(s3, s6), s21_strtok(s4, s6));
  ck_assert_pstr_eq(strtok(s21_NULL, s6), s21_strtok(s21_NULL, s6));
  ck_assert_pstr_eq(strtok(s21_NULL, s6), s21_strtok(s21_NULL, s6));
}
END_TEST

START_TEST(test_s21_strtok_17) {
  char s1[] = "ROROROROMA!!!!!!!!!";
  char s2[] = "ROROROROMA!!!!!!!!!";
  char s3[] = "R";
  strtok(s1, s3);
  strtok(NULL, s3);
  s21_strtok(s2, s3);
  s21_strtok(NULL, s3);
  ck_assert_pstr_eq(s1, s2);
}
END_TEST

START_TEST(test_s21_strtok_18) {
  char s1[] = "AGONIA";
  char s2[] = "AGONIA";
  char s3[] = "A";
  strtok(s1, s3);
  strtok(NULL, s3);
  strtok(NULL, s3);
  s21_strtok(s2, s3);
  s21_strtok(NULL, s3);
  s21_strtok(NULL, s3);
  ck_assert_pstr_eq(s1, s2);
}
END_TEST

START_TEST(test_s21_strtok_19) {
  char s1[] = "MYPHONENUM68697317172648";
  char s2[] = "MYPHONENUM68697317172648";
  char s3[] = "MYPHONENUM6869";
  char *s4 = strtok(s1, s3);
  char *s6 = strtok(s21_NULL, s3);

  char *s5 = s21_strtok(s2, s3);
  char *s7 = s21_strtok(s21_NULL, s3);

  ck_assert_pstr_eq(s1, s2);
  ck_assert_pstr_eq(s4, s5);
  ck_assert_pstr_eq(s6, s7);
}
END_TEST

START_TEST(test_s21_strtok_20) {
  char s1[] = "AAAAAAGOONIAAAAA";
  char s2[] = "AAAAAAGOONIAAAAA";
  char s3[] = "A";
  strtok(s1, s3);
  strtok(NULL, s2);
  strtok(NULL, s2);
  s21_strtok(s2, s3);
  s21_strtok(NULL, s3);
  s21_strtok(NULL, s3);
  ck_assert_pstr_eq(s1, s2);
}
END_TEST

START_TEST(test_s21_strtok_21) {
  char s1[] = "Hello, world!";
  char s2[] = "Hello, world!";
  char s3[] = "!";
  ck_assert_pstr_eq(strtok(s1, s3), s21_strtok(s2, s3));
}
END_TEST

START_TEST(test_s21_strtok_22) {
  char s1[] = "";
  char s2[] = "";
  char s3[] = "";
  ck_assert_pstr_eq(strtok(s1, s3), s21_strtok(s2, s3));
}
END_TEST

START_TEST(test_s21_strtok_23) {
  char s1[] = "Hello, world!";
  char s2[] = "Hello, world!";
  char s3[] = "\0";
  ck_assert_pstr_eq(strtok(s1, s3), s21_strtok(s2, s3));
}
END_TEST

START_TEST(test_s21_strtok_24) {
  char s1[] = "Hello, world!";
  char s2[] = "Hello, world!";
  char s3[] = "";
  ck_assert_pstr_eq(strtok(s1, s3), s21_strtok(s2, s3));
}
END_TEST

START_TEST(test_s21_strtok_25) {
  char s1[] = "Hello, world!";
  char s2[] = "Hello, world!";
  char s3[] = "Hello, world!";
  ck_assert_pstr_eq(strtok(s1, s3), s21_strtok(s2, s3));
}
END_TEST

START_TEST(test_s21_strtok_26) {
  char s1[] = "Hello, world!";
  char s2[] = "Hello, world!";
  char s3[] =
      "My name is Polina. I hate this, maybe I'm not supposed for this.";
  ck_assert_pstr_eq(strtok(s1, s3), s21_strtok(s2, s3));
}
END_TEST

START_TEST(test_s21_strtok_27) {
  char s1[] = "ABABABABABBABABABBABABABABABBA";
  char s2[] = "ABABABABABBABABABBABABABABABBA";
  char s3[] = "B";
  ck_assert_pstr_eq(strtok(s1, s3), s21_strtok(s2, s3));
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
  tcase_add_test(tc_strings, test_s21_strtok_8);
  tcase_add_test(tc_strings, test_s21_strtok_9);
  tcase_add_test(tc_strings, test_s21_strtok_10);
  tcase_add_test(tc_strings, test_s21_strtok_12);
  tcase_add_test(tc_strings, test_s21_strtok_13);
  tcase_add_test(tc_strings, test_s21_strtok_14);
  tcase_add_test(tc_strings, test_s21_strtok_15);
  tcase_add_test(tc_strings, test_s21_strtok_16);
  tcase_add_test(tc_strings, test_s21_strtok_17);
  tcase_add_test(tc_strings, test_s21_strtok_18);
  tcase_add_test(tc_strings, test_s21_strtok_19);
  tcase_add_test(tc_strings, test_s21_strtok_20);
  tcase_add_test(tc_strings, test_s21_strtok_21);
  tcase_add_test(tc_strings, test_s21_strtok_22);
  tcase_add_test(tc_strings, test_s21_strtok_23);
  tcase_add_test(tc_strings, test_s21_strtok_24);
  tcase_add_test(tc_strings, test_s21_strtok_25);
  tcase_add_test(tc_strings, test_s21_strtok_26);
  tcase_add_test(tc_strings, test_s21_strtok_27);
  return s;
}
