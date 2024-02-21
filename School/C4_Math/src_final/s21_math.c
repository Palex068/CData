#include "s21_math.h"

long double s21_sincos_normalize(double x) {
  int sign = 1;
  if (x > 2 * S21_PI)
    sign = -1;
  else if (x < -2 * S21_PI)
    sign = 1;
  while (s21_fabs(x) > 2 * S21_PI) {
    x += sign * 2 * S21_PI;
  }
  return x;
}

long double s21_fact(int x) {
  if (x == 0) return x = 1;
  long double ret = 1;
  for (int i = 1; i <= x; i++) {
    ret *= i;
  }
  return ret;
}