#include "s21_math.h"

long double s21_atan(double x) {
  long double result = 0;
  if (x < 1 && x > -1) {
    result = s21_atan_support(x);
  } else if (x == 1) {
    result = S21_PI / 4;
  } else if (x == -1) {
    result = -S21_PI / 4;
  } else if (x > 1) {
    result = S21_PI / 2 - s21_atan_support(1 / x);
  } else {
    result = -S21_PI / 2 - s21_atan_support(1 / x);
  }
  return result;
}

long double s21_atan_support(double x) {
  long double result = x, temp = x, i = 1;
  while (s21_fabs(result) > S21_EPS) {
    result = -1 * result * x * x * (2 * i - 1) / (2 * i + 1);
    i += 1;
    temp += result;
  }
  return temp;
}