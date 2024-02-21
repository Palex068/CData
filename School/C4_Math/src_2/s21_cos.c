#include "s21_math.h"

long double s21_cos(double x) {
  double pow = 0.0;
  long double result = 1.0;
  long double num = 1.0;
  long double xpi = s21_fmod(x, 2.0 * S21_PI);
  if (x == S21_INF || x == -S21_INF || x == S21_NAN) {
    result = S21_NAN;
  } else if (x == 0 || x == -0) {
    result = 1;
  } else if (x == S21_PI || x == -S21_PI) {
    result = -1;
  } else {
    while (s21_fabs(num / result) > S21_EPS) {
      pow += 2.0;
      num = (-num * xpi * xpi) / ((pow - 1.0) * pow);
      result += num;
    }
  }
  return result;
}