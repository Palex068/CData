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
  ar_big_decimal b_value_1 = dec2big_converter(value_1);
  ar_big_decimal b_value_2 = dec2big_converter(value_2);
  ar_big_decimal b_result = {0};
  int sc1 = get_scale(value_1);
  int sc2 = get_scale(value_2);
  int scale = big_scale_normalize(&b_value_1, &b_value_2, sc1, sc2);
  if (get_sign(value_1) == get_sign(value_2)) {
    if (get_sign(value_1)) set_negative(result);
    big_long_add(b_value_1, b_value_2, &b_result);
    s21_error = big2dec_converter(b_result, result, scale);
  } else {
    int sign = 0;
    if (big_decimal_cmp(b_value_1, b_value_2)) {
      big_decimal_rotate(&b_value_1, &b_value_2);
      decimal_rotate(&value_1, &value_2);
    }
    if (get_sign(value_1)) sign = 1;
    big_long_sub(b_value_1, b_value_2, &b_result);
    s21_error = big2dec_converter(b_result, result, scale);
    if (sign)
      set_negative(result);
    else
      set_positive(result);
  }
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
  ar_big_decimal b_value_1 = dec2big_converter(value_1);
  ar_big_decimal b_value_2 = dec2big_converter(value_2);
  ar_big_decimal b_result = {0};
  int sc1 = get_scale(value_1);
  int sc2 = get_scale(value_2);
  int scale = big_scale_normalize(&b_value_1, &b_value_2, sc1, sc2);
  if (get_sign(value_1) == get_sign(value_2)) {
    if (get_sign(value_1)) big_decimal_rotate(&b_value_1, &b_value_2);
    if (big_decimal_cmp(b_value_1, b_value_2)) {
      big_decimal_rotate(&b_value_1, &b_value_2);
      set_negative(result);
    }
    big_long_sub(b_value_1, b_value_2, &b_result);
    s21_error = big2dec_converter(b_result, result, scale);
  } else {
    if (get_sign(value_1)) set_negative(result);
    big_long_add(b_value_1, b_value_2, &b_result);
    s21_error = big2dec_converter(b_result, result, scale);
  }
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
  if (decimal_is_null(&value_1) || decimal_is_null(&value_2)) return s21_error;
  if (get_sign(value_1) == get_sign(value_2)) sign = 0;
  int scale = get_scale(value_1) + get_scale(value_2);
  int len1 = decimal_len(value_1);
  int len2 = decimal_len(value_2);
  ar_big_decimal b_value_1 = dec2big_converter(value_1);
  ar_big_decimal b_value_2 = dec2big_converter(value_2);
  ar_big_decimal b_result = {0};
  int b_len1 = big_decimal_len(b_value_1);
  int b_len2 = big_decimal_len(b_value_2);
  AR_BIG_HELPER b_mul =
      ar_big_cons(&b_result, b_value_1, b_value_2, NULL, b_len1, b_len2);
  mul_big_set_bit(
      b_mul);  // NOTE: ошибки переполнения тут по идее быть не может
  if (sign) set_negative(result);
  s21_error = big2dec_converter(b_result, result, scale);
  if (!s21_error) {
    if (sign && (len1 && len2))
      set_negative(result);
    else
      set_positive(result);
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
  int sc1 = get_scale(value_1);
  int sc2 = get_scale(value_2);
  int scale = sc1 - sc2;
  set_scale(&value_1, 0);
  set_scale(&value_2, 0);
  if (get_sign(value_1) == get_sign(value_2)) sign = 0;
  set_positive(&value_1);
  set_positive(&value_2);
  int len1 = decimal_len(value_1);
  s21_decimal rem = {0};
  AR_HELPER div = ar_cons(result, value_1, value_2, &rem, len1, 0, sign, scale);
  if (div_equals(div)) return s21_error = 0;
  ar_big_decimal b_value_1 = dec2big_converter(value_1);
  ar_big_decimal b_value_2 = dec2big_converter(value_2);
  ar_big_decimal b_rem = {0};
  ar_big_decimal b_result = {0};
  big_scale_normalize(&b_value_1, &b_value_2, sc1, sc2);
  int b_len1 = big_decimal_len(b_value_1);
  int b_len2 = big_decimal_len(b_value_2);
  AR_BIG_HELPER b_mul =
      ar_big_cons(&b_result, b_value_1, b_value_2, &b_rem, b_len1, b_len2);
  scale = div_big_set_bit(b_mul);
  if (scale < 0)
    return s21_exit_error(result);  // TODO: обработчик ошибки тут scale;
  s21_error = big2dec_converter(b_result, result, scale);
  if (sign && !s21_error) set_negative(result);
  return s21_error;
}