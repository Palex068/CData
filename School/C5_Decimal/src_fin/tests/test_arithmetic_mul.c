#include "test_main.h"

START_TEST(s21_mul_0_simple) {
  s21_decimal dec1 = {{2, 0, 0, POSITIVE}};
  s21_decimal dec2 = {{268435456, 1042612833, 542101086, POSITIVE}};  // 10^28
  s21_decimal res = {0};
  s21_decimal answer = {{536870912, 2085225666, 1084202172, POSITIVE}};  // 2e28
  int error = s21_mul(dec1, dec2, &res);
  ck_assert_int_eq(error, 0);
  for (int i = 0; i <= 3; i++) ck_assert_int_eq(res.bits[i], answer.bits[i]);
}
END_TEST

START_TEST(s21_mul_1_simple) {
  s21_decimal dec1 = {{9, 0, 0, POSITIVE}};
  s21_decimal dec2 = {{10, 0, 0, POSITIVE}};
  s21_decimal res = {0};
  s21_decimal answer = {{90, 0, 0, POSITIVE}};
  int error = s21_mul(dec1, dec2, &res);
  ck_assert_int_eq(error, 0);
  for (int i = 0; i <= 3; i++) ck_assert_int_eq(res.bits[i], answer.bits[i]);
}
END_TEST

START_TEST(s21_mul_2_simple) {
  s21_decimal dec1 = {{51, 0, 0, scomp(NEGATIVE)}};
  s21_decimal dec2 = {{22, 0, 0, POSITIVE}};
  s21_decimal res = {0};
  s21_decimal answer = {{1122, 0, 0, scomp(NEGATIVE)}};
  int error = s21_mul(dec1, dec2, &res);
  ck_assert_int_eq(error, 0);
  for (int i = 0; i <= 3; i++) ck_assert_int_eq(res.bits[i], answer.bits[i]);
}
END_TEST

START_TEST(s21_mul_3_simple) {
  s21_decimal dec1 = {{65, 0, 0, POSITIVE}};
  s21_decimal dec2 = {
      {1057222719, scomp(4030661616), 66076419, scomp(NEGATIVE)}};
  s21_decimal res = {0};
  s21_decimal answer = {{-1, -1, -1, scomp(NEGATIVE)}};
  int error = s21_mul(dec1, dec2, &res);
  ck_assert_int_eq(error, 0);
  for (int i = 0; i <= 3; i++) ck_assert_int_eq(res.bits[i], answer.bits[i]);
}
END_TEST

START_TEST(s21_mul_4_scale) {
  s21_decimal dec1 = {{14, 0, 0, POSITIVE + SCALE(2)}};
  s21_decimal dec2 = {{2, 0, 0, POSITIVE}};
  s21_decimal res = {0};
  s21_decimal answer = {{28, 0, 0, POSITIVE + SCALE(2)}};
  int error = s21_mul(dec1, dec2, &res);
  ck_assert_int_eq(error, 0);
  for (int i = 0; i <= 3; i++) ck_assert_int_eq(res.bits[i], answer.bits[i]);
}
END_TEST

START_TEST(s21_mul_5_scale) {
  s21_decimal dec1 = {{100, 0, 0, POSITIVE + SCALE(14)}};
  s21_decimal dec2 = {{2, 0, 0, POSITIVE + SCALE(14)}};
  s21_decimal res = {0};
  s21_decimal answer = {{200, 0, 0, POSITIVE + SCALE(28)}};
  int error = s21_mul(dec1, dec2, &res);
  ck_assert_int_eq(error, 0);
  for (int i = 0; i <= 3; i++) ck_assert_int_eq(res.bits[i], answer.bits[i]);
}
END_TEST

START_TEST(s21_mul_6_scale) {
  s21_decimal dec1 = {{5, 0, 0, POSITIVE + SCALE(15)}};
  s21_decimal dec2 = {{3, 0, 0, POSITIVE + SCALE(14)}};
  s21_decimal res = {0};
  s21_decimal answer = {{2, 0, 0, POSITIVE + SCALE(28)}};
  int error = s21_mul(dec1, dec2, &res);
  ck_assert_int_eq(error, 0);
  for (int i = 0; i <= 3; i++) ck_assert_int_eq(res.bits[i], answer.bits[i]);
}
END_TEST

START_TEST(s21_mul_7_error) {
  s21_decimal dec1 = {{2, 0, 0, POSITIVE + SCALE(0)}};
  s21_decimal dec2 = {{-1, -1, -1, POSITIVE}};
  s21_decimal res = {0};
  s21_decimal answer = {{0, 0, 0, 0}};
  int error = s21_mul(dec1, dec2, &res);
  ck_assert_int_eq(error, 1);
  for (int i = 0; i <= 3; i++) ck_assert_int_eq(res.bits[i], answer.bits[i]);
}
END_TEST

