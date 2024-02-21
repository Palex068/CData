#include "s21_math.h"

long double s21_exp(double x) {
  long double result = 1.0;
  if (x == S21_INF) {
    result = S21_INF;
  } else if (x != x) {
    result = S21_NAN;
  } else if (x == -S21_INF) {
    result = 0;
  } else {
    int n = 1;
    long double a = x, sn = 1;
    if (x < 0.0) {
      a = -x;
    }
    for (int i = 0; i < 1500; i++) {
      sn *= a / n++;
      result += sn;
    }
    if (x < 0.0) {
      result = 1 / result;
    }
  }
  return result;
}