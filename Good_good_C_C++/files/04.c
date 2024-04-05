// #include <stdio.h>

// int main(void) {
//     int count = 0;
//     int s = 0;

//     while (count++ <= 5) s += count;

//     printf("%d", s);

//     return 0;
// }

// #include <stdio.h>

// int main(void) {
//     int x;

//     while (scanf("%d", &x) == 1 && x != 0) printf("%d ", x * x);

//     return 0;
// }
// #include <stdio.h>

// int main(void) {
//     int x;
//     double sum;

//     scanf("%d", &x);

//     while (x > 0) {
//         sum += 1.0 / (x * x);
//         x--;
//     }

//     printf("%.3lf", sum);

//     return 0;
// }

// #include <stdio.h>

// int main(void) {
//     int x, sum;

//     scanf("%d", &x);

//     while (x > 0) {
//         sum += x % 10;
//         x /= 10;
//     }

//     printf("%d", sum);

//     return 0;
// }

// #include <stdio.h>

// int main() {
//     int x, num0 = 0, num1 = 1, num = 1, counter = 0;

//     scanf("%d", &x);

//     while (counter != x) {
//         printf("%d ", num);
//         num = num0 + num1;
//         num0 = num1;
//         num1 = num;
//         counter++;
//     }

//     return 0;
// }

// #include <stdio.h>

// int main() {
//     int n, m;

//     scanf("%d %d", &n, &m);

//     while (n <= m) {
//         if (n % 3 == 0) printf("%d ", n);
//         n++;
//     }

//     return 0;
// }

// #include <stdio.h>
// #define LEFT 100
// #define RIGHT 999

// int main() {
//     int n = LEFT;

//     while (n <= RIGHT) {
//         if (n % 47 == 6 || n % 53 == 45) printf("%d ", n);
//         n++;
//     }

//     return 0;
// }

// #include <math.h>
// #include <stdio.h>

// int main() {
//     int count = 0, n;

//     scanf("%d", &n);

//     // посчитаем количество знаков в числе
//     int ncopy = n;

//     while (ncopy > 0) {
//         ncopy /= 10;
//         count++;
//     }

//     count--;

//     char res = 1;

//     while (n >= 10) {
//         // вычислим первую и последнюю цифры и сравним их
//         int a = n / pow(10, count);
//         int b = n % 10;
//         // printf("%d %d\n", a, b); // проверочная печать
//         if (a != b) {  // если не равны выходим из цикла с res = 0
//             res = 0;
//             break;
//         }
//         // откидываем от n первую и последнюю цифры
//         n -= a * pow(10, count);
//         n /= 10;
//         // printf("%d\n", n); // проверочная печать
//         // уменьшаем счетчик знаков
//         count -= 2;
//     }
//     // печатаем через тернарный оператор ответ
//     printf("%s", res ? "yes" : "no");

//     return 0;
// }

// #include <stdio.h>

// int main() {
//     int a, b;

//     scanf("%d %d", &a, &b);

//     while (b > 0) {
//         if (a > b) {
//             int tmp = a;
//             a = b;
//             b = tmp;
//         }
//         b %= a;
//     }

//     printf("%d", a);
//     return 0;
// }

// #include <stdio.h>

// int main(void) {
//     int s = 0, n = 0;

//     scanf("%d", &n);

//     for (int i = 5; i++ <= n; s += i)
//         ;

//     printf("%d", s);

//     return 0;
// }

// #include <stdio.h>

// int main(void) {
//     int a0, d, n;
//     scanf("%d; %d; %d", &a0, &d, &n);

//     for (int i = 0; i < n; i++) {
//         int res = a0 + i * d;
//         printf("%d ", res);
//     }

//     return 0;
// }

// #include <math.h>
// #include <stdio.h>

// int main(void) {
//     int b0, q, n;
//     scanf("%d; %d; %d", &b0, &q, &n);

//     for (int i = 0; i < n; i++) {
//         int res = b0 * pow(q, i);
//         printf("%d ", res);
//     }

//     return 0;
// }

// #include <math.h>
// #include <stdio.h>

