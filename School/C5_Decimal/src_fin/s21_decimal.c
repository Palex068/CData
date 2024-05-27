#include "s21_decimal.h"

/** @brief Получение значения определённого бита в числе типа decimal
 * @param dec адрес структуры числа децимал
 * @param bit_num нужный бит (от 0 до 127) числа типа decimal
 * @return Состояние бита (1 или 0)
 */
BIT_STATE get_bit(s21_decimal dec, int bit_num) {
  int bit_index = bit_num / BITSIZE32;
  int bit_shift = bit_num % BITSIZE32;
  return (dec.bits[bit_index] >> bit_shift) & bitone;
}

BIT_STATE ar_big_get_bit(ar_big_decimal dec, int bit_num) {
  int bit_index = bit_num / BITSIZE32;
  int bit_shift = bit_num % BITSIZE32;
  return (dec.bits[bit_index] >> bit_shift) & bitone;
}

/** @brief Выставление определённого бита в числе типа decimal
 * @param dec адрес структуры числа типа decimal
 * @param bit_num нужный бит (от 0 до 127) числа типа decimal
 * @param bit_state перечислимый тип состояния бита (bitzero
 *  или bitone)
 */
void set_bit(s21_decimal *dec, int bit_num, BIT_STATE bit_state) {
  int bit_index = bit_num / BITSIZE32;
  int bit_shift = bit_num % BITSIZE32;
  if (get_bit(*dec, bit_num) && bit_state == bitzero)
    toggle_bit(dec, bit_num);
  else
    dec->bits[bit_index] |= bit_state << bit_shift;
}

void ar_big_set_bit(ar_big_decimal *dec, int bit_num, BIT_STATE bit_state) {
  int bit_index = bit_num / BITSIZE32;
  int bit_shift = bit_num % BITSIZE32;
  if (ar_big_get_bit(*dec, bit_num) && bit_state == bitzero)
    big_toggle_bit(dec, bit_num);
  else
    dec->bits[bit_index] |= bit_state << bit_shift;
}

/** @brief Изменение на противоположный определённого бита в числе типа decimal
 * @param dec адрес структуры числа типа decimal
 * @param bit_num нужный бит (от 0 до 127) числа типа decimal
 */
void toggle_bit(s21_decimal *dec, int bit_num) {
  int bit_index = bit_num / BITSIZE32;
  int bit_shift = bit_num % BITSIZE32;
  dec->bits[bit_index] ^= bitone << bit_shift;
}

void big_toggle_bit(ar_big_decimal *dec, int bit_num) {
  int bit_index = bit_num / BITSIZE32;
  int bit_shift = bit_num % BITSIZE32;
  dec->bits[bit_index] ^= bitone << bit_shift;
}

/** @brief Очищает число типа decimal
 *
 */
void decimal_clear(s21_decimal *dec) {
  for (int i = BIT128; i >= BIT1; i--) {
    set_bit(dec, i, bitzero);
  }
}

void big_decimal_clear(ar_big_decimal *dec) {
  for (int i = BIT256; i >= BIT1; i--) {
    ar_big_set_bit(dec, i, bitzero);
  }
}

/** @brief Сравнение величин двух чисeл типа decimal, путём побитового
 * перебора мантисс, начиная со старшего бита.
 * Проводится до первого неравного бита.
 * @param value_1
 * @param value_2
 * @return Возвращает 1, если мантисса value_2 больше мантиссы value_1, иначе 0
 */
int big_decimal_cmp(ar_big_decimal value_1, ar_big_decimal value_2) {
  for (int i = BIT256; i >= 0; i--) {
    int v1 = ar_big_get_bit(value_1, i);
    int v2 = ar_big_get_bit(value_2, i);
    if (v2 > v1)
      return 1;
    else if (v1 > v2)
      break;
  }
  return 0;
}

/** @brief Побитовое сравнение двух чисел типа decimal
 * @param value_1
 * @param value_2
 * @param high_bit
 * @param low_bit
 * @return Возвращает единицу, если числа типа decimal из заданного диапазона
 * бит равны
 */
int decimal_bit_eq(s21_decimal value_1, s21_decimal value_2, int high_bit,
                   int low_bit) {
  int s21_true = 1;
  for (int i = high_bit; i >= low_bit; i--) {
    int v1 = get_bit(value_1, i);
    int v2 = get_bit(value_2, i);
    if (v1 != v2) {
      s21_true = 0;
      break;
    }
  }
  return s21_true;
}

