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

#include <stdio.h>

#define ROWS 3
#define COLUMNS 3

int main() {
  int arr[ROWS][COLUMNS];
  int sum = 0;
  // чтение массива
  for (int i = 0; i < ROWS; i++) {
    // чтение одной строки a[i]
    for (int j = 0; j < COLUMNS; j++) {
      scanf("%d", &arr[i][j]);
      sum += arr[i][j];
    }
  }
  printf("%d ", sum);
  return 0;
}
