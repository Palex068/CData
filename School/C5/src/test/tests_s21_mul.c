#include "../tests.h"

START_TEST(mul_2x2) {
  s21_decimal num1 = {{2, 0, 0, 0}};
  s21_decimal num2 = {{2, 0, 0, 0}};
  s21_decimal res = {{0, 0, 0, 0}};
  int status = s21_mul(num1, num2, &res);
  ck_assert_int_eq(status, 0);
  ck_assert_int_eq(res.bits[0], 4);
  ck_assert_int_eq(res.bits[1], 0);
  ck_assert_int_eq(res.bits[2], 0);
  ck_assert_int_eq(res.bits[3], 0);
}
END_TEST

START_TEST(mul_24xminus6) {
  s21_decimal num1 = {{24, 0, 0, 0}};
  s21_decimal num2 = {{6, 0, 0, (unsigned int)-2147483648}};
  s21_decimal res = {{0, 0, 0, 0}};
  int status = s21_mul(num1, num2, &res);
  ck_assert_int_eq(status, 0);
  ck_assert_int_eq(res.bits[0], 144);
  ck_assert_int_eq(res.bits[1], 0);
  ck_assert_int_eq(res.bits[2], 0);
  ck_assert_int_eq(res.bits[3], (unsigned int)-2147483648);
}
END_TEST

START_TEST(mul_minus500xminus3) {
  s21_decimal num1 = {{500, 0, 0, (unsigned int)-2147483648}};
  s21_decimal num2 = {{3, 0, 0, (unsigned int)-2147483648}};
  s21_decimal res = {{0, 0, 0, 0}};
  int status = s21_mul(num1, num2, &res);
  ck_assert_int_eq(status, 0);
  ck_assert_int_eq(res.bits[0], 1500);
  ck_assert_int_eq(res.bits[1], 0);
  ck_assert_int_eq(res.bits[2], 0);
  ck_assert_int_eq(res.bits[3], 0);
}
END_TEST

START_TEST(mul_minus2x5) {
  s21_decimal num1 = {{2, 0, 0, 0}};
  s21_decimal num2 = {{5, 0, 0, (unsigned int)-2147483648}};
  s21_decimal res = {{0, 0, 0, 0}};
  int status = s21_mul(num1, num2, &res);
  ck_assert_int_eq(status, 0);
  ck_assert_int_eq(res.bits[0], 10);
  ck_assert_int_eq(res.bits[1], 0);
  ck_assert_int_eq(res.bits[2], 0);
  ck_assert_int_eq(res.bits[3], (unsigned int)-2147483648);
}
END_TEST

START_TEST(mul_3x0point256) {
  s21_decimal num1 = {{3, 0, 0, 0}};
  s21_decimal num2 = {{256, 0, 0, 262144}};
  s21_decimal res = {{0, 0, 0, 0}};
  int status = s21_mul(num1, num2, &res);
  ck_assert_int_eq(status, 0);
  ck_assert_int_eq(res.bits[0], 768);
  ck_assert_int_eq(res.bits[1], 0);
  ck_assert_int_eq(res.bits[2], 0);
  ck_assert_int_eq(res.bits[3], 262144);
}
END_TEST

START_TEST(mul_9point213658xminus169point312846) {
  s21_decimal num1 = {{9213658, 0, 0, 393216}};
  s21_decimal num2 = {{169312846, 0, 0, (unsigned int)-2147090432}};
  s21_decimal res = {{0, 0, 0, 0}};
  int status = s21_mul(num1, num2, &res);
  ck_assert_int_eq(status, 0);
  ck_assert_int_eq(res.bits[0], (unsigned int)-1593398676);
  ck_assert_int_eq(res.bits[1], 363213);
  ck_assert_int_eq(res.bits[2], 0);
  ck_assert_int_eq(res.bits[3], (unsigned int)-2146697216);
}
END_TEST

START_TEST(mul_3point21x30point336) {
  s21_decimal num1 = {{321, 0, 0, 131072}};
  s21_decimal num2 = {{30336, 0, 0, 196608}};
  s21_decimal res = {{0, 0, 0, 0}};
  int status = s21_mul(num1, num2, &res);
  ck_assert_int_eq(status, 0);
  ck_assert_int_eq(res.bits[0], 9737856);
  ck_assert_int_eq(res.bits[1], 0);
  ck_assert_int_eq(res.bits[2], 0);
  ck_assert_int_eq(res.bits[3], 327680);
}
END_TEST

START_TEST(mul_minus3point2xminus0point3) {
  s21_decimal num1 = {{32, 0, 0, (unsigned int)-2147418112}};
  s21_decimal num2 = {{3, 0, 0, (unsigned int)-2147418112}};
  s21_decimal res = {{0, 0, 0, 0}};
  int status = s21_mul(num1, num2, &res);
  ck_assert_int_eq(status, 0);
  ck_assert_int_eq(res.bits[0], 96);
  ck_assert_int_eq(res.bits[1], 0);
  ck_assert_int_eq(res.bits[2], 0);
  ck_assert_int_eq(res.bits[3], 131072);
}
END_TEST

START_TEST(mul_zero) {
  s21_decimal num1 = {{32, 0, 0, (unsigned int)-2147418112}};
  s21_decimal num2 = {{0, 0, 0, 0}};
  s21_decimal res = {{0, 0, 0, 0}};
  int status = s21_mul(num1, num2, &res);
  ck_assert_int_eq(status, 0);
  ck_assert_int_eq(res.bits[0], 0);
  ck_assert_int_eq(res.bits[1], 0);
  ck_assert_int_eq(res.bits[2], 0);
  ck_assert_int_eq(res.bits[3], 0);
}
END_TEST

