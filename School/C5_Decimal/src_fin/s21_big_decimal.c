#include "s21_decimal.h"

/** @brief Преобразование числа `decimal` в число типа `big_decimal`
 * @param decimal s21_decimal - исходное число
 * @param b_decimal *s21_big_decimal - указатель на число типа big_decimal
 */
void translate_to_big(s21_decimal decimal, s21_big_decimal *b_decimal) {
  for (int i = 0; i < 3; i++) b_decimal->bits[i] = decimal.bits[i];
  b_decimal->exp = get_exp(decimal);
  b_decimal->sign = get_sign(decimal);
}

/** @brief Получение значения определённого бита в числе типа big_decimal
 * @param decimal число типа big_decimal
 * @param bit_to_get нужный бит (от 0 до 127) числа типа big_decimal
 * @return Состояние бита (1 или 0) `int`
 */
int big_get_bit(s21_big_decimal decimal, int bit_to_get) {
  int res_bit;
  int index = bit_to_get / BITS_IN_1_INT;
  int mask = 1 << (bit_to_get % BITS_IN_1_INT);
  int check_bit = decimal.bits[index] & mask;
  if (check_bit == 0)
    res_bit = 0;
  else
    res_bit = 1;
  return res_bit;
}

/** @brief Выставление определённого бита в числе типа `decimal`
 * @param decimal указатель структуры числа типа decimal
 * @param position_bit_to_set нужный бит (от 0 до 127) числа типа `decimal`
 * @param res_of_set Состояние бита (1 или 0) `int`
 */
void set_bit_int(s21_decimal *decimal, int position_bit_to_set,
                 int res_of_set) {
  int index = position_bit_to_set / BITS_IN_1_INT;
  int mask = 1 << (position_bit_to_set % BITS_IN_1_INT);
  if (res_of_set == 0)
    decimal->bits[index] &= ~(mask);
  else
    decimal->bits[index] |= (mask);
}

/** @brief Выставление определённого бита в числе типа `big_decimal`
 * @param decimal указатель структуры числа типа decimal
 * @param position_bit_to_set нужный бит (от 0 до 127) числа типа `decimal`
 * @param res_of_set Состояние бита (1 или 0) `int`
 */
void big_set_bit(s21_big_decimal *decimal, int position_bit_to_set,
                 int res_of_set) {
  int index = position_bit_to_set / BITS_IN_1_INT;
  int mask = 1 << (position_bit_to_set % BITS_IN_1_INT);
  if (res_of_set == 0)
    decimal->bits[index] &= ~(mask);
  else
    decimal->bits[index] |= (mask);
}

/** @brief Вычитание мантисс чисел типа `big_decimal`
 * @param minuend уменьшаемое число типа `big_decimal`
 * @param subtrahend вычитаемое число типа `big_decimal`
 * @param difference разница - число типа `big_decimal`
 */
void big_sub_of_mantissas(s21_big_decimal minuend, s21_big_decimal subtrahend,
                          s21_big_decimal *difference) {
  int borrow = 0;
  int result = 0;
  for (int i = 0; i < BITS_BIG_DECIMAL; i++) {
    result = big_get_bit(minuend, i) - big_get_bit(subtrahend, i) - borrow;
    borrow = result < 0;  // запоминаем если потредовалось занимать
    result = abs(result);
    big_set_bit(difference, i, result % 2);
  }
  if (minuend.exp != subtrahend.exp) {
    if (minuend.exp == 0)
      difference->exp = subtrahend.exp;
    else
      difference->exp = minuend.exp;
  } else
    difference->exp = minuend.exp;
}

// сложение мантисс биг децимала
/** @brief Сложение мантисс чисел типа `big_decimal`
 * @param term_1 число типа `big_decimal`
 * @param term_2 число типа `big_decimal`
 * @param sum сумма - число типа `big_decimal`
 * @return код ошибки: `0` — OK, `1` — ошибка.
 */
int big_add_of_mantissas(s21_big_decimal *term_1, s21_big_decimal *term_2,
                         s21_big_decimal *sum) {
  int error = 0;
  int save_ten = 0;
  int result = 0;
  for (int i = 0; i < BITS_BIG_DECIMAL; i++) {
    result = big_get_bit(*term_1, i) + big_get_bit(*term_2, i) + save_ten;
    save_ten = result / 2;  // запоминаем лишний десяток для следующего разряда
    big_set_bit(sum, i, result % 2);
  }
  sum->exp =
      term_1->exp;  // сохраняем значение степени в результирующий децимал
  if (term_1->exp != term_2->exp) {
    if (term_1->exp == 0)
      sum->exp = term_2->exp;
    else
      sum->exp = term_1->exp;
  } else
    sum->exp = term_1->exp;
  if (save_ten == 1) error = 1;
  return error;
}

