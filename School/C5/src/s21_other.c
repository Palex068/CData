#include "s21_decimal.h"
#define PLUS 0

// Возвращает результат умножения указанного Decimal на -1.
int s21_negate(s21_decimal value, s21_decimal* result) {
  int error_status = 0;
  if (result == NULL) {
    error_status = 1;
  } else {
    null_decimal(result);
    *result = value;
    if (get_sign(*result) == PLUS)
      set_minus(result);
    else if (get_sign(*result) == MINUS)
      set_plus(result);
  }
  return error_status;
}

void set_plus(s21_decimal* decimal) { set_bit(decimal, 127, PLUS); }

// Округляет указанное Decimal число до ближайшего целого числа в сторону
// отрицательной бесконечности.
int s21_floor(s21_decimal val, s21_decimal* res) {
  int error_status = 0;
  if (res != NULL) {
    null_decimal(res);
    s21_decimal one = {{1, 0, 0, 0}};
    s21_decimal trunc = {0};

    s21_truncate(val, &trunc);

    s21_sub(val, trunc, res);

    if (get_sign(*res) == MINUS) {
      s21_sub(trunc, one, res);
    } else {
      *res = trunc;
    }

    if (!res->bits[0] && !res->bits[1] && !res->bits[2])
      set_plus(res);  // устнавливаем знак
  } else {
    error_status = 1;
  }
  return error_status;
}

// Возвращает целые цифры указанного Decimal числа; любые дробные цифры
// отбрасываются, включая конечные нули.
int s21_truncate(s21_decimal val, s21_decimal* res) {
  int error_status = 0;
  if (res != NULL) {
    null_decimal(res);
    s21_big_decimal bval = {0};
    translate_to_big(val, &bval);
    get_position_of_senior_bit(&bval);
    s21_big_decimal ten = {0};
    ten.bits[0] = 10;
    while (bval.exp > 0 && comp_of_mantissas_for_big(bval, ten) >= 0) {
      division_big_devimal_with_rest_10(bval, &bval);
    }
    if (bval.exp > 0 && !(comp_of_mantissas_for_big(bval, ten) >= 0)) {
      null_big_decimal(&bval);
    } else if (!error_status) {
      translate_to_s21_decimal(&bval, res);
    }
  } else {
    error_status = 1;
  }
  return error_status;
}

// Округляет Decimal до ближайшего целого числа. (Математическое округление)
int s21_round(s21_decimal value, s21_decimal* result) {
  int error_status = 0;
  if (result != NULL) {
    null_decimal(result);
    double float_to_round = 0.0;
    double difference = 0;
    s21_from_decimal_to_double(value, &float_to_round);
    float_to_round = round(float_to_round);
    if (float_to_round < 0.0) {
      set_bit(result, 127, 1);
      float_to_round *= -1;
    }
    for (int i = 0; float_to_round >= 1 && i < BITS_IN_3_INT; i++) {
      float_to_round = floor(float_to_round) / 2;
      difference = float_to_round - floor(float_to_round);
      if (difference > 0.0) {
        set_bit(result, i, 1);
      } else {
        set_bit(result, i, 0);
      }
    }
    set_exp(result, 0);
  } else {
    error_status = 1;
  }
  return error_status;
}

int s21_from_decimal_to_double(s21_decimal src, double* dst) {
  int result = 0;
  if (dst != NULL) {
    int scale = 0, sign = 0;
    *dst = 0.0F;
    scale = get_exp(src);
    sign = get_sign(src);
    if (scale > 28)
      result = 1;
    else {
      for (int i = 0; i < 96; i++)
        if (get_bit(src, i)) *dst += (double)pow(2, i);
      *dst /= pow(10, scale);
      if (sign) *dst *= -1;
    }
  } else
    result = 1;
  return result;
}