// int main(void) {
//     int n;
//     scanf("%d", &n);

//     for (int i = 0; i < n; i++) {
//         printf("=");
//     }

//     return 0;
// }

// #include <stdio.h>

// int main(void) {
//     int n;
//     scanf("%d", &n);

//     for (int i = 1; i <= n / 2; i++) {
//         if (n % i == 0) printf("%d ", i);
//     }
//     printf("%d ", n);

//     return 0;
// }

// #include <stdio.h>

// int main(void) {
//     int n, res = 0;
//     scanf("%d", &n);

//     for (int i = 1; i < n; i++) {
//         if (i % 3 == 0 || i % 5 == 0) res += i;
//     }
//     printf("%d", res);

//     return 0;
// }
// #include <stdio.h>

// int main(void) {
//     int n, res = 0;

//     while (scanf("%d", &n) == 1 && n != 0) {
//         res = res * 10 + n;
//     }

//     printf("%d", res);

//     return 0;
// }

// #include <stdio.h>

// int main(void) {
//     int n, res = 0;

//     scanf("%d", &n);

//     while (n > 0) {
//         res = res * 10 + n % 10;
//         n /= 10;
//     }

//     printf("%d", res);

//     return 0;
// }

// #include <stdio.h>

// int main(void) {
//     int a, b, c, d, e, f;

//     scanf("%1d %1d %1d %1d %1d %1d", &a, &b, &c, &d, &e, &f);

//     char res = (a + b + c) == (d + e + f);

//     printf("%s", res ? "yes" : "no");

//     return 0;
// }

// #include <stdio.h>

// int main(void) {
//     int pass_code = 13;
//     int enter_code;

//     do {
//         printf("Please enter the secret code: ");
//         scanf("%d", &enter_code);
//     } while (enter_code != pass_code);

//     printf("Access is allowed\n");

//     return 0;
// }

// #include <stdio.h>

// int main(void) {
//     int pass_code = 13;
//     int enter_code;
//     int c;

//     do {
//         printf("Please enter the secret code: ");
//         scanf("%d", &enter_code);

//         while ((c = getchar()) != '\n' && c != EOF) {
//         }
//     } while (enter_code != pass_code);

//     printf("Access is allowed\n");

//     return 0;
// }

// #include <stdio.h>

// int main(void) {
//     int pass_code = 13;
//     int enter_code;
//     int c;

//     do {
//         printf("Please enter the secret code: ");
//         scanf("%d", &enter_code);

//         while ((c = getchar()) != '\n' && c != EOF) {
//         }
//     } while (enter_code != pass_code);

//     while ((c = getchar()) != '\n' && c != EOF) {
//     }

//     printf("Access is allowed\n");

//     return 0;
// }

// #include <stdio.h>

// int main(void) {
//     int res = 0;

//     for (int i = -3; i <= 7; ++i) {
//         for (int j = 1; j <= 5; ++j) {
//             for (int k = 2; k <= 4; ++k) {
//                 res += (i + j - k) * (i + j - k);
//             }
//         }
//     }
//     printf("%d", res);
//     return 0;
// }

// #include <stdio.h>

// int main(void) {
//     int p = 1, n, i = 1;

//     scanf("%d", &n);

//     do {
//         p *= i;
//     } while (i++ < n);

//     printf("%d", p);

//     return 0;
// }

// #include <stdio.h>
// #define LAST_DIGIT 13

// int main(void) {
//     int res = 0, n;

//     do {
//         scanf("%d", &n);
//         if (n > 0) res += n;
//     } while (n != LAST_DIGIT);

//     printf("%d", res);

//     return 0;
// }

// #include <stdio.h>

// int main(void) {
//     int n, i = 1;
//     double res = 0;

//     scanf("%d", &n);

//     do {
//         res += 1 / (double)n;
//     } while (++i <= n);

//     printf("%.2lf", res);

//     return 0;
// }

// #include <stdio.h>
// #include <stdlib.h>

// #define FIRST_DIGIT 1
// #define LAST_DIGIT 1000

