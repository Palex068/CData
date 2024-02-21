#include "s21_math.h"

long double s21_log(double x) {
  long double ret = 0;
  if (x < 0 && x != S21_INF_NEG) {
    ret = S21_NAN;
  } else if (x == 0) {
    ret = S21_INF_NEG;
  } else if (x == S21_INF_NEG || x == S21_INF_POS) {
    ret = S21_INF_POS;
  } else {
    double tmp = 1;
    while (s21_fabs(tmp) > S21_EPS) {
      double cmp = ret;
      tmp = 2 * (x - s21_exp(cmp)) / (x + s21_exp(cmp));  // Halley's method
      ret = cmp + tmp;
    }
  }
  return ret;
}