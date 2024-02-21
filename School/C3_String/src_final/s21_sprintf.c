#include "s21_string.h"

int s21_sprintf(char *str, const char *format, ...) {
  flags f = {0};
  va_list arg_ptr;
  va_start(arg_ptr, format);
  char *newStr = str;
  while (*format) {
    if (*format == '%') {
      format++;
      s21_memset(&f, 0, sizeof(flags));
    } else {
      *str++ = *format++;
      continue;
    }
    format = ifFlags(format, &f);
    format = width(format, &f, arg_ptr);
    format = precision(format, &f, arg_ptr);
    format = length(format, &f);
    f.specifier = *format;
    format++;
    char buff[BUFFERSIZE] = {'\0'};
    menu(f, buff, arg_ptr);
    for (int i = 0; buff[i]; i++, str++) {
      *str = buff[i];
    }
    if (f.specifier == 'n') {
      int *n = va_arg(arg_ptr, int *);

      *n = str - newStr;
    }
  }
  *str = '\0';
  va_end(arg_ptr);
  return str - newStr;
}

const char *ifFlags(const char *format, flags *f) {
  while (*format == '-' || *format == '+' || *format == ' ' || *format == '0' ||
         *format == '#') {
    switch (*format) {
      case '0':
        f->zero = ON;
        break;
      case '-':
        f->minus = ON;
        break;
      case '+':
        f->plus = ON;
        break;
      case ' ':
        f->space = ON;
        break;
      case '#':
        f->hash = ON;
        break;
    }
    format++;
  }
  return format;
}

const char *width(const char *format, flags *f, va_list arg_ptr) {
  if (*format == '*') {
    format++;
    f->width = va_arg(arg_ptr, int);
  } else if (isDigit(*format)) {
    char tmp[BUFFERSIZE] = {'\0'};
    for (int i = 0; isDigit(*format); i++, format++) tmp[i] = *format;
    f->width = atoi(tmp);
  }
  return format;
}

const char *precision(const char *format, flags *f, va_list arg_ptr) {
  if (*format == '.') {
    f->isPrecisionSet = ON;
    format++;
  }
  if (*format == '*') {
    format++;
    f->precision = va_arg(arg_ptr, int);
  }
  if (isDigit(*format)) {
    char tmp[BUFFERSIZE] = {'\0'};
    for (int i = 0; isDigit(*format); i++, format++) tmp[i] = *format;
    f->precision = atoi(tmp);
  }
  return format;
}

const char *length(const char *format, flags *f) {
  switch (*format) {
    case 'h':
      f->length = 'h';
      format++;
      break;
    case 'l':
      f->length = 'l';
      format++;
      break;
    case 'L':
      f->length = 'L';
      format++;
  }
  return format;
}

void menu(flags f, char *buff, va_list arg_ptr) {
  char *s;
  s = NULL;
  if (f.specifier == 'c')
    parseChar(f, buff, arg_ptr);
  else if (f.specifier == 'd' || f.specifier == 'i')
    parseInt(f, buff, arg_ptr);
  else if (f.specifier == 'f')
    parseFloat(f, buff, arg_ptr);
  else if (f.specifier == 's')
    parseString(f, buff, arg_ptr);
  else if (f.specifier == 'u')
    parseUnsigned(f, buff, arg_ptr);
  else if (f.specifier == '%')
    buff[0] = '%';
  else if (f.specifier == 'g' || f.specifier == 'G')
    parsegG(f, buff, arg_ptr);
  else if (f.specifier == 'e' || f.specifier == 'E')
    parseMantiss(f, buff, arg_ptr);
  else if (f.specifier == 'x' || f.specifier == 'X')
    parseHex(f, buff, arg_ptr);
  else if (f.specifier == 'o')
    parseOctal(f, buff, arg_ptr);
  else if (f.specifier == 'p')
    parsePointer(f, buff, arg_ptr);
  if (f.specifier == 'G' || f.specifier == 'E' || f.specifier == 'X') {
    s = s21_to_upper(buff);
    s21_strcpy(buff, s);
    free(s);
  }
}

void parseInt(flags f, char *buff, va_list arg_ptr) {
  int val = va_arg(arg_ptr, int);
  switch (f.length) {
    case 0:
      val = (int32_t)val;
      break;
    case 'h':
      val = (int16_t)val;
      break;
  }
  intToChar(val, buff, 10);
  formatPrecision(buff, f);
  formatFlags(buff, f);
}

