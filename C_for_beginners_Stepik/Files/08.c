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

// #include <stdio.h>
// #include <stdlib.h>

// int main() {
//   int b[10] = {0}, *a = NULL;
//   int n;
//   scanf("%d", &n);
//   a = malloc(n * sizeof(int));
//   for (int i = 0; i < n; i++) {
//     scanf("%d", &a[i]);
//     b[a[i]]++;
//   }
//   for (int i = 0; i < 10; i++) {
//     printf("%d %d\n", i, b[i]);
//   }
//   free(a);
//   return 0;
// }

// #include <stdio.h>

// int main() {
//   int const mon[] = {5000, 1000, 500, 100, 50, 10, 5, 2, 1};
//   int x;
//   scanf("%d", &x);
//   for (int i = 0; i < 9; i++) {
//     printf("%d %d\n", mon[i], x / mon[i]);
//     x %= mon[i];
//   }
//   return 0;
// }

// #include <stdio.h>
// #define MAX 70
// int main() {
//   int n;
//   scanf("%d", &n);
//   unsigned long int arr[MAX] = {0};
//   arr[0] = 1;
//   for (int i = 1; i <= n; i++) {
//     arr[i] = 1;
//     for (int k = i - 1; k > 0; k--) {
//       arr[k] += arr[k - 1];
//     }
//   }
//   for (int i = 0; i <= n; i++) {
//     printf("%lu ", arr[i]);
//   }
//   return 0;
// }

// #include <stdio.h>
// #include <stdlib.h>

// int max(const int *a, int n) {
//   int maximum = a[0];
//   for (int i = 1; i < n; i++) {
//     if (maximum < a[i]) {
//       maximum = a[i];
//     }
//   }
//   return maximum;
// }

// int main() {
//   int n, *a = NULL;
//   scanf("%d", &n);
//   a = malloc(n * sizeof(int));
//   for (int i = 0; i < n; i++) {
//     scanf("%d", &a[i]);
//   }
//   int max_num = max(a, n) + 1;
//   char *prime = NULL;
//   prime = malloc((max_num) * sizeof(char));

//   for (int i = 0; i < max_num; i++) {
//     prime[i] = 1;
//   }

//   for (int i = 2; i * i <= max_num; i++) {
//     if (prime[i]) {
//       for (int k = i * i; k <= max_num; k += i) {
//         prime[k] = 0;
//       }
//     }
//   }

//   for (int i = 0; i < n; i++) {
//     if (prime[a[i]]) {
//       printf("%d ", a[i]);
//     }
//   }
//   free(a);
//   free(prime);
//   return 0;
// }

// #include <stdio.h>
// #include <stdlib.h>
// #define MAX 10000

// int main() {
//   int n;
//   int a[MAX][3];

//   scanf("%d", &n);

//   // записали входные данные
//   for (int i = 0; i < n; i++) {
//     for (int k = 0; k < 3; k++) {
//       scanf("%d", &a[i][k]);
//     }
//   }
//   // отсортировали
//   for (int i = 0; i < n; i++) {
//     for (int k = i + 1; k < n; k++) {
//       if (a[i][1] > a[k][1]) {
//         int temp = a[k][1];
//         a[k][1] = a[i][1];
//         a[i][1] = temp;
//       }
//     }
//   }
//   // посчитали
//   int result = 1;
//   for (int i = 1; i < n; i++) {
//     if (a[i][1] != a[i - 1][1]) {
//       result++;
//     }
//   }
//   printf("%d", result);
//   return 0;
// }

#include <stdio.h>

#define CLIENTBIG 1000

int main() {
    int n, i, client_id, tmp;
    int a[CLIENTBIG + 1] = {};  // a[i] - сколько покупок сделал клиент i

    // читаем все записи
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d %d %d", &tmp, &client_id, &tmp);
        a[client_id]++;  // клиент client_id сделал еще 1 покупку
    }

    int x = 0;                               // сколько уникальных клиентов
    for (i = 0, x = 0; i <= CLIENTBIG; i++)  // для всех клиентов
        if (a[i])                            // если этот клиент покупал
            x++;  // мы его учитываем, как уникального клиента
    printf("%d\n", x);

    return 0;
}