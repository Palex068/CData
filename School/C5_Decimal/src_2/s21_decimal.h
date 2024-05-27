#ifndef S21_DECIMAL_H_SENTRY
#define S21_DECIMAL_H_SENTRY

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int bits[4];
} s21_decimal;

typedef enum { bitzero, bitone } BIT_STATE;

typedef struct {
  s21_decimal *result;
  s21_decimal value_1;
  s21_decimal value_2;
  s21_decimal *remainder;
  int len1, len2, sign, scale;
} AR_HELPER;

#define BITSIZE32 32
#define BITSIZE96 96
#define BIT1 0
#define BIT32 31
#define BIT64 63
#define BIT96 95
#define BIT128 127
#define BIT127 126
#define BIT16SCALE 112
#define BIT23SCALE 119
#define NEGATIVE 2147483648
#define POSITIVE 0

#define SCALE(x) (x * 65536) // Степень x от 0 до 28

void print_binary(int num);
void print_decimal(s21_decimal dec);
void set_bit(s21_decimal *dec, int bit_num, BIT_STATE bit_state);
void toggle_bit(s21_decimal *dec, int bit_num);
void decimal_clear(s21_decimal *dec);
BIT_STATE get_bit(s21_decimal dec, int bit_num);
int decimal_cmp(s21_decimal value_1, s21_decimal value_2);
int decimal_bit_eq(s21_decimal value_1, s21_decimal value_2, int high_bit,
                   int low_bit);
int decimal_len(s21_decimal dec);
int decimal_is_null(s21_decimal *dec);
int get_sign(s21_decimal dec);
void set_negative(s21_decimal *dec);
void set_positive(s21_decimal *dec);
int decimal_rotate(s21_decimal *value_1, s21_decimal *value_2);
int decimal_shift(s21_decimal *dec, int shift);
unsigned int bin2dec(s21_decimal dec, int high_bit, int low_bit);
int bin2dec_last(s21_decimal dec);
int get_scale(s21_decimal dec);
void set_scale(s21_decimal *dec, int scale);
void scale_normalize(s21_decimal *value_1, s21_decimal *value_2,
                     s21_decimal *result);
int add_set_bit(s21_decimal *dec, int v1, int v2, int remainder, int i);
int sub_set_bit(s21_decimal *dec, int v1, int v2, int borrow, int i);
int mul_set_bit(AR_HELPER mul);
int div_set_bit(AR_HELPER div);
int div_bit_long_div(AR_HELPER div, int *s21_borrow, int i, s21_decimal tmp,
                     s21_decimal *tmpresult, int fract);
int div_equals(AR_HELPER h);
int div_by_zero(s21_decimal value_2);
void div_bank_rounding(AR_HELPER div, int overflow);
int div_rem_normalize(AR_HELPER div, int *overflow, int *scale,
                      s21_decimal *tmp_value_2);
AR_HELPER ar_cons(s21_decimal *r, s21_decimal v1, s21_decimal v2,
                  s21_decimal *rm, int l1, int l2, int si, int sc);

s21_decimal power10(int power);
void bank_rounding(s21_decimal *dec);
int scomp(long num);
int s21_exit_error(s21_decimal *dec);

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);

// int s21_is_less(s21_decimal, s21_decimal);
// int s21_is_less_or_equal(s21_decimal, s21_decimal);
// int s21_is_greater(s21_decimal, s21_decimal);
// int s21_is_greater_or_equal(s21_decimal, s21_decimal);
int s21_is_equal(s21_decimal, s21_decimal);
// int s21_is_not_equal(s21_decimal, s21_decimal);

int s21_from_int_to_decimal(int src, s21_decimal *dst);
// int s21_from_float_to_decimal(float src, s21_decimal *dst);
// int s21_from_decimal_to_int(s21_decimal src, int *dst);
// int s21_from_decimal_to_float(s21_decimal src, float *dst);

// int s21_floor(s21_decimal value, s21_decimal *result);
// int s21_round(s21_decimal value, s21_decimal *result);
// int s21_truncate(s21_decimal value, s21_decimal *result);
// int s21_negate(s21_decimal value, s21_decimal *result);

#endif