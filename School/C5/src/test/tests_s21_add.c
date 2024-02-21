#include "../tests.h"

START_TEST(add_1_test) {
  s21_decimal num = {{1, 0, 0, 0}};
  s21_decimal num2 = {{1, 0, 0, 0}};
  s21_decimal res = {0};
  s21_decimal answer = {{2, 0, 0, 0}};

  s21_add(num, num2, &res);
  ck_assert_int_eq(res.bits[0], answer.bits[0]);
  ck_assert_int_eq(res.bits[1], answer.bits[1]);
  ck_assert_int_eq(res.bits[2], answer.bits[2]);
  ck_assert_int_eq(res.bits[3], answer.bits[3]);
}
END_TEST

START_TEST(add_2_test) {
  s21_decimal num1 = {{-1, -1, 56648, 0}};
  s21_decimal num2 = {{44, 369, 1687, 0}};
  s21_decimal res = {{0, 0, 0, 0}};

  int status = s21_add(num1, num2, &res);

  ck_assert_int_eq(status, 0);
  ck_assert_int_eq(res.bits[0], 43);
  ck_assert_int_eq(res.bits[1], 369);
  ck_assert_int_eq(res.bits[2], 58336);
  ck_assert_int_eq(res.bits[3], 0);
}
END_TEST

START_TEST(add_3_test) {
  s21_decimal num1 = {{-1, -1, -1688, 0}};
  s21_decimal num2 = {{44, 369, 1687, 0}};
  s21_decimal res = {{0, 0, 0, 0}};
  int status = s21_add(num1, num2, &res);
  ck_assert_int_eq(status, 1);
  ck_assert_int_eq(res.bits[0], 0);
  ck_assert_int_eq(res.bits[1], 0);
  ck_assert_int_eq(res.bits[2], 0);
  ck_assert_int_eq(res.bits[3], 0);
}
END_TEST

START_TEST(add_4_test) {
  s21_decimal num1 = {
      {(unsigned int)-1, (unsigned int)-1, 56648, (unsigned int)-2147483648}};
  s21_decimal num2 = {{44, 369, 1687, (unsigned int)-2147483648}};
  s21_decimal res = {{0, 0, 0, 0}};
  int status = s21_add(num1, num2, &res);
  ck_assert_int_eq(status, 0);
  ck_assert_int_eq(res.bits[0], 43);
  ck_assert_int_eq(res.bits[1], 369);
  ck_assert_int_eq(res.bits[2], 58336);
  ck_assert_int_eq(res.bits[3], (unsigned int)-2147483648);
}
END_TEST

START_TEST(add_5_test) {
  s21_decimal num1 = {{(unsigned int)-1, (unsigned int)-1, (unsigned int)-1688,
                       (unsigned int)-2147483648}};
  s21_decimal num2 = {{44, 369, 1687, (unsigned int)-2147483648}};
  s21_decimal res = {{0, 0, 0, 0}};
  int status = s21_add(num1, num2, &res);
  ck_assert_int_eq(status, 2);
  ck_assert_int_eq(res.bits[0], 0);
  ck_assert_int_eq(res.bits[1], 0);
  ck_assert_int_eq(res.bits[2], 0);
  ck_assert_int_eq(res.bits[3], 0);
}
END_TEST

START_TEST(add_6_test) {
  s21_decimal num1 = {{45, 0, 10, (unsigned int)-2147483648}};
  // print_decimal(num1);
  s21_decimal num2 = {{67, 0, 0, (unsigned int)-2147352576}};
  // print_decimal(num2);
  s21_decimal res = {{0, 0, 0, 0}};

  int status = s21_add(num1, num2, &res);

  ck_assert_int_eq(status, 0);
  ck_assert_int_eq(res.bits[0], 4567);
  ck_assert_int_eq(res.bits[1], 0);
  ck_assert_int_eq(res.bits[2], 1000);
  ck_assert_int_eq(res.bits[3], (unsigned int)-2147352576);
}
END_TEST

START_TEST(add_7_test) {
  s21_decimal num1 = {{45, 0, 10, 65536}};

  s21_decimal num2 = {{67, 0, 0, 131072}};

  s21_decimal res = {{0, 0, 0, 0}};

  int status = s21_add(num1, num2, &res);

  ck_assert_int_eq(status, 0);
  ck_assert_int_eq(res.bits[0], 517);
  ck_assert_int_eq(res.bits[1], 0);
  ck_assert_int_eq(res.bits[2], 100);
  ck_assert_int_eq(res.bits[3], 131072);
}
END_TEST

START_TEST(add_8_test) {
  s21_decimal num1 = {
      {(unsigned int)-2, (unsigned int)-1, (unsigned int)-1, 0}};
  s21_decimal num2 = {{5, 0, 0, 65536}};
  s21_decimal res = {{0, 0, 0, 0}};

  int status = s21_add(num1, num2, &res);

  ck_assert_int_eq(status, 0);
  ck_assert_int_eq(res.bits[0], (unsigned int)-2);
  ck_assert_int_eq(res.bits[1], (unsigned int)-1);
  ck_assert_int_eq(res.bits[2], (unsigned int)-1);
  ck_assert_int_eq(res.bits[3], 0);
}
END_TEST

START_TEST(add_9_test) {
  s21_decimal num1 = {{(unsigned int)-3, (unsigned int)-1, (unsigned int)-1,
                       (unsigned int)-2147483648}};
  s21_decimal num2 = {{7, 0, 0, (unsigned int)-2147418112}};
  s21_decimal res = {{2, 1, 4, 65536}};
  int status = s21_add(num1, num2, &res);
  ck_assert_int_eq(status, 0);
  ck_assert_int_eq(res.bits[0], (unsigned int)-2);
  ck_assert_int_eq(res.bits[1], (unsigned int)-1);
  ck_assert_int_eq(res.bits[2], (unsigned int)-1);
  ck_assert_int_eq(res.bits[3], (unsigned int)-2147483648);
}
END_TEST

