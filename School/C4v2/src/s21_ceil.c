#include "s21_math.h"

long double s21_ceil(double x) {
  long double result = 0.0;
  if ((int)x == x) {
    result = x;
  } else if (x < 0) {
    result = (int)x;
  } else {
    result = (int)x + 1;
  }
  return result;
}