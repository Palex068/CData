#include "s21_math.h"

long double s21_pow(double base, double exp) {
  long double result = 0.0;
  int marker = 0;
  if (exp == S21_INF_POS && base == base) {
    if (base > 1 || base < -1) {
      return S21_INF_POS;
    } else if (base == -1 || base == 1) {
      return 1.0;
    } else {
      return 0.0;
    }
  } else if (exp == S21_INF_NEG && base == base) {
    if (base > 1 || base < -1) {
      return 0.0;
    } else if (base == -1 || base == 1) {
      return 1.0;
    } else {
      return S21_INF_POS;
    }
  }

  if (exp == 0) {
    result = 1.0;
  } else if (base == 0 && (exp < 0 || exp == S21_INF_NEG)) {
    result = S21_INF_POS;
  } else if (exp == S21_NAN || (base < 0 && exp != (int)exp)) {
    result = S21_NAN;
  } else {
    if (base < 0) {
      if ((int)exp % 2 != 0) {
        marker = 1;
      }
      base = s21_fabs(base);
    }
    result = s21_exp(exp * s21_log(base));
    if (marker == 1) {
      result *= -1;
    }
  }
  return result;
}