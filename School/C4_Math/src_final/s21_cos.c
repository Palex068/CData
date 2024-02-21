#include "s21_math.h"

long double s21_cos(double x) {
  long double res = 0, tmp = 1;
  int i = 0;
  x = s21_sincos_normalize(x);
  while (s21_fabs(tmp) > S21_EPS) {
    tmp = s21_pow(x, 2 * i) / s21_fact(2 * i);
    res += s21_pow(-1, i) * tmp;
    i++;
  }
  return res;
}