/** @brief Вычисление длины числа типа decimal.
 * Используется в операции умножения
 * @param dec
 * @return Возвращает количество бит в числе типа decimal
 */
int decimal_len(s21_decimal dec) {
  for (int i = BIT96; i >= 0; i--)
    if (get_bit(dec, i)) return i + 1;
  return 0;
}

int big_decimal_len(ar_big_decimal dec) {
  for (int i = BIT256; i >= 0; i--)
    if (ar_big_get_bit(dec, i)) return i + 1;
  return 0;
}

/** @brief Првоверяет значение целого числа типа decimal.
 * @param dec число типа decimal
 * @return Возвращает единицу, если int'ы целого числа типа decimal равны нулю.
 * Также обнуляет коэффициент масштабирования, если число нулевое.
 */
int decimal_is_null(s21_decimal *dec) {
  int s21_null = 1;
  for (int i = 0; i < 3; i++) {
    if (dec->bits[i] != 0) {
      s21_null = 0;
      break;
    }
  }
  if (s21_null) dec->bits[3] = 0;
  return s21_null;
}

int big_decimal_is_null(ar_big_decimal *dec) {
  int s21_null = 1;
  for (int i = 0; i <= 7; i++) {
    if (dec->bits[i] != 0) {
      s21_null = 0;
      break;
    }
  }
  return s21_null;
}

/** @brief Определяет знак числа типа decimal
 * @return Возвращает значение 127-го бита
 */
int get_sign(s21_decimal dec) { return get_bit(dec, 127); }

/** @brief Выставляет число типа decimal отрицательным
 *
 */
void set_negative(s21_decimal *dec) { set_bit(dec, 127, bitone); }

/** @brief Выставляет число типа decimal положительным
 *
 */
void set_positive(s21_decimal *dec) { set_bit(dec, 127, bitzero); }

/** @brief Меняет местами значения двух чисел типа decimal
 * @return Всегда возвращает единицу
 */
int decimal_rotate(s21_decimal *value_1, s21_decimal *value_2) {
  s21_decimal tmp = {0};
  tmp = *value_1;
  *value_1 = *value_2;
  *value_2 = tmp;
  return 1;
}

int big_decimal_rotate(ar_big_decimal *value_1, ar_big_decimal *value_2) {
  ar_big_decimal tmp = {0};
  tmp = *value_1;
  *value_1 = *value_2;
  *value_2 = tmp;
  return 1;
}

/** @brief Производит побитовый сдвиг числа типа decimal.
 * @param dec Адрес заданного числа типа decimal
 * @param shift Минусовое значение соответствует сдвигу влево
 * @return возвращает 1 в случае переполнения при сдвиге влево
 */
int big_decimal_shift(ar_big_decimal *dec, int shift) {
  if (!shift) return 0;
  ar_big_decimal tmp = {0};
  int lendec = big_decimal_len(*dec), s21_error = 0;
  for (int i = lendec - 1; i >= BIT1; i--) {
    if (shift < 0) {
      if ((lendec - shift) > BITSIZE256) return s21_error = 1;
      ar_big_set_bit(&tmp, i - shift, ar_big_get_bit(*dec, i));
    } else if (shift > 0) {
      if (shift >= (i + 1)) break;
      ar_big_set_bit(&tmp, i - shift, ar_big_get_bit(*dec, i));
    }
  }
  big_decimal_clear(dec);
  *dec = tmp;
  return s21_error;
}

/** @brief Преобразует заданное количество битов числа типа decimal в десятичное
 * представление. Максимально unsigned int
 * @param dec число типа decimal
 * @param high_bit старший бит
 * @param low_bit младший бит
 * @return заданные биты в десятичном виде
 */
unsigned int bin2dec(s21_decimal dec, int high_bit, int low_bit) {
  unsigned int num = 0;
  for (int i = high_bit; i >= low_bit; i--) {
    BIT_STATE s = get_bit(dec, i);
    num *= 2;
    if (s == 1) num += 1;
  }
  return num;
}

/** @brief Высчитывает десятичное число стоящее с правого края. @r
 * Quote form math.stackexchange:
 * From right to left, the binary place values (mod 10) are 1,2,4,8,6,2,4,8,6,…
 * You can add the reduced (mod 10) place values with 1s in them,
 * and then mod your answer by ten.
 * In your example, 11001, you would add 8+6+0+0+1=15≡5(mod10)
 * @param dec число типа decimal
 * @return Десятичная цифра
 */