void intToChar(int val, char *buff, int base) {
  char tmp[BUFFERSIZE] = {'\0'};
  int n = BUFFERSIZE - 2;
  int neg = val < 0 ? 1 : 0;
  val = neg ? -val : val;
  if (val == 0) tmp[n] = '0';
  while (val > 0) {
    n--;
    tmp[n] = "0123456789"[val % base];
    val /= base;
  }
  for (int j = 0; tmp[n]; n++, j++) {
    if (neg && j == 0) {
      buff[j++] = '-';
    }
    buff[j] = tmp[n];
  }
}

int checkIntCpec(char c) {
  char *specs = "diouxX";
  int res = false;
  for (s21_size_t i = 0; i < s21_strlen(specs); i++) {
    if (specs[i] == c) {
      res = ON;
      break;
    }
  }
  return res;
}

void parseUnsigned(flags f, char *buff, va_list arg_ptr) {
  int val = va_arg(arg_ptr, int);
  switch (f.length) {
    case 'h':
      val = (uint16_t)val;
      break;
    case 'l':
      val = (uint64_t)val;
      break;
    case 0:
      val = (uint32_t)val;
  }
  unsignedIntToChar(val, buff, 10);
  formatPrecision(buff, f);
  formatFlags(buff, f);
}

void unsignedIntToChar(int val, char *ret, int base) {
  char buf[BUFFERSIZE + 1] = {'\0'};
  int n = BUFFERSIZE - 1;
  if (val == 0) {
    buf[n] = '0';
    n--;
  }
  for (; val && n; --n, val /= base) buf[n] = "0123456789abcdef"[val % base];
  for (int j = 0; buf[n + 1]; n++, j++) ret[j] = buf[n + 1];
}

void parseOctal(flags f, char *buff, va_list arg_ptr) {
  buff[0] = '0';
  intToChar(va_arg(arg_ptr, int), buff + f.hash, 8);
  formatPrecision(buff, f);
  formatFlags(buff, f);
}

int isAllZero(char *buff) {
  for (int i = 0; buff[i]; i++)
    if (buff[i] != '0') return OFF;
  return ON;
}

void parseHex(flags f, char *buff, va_list arg_ptr) {
  uint64_t val = va_arg(arg_ptr, uint64_t);
  switch (f.length) {
    case 0:
      val = (uint32_t)val;
      break;
    case 'h':
      val = (uint16_t)val;
      break;
    case 'l':
      val = (uint64_t)val;
      break;
  }
  unsignedIntToChar(val, buff, 16);
  formatPrecision(buff, f);
  if (f.hash) {
    ox(buff, f);
  }
  formatFlags(buff, f);
}

void parseChar(flags f, char *buff, va_list arg_ptr) {
  if (f.length == 'l') {
    wchar_t w_c;
    w_c = va_arg(arg_ptr, wchar_t);
    formatWidthChar(f, buff, w_c);
  } else {
    char c;
    c = va_arg(arg_ptr, int);
    formatChar(f, buff, c);
  }
}

void formatChar(flags f, char *buff, char c) {
  if (!f.minus && f.width) {
    for (int i = 0; i < f.width; i++) {
      buff[i] = ' ';
      if (i == f.width - 1) buff[i] = c;
    }
  } else if (f.width) {
    buff[0] = c;
    for (int i = 1; i < f.width; i++) buff[i] = ' ';
  } else {
    buff[0] = c;
  }
}

void formatWidthChar(flags f, char *buff, wchar_t w_c) {
  if (!f.minus && f.width) {
    for (int i = 0; i < f.width; i++) {
      buff[i] = ' ';
      if (i == f.width - 1) wcstombs(buff, &w_c, BUFFERSIZE);
    }
  } else if (f.width) {
    wcstombs(buff, &w_c, BUFFERSIZE);
    for (int i = s21_strlen(buff); i < f.width; i++) buff[i] = ' ';
  } else {
    wcstombs(buff, &w_c, BUFFERSIZE);
  }
}

void parseString(flags f, char *buff, va_list arg_ptr) {
  if (f.length == 'l') {
    wchar_t *wstr = va_arg(arg_ptr, wchar_t *);
    formatWideString(f, buff, wstr);
  } else {
    char *str = va_arg(arg_ptr, char *);
    formatString(f, buff, str);
  }
}

