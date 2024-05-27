#include "s21_decimal.h"

// int s21_is_less(s21_decimal, s21_decimal);
// int s21_is_less_or_equal(s21_decimal, s21_decimal);
// int s21_is_greater(s21_decimal, s21_decimal);
// int s21_is_greater_or_equal(s21_decimal, s21_decimal);

/** @brief Сравнение на равенство двух чисел типа decimal
 * @param value_1
 * @param value_2
 * @return true = 1, если равны, иначе false = 0
 */
int s21_is_equal(s21_decimal value_1, s21_decimal value_2) {
  int s21_true = 1;
  for (int i = 0; i <= 3; i++)
    if (value_1.bits[i] != value_2.bits[i]) s21_true = 0;
  return s21_true;
}
// int s21_is_not_equal(s21_decimal, s21_decimal);