int big_bin2dec_last(ar_big_decimal dec) {
  int num = 0;
  int vals[] = {6, 2, 4, 8};
  int len = big_decimal_len(dec) - 1;
  if (ar_big_get_bit(dec, BIT1)) num++;
  for (int i = BIT1 + 1; i <= len; i++) {
    BIT_STATE s = ar_big_get_bit(dec, i);
    if (s) num += vals[i % 4];
  }
  return num % 10;
}

/** @brief Считывает коэффициент масштабирования числа типа decimal @r
 * Bits 0 to 15, the lower word, are unused and must be zero.
 * Bits 16 to 23 must contain an exponent between 0 and 28, which indicates the
 * power of 10 to divide the integer number. Bits 24 to 30 are unused and must
 * be zero. Bit 31 contains the sign; 0 meaning positive, and 1 meaning
 * negative.
 * @param dec Число типа decimal
 * @return Коэффициент масштабирования числа типа decimal в десятичном виде
 */
int get_scale(s21_decimal dec) { return bin2dec(dec, BIT23SCALE, BIT16SCALE); }

/** @brief Выставляет коэффициент мастабирования числа типа decimal
 * @param dec Адрес числа типа decimal
 * @param scale Степень в десятичном виде (от 0 до 28)
 */
void set_scale(s21_decimal *dec, int scale) {
  // TODO: добавить обратотку значений scale меньше нуля.
  if (!scale) {
    for (int i = BIT16SCALE; i <= BIT23SCALE; i++) {
      set_bit(dec, i, bitzero);
    }
  } else {
    for (int i = 0; scale > 0; i++) {
      set_bit(dec, BIT16SCALE + i, scale % 2);
      scale /= 2;
    }
  }
}

/** @brief Приведение коэффициента масштабироваия чисел типа decimal к
 * общему знаменателю. Выставляет выравненные коэффициенты во всех параметрах.
 * @param value_1 число типа decimal
 * @param value_2 число типа decimal
 * @param result число типа decimal
 */
int big_scale_normalize(ar_big_decimal *value_1, ar_big_decimal *value_2,
                        int sc1, int sc2) {
  int scale = sc1;
  if (sc2 > sc1) scale = sc2;
  if (sc1 - sc2) {
    int rot = 0;
    if (sc1 > sc2) rot = big_decimal_rotate(value_1, value_2);
    while (sc1 != sc2) {
      *value_1 = big_power10(*value_1, 1);  // TODO: сделать разницой степеней
      if (rot)
        sc1--;
      else
        sc2--;
    }
    if (rot) big_decimal_rotate(value_1, value_2);
  }
  return scale;
}

/** @brief Получение числа типа decimal в степени `power`.
 * Степень должна быть больше нуля.
 * @param power степень десяти
 * @return Число типа decimal, умноженное на 10 в заданной степени
 */
ar_big_decimal big_power10(ar_big_decimal dec, int power) {
  ar_big_decimal result = {{0}};
  ar_big_decimal ten = {{10, 0, 0, 0, 0, 0, 0, 0}};
  int b_tenlen = big_decimal_len(ten);
  for (int i = 0; i < power; i++) {
    int b_dec = big_decimal_len(dec);
    AR_BIG_HELPER b_mul = ar_big_cons(&result, dec, ten, NULL, b_dec, b_tenlen);
    mul_big_set_bit(b_mul);
    big_dec_cpy(result, &dec);
    big_decimal_clear(&result);
  }
  return dec;
}

/** @brief Делит на 10 числа заканчивающиеся на ноль*/
ar_big_decimal big_div10(ar_big_decimal dec, int power) {
  if (big_bin2dec_last(dec) != 0) return dec;

  ar_big_decimal result = {{0}};
  ar_big_decimal remainder = {{0}};
  ar_big_decimal ten = {{10, 0, 0, 0, 0, 0, 0, 0}};
  int b_tenlen = big_decimal_len(ten);

  for (int i = 0; i < power; i++) {
    int b_dec = big_decimal_len(dec);
    AR_BIG_HELPER b_div =
        ar_big_cons(&result, dec, ten, &remainder, b_dec, b_tenlen);
    div_big_set_bit(b_div);
    big_dec_cpy(result, &dec);
    big_decimal_clear(&result);
  }
  return dec;
}

/** @brief Банковское округление числа (`[x >= 0.6] = 1`,`[x < 0.4] = 0`
 * и `[x == *.5]` = округляется до ближайшего четного). В параметр `dec`
 * записывает результат округления и уменьшает степень на единицу.
 * @param dec Адрес числа типа decimal
 */
