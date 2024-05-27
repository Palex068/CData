#include "test_main.h"

START_TEST(test_s21_from_float_to_decimal_003f) {
  s21_decimal value;
  s21_from_float_to_decimal(0.03F, &value);
  ck_assert_int_eq(value.bits[0], 3);
  ck_assert_int_eq(value.bits[1], 0);
  ck_assert_int_eq(value.bits[2], 0);
  ck_assert_int_eq(value.bits[3], 0b00000000000000100000000000000000);
}
END_TEST

START_TEST(test_s21_from_float_to_decimal_m003f) {
  s21_decimal value;
  s21_from_float_to_decimal(-0.03F, &value);
  ck_assert_int_eq(value.bits[0], 3);
  ck_assert_int_eq(value.bits[1], 0);
  ck_assert_int_eq(value.bits[2], 0);
  ck_assert_int_eq((unsigned)value.bits[3], 0b10000000000000100000000000000000);
}
END_TEST

START_TEST(test_s21_from_float_to_decimal_30f) {
  s21_decimal value;
  s21_from_float_to_decimal(3.0F, &value);
  ck_assert_int_eq(value.bits[0], 3);
  ck_assert_int_eq(value.bits[1], 0);
  ck_assert_int_eq(value.bits[2], 0);
  ck_assert_int_eq(value.bits[3], 0);
}
END_TEST

START_TEST(test_s21_from_float_to_decimal_m30f) {
  s21_decimal value;
  s21_from_float_to_decimal(-3.0F, &value);
  ck_assert_int_eq(value.bits[0], 3);
  ck_assert_int_eq(value.bits[1], 0);
  ck_assert_int_eq(value.bits[2], 0);
  ck_assert_int_eq((unsigned)value.bits[3], S21_MINUS);
}
END_TEST

START_TEST(test_s21_from_float_to_decimal_0f) {
  s21_decimal value;
  s21_from_float_to_decimal(0.0F, &value);
  ck_assert_int_eq(value.bits[0], 0);
  ck_assert_int_eq(value.bits[1], 0);
  ck_assert_int_eq(value.bits[2], 0);
  ck_assert_int_eq(value.bits[3], 0);
}
END_TEST

START_TEST(test_s21_from_float_to_decimal_105f) {
  s21_decimal value;
  s21_from_float_to_decimal(10.5F, &value);
  ck_assert_int_eq(value.bits[0], 105);
  ck_assert_int_eq(value.bits[1], 0);
  ck_assert_int_eq(value.bits[2], 0);
  ck_assert_int_eq(value.bits[3], 65536);
}
END_TEST

START_TEST(test_s21_from_float_to_decimal_too_small) {
  s21_decimal value;
  int err = s21_from_float_to_decimal(1e-29F, &value);
  ck_assert_int_eq(value.bits[0], 0);
  ck_assert_int_eq(value.bits[1], 0);
  ck_assert_int_eq(value.bits[2], 0);
  ck_assert_int_eq(value.bits[3], 0);
  ck_assert_int_eq(err, S21_ERROR);
}
END_TEST

START_TEST(test_s21_from_float_to_decimal_div_mzero) {
  s21_decimal value;
  int err = s21_from_float_to_decimal(-1.0F / 0.0F, &value);
  ck_assert_int_eq(err, S21_ERROR);
}
END_TEST

START_TEST(test_s21_from_float_to_decimal_div_zero) {
  s21_decimal value;
  int err = s21_from_float_to_decimal(1.0F / 0.0F, &value);
  ck_assert_int_eq(err, S21_ERROR);
}
END_TEST

START_TEST(test_s21_from_float_to_decimal_small_num) {
  s21_decimal value;
  int err = s21_from_float_to_decimal(1.234567e-28F, &value);
  ck_assert_int_eq(value.bits[0], 1);
  ck_assert_int_eq(value.bits[1], 0);
  ck_assert_int_eq(value.bits[2], 0);
  ck_assert_int_eq(value.bits[3], 1835008U);
  ck_assert_int_eq(err, S21_OK);
}
END_TEST

START_TEST(test_s21_from_float_to_decimal_10209f) {
  s21_decimal value;
  s21_from_float_to_decimal(1.02E+09F, &value);
  ck_assert_int_eq(value.bits[0], 1020000000);
  ck_assert_int_eq(value.bits[1], 0);
  ck_assert_int_eq(value.bits[2], 0);
  ck_assert_int_eq(value.bits[3], 0);
}
END_TEST

START_TEST(test_s21_from_float_to_decimal_NAN) {
  s21_decimal value;
  float nan_value = NAN;
  int err = s21_from_float_to_decimal(nan_value, &value);
  ck_assert_int_eq(err, S21_ERROR);
  ck_assert_int_eq(value.bits[0], 0);
  ck_assert_int_eq(value.bits[1], 0);
  ck_assert_int_eq(value.bits[2], 0);
  ck_assert_int_eq(value.bits[3], 0);
}
END_TEST

