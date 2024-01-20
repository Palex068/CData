// #include <stdio.h>

// int x; // неявная инициализация

// void foo() { x = x + 1; }

// int main()
// {
//     foo();
//     foo();
//     printf("%d\n", x);
//     return 0;
// }

// #include <stdio.h>

// void foo() {
//   static int x; // неявная инициализация
//   x = x + 1;
//   printf("%d ", x);
// }

// int main() {
//   foo();
//   foo();
//   return 0;
// }

#include <stdio.h>

void foo() {
  static int x = 2; // явная инициализация
  x = x + 1;
  printf("%d ", x);
}

int main() {
  foo();
  foo();
  return 0;
}