void big_bank_rounding(ar_big_decimal *dec) {
  int num = big_bin2dec_last(*dec);
  int mod10 = num % 10;
  ar_big_decimal sub = {{mod10, 0, 0, 0, 0, 0, 0, 0}};
  ar_big_decimal result = {0};
  ar_big_decimal one = {{1, 0, 0, 0, 0, 0, 0, 0}};
  // ar_big_decimal ten = {{10, 0, 0, 0, 0 , 0 , 0 , 0}};
  // s21_sub(*dec, sub, &result);
  big_long_sub(*dec, sub, &result);
  // s21_div(result, ten, dec);
  *dec = big_div10(result, 1);
  if (mod10 >= 5) {
    result = *dec;
    if (mod10 == 5) {
      int num_bank = big_bin2dec_last(*dec);
      if (num_bank % 2) big_long_add(result, one, dec);
    } else {
      // s21_add(result, one, dec);
      big_long_add(result, one, dec);
    }
  }
}

/** @brief Дополнительный код (2's complement). Преобразует UINT
 * в отрицательный int
 * @param num число которое преобразуется в отрицательный int
 * @return Возвращает преобразованный int
 */
int scomp(long num) {
  if (num > 2147483647) num = -(4294967295 - num + 1);
  return num;
}

/** @brief  Копирование структуры big decimal
 * @param from
 * @param to
 */
void big_dec_cpy(ar_big_decimal from, ar_big_decimal *to) {
  for (int i = 0; i <= 7; i++) {
    to->bits[i] = from.bits[i];
  }
}

/** @brief Выход с ошибкой с очищением числа типа decimal
 *  @return Возвращается int с кодом ошибки
 * 0 — OK;
 * 1 — число слишком велико или равно бесконечности;
 * 2 — число слишком мало или равно отрицательной бесконечности;
 * 3 — деление на 0.
 */
int s21_exit_error(s21_decimal *dec) {
  int s21_error = 0;
  if (!get_sign(*dec))
    s21_error = 1;
  else
    s21_error = 2;
  decimal_clear(dec);
  return s21_error;
}

/** @brief Вспомогательная функция для операции сложения. Выставляет биты.
 * @param dec Адрес числа типа decimal
 * @param v1 считанный бит первого слагаемого
 * @param v2 считанный бит второго слагаемого
 * @param remainder остаток
 * @param i итератор
 * @return Единица в уме
 */
int add_big_set_bit(ar_big_decimal *dec, int v1, int v2, int remainder, int i) {
  if (v1 == v2) {
    if (!remainder)
      ar_big_set_bit(dec, i, bitzero);
    else
      ar_big_set_bit(dec, i, bitone);
    if (v1)
      remainder = 1;
    else
      remainder = 0;
  } else {  // if (v1 || v2) {
    if (!remainder)
      ar_big_set_bit(dec, i, bitone);
    else
      ar_big_set_bit(dec, i, bitzero);
  }
  return remainder;
}

/** @brief Побитовое сложение в столбик без всего*/
void big_long_add(ar_big_decimal value_1, ar_big_decimal value_2,
                  ar_big_decimal *result) {
  int b_rem = 0;
  for (int i = 0; i < BITSIZE256; i++) {
    int v1 = ar_big_get_bit(value_1, i);
    int v2 = ar_big_get_bit(value_2, i);
    b_rem = add_big_set_bit(result, v1, v2, b_rem, i);
  }
}

/** @brief Вспомогательная функция для операции вычитания. Выставляет биты.
 * @param dec Адрес числа типа decimal
 * @param v1 считанный бит делимого
 * @param v2 считанный бит делителя
 * @param borrow заём
 * @param i итератор
 * @return Единица в уме
 */
int sub_big_set_bit(ar_big_decimal *dec, int v1, int v2, int borrow, int i) {
  if (!v1 && v2) {  // v1 = 0, v2 = 1
    if (borrow)
      ar_big_set_bit(dec, i, bitzero);
    else
      ar_big_set_bit(dec, i, bitone);
    borrow = 1;
  } else if (v1 && !v2) {  // v1 = 1, v2 = 0
    ar_big_set_bit(dec, i, v1 - borrow);
    borrow = 0;
  } else if (!v1 && !v2) {  // v1 == v2 == 0
    if (borrow)
      ar_big_set_bit(dec, i, bitone);
    else
      ar_big_set_bit(dec, i, bitzero);
  } else {  // v1 == v2 == 1
    if (borrow)
      ar_big_set_bit(dec, i, bitone);
    else
      ar_big_set_bit(dec, i, bitzero);
  }
  return borrow;
}

