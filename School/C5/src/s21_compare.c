#include "s21_decimal.h"

// 0 - false, 1 - true
int s21_is_less(s21_decimal value_1, s21_decimal value_2) {
  int status = pre_work_compresion(value_1, value_2);
  status = (status == -1 ? 1 : 0);  // если нам вернулось -1, то первое число
                                    // меньше второго, значит возвращаем true
  return status;
}

int s21_is_less_or_equal(s21_decimal value_1, s21_decimal value_2) {
  int status = pre_work_compresion(value_1, value_2);
  status = (((status == -1) || (status == 0))
                ? 1
                : 0);  // если нам вернулось -1 или 0, то первое число меньше
                       // второго или равно значит возвращаем true
  return status;
}

int s21_is_greater(s21_decimal value_1, s21_decimal value_2) {
  int status = pre_work_compresion(value_1, value_2);
  status = ((status == 1) ? 1 : 0);  // если нам вернулось 1, то первое число
                                     // больше второго, значит возвращаем true
  return status;
}

int s21_is_greater_or_equal(s21_decimal value_1, s21_decimal value_2) {
  int status = pre_work_compresion(value_1, value_2);
  status = (((status == 1) || (status == 0))
                ? 1
                : 0);  // если нам вернулось 1 или 0, то первое число больше
                       // второго или равно, значит возвращаем true
  return status;
}

int s21_is_equal(s21_decimal value_1, s21_decimal value_2) {
  int status = pre_work_compresion(value_1, value_2);
  ;
  status = ((status == 0) ? 1 : 0);  // если нам вернулось 0, то первое число ==
                                     // второму, значит возвращаем true
  return status;
}

int s21_is_not_equal(s21_decimal value_1, s21_decimal value_2) {
  int status = pre_work_compresion(value_1, value_2);
  status = ((status != 0)
                ? 1
                : 0);  //если нам вернулось что угодно только не 0, то первое
                       //число не равно второму, значит возвращаем true
  return status;
}

// 1 если децимал_1 больше, -1 если децимал_2 больше, 0 если равно
int pre_work_compresion(s21_decimal value_1, s21_decimal value_2) {
  int res = 0;
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
  // строки выше это начало работы. переводим числа в биг децемал и нормализуем
  // их. создаём переменные для хранения знаков а также флажок одинаковых знаков
  if (is_sign_equal) {  //если знаки у чисел одинаковые
    if (is_value_1_negative) {  //и оба знака отрицательные
      res = (comp_of_mantissas(v_1, v_2));
      if (res == 1)
        res = -1;  //если по модулю первое число больше, то меняем результат
      else if (res == -1)
        res = 1;
      // так как например (-5 < -2). а функция комп сравнивает тольео мантисы
    } else {
      res = (comp_of_mantissas(v_1, v_2));
      // иначе если оба знака положительные, то возвращаем обычный результат
      // сравнения
    }       // 1 или -1
  } else {  // сюда заходим если числа имеют разные знаки
    if ((is_value_1_negative) && !(is_value_2_negative)) {
      // если например (-1 и 1) то рез = -1 так как второе число больше
      res = -1;
    } else if (!(is_value_1_negative) && (is_value_2_negative))
      res = 1;  //тут наоборот если (1 и -1) то рез = 1 так как первое число
                //конечно же больше
  }
  if (comp_of_mantissas_for_big(b_value_1, nul) == 0 &&
      comp_of_mantissas_for_big(b_value_2, nul) == 0)
    res = 0;
  return res;
  //возвращаем резльтат -1 1 или 0, чтобы раскидаться в функциях сравнения
}