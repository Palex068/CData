#include "s21_decimal.h"

// int s21_is_less(s21_decimal, s21_decimal);
// int s21_is_less_or_equal(s21_decimal, s21_decimal);
// int s21_is_greater(s21_decimal, s21_decimal);
// int s21_is_greater_or_equal(s21_decimal, s21_decimal);

// int s21_is_not_equal(s21_decimal, s21_decimal);

/** @brief Сравнение двух чисел типа decimal
 * @param value_1
 * @param value_2
 * @return `1` если value_1 больше, `-1` если value_2 больше, `0` если равно
 */
int s21_pre_work_comparison(s21_decimal value_1, s21_decimal value_2) {
  int res = 0;

  // строки выше это начало работы. переводим числа в big_decimal и нормализуем
  // их. создаём переменные для хранения знаков а также флажок одинаковых знаков
  s21_big_decimal b_value_1 = {0}, b_value_2 = {0}, nul = {0};
  s21_decimal v_1 = {0}, v_2 = {0};
  translate_to_big(value_1, &b_value_1);
  translate_to_big(value_2, &b_value_2);
  normalization(&b_value_1, &b_value_2);
  int is_value_1_negative = get_sign(value_1) == MINUS;
  int is_value_2_negative = get_sign(value_2) == MINUS;
  int is_sign_equal = !(is_value_1_negative - is_value_2_negative);
  translate_to_s21_decimal(&b_value_1, &v_1);
  translate_to_s21_decimal(&b_value_2, &v_2);

  // если знаки у чисел одинаковые
  if (is_sign_equal) {
    // и оба знака отрицательные
    if (is_value_1_negative) {
      res = (comp_of_mantissas(v_1, v_2));

      // если по модулю первое число больше, то меняем результат
      if (res == 1) res = -1;

      // так как например (-5 < -2). а функция comp_of_mantissas сравнивает
      // только мантиссы
      else if (res == -1)
        res = 1;

      // иначе если оба знака положительные, то возвращаем обычный результат
      // сравнения
    } else {
      res = (comp_of_mantissas(v_1, v_2));
    }

    // 1 или -1
    // сюда заходим если числа имеют разные знаки
  } else {
    // если например (-1 и 1) то рез = -1 так как второе число больше
    if ((is_value_1_negative) && !(is_value_2_negative)) {
      res = -1;

      // тут наоборот если (1 и -1) то рез = 1 так как первое число
      // конечно же больше
    } else if (!(is_value_1_negative) && (is_value_2_negative))
      res = 1;
  }
  if (comp_of_mantissas_for_big(b_value_1, nul) == 0 &&
      comp_of_mantissas_for_big(b_value_2, nul) == 0)
    res = 0;

  // возвращаем результат -1 1 или 0, чтобы применить его в функциях сравнения
  return res;
}

/** @brief Сравнение меньше двух чисел типа decimal
 * @param value_1
 * @param value_2
 * @return true = 1, если `value_1` меньше `value_2`, иначе false = 0
 */
int s21_is_less(s21_decimal value_1, s21_decimal value_2) {
  int status = s21_pre_work_comparison(value_1, value_2);

  // если нам вернулось -1, то первое число
  // меньше второго, значит возвращаем true

  status = (status == -1 ? 1 : 0);
  return status;
}

/** @brief Сравнение меньше или равно двух чисел типа decimal
 * @param value_1
 * @param value_2
 * @return true = 1, если `value_1` меньше `value_2`, иначе false = 0
 */
int s21_is_less_or_equal(s21_decimal value_1, s21_decimal value_2) {
  int status = s21_pre_work_comparison(value_1, value_2);

  // если нам вернулось -1 или 0, то первое число меньше
  // второго или равно значит возвращаем true

  status = (((status == -1) || (status == 0)) ? 1 : 0);
  return status;
}

/** @brief Сравнение больше двух чисел типа decimal
 * @param value_1
 * @param value_2
 * @return true = 1, если `value_1` больше `value_2`, иначе false = 0
 */
int s21_is_greater(s21_decimal value_1, s21_decimal value_2) {
  int status = s21_pre_work_comparison(value_1, value_2);

  // если нам вернулось 1, то первое число
  // больше второго, значит возвращаем true

  status = ((status == 1) ? 1 : 0);
  return status;
}

/** @brief Сравнение больше или равно двух чисел типа decimal
 * @param value_1
 * @param value_2
 * @return true = 1, если `value_1` больше или равно `value_2`, иначе false = 0
 */
int s21_is_greater_or_equal(s21_decimal value_1, s21_decimal value_2) {
  int status = s21_pre_work_comparison(value_1, value_2);

  // если нам вернулось 1 или 0, то первое число больше
  // второго или равно, значит возвращаем true

  status = (((status == 1) || (status == 0)) ? 1 : 0);
  return status;
}

/** @brief Сравнение на равенство двух чисел типа decimal
 * @param value_1
 * @param value_2
 * @return true = 1, если равны, иначе false = 0
 */
int s21_is_equal(s21_decimal value_1, s21_decimal value_2) {
  int status = s21_pre_work_comparison(value_1, value_2);

  // если нам вернулось 0, то первое число равно второму,
  // значит возвращаем true

  status = ((status == 0) ? 1 : 0);
  return status;
}

/** @brief Сравнение на неравенство двух чисел типа decimal
 * @param value_1
 * @param value_2
 * @return true = 1, если не равны, иначе false = 0
 */
int s21_is_not_equal(s21_decimal value_1, s21_decimal value_2) {
  int status = s21_pre_work_comparison(value_1, value_2);

  // если нам вернулось что угодно только не 0, то первое число не равно
  // второму, значит возвращаем true

  status = ((status != 0) ? 1 : 0);
  return status;
}
