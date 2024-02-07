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

// #include <stdio.h>

// int main() {
//   int n, m;
//   scanf("%d%d", &n, &m);
//   int a[n][m];

//   for (int i = 0; i < n; i++) {
//     for (int j = 0; j < m; j++) {
//       scanf("%d", &a[i][j]);
//     }
//   }

//   int b[n][m];

//   for (int i = 0; i < n; i++) {
//     for (int j = 0; j < m; j++) {
//       scanf("%d", &b[i][j]);
//     }
//   }

//   for (int i = 0; i < n; i++) {
//     for (int j = 0; j < m; j++) printf("%d ", a[i][j] + b[i][j]);
//     printf("\n");
//   }

//   return 0;
// }

// #include <stdio.h>

// #define N 10

// void sum(int rows, int cols, int a[N][N], int b[N][N], int c[N][N]) {
//   int i, j;
//   for (i = 0; i < rows; i++)
//     for (j = 0; j < cols; j++) c[i][j] = a[i][j] + b[i][j];
// }

// void matrix_read(int rows, int cols, int a[][N]) {
//   for (int i = 0; i < rows; i++)
//     for (int j = 0; j < cols; j++) scanf("%d", &a[i][j]);
// }

// void matrix_print(int rows, int cols, int a[][N]) {
//   for (int i = 0; i < rows; i++) {
//     for (int j = 0; j < cols; j++) printf("%d ", a[i][j]);
//     printf("\n");
//   }
// }

// int main() {
//   int n, m;
//   scanf("%d%d", &n, &m);
//   int a[N][N];
//   int b[N][N];
//   int c[N][N];

//   matrix_read(n, m, a);
//   matrix_read(n, m, b);

//   sum(n, m, a, b, c);

//   matrix_print(n, m, c);
//   return 0;
// }

#include <stdio.h>
#define N 100

int main() {
  int n;
  scanf("%d", &n);
  char line[101];
  int matrix[N][N];
  int result[N][N];
  for (int i = 0; i < n; i++) {
    scanf("%101s", line);
    for (int j = 0; line[j] != '\0'; j++) {
      matrix[i][j] = (line[j] == '*') ? 1 : 0;
    }
  }

  // считаем площади в каждой точке и запишем результат
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (matrix[i][j]) {
        int wight = 0;
        int hight = 0;
        for (int x = i; x < n; x++) {
          if (matrix[x][j]) {
            wight++;
          } else
            break;
        }
        for (int y = j; y < n; y++) {
          if (matrix[i][y]) {
            hight++;
          } else
            break;
        }
        result[i][j] = wight * hight;
      } else
        result[i][j] = matrix[i][j];
    }
  }
  int maximum = result[0][0];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (maximum < result[i][j]) {
        maximum = result[i][j];
      }
    }
  }
  printf("%d", maximum);
  return 0;
}