// int main(void) {
//     int a = FIRST_DIGIT;
//     int b = LAST_DIGIT;
//     int x, m;

//     scanf("%d", &x);

//     do {
//         m = rand() % (b - a + 1) + a;
//         if (m < x) a = m;
//         if (m > x) b = m;
//     } while (m != x);

//     printf("%d", m);

//     return 0;
// }

// #include <stdio.h>

// int main(void) {
//     int n;

//     scanf("%d", &n);

//     for (int i = 0; i < n; i++) {
//         for (int j = i; j >= 0; j--) {
//             printf("*");
//         }
//         printf("\n");
//     }

//     return 0;
// }

// #include <stdio.h>

// char st[100];

// int main(void) {
//     int n = 0;

//     scanf("%d", &n);

//     for (int i = 0; i < n; i++) {
//         st[i] = '*';
//         st[i + 1] = '\n';
//         printf(st);
//     }
//     return 0;
// }

// #include <stdio.h>

// int main(void) {
//     int lines, cnt = 0;
//     scanf("%d", &lines);
//     while (cnt++ < lines) {
//         for (int i = 0; i < cnt; i++) {
//             putchar(0x2A);
//         }
//         putchar(0x0A);
//     }
// }

// #include <stdio.h>

// int main(void) {
//     int n;

//     scanf("%d", &n);

//     for (int i = 0; i <= n; i++) {
//         for (int j = 0; j <= n - i - 1; j++) {
//             printf(" ");
//         }
//         for (int j = i * 2 - 1; j > 0; j--) {
//             printf("*");
//         }
//         printf("\n");
//     }

//     return 0;
// }

// #include <stdio.h>

// char sp[100];

// int main(void) {
//     int n = 0;
//     memset(sp, ' ', 100);
//     scanf("%d", &n);

//     for (int i = 0; i < n; i++) {
//         sp[n - 1 + i] = '*';
//         sp[n - 1 - i] = '*';
//         sp[n + i] = '\n';
//         sp[n + i + 1] = 0x00;
//         printf(sp);
//     }
//     return 0;
// }

// /*
// ------*
// -----***
// ----*****
// ---*******
// --*********
// -***********
// *************
// n=7

// номер  число    число
// строки пробелов звезд
// 1       6       2-1=1
// 2       5       4-1=3
// 3       4       6-1=5
// 4       3       8-1=7
// 5       2       10-1=9
// 6       1       12-1=11
// 7       0       14-1=13
// */

// #include <stdio.h>
// int main() {
//     int n;
//     scanf("%d", &n);
//     for (int i = 1; i <= n; i++) {
//         for (int j = 1; j <= n - i; j++) printf(" ");
//         for (int j = 1; j <= 2 * i - 1; j++) printf("*");
//         printf("\n");
//     }
//     return 0;
// }

// #include <stdio.h>

// int main(void) {
//     int m, n;

//     scanf("%d %d", &m, &n);

//     for (int i = m; i <= n; i++) {
//         int icopy = i, reverse = 0;

//         while (icopy) {
//             reverse = reverse * 10 + icopy % 10;
//             icopy /= 10;
//         }

//         if (i == reverse) {
//             printf("%d ", i);
//         }
//     }
//     return 0;
// }

// #include <math.h>
// #include <stdio.h>

// int main(void) {
//     int m, n, k;

//     scanf("%d %d %d", &m, &n, &k);

//     double sum = 0;

//     for (int i = 1; i <= m; i++) {
//         for (int j = 1; j <= n; j++) {
//             for (int t = 1; t <= k; t++) {
//                 sum += j * j / (pow(i + t, 3) - t);
//             }
//         }
//     }
//     sum /= m + n + k;

//     printf("%.4lf", sum);

//     return 0;
// }

// #include <stdio.h>

// int main(void) {
//     double x, s = 0.0;

//     while (scanf("%lf", &x) == 1) {
//         if (x < 0) break;

//         s += x;
//     }

//     printf("s = %.2f\n", s);

//     return 0;
// }

// #include <stdio.h>

// int main(void) {
//     int x, s = 0;

