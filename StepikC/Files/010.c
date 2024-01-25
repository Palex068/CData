// #include <stdio.h>

// int main(void) {
//     int a = 100;
//     int* p_a = &a;  // сохраняем в указатель адрес переменной a
//     printf("a = %d\n", a);  // стандартный способ получить значение переменной a
//     printf("a = %d\n", *p_a);  // получаем значение переменной a через указатель на неё

//     // используя указатель p_a, записываем в переменную a другое значение
//     *p_a = 50;

//     printf("a =  %d\n", *p_a);
//     return 0;
// }

// #include <stdio.h>

// int main(void) {
//     int a = 100;
//     int* p_a = &a;  // сохраняем в указатель адрес переменной a
//     printf("a = %d\n", a);  // стандартный способ получить значение переменной a
//     printf("a = %d\n", *p_a);  // получаем значение переменной a через указатель на неё

//     // используя указатель p_a, записываем в переменную a другое значение
//     *p_a = 50;

//     printf("a =  %d\n", *p_a);

//     printf("%p\n", p_a);
//     p_a = NULL;
//     printf("%p\n", p_a);

//     return 0;
// }

// #include <stdio.h>

// void swap(int a, int b) {
//     int temp;

//     temp = a;
//     a = b;
//     b = temp;
// }

// int main(void) {
//     int x = 4, y = 9;

//     printf("x=%d y=%d\n", x, y);
//     swap(x, y);
//     printf("x=%d y=%d\n", x, y);

//     return 0;
// }

// #include <stdio.h>

// // функция swap принимает два указателя на целые числа
// // другими словами, два адреса в памяти компьютера,
// // в которых записаны целые числа
// void swap(int *a, int *b) {
//     // a -- адрес первого числа
//     // b -- адрес второго числа

//     int temp;
//     // *a -- разыменование указателя
//     // *a позволяет обращаться к значению, хранящемуся по адресу a
//     // выводим значения, хранящиеся по адресам a и b
//     printf("a=%d b=%d\n", *a, *b);

//     // переменной temp присваиваем значение, хранящееся по адресу a
//     temp = *a;
//     // в ячейку по адресу a записываем значение, хранящееся по адресу b
//     *a = *b;
//     // в ячейку по адресу b записываем значение из переменной temp
//     *b = temp;
//     printf("a=%d b=%d\n", *a, *b);
// }

// int main(void) {
//     int x = 4, y = 9;

//     printf("x=%d y=%d\n", x, y);
//     // передаём адреса переменных x и y в фунцию swap
//     swap(&x, &y);

//     printf("x=%d y=%d\n", x, y);

//     return 0;
// }

// #include <stdio.h>

// void print_arr(int arr[], int n) {
//     for (int k = 0; k < n; k++) {
//         printf("arr[%d] = %d\t", k, arr[k]);
//     }

//     printf("\n");
// }

// void print_arr2(int arr[][5], int k, int n) {
//     for (int i = 0; i < k; i++, printf("\n"))
//         for (int j = 0; j < n; j++) printf("arr[%d][%d] = %d\t", i, j, arr[i][j]);

//     printf("\n");
// }

// int main(void) {
//     int q[5] = {5, 4, 2, 3, 4};
//     int q2[2][5] = {{1, 2, 3, 4, 5}, {0, 9, 8, 7, 6}};

//     print_arr(q, 5);

//     print_arr2(q2, 2, 5);

//     return 0;
// }

/*
Минимум-2.
Напишите программу, которая будет вычислять и возвращать
минимальное из трёх чисел, переданных в неё, при помощи функции min.
*/

// #include <stdio.h>
// int min(int a, int b, int c) {
//     int min = a;
//     if (b < min) {
//         min = b;
//     }
//     if (c < min) {
//         min = c;
//     }
//     return min;
// }
// int main(void) {
//     int a, b, c;
//     scanf("%d %d %d", &a, &b, &c);
//     printf("%d", min(a, b, c));
//     return 0;
// }

// #include <stdio.h>

// int factorial(int k) {
//     int res = 1;
//     for (int i = 1; i <= k; i++) {
//         res *= i;
//     }
//     return res;
// }

// int main(void) {
//     int n;
//     scanf("%d", &n);
//     printf("%d", factorial(n));
//     return 0;
// }

// #include <stdio.h>

// int factorial(int k) {
//     int res = 1;
//     for (int i = 1; i <= k; i++) {
//         res *= i;
//     }
//     return res;
// }

// int combin(int n, int k) { return factorial(n) / (factorial(k) * factorial(n - k)); }

// int main(void) {
//     int n = 0, k = 0;
//     scanf("%d%d", &n, &k);

//     printf("%d", combin(n, k));

//     return 0;
// }

// #include <stdio.h>

// int sequence_multipliers(int k) {
//     int x = 1;
//     while (x * (x + 1) * (x + 2) < k + 1) {
//         if (x * (x + 1) * (x + 2) == k) {
//             return x;
//         }
//         x++;
//     }
//     return -1;
// }
// int main(void) {
//     int a;
//     scanf("%d", &a);
//     printf("%d", sequence_multipliers(a));
//     return 0;
// }

// #include <stdio.h>

// void square(int x, char c) {
//     for (int i = 0; i < x; i++) {
//         for (int j = 0; j < x; j++) {
//             printf("%c%s", c, j == x - 1 ? "\n" : "");
//         }
//     }
// }

// int main() {
//     int n;
//     char c;
//     scanf("%d %c", &n, &c);

//     square(n, c);

//     return 0;
// }

// #include <stdio.h>
// void print_date(int d, int m, int y, int k) {
//     switch (k) {
//         case 0:
//             printf("%02d.%02d.%02d", d, m, y % 100);
//             break;
//         case 1:
//             printf("%02d.%02d.%d", d, m, y);
//             break;
//         case 2:
//             printf("%d/%02d/%02d", y, m, d);
//             break;

//         default:
//             printf("error");
//             break;
//     }
// }
// int main() {
//     int d, m, y, k;

//     scanf("%d %d %d %d", &d, &m, &y, &k);
//     print_date(d, m, y, k);

//     return 0;
// }

// #include <stdio.h>
// int main(void) {
//     int a = 0, b = 0, c = 0;
//     scanf("%d %d %d", &a, &b, &c);

//     int* p_a = &a;
//     int* p_b = &b;
//     int* p_c = &c;

//     if (*p_a > *p_b) *p_a = *p_b;
//     if (*p_a > *p_c) *p_a = *p_c;

//     *p_b = *p_a;
//     *p_c = *p_a;

//     printf("%d %d %d", a, b, c);

//     return 0;
// }

// #include <stdio.h>

// int delim_konfety(int a) {
//     int res = 1;
//     while (a > 1) {
//         a = a - a / 2;
//         res++;
//     }
//     return res;
// }

// int main()
// {
//     int konfet;
//     scanf("%d", &konfet);

//     int detey = delim_konfety(konfet);
//     printf("%d\n", detey);

//     return 0;
// }


