#include "test_me.h"

START_TEST(sscanf_spec_hi_dec_1) {
  char format[] = "%hi%hi%hi";
  char str[] = "123 +198 -87";
  unsigned short d1, d2;
  unsigned short q1, q2;
  unsigned short z1, z2;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_hi_dec_2) {
  char format[] = "%hi %hi %hi";
  char str[] = "123 +198 -87";
  unsigned short d1, d2;
  unsigned short q1, q2;
  unsigned short z1, z2;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_hi_dec_3) {
  char format[] = "%1hi %1hi %1hi";
  char str[] = "13 +137 -8";
  unsigned short d1, d2;
  unsigned short q1, q2;
  unsigned short z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_hi_dec_4) {
  char format[] = "%2hi %2hi %2hi";
  char str[] = "13 +137 -8";
  unsigned short d1, d2;
  unsigned short q1, q2;
  unsigned short z1, z2;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_hi_dec_5) {
  char format[] = "%3hi %3hi %3hi";
  char str[] = "13 +137 -8";
  unsigned short d1, d2;
  unsigned short q1, q2;
  unsigned short z1, z2;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_hi_dec_6) {
  char format[] = "%30hi %24hi %21hi";
  char str[] = "13 +137 -8";
  unsigned short d1, d2;
  unsigned short q1, q2;
  unsigned short z1, z2;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_hi_dec_7) {
  char format[] = "%hi %hi %hi %hi";
  char str[] = "2147483647 +2147483648 -2147483648 -2147483649";
  unsigned short d1, d2;
  unsigned short q1, q2;
  unsigned short z1, z2;
  unsigned short w1, w2;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1, &w1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2, &w2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
  ck_assert_uint_eq(w1, w2);
}
END_TEST

START_TEST(sscanf_spec_hi_dec_8) {
  char format[] = "%hi %hi %hi %hi";
  char str[] =
      "9223372036854775807 +9223372036854775808 -9223372036854775808 "
      "-9223372036854775809";
  unsigned short d1, d2;
  unsigned short q1, q2;
  unsigned short z1, z2;
  unsigned short w1, w2;
  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1, &w1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2, &w2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
  ck_assert_uint_eq(w1, w2);
}
END_TEST

START_TEST(sscanf_spec_hi_oct_1) {
  char format[] = "%hi%hi%hi";
  char str[] = "0123 +0198 -087";
  unsigned short d1, d2;
  unsigned short q1, q2;
  unsigned short z1, z2;
  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_hi_oct_2) {
  char format[] = "%hi %hi %hi";
  char str[] = "0123 +0198 -087";
  unsigned short d1, d2;
  unsigned short q1, q2;
  unsigned short z1, z2;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_hi_oct_3) {
  char format[] = "%1hi %1hi %1hi";
  char str[] = "013 +0137 -08";
  unsigned short d1, d2;
  unsigned short q1, q2;
  unsigned short z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_hi_oct_4) {
  char format[] = "%2hi %2hi %2hi";
  char str[] = "013 +0137 -08";
  unsigned short d1, d2;
  unsigned short q1, q2;
  unsigned short z1, z2;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_hi_oct_5) {
  char format[] = "%3hi %3hi %3hi";
  char str[] = "013 +0137 -08";
  unsigned short d1, d2;
  unsigned short q1, q2;
  unsigned short z1, z2;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_hi_oct_6) {
  char format[] = "%30hi %24hi %21hi";
  char str[] = "013 +0137 -08";
  unsigned short d1, d2;
  unsigned short q1, q2;
  unsigned short z1, z2;
  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_hi_oct_7) {
  char format[] = "%hi %hi %hi %hi";
  char str[] = "037777777777 +040000000000 -040000000000 -040000000001";
  unsigned short d1, d2;
  unsigned short q1, q2;
  unsigned short z1, z2;
  unsigned short w1, w2;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1, &w1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2, &w2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
  ck_assert_uint_eq(w1, w2);
}
END_TEST

