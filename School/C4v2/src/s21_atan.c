#include "s21_math.h"

long double s21_atan(double x) {
  long double result = 0.0;
  long double x_sqrt = 0.0;
  int sn = 0, sn2 = 0;
  int size = 0;
  if (x < 0.F) {
    x = -x;
    sn = 1;
  }
  if (x > s21_pow(10, 7)) {
    x = s21_pow(10, 7);
  }
  if (x > 1.F) {
    x = 1.F / x;
    sn2 = 1;
  }
  while (x > S21_PI_12) {
    size++;
    result = 1.F / (x + S21_SQRT_3);
    x = ((x * S21_SQRT_3) - 1) * result;
  }
  x_sqrt = s21_pow(x, 2);
  result = x * (0.55913709 / (1.4087812 + x_sqrt) + 0.60310579 -
                0.05160454 * x_sqrt);
  while (size > 0) {
    result += S21_PI_6;
    size--;
  }
  if (sn2 == 1) {
    result = S21_PI_2 - result;
  }
  if (sn == 1) {
    result = -result;
  }
  return result;
}