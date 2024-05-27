#include "s21_decimal.h"

/** @brief Печать в стандартный поток вывода числа типа int
 * в 32-разрядном битовом представлении
 * @param num десятичное число
 */
void print_binary(int num) {
  for (int i = 31; i >= 0; i--) {
    printf("%d", (num >> i) & 1);
    // fflush(stdout);
  }
  printf("\n");
}

/** @brief Печать в стандартный поток вывода числа типа decimal
 * в виде 4-х элементного массива, каждый в 32-разрядном
 * битовом представлении
 * @param dec структура числа децимал
 */
void print_decimal(s21_decimal dec) {
  for (int i = 3; i >= 0; i--) {
    printf("bit %d - ", i);
    print_binary(dec.bits[i]);
  }
  printf("\n");
}

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

/** @brief Изменение на противоположный определённого бита в числе типа decimal
 * @param dec адрес структуры числа типа decimal
 * @param bit_num нужный бит (от 0 до 127) числа типа decimal
 */
void toggle_bit(s21_decimal *dec, int bit_num) {
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

/** @brief Сравнение величин двух чисeл типа decimal, путём побитового
 * перебора мантисс, начиная со старшего бита.
 * Проводится до первого неравного бита.
 * @param value_1
 * @param value_2
 * @return Возвращает 1, если мантисса value_2 больше мантиссы value_1, иначе 0
 */
int decimal_cmp(s21_decimal value_1, s21_decimal value_2) {
  for (int i = BIT96; i >= 0; i--) {
    int v1 = get_bit(value_1, i);
    int v2 = get_bit(value_2, i);
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

/** @brief Производит побитовый сдвиг числа типа decimal.
 * @param dec Адрес заданного числа типа decimal
 * @param shift Минусовое значение соответствует сдвигу влево
 * @return возвращает 1 в случае переполнения при сдвиге влево
 */
int decimal_shift(s21_decimal *dec, int shift) {
  if (!shift) return 0;
  s21_decimal tmp = {0};
  int lendec = decimal_len(*dec), s21_error = 0;
  for (int i = lendec - 1; i >= BIT1; i--) {
    if (shift < 0) {
      if ((lendec - shift) > BITSIZE96) return s21_error = 1;
      set_bit(&tmp, i - shift, get_bit(*dec, i));
    } else if (shift > 0) {
      if (shift >= (i + 1)) break;
      set_bit(&tmp, i - shift, get_bit(*dec, i));
    }
  }
  decimal_clear(dec);
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
int bin2dec_last(s21_decimal dec) {
  int num = 0;
  int vals[] = {6, 2, 4, 8};
  int len = decimal_len(dec) - 1;
  if (get_bit(dec, BIT1)) num++;
  for (int i = BIT1 + 1; i <= len; i++) {
    BIT_STATE s = get_bit(dec, i);
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
void scale_normalize(s21_decimal *value_1, s21_decimal *value_2,
                     s21_decimal *result) {
  int sc1 = get_scale(*value_1);
  int sc2 = get_scale(*value_2);

  if (sc1 - sc2) {
    int rot = 0;
    s21_decimal tmp = {{0}};
    if (sc1 > sc2) rot = decimal_rotate(value_1, value_2);
    while (sc1 != sc2) {
      if (!s21_mul(*value_1, power10(abs(sc1 - sc2)), &tmp)) {
        *value_1 = tmp;
        break;
      }
      bank_rounding(value_2);
      sc1 = get_scale(*value_1);
      sc2 = get_scale(*value_2);
    }
    if (rot) decimal_rotate(value_1, value_2);
    if (sc1 > sc2) {
      set_scale(result, sc1);
      set_scale(value_2, sc1);
    } else {
      set_scale(result, sc2);
      set_scale(value_1, sc2);
    }
  } else {
    set_scale(result, sc1);
  }
}

/** @brief Получение числа типа decimal в степени `power`.
 * Степень должна быть больше нуля.
 * @param power степень десяти
 * @return Число типа decimal, умноженное на 10 в заданной степени
 */
s21_decimal power10(int power) {
  s21_decimal power10 = {{10, 0, 0, 0}};
  if (power == 0) {
    s21_decimal one = {{1, 0, 0, 0}};
    power10 = one;
  } else {
    s21_decimal ten = {{10, 0, 0, 0}};
    s21_decimal tmp = {{10, 0, 0, 0}};
    for (int i = 1; i < power; i++) {
      s21_mul(tmp, ten, &power10);
      tmp = power10;
    }
  }
  return power10;
}

/** @brief Банковское округление числа (`[x >= 0.6] = 1`,`[x < 0.4] = 0`
 * и `[x == *.5]` = округляется до ближайшего четного). В параметр `dec`
 * записывает результат округления и уменьшает степень на единицу.
 * @param dec Адрес числа типа decimal
 */
void bank_rounding(s21_decimal *dec) {
  int scale = get_scale(*dec);
  int sign = get_sign(*dec);
  int num = bin2dec_last(*dec);
  int mod10 = num % 10;
  set_positive(dec);
  set_scale(dec, 0);
  s21_decimal sub = {{mod10, 0, 0, 0}};
  s21_decimal result = {0};
  s21_decimal one = {{1, 0, 0, 0}};
  s21_decimal ten = {{10, 0, 0, 0}};
  s21_sub(*dec, sub, &result);
  s21_div(result, ten, dec);
  if (mod10 >= 5) {
    result = *dec;
    if (mod10 == 5) {
      int num_bank = bin2dec_last(*dec);
      if (num_bank % 2) s21_add(result, one, dec);
    } else {
      s21_add(result, one, dec);
    }
  }
  if (scale) set_scale(dec, scale - 1);
  if (sign) set_negative(dec);
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
int add_set_bit(s21_decimal *dec, int v1, int v2, int remainder, int i) {
  if (v1 == v2) {
    if (!remainder)
      set_bit(dec, i, bitzero);
    else
      set_bit(dec, i, bitone);
    if (v1)
      remainder = 1;
    else
      remainder = 0;
  } else {  // if (v1 || v2) {
    if (!remainder)
      set_bit(dec, i, bitone);
    else
      set_bit(dec, i, bitzero);
  }
  return remainder;
}

/** @brief Вспомогательная функция для операции вычитания. Выставляет биты.
 * @param dec Адрес числа типа decimal
 * @param v1 считанный бит делимого
 * @param v2 считанный бит делителя
 * @param borrow заём
 * @param i итератор
 * @return Единица в уме
 */
int sub_set_bit(s21_decimal *dec, int v1, int v2, int borrow, int i) {
  if (!v1 && v2) {  // v1 = 0, v2 = 1
    if (borrow)
      set_bit(dec, i, bitzero);
    else
      set_bit(dec, i, bitone);
    borrow = 1;
  } else if (v1 && !v2) {  // v1 = 1, v2 = 0
    set_bit(dec, i, v1 - borrow);
    borrow = 0;
  } else if (!v1 && !v2) {  // v1 == v2 == 0
    if (borrow)
      set_bit(dec, i, bitone);
    else
      set_bit(dec, i, bitzero);
  } else {  // v1 == v2 == 1
    if (borrow)
      set_bit(dec, i, bitone);
    else
      set_bit(dec, i, bitzero);
  }
  return borrow;
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
int mul_set_bit(AR_HELPER mul) {
  int s21_error = 0, shift = 0;
  for (int i = 0; i < mul.len2; i++) {
    int v2 = get_bit(mul.value_2, i);
    if (v2) {
      s21_decimal med = {0};
      s21_decimal tmp = {0};
      for (int j = 0; j < mul.len1; j++) {
        int v1 = get_bit(mul.value_1, j);
        if (v1 && v2)
          set_bit(&tmp, j, bitone);
        else
          set_bit(&tmp, j, bitzero);
      }
      if (!shift) {
        *(mul.result) = tmp;
        shift++;
        continue;
      }
      int lentmp = decimal_len(tmp);
      if ((lentmp + shift) > BITSIZE96) {
        if (mul.sign) set_negative(&tmp);
        *(mul.result) = tmp;
        return s21_exit_error(mul.result);
      }
      decimal_shift(&tmp, -shift);
      s21_error = s21_add(*(mul.result), tmp, &med);
      *(mul.result) = med;
      if (s21_error) return s21_exit_error(mul.result);
    }
    shift++;
  }
  return s21_error;
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
int div_set_bit(AR_HELPER div) {
  int s21_borrow = 0, fract = 0, steps = 0;
  int init_scale = div.scale;
  int overflow = 0;
  s21_decimal tmp = {0};
  s21_decimal tmpresult = {0};
  for (int i = 0; i < div.len1; i++) {  // выставили целые числа
    int curbit = div_bit_long_div(div, &s21_borrow, i, tmp, &tmpresult, fract);

    if (i == curbit &&
        !decimal_is_null(div.remainder)) {  // работа с дробной частью
      fract = 1;
      steps++;
      if (steps + init_scale <= 29 && !overflow)
        s21_add(*(div.result), tmpresult, div.result);  // TODO: переполнение?

      if ((steps + init_scale > 28) || overflow || div.scale > 27) {
        if (decimal_is_null(div.result)) return 2;
        div_bank_rounding(div, overflow);
        break;
      }
      if (div_rem_normalize(div, &overflow, &(div.scale), &(div.value_2)))
        return 1;

      div.value_1 = *(div.remainder);
      div.len1 = decimal_len(div.value_1);
      i = -1;
      s21_borrow = 0;
    } else if (i == curbit) {
      steps++;
      if (!overflow)
        s21_add(*(div.result), tmpresult, div.result);  // TODO: переполнение?
      if (overflow) {
        *(div.remainder) = div.value_1;
        div_bank_rounding(div, overflow);
      }
      if (div.scale < 0) {
        int s21_error =
            s21_mul(*(div.result), power10(abs(div.scale)), div.result);
        if (s21_error) return s21_error;
      }
      set_scale(div.result, div.scale);
    }
  }
  return 0;
}

/** @brief Вспомогательная функция деления. Производит побитовое деление в
 * столбик для целых и дробных чисел
 * @return Возвращает положение обрабатываемого бита.
 */
int div_bit_long_div(AR_HELPER div, int *s21_borrow, int i, s21_decimal tmp,
                     s21_decimal *tmpresult, int fract) {
  int curbit = div.len1 - 1;
  if (*s21_borrow) {
    decimal_shift(div.remainder, -1);
    int takebit = get_bit(div.value_1, curbit - i);
    set_bit(div.remainder, BIT1, takebit);
  } else {
    tmp = div.value_1;
    decimal_shift(&tmp, curbit - i);
    *(div.remainder) = tmp;
  }

  if (!decimal_cmp(*(div.remainder), div.value_2)) {
    if (!fract)
      set_bit(div.result, curbit - i, bitone);
    else
      set_bit(tmpresult, curbit - i, bitone);

    if (*s21_borrow) tmp = *(div.remainder);
    s21_sub(tmp, div.value_2, div.remainder);
    *s21_borrow = 1;
  } else {
    if (!fract)
      set_bit(div.result, curbit - i, bitzero);  // запись в целую часть
    else
      set_bit(tmpresult, curbit - i, bitzero);
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

/** @brief Вспомогательная функция для операции деления.
 * Производит банковское округление при значениях не влезающих в мантиссу.
 * @param div структура с упакованными ключевыми параметрами расчёта
 */
void div_bank_rounding(AR_HELPER div, int overflow) {
  int prev = bin2dec_last(*(div.result));
  while (decimal_cmp(*(div.remainder), div.value_2)) {
    s21_mul(*(div.remainder), power10(1), div.remainder);
  }
  if (!overflow) div.value_1 = *(div.remainder);
  s21_decimal br_tmp = {0};
  s21_decimal br_tmprem = {0};
  s21_decimal br_tmpres = {0};
  AR_HELPER div_br =
      ar_cons(NULL, div.value_1, div.value_2, &br_tmprem, div.len1, 0, 0, 0);
  int br_borrow = 0;
  for (int i = 0; i < div.len1; i++) {
    div_bit_long_div(div_br, &br_borrow, i, br_tmp, &br_tmpres, 1);
  }
  int next = bin2dec_last(br_tmpres);

  set_scale(div.result, div.scale);
  s21_decimal one = {{1, 0, 0, 0}};
  set_scale(&one, div.scale);
  if (next >= 5) {
    if (next == 5) {
      if (prev % 2) s21_add(*(div.result), one, div.result);
    } else {
      s21_add(*(div.result), one, div.result);
    }
  }
}

/** @brief Вспомогательная функция для операции деления.
 * Производит домножение остатка на 10, если он слишком мал
 * в сравнении с делителем. Также домножает мантиссу ответа
 * и увеличивает степень на один.
 * @return Возвращет единицу, если значение мантиссы после
 * домножения на 10 слишком большое
 */
int div_rem_normalize(AR_HELPER div, int *overflow, int *scale,
                      s21_decimal *tmpvalue) {
  int isover = 0;
  while (decimal_cmp(*(div.remainder), div.value_2)) {
    s21_decimal save_res = *(div.result);
    s21_decimal save_rem = *(div.remainder);
    if (*scale <= 28) {
      *overflow = s21_mul(*(div.result), power10(1), div.result);
      if (*overflow) {
        if (*scale < 0) return isover = 1;  // слишком большое значение
        *(div.result) = save_res;
        s21_mul(*(div.remainder), power10(1), div.remainder);
        set_scale(div.result, *scale);
        break;
      }
      *scale = ++div.scale;
    }
    int overflow_rem = s21_mul(*(div.remainder), power10(1), div.remainder);
    if (overflow_rem) {
      *(div.remainder) = save_rem;
      bank_rounding(&(div.value_2));
      *(tmpvalue) = div.value_2;
    }
  }
  return isover;
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