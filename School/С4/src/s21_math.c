#include "s21_math.h"

int s21_abs(int x) { return (x > 0) ? x : (-x); }

long double s21_ceil(double x) {
  long floor_x = (long)x;
  if (x > 0) {
    return floor_x + 1;
  } else {
    return floor_x;
  }
}

long double s21_exp(double x) {
  long double arg = 1.0, ret = 1.0;
  for (int n = 0; s21_fabs(arg) > S21_EPS; n++) {
    arg = (arg * x) / (n + 1);  // recurrent argument
    ret += arg;
  }
  return ret;
}

long double s21_fabs(double x) { return x >= 0 ? x : -x; }

long double s21_floor(double x) { return x >= 0 ? (long)x : (long)x - 1; }

long double s21_fmod(double x, double y) { return x - (long)(x / y) * y; }

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

long double s21_pow(double base, double exp) {
  if (exp == 1) {
    return base;
  } else if (exp == 0) {
    base = 1;
  } else if (base == 0) {
    if (exp > 0) {
      base = 0;
    } else {
      base = S21_INF_POS;
    }
  } else if (s21_fabs(base) == 1 &&
             (exp == S21_INF_POS || exp == S21_INF_NEG)) {
    base = 1;
  } else if (s21_fabs(base) > 1 && exp == S21_INF_POS) {
    base = S21_INF_POS;
  } else if (s21_fabs(base) > 1 && exp == S21_INF_NEG) {
    base = +0;
  } else if (s21_fabs(base) < 1 && exp == S21_INF_POS) {
    base = +0;
  } else if (s21_fabs(base) < 1 && exp == S21_INF_NEG) {
    base = S21_INF_POS;
  } else if (base < 0) {
    int is_int = (int)exp;
    double tmp = base;
    if (exp == is_int) {
      for (int i = 1; i < exp; i++) {
        tmp *= (-1) * s21_fabs(base);
      }
      base = tmp;
    } else {
      base = S21_NAN;
    }
  } else {
    base = s21_exp(exp * s21_log(base));
  }
  return base;
}

long double s21_sqrt(double x) {
  long double tmp = 0;
  long double result = x / 2;
  if (x == S21_INF_POS) return result = x;
  if (x < 0) {
    result = S21_NAN;
  } else if (x == 0) {
    result = 0.0;
  } else {
    while ((tmp - result) != 0) {
      tmp = result;
      result = (tmp + (x / tmp)) / 2;
    }
  }
  return result;
}

long double s21_fact(int x) {
  if (x == 0) return x = 1;
  long double ret = 1;
  for (int i = 1; i <= x; i++) {
    ret *= i;
  }
  return ret;
}

long double s21_sincos_normalize(double x) {
  int sign = 1;
  if (x > 2 * S21_PI)
    sign = -1;
  else if (x < -2 * S21_PI)
    sign = 1;
  while (s21_fabs(x) > 2 * S21_PI) {
    x += sign * 2 * S21_PI;
  }
  return x;
}

long double s21_cos(double x) {
  long double res = 0, tmp = 1;
  int i = 0;
  x = s21_sincos_normalize(x);
  while (s21_fabs(tmp) > S21_EPS) {
    tmp = s21_pow(x, 2 * i) / s21_fact(2 * i);
    res += s21_pow(-1, i) * tmp;
    i++;
  }
  return res;
}

long double s21_sin(double x) {
  long double res = 0, tmp = 1;
  int i = 0;
  x = s21_sincos_normalize(x);
  while (s21_fabs(tmp) > S21_EPS) {
    tmp = s21_pow(x, 2 * i + 1) / s21_fact(2 * i + 1);
    res += s21_pow(-1, i) * tmp;
    i++;
  }
  return res;
}

long double s21_tan(double x) {
  if (x == S21_PI / 2) return 16331239353195370.0;
  x = s21_fmod(x, S21_PI);
  return s21_sin(x) / s21_cos(x);
}

long double s21_atan(double x) {
  long double result = 0;
  if (x < 1 && x > -1) {
    result = s21_atan_support(x);
  } else if (x == 1) {
    result = S21_PI / 4;
  } else if (x == -1) {
    result = -S21_PI / 4;
  } else if (x > 1) {
    result = S21_PI / 2 - s21_atan_support(1 / x);
  } else {
    result = -S21_PI / 2 - s21_atan_support(1 / x);
  }
  return result;
}

long double s21_atan_support(double x) {
  long double result = x, temp = x, i = 1;
  while (s21_fabs(result) > S21_EPS) {
    result = -1 * result * x * x * (2 * i - 1) / (2 * i + 1);
    i += 1;
    temp += result;
  }
  return temp;
}

long double s21_asin(double x) { return s21_atan(x / s21_sqrt(1 - (x * x))); }

long double s21_acos(double x) {
  long double result = S21_NAN;
  if (x <= 1 && x >= -1) {
    if (s21_acos_support(x) == 1) {
      result = S21_PI * (1 - x) / 2;
    } else {
      result = S21_PI / 2. - s21_asin(x);
    }
  }
  return result;
}

double s21_acos_support(double x) {
  if (x < 0) {
    x *= -1;
  }
  return x;
}