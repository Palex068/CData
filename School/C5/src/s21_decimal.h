#ifndef S21_DECIMAL
#define S21_DECIMAL

#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

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

#define S21_OK 0
#define S21_ERROR 1
#define S21_ERROR_TOO_BIG 1
#define S21_ERROR_TOO_SMALL 2
#define S21_ERROR_ZERO_DIVISION 3

typedef struct {
  unsigned int bits[4];
} s21_decimal;

typedef struct {
  unsigned int bits[8];
  int exp;           // сохранение степени
  int senior_bit;    // индекс старшего бита
  int sign;          // 1(-), 0(+)
  int digits_after;  // для банковского округления
} s21_big_decimal;

/*-----Арифметика-----*/
int s21_div(s21_decimal val1, s21_decimal val2, s21_decimal *result);
int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);

/*-----Конвертации-----*/
int s21_from_int_to_decimal(int src, s21_decimal *dst);
int s21_from_decimal_to_int(s21_decimal src, int *dst);
int s21_from_float_to_decimal(float src, s21_decimal *dst);
int s21_from_decimal_to_float(s21_decimal src, float *dst);
int get_exp_from_float(float src);
int normalize_float(double *copy_num);
unsigned int count_significant(float copy_num);
void scale_float(double *copy_num, int *scale,
                 unsigned int count_significant_digits);
int write_float_to_decimal(double src, s21_decimal *dst, int scale);
void clear_nonsignficant_zero(s21_decimal *dst, int *scale);

/*-----Сравнения-----*/
int s21_is_less(s21_decimal value_1, s21_decimal value_2);
int s21_is_less_or_equal(s21_decimal value_1, s21_decimal value_2);
int s21_is_greater(s21_decimal value_1, s21_decimal value_2);
int s21_is_greater_or_equal(s21_decimal value_1, s21_decimal value_2);
int s21_is_equal(s21_decimal value_1, s21_decimal value_2);
int s21_is_not_equal(s21_decimal value_1, s21_decimal value_2);
int pre_work_compresion(s21_decimal value_1, s21_decimal value_2);

/*-----Другие функции-----*/
int s21_negate(s21_decimal value, s21_decimal *result);
void set_plus(s21_decimal *decimal);
int s21_floor(s21_decimal val, s21_decimal *res);
int s21_truncate(s21_decimal val, s21_decimal *res);
int s21_round(s21_decimal value, s21_decimal *result);

/*-----Переводы-----*/
void translate_to_big(s21_decimal decimal, s21_big_decimal *b_decimal);
int translate_to_s21_decimal(s21_big_decimal *big_decimal,
                             s21_decimal *s21_decimal);
void normalization(s21_big_decimal *decimal_1, s21_big_decimal *decimal_2);
void bank_round(s21_big_decimal *val1, int rank);

/*-----Гет сет-----*/
int get_bit(s21_decimal decimal, int bit_to_get);
void set_bit(s21_decimal *decimal, int position_bit_to_set, int res_of_set);
int get_exp(s21_decimal decimal);
int set_exp(s21_decimal *num, int scale);
int get_sign(s21_decimal num);
void set_minus(s21_decimal *num);

/*-----Биг гет сет-----*/
void big_set_bit(s21_big_decimal *decimal, int position_bit_to_set,
                 int res_of_set);
int big_get_bit(s21_big_decimal decimal, int bit_to_get);

/*-----Арифметические операции в биг-----*/
void big_sub_of_mantissas(s21_big_decimal minuend, s21_big_decimal subtrahend,
                          s21_big_decimal *difference);
int big_add_of_mantissas(s21_big_decimal *term_1, s21_big_decimal *term_2,
                         s21_big_decimal *sum);
int big_mul_of_mantissas(s21_big_decimal decimal_1, s21_big_decimal decimal_2,
                         s21_big_decimal *res);
void division_big_devimal(s21_big_decimal val1, s21_big_decimal val2,
                          s21_big_decimal *res);

/*-----Вспомогательные функции-----*/
s21_big_decimal shift_big_decimal_to_left(s21_big_decimal decimal_to_shift,
                                          int shift);
void null_big_decimal(s21_big_decimal *decimal);
void mul_10_mantissas(s21_big_decimal *decimal, int exp_diff);
int comp_of_mantissas_for_big(s21_big_decimal decimal_1,
                              s21_big_decimal decimal_2);
int comp_of_mantissas(s21_decimal decimal_1, s21_decimal decimal_2);
unsigned int division_big_devimal_with_rest_10(s21_big_decimal val1,
                                               s21_big_decimal *res);
int get_position_of_senior_bit(s21_big_decimal *big_decimal);
int s21_from_decimal_to_double(s21_decimal src, double *dst);
void null_decimal(s21_decimal *decimal);
int is_zero_big(s21_big_decimal val);
void full_decimal(s21_decimal *num);
int is_zero(s21_decimal val);
// void print_decimal(s21_decimal decimal);
// void print_big_decimal(s21_big_decimal decimal);

#endif