START_TEST(s21_mul_8_simple) {
  s21_decimal dec1 = {{2, 0, 0, 0}};
  s21_decimal dec2 = {{2, 0, 0, 0}};
  s21_decimal res = {{0, 0, 0, 0}};
  int error = s21_mul(dec1, dec2, &res);
  ck_assert_int_eq(error, 0);
  ck_assert_int_eq(res.bits[0], 4);
  ck_assert_int_eq(res.bits[1], 0);
  ck_assert_int_eq(res.bits[2], 0);
  ck_assert_int_eq(res.bits[3], 0);
}
END_TEST

START_TEST(s21_mul_9_simple) {
  s21_decimal dec1 = {{24, 0, 0, 0}};
  s21_decimal dec2 = {{6, 0, 0, scomp(scomp(NEGATIVE))}};
  s21_decimal res = {{0, 0, 0, 0}};
  int error = s21_mul(dec1, dec2, &res);
  ck_assert_int_eq(error, 0);
  ck_assert_int_eq(res.bits[0], 144);
  ck_assert_int_eq(res.bits[1], 0);
  ck_assert_int_eq(res.bits[2], 0);
  ck_assert_int_eq(res.bits[3], scomp(scomp(NEGATIVE)));
}
END_TEST

START_TEST(s21_mul_10_simple) {
  s21_decimal dec1 = {{500, 0, 0, scomp(scomp(NEGATIVE))}};
  s21_decimal dec2 = {{3, 0, 0, scomp(scomp(NEGATIVE))}};
  s21_decimal res = {{0, 0, 0, 0}};
  int error = s21_mul(dec1, dec2, &res);
  ck_assert_int_eq(error, 0);
  ck_assert_int_eq(res.bits[0], 1500);
  ck_assert_int_eq(res.bits[1], 0);
  ck_assert_int_eq(res.bits[2], 0);
  ck_assert_int_eq(res.bits[3], 0);
}
END_TEST

START_TEST(s21_mul_11_simple) {
  s21_decimal dec1 = {{2, 0, 0, 0}};
  s21_decimal dec2 = {{5, 0, 0, scomp(scomp(NEGATIVE))}};
  s21_decimal res = {{0, 0, 0, 0}};
  int error = s21_mul(dec1, dec2, &res);
  ck_assert_int_eq(error, 0);
  ck_assert_int_eq(res.bits[0], 10);
  ck_assert_int_eq(res.bits[1], 0);
  ck_assert_int_eq(res.bits[2], 0);
  ck_assert_int_eq(res.bits[3], scomp(scomp(NEGATIVE)));
}
END_TEST

START_TEST(s21_mul_12_scale) {
  s21_decimal dec1 = {{3, 0, 0, 0}};
  s21_decimal dec2 = {{256, 0, 0, SCALE(4)}};
  s21_decimal res = {{0, 0, 0, 0}};
  int error = s21_mul(dec1, dec2, &res);
  ck_assert_int_eq(error, 0);
  ck_assert_int_eq(res.bits[0], 768);
  ck_assert_int_eq(res.bits[1], 0);
  ck_assert_int_eq(res.bits[2], 0);
  ck_assert_int_eq(res.bits[3], SCALE(4));
}
END_TEST

START_TEST(s21_mul_13_scale) {
  s21_decimal dec1 = {{9213658, 0, 0, SCALE(6)}};
  s21_decimal dec2 = {{169312846, 0, 0, scomp(scomp(NEGATIVE) + SCALE(6))}};
  s21_decimal res = {{0, 0, 0, 0}};
  int error = s21_mul(dec1, dec2, &res);
  ck_assert_int_eq(error, 0);
  ck_assert_int_eq(res.bits[0], -1593398676);
  ck_assert_int_eq(res.bits[1], 363213);
  ck_assert_int_eq(res.bits[2], 0);
  ck_assert_int_eq(res.bits[3], scomp(scomp(NEGATIVE) + SCALE(12)));
}
END_TEST

START_TEST(s21_mul_14_scale) {
  s21_decimal dec1 = {{321, 0, 0, SCALE(2)}};
  s21_decimal dec2 = {{30336, 0, 0, SCALE(3)}};
  s21_decimal res = {{0, 0, 0, 0}};
  int error = s21_mul(dec1, dec2, &res);
  ck_assert_int_eq(error, 0);
  ck_assert_int_eq(res.bits[0], 9737856);
  ck_assert_int_eq(res.bits[1], 0);
  ck_assert_int_eq(res.bits[2], 0);
  ck_assert_int_eq(res.bits[3], SCALE(5));
}
END_TEST