START_TEST(add_10_test) {
  s21_decimal num1 = {{0, 0, 10, 0}};
  s21_decimal num2 = {{6, 0, 0, 589824}};
  s21_decimal res = {{0, 0, 0, 0}};
  int status = s21_add(num1, num2, &res);
  ck_assert_int_eq(status, 0);
  ck_assert_int_eq(res.bits[0], 1);
  ck_assert_int_eq(res.bits[1], 0);
  ck_assert_int_eq(res.bits[2], 1000000000);
  ck_assert_int_eq(res.bits[3], 524288);
}
END_TEST

START_TEST(add_11_test) {
  s21_decimal num1 = {{0, 0, 13, (unsigned int)-2147483648}};
  s21_decimal num2 = {{4, 0, 0, (unsigned int)-2146893824}};
  s21_decimal res = {{0, 0, 0, 0}};
  int status = s21_add(num1, num2, &res);
  ck_assert_int_eq(status, 0);
  ck_assert_int_eq(res.bits[0], 0);
  ck_assert_int_eq(res.bits[1], 0);
  ck_assert_int_eq(res.bits[2], 1300000000);
  ck_assert_int_eq(res.bits[3], (unsigned int)-2146959360);
}
END_TEST

START_TEST(add_12_test) {
  s21_decimal num1 = {{6, 7, 8, 0}};
  s21_decimal num2 = {{5, 4, 3, (unsigned int)-2147483648}};
  s21_decimal res = {{0, 0, 0, 0}};
  int status = s21_add(num1, num2, &res);
  ck_assert_int_eq(status, 0);
  ck_assert_int_eq(res.bits[0], 1);
  ck_assert_int_eq(res.bits[1], 3);
  ck_assert_int_eq(res.bits[2], 5);
  ck_assert_int_eq(res.bits[3], 0);
}
END_TEST

START_TEST(add_13_test) {
  s21_decimal num1 = {{3, 1, 3, 0}};
  s21_decimal num2 = {{5, 4, 8, (unsigned int)-2147483648}};
  s21_decimal res = {{0, 0, 0, 0}};
  int status = s21_add(num1, num2, &res);
  ck_assert_int_eq(status, 0);
  ck_assert_int_eq(res.bits[0], 2);
  ck_assert_int_eq(res.bits[1], 3);
  ck_assert_int_eq(res.bits[2], 5);
  ck_assert_int_eq(res.bits[3], (unsigned int)-2147483648);
}
END_TEST

START_TEST(add_14_test) {
  s21_decimal num1 = {{6, 7, 8, (unsigned int)-2147483648}};
  s21_decimal num2 = {{5, 4, 3, 0}};
  s21_decimal res = {{0, 0, 0, 0}};
  int status = s21_add(num1, num2, &res);
  ck_assert_int_eq(status, 0);
  ck_assert_int_eq(res.bits[0], 1);
  ck_assert_int_eq(res.bits[1], 3);
  ck_assert_int_eq(res.bits[2], 5);
  ck_assert_int_eq(res.bits[3], (unsigned int)-2147483648);
}
END_TEST

START_TEST(add_15_test) {
  s21_decimal num1 = {{3, 1, 3, (unsigned int)-2147483648}};
  s21_decimal num2 = {{5, 4, 8, 0}};
  s21_decimal res = {{0, 0, 0, 0}};
  int status = s21_add(num1, num2, &res);
  ck_assert_int_eq(status, 0);
  ck_assert_int_eq(res.bits[0], 2);
  ck_assert_int_eq(res.bits[1], 3);
  ck_assert_int_eq(res.bits[2], 5);
  ck_assert_int_eq(res.bits[3], 0);
}
END_TEST

START_TEST(add_16_test) {
  s21_decimal num1 = {{0, 0, 0, 0}};
  s21_decimal num2 = {{5, 0, 0, 65536}};
  s21_decimal res = {{0, 0, 0, 0}};
  int status = s21_add(num1, num2, &res);
  ck_assert_int_eq(status, 0);
  ck_assert_int_eq(res.bits[0], 5);
  ck_assert_int_eq(res.bits[1], 0);
  ck_assert_int_eq(res.bits[2], 0);
  ck_assert_int_eq(res.bits[3], 65536);
}
END_TEST

START_TEST(add_error) {
  s21_decimal src1 = {{0, 0, 0, 0}};
  s21_decimal src2 = {{0, 0, 0, 0}};
  s21_decimal *result_our = NULL;
  int val = s21_add(src1, src2, result_our);
  ck_assert_int_eq(val, 1);
}
END_TEST

TCase *tests_s21_add(void) {
  TCase *tcase = tcase_create(TCASE_NAME);

  tcase_add_test(tcase, add_1_test);
  tcase_add_test(tcase, add_2_test);
  tcase_add_test(tcase, add_3_test);
  tcase_add_test(tcase, add_4_test);
  tcase_add_test(tcase, add_5_test);
  tcase_add_test(tcase, add_6_test);
  tcase_add_test(tcase, add_7_test);
  tcase_add_test(tcase, add_8_test);
  tcase_add_test(tcase, add_9_test);
  tcase_add_test(tcase, add_10_test);
  tcase_add_test(tcase, add_11_test);
  tcase_add_test(tcase, add_12_test);
  tcase_add_test(tcase, add_13_test);
  tcase_add_test(tcase, add_14_test);
  tcase_add_test(tcase, add_15_test);
  tcase_add_test(tcase, add_16_test);
  tcase_add_test(tcase, add_error);

  return tcase;
}
