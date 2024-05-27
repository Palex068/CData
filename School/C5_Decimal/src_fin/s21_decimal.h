#ifndef S21_DECIMAL_H_SENTRY
#define S21_DECIMAL_H_SENTRY

#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int bits[4];
} s21_decimal;

typedef struct {
  int bits[8];
} ar_big_decimal;

typedef struct {
  unsigned int bits[8];
  int exp;           // сохранение степени
  int senior_bit;    // индекс старшего бита
  int sign;          // 1(-), 0(+)
  int digits_after;  // для банковского округления
} s21_big_decimal;

typedef enum { bitzero, bitone } BIT_STATE;

typedef struct {
  s21_decimal *result;
  s21_decimal value_1;
  s21_decimal value_2;
  s21_decimal *remainder;
  int len1, len2, sign, scale;
} AR_HELPER;

typedef struct {
  ar_big_decimal *result;
  ar_big_decimal value_1;
  ar_big_decimal value_2;
  ar_big_decimal *remainder;
  int len1, len2;
} AR_BIG_HELPER;

#define BITSIZE32 32
#define BITSIZE96 96
#define BITSIZE256 256  // big_dec
#define BIT1 0
#define BIT32 31
#define BIT64 63
#define BIT96 95
#define BIT128 127
#define BIT127 126
#define BIT256 255  // big_dec
#define BIT16SCALE 112
#define BIT23SCALE 119
#define NEGATIVE 2147483648
#define POSITIVE 0

#define SCALE(x) (x * 65536)  // Степень x от 0 до 28

/*-big_decimal-*/

#define S21_OK 0
#define S21_ERROR 1
#define S21_ERROR_TOO_BIG 1
#define S21_ERROR_TOO_SMALL 2
#define S21_ERROR_ZERO_DIVISION 3

#define BITS_IN_1_INT 32
#define BITS_IN_3_INT 96   // размер мантиссы децимала
#define BITS_IN_4_INT 128  // размер всего децимала
#define BITS_BIG_DECIMAL 256
#define EXP_SIZE 8  // количество битов отведенное под степень
#define EXP_MASK 0b11111111  // максимальное значение в пределах 8 бит (255)
#define MINUS 1

#define s21_INF __builtin_inf()
#define s21_NAN __builtin_nan("")
#define PRECISION 7

#define S21_MINUS 0b10000000000000000000000000000000
#define S21_PLUS 0b00000000000000000000000000000000

/*-arithmetic-*/

void set_bit(s21_decimal *dec, int bit_num, BIT_STATE bit_state);
void ar_big_set_bit(ar_big_decimal *dec, int bit_num, BIT_STATE bit_state);
void toggle_bit(s21_decimal *dec, int bit_num);
void big_toggle_bit(ar_big_decimal *dec, int bit_num);
void decimal_clear(s21_decimal *dec);
void big_decimal_clear(ar_big_decimal *dec);
BIT_STATE get_bit(s21_decimal dec, int bit_num);
BIT_STATE ar_big_get_bit(ar_big_decimal dec, int bit_num);
int big_decimal_cmp(ar_big_decimal value_1, ar_big_decimal value_2);
int decimal_bit_eq(s21_decimal value_1, s21_decimal value_2, int high_bit,
                   int low_bit);
int decimal_len(s21_decimal dec);
int big_decimal_len(ar_big_decimal dec);
int decimal_is_null(s21_decimal *dec);
int big_decimal_is_null(ar_big_decimal *dec);
int get_sign(s21_decimal dec);
void set_negative(s21_decimal *dec);
void set_positive(s21_decimal *dec);
int decimal_rotate(s21_decimal *value_1, s21_decimal *value_2);
int big_decimal_rotate(ar_big_decimal *value_1, ar_big_decimal *value_2);
int big_decimal_shift(ar_big_decimal *dec, int shift);
unsigned int bin2dec(s21_decimal dec, int high_bit, int low_bit);
int get_scale(s21_decimal dec);
void set_scale(s21_decimal *dec, int scale);
int big_scale_normalize(ar_big_decimal *value_1, ar_big_decimal *value_2,
                        int sc1, int sc2);
void big_long_add(ar_big_decimal value_1, ar_big_decimal value_2,
                  ar_big_decimal *result);
int add_big_set_bit(ar_big_decimal *dec, int v1, int v2, int remainder, int i);
void big_long_sub(ar_big_decimal value_1, ar_big_decimal value_2,
                  ar_big_decimal *result);
int sub_big_set_bit(ar_big_decimal *dec, int v1, int v2, int borrow, int i);
int mul_big_set_bit(AR_BIG_HELPER mul);
int div_big_set_bit(AR_BIG_HELPER div);
int div_big_bit_long_div(AR_BIG_HELPER div, int *s21_borrow, int i,
                         ar_big_decimal tmp, ar_big_decimal *tmpresult,
                         int fract);