START_TEST(s21_mul_15_scale) {
  s21_decimal dec1 = {{32, 0, 0, scomp(scomp(NEGATIVE) + SCALE(1))}};
  s21_decimal dec2 = {{3, 0, 0, scomp(scomp(NEGATIVE) + SCALE(1))}};
  s21_decimal res = {{0, 0, 0, 0}};
  int error = s21_mul(dec1, dec2, &res);
  ck_assert_int_eq(error, 0);
  ck_assert_int_eq(res.bits[0], 96);
  ck_assert_int_eq(res.bits[1], 0);
  ck_assert_int_eq(res.bits[2], 0);
  ck_assert_int_eq(res.bits[3], SCALE(2));
}
END_TEST

START_TEST(s21_mul_16_scale) {
  s21_decimal dec1 = {{32, 0, 0, scomp(scomp(NEGATIVE) + SCALE(1))}};
  s21_decimal dec2 = {{0, 0, 0, 0}};
  s21_decimal res = {{0, 0, 0, 0}};
  int error = s21_mul(dec1, dec2, &res);
  ck_assert_int_eq(error, 0);
  ck_assert_int_eq(res.bits[0], 0);
  ck_assert_int_eq(res.bits[1], 0);
  ck_assert_int_eq(res.bits[2], 0);
  ck_assert_int_eq(res.bits[3], 0);
}
END_TEST

START_TEST(s21_mul_17_scale) {
  s21_decimal dec1 = {{0, 0, 1, 0}};
  s21_decimal dec2 = {{256, 0, 0, SCALE(14)}};
  s21_decimal res = {{0, 0, 0, 0}};
  int error = s21_mul(dec1, dec2, &res);
  ck_assert_int_eq(error, 0);
  ck_assert_int_eq(res.bits[0], 0);
  ck_assert_int_eq(res.bits[1], 0);
  ck_assert_int_eq(res.bits[2], 256);
  ck_assert_int_eq(res.bits[3], SCALE(14));
}
END_TEST

START_TEST(s21_mul_18_error) {
  s21_decimal dec1 = {{0, 0, 5, 0}};
  s21_decimal dec2 = {{-1, 0, 0, 0}};
  s21_decimal res = {{0, 0, 0, 0}};
  int error = s21_mul(dec1, dec2, &res);
  ck_assert_int_eq(error, 1);
  ck_assert_int_eq(res.bits[0], 0);
  ck_assert_int_eq(res.bits[1], 0);
  ck_assert_int_eq(res.bits[2], 0);
  ck_assert_int_eq(res.bits[3], 0);
}
END_TEST

START_TEST(s21_mul_19_error) {
  s21_decimal dec1 = {{0, 0, 1, 0}};
  s21_decimal dec2 = {{0, -1, 0, scomp(scomp(NEGATIVE))}};
  s21_decimal res = {{0, 0, 0, 0}};
  int error = s21_mul(dec1, dec2, &res);
  ck_assert_int_eq(error, 2);
  ck_assert_int_eq(res.bits[0], 0);
  ck_assert_int_eq(res.bits[1], 0);
  ck_assert_int_eq(res.bits[2], 0);
  ck_assert_int_eq(res.bits[3], 0);
}
END_TEST

START_TEST(s21_mul_20_error) {
  s21_decimal dec1 = {{0, 0, 1, scomp(scomp(NEGATIVE))}};
  s21_decimal dec2 = {{0, -1, 0, scomp(scomp(NEGATIVE))}};
  s21_decimal res = {{0, 0, 0, 0}};
  int error = s21_mul(dec1, dec2, &res);
  ck_assert_int_eq(error, 1);
  ck_assert_int_eq(res.bits[0], 0);
  ck_assert_int_eq(res.bits[1], 0);
  ck_assert_int_eq(res.bits[2], 0);
  ck_assert_int_eq(res.bits[3], 0);
}
END_TEST

START_TEST(s21_mul_21_scale) {
  s21_decimal dec1 = {{200, 0, 0, 0}};
  s21_decimal dec2 = {{2, 0, 0, SCALE(26)}};
  s21_decimal res = {{0, 0, 0, 0}};
  int error = s21_mul(dec1, dec2, &res);
  ck_assert_int_eq(error, 0);
  ck_assert_int_eq(res.bits[0], 400);
  ck_assert_int_eq(res.bits[1], 0);
  ck_assert_int_eq(res.bits[2], 0);
  ck_assert_int_eq(res.bits[3], 0b00011010 << 16);
}
END_TEST