START_TEST(sscanf_spec_hi_oct_8) {
  char format[] = "%hi %hi %hi %hi";
  char str[] =
      "01777777777777777777777 +02000000000000000000000 "
      "-02000000000000000000000 -02000000000000000000001";
  unsigned short d1, d2;
  unsigned short q1, q2;
  unsigned short z1, z2;
  unsigned short w1, w2;
  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1, &w1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2, &w2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
  ck_assert_uint_eq(w1, w2);
}
END_TEST

START_TEST(sscanf_spec_hi_hex_1) {
  char format[] = "%hi%hi%hi";
  char str[] = "0x123 +0X198 -0x87";
  unsigned short d1, d2;
  unsigned short q1, q2;
  unsigned short z1, z2;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_hi_hex_2) {
  char format[] = "%hi %hi %hi";
  char str[] = "0X123 +0x198 -0X87";
  unsigned short d1, d2;
  unsigned short q1, q2;
  unsigned short z1, z2;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_hi_hex_3) {
  char format[] = "%1hi %1hi %1hi";
  char str[] = "0X13 +0x137 -0x8";
  unsigned short d1 = 0, d2 = 0;
  unsigned short q1 = 0, q2 = 0;
  unsigned short z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_hi_hex_5) {
  char format[] = "%3hi %3hi %3hi";
  char str[] = "0x13 +0x137 -0x8";
  unsigned short d1, d2;
  unsigned short q1, q2;
  unsigned short z1, z2;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_hi_hex_6) {
  char format[] = "%30hi %24hi %21hi";
  char str[] = "0x13 +0x1a -0x8";
  unsigned short d1, d2;
  unsigned short q1, q2;
  unsigned short z1, z2;
  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_hi_hex_7) {
  char format[] = "%hi %hi %hi %hi";
  char str[] = "0xffffffff +0xffffffeab -0xFfFfffFf -0x39cdb3aa";
  unsigned short d1, d2;
  unsigned short q1, q2;
  unsigned short z1, z2;
  unsigned short w1, w2;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1, &w1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2, &w2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
  ck_assert_uint_eq(w1, w2);
}
END_TEST

START_TEST(sscanf_spec_hi_hex_8) {
  char format[] = "%hi %hi %hi %hi";
  char str[] =
      "0xFFFFFFFFFFFFFFFF 0x8000000000000000 -0xFFFFFFFFFFFFFFFF "
      "-0x348923848239742389328";
  unsigned short d1, d2;
  unsigned short q1, q2;
  unsigned short z1, z2;
  unsigned short w1, w2;
  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1, &w1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2, &w2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
  ck_assert_uint_eq(w1, w2);
}
END_TEST

START_TEST(sscanf_spec_i_dec_1) {
  char format[] = "%i%i%i";
  char str[] = "123 +198 -87";
  unsigned int d1, d2;
  unsigned int q1, q2;
  unsigned int z1, z2;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_i_dec_2) {
  char format[] = "%i %i %i";
  char str[] = "123 +198 -87";
  unsigned int d1, d2;
  unsigned int q1, q2;
  unsigned int z1, z2;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_i_dec_3) {
  char format[] = "%1i %1i %1i";
  char str[] = "13 +137 -8";
  unsigned int d1, d2;
  unsigned int q1, q2;
  unsigned int z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_i_dec_4) {
  char format[] = "%2i %2i %2i";
  char str[] = "13 +137 -8";
  unsigned int d1, d2;
  unsigned int q1, q2;
  unsigned int z1, z2;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_i_dec_5) {
  char format[] = "%3i %3i %3i";
  char str[] = "13 +137 -8";
  unsigned int d1, d2;
  unsigned int q1, q2;
  unsigned int z1, z2;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_i_dec_6) {
  char format[] = "%30i %24i %21i";
  char str[] = "13 +137 -8";
  unsigned int d1, d2;
  unsigned int q1, q2;
  unsigned int z1, z2;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_i_dec_7) {
  char format[] = "%i %i %i %i";
  char str[] = "2147483647 +2147483648 -2147483648 -2147483649";
  unsigned int d1, d2;
  unsigned int q1, q2;
  unsigned int z1, z2;
  unsigned int w1, w2;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1, &w1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2, &w2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
  ck_assert_uint_eq(w1, w2);
}
END_TEST

