#include "s21_math.h"

long double s21_fmod(double x, double y) {
  long double res = 0;
  if (s21_is_nan(x) || s21_is_nan(y) || s21_is_inf(x) || y == 0) {
    res = S21_NAN;
  } else if (s21_is_inf(y)) {
    res = x;
  } else if (x == 0.0 && y != 0) {
    res = 0.0;
  } else {
    if (x < 0 || y < 0) {
      res = -s21_abs(x / y);
    } else {
      res = s21_abs(x / y);
    }
    res = x - res * y;
  }
  return res;
}