int div_equals(AR_HELPER h);
int div_by_zero(s21_decimal value_2);
AR_HELPER ar_cons(s21_decimal *r, s21_decimal v1, s21_decimal v2,
                  s21_decimal *rm, int l1, int l2, int si, int sc);

AR_BIG_HELPER ar_big_cons(ar_big_decimal *r, ar_big_decimal v1,
                          ar_big_decimal v2, ar_big_decimal *rm, int l1,
                          int l2);
ar_big_decimal dec2big_converter(s21_decimal dec);
int big2dec_converter(ar_big_decimal big_dec, s21_decimal *dec, int scale);
ar_big_decimal big_power10(ar_big_decimal dec, int power);
ar_big_decimal big_div10(ar_big_decimal dec, int power);
void big_bank_rounding(ar_big_decimal *dec);
int scomp(long num);
void big_dec_cpy(ar_big_decimal result, ar_big_decimal *value_1);
int s21_exit_error(s21_decimal *dec);

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);

/*-comparison-*/

int s21_pre_work_comparison(s21_decimal value_1, s21_decimal value_2);
int s21_is_less(s21_decimal, s21_decimal);
int s21_is_less_or_equal(s21_decimal, s21_decimal);
int s21_is_greater(s21_decimal, s21_decimal);
int s21_is_greater_or_equal(s21_decimal, s21_decimal);
int s21_is_equal(s21_decimal, s21_decimal);
int s21_is_not_equal(s21_decimal, s21_decimal);

/*-convertations-*/

int s21_from_int_to_decimal(int src, s21_decimal *dst);
int s21_from_float_to_decimal(float src, s21_decimal *dst);
int get_exp_from_float(float src);
int normalize_float(double *copy_num);
unsigned int count_significant(float copy_num);
void scale_float(double *copy_num, int *scale,
                 unsigned int count_significant_digits);
int write_float_to_decimal(double src, s21_decimal *dst, int scale);
void clear_nonsignficant_zero(s21_decimal *dst, int *scale);

int s21_from_decimal_to_int(s21_decimal src, int *dst);
int is_zero(s21_decimal val);
int s21_from_decimal_to_float(s21_decimal src, float *dst);
int s21_from_decimal_to_double(s21_decimal src, double *dst);

/*-other-*/

int s21_floor(s21_decimal value, s21_decimal *result);
int s21_round(s21_decimal value, s21_decimal *result);
int s21_truncate(s21_decimal value, s21_decimal *result);
int s21_negate(s21_decimal value, s21_decimal *result);
void set_plus(s21_decimal *decimal);

/*-big_decimal-*/

void translate_to_big(s21_decimal decimal, s21_big_decimal *b_decimal);
int get_bit_int(s21_decimal decimal, int bit_to_get);
int big_get_bit(s21_big_decimal decimal, int bit_to_get);
void set_bit_int(s21_decimal *decimal, int position_bit_to_set, int res_of_set);
void big_set_bit(s21_big_decimal *decimal, int position_bit_to_set,
                 int res_of_set);
void big_sub_of_mantissas(s21_big_decimal minuend, s21_big_decimal subtrahend,
                          s21_big_decimal *difference);
int big_add_of_mantissas(s21_big_decimal *term_1, s21_big_decimal *term_2,
                         s21_big_decimal *sum);
int get_exp(s21_decimal decimal);
int set_exp(s21_decimal *num, int scale);
void set_minus(s21_decimal *decimal);
s21_big_decimal shift_big_decimal_to_left(s21_big_decimal decimal_to_shift,
                                          int shift);
void null_big_decimal(s21_big_decimal *decimal);
int is_zero_big(s21_big_decimal val);
int comp_of_mantissas_for_big(s21_big_decimal b_dec_1, s21_big_decimal b_dec_2);
int comp_of_mantissas(s21_decimal dec_1, s21_decimal dec_2);
int big_mul_of_mantissas(s21_big_decimal decimal_1, s21_big_decimal decimal_2,
                         s21_big_decimal *res);
void mul_10_mantissas(s21_big_decimal *decimal, int exp_diff);
void normalization(s21_big_decimal *decimal_1, s21_big_decimal *decimal_2);
int translate_to_s21_decimal(s21_big_decimal *big_decimal,
                             s21_decimal *s21_decimal);
int get_position_of_senior_bit(s21_big_decimal *big_decimal);
void division_big_decimal(s21_big_decimal val1, s21_big_decimal val2,
                          s21_big_decimal *res);
unsigned int division_big_decimal_with_rest_10(s21_big_decimal val1,
                                               s21_big_decimal *res);
void bank_round(s21_big_decimal *val1, int rank);
void null_decimal(s21_decimal *decimal);
void full_decimal(s21_decimal *num);

#endif