START_TEST(sscanf_spec_i_dec_8) {
  char format[] = "%i %i %i %i";
  char str[] =
      "9223372036854775807 +9223372036854775808 -9223372036854775808 "
      "-9223372036854775809";
  unsigned int d1, d2;
  unsigned int q1, q2;
  unsigned int z1, z2;
  unsigned int w1, w2;
  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1, &w1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2, &w2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
  ck_assert_uint_eq(w1, w2);
}
END_TEST

START_TEST(sscanf_spec_i_oct_1) {
  char format[] = "%i%i%i";
  char str[] = "0123 +0198 -087";
  unsigned int d1, d2;
  unsigned int q1, q2;
  unsigned int z1, z2;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_i_oct_2) {
  char format[] = "%i %i %i";
  char str[] = "0123 +0198 -087";
  unsigned int d1, d2;
  unsigned int q1, q2;
  unsigned int z1, z2;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_i_oct_3) {
  char format[] = "%1i %1i %1i";
  char str[] = "013 +0137 -08";
  unsigned int d1, d2;
  unsigned int q1, q2;
  unsigned int z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_i_oct_4) {
  char format[] = "%2i %2i %2i";
  char str[] = "013 +0137 -08";
  unsigned int d1, d2;
  unsigned int q1, q2;
  unsigned int z1, z2;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_i_oct_5) {
  char format[] = "%3i %3i %3i";
  char str[] = "013 +0137 -08";
  unsigned int d1, d2;
  unsigned int q1, q2;
  unsigned int z1, z2;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_i_oct_6) {
  char format[] = "%30i %24i %21i";
  char str[] = "013 +0137 -08";
  unsigned int d1, d2;
  unsigned int q1, q2;
  unsigned int z1, z2;
  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_i_oct_7) {
  char format[] = "%i %i %i %i";
  char str[] = "037777777777 +040000000000 -040000000000 -040000000001";
  unsigned int d1, d2;
  unsigned int q1, q2;
  unsigned int z1, z2;
  unsigned int w1, w2;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1, &w1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2, &w2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
  ck_assert_uint_eq(w1, w2);
}
END_TEST

START_TEST(sscanf_spec_i_oct_8) {
  char format[] = "%i %i %i %i";
  char str[] =
      "01777777777777777777777 +02000000000000000000000 "
      "-02000000000000000000000 -02000000000000000000001";
  unsigned int d1, d2;
  unsigned int q1, q2;
  unsigned int z1, z2;
  unsigned int w1, w2;
  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1, &w1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2, &w2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
  ck_assert_uint_eq(w1, w2);
}
END_TEST

START_TEST(sscanf_spec_i_hex_1) {
  char format[] = "%i%i%i";
  char str[] = "0x123 +0X198 -0x87";
  unsigned int d1, d2;
  unsigned int q1, q2;
  unsigned int z1, z2;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_i_hex_2) {
  char format[] = "%i %i %i";
  char str[] = "0X123 +0x198 -0X87";
  unsigned int d1, d2;
  unsigned int q1, q2;
  unsigned int z1, z2;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_i_hex_3) {
  char format[] = "%1i %1i %1i";
  char str[] = "0X13 +0x137 -0x8";
  unsigned int d1 = 0, d2 = 0;
  unsigned int q1 = 0, q2 = 0;
  unsigned int z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_i_hex_5) {
  char format[] = "%3i %3i %3i";
  char str[] = "0x13 +0x137 -0x8";
  unsigned int d1, d2;
  unsigned int q1, q2;
  unsigned int z1, z2;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_i_hex_6) {
  char format[] = "%30i %24i %21i";
  char str[] = "0x13 +0x1a -0x8";
  unsigned int d1, d2;
  unsigned int q1, q2;
  unsigned int z1, z2;
  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_i_hex_7) {
  char format[] = "%i %i %i %i";
  char str[] = "0xffffffff +0xffffffeab -0xFfFfffFf -0x39cdb3aa";
  unsigned int d1, d2;
  unsigned int q1, q2;
  unsigned int z1, z2;
  unsigned int w1, w2;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1, &w1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2, &w2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
  ck_assert_uint_eq(w1, w2);
}
END_TEST

