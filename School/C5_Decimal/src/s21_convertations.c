#include "s21_decimal.h"

// Перевод int числа в структуру s21_decimal, возвращается 0 - OK, 1 - ошибка
// конвертации
int s21_from_int_to_decimal(int src, s21_decimal *dst) {
  int result = 0;
  if (src != -s21_INF && src != s21_INF && src != s21_NAN && dst != NULL &&
      src <= INT_MAX && src >= INT_MIN) {
    null_decimal(dst);
    if (src < 0) {
      set_minus(dst);
      src = -src;
    }
    dst->bits[0] = src;  // int у нас занимает только 1 байт
  } else
    result = 1;
  return result;
}

// Перевод числа из структуры s21_decimal в int число, возвращается 0 - OK, 1 -
// ошибка конвертации
int s21_from_decimal_to_int(s21_decimal src, int *dst) {
  int result = 0;
  while (get_exp(src) > 0 && (result = is_zero(src)) == 0) {
    s21_big_decimal big_src = {0};
    translate_to_big(src, &big_src);
    division_big_devimal_with_rest_10(big_src, &big_src);
    translate_to_s21_decimal(&big_src, &src);
  }
  if (src.bits[1] == 0 && src.bits[2] == 0 &&
      dst != NULL) {  // int хранится только в нулевом байте массива
    *dst = src.bits[0];
    if (get_sign(src) == 1) *dst *= -1;
  } else
    result = 1;
  return result;
}

// если не ноль то возвращает 1
int is_zero(s21_decimal val) {
  int res = 1;
  for (int i = 2; i >= 0; i--) {
    if (val.bits[i] != 0) {
      res = 0;
      break;
    }
  }
  return res;
}

// Перевод числа из float в структуру s21_decimal, возвращается 0 - OK, 1 -
// ошибка конвертации
int s21_from_float_to_decimal(float src, s21_decimal *dst) {
  int result = 0;
  int small_number = (fabs(src) > 0 && fabs(src) < 1e-28)
                         ? 1
                         : 0;  // если число слишком маленькое, то 1
  if (dst != NULL && src != -s21_INF && src != s21_INF && src != s21_NAN &&
      !small_number) {
    null_decimal(dst);
    int exp_for_float = get_exp_from_float(src);
    if (exp_for_float < 95 &&
        exp_for_float > -95) {  // -126<exp<127, но используется из-за
                                // переполнения и недостатка точности -95<exp<95
      if (src < 0) {
        set_minus(dst);
        src = -src;
      }
      double copy_num = src;
      int scale = 0;
      if (exp_for_float < 0) {
        scale = normalize_float(&copy_num);
      }
      unsigned int count_signigicant_digits = count_significant(copy_num);
      scale_float(&copy_num, &scale, count_signigicant_digits);
      result = write_float_to_decimal(copy_num, dst, scale);

    } else
      result = 1;

  } else {
    result = 1;
    if (small_number) {
      null_decimal(dst);
      if (src < 0) set_minus(dst);
    }
  }
  return result;
}

// получаем экспоненту флота
int get_exp_from_float(float src) {
  unsigned int *temp =
      ((unsigned int *)&src);  // приводим адрес к типу unsigned int, чтобы
                               // работать с битами числа
  unsigned int mask = 255 << 23;  //
  return (int)((*temp & mask) >> 23) -
         127;  // вычитаем 127 для коррекции смещения экспоненты
}

// считает коэффициент масштабирования (scale)
int normalize_float(double *copy_num) {
  int scale = 0;
  unsigned int count_significant_digits = 0;
  if (copy_num != NULL) {
    while (count_significant_digits < PRECISION && scale < 28) {
      *copy_num *= 10.0;
      count_significant_digits = count_significant(*copy_num);
      scale++;
    }
  }
  return scale;
}

// считает количество цифр в целой части
unsigned int count_significant(float copy_num) {
  unsigned int count_significant_digits = 0;
  while (copy_num >= 1.0) {
    copy_num /= 10.0;
    count_significant_digits++;
  }
  return count_significant_digits;
}

// изменяет масштаб числа (добавляет либо удаляет указанное число значащих цифр)
void scale_float(double *copy_num, int *scale,
                 unsigned int count_significant_digits) {
  if (copy_num != NULL && scale != NULL) {
    double fractional_part = 0.0;  // дробная часть
    if (count_significant_digits < PRECISION && *scale < 28) {
      for (unsigned int i = 0; i < PRECISION - count_significant_digits; i++) {
        *copy_num *= 10.0;
        (*scale)++;
      }
    } else if (count_significant_digits > PRECISION) {
      for (unsigned int i = 0; i < count_significant_digits - PRECISION; i++) {
        (*scale)--;
        *copy_num /= 10.0;
      }
    }
    fractional_part =
        modf(*copy_num, copy_num);  // возвращает дробную часть, в copy_num
                                    // записывается целая часть
    *copy_num += (int)(fractional_part * 10.0) >=
                 5;  // если первая цифра дробного числа больше 0.5, то
                     // прибавляем к целой части 1
  }
}

//записывает в s21_decimal
int write_float_to_decimal(double src, s21_decimal *dst, int scale) {
  int result = 0;
  unsigned int bit_position = 0;

  while (src >= 1 && bit_position < BITS_IN_3_INT) {
    set_bit(dst, bit_position, fmodf(src, 2.0));
    src /= 2.0;
    bit_position++;
  }
  if (src > 1.0) {  // переполнение
    null_decimal(dst);
    result = 1;
  } else {
    while (scale < 0) {
      s21_big_decimal big_decimal = {0};
      translate_to_big(*dst, &big_decimal);
      mul_10_mantissas(&big_decimal, 1);
      translate_to_s21_decimal(&big_decimal, dst);
      scale++;
    }
    clear_nonsignficant_zero(dst, &scale);
    set_exp(dst, scale);
  }
  return result;
}

// убирает не значащие нули
void clear_nonsignficant_zero(s21_decimal *dst, int *scale) {
  if (dst != NULL) {
    if (*scale > 0) {
      s21_big_decimal tmp = {0};
      tmp.exp = *scale;
      int remainder = 0;
      translate_to_big(*dst, &tmp);
      s21_big_decimal result = tmp;
      do {
        remainder = division_big_devimal_with_rest_10(tmp, &tmp);
        if (remainder == 0) {
          (*scale)--;
          result = tmp;
        }
      } while (
          (*scale) > 0 &&
          remainder ==
              0);  // если в remainder ноль, то у нас результат делится на 10
      translate_to_s21_decimal(&result, dst);
    }
  }
}

// Перевод числа из структуры s21_decimal в float число, возвращается 0 - OK, 1
// - ошибка конвертации
int s21_from_decimal_to_float(s21_decimal src, float *dst) {
  int result = 0;
  if (dst != NULL) {
    int scale = 0, sign = 0;
    *dst = 0.0f;  // обнуляем значение, чтобы не записывался мусор
    scale = get_exp(src);
    sign = get_sign(src);
    if (scale > 28)
      result = 1;
    else {
      for (int i = 0; i < 96; i++)
        if (get_bit(src, i)) *dst += (float)pow(2, i);
      *dst /= pow(10, scale);  // учитываем показатель степени
      if (sign) *dst *= -1;
    }
  } else
    result = 1;
  return result;
}