/** @brief Считывает коэффициент масштабирования числа типа `decimal`
 * @param decimal Число типа `decimal`
 * @return Коэффициент масштабирования числа типа `decimal` в десятичном виде
 */
int get_exp(s21_decimal decimal) {
  int mask_8_bit = EXP_MASK;
  mask_8_bit <<= 16;
  mask_8_bit = decimal.bits[3] & mask_8_bit;
  mask_8_bit >>= 16;
  return mask_8_bit;
}

/** @brief Записывает коэффициент масштабирования числа типа `decimal`
 * @param num Число типа `decimal`
 * @param scale коэффициент масштабирования
 * @return код ошибки: `0` — OK, `1` — ошибка.
 */
int set_exp(s21_decimal *num, int scale) {
  int result = 0;
  if (scale <= (int)EXP_MASK && scale >= 0) {
    for (int i = 0; i < EXP_SIZE; i++) {
      set_bit_int(num, i + 16 + 96, scale % 2);
      // значения для перемещения по bits[3] до значения степени
      scale >>= 1;
    }
  } else {
    result = 1;
  }
  return result;
}

//
/** @brief Устанавливаем знак минуса (он обозначается 1) числа типа `decimal`
 * @param decimal Число типа `decimal`
 */
void set_minus(s21_decimal *decimal) { set_bit(decimal, 127, MINUS); }

/** @brief TODO
 * @param decimal_to_shift Число типа `big_decimal`
 * @param shift Число типа `int`
 * @return Число типа `big_decimal`
 */
s21_big_decimal shift_big_decimal_to_left(s21_big_decimal decimal_to_shift,
                                          int shift) {
  s21_big_decimal res = {0};
  for (int i = 0; i < (BITS_BIG_DECIMAL - 1); i++) {
    if ((i + shift) < BITS_BIG_DECIMAL) {
      big_set_bit(&res, (i + shift), big_get_bit(decimal_to_shift, i));
    }
  }
  return res;
}

/** @brief Очищает число типа `big_decimal`
 *
 */
void null_big_decimal(s21_big_decimal *decimal) {
  for (int i = 0; i < 8; i++) {
    decimal->bits[i] = 0;
  }
  decimal->exp = 0;
  decimal->sign = 0;
  decimal->digits_after = 0;
  decimal->senior_bit = 0;
}

/** @brief Проверка на равенство `0`
 * @param val Число типа `big_decimal`
 * @return Если число не ноль вернет `1`
 */
int is_zero_big(s21_big_decimal val) {
  int res = 0;
  for (int i = 7; i >= 0; i--) {
    if (val.bits[i] != 0) {
      res = 1;
      break;
    }
  }
  return res;
}

/** @brief Сравнение мантисс двух чисел типа `big_decimal`
 * @param b_dec_1 Число типа `big_decimal`
 * @param b_dec_2 Число типа `big_decimal`
 * @return `1` если `b_dec_1` больше, `-1` если `b_dec_2` больше, `0` если равно
 */
int comp_of_mantissas_for_big(s21_big_decimal b_dec_1,
                              s21_big_decimal b_dec_2) {
  int res = 0;
  int bit_1 = 0, bit_2 = 0;
  for (int i = BITS_BIG_DECIMAL - 1; i >= 0; i--) {
    bit_1 = big_get_bit(b_dec_1, i);
    bit_2 = big_get_bit(b_dec_2, i);
    if (bit_1 - bit_2 > 0) {
      res = 1;
      break;
    } else if (bit_1 - bit_2 < 0) {
      res = -1;
      break;
    }
  }
  return res;
}

/** @brief Сравнение мантисс двух чисел типа `decimal`
 * @param dec_1 Число типа `decimal`
 * @param dec_2 Число типа `decimal`
 * @return `1` если `dec_1` больше, `-1` если `dec_2` больше, `0` если равно
 */
int comp_of_mantissas(s21_decimal dec_1, s21_decimal dec_2) {
  int res = 0;
  int bit_1 = 0, bit_2 = 0;
  for (int i = 96 - 1; i >= 0; i--) {
    bit_1 = get_bit(dec_1, i);
    bit_2 = get_bit(dec_2, i);
    if (bit_1 - bit_2 > 0) {
      res = 1;
      break;
    } else if (bit_1 - bit_2 < 0) {
      res = -1;
      break;
    }
  }
  return res;
}

