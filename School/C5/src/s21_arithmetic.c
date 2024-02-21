#include "s21_decimal.h"

// Функции возвращают код ошибки:

// 0 - OK
// 1 - число слишком велико или равно бесконечности
// 2 - число слишком мало или равно отрицательной бесконечности
// 3 - деление на 0

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int error_status = S21_OK;
  if (result == NULL) {
    error_status = S21_ERROR;
  } else {
    s21_big_decimal b_value_1 = {0}, b_value_2 = {0}, b_result = {0};
    null_decimal(result);
    translate_to_big(value_1, &b_value_1);
    translate_to_big(value_2, &b_value_2);
    normalization(&b_value_1, &b_value_2);
    //если у первого или второго знак отрицательный то надо вычитать
    int is_value_1_negative = get_sign(value_1) == MINUS;
    int is_value_2_negative = get_sign(value_2) == MINUS;
    if (is_value_1_negative || is_value_2_negative) {
      if (is_value_1_negative == is_value_2_negative) {
        //если знаки равны и оба минус то надо сложить и потом просто в 1 бит
        //записать минус
        big_add_of_mantissas(&b_value_1, &b_value_2, &b_result);
        b_result.sign = 1;
      } else {
        if (comp_of_mantissas_for_big(b_value_1, b_value_2) == 1) {
          // b_value_1 >
          big_sub_of_mantissas(b_value_1, b_value_2, &b_result);
          if (is_value_1_negative) b_result.sign = 1;
        } else {
          // b_value_2 > || (b_value_1 = b_value_2)
          big_sub_of_mantissas(b_value_2, b_value_1, &b_result);
          if (is_value_2_negative) b_result.sign = 1;
        }
      }
      // в элс ниже мы попадаем если у нас оба знака плюс
    } else {
      // тут обычное сложение 2 положительных чисел
      big_add_of_mantissas(&b_value_1, &b_value_2, &b_result);
    }
    error_status = translate_to_s21_decimal(&b_result, result);
  }
  return error_status;
}

int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int error_status = S21_OK;
  if (result == NULL) {
    error_status = S21_ERROR;
  } else {
    s21_big_decimal b_value_1 = {0}, b_value_2 = {0}, b_result = {0};
    null_decimal(result);
    translate_to_big(value_1, &b_value_1);
    translate_to_big(value_2, &b_value_2);
    normalization(&b_value_1, &b_value_2);
    //для -0
    if (!(is_zero_big(b_value_1))) {
      null_big_decimal(&b_value_1);
      null_decimal(&value_1);
    }
    if (!(is_zero_big(b_value_2))) {
      null_big_decimal(&b_value_2);
      null_decimal(&value_2);
    }
    int is_value_1_negative = get_sign(value_1) == MINUS;
    int is_value_2_negative = get_sign(value_2) == MINUS;
    int is_sign_equal = !(is_value_1_negative - is_value_2_negative);
    if (is_sign_equal) {
      if (comp_of_mantissas_for_big(b_value_1, b_value_2) >= 0) {
        big_sub_of_mantissas(b_value_1, b_value_2, &b_result);
        if (is_value_1_negative) b_result.sign = 1;
      } else {
        big_sub_of_mantissas(b_value_2, b_value_1, &b_result);
        if (is_value_2_negative == 0 && is_value_1_negative == 0)
          b_result.sign = 1;
      }
    } else {
      big_add_of_mantissas(&b_value_1, &b_value_2, &b_result);
      if (is_value_1_negative) b_result.sign = 1;
    }
    error_status = translate_to_s21_decimal(&b_result, result);
  }
  return error_status;
}

int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int error_status = S21_OK;
  if (result == NULL) {
    error_status = S21_ERROR;
  } else {
    s21_big_decimal b_value_1 = {0}, b_value_2 = {0}, b_result = {0},
                    null = {0};
    null_decimal(result);
    translate_to_big(value_1, &b_value_1);
    translate_to_big(value_2, &b_value_2);
    int is_value_1_negative = get_sign(value_1) == MINUS;
    int is_value_2_negative = get_sign(value_2) == MINUS;
    int is_sign_equal = !(is_value_1_negative - is_value_2_negative);
    if (is_sign_equal) {
      big_mul_of_mantissas(b_value_1, b_value_2, &b_result);
    } else {
      big_mul_of_mantissas(b_value_1, b_value_2, &b_result);
      b_result.sign = 1;
    }
    if (comp_of_mantissas_for_big(b_value_1, null) == 0 ||
        comp_of_mantissas_for_big(b_value_2, null) == 0) {
      null_big_decimal(&b_result);
    }
    error_status = translate_to_s21_decimal(&b_result, result);
  }

  return error_status;
}

int s21_div(s21_decimal val1, s21_decimal val2, s21_decimal *result) {
  int status = S21_OK;
  int zero1 = 0;
  // рез не НУЛ
  if (result) {
    null_decimal(result);  // обнуляем результат
    s21_big_decimal bval1 = {0}, bval2 = {0}, bres = {0};
    translate_to_big(val1, &bval1);
    translate_to_big(val2, &bval2);
    // если делимое 0
    if (!is_zero_big(bval1)) {
      zero1 = 1;
    }
    if (is_zero_big(bval2)) {
      // делим
      division_big_devimal(bval1, bval2, &bres);
      // устанавлваем знаак
      if (get_sign(val1) != get_sign(val2)) bres.sign = 1;
      if (!status) {
        status = translate_to_s21_decimal(&bres, result);
      }

    } else {
      status = S21_ERROR_ZERO_DIVISION;
    }
    if (status || zero1) {
      null_decimal(result);
    }

  } else {
    status = S21_ERROR;
  }
  return status;
}
