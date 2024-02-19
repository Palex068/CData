#include "s21_math.h"

long double s21_sqrt(double x) {
  long double result = 0.0;
  if (x == -S21_INF || x < 0) {
    result = S21_NAN;
  } else if (x == 0 || x == -0) {
    result = 0.0;
  } else if (x == S21_INF || x <= S21_SQRT_EPS) {
    result = S21_INF;
  } else {
    result = s21_pow(x, 0.5);
  }
  return result;
}