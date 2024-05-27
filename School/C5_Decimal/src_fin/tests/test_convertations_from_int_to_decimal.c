#include "test_main.h"

START_TEST(test_s21_int_to_decimal_0) {
  int test = 0;
  s21_decimal value = {{0, 0, 0, 0}};
  s21_decimal result = {{test, 0, 0, 0}};

  s21_from_int_to_decimal(test, &value);
  ck_assert_int_eq(value.bits[0], result.bits[0]);
  ck_assert_int_eq(value.bits[1], result.bits[1]);
  ck_assert_int_eq(value.bits[2], result.bits[2]);
  ck_assert_int_eq(value.bits[3], result.bits[3]);
}
END_TEST

START_TEST(test_s21_int_to_decimal_1) {
  int test = 1;
  s21_decimal value = {{0, 0, 0, 0}};
  s21_decimal result = {{test, 0, 0, 0}};

  s21_from_int_to_decimal(test, &value);
  ck_assert_int_eq(value.bits[0], result.bits[0]);
  ck_assert_int_eq(value.bits[1], result.bits[1]);
  ck_assert_int_eq(value.bits[2], result.bits[2]);
  ck_assert_int_eq(value.bits[3], result.bits[3]);
}
END_TEST

START_TEST(test_s21_int_to_decimal_10) {
  int test = 10;
  s21_decimal value = {{0, 0, 0, 0}};
  s21_decimal result = {{test, 0, 0, 0}};

  s21_from_int_to_decimal(test, &value);
  ck_assert_int_eq(value.bits[0], result.bits[0]);
  ck_assert_int_eq(value.bits[1], result.bits[1]);
  ck_assert_int_eq(value.bits[2], result.bits[2]);
  ck_assert_int_eq(value.bits[3], result.bits[3]);
}
END_TEST

START_TEST(test_s21_int_to_decimal_1234567) {
  int test = 1234567;
  s21_decimal value = {{0, 0, 0, 0}};
  s21_decimal result = {{test, 0, 0, 0}};

  s21_from_int_to_decimal(test, &value);
  ck_assert_int_eq(value.bits[0], result.bits[0]);
  ck_assert_int_eq(value.bits[1], result.bits[1]);
  ck_assert_int_eq(value.bits[2], result.bits[2]);
  ck_assert_int_eq(value.bits[3], result.bits[3]);
}
END_TEST

START_TEST(test_s21_int_to_decimal_int_max) {
  int test = INT_MAX;
  s21_decimal value = {{0, 0, 0, 0}};
  s21_decimal result = {{test, 0, 0, 0}};

  s21_from_int_to_decimal(test, &value);
  ck_assert_int_eq(value.bits[0], result.bits[0]);
  ck_assert_int_eq(value.bits[1], result.bits[1]);
  ck_assert_int_eq(value.bits[2], result.bits[2]);
  ck_assert_int_eq(value.bits[3], result.bits[3]);
}
END_TEST

START_TEST(test_s21_int_to_decimal_minus_1) {
  int test = -1;
  s21_decimal value = {{0, 0, 0, 0}};
  s21_decimal result = {
      {-test, 0, 0, 0x80000000}};  // = 0x80000000 = -2147483648 = 2147483648

  // s21_init_decimal(&value);
  s21_from_int_to_decimal(test, &value);
  // result.bits[0] = 0b00000000000000000000000000000001;
  // result.bits[1] = 0b00000000000000000000000000000000;
  // result.bits[2] = 0b00000000000000000000000000000000;
  // result.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(value.bits[0], result.bits[0]);
  ck_assert_int_eq(value.bits[1], result.bits[1]);
  ck_assert_int_eq(value.bits[2], result.bits[2]);
  ck_assert_int_eq(value.bits[3], result.bits[3]);
}
END_TEST

START_TEST(test_s21_int_to_decimal_minus_10) {
  int test = -10;
  s21_decimal value = {{0, 0, 0, 0}};
  s21_decimal result = {{-test, 0, 0, 0x80000000}};

  // s21_init_decimal(&value);
  s21_from_int_to_decimal(test, &value);
  // result.bits[0] = 0b00000000000000000000000000001010;
  // result.bits[1] = 0b00000000000000000000000000000000;
  // result.bits[2] = 0b00000000000000000000000000000000;
  // result.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(value.bits[0], result.bits[0]);
  ck_assert_int_eq(value.bits[1], result.bits[1]);
  ck_assert_int_eq(value.bits[2], result.bits[2]);
  ck_assert_int_eq(value.bits[3], result.bits[3]);
}
END_TEST

