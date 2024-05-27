#include "s21_decimal.h"

#define s21_INF __builtin_inf()
#define s21_NAN __builtin_nan("")

#define S21_OK 0
#define S21_ERROR 1
#define S21_ERROR_TOO_BIG 1
#define S21_ERROR_TOO_SMALL 2
#define S21_ERROR_ZERO_DIVISION 3

/** @brief Преобразование числа int в число типа decimal
 * @param src int - исходное число
 * @param dst *s21_decimal - указатель на число типа decimal
 * @return код ошибки: 0 — OK, 1 — ошибка конвертации.
 */
int s21_from_int_to_decimal(int src, s21_decimal *dst) {
  int result = 0;
  if (src != -s21_INF && src != s21_INF && src != s21_NAN && dst != NULL &&
      src <= INT_MAX && src >= INT_MIN) {
    decimal_clear(dst);
    if (src < 0) {
      set_negative(dst);
      src = -src;
    }
    dst->bits[0] = src; // int у нас занимает только 1 байт
  } else
    result = 1;
  return result;
}