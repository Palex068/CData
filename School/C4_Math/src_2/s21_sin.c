#include "s21_math.h"

long double s21_sin(double x) {
  long double result = 0.0;
  if (x == S21_INF || x == -S21_INF || x == S21_NAN) {
    result = S21_NAN;
  } else if (x == 0 || x == -0 || x == S21_PI) {
    result = 0.0;
  } else {
    x = s21_fmod(x, 2 * S21_PI);
    while (x > S21_PI) {
      x -= 2 * S21_PI;
    }
    while (x < -S21_PI) {
      x += 2 * S21_PI;
    }
    result = x;
    int factorial = 1;
    long double temp = x;
    while (s21_fabs(temp) > S21_EPS) {
      temp = (-temp * x * x) / ((2 * factorial + 1) * (2 * factorial));
      result += temp;
      factorial++;
    }
  }
  return result;
}