START_TEST(test_s21_int_to_decimal_minus_1234567) {
  int test = -1234567;
  s21_decimal value = {{0, 0, 0, 0}};
  s21_decimal result = {{-test, 0, 0, 0x80000000}};

  // s21_init_decimal(&value);
  s21_from_int_to_decimal(test, &value);
  // result.bits[0] = 0b00000000000100101101011010000111;
  // result.bits[1] = 0b00000000000000000000000000000000;
  // result.bits[2] = 0b00000000000000000000000000000000;
  // result.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(value.bits[0], result.bits[0]);
  ck_assert_int_eq(value.bits[1], result.bits[1]);
  ck_assert_int_eq(value.bits[2], result.bits[2]);
  ck_assert_int_eq(value.bits[3], result.bits[3]);
}
END_TEST

START_TEST(test_s21_int_to_decimal_int_min) {
  int test = INT_MIN;
  s21_decimal value = {{0, 0, 0, 0}};
  s21_decimal result = {{-test, 0, 0, 0x80000000}};

  // s21_init_decimal(&value);
  s21_from_int_to_decimal(test, &value);
  // result.bits[0] = 0b10000000000000000000000000000000;
  // result.bits[1] = 0b00000000000000000000000000000000;
  // result.bits[2] = 0b00000000000000000000000000000000;
  // result.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(value.bits[0], result.bits[0]);
  ck_assert_int_eq(value.bits[1], result.bits[1]);
  ck_assert_int_eq(value.bits[2], result.bits[2]);
  ck_assert_int_eq(value.bits[3], result.bits[3]);
}
END_TEST

START_TEST(test_s21_int_max_to_decimal_to_int) {
  int test = INT_MAX;
  int summary = 0;
  s21_decimal value = {{0, 0, 0, 0}};

  s21_from_int_to_decimal(test, &value);
  s21_from_decimal_to_int(value, &summary);
  s21_from_int_to_decimal(summary, &value);
  s21_from_decimal_to_int(value, &summary);
  s21_from_int_to_decimal(summary, &value);
  s21_from_decimal_to_int(value, &summary);
  s21_from_int_to_decimal(summary, &value);
  s21_from_decimal_to_int(value, &summary);
  s21_from_int_to_decimal(summary, &value);
  s21_from_decimal_to_int(value, &summary);
  s21_from_int_to_decimal(summary, &value);
  s21_from_decimal_to_int(value, &summary);
  ck_assert_int_eq(test, summary);
}
END_TEST

START_TEST(test_s21_int_to_decimal_null_error) {
  int check = 0;
  s21_decimal *test = NULL;
  int val = s21_from_int_to_decimal(check, test);
  ck_assert_int_eq(val, 1);
}
END_TEST

Suite *s21_convertations_int_to_decimal(void) {
  Suite *s = suite_create("s21_from_int_to_decimal");
  TCase *tc = tcase_create("s21_decimal");
  suite_add_tcase(s, tc);

  tcase_add_test(tc, test_s21_int_to_decimal_0);
  tcase_add_test(tc, test_s21_int_to_decimal_1);
  tcase_add_test(tc, test_s21_int_to_decimal_10);
  tcase_add_test(tc, test_s21_int_to_decimal_1234567);
  tcase_add_test(tc, test_s21_int_to_decimal_int_max);
  tcase_add_test(tc, test_s21_int_to_decimal_minus_1);
  tcase_add_test(tc, test_s21_int_to_decimal_minus_10);
  tcase_add_test(tc, test_s21_int_to_decimal_minus_1234567);
  tcase_add_test(tc, test_s21_int_to_decimal_int_min);
  tcase_add_test(tc, test_s21_int_max_to_decimal_to_int);
  tcase_add_test(tc, test_s21_int_to_decimal_null_error);

  return s;
}