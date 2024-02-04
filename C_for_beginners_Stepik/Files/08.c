// #include <stdio.h>
// #define N 10

// int main() {
//   int a[N];  // коробка с ячейками
//   int i, sum = 0, k, n;
//   // читаем N чисел в массив a
//   for (i = 0; i < N; i++) {
//     scanf("%d", &a[i]);
//   }

//   scanf("%d %d", &k, &n);

//   for (i = k; i < n; i++) {
//     sum += a[i];
//   }
//   printf("%d\n", sum);  // печатаем сумму

//   return 0;
// }

#include <stdio.h>
#include <stdlib.h>

int main() {
  int b[10] = {0}, *a = NULL;
  int n;
  scanf("%d", &n);
  a = malloc(n * sizeof(int));
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    b[a[i]]++;
  }
  for (int i = 0; i < 10; i++) {
    printf("%d %d\n", i, b[i]);
  }
  free(a);
  return 0;
}