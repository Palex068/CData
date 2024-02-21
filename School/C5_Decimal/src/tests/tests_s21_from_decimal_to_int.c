#include "tests.h"

START_TEST(test_s21_decimal_to_int_0) {
  int test = 0;
  int result = 0;
  s21_decimal value = {{test, 0, 0, 0}};

  s21_from_decimal_to_int(value, &result);
  ck_assert_int_eq(test, result);
}
END_TEST

START_TEST(test_s21_decimal_to_int_1) {
  int test = 1;
  int result = 0;
  s21_decimal value = {{test, 0, 0, 0}};

  s21_from_decimal_to_int(value, &result);
  ck_assert_int_eq(test, result);
}
END_TEST

START_TEST(test_s21_decimal_to_int_1234567) {
  int test = 12345678;
  int result = 0;
  s21_decimal value = {{test, 0, 0, 0}};

  s21_from_decimal_to_int(value, &result);
  ck_assert_int_eq(test, result);
}
END_TEST

START_TEST(test_s21_decimal_to_int_max) {
  int test = INT_MAX;
  int result = 0;
  s21_decimal value = {{test, 0, 0, 0}};

  s21_from_decimal_to_int(value, &result);
  ck_assert_int_eq(test, result);
}
END_TEST

START_TEST(test_s21_decimal_to_int_max_scale_1) {
  int test = INT_MAX / 10;
  int result = 0;
  s21_decimal value = {{0, 0, 0, 0}};
  null_decimal(&value);
  value.bits[0] = 0b01111111111111111111111111111111;
  value.bits[1] = 0b00000000000000000000000000000000;
  value.bits[2] = 0b00000000000000000000000000000000;
  value.bits[3] = 0b00000000000000010000000000000000;

  s21_from_decimal_to_int(value, &result);
  ck_assert_int_eq(test, result);
}
END_TEST

START_TEST(test_s21_decimal_to_int_max_scale_10) {
  int test = 2;
  int result = 0;
  s21_decimal value = {{0, 0, 0, 0}};
  null_decimal(&value);
  value.bits[0] = 0b11111111111111111111111111110110;
  value.bits[1] = 0b00000000000000000000000000000100;
  value.bits[2] = 0b00000000000000000000000000000000;
  value.bits[3] = 0b00000000000010100000000000000000;

  s21_from_decimal_to_int(value, &result);

  ck_assert_int_eq(test, result);
}
END_TEST

START_TEST(test_s21_decimal_to_int_max_scale_28) {
  int test = 7;
  int result = 0;
  s21_decimal value = {{0, 0, 0, 0}};
  null_decimal(&value);
  full_decimal(&value);
  value.bits[3] = 0b00000000000111000000000000000000;

  s21_from_decimal_to_int(value, &result);

  ck_assert_int_eq(test, result);
}
END_TEST

START_TEST(test_s21_decimal_to_int_max_scale_29_error) {
  int result = 0;
  s21_decimal value = {{0, 0, 0, 0}};
  null_decimal(&value);
  value.bits[0] = 0b11111111111111111111111111111111;
  value.bits[1] = 0b00000111111111111111111111111111;
  value.bits[2] = 0b00000000000000000000000000000000;
  value.bits[3] = 0b00000000000111010000000000000000;

  int status = s21_from_decimal_to_int(value, &result);
  ck_assert_int_eq(status, S21_ERROR);
}
END_TEST

START_TEST(test_s21_decimal_to_int_minus_1) {
  int test = -1;
  int result = 0;
  s21_decimal value = {{-test, 0, 0, 0x80000000}};

  s21_from_decimal_to_int(value, &result);
  ck_assert_int_eq(test, result);
}
END_TEST

START_TEST(test_s21_decimal_to_int_minus_1234567) {
  int test = -1234567;
  int result = 0;
  s21_decimal value = {{-test, 0, 0, 0x80000000}};

  s21_from_decimal_to_int(value, &result);
  ck_assert_int_eq(test, result);
}
END_TEST

START_TEST(test_s21_decimal_to_int_min_plus_1) {
  int test = INT_MIN + 1;
  int result = 0;
  s21_decimal value = {{-test, 0, 0, 0x80000000}};

  s21_from_decimal_to_int(value, &result);
  ck_assert_int_eq(test, result);
}
END_TEST

START_TEST(test_s21_decimal_to_int_min_plus_1_scale_1) {
  int test = -429496729;
  int result = 0;
  s21_decimal value = {{0, 0, 0, 0}};
  null_decimal(&value);
  value.bits[0] = 0b11111111111111111111111111111110;
  value.bits[1] = 0b00000000000000000000000000000000;
  value.bits[2] = 0b00000000000000000000000000000000;
  value.bits[3] = 0b10000000000000010000000000000000;

  s21_from_decimal_to_int(value, &result);

  ck_assert_int_eq(test, result);
}
END_TEST