//     while (scanf("%d", &x) == 1 && x != 0) {
//         if (x % 2 == 0) continue;

//         s += x;
//     }

//     printf("s = %d\n", s);

//     return 0;
// }

// #include <stdio.h>

// int main(void) {
//     for (int i = 1; i <= 100; ++i) {
//         if (i % 3 != 0 || i % 5 != 0) continue;

//         printf("%d ", i);
//     }

//     return 0;
// }

// #include <stdio.h>

// int main(void) {
//     int s = 0;
//     for (int i = 1; i <= 10; ++i)
//         for (int j = 7; j >= 5; --j) {
//             if (i - j > 0) goto exit_sum;
//             s += i - j;
//         }

// exit_sum:
//     printf("s = %d\n", s);

//     return 0;
// }

// #include <stdio.h>

// int main(void) {
//     int n = 5, m = 7;
//     int total = 5;

//     for (int i = 0; i < total; ++i) {
//         int x, y;
//         scanf("%d, %d", &x, &y);

//         if (x >= 1 && x <= n && y >= 1 && y <= m) {
//             printf("(%d, %d)\n", x, y);
//         } else
//             continue;
//     }

//     return 0;
// }

// #include <stdio.h>

// int main(void) {
//     int n, res = 1;

//     while (scanf("%d", &n) == 1 && n != 0) {
//         if (n < 0)
//             continue;
//         else
//             res *= n;
//     }
//     printf("%d", res);
//     return 0;
// }

// #include <stdio.h>

// int main(void) {
//     int n;

//     scanf("%d", &n);

//     for (int i = 1; i < n; i++) {
//         if (i * i >= n) break;
//         printf("%d ", i);
//     }
//     return 0;
// }

// #include <stdio.h>

// int main(void) {
//     int n, i = 2;

//     scanf("%d", &n);
//     while (n != 1) {
//         while (n % i == 0) {
//             n /= i;
//             printf("%d ", i);
//         }
//         i++;
//     }
//     return 0;
// }

// #include <stdio.h>

// int main(void) {
//     int n, m, sum = 0;

//     scanf("%d %d", &n, &m);
//     for (int i = 0; i <= n; i++) {
//         for (int j = 0; j <= m; j++) {
//             if (i + j >= 10) goto end_of_sum;
//             sum += i + j;
//         }
//     }
// end_of_sum:
//     printf("%d", sum);
//     return 0;
// }

// #include <stdio.h>

// int main(void) {
//     int n, m, sum = 0;

//     scanf("%d %d", &n, &m);
//     for (int i = 0; i <= n; i++) {
//         for (int j = 0; j <= m; j++) {
//             if (i + j >= 10) break;
//             sum += i + j;
//         }
//     }

//     printf("%d", sum);
//     return 0;
// }

// #include <math.h>
// #include <stdio.h>

// int main(void) {
//     int n;

//     scanf("%d", &n);

//     char res = 1;
//     // проверим ввод на 1 и 2
//     if (n == 1 || n == 2)
//         ;
//     // откинем все четные числа
//     else if (n % 2 == 0) {
//         res = 0;
//     } else {
//         // проверять будем от 3 до квадратного корня из числа с шагом 2
//         for (int i = 3; i < sqrt(n); i += 2) {
//             if (n % i == 0) {
//                 res = 0;
//                 break;
//             }
//         }
//     }

//     printf("%s", res ? "yes" : "no");
//     return 0;
// }

// #include <stdio.h>

// #define MUL(X, Y) X* Y
// #define ADD(X, Y) ((X) + (Y))
// #define T_ADD(X, Y) "Adding two values " #X " and " #Y
// #define RES_N(RES) res_##RES

// int main(void) {
//     int a = 2, b = 5;
//     int res_1 = MUL(7, b);
//     int res_2 = MUL(a + 2, b - 1);
//     int res_3 = ADD(7, b * 2);
//     printf(T_ADD(i, j) "\n");
//     printf("%d %d %d", RES_N(1), RES_N(2), RES_N(3));

//     return 0;
// }