START_TEST(sscanf_spec_i_hex_8) {
  char format[] = "%i %i %i %i";
  char str[] =
      "0xFFFFFFFFFFFFFFFF 0x8000000000000000 -0xFFFFFFFFFFFFFFFF "
      "-0x348923848239742389328";
  unsigned int d1, d2;
  unsigned int q1, q2;
  unsigned int z1, z2;
  unsigned int w1, w2;
  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1, &w1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2, &w2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
  ck_assert_uint_eq(w1, w2);
}
END_TEST

START_TEST(sscanf_spec_li_dec_1) {
  char format[] = "%li%li%li";
  char str[] = "123 +198 -87";
  unsigned long int d1, d2;
  unsigned long int q1, q2;
  unsigned long int z1, z2;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_li_dec_2) {
  char format[] = "%li %li %li";
  char str[] = "123 +198 -87";
  unsigned long int d1, d2;
  unsigned long int q1, q2;
  unsigned long int z1, z2;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_li_dec_3) {
  char format[] = "%1li %1li %1li";
  char str[] = "13 +137 -8";
  unsigned long int d1, d2;
  unsigned long int q1, q2;
  unsigned long int z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_li_dec_4) {
  char format[] = "%2li %2li %2li";
  char str[] = "13 +137 -8";
  unsigned long int d1, d2;
  unsigned long int q1, q2;
  unsigned long int z1, z2;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_li_dec_5) {
  char format[] = "%3li %3li %3li";
  char str[] = "13 +137 -8";
  unsigned long int d1, d2;
  unsigned long int q1, q2;
  unsigned long int z1, z2;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_li_dec_6) {
  char format[] = "%30li %24li %21li";
  char str[] = "13 +137 -8";
  unsigned long int d1, d2;
  unsigned long int q1, q2;
  unsigned long int z1, z2;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_li_dec_7) {
  char format[] = "%li %li %li %li";
  char str[] = "2147483647 +2147483648 -2147483648 -2147483649";
  unsigned long int d1, d2;
  unsigned long int q1, q2;
  unsigned long int z1, z2;
  unsigned long int w1, w2;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1, &w1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2, &w2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
  ck_assert_uint_eq(w1, w2);
}
END_TEST

START_TEST(sscanf_spec_li_dec_8) {
  char format[] = "%li %li %li %li";
  char str[] =
      "9223372036854775807 +9223372036854775808 -9223372036854775808 "
      "-9223372036854775809";
  unsigned long int d1, d2;
  unsigned long int q1, q2;
  unsigned long int z1, z2;
  unsigned long int w1, w2;
  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1, &w1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2, &w2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
  ck_assert_uint_eq(w1, w2);
}
END_TEST

START_TEST(sscanf_spec_li_oct_1) {
  char format[] = "%li%li%li";
  char str[] = "0123 +0198 -087";
  unsigned long int d1, d2;
  unsigned long int q1, q2;
  unsigned long int z1, z2;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_li_oct_2) {
  char format[] = "%li %li %li";
  char str[] = "0123 +0198 -087";
  unsigned long int d1, d2;
  unsigned long int q1, q2;
  unsigned long int z1, z2;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_li_oct_3) {
  char format[] = "%1li %1li %1li";
  char str[] = "013 +0137 -08";
  unsigned long int d1, d2;
  unsigned long int q1, q2;
  unsigned long int z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_li_oct_4) {
  char format[] = "%2li %2li %2li";
  char str[] = "013 +0137 -08";
  unsigned long int d1, d2;
  unsigned long int q1, q2;
  unsigned long int z1, z2;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_li_oct_5) {
  char format[] = "%3li %3li %3li";
  char str[] = "013 +0137 -08";
  unsigned long int d1, d2;
  unsigned long int q1, q2;
  unsigned long int z1, z2;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_li_oct_6) {
  char format[] = "%30li %24li %21li";
  char str[] = "013 +0137 -08";
  unsigned long int d1, d2;
  unsigned long int q1, q2;
  unsigned long int z1, z2;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_li_oct_7) {
  char format[] = "%li %li %li %li";
  char str[] = "037777777777 +040000000000 -040000000000 -040000000001";
  unsigned long int d1, d2;
  unsigned long int q1, q2;
  unsigned long int z1, z2;
  unsigned long int w1, w2;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1, &w1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2, &w2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
  ck_assert_uint_eq(w1, w2);
}
END_TEST

