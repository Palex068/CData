// #include <stdio.h>

// #define ROWS 3
// #define COLUMNS 3

// int main() {
//   int arr[ROWS][COLUMNS];
//   // чтение массива
//   for (int i = 0; i < ROWS; i++) {
//     // чтение одной строки a[i]
//     for (int j = 0; j < COLUMNS; j++) {
//       scanf("%d", &arr[i][j]);
//     }
//   }
//   // внесём изменения
//   arr[1][2] *= 10;
//   // печать массива
//   for (int i = 0; i < ROWS; i++) {
//     for (int j = 0; j < COLUMNS; j++) {
//       printf("%d ", arr[i][j]);
//     }
//     printf("\n")
//   }
//   return 0;
// }

// #include <stdio.h>

// #define ROWS 3
// #define COLUMNS 3

// int main() {
//   int arr[ROWS][COLUMNS];
//   int sum = 0;
//   // чтение массива
//   for (int i = 0; i < ROWS; i++) {
//     // чтение одной строки a[i]
//     for (int j = 0; j < COLUMNS; j++) {
//       scanf("%d", &arr[i][j]);
//       sum += arr[i][j];
//     }
//   }
//   printf("%d ", sum);
//   return 0;
// }

// #include <stdio.h>

// void number_mult(int k, int rows, int cols, int a[][cols]) {
//   for (int i = 0; i < rows; i++)
//     for (int j = 0; j < cols; j++) a[i][j] *= k;
// }

// void matrix_read(int rows, int cols, int a[][cols]) {
//   for (int i = 0; i < rows; i++)
//     for (int j = 0; j < cols; j++) scanf("%d", &a[i][j]);
// }

// void matrix_print(int rows, int cols, int a[][cols]) {
//   for (int i = 0; i < rows; i++) {
//     for (int j = 0; j < cols; j++) printf("%d ", a[i][j]);
//     printf("\n");
//   }
// }

// int main() {
//   int n, m;
//   scanf("%d%d", &n, &m);
//   int a[n][m];

//   matrix_read(n, m, a);

//   int k;
//   scanf("%d", &k);

//   number_mult(k, n, m, a);

//   matrix_print(n, m, a);
//   return 0;
// }

#include <stdio.h>

void matrix_read(int rows, int cols, int a[10][10]) {
  for (int i = 0; i < rows; i++)
    for (int j = 0; j < cols; j++) scanf("%d", &a[i][j]);
}

void matrix_print(int rows, int cols, const int a[10][10]) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) printf("%d ", a[i][j]);
    printf("\n");
  }
}

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  int a[n][m];
  int b[n][m];

  matrix_read(n, m, a);

  matrix_read(n, m, b);

  printf("\n");
  matrix_print(n, m, a);
  printf("\n");
  matrix_print(n, m, b);
  printf("\n");

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) printf("%d ", a[i][j] + b[i][j]);
    printf("\n");
  }

  return 0;
}