void formatString(flags f, char *buff, char *str) {
  char tmp[BUFFERSIZE] = {'\0'};
  s21_strcpy(tmp, str);
  if (f.isPrecisionSet) tmp[f.precision] = '\0';
  int shift = f.width - s21_strlen(tmp);
  int len = s21_strlen(tmp);
  if (f.minus && shift > 0) {
    s21_strcpy(buff, tmp);
    s21_memset(buff + len, ' ', shift);
  } else if (shift > 0) {
    s21_memset(buff, ' ', shift);
    s21_strcpy(buff + shift, tmp);
  } else {
    s21_strcpy(buff, tmp);
  }
}

void formatWideString(flags f, char *buff, wchar_t *wstr) {
  char tmp[BUFFERSIZE] = {'\0'};
  char str[BUFFERSIZE] = {'\0'};
  wcstombs(str, wstr, BUFFERSIZE);
  s21_strcpy(tmp, str);
  if (f.isPrecisionSet) tmp[f.precision] = '\0';
  int shift = f.width - s21_strlen(tmp);
  int len = s21_strlen(tmp);
  if (f.minus && shift > 0) {
    s21_strcpy(buff, tmp);
    s21_memset(buff + len, ' ', shift);
  } else if (shift > 0) {
    s21_memset(buff, ' ', shift);
    s21_strcpy(buff + shift, tmp);
  } else {
    s21_strcpy(buff, tmp);
  }
}

void parsePointer(flags f, char *buff, va_list arg_ptr) {
  unsignedIntToChar(va_arg(arg_ptr, uint64_t), buff, 16);
  formatPrecision(buff, f);
  ox(buff, f);
  formatFlags(buff, f);
}

void formatPrecision(char *buff, flags f) {
  char tmp[BUFFERSIZE] = {'\0'};
  int sign = 0;
  int len = s21_strlen(buff);
  if (buff[0] == '-') {
    tmp[0] = '-';
    len--;
    sign = 1;
  }
  if (f.precision > len) {
    int n;
    for (n = sign; n < f.precision - len + sign; n++) tmp[n] = '0';
    for (int i = sign; buff[i]; i++, n++) tmp[n] = buff[i];
    s21_strcpy(buff, tmp);
  }
  if (f.isPrecisionSet && f.precision == 0 && checkIntCpec(f.specifier) &&
      buff[0] == '0')
    buff[0] = '\0';
}

void ox(char *buff, flags f) {
  if (!isAllZero(buff) || f.specifier == 'p') {
#ifdef __APPLE__
    s21_memmove(buff + 2, buff, s21_strlen(buff));
    buff[0] = '0';
    buff[1] = 'x';
#elif __linux__
    s21_memmove(buff + 4, buff, s21_strlen(buff));
    char nil[] = "(nil)";
    s21_strcpy(buff, nil);
#endif
  }
}

void formatFlags(char *buff, flags f) {
  char tmp[BUFFERSIZE + 1] = {'\0'};
  if (f.plus && f.specifier != 'u') {
    tmp[0] = buff[0] == '-' ? buff[0] : '+';
    s21_strcpy(tmp + 1, buff[0] == '-' ? buff + 1 : buff);
    s21_strcpy(buff, tmp);
  } else if (f.space && buff[0] != '-' && f.specifier != 'u') {
    tmp[0] = ' ';
    s21_strcpy(tmp + 1, buff);
    s21_strcpy(buff, tmp);
  }
  if (f.width > (int)s21_strlen(buff)) {
    int n = f.width - s21_strlen(buff);
    if (!f.minus) {
      s21_memset(tmp, f.zero ? '0' : ' ', n);
      s21_strcpy(tmp + n, buff);
    } else {
      s21_strcpy(tmp, buff);
      s21_memset(tmp + s21_strlen(tmp), ' ', n);
    }
    s21_strcpy(buff, tmp);
  }
}

void parseFloat(flags f, char *buff, va_list arg_ptr) {
  long double val = 0;
  if (f.length == 'L') {
    val = va_arg(arg_ptr, long double);
  } else {
    val = va_arg(arg_ptr, double);
  }
  if (!f.isPrecisionSet) {
    f.precision = 6;
  }
  doubleToChar(val, buff, f);
  formatFlags(buff, f);
}