START_TEST(sscanf_spec_li_oct_8) {
  char format[] = "%li %li %li %li";
  char str[] =
      "01777777777777777777777 +02000000000000000000000 "
      "-02000000000000000000000 -02000000000000000000001";
  unsigned long int d1, d2;
  unsigned long int q1, q2;
  unsigned long int z1, z2;
  unsigned long int w1, w2;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1, &w1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2, &w2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
  ck_assert_uint_eq(w1, w2);
}
END_TEST

START_TEST(sscanf_spec_li_hex_1) {
  char format[] = "%li%li%li";
  char str[] = "0x123 +0X198 -0x87";
  unsigned long int d1, d2;
  unsigned long int q1, q2;
  unsigned long int z1, z2;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_li_hex_2) {
  char format[] = "%li %li %li";
  char str[] = "0X123 +0x198 -0X87";
  unsigned long int d1, d2;
  unsigned long int q1, q2;
  unsigned long int z1, z2;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_li_hex_3) {
  char format[] = "%1li %1li %1li";
  char str[] = "0X13 +0x137 -0x8";
  unsigned long int d1 = 0, d2 = 0;
  unsigned long int q1 = 0, q2 = 0;
  unsigned long int z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_li_hex_5) {
  char format[] = "%3li %3li %3li";
  char str[] = "0x13 +0x137 -0x8";
  unsigned long int d1, d2;
  unsigned long int q1, q2;
  unsigned long int z1, z2;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_li_hex_6) {
  char format[] = "%30li %24li %21li";
  char str[] = "0x13 +0x1a -0x8";
  unsigned long int d1, d2;
  unsigned long int q1, q2;
  unsigned long int z1, z2;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_li_hex_7) {
  char format[] = "%li %li %li %li";
  char str[] = "0xffffffff +0xffffffeab -0xFfFfffFf -0x39cdb3aa";
  unsigned long int d1, d2;
  unsigned long int q1, q2;
  unsigned long int z1, z2;
  unsigned long int w1, w2;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1, &w1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2, &w2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
  ck_assert_uint_eq(w1, w2);
}
END_TEST

START_TEST(sscanf_spec_li_hex_8) {
  char format[] = "%li %li %li %li";
  char str[] =
      "0xFFFFFFFFFFFFFFFF 0x8000000000000000 -0xFFFFFFFFFFFFFFFF "
      "-0x348923848239742389328";
  unsigned long int d1, d2;
  unsigned long int q1, q2;
  unsigned long int z1, z2;
  unsigned long int w1, w2;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1, &w1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2, &w2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
  ck_assert_uint_eq(w1, w2);
}
END_TEST