START_TEST(test_s21_decimal_to_int_min_plus_1_scale_10) {
  int test = -219;
  int result = 0;
  s21_decimal value = {{0, 0, 0, 0}};
  null_decimal(&value);
  value.bits[0] = 0b11111111111111111111111111111111;
  value.bits[1] = 0b00000000000000000000000111111111;
  value.bits[2] = 0b00000000000000000000000000000000;
  value.bits[3] = 0b10000000000010100000000000000000;

  s21_from_decimal_to_int(value, &result);

  ck_assert_int_eq(test, result);
}
END_TEST

START_TEST(test_s21_decimal_to_int_min_plus_1_scale_28) {
  int test = -7;
  int result = 0;
  s21_decimal value = {{0, 0, 0, 0}};
  null_decimal(&value);
  full_decimal(&value);
  value.bits[3] = 0b10000000000111000000000000000000;

  s21_from_decimal_to_int(value, &result);
  ck_assert_int_eq(test, result);
}
END_TEST

START_TEST(test_s21_decimal_to_int_min_plus_1_scale_29_error) {
  int result = 0;
  s21_decimal value = {{0, 0, 0, 0}};
  null_decimal(&value);
  value.bits[0] = 0b11111111111111111111111111111111;
  value.bits[1] = 0b00000111111111111111111111111111;
  value.bits[2] = 0b00000000000000000000000000000000;
  value.bits[3] = 0b10000000000111010000000000000000;

  int status = s21_from_decimal_to_int(value, &result);
  ck_assert_int_eq(status, S21_ERROR);
}
END_TEST

START_TEST(test_s21_decimal_to_int_big_number_error) {
  int result = 0;
  s21_decimal value = {{0, 0, 0, 0}};
  null_decimal(&value);
  value.bits[0] = 0b00000000000000000000000000000000;
  value.bits[1] = 0b00000000000000000000000000000000;
  value.bits[2] = 0b00000001000000000000000000000000;
  value.bits[3] = 0b00000000000000000000000000000000;

  int status = s21_from_decimal_to_int(value, &result);
  ck_assert_int_eq(status, S21_ERROR);
}
END_TEST

START_TEST(test_s21_decimal_to_int_null_error) {
  int *check = NULL;
  s21_decimal test = {{
      0,
      0,
      0,
      0,
  }};
  int val = s21_from_decimal_to_int(test, check);
  ck_assert_int_eq(val, S21_ERROR);
}
END_TEST

START_TEST(test_s21_decimal_to_int_min) {
  int test = -2147483648;
  int result = 0;
  s21_decimal value = {
      {(unsigned int)2147483648, 0, 0, 0b10000000000000000000000000000000}};
  s21_from_decimal_to_int(value, &result);
  ck_assert_int_eq(test, result);
}
END_TEST

// -2147483648

TCase *tests_s21_decimal_to_int(void) {
  TCase *tcase = tcase_create(TCASE_NAME);

  tcase_add_test(tcase, test_s21_decimal_to_int_0);
  tcase_add_test(tcase, test_s21_decimal_to_int_1);
  tcase_add_test(tcase, test_s21_decimal_to_int_1234567);
  tcase_add_test(tcase, test_s21_decimal_to_int_max);
  tcase_add_test(tcase, test_s21_decimal_to_int_max_scale_1);
  tcase_add_test(tcase, test_s21_decimal_to_int_max_scale_10);
  tcase_add_test(tcase, test_s21_decimal_to_int_max_scale_28);
  tcase_add_test(tcase, test_s21_decimal_to_int_max_scale_29_error);
  tcase_add_test(tcase, test_s21_decimal_to_int_minus_1);
  tcase_add_test(tcase, test_s21_decimal_to_int_minus_1234567);
  tcase_add_test(tcase, test_s21_decimal_to_int_min_plus_1);
  tcase_add_test(tcase, test_s21_decimal_to_int_min_plus_1_scale_1);
  tcase_add_test(tcase, test_s21_decimal_to_int_min_plus_1_scale_10);
  tcase_add_test(tcase, test_s21_decimal_to_int_min_plus_1_scale_28);
  tcase_add_test(tcase, test_s21_decimal_to_int_min_plus_1_scale_29_error);
  tcase_add_test(tcase, test_s21_decimal_to_int_big_number_error);
  tcase_add_test(tcase, test_s21_decimal_to_int_null_error);
  tcase_add_test(tcase, test_s21_decimal_to_int_min);

  return tcase;
}