/** @brief Побитовое вычитание в столбик без всего*/
void big_long_sub(ar_big_decimal value_1, ar_big_decimal value_2,
                  ar_big_decimal *result) {
  int b_borrow = 0;
  for (int i = 0; i < BITSIZE256; i++) {
    int v1 = ar_big_get_bit(value_1, i);
    int v2 = ar_big_get_bit(value_2, i);
    b_borrow = sub_big_set_bit(result, v1, v2, b_borrow, i);
  }
}

/** @brief Вспомогательная функция для операции уножения. Выставляет биты.
 * Также записывает в `result` произведённые вычисления.
 * @param mul структура для компактной упаковки ключевых параметров расчёта
 * @return Возвращается int с кодом ошибки
 * 0 — OK;
 * 1 — число слишком велико или равно бесконечности;
 * 2 — число слишком мало или равно отрицательной бесконечности;
 * 3 — деление на 0.
 */
int mul_big_set_bit(AR_BIG_HELPER mul) {
  int shift = 0;
  for (int i = 0; i < mul.len2; i++) {
    int v2 = ar_big_get_bit(mul.value_2, i);
    if (v2) {
      ar_big_decimal b_med = {0};
      ar_big_decimal b_tmp = {0};
      for (int j = 0; j < mul.len1; j++) {
        int v1 = ar_big_get_bit(mul.value_1, j);
        if (v1)  // && v2)
          ar_big_set_bit(&b_tmp, j, bitone);
        else
          ar_big_set_bit(&b_tmp, j, bitzero);
      }
      if (!shift) {
        *(mul.result) = b_tmp;
        shift++;
        continue;
      }
      big_decimal_shift(&b_tmp, -shift);
      big_long_add(*(mul.result), b_tmp, &b_med);
      *(mul.result) = b_med;
    }
    shift++;
  }
  return 0;
}

/** @brief Вспомогательная функция для операции деления. Выставляет биты.
 * Также записывает в `result` произведённые вычисления.
 * @param div структура для компактной упаковки ключевых параметров расчёта
 * @return Возвращается int с кодом ошибки
 * 0 — OK;
 * 1 — число слишком велико или равно бесконечности;
 * 2 — число слишком мало или равно отрицательной бесконечности;
 * 3 — деление на 0.
 */
int div_big_set_bit(AR_BIG_HELPER div) {
  int s21_borrow = 0, fract = 0, steps = 0;
  ar_big_decimal tmp = {0};
  ar_big_decimal tmpres = {0};
  for (int i = 0; i < div.len1; i++) {  // выставили целые числа
    int curbit = div_big_bit_long_div(div, &s21_borrow, i, tmp, &tmpres, fract);
    if (i == curbit &&
        !big_decimal_is_null(div.remainder)) {  // работа с дробной частью
      if (!steps && big_decimal_len(*(div.result)) > BITSIZE96)
        return -1;  // FIXME: через steps передается ошибка переполнения целой
                    // части
      fract = 1;
      steps++;
      if (steps <= 30) {
        // if (steps <= 75) {
        big_long_add(*(div.result), tmpres, div.result);
      }
      if (steps > 29) {
        // if (steps > 74) {
        steps--;  // NOTE: для банковского округления,
        break;
      }
      *(div.result) = big_power10(*(div.result), 1);
      div.value_1 = big_power10(*(div.remainder), 1);
      div.len1 = big_decimal_len(div.value_1);
      i = -1;
      s21_borrow = 0;
    } else if (i == curbit) {
      if (steps) {
        // TODO: сложение в столбик
        big_long_add(*(div.result), tmpres, div.result);
      }
    }
  }
  return steps;
}

/** @brief Вспомогательная функция деления. Производит побитовое деление в
 * столбик для целых и дробных чисел
 * @return Возвращает положение обрабатываемого бита.
 */
