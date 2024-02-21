#include "s21_math.h"

long double s21_acos(double x) {
  long double result = S21_NAN;
  if (x <= 1 && x >= -1) {
    if (s21_acos_support(x) == 1) {
      result = S21_PI * (1 - x) / 2;
    } else {
      result = S21_PI / 2. - s21_asin(x);
    }
  }
  return result;
}

double s21_acos_support(double x) {
  if (x < 0) {
    x *= -1;
  }
  return x;
}