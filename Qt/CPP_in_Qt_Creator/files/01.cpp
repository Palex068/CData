// #include <stdio.h>

// int main(void) {
//   double f;
//   for (f = 1.0; f < 1.0e+10; f = f * 10) printf("%g ", f);
//   return 0;
// }

#include <stdio.h>

int main(void) {
  unsigned num;
  for (num = 0; num < 16; num++) {
    printf("%o ", num);
    printf("%x ", num);
    printf("%X\n", num);
  }

  return 0;
}