int div_big_bit_long_div(AR_BIG_HELPER div, int *s21_borrow, int i,
                         ar_big_decimal tmp, ar_big_decimal *tmpresult,
                         int fract) {
  int curbit = div.len1 - 1;
  if (*s21_borrow) {
    big_decimal_shift(div.remainder, -1);
    int takebit = ar_big_get_bit(div.value_1, curbit - i);
    ar_big_set_bit(div.remainder, BIT1, takebit);
  } else {
    tmp = div.value_1;
    big_decimal_shift(&tmp, curbit - i);
    *(div.remainder) = tmp;
  }
  if (!big_decimal_cmp(*(div.remainder), div.value_2)) {
    if (!fract)
      ar_big_set_bit(div.result, curbit - i, bitone);
    else
      ar_big_set_bit(tmpresult, curbit - i, bitone);
    if (*s21_borrow) tmp = *(div.remainder);

    big_long_sub(tmp, div.value_2, div.remainder);
    *s21_borrow = 1;
  } else {
    if (!fract)
      ar_big_set_bit(div.result, curbit - i, bitzero);  // запись в целую часть
    else
      ar_big_set_bit(tmpresult, curbit - i, bitzero);
  }
  return curbit;
}

/** @brief Вспомогательная функция при одинаковых делимом и делителе.
 * Частное всегда единица, коэф. масштабирования ноль.
 * @param h структура с упакованными ключевыми параметрами расчёта
 * @return Возвращает единицу, если сравниваемые числа типа decimal равны.
 * Выставляет в `result` единицу и знак.
 */
int div_equals(AR_HELPER h) {
  int is_eq = 0;
  if (decimal_bit_eq(h.value_1, h.value_2, BIT127, BIT1)) {
    s21_decimal one = {{1, 0, 0, 0}};
    *(h.result) = one;
    if (h.sign) set_negative(h.result);
    is_eq = 1;
  }
  return is_eq;
}

/** @brief Вспомогательная функция при делении на ноль.
 * Обнуляет число типа decimal.
 * @param h структура с упакованными ключевыми параметрами расчёта
 * @return Возвращает ошибку 3.
 * Выставляет в `result` нули.
 */
int div_by_zero(s21_decimal value_2) {
  int devisor_is_zero = 0;
  if (decimal_is_null(&value_2)) {
    devisor_is_zero = 3;
  }
  return devisor_is_zero;
}

/** @brief Квази-конструктор для структуры AR_HELPER
 * @param r result
 * @param v1 value_1
 * @param v2 value_2
 * @param l1 len1
 * @param l2 len2
 * @param si sign
 * @param sc scale
 * @return Возвращает наполненную структуру
 */
AR_HELPER ar_cons(s21_decimal *r, s21_decimal v1, s21_decimal v2,
                  s21_decimal *rm, int l1, int l2, int si, int sc) {
  AR_HELPER m = {0};
  m.result = r;
  m.value_1 = v1;
  m.value_2 = v2;
  m.remainder = rm;
  m.len1 = l1;
  m.len2 = l2;
  m.sign = si;
  m.scale = sc;
  return m;
}

AR_BIG_HELPER ar_big_cons(ar_big_decimal *r, ar_big_decimal v1,
                          ar_big_decimal v2, ar_big_decimal *rm, int l1,
                          int l2) {
  AR_BIG_HELPER m = {0};
  m.result = r;
  m.value_1 = v1;
  m.value_2 = v2;
  m.remainder = rm;
  m.len1 = l1;
  m.len2 = l2;
  return m;
}

/** @brief Конвертер из обычного децимал в биг децимал
 *
 */
ar_big_decimal dec2big_converter(s21_decimal dec) {
  ar_big_decimal big_dec = {0};
  for (int i = 0; i < 3; i++) {
    big_dec.bits[i] = dec.bits[i];
  }
  return big_dec;
}

/** @brief Конвертер из биг децимал в обычный.
 * Производит банковское округление и отслеживает
 * ошибки преполнения (не все)
 *
 */
int big2dec_converter(ar_big_decimal big_dec, s21_decimal *dec, int scale) {
  int s21_error = 0, round = 0;
  int b_len = big_decimal_len(big_dec);
  // if (b_len > BITSIZE96) {
  while (b_len > BITSIZE96) {
    if (scale == 0) return s21_exit_error(dec);
    scale--;
    big_bank_rounding(&big_dec);
    b_len = big_decimal_len(big_dec);
    round = 1;
  }

  if (scale > 28) {
    while (scale > 28) {
      big_bank_rounding(&big_dec);
      scale--;
    }
    round = 1;
  }

  for (int i = 0; i < 3; i++) {
    dec->bits[i] = big_dec.bits[i];
  }
  if (round && big_decimal_is_null(&big_dec))
    s21_error = 2;
  else
    set_scale(dec, scale);
  return s21_error;
}