START_TEST(test_s21_from_float_to_decimal_12345678) {
  s21_decimal value;
  int err = s21_from_float_to_decimal(123456789.123456789F, &value);
  ck_assert_int_eq(value.bits[0], 123456800);
  ck_assert_int_eq(value.bits[1], 0);
  ck_assert_int_eq(value.bits[2], 0);
  ck_assert_int_eq(value.bits[3], 0);
  ck_assert_int_eq(err, S21_OK);
}
END_TEST

START_TEST(test_s21_from_float_to_decimal_00002f) {
  s21_decimal value;
  s21_from_float_to_decimal(0.000000002F, &value);
  ck_assert_int_eq(value.bits[0], 2);
  ck_assert_int_eq(value.bits[1], 0);
  ck_assert_int_eq(value.bits[2], 0);
  ck_assert_int_eq(value.bits[3], 0b00000000000010010000000000000000);
}
END_TEST

START_TEST(test_s21_from_float_to_decimal_001f) {
  s21_decimal value;
  int err = s21_from_float_to_decimal(10000000000.000000001F, &value);
  ck_assert_int_eq(value.bits[0], 0b01010100000010111110010000000000);
  ck_assert_int_eq(value.bits[1], 0b00000000000000000000000000000010);
  ck_assert_int_eq(value.bits[2], 0);
  ck_assert_int_eq(value.bits[3], 0);
  ck_assert_int_eq(err, S21_OK);
}
END_TEST

START_TEST(test_s21_from_float_to_decimal_5454) {
  s21_decimal value;
  s21_from_float_to_decimal(-5454.353F, &value);
  ck_assert_int_eq(value.bits[0], 5454353);
  ck_assert_int_eq(value.bits[1], 0);
  ck_assert_int_eq(value.bits[2], 0);
  ck_assert_int_eq((unsigned)value.bits[3], 0b10000000000000110000000000000000);
}
END_TEST

START_TEST(test_s21_from_float_to_decimal_m5492) {
  s21_decimal value;
  s21_from_float_to_decimal(-5.492654F, &value);
  ck_assert_int_eq(value.bits[0], 5492654);
  ck_assert_int_eq(value.bits[1], 0);
  ck_assert_int_eq(value.bits[2], 0);
  ck_assert_int_eq((unsigned)value.bits[3], 0b10000000000001100000000000000000);
}
END_TEST

START_TEST(test_s21_from_float_to_decimal_7961) {
  s21_decimal value;
  s21_from_float_to_decimal(7.961328E+08F, &value);
  ck_assert_int_eq(value.bits[0], 796132800);
  ck_assert_int_eq(value.bits[1], 0);
  ck_assert_int_eq(value.bits[2], 0);
  ck_assert_int_eq(value.bits[3], 0);
}
END_TEST

START_TEST(test_s21_from_float_to_decimal_m1234) {
  s21_decimal value;
  s21_from_float_to_decimal(-1.234568E+07F, &value);
  ck_assert_int_eq(value.bits[0], 12345680);
  ck_assert_int_eq(value.bits[1], 0);
  ck_assert_int_eq(value.bits[2], 0);
  ck_assert_int_eq((unsigned)value.bits[3], S21_MINUS);
}
END_TEST

START_TEST(test_s21_from_float_to_decimal_null_error) {
  float check = 0.f;
  s21_decimal *test = NULL;
  int val = s21_from_float_to_decimal(check, test);
  ck_assert_int_eq(val, S21_ERROR);
}
END_TEST

Suite *s21_convertations_float_to_decimal(void) {
  Suite *s = suite_create("s21_from_float_to_decimal");
  TCase *tc = tcase_create("s21_decimal");
  suite_add_tcase(s, tc);

  tcase_add_test(tc, test_s21_from_float_to_decimal_003f);
  tcase_add_test(tc, test_s21_from_float_to_decimal_m003f);
  tcase_add_test(tc, test_s21_from_float_to_decimal_30f);
  tcase_add_test(tc, test_s21_from_float_to_decimal_m30f);
  tcase_add_test(tc, test_s21_from_float_to_decimal_0f);
  tcase_add_test(tc, test_s21_from_float_to_decimal_105f);
  tcase_add_test(tc, test_s21_from_float_to_decimal_too_small);
  tcase_add_test(tc, test_s21_from_float_to_decimal_div_mzero);
  tcase_add_test(tc, test_s21_from_float_to_decimal_div_zero);
  tcase_add_test(tc, test_s21_from_float_to_decimal_small_num);
  tcase_add_test(tc, test_s21_from_float_to_decimal_10209f);
  tcase_add_test(tc, test_s21_from_float_to_decimal_NAN);
  tcase_add_test(tc, test_s21_from_float_to_decimal_12345678);
  tcase_add_test(tc, test_s21_from_float_to_decimal_00002f);
  tcase_add_test(tc, test_s21_from_float_to_decimal_001f);
  tcase_add_test(tc, test_s21_from_float_to_decimal_5454);
  tcase_add_test(tc, test_s21_from_float_to_decimal_m5492);
  tcase_add_test(tc, test_s21_from_float_to_decimal_7961);
  tcase_add_test(tc, test_s21_from_float_to_decimal_m1234);
  tcase_add_test(tc, test_s21_from_float_to_decimal_null_error);

  return s;
}