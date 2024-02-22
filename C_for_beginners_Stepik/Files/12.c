// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// #define N 1000

// int main() {
//     int n, numbers[N];
//     scanf("%d", &n);
//     for (int i = 0; i < n; i++) scanf("%d", &numbers[i]);
//     for (int i = 0; i < n - 1; i++) {
//         for (int j = i; j < n; j++) {
//             if (numbers[i] > numbers[j]) {
//                 int tmp = numbers[i];
//                 numbers[i] = numbers[j];
//                 numbers[j] = tmp;
//             }
//         }
//     }

//     for (int i = 0; i < n; ++i) printf("%d ", numbers[i]);

//     return 0;
// }

// #include <stdio.h>
// #include <stdlib.h>
// #define N 1000

// void prInt(int* a, int n) {
//     for (int i = 0; i < n; i++) printf("%d ", a[i]);
//     printf("\n");
// }
// // Реализация функции сравнения
// int cmpInt(const void* pa, const void* pb) {
//     // Преобразование неопределенного указателя к указателю типа int*
//     // и получение значения
//     int a = *(int*)pa;
//     int b = *(int*)pb;
//     // возвращвемая разность как раз будет
//     // удовлетворять нужному критерию
//     return a - b;
// }

// // Реализация функции сравнения "обратным" порядком
// int cmpIntR(const void* pa, const void* pb) {
//     // Можно сразу получить значения
//     return *(int*)pb - *(int*)pa;
// }
// int main() {
//     int n, numbers[N];
//     scanf("%d", &n);
//     for (int i = 0; i < n; i++) scanf("%d", &numbers[i]);

//     // prInt(numbers, 10);
//     // Вызов функции qsort() для 10 элементов массива numbers
//     qsort(numbers, n, sizeof(int), cmpInt);
//     prInt(numbers, n);
//     // Соритровка с 3 по 8 элементов  массива numbers в "обратном" порядке
//     // qsort(numbers + 2, 5, sizeof(int), cmpIntR);
//     // prInt(numbers, n);
//     return 0;
// }

// #include <stdio.h>
// #include <stdlib.h>
// #define N 1000

// void prIntArr(int* numbers, int n) {
//     for (int i = 0; i < n; i++) printf("%d%s", numbers[i], n == n - 1 ? " \n" : " ");
// }

// int cmpIntR(const void* pa, const void* pb) { return (*(int*)pb > *(int*)pa) - (*(int*)pb < *(int*)pa); }

// int main() {
//     int n, numbers[N];
//     scanf("%d", &n);
//     for (int i = 0; i < n; i++) scanf("%d", &numbers[i]);

//     qsort(numbers, n, sizeof(int), cmpIntR);

//     prIntArr(numbers, n);
//     return 0;
// }

// #include <stdio.h>
// #include <stdlib.h>
// #define N 1000

// void prIntArr(float* numbers, int n) {
//     for (int i = 0; i < n; i++) printf("%.2f%s", numbers[i], n == n - 1 ? " \n" : " ");
// }

// // int cmpfloatR(const void* pa, const void* pb) { return (*(float*)pb > *(float*)pa) - (*(float*)pb <
// // *(float*)pa); }
// int cmpFloat(const void* pa, const void* pb) {
//     return (*(float*)pa > *(float*)pb) - (*(float*)pa < *(float*)pb);
// }

// int main() {
//     int n;
//     float numbers[N];
//     scanf("%d", &n);
//     for (int i = 0; i < n; i++) scanf("%fd", &numbers[i]);

//     qsort(numbers, n, sizeof(float), cmpFloat);

//     prIntArr(numbers, n);
//     return 0;
// }

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #define N 1001

// void printString(char* str, int n) {
//     for (int i = 0; i < n; i++) printf("%c%s", str[i], n == n - 1 ? "." : "");
// }

// int cmpFloat(const void* pa, const void* pb) { return (*(char*)pa > *(char*)pb) - (*(char*)pa <
// *(char*)pb); }

// int main() {
//     char str[N];
//     fgets(str, 1000, stdin);
//     int len = strlen(str), count = 0;

//     for (int i = 0; i < len; i++) {
//         if (str[i] == '.') break;
//         count++;
//     }

//     qsort(str, count, sizeof(str[0]), cmpFloat);

//     printString(str, len);
//     return 0;
// }

#include <stdio.h>
#include <stdlib.h>

#define N 1001

void prIntArr(int* numbers, int n) {
    for (int i = 0; i < n; i++) printf("%d%s", numbers[i], n == n - 1 ? " \n" : " ");
}

int cmpint(const void* pa, const void* pb) {
    int result = 0;
    int x = *(int*)pa;
    int y = *(int*)pb;
    while ((x > 0 && y > 0) || result == 0) {
        result += (x % 10 > y % 10) - (x % 10 < y % 10);
        x /= 10;
        y /= 10;
    }
    return result;
}

int main() {
    int n;
    int numbers[N];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &numbers[i]);

    qsort(numbers, n, sizeof(int), cmpint);

    prIntArr(numbers, n);
    return 0;
}