START_TEST(mul_bigXfloat) {
  s21_decimal num1 = {{0, 0, 1, 0}};
  s21_decimal num2 = {{256, 0, 0, 917504}};
  s21_decimal res = {{0, 0, 0, 0}};
  int status = s21_mul(num1, num2, &res);
  ck_assert_int_eq(status, 0);
  ck_assert_int_eq(res.bits[0], 0);
  ck_assert_int_eq(res.bits[1], 0);
  ck_assert_int_eq(res.bits[2], 256);
  ck_assert_int_eq(res.bits[3], 917504);
}
END_TEST

START_TEST(mul_overflow_positive) {
  s21_decimal num1 = {{0, 0, 5, 0}};
  s21_decimal num2 = {{(unsigned int)-1, 0, 0, 0}};
  s21_decimal res = {{0, 0, 0, 0}};
  int status = s21_mul(num1, num2, &res);
  ck_assert_int_eq(status, 1);
}
END_TEST

START_TEST(mul_overflow_negative) {
  s21_decimal num1 = {{0, 0, 1, 0}};
  s21_decimal num2 = {{0, (unsigned int)-1, 0, (unsigned int)-2147483648}};
  s21_decimal res = {{0, 0, 0, 0}};
  int status = s21_mul(num1, num2, &res);
  ck_assert_int_eq(status, 2);
}
END_TEST

START_TEST(mul_minusBigXminusBig) {
  s21_decimal num1 = {{0, 0, 1, (unsigned int)-2147483648}};
  s21_decimal num2 = {{0, -1, 0, (unsigned int)-2147483648}};
  s21_decimal res = {{0, 0, 0, 0}};
  int status = s21_mul(num1, num2, &res);
  ck_assert_int_eq(status, 1);
}
END_TEST

START_TEST(mul_normalXsmall) {
  s21_decimal num1 = {{200, 0, 0, 0}};
  s21_decimal num2 = {{2, 0, 0, 1703936}};
  s21_decimal res = {{0, 0, 0, 0}};
  int status = s21_mul(num1, num2, &res);
  ck_assert_int_eq(status, 0);
  ck_assert_int_eq(res.bits[0], 400);
  ck_assert_int_eq(res.bits[1], 0);
  ck_assert_int_eq(res.bits[2], 0);
  ck_assert_int_eq(res.bits[3], 0b00011010 << 16);
}
END_TEST

START_TEST(mul_floatXsmall) {
  s21_decimal num1 = {{41152263, 0, 0, 1048576}};
  s21_decimal num2 = {{3, 0, 0, 917504}};
  s21_decimal res = {{0, 0, 0, 0}};
  int status = s21_mul(num1, num2, &res);
  ck_assert_int_eq(status, 0);
  ck_assert_int_eq(res.bits[0], 1234568);
  ck_assert_int_eq(res.bits[1], 0);
  ck_assert_int_eq(res.bits[2], 0);
  ck_assert_int_eq(res.bits[3], 1835008);
}
END_TEST

START_TEST(mul_smallXsmall) {
  s21_decimal num1 = {{4, 0, 0, 1048576}};
  s21_decimal num2 = {{3, 0, 0, 1048576}};
  s21_decimal res = {{0, 0, 0, 0}};
  int status = s21_mul(num1, num2, &res);
  ck_assert_int_eq(status, 2);
  ck_assert_int_eq(res.bits[0], 0);
  ck_assert_int_eq(res.bits[1], 0);
  ck_assert_int_eq(res.bits[2], 0);
  ck_assert_int_eq(res.bits[3], 0);
}
END_TEST

START_TEST(mul_bigXsmall) {
  s21_decimal num1 = {{0, 0, 1234000000, 393216}};
  s21_decimal num2 = {{1, 0, 0, 1835008}};
  s21_decimal res = {{0, 0, 0, 0}};
  int status = s21_mul(num1, num2, &res);
  ck_assert_int_eq(status, 0);
  ck_assert_int_eq(res.bits[0], 0);
  ck_assert_int_eq(res.bits[1], 0);
  ck_assert_int_eq(res.bits[2], 1234);
  ck_assert_int_eq(res.bits[3], 1835008);
}
END_TEST

START_TEST(mul_error) {
  s21_decimal src1 = {{0, 0, 0, 0}};
  s21_decimal src2 = {{0, 0, 0, 0}};
  s21_decimal *result_our = NULL;
  int val = s21_mul(src1, src2, result_our);
  ck_assert_int_eq(val, S21_ERROR);
}
END_TEST

TCase *tests_s21_mul(void) {
  TCase *tcase = tcase_create(TCASE_NAME);

  tcase_add_test(tcase, mul_2x2);
  tcase_add_test(tcase, mul_24xminus6);
  tcase_add_test(tcase, mul_minus500xminus3);
  tcase_add_test(tcase, mul_minus2x5);
  tcase_add_test(tcase, mul_3x0point256);
  tcase_add_test(tcase, mul_9point213658xminus169point312846);
  tcase_add_test(tcase, mul_3point21x30point336);
  tcase_add_test(tcase, mul_minus3point2xminus0point3);
  tcase_add_test(tcase, mul_zero);
  tcase_add_test(tcase, mul_bigXfloat);
  tcase_add_test(tcase, mul_overflow_positive);
  tcase_add_test(tcase, mul_overflow_negative);
  tcase_add_test(tcase, mul_minusBigXminusBig);
  tcase_add_test(tcase, mul_normalXsmall);
  tcase_add_test(tcase, mul_floatXsmall);
  tcase_add_test(tcase, mul_smallXsmall);
  tcase_add_test(tcase, mul_bigXsmall);
  tcase_add_test(tcase, mul_error);

  return tcase;
}