START_TEST(s21_mul_22_scale) {
  s21_decimal dec1 = {{41152263, 0, 0, SCALE(16)}};
  s21_decimal dec2 = {{3, 0, 0, SCALE(14)}};
  s21_decimal res = {{0, 0, 0, 0}};
  int error = s21_mul(dec1, dec2, &res);
  ck_assert_int_eq(error, 0);
  ck_assert_int_eq(res.bits[0], 1234568);
  ck_assert_int_eq(res.bits[1], 0);
  ck_assert_int_eq(res.bits[2], 0);
  ck_assert_int_eq(res.bits[3], SCALE(28));
}
END_TEST

START_TEST(s21_mul_23_scale) {
  s21_decimal dec1 = {{4, 0, 0, SCALE(16)}};
  s21_decimal dec2 = {{3, 0, 0, SCALE(16)}};
  s21_decimal res = {{0, 0, 0, 0}};
  int error = s21_mul(dec1, dec2, &res);
  ck_assert_int_eq(error, 2);
  ck_assert_int_eq(res.bits[0], 0);
  ck_assert_int_eq(res.bits[1], 0);
  ck_assert_int_eq(res.bits[2], 0);
  ck_assert_int_eq(res.bits[3], 0);
}
END_TEST

START_TEST(s21_mul_24_scale) {
  s21_decimal dec1 = {{0, 0, 1234000000, SCALE(6)}};
  s21_decimal dec2 = {{1, 0, 0, SCALE(28)}};
  s21_decimal res = {{0, 0, 0, 0}};
  int error = s21_mul(dec1, dec2, &res);
  ck_assert_int_eq(error, 0);
  ck_assert_int_eq(res.bits[0], 0);
  ck_assert_int_eq(res.bits[1], 0);
  ck_assert_int_eq(res.bits[2], 1234);
  ck_assert_int_eq(res.bits[3], SCALE(28));
}
END_TEST

START_TEST(s21_mul_25_scale) {
  s21_decimal dec1 = {{-1, -1, -1, SCALE(28)}};
  s21_decimal dec2 = {{-1, -1, -1, SCALE(28)}};
  s21_decimal res = {{0, 0, 0, 0}};
  int error = s21_mul(dec1, dec2, &res);
  ck_assert_int_eq(error, 0);
  ck_assert_int_eq(res.bits[0], 158262358);
  ck_assert_int_eq(res.bits[1], 899300158);
  ck_assert_int_eq(res.bits[2], scomp(3402823669));
  ck_assert_int_eq(res.bits[3], SCALE(27));
}

END_TEST
Suite *s21_arithmetic_mul_suite() {
  Suite *s = suite_create("s21_arithmetic_mul");
  TCase *tc = tcase_create("s21_decimal");
  suite_add_tcase(s, tc);
  tcase_add_test(tc, s21_mul_0_simple);
  tcase_add_test(tc, s21_mul_1_simple);
  tcase_add_test(tc, s21_mul_2_simple);
  tcase_add_test(tc, s21_mul_3_simple);
  tcase_add_test(tc, s21_mul_4_scale);
  tcase_add_test(tc, s21_mul_5_scale);
  tcase_add_test(tc, s21_mul_6_scale);
  tcase_add_test(tc, s21_mul_7_error);
  tcase_add_test(tc, s21_mul_8_simple);
  tcase_add_test(tc, s21_mul_9_simple);
  tcase_add_test(tc, s21_mul_10_simple);
  tcase_add_test(tc, s21_mul_11_simple);
  tcase_add_test(tc, s21_mul_12_scale);
  tcase_add_test(tc, s21_mul_13_scale);
  tcase_add_test(tc, s21_mul_14_scale);
  tcase_add_test(tc, s21_mul_15_scale);
  tcase_add_test(tc, s21_mul_16_scale);
  tcase_add_test(tc, s21_mul_17_scale);
  tcase_add_test(tc, s21_mul_18_error);
  tcase_add_test(tc, s21_mul_19_error);
  tcase_add_test(tc, s21_mul_20_error);
  tcase_add_test(tc, s21_mul_21_scale);
  tcase_add_test(tc, s21_mul_22_scale);
  tcase_add_test(tc, s21_mul_23_scale);
  tcase_add_test(tc, s21_mul_24_scale);
  tcase_add_test(tc, s21_mul_25_scale);

  return s;
}