void parseMantiss(flags f, char *buff, va_list arg_ptr) {
  long double val = 0;
  if (f.length == 'L') {
    val = va_arg(arg_ptr, long double);
  } else {
    val = va_arg(arg_ptr, double);
  }
  int pow = 0;
  char sign = (int)val == 0 ? '-' : '+';
  if ((int)val - val) {
    while ((int)val == 0) {
      pow++;
      val *= 10;
    }
  } else {
    sign = '+';
  }
  while ((int)val / 10 != 0) {
    pow++;
    val /= 10;
  }
  if (!f.isPrecisionSet) f.precision = 6;
  doubleToChar(val, buff, f);
  mantiss(buff, pow, sign);
  formatFlags(buff, f);
}

void doubleToChar(long double val, char *ret, flags f) {
  char buff[BUFFERSIZE] = {'\0'};
  int n = BUFFERSIZE - 2;
  int neg = val < 0 ? 1 : 0;
  val = neg ? val * -1 : val;
  long double l = 0, r = modfl(val, &l);
  if (f.precision == 0) {
    l = roundl(val);
    r = 0;
  }
  char fractions[BUFFERSIZE] = {'\0'};
  for (int i = 0; i < f.precision; i++) {
    r = r * 10;
    fractions[i] = (int)r + '0';
  }
  long long right = roundl(r), left = l;
  if (!right) {
    for (int i = 0; i < f.precision; n--, i++) buff[n] = '0';
  } else {
    for (int i = s21_strlen(fractions); right || i > 0; right /= 10, n--, i--)
      buff[n] = (int)(right % 10 + 0.05) + '0';
  }
  if ((f.isPrecisionSet && f.precision != 0) || (int)r ||
      (!f.isPrecisionSet && val == 0) || s21_strlen(fractions))
    buff[n--] = '.';
  if (!left) {
    buff[n] = '0';
    n--;
  } else {
    for (; left; left /= 10, n--) buff[n] = (int)(left % 10) + '0';
  }
  for (int i = 0; buff[n + 1]; n++, i++) {
    if (neg && i == 0) {
      ret[i] = '-';
      i++;
    }
    ret[i] = buff[n + 1];
  }
}

void mantiss(char *str, int pow, char sign) {
  int len = s21_strlen(str);
  str[len] = 'e';
  str[len + 1] = sign;
  str[len + 3] = pow % 10 + '0';
  pow /= 10;
  str[len + 2] = pow % 10 + '0';
  str[len + 4] = '\0';
}

void parsegG(flags f, char *buff, va_list arg_ptr) {
  long double val = 0;
  if (f.length == 'L') {
    val = va_arg(arg_ptr, long double);
  } else {
    val = va_arg(arg_ptr, double);
  }
  if (!f.isPrecisionSet) {
    f.precision = 6;
  }
  if (f.precision == 0) f.precision = 1;
  int prec = f.precision;
  long double m_val = val;
  int pow = 0;
  if ((int)val - val) {
    while ((int)m_val == 0) {
      pow++;
      m_val *= 10;
    }
  }
  if (pow > 4) {
    f.precision = 0;
    doubleToChar(m_val, buff, f);
  } else {
    f.precision = 10;
    doubleToChar(val, buff, f);
  }
  formatPrecisiongG(buff, prec);
  if (pow > 4) mantiss(buff, pow, '-');
  removeZero(buff);
  formatFlags(buff, f);
}

void removeZero(char *buff) {
  int len = s21_strlen(buff);
  char *dot = s21_strchr(buff, '.');
  if (dot) {
    for (int i = len - 1; buff[i] != '.'; i--) {
      if (buff[i] == '0')
        buff[i] = '\0';
      else
        break;
    }
    if (dot[1] == '\0') dot[0] = '\0';
  }
}

void formatPrecisiongG(char *buff, int prec) {
  int sig_digs = 0;
  s21_size_t len = s21_strlen(buff);
  int noZero = 0;
  for (s21_size_t i = 0; i < s21_strlen(buff); i++) {
    if ((buff[i] == '0' && !noZero) || buff[i] == '.')
      continue;
    else
      noZero = 1;
    if (isDigit(buff[i]) && noZero) {
      sig_digs++;
    }
    if (sig_digs == prec && i + 1 < len) {
      int next = buff[i + 1] == '.' ? 2 : 1;
      buff[i] = buff[i + next] - '0' > 5 ? (char)(buff[i] + 1) : buff[i];
      buff[i + 1] = '\0';
      break;
    }
  }
}

int isDigit(char c) { return (c >= '0' && c <= '9'); }
