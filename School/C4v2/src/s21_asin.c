#include "s21_math.h"

long double s21_asin(double x) {
  long double result = 0.0;
  if (x == 0.0 || x == -0.0) {
    result = 0.0;
  } else if (x == S21_INF || x == -S21_INF || x == S21_NAN || x < -1.F ||
             x > 1.F) {
    result = S21_NAN;
  } else {
    x /= s21_sqrt(1.F - x * x);
    result = s21_atan(x);
  }
  return result;
}