Suite *test_sscanf_i(void) {
  Suite *s = suite_create("\033[45m-=S21_SSCANF_I=-\033[0m");
  TCase *tc = tcase_create("sscanf_tc");

  tcase_add_test(tc, sscanf_spec_i_dec_1);
  tcase_add_test(tc, sscanf_spec_i_dec_2);
  tcase_add_test(tc, sscanf_spec_i_dec_3);
  tcase_add_test(tc, sscanf_spec_i_dec_4);
  tcase_add_test(tc, sscanf_spec_i_dec_5);
  tcase_add_test(tc, sscanf_spec_i_dec_6);
  tcase_add_test(tc, sscanf_spec_i_dec_7);
  tcase_add_test(tc, sscanf_spec_i_dec_8);

  tcase_add_test(tc, sscanf_spec_i_oct_1);
  tcase_add_test(tc, sscanf_spec_i_oct_2);
  tcase_add_test(tc, sscanf_spec_i_oct_3);
  tcase_add_test(tc, sscanf_spec_i_oct_4);
  tcase_add_test(tc, sscanf_spec_i_oct_5);
  tcase_add_test(tc, sscanf_spec_i_oct_6);
  tcase_add_test(tc, sscanf_spec_i_oct_7);
  tcase_add_test(tc, sscanf_spec_i_oct_8);

  tcase_add_test(tc, sscanf_spec_i_hex_1);
  tcase_add_test(tc, sscanf_spec_i_hex_2);
  tcase_add_test(tc, sscanf_spec_i_hex_3);
  tcase_add_test(tc, sscanf_spec_i_hex_5);
  tcase_add_test(tc, sscanf_spec_i_hex_6);
  tcase_add_test(tc, sscanf_spec_i_hex_7);
  tcase_add_test(tc, sscanf_spec_i_hex_8);

  tcase_add_test(tc, sscanf_spec_hi_dec_1);
  tcase_add_test(tc, sscanf_spec_hi_dec_2);
  tcase_add_test(tc, sscanf_spec_hi_dec_3);
  tcase_add_test(tc, sscanf_spec_hi_dec_4);
  tcase_add_test(tc, sscanf_spec_hi_dec_5);
  tcase_add_test(tc, sscanf_spec_hi_dec_6);
  tcase_add_test(tc, sscanf_spec_hi_dec_7);
  tcase_add_test(tc, sscanf_spec_hi_dec_8);

  tcase_add_test(tc, sscanf_spec_hi_oct_1);
  tcase_add_test(tc, sscanf_spec_hi_oct_2);
  tcase_add_test(tc, sscanf_spec_hi_oct_3);
  tcase_add_test(tc, sscanf_spec_hi_oct_4);
  tcase_add_test(tc, sscanf_spec_hi_oct_5);
  tcase_add_test(tc, sscanf_spec_hi_oct_6);
  tcase_add_test(tc, sscanf_spec_hi_oct_7);
  tcase_add_test(tc, sscanf_spec_hi_oct_8);

  tcase_add_test(tc, sscanf_spec_hi_hex_1);
  tcase_add_test(tc, sscanf_spec_hi_hex_2);
  tcase_add_test(tc, sscanf_spec_hi_hex_3);
  tcase_add_test(tc, sscanf_spec_hi_hex_5);
  tcase_add_test(tc, sscanf_spec_hi_hex_6);
  tcase_add_test(tc, sscanf_spec_hi_hex_7);
  tcase_add_test(tc, sscanf_spec_hi_hex_8);

  tcase_add_test(tc, sscanf_spec_li_dec_1);
  tcase_add_test(tc, sscanf_spec_li_dec_2);
  tcase_add_test(tc, sscanf_spec_li_dec_3);
  tcase_add_test(tc, sscanf_spec_li_dec_4);
  tcase_add_test(tc, sscanf_spec_li_dec_5);
  tcase_add_test(tc, sscanf_spec_li_dec_6);
  tcase_add_test(tc, sscanf_spec_li_dec_7);
  tcase_add_test(tc, sscanf_spec_li_dec_8);

  tcase_add_test(tc, sscanf_spec_li_oct_1);
  tcase_add_test(tc, sscanf_spec_li_oct_2);
  tcase_add_test(tc, sscanf_spec_li_oct_3);
  tcase_add_test(tc, sscanf_spec_li_oct_4);
  tcase_add_test(tc, sscanf_spec_li_oct_5);
  tcase_add_test(tc, sscanf_spec_li_oct_6);
  tcase_add_test(tc, sscanf_spec_li_oct_7);
  tcase_add_test(tc, sscanf_spec_li_oct_8);

  tcase_add_test(tc, sscanf_spec_li_hex_1);
  tcase_add_test(tc, sscanf_spec_li_hex_2);
  tcase_add_test(tc, sscanf_spec_li_hex_3);
  tcase_add_test(tc, sscanf_spec_li_hex_5);
  tcase_add_test(tc, sscanf_spec_li_hex_6);
  tcase_add_test(tc, sscanf_spec_li_hex_7);
  tcase_add_test(tc, sscanf_spec_li_hex_8);

  suite_add_tcase(s, tc);
  return s;
}
