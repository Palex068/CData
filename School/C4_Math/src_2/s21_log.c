#include "s21_math.h"

long double s21_log(double x) {
  long double result = 0.0;
  if (x < 0 || x == -S21_INF || x == S21_NAN) {
    result = S21_NAN;
  } else if (x == 0) {
    result = -S21_INF;
  } else if (x == S21_INF) {
    result = S21_INF;
  } else if (x == 1) {
    result = 0;
  } else {
    double N = 0.0, P = x;
    while (P >= S21_E) {
      P /= S21_E;
      N++;
    }
    N += (P / S21_E);
    P = x;
    int j = 0;
    do {
      double L, R;
      L = (P / (s21_exp(N - 1.0)));
      R = ((N - 1.0) * S21_E);
      N = ((L + R) / S21_E);
      j++;
    } while (N != 0 &&
             j < 100);  // увеличить количество итераций для большей точности
    result = N;
  }
  return result;
}