// #include <stdio.h>

// int main(void) {
//     char d = 10;
//     char *gpt;
//     gpt = &d;

//     printf("gpt = %p, *gpt = %d, d = %d\n", gpt, *gpt, d);

//     *gpt = 100;
//     printf("gpt = %p, *gpt = %d, d = %d\n", gpt, *gpt, d);

//     return 0;
// }

// #include <stdio.h>

// int main(void) {
//     int d = 10;
//     int *gpt = &d;

//     printf("gpt = %p, *gpt = %d, d = %d\n", gpt, *gpt, d);

//     *gpt = 75432;
//     printf("gpt = %p, *gpt = %d, d = %d\n", gpt, *gpt, d);

//     return 0;
// }

// #include <stdio.h>

// int main(void) {
//     short var = 7;
//     short* ptr_var;

//     ptr_var = &var;
//     *ptr_var = 8;

//     printf("%d\n", *ptr_var);

//     return 0;
// }

// #include <stdio.h>

// int main(void) {
//     short* ptr_var;
//     *ptr_var = 8;

//     return 0;
// }

// #include <stdio.h>

// int main(void) {
//     double var_d = 0;

//     double* ptr_var_d = &var_d;

//     *ptr_var_d = -54.38;

//     return 0;
// }

// #include <stdio.h>

// int main(void) {
//     int init, k;

//     scanf("%d", &init);
//     k = init;
//     int* ptr_k = &k;
//     *ptr_k += 10;

//     return 0;
// }

// #include <stdio.h>

// int main(void) {
//     short a, b;

//     scanf("%hd", &b);

//     short* ptr_a = &a;
//     *ptr_a = b;

//     printf("%d", a);
//     return 0;
// }

// #include <stdio.h>

// int main(void) {
//     short a, b, init_a, init_b;

//     scanf("%hd, %hd", &a, &b);
//     init_a = a;
//     init_b = b;

//     short* ptr_a = &a;
//     short* ptr_b = &b;

//     *ptr_a = init_b;
//     *ptr_b = init_a;

//     return 0;
// }

// #include <stdio.h>

// int main(void) {
//     short a, b;

//     scanf("%hd, %hd", &a, &b);

//     short* ptr_a = &a;
//     short* ptr_b = &b;

//     int res = *ptr_a * *ptr_b;

//     printf("%d", res);

//     return 0;
// }

// #include <stdio.h>

// int main(void) {
//     int arg = 7;
//     int *ptr_arg, *ptr;

//     ptr_arg = &arg;

//     return 0;
// }

// #include <stdio.h>

// int main(void) {
//     int arg = 7;
//     int *ptr_arg, *ptr;

//     ptr_arg = &arg;
//     ptr = ptr_arg;

//     printf("*ptr = %d, arg = %d\n", *ptr, arg);

//     *ptr_arg = 100;
//     printf("*ptr = %d, arg = %d\n", *ptr, arg);

//     return 0;
// }

// #include <stdio.h>

// int main(void) {
//     int arg = 777;
//     int *ptr_arg;
//     char *ptr;

//     ptr_arg = &arg;
//     ptr = ptr_arg;

//     return 0;
// }

// #include <stdio.h>

// int main(void) {
//     int *ptr;
//     *ptr = 1;

//     return 0;
// }

// #include <stdio.h>

// int main(void) {
//     int arg = 5;
//     int *ptr = &arg;
//     *ptr = 1;

//     return 0;
// }

// #include <stdio.h>

// int main(void) {
//     int arg = 5;
//     int *ptr = NULL;

//     if (ptr != NULL) *ptr = 1;

//     return 0;
// }

// #include <stdio.h>

// int main(void) {
//     short a, b;

//     scanf("%hd, %hd", &a, &b);

//     short *ptr_a = &a;
//     short *ptr_b = &b;

//     void *tmp = ptr_a;
//     ptr_a = ptr_b;
//     ptr_b = tmp;

//     printf("%d %d", *ptr_a, *ptr_b);

//     return 0;
// }

// #include <stdio.h>

// int main(void) {
//     int var;

