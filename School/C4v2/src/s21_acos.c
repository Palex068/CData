#include "s21_math.h"

long double s21_acos(double x) {
  long double result = 0.0;
  if (x == 1.0) {
    result = 0.0;
  } else {
    result = (S21_PI_2 - s21_asin(x));
  }
  return result;
}