/** @brief TODO Умножение мантисс чисел типа `big_decimal`
 * @param decimal_1 Число типа `big_decimal`
 * @param decimal_2 Число типа `big_decimal`
 * @return код ошибки: `0` — OK, `1` — ошибка.
 */
int big_mul_of_mantissas(s21_big_decimal decimal_1, s21_big_decimal decimal_2,
                         s21_big_decimal *res) {
  s21_big_decimal step = {0};
  null_big_decimal(res);
  int error_status = 0;
  for (int i = 0; i <= BITS_BIG_DECIMAL - 1; i++) {
    if (big_get_bit(decimal_1, i) == 1) {
      // если бит множителя равен одному то в результат добавляем 2 в
      // степени индекса на котором находится этот бит
      step = shift_big_decimal_to_left(decimal_2, i);
      if (big_add_of_mantissas(res, &step, res)) error_status = 1;
    }
  }
  res->exp = decimal_1.exp + decimal_2.exp;
  return error_status;
}

/** @brief TODO
 * @param decimal Число типа `big_decimal`
 * @param exp_diff Разница коэффициентов масштабирования
 */
void mul_10_mantissas(s21_big_decimal *decimal, int exp_diff) {
  s21_big_decimal ten = {0};
  ten.bits[0] = 10;
  for (int i = 0; i < abs(exp_diff); i++) {
    big_mul_of_mantissas(*decimal, ten, decimal);
  }
  decimal->exp += abs(exp_diff);
}

/** @brief Приводим коэффициенты масштабирования к одному знаменателю
 * @param decimal_1 Число типа `big_decimal`
 * @param decimal_2 Число типа `big_decimal`
 */
void normalization(s21_big_decimal *decimal_1, s21_big_decimal *decimal_2) {
  int diff_of_exp = decimal_1->exp - decimal_2->exp;
  // если 1 степень больше то увеличиваем decimal_2
  if (diff_of_exp > 0) {
    mul_10_mantissas(decimal_2, diff_of_exp);
    // если 2 степень больше то увеличиваем decimal_1
  } else if (diff_of_exp < 0) {
    mul_10_mantissas(decimal_1, diff_of_exp);
  }
}

/** @brief Перевод числа типа `big_decimal` в число типа `decimal`
 * @param big_decimal Число типа `big_decimal`
 * @param s21_decimal Число типа `decimal`
 * @return код ошибки:
 * `0` — OK;
 * `1` — число слишком велико или равно бесконечности;
 * `2` — число слишком мало или равно отрицательной бесконечности;
 * `3` — деление на 0.
 */
int translate_to_s21_decimal(s21_big_decimal *big_decimal,
                             s21_decimal *s21_decimal) {
  int error_status = S21_OK;
  if (big_decimal->sign == MINUS) set_minus(s21_decimal);
  get_position_of_senior_bit(big_decimal);
  unsigned int remainder = 0;

  s21_big_decimal ten = {0};
  ten.bits[0] = 10;
  while (big_decimal->exp > 28) {
    if (remainder > 0) big_decimal->digits_after = 1;
    if (comp_of_mantissas_for_big(*big_decimal, ten) == -1) {
      error_status = S21_ERROR_TOO_SMALL;
      // число уже меньше 10 а его все еще надо делить =>
      // ошибка 2 (число слишком мало)
      null_decimal(s21_decimal);
      break;
    }
    remainder = division_big_decimal_with_rest_10(*big_decimal, big_decimal);
  }
  if (error_status == 0) {
    while (big_decimal->senior_bit > (BITS_IN_3_INT - 1)) {
      if (remainder > 0) big_decimal->digits_after = 1;
      if (big_decimal->exp == 0) {
        // вот тут если мы понижали степень но все равно сюда зашли вернуть
        // ошибку 1 (число слишком велико)
        //  либо 2 если стоит минус
        if (big_decimal->sign == 1)
          error_status = S21_ERROR_TOO_SMALL;
        else
          error_status = S21_ERROR_TOO_BIG;
        null_decimal(s21_decimal);
        break;
      }
      remainder = division_big_decimal_with_rest_10(*big_decimal, big_decimal);
      get_position_of_senior_bit(big_decimal);
    }
    if (error_status == 0) {
      set_exp(s21_decimal, big_decimal->exp);
      bank_round(big_decimal, remainder);
      for (int i = 0; i < 3; i++) {
        s21_decimal->bits[i] = big_decimal->bits[i];
      }
    }
  }
  return error_status;
}

