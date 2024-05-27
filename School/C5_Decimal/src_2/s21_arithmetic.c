#include "s21_decimal.h"

/** @brief Сложение двух чисел типа decimal
 * @param value_1 первое слагаемое число decimal
 * @param value_2 второе слагаемое число decimal
 * @param result структура куда записывается сумма слагаемых чисел decimal
 * @return Возвращается int с кодом ошибки:
 * 0 — OK;
 * 1 — число слишком велико или равно бесконечности;
 * 2 — число слишком мало или равно отрицательной бесконечности;
 * 3 — деление на 0.
 */
int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  decimal_clear(result);
  int s21_error = 0;
  int s21_remainder = 0;
  scale_normalize(&value_1, &value_2, result);
  int scale = get_scale(*result);
  if (get_sign(value_1) == get_sign(value_2)) {
    if (get_sign(value_1)) set_negative(result);
    for (int i = 0; i < BITSIZE96; i++) {
      int v1 = get_bit(value_1, i);
      int v2 = get_bit(value_2, i);
      if (i == BIT96 && (v1 + v2 + s21_remainder) > 1)
        return s21_exit_error(result);
      s21_remainder = add_set_bit(result, v1, v2, s21_remainder, i);
    }
  } else {
    int ssb = 0, sign = 0;
    ssb = decimal_cmp(value_1, value_2);  // set sign back
    if (get_sign(value_1)) {
      set_positive(&value_1);
      if (!ssb)
        sign = 1;
      else
        sign = 0;
    } else {
      set_positive(&value_2);
      if (ssb)
        sign = 1;
      else
        sign = 0;
    }
    s21_error = s21_sub(value_1, value_2, result);
    if (sign)
      set_negative(result);
    else
      set_positive(result);
  }
  set_scale(result, scale);
  return s21_error;
}

/** @brief Вычитание двух чисел типа decimal
 * @param value_1 уменьшаемое число decimal
 * @param value_2 вычитаемое число decimal
 * @param result структура, куда записывается разница чисел decimal
 * @return Возвращается int с кодом ошибки:
 * 0 — OK;
 * 1 — число слишком велико или равно бесконечности;
 * 2 — число слишком мало или равно отрицательной бесконечности;
 * 3 — деление на 0.
 */
int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  decimal_clear(result);
  int s21_error = 0;
  int s21_borrow = 0;
  scale_normalize(&value_1, &value_2, result);
  int scale = get_scale(*result);
  if (get_sign(value_1) == get_sign(value_2)) {
    if (get_sign(value_1)) decimal_rotate(&value_1, &value_2);
    if (decimal_cmp(value_1, value_2)) {
      decimal_rotate(&value_1, &value_2);
      set_negative(result);
    }
    for (int i = 0; i < BITSIZE96; i++) {
      int v1 = get_bit(value_1, i);
      int v2 = get_bit(value_2, i);
      s21_borrow = sub_set_bit(result, v1, v2, s21_borrow, i);
    }
  } else {
    int sign = 0;
    if (get_sign(value_1)) {
      set_positive(&value_1);
      sign = 1;
    } else {
      set_positive(&value_2);
      sign = 0;
    }
    s21_error = s21_add(value_1, value_2, result);
    if (sign) {
      set_negative(result);
      if (s21_error) return s21_exit_error(result);
    } else {
      set_positive(result);
    }
  }
  set_scale(result, scale);
  return s21_error;
}

/** @brief Умножение двух чисел decimal
 * @param value_1 первый множитель типа число decimal
 * @param value_2 второй множитель типа число decimal
 * @param result структура, куда записывается произведение decimal
 * @return Возвращается int с кодом ошибки:
 * 0 — OK;
 * 1 — число слишком велико или равно бесконечности;
 * 2 — число слишком мало или равно отрицательной бесконечности;
 * 3 — деление на 0.
 */
int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  decimal_clear(result);
  int s21_error = 0, sign = 1;
  if (get_sign(value_1) == get_sign(value_2)) sign = 0;
  int scale = get_scale(value_1) + get_scale(value_2);
  int len1 = decimal_len(value_1);
  int len2 = decimal_len(value_2);
  AR_HELPER mul = ar_cons(result, value_1, value_2, NULL, len1, len2, sign, 0);
  s21_error = mul_set_bit(mul);
  if (!s21_error) {
    if (sign && (len1 && len2))
      set_negative(result);
    else
      set_positive(result);
    if (len1 && len2) set_scale(result, scale);
    while (scale > 28) {
      bank_rounding(result);
      scale = get_scale(*result);
      if (decimal_is_null(result)) return s21_error = 2;
    }
  }
  return s21_error;
}

/** @brief Деление двух чисел decimal
 * @param value_1 делимое число decimal
 * @param value_2 делитель числа decimal
 * @param result структура, куда записывается частное decimal
 * @return Возвращается int с кодом ошибки:
 * 0 — OK;
 * 1 — число слишком велико или равно бесконечности;
 * 2 — число слишком мало или равно отрицательной бесконечности;
 * 3 — деление на 0.
 */
int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  decimal_clear(result);
  int s21_error = 0, sign = 1;
  if (div_by_zero(value_2)) return s21_error = 3;

  int scale = get_scale(value_1) - get_scale(value_2);
  set_scale(&value_1, 0);
  set_scale(&value_2, 0);

  if (get_sign(value_1) == get_sign(value_2)) sign = 0;
  set_positive(&value_1);
  set_positive(&value_2);

  int len1 = decimal_len(value_1);
  s21_decimal rem = {0};
  AR_HELPER div = ar_cons(result, value_1, value_2, &rem, len1, 0, sign, scale);
  if (div_equals(div)) return s21_error = 0;

  s21_error = div_set_bit(div);

  if (sign && !s21_error) set_negative(result);
  return s21_error;
}