//     scanf("%d", &var);

//     int *ptr_var = &var;
//     char *ptr_ch = (char *)ptr_var;

//     printf("%d", *ptr_ch);

//     return 0;
// }

// #include <stdio.h>

// int main(void) {
//     short var;

//     scanf("%hd", &var);

//     short *ptr_var = &var;
//     char *ptr_ch = (char *)ptr_var;

//     *ptr_ch = 2;

//     printf("%d", var);

//     return 0;
// }

// int main(void) {
//     char ch = 'a';
//     char* ptr = &ch;

//     int* ptr_i = (int*)ptr;
//     *ptr_i = 0;

//     return 0;
// }

// #include <stdio.h>

// int main(void) {
//     if (global_ptr != NULL) *global_ptr = 10;
//     return 0;
// }

// #include <stdio.h>

// int main(void) {
//     int g = 4;
//     int *ptr = &g;

//     printf("ptr = %u\n", ptr);

//     return 0;
// }

// #include <stdio.h>

// int main(void) {
//     int g = 4;
//     int *ptr = &g;

//     printf("%p\n", ptr);

//     ptr += 3;
//     ptr -= 4;
//     ptr = ptr + 10;
//     ptr = ptr - 9;
//     --ptr;
//     ptr++;

//     printf("%p\n", ptr);

//     return 0;
// }

// #include <stdio.h>

// int main(void) {
//     short g = 4, d = 1;
//     short *ptr = &g;
//     short *p = &d;

//     printf("ptr = %u, p = %u\n", ptr, p);

//     int res = ptr - p;

//     printf("res = %d\n", res);

//     return 0;
// }

// #include <stdio.h>

// int main(void) {
//     int g = 476789;
//     char *ptr = (char *)&g;

//     for (int i = 0; i < sizeof(g); ++i) {
//         printf("%d ", *ptr);
//         ptr++;
//     }

//     return 0;
// }

// #include <stdio.h>

// int main(void) {
//     int g = 476789;
//     char *ptr = (char *)&g;

//     int x = *ptr + 1;
//     printf("x = %d\n", x);

//     return 0;
// }

// #include <stdio.h>

// int main(void) {
//     double value;

//     scanf("%lf", &value);

//     char *ptr = (char *)&value;

//     for (int i = 0; i < 8; i++) printf("%d ", *ptr++);

//     return 0;
// }

// #include <stdio.h>

// int main(void) {
//     int value;

//     scanf("%d", &value);

//     short *ptr = (short *)&value;

//     for (int i = 0; i < 2; i++) {
//         *ptr++ += 1;
//     }
//     printf("%d ", value);

//     return 0;
// }

// #include <stdio.h>

// int main(void) {
//     int a, b;

//     scanf("%d; %d", &a, &b);

//     void* p1 = (void*)a;
//     void* p2 = (void*)b;

//     int res = (p2 - p1) * sizeof(int) / sizeof(double);

//     printf("%d", res);

//     return 0;
// }

// #include <stdio.h>

// int main(void) {
//     int a;

//     scanf("%d", &a);

//     char *ptr_ch = (char *)&a;

//     char count = sizeof(int);

//     while (count--) {
//         *ptr_ch++ |= 9;
//     }

//     printf("%d", a);

//     return 0;
// }

// #include <stdio.h>

// int main(void) {
//     int a;

//     scanf("%d", &a);

//     char *ptr_ch = (char *)&a;

//     char count = sizeof(int);
//     unsigned char mask = 0b00111101;

//     while (count--) {
//         *ptr_ch++ &= mask;
//     }

//     printf("%d", a);

//     return 0;
// }
#include <stdio.h>
#define DELTA 1

int main(void) {
    int a, b, c, d;

    scanf("%d %d %d %d", &a, &b, &c, &d);

    char wight = (a > b ? a : b) - (c > d ? c : d) - DELTA >= 0;
    char height = (a < b ? a : b) - (c < d ? c : d) - DELTA >= 0;

    char res = wight * height;

    printf("%s", res ? "yes" : "no");

    return 0;
}