/** @brief Находим индекс старшего бита (первый значащий бит) числа типа
 * `big_decimal`
 * @param decimal Число типа `big_decimal`
 * @return `int`индекс старшего бита
 */
int get_position_of_senior_bit(s21_big_decimal *big_decimal) {
  int i;
  for (i = BITS_BIG_DECIMAL - 1; i >= 0; i--) {
    if (big_get_bit(*big_decimal, i) == 1) {
      big_decimal->senior_bit = i;
      break;
    }
  }
  return i;
}

/** @brief TODO Деление числа `big_decimal` на `10`
 * @param val1 делимое число `big_decimal`
 * @param res структура, куда записывается частное `big_decimal`
 */
unsigned int division_big_decimal_with_rest_10(s21_big_decimal val1,
                                               s21_big_decimal *res) {
  s21_big_decimal val2 = {0};
  val2.bits[0] = 10;
  // int scale_diff = val1.exp-val2.exp; // разность экспонент
  int q = 0;  // максимальная степень двойки умножение делителя на которую не
              // превысит делимое число
  s21_big_decimal part = {0};  // вычитаемое из делителя при найденном q
  s21_big_decimal part_next = {
      0};  // вычитаемое из делителя при найденном q+1 (остаток)
  s21_big_decimal sum = {0};  // текущая сумма -> станет ответом
  sum.digits_after = val1.digits_after;
  sum.sign = val1.sign;
  sum.exp = val1.exp;
  s21_big_decimal before_sum = {0};  // промежуточная сумма
  while (is_zero_big(val1) && comp_of_mantissas_for_big(val2, val1) <= 0) {
    q = 0;
    null_big_decimal(&part);
    null_big_decimal(&before_sum);
    part_next = val2;
    part = val2;
    int comp;  // переменная для сравнения
    while ((comp = comp_of_mantissas_for_big(part_next, val1)) <= 0) {
      part = part_next;  // перезаписываем промежуточное значение
      part_next = shift_big_decimal_to_left(
          part_next, 1);  // совершаем сдвиг -> умножение на 2
      q++;
    }
    q--;  // убираем одну степень двойки
    big_set_bit(&before_sum, q, 1);  // записываем в промежуточную сумму число
                                     // что получили по итогу в цикле
    big_add_of_mantissas(&sum, &before_sum,
                         &sum);  // суммируем промежуточную и основную суммы
    if (comp_of_mantissas_for_big(part, val1) <= 0) {
      big_sub_of_mantissas(
          val1, part, &val1);  // перезаписываем val1 для продолжения деления
    }
  }
  sum.exp = val1.exp - 1;
  get_position_of_senior_bit(&sum);
  *res = sum;
  return val1.bits[0];
}

/** @brief Банковское округление числа `2,65 = 3` `2,5 = 2` `3,5 = 4`
 * @param val1 Указатель на число типа `decimal`
 */
void bank_round(s21_big_decimal *val1,
                int rank) {  // 2, 65 = 3 // 2, 5 = 2 // 3, 5 = 4
  if (rank > 5 ||
      (rank == 5 && (big_get_bit(*val1, 0) || val1->digits_after))) {
    s21_big_decimal alone = {0};
    alone.bits[0] = 1;
    alone.exp = val1->exp;
    alone.sign = val1->sign;
    // при необходимости переписать в alone экспоненту и знак
    big_add_of_mantissas(val1, &alone, val1);
    if (get_position_of_senior_bit(val1) > BITS_IN_3_INT) {
      big_sub_of_mantissas(*val1, alone, val1);
      rank = division_big_decimal_with_rest_10(*val1, val1);
      bank_round(val1, rank);
    }
  }
}

/** @brief Заполняет число типа `decimal` `0`
 * @param decimal Число типа `decimal`
 */
void null_decimal(s21_decimal *decimal) {
  for (int i = 0; i < 4; i++) {
    decimal->bits[i] = 0;
  }
}

/** @brief Заполняет мантиссу числа типа `decimal` `1`
 * @param num Число типа `decimal`
 */
void full_decimal(s21_decimal *num) {
  for (int i = 0; i < 96; i++) {
    set_bit_int(num, i, 1);
  }
}