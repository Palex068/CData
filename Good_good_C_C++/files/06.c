// #include <stdio.h>

// int main(void) {
//     int x;
//     if (scanf("%d", &x) == 1)
//         puts("Correct input!");
//     else
//         puts("Incorrect input!");

//     return 0;
// }

// #include <stdio.h>

// void print_hi(void) { puts("Hello! I'm Sergey Balakirev!"); }

// int main(void) { return 0; }

// int main(void) {
//     print_hi();
//     print_hi();
//     print_hi();
//     return 0;
// }

// int get_per(int width, int height) {
//     int p = 2 * (width + height);
//     return p;
// }

// int main(void) {
//     int w = 2, h = 5;

//     get_per(w, h);
//     int per_1 = get_per(w + 1, h - 4);
//     int per_2 = get_per(w, 3);
//     int per_3 = get_per(1, 3);

//     return 0;
// }

// #include <stdio.h>

// int fact(int n) {
//     if (n < 0) return -1;
//     int res = 1;
//     for (int i = 1; i <= n; i++) {
//         res *= i;
//     }
//     return res;
// }

// int main(void) {
//     int res = fact(-10);
//     printf("%d", res);
//     return 0;
// }

// #include <stdio.h>

// int get_volume(int h, int w, int d) {
//     int res = h * w * d;
//     return res;
// }

// int main(void) {
//     int height, width, depth;
//     scanf("%d %d %d", &height, &width, &depth);
//     int res = get_volume(height, width, depth);
//     printf("%d", res);
//     return 0;
// }
// #include <stdio.h>

// int is_triangle(int a, int b, int c) {
//     int res = (a < b + c) * (b < a + c) * (c < a + b);
//     return res;
// }

// int main(void) {
//     int a, b, c;
//     scanf("%d %d %d", &a, &b, &c);
//     int res = is_triangle(a, b, c);
//     printf("%d", res);
//     return 0;
// }

// #include <math.h>
// #include <stdio.h>

// double sq4_x(double x) {
//     double res = (x < 0) ? NAN : pow(x, 0.25);
//     return res;
// }

// int main(void) {
//     printf("%f\n", sq4_x(16));
//     return 0;
// }

// double sq4_x(double x) {
//     double res = (x < 0) ? NAN : pow(x, 0.25);
//     return res;
//     puts("sq4_x");
// }

// double sq4_x(double x) {
//     if (x < 0) return NAN;

//     return pow(x, 0.25);
// }

// void print_even_x(int x) {
//     if (x % 2 == 0) printf("x = %d\n", x);
// }

// int main(void) {
//     printf("%f\n", sq4_x(-16));
//     print_even_x(4);

//     return 0;
// }

// void print_even_x(int x) {
//     if (x % 2 != 0) return;

//     printf("x = %d\n", x);
// }

// double min_2(double a, double b) { return (a < b) ? a : b; }

// int main(void) {
//     int x = 1, y = -2, z = 10;

//     double res_1 = min_2(x, y);
//     double res_2 = min_3(x, y, z);
//     double res_3 = min_2(min_2(x, y), z);
//     double res_4 = min_2(x, min_2(y, z));

//     printf("res_1 = %.2f, res_2 = %.2f, res_3 = %.2f, res_4 = %.2f\n", res_1, res_2, res_3, res_4);

//     return 0;
// }

// int get_square(int x) { return x * x; }

// int main(void) {
//     int a = 7, b = 7, c = 7;
//     int res_1 = get_square(a);
//     int res_2 = get_square(b++);
//     int res_3 = get_square(--c);

//     return 0;
// }

// #include <stdio.h>

// int sum_two(int a, int b) { return a + b; }

// int main(void) {
//     int a = 3, b = 2;
//     int res_1 = sum_two(a, a);
//     printf("%d ", res_1);
//     a = 3;
//     b = 2;
//     int res_2 = sum_two(++a, b);
//     printf("%d ", res_2);
//     a = 3;
//     b = 2;
//     int res_3 = sum_two(a, b++);
//     printf("%d ", res_3);

//     return 0;
// }

// #include <stdio.h>

// double get_mean2(int a, int b) {
//     double result = (a + b) / 2.0;
//     return result;
// }

// int main(void) {
//     int a, b;

//     scanf("%d %d", &a, &b);

//     double res = get_mean2(a, b);

//     printf("%.1lf", res);

//     return 0;
// }
// #include <stdio.h>

// int get_sum2(int a, int b) {
//     int result = a + b;
//     return result;
// }

// int main(void) {
//     int a, b, c;

//     scanf("%d %d %d", &a, &b, &c);

//     int res = get_sum2(c, get_sum2(a, b));

//     printf("%.d", res);

//     return 0;
// }

// #include <stdio.h>

// int is_even(int a) {
//     int res = a % 2 ? 0 : 1;
//     return res;
// }

// int main(void) {
//     int x;
//     while (scanf("%d", &x) == 1) {
//         if (is_even(x)) {
//             printf("%d ", x);
//         }
//     }
//     return 0;
// }

// #include <stdio.h>
// #define A -2.5
// #define B 3.5

// int is_range(double x, double a, double b) {
//     int res = (x > a) * (x < b);
//     return res;
// }

// int main(void) {
//     double x;
//     while (scanf("%lf", &x) == 1) {
//         if (!is_range(x, A, B)) {
//             printf("%.1lf ", x);
//         }
//     }
//     return 0;
// }

// #include <math.h>
// #include <stdio.h>

// double get_length(double x, double y) {
//     double res = sqrt(x * x + y * y);
//     return res;
// }

// int main(void) {
//     double x, y;
//     if (scanf("%lf %lf", &x, &y) == 2) {
//         double result = get_length(x, y);
//         printf("%.2lf ", result);
//     }
//     return 0;
// }

// #include <stdio.h>

// double get_qm(double qm_1, int m, int x) {
//     double res = ((m - 1) / (double)m) * qm_1 + (1 / (double)m) * x;
//     return res;
// }

// int main(void) {
//     int x;
//     int m = 1;
//     double result = 0;

//     while (scanf("%d", &x) == 1) {
//         result = get_qm(result, m++, x);
//     }
//     printf("%.3lf ", result);
//     return 0;
// }

// #include <stdio.h>

// double per_sq(double w, double h) {
//     if (w < 0 || h < 0) return 0;

//     return 2 * (w + h);
// }

// int main(void) {
//     printf("per = %.2f\n", per_sq(2.5, 3.5));
//     return 0;
// }

// #include <stdio.h>

// double per_sq(double w, double h);

// int main(void) {
//     printf("per = %.2f\n", per_sq(2.5, 3.5));
//     return 0;
// }

// double per_sq(double w, double h) {
//     if (w < 0 || h < 0) return 0;

//     return 2 * (w + h);
// }

// double per_sq(double w, double h) {
//     if (w < 0 || h < 0) return 0;

//     return 2 * (w + h);
// }

// #include <stdio.h>

// #include "func.h"

// int main(void) {
//     printf("per = %.2f\n", per_sq(2.5, 3.5));
//     return 0;
// }

// #include <math.h>
// #include <stdio.h>

// double get_geom(int a, int b);

// int main(void) {
//     int a, b;
//     scanf("%d, %d", &a, &b);

//     double result = get_geom(a, b);

//     printf("%.2lf", result);

//     return 0;
// }

// double get_geom(int a, int b) {
//     double res = sqrt(a * b);
//     return res;
// }

// #include <stdio.h>

// int calc_rect(int w, int h, int t);

// int main(void) {
//     int a, b, t;
//     scanf("%d, %d, %d", &a, &b, &t);

//     int result = calc_rect(a, b, t);

//     printf("%d", result);

//     return 0;
// }

// int calc_rect(int w, int h, int t) {
//     int res;
//     if (t == 1) {
//         res = w * h;
//     } else
//         res = 2 * (w + h);
//     return res;
// }

// #include <stdio.h>

// int get_max(int a, int b);
// int get_min(int a, int b);

// int main(void) {
//     int a, b, t;
//     scanf("%d, %d, %d", &a, &b, &t);
//     int result;
//     if (t == 1)
//         result = get_max(a, b);
//     else
//         result = get_min(a, b);

//     printf("%d", result);

//     return 0;
// }

// int get_max(int a, int b) {
//     if (a > b)
//         return a;
//     else
//         return b;
// }

// int get_min(int a, int b) {
//     if (a > b)
//         return b;
//     else
//         return a;
// }

// #include <stdio.h>
// #define PI 3.1415

// double circle_len(double radius);

// int main(void) {
//     double r;
//     scanf("%lf", &r);

//     double result = circle_len(r);

//     printf("%.2lf", result);

//     return 0;
// }

// double circle_len(double radius) {
//     double res = radius * 2 * PI;
//     return res;
// }

// #include <stdio.h>

// int main(void) {
//     short var_a = 10;
//     short* ptr = &var_a;
//     *ptr = 5;

//     return 0;
// }

// void swap_2(int* a, int* b) {
//     int t = *a;
//     *a = *b;
//     *b = t;
// }

// int main(void) {
//     int x = 5, y = 10;
//     swap_2(&x, &y);

//     return 0;
// }

// #include <stdio.h>

// int sum_ar(const short* arr, int length) {
//     int res = 0;
//     for (int i = 0; i < length; ++i) res += arr[i];

//     return res;
// }

// int main(void) {
//     short ar[] = {1, 2, 3, 4, 5};
//     int res = sum_ar(ar, sizeof(ar) / sizeof(*ar));

//     printf("res = %d\n", res);

//     return 0;
// }

// const char* find_space(const char* buf) {
//     while (*buf != '\0') {
//         if (*buf == ' ') return buf;
//         buf++;
//     }
// }

// void show_ar2D(const short (*ar)[3], int rows) {
//     for (int i = 0; i < rows; ++i) {
//         for (int j = 0; j < 3; ++j) printf("%d ", ar[i][j]);
//         printf("\n");
//     }
// }

// int main(void) {
//     short ar[][3] = {{1, 2, 3}, {4, 5, 6}};
//     show_ar2D(ar, sizeof(ar) / sizeof(*ar));

//     return 0;
// }

// #include <stdio.h>

// #define COLS 3

// void show_ar2D(const short (*ar)[COLS], int rows) {
//     for (int i = 0; i < rows; ++i) {
//         for (int j = 0; j < COLS; ++j) printf("%d ", ar[i][j]);
//         printf("\n");
//     }
// }

// int main(void) {
//     short ar[][COLS] = {{1, 2, 3}, {4, 5, 6}};
//     show_ar2D(ar, sizeof(ar) / sizeof(*ar));

//     return 0;
// }

// #include <stdio.h>

// #define MAX 10

// int sum_ar(const int *ar, int len) {
//     int res = 0;
//     for (int i = 0; i < len; i++) {
//         res += ar[i];
//     }
//     return res;
// }

// int main(void) {
//     int ar[MAX] = {0};
//     for (int i = 0; i < MAX; i++) {
//         scanf("%d", &ar[i]);
//     }

//     int *ptr = ar;
//     int result = sum_ar(ptr, sizeof(ar) / sizeof(*ar));

//     printf("%d", result);

//     return 0;
// }

// #include <stdio.h>

// #define MAX 20

// int prod_ar(const int *ar, int len) {
//     int res = 1;
//     for (int i = 0; i < len; i++) {
//         res *= ar[i];
//     }
//     return res;
// }

// int main(void) {
//     int ar[MAX] = {0}, count = 0;
//     for (int i = 0; i < MAX; i++) {
//         if (scanf("%d", &ar[i]) == 1)
//             count++;
//         else
//             break;
//     }

//     int *ptr = ar;
//     int result = prod_ar(ptr, count);

//     printf("%d", result);

//     return 0;
// }

// #include <stdio.h>
// #include <string.h>

// #define NUMBERS 20
// #define STR_LEN 100

// int to_csv(char *str, unsigned int str_len, const double *ar, const int ar_len) {
//     int res = 0;
//     strcpy(str, "csv:");
//     for (int i = 0; i < ar_len; i++) {
//         char buff[8];
//         sprintf(buff, " %.2lf%s", ar[i], i == ar_len - 1 ? "" : ";");
//         strcat(str, buff);
//         res++;
//     }
//     if (strlen(str) < str_len) str[strlen(str)] = '\0';

//     return res;
// }

// int main(void) {
//     double ar[NUMBERS] = {0};
//     int count = 0;
//     char str[STR_LEN];

//     for (int i = 0; i < NUMBERS; i++) {
//         if (scanf("%lf", &ar[i]) == 1)
//             count++;
//         else
//             break;
//     }

//     const double *ar_ptr = ar;
//     char *str_ptr = str;
//     to_csv(str_ptr, STR_LEN, ar_ptr, count);

//     printf("%s", str);

//     return 0;
// }

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// #define NUMBERS 20

// int get_data_csv(double ar[], int len, char* str) {
//     int count = 0;
//     while (strpbrk(str, ":;")) {
//         str = strpbrk(str, ":;");
//         ar[count++] = atof(++str);
//         if (count == len - 1) return len;
//     }
//     return count;
// }

// int main(void) {
//     char str[100] = {0};
//     fgets(str, sizeof(str) - 1, stdin);
//     char* ptr_n = strrchr(str, '\n');
//     if (ptr_n != NULL) *ptr_n = '\0';
//     ptr_n = str;
//     double ar[NUMBERS];

//     int result = get_data_csv(ar, NUMBERS, ptr_n);

//     for (int i = 0; i < result; i++) {
//         printf("%.2lf ", ar[i]);
//     }

//     return 0;
// }

// #include <stdio.h>

// #define SIZE 4

// void transpose(short (*matrix)[SIZE]);
// void print_matrix(short (*matrix)[SIZE]);
// void copy_matrix(short (*copy)[SIZE], short (*matrix)[SIZE]);

// int main(void) {
//     short matrix[SIZE][SIZE] = {0};
//     short* ptr = &matrix[0][0];
//     int count = 0;
//     while (count < SIZE * SIZE && scanf("%hd", ptr) == 1) {
//         ptr++;
//         count++;
//     }

//     transpose(matrix);
//     print_matrix(matrix);

//     return 0;
// }

// void transpose(short (*matrix)[SIZE]) {
//     short copy[SIZE][SIZE];

//     copy_matrix(copy, matrix);

//     for (int i = 0; i < SIZE; i++) {
//         for (int j = 0; j < SIZE; j++) {
//             matrix[j][i] = copy[i][j];
//         }
//     }
// }

// void copy_matrix(short (*copy)[SIZE], short (*matrix)[SIZE]) {
//     short* matrix_ptr = &matrix[0][0];
//     short* copy_ptr = &copy[0][0];
//     int count = 0;
//     while (count < SIZE * SIZE) {
//         *copy_ptr++ = *matrix_ptr++;
//         count++;
//     }
// }

// void print_matrix(short (*matrix)[SIZE]) {
//     for (int i = 0; i < SIZE; i++) {
//         for (int j = 0; j < SIZE; j++) {
//             printf("%d%s", matrix[i][j], j == SIZE - 1 ? "\n" : " ");
//         }
//     }
// }

// #include <stdio.h>

// #define SIZE 3

// void print_matrix(char (*matrix)[SIZE]);

// int main(void) {
//     char pole[SIZE][SIZE] = {0};
//     char* ptr_p = &pole[0][0];
//     int count = 0;
//     while (count < SIZE * SIZE && scanf("%d", ptr_p) == 1) {
//         *ptr_p = (*ptr_p == 1) ? 'x' : (*ptr_p == 2) ? 'o' : *ptr_p;
//         ptr_p++;
//         count++;
//     }

//     print_matrix(pole);

//     return 0;
// }

// void print_matrix(char (*matrix)[SIZE]) {
//     for (int i = 0; i < SIZE; i++) {
//         for (int j = 0; j < SIZE; j++) {
//             printf("%c%s", matrix[i][j], j == SIZE - 1 ? "\n" : " ");
//         }
//     }
// }
// #include <stdio.h>

// #define SIZE 3

// int is_win(int (*matrix)[SIZE]);
// int ch_to_int(char ch);

// int main(void) {
//     int pole[SIZE][SIZE] = {0};
//     int* ptr_p = &pole[0][0];
//     int count = 0;
//     while (count < SIZE * SIZE && scanf("%d", ptr_p) == 1) {
//         *ptr_p = (*ptr_p == 1) ? 'x' : (*ptr_p == 2) ? 'o' : *ptr_p;
//         ptr_p++;
//         count++;
//     }

//     int result = is_win(pole);

//     printf("%d", result);

//     return 0;
// }

// int ch_to_int(char ch) {
//     if (ch == 'x') return 1;
//     if (ch == 'o') return 2;
//     return 0;
// }

// int is_win(int (*matrix)[SIZE]) {
//     // проверим строки
//     for (int i = 0; i < SIZE; i++) {
//         int row_count = 0;
//         int nulls = 1;
//         for (int j = 0; j < SIZE; j++) {
//             if (matrix[i][j] == 0) {
//                 nulls = 0;
//                 break;
//             }
//             row_count += ch_to_int(matrix[i][j]);
//         }
//         if (nulls && row_count == 3) return 1;
//         if (nulls && row_count == 6) return 2;
//     }

//     // проверим столбцы
//     for (int i = 0; i < SIZE; i++) {
//         int cell_count = 0;
//         int nulls = 1;
//         for (int j = 0; j < SIZE; j++) {
//             if (matrix[j][i] == 0) {
//                 nulls = 0;
//                 break;
//             }
//             cell_count += ch_to_int(matrix[j][i]);
//         }
//         if (nulls && cell_count == 3) return 1;
//         if (nulls && cell_count == 6) return 2;
//     }

//     // проверим диагонали
//     int diag1_sum = 0;
//     int diag2_sum = 0;
//     int nulls = 1;
//     for (int i = 0; i < SIZE; i++) {
//         if (matrix[i][i] == 0) {
//             nulls = 0;
//             break;
//         }
//         diag1_sum += ch_to_int(matrix[i][i]);
//         diag2_sum += ch_to_int(matrix[i][SIZE - i - 1]);
//     }
//     if (nulls && diag1_sum == 3) return 1;
//     if (nulls && diag2_sum == 3) return 1;
//     if (nulls && diag1_sum == 6) return 2;
//     if (nulls && diag2_sum == 6) return 2;

//     // проверим нули
//     for (int i = 0; i < SIZE; i++) {
//         for (int j = 0; j < SIZE; j++) {
//             if (matrix[i][j] == 0) {
//                 return 0;
//             }
//         }
//     }
//     return 3;
// }

// #include <stdio.h>

// #define SIZE 10

// void filter(int dst[], size_t size_dst, const int src[], size_t size_src, int (*is_correct)(int)) {
//     for (int i = 0; i < size_dst; ++i) dst[i] = 0;

//     for (int i = 0, j = 0; i < size_src; ++i)
//         if (is_correct(src[i])) dst[j++] = src[i];
// }

// int is_even(int x) { return x % 2 == 0; }

// int main(void) {
//     int digits[] = {-3, 4, 10, 11, -5, 3};
//     int result[SIZE];

//     filter(result, SIZE, digits, sizeof(digits) / sizeof(*digits), is_even);

//     for (int i = 0; i < SIZE; ++i) printf("%d ", result[i]);

//     return 0;
// }

// #include <stdio.h>

// double (*ptr_func)(int, int);

// int main(void) {

//     return 0;
// }

// #include <stdio.h>

// double max_2(double a, double b) { return (a > b) ? a : b; }

// int main(void) {
//     double a, b;
//     scanf("%lf, %lf", &a, &b);

//     double (*ptr_max_2)(double, double);
//     ptr_max_2 = max_2;

//     double result = ptr_max_2(a, b);

//     printf("%.1lf", result);
//     //__ASSERT_TESTS__
//     // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0)
//     return 0;
// }

// #include <stdio.h>
// #include <string.h>

// void copy_string(char* dst, size_t max_len_dst, const char* src, int (*to_copy)(const char)) {
//     size_t counter = 0;
//     int index = 0, shift = 0;
//     char* dst_ptr = dst;
//     while (src[index] != '\0' && counter + shift + 1 < max_len_dst) {
//         if (to_copy(src[index])) {
//             if (((int)src[index]) < 0) shift++;
//             // printf("%c ", src[index]);
//             *dst_ptr++ = src[index];
//             counter++;
//         }

//         index++;
//     }

//     // printf("\n%d %d\n", counter, shift);

//     dst[max_len_dst - shift - 1] = '\0';
// }

// int is_alpha(const char ch) {
//     int res = 1;
//     if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
//         res = 0;
//     }
//     return res;
// }

// int (*to_copy)(const char) = is_alpha;

// int main(void) {
//     char str[100] = {0}, str2[20];
//     fgets(str, sizeof(str) - 1, stdin);
//     char* ptr_n = strrchr(str, '\n');
//     if (ptr_n != NULL) *ptr_n = '\0';

//     copy_string(str2, 20, str, to_copy);

//     printf("%s", str2);

//     return 0;
// }

// #include <stdio.h>
// #define MAX 20

// int sum_ar(const int *ar, size_t len_ar, int (*request)(int)) {
//     int res = 0;
//     for (size_t i = 0; i < len_ar; i++) {
//         if (request(ar[i])) res += ar[i];
//     }
//     return res;
// }

// int is_even(int num) {
//     int res = 1;
//     if (num % 2) res = 0;
//     return res;
// }

// int (*request)(int) = is_even;

// int main(void) {
//     int marks[MAX] = {0};
//     int x;
//     size_t count = 0;
//     while (scanf("%d", &x) == 1 && count < MAX) {
//         marks[count++] = x;
//     }

//     int result = sum_ar(marks, count, request);

//     printf("%d", result);

//     return 0;
// }

// #include <stdio.h>

// int is_odd(int num) {
//     int res = 0;
//     if (num % 2) res = 1;
//     return res;
// }

// int is_positive(int num) {
//     int res = 0;
//     if (num >= 0) res = 1;
//     return res;
// }

// int is_negative(int num) {
//     int res = 1;
//     if (num >= 0) res = 0;
//     return res;
// }

// int deflt(int num) {
//     int res = num * 0 + 1;
//     return res;
// }

// int sum_ar(const int *ar, size_t len_ar, int (*func)(int)) {
//     int res = 0;
//     for (size_t i = 0; i < len_ar; i++) {
//         if (func(ar[i])) res += ar[i];
//     }
//     return res;
// }

// int main(void) {
//     // здесь массив указателей funcs на критериальные функции
//     int marks[20] = {0};

//     int item = 0;
//     scanf("%d", &item);  // выбор критерия суммирования

//     int x;
//     size_t count = 0, len = sizeof(marks) / sizeof(marks[0]);
//     while (scanf("%d", &x) == 1 && count < len) {
//         marks[count++] = x;
//     }

//     int (*funcs[4])(int) = {is_odd, is_positive, is_negative, deflt};

//     int sum = 0;  // переменная для хранения суммы
//     switch (item) {
//         case 1:
//             sum = sum_ar(marks, len, funcs[item - 1]);
//             break;
//         case 2:
//             sum = sum_ar(marks, len, funcs[item - 1]);
//             break;
//         case 3:
//             sum = sum_ar(marks, len, funcs[item - 1]);
//             break;
//         default:
//             sum = sum_ar(marks, len, funcs[item - 1]);
//     }

//     printf("%d", sum);

//     return 0;
// }

// #include <stdio.h>
// #include <string.h>

// int is_digit(const char a) {
//     int res = 0;
//     if (a >= '0' && a <= '9') res = 1;
//     return res;
// }

// int match_ab(const char a, const char b) {
//     int a_is_digit = is_digit(a);
//     int b_is_digit = is_digit(b);

//     if (a_is_digit == b_is_digit) return a < b;
//     if (a_is_digit > b_is_digit)
//         return 1;
//     else
//         return 0;
// }

// void swap(char* a, char* b) {
//     char tmp = *a;
//     *a = *b;
//     *b = tmp;
// }

// void sort_string(char* str, size_t max_len, int (*match_ab)(const char, const char)) {
//     max_len = strlen(str);
//     for (size_t i = 0; i < max_len; i++) {
//         for (size_t j = i; j < max_len; j++) {
//             if (!match_ab(str[i], str[j])) swap(&str[i], &str[j]);
//         }
//     }
// }

// int main(void) {
//     char str[100] = {0};
//     fgets(str, sizeof(str) - 1, stdin);
//     char* ptr_n = strrchr(str, '\n');
//     if (ptr_n != NULL) *ptr_n = '\0';

//     sort_string(str, strlen(str) - 1, match_ab);

//     puts(str);

//     return 0;
// }

// #include <stdio.h>
// #define MAX 4

// void swap(int* a, int* b) {
//     int tmp = *a;
//     *a = *b;
//     *b = tmp;
// }

// int match_ab(const int a, const int b) { return a < b; }

// int sum_big2(int a, int b, int c, int d) {
//     int nums[MAX] = {a, b, c, d};
//     for (size_t i = 0; i < MAX; i++) {
//         for (size_t j = i; j < MAX; j++) {
//             if (match_ab(nums[i], nums[j])) swap(&nums[i], &nums[j]);
//         }
//     }
//     return nums[0] + nums[1];
// }

// int main(void) {
//     int a, b, c, d;
//     scanf("%d %d %d %d", &a, &b, &c, &d);

//     int result = sum_big2(a, b, c, d);

//     printf("%d", result);

//     return 0;
// }

// int max2(int a, int b) { return (a > b) ? a : b; }

// int main(void) {
//     int x = 1, y = 2;
//     int res = max2(x, y);

//     return 0;
// }

// #include <stdio.h>
// #include <stdlib.h>
// #define N 100

// double norm(int a, int b) {
//     double res = 0;
//     size_t count = N;
//     for (size_t i = 0; i < count; i++) {
//         res += a + rand() % (b - a + 1);
//     }
//     return res / N;
// }

// int main(void) {
//     double y = norm(-2, 10);

//     printf("%.2lf", y);
//     //__ASSERT_TESTS__
//     // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0)
//     return 0;
// }

// #include <math.h>
// #include <stdio.h>
// #include <stdlib.h>

// #define N 100

// double norm(int a, int b) {
//     double res = 0;
//     size_t count = N;
//     for (size_t i = 0; i < count; i++) {
//         res += a + rand() % (b - a + 1);
//     }
//     return res / N;
// }

// double reley(double x1, double x2) {
//     double res = sqrt(x1 * x1 + x2 * x2);
//     return res;
// }

// int main(void) {
//     double y = reley(norm(0, 5), norm(0, 5));

//     printf("%.2lf", y);
//     //__ASSERT_TESTS__
//     // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0)
//     return 0;
// }

// #include <stdio.h>
// #define MAX_SIZE 20

// void swap(short* a, short* b) {
//     short tmp = *a;
//     *a = *b;
//     *b = tmp;
// }

// void print_array(short array[], short size) {
//     for (int i = 0; i < size; i++) {
//         printf("%d%s", array[i], i == size - 1 ? "" : " ");
//     }
// }

// void reverse(short* array, short size) {
//     for (int i = 0; i < size / 2; i++) {
//         swap((array + i), (array + size - i - 1));
//     }
// }

// int main(void) {
//     short digs[MAX_SIZE];
//     int count = 0;
//     while (count < MAX_SIZE && scanf("%hd", &digs[count]) == 1) count++;

//     reverse(digs, count);

//     print_array(digs, count);

//     return 0;
// }

// #include <stdio.h>
// #include <string.h>

// // void strip_str(char* str, const char* strip) {
// //     char *ptr = str, shift = 0;
// //     while (*ptr != '\0') {
// //         *(ptr - shift) = *ptr;
// //         if (strchr(strip, *ptr) != NULL) shift++;
// //         ptr++;
// //     }
// //     *(ptr - shift) = '\0';
// //     return;
// // }

// void strip_str(const char* str, const char* find) {
//     char* ptr = strpbrk(str, find);
//     while (ptr) {
//         strcpy(ptr, ptr + 1);
//         ptr = strpbrk(str, find);
//     }

//     return;
// }

// int main(void) {
//     char str[100] = {0}, str2[20] = ".,-!?";
//     fgets(str, sizeof(str) - 1, stdin);
//     char* ptr_n = strrchr(str, '\n');
//     if (ptr_n != NULL) *ptr_n = '\0';

//     const char* str_ptr = str;
//     const char* str2_ptr = str2;

//     strip_str(str_ptr, str2_ptr);

//     puts(str);

//     return 0;
// }

// #include <stdio.h>

// void rcs(int x) {
//     printf("Down: x = %d\n", x);

//     if (x > 1) rcs(x - 1);

//     printf("Up: x = %d\n", x);
// }

// int main(void) {
//     rcs(4);

//     return 0;
// }

// #include <stdio.h>

// #define N 5

// void show_pole(const char (*p)[N]) {
//     for (int i = 0; i < N; ++i) {
//         for (int j = 0; j < N; ++j) printf("%c ", (p[i][j] == 0) ? '#' : '0');
//         putchar('\n');
//     }
// }

// void open_zeros(const char (*p)[N], char (*pp)[N], int i, int j) {
//     if (p[i][j] != 0 || pp[i][j] == 1) return;

//     pp[i][j] = 1;  // открываем клетку

//     if (i - 1 >= 0 && p[i - 1][j] == 0) open_zeros(p, pp, i - 1, j);
//     if (i + 1 < N && p[i + 1][j] == 0) open_zeros(p, pp, i + 1, j);
//     if (j - 1 >= 0 && p[i][j - 1] == 0) open_zeros(p, pp, i, j - 1);
//     if (j + 1 < N && p[i][j + 1] == 0) open_zeros(p, pp, i, j + 1);
// }

// int main(void) {
//     char pole[N][N] = {
//         {1, 1, 1, 1, 1}, {1, 1, 0, 1, 1}, {0, 0, 0, 0, 1}, {1, 1, 0, 0, 0}, {1, 1, 0, 1, 1},
//     };

//     char ppole[N][N] = {0};

//     show_pole(ppole);
//     open_zeros(pole, ppole, 2, 2);

//     puts("--------------------");
//     show_pole(ppole);

//     return 0;
// }

// #include <stdio.h>
// #define MAX_RECURSION 4

// void recursive(int num) {
//     if (num > MAX_RECURSION) return;

//     recursive(num + 1);

//     printf("%d ", num);
//     return;
// }

// int main(void) {
//     recursive(1);

//     return 0;
// }

// #include <stdio.h>
// #define MAX_LENGTH 20

// size_t range_to_ar(int* ptr_a, size_t max_len, int from, int to, size_t count) {
//     if (from > to || count >= max_len)
//         return (size_t)(to - from + 1) > (size_t)max_len ? max_len : (size_t)(to - from + 1);

//     ptr_a[count] = from;
//     // printf("UP:%d %d\n", from, count);

//     range_to_ar(ptr_a, max_len, from + 1, to, count + 1);

//     // printf("DOWN:%d %d\n", from, count);

//     return (size_t)(to - from + 1) > (size_t)max_len ? max_len : (size_t)(to - from + 1);
// }

// size_t range_to_ar(int* ptr_a, size_t max_len, int from, int to, size_t count) {
//     if (from > to || count == max_len) {
//         return count;
//     }

//     *(ptr_a + count) = from;
//     return range_to_ar(ptr_a, max_len, ++from, to, ++count);
// }

// int main(void) {
//     int max_rec;
//     int ar[MAX_LENGTH];
//     scanf("%d", &max_rec);

//     size_t cnt = range_to_ar(ar, MAX_LENGTH, 1, max_rec, 0);

//     // printf("%d\n", cnt);

//     for (size_t i = 0; i < cnt; i++) {
//         printf("%d ", ar[i]);
//     }

//     return 0;
// }

// #include <stdio.h>
// #define MAX_LENGTH 20

// int sum_ar(const short* ar, size_t len, size_t indx) {
//     if (indx == len) return 0;
//     // printf("%d ", ar[indx]);
//     return ar[indx] + sum_ar(ar, len, indx + 1);
// }

// int main(void) {
//     short ar[MAX_LENGTH];
//     int count = 0;
//     while (count < MAX_LENGTH && scanf("%hd", &ar[count]) != EOF) count++;
//     // printf("%d ", count);
//     int sum = sum_ar(ar, count, 0);

//     printf("%d ", sum);

//     return 0;
// }

// #include <stdio.h>
// #define MAX_LENGTH 20

// size_t to_flat(short* v,         /* массив, в который заносятся значения */
//                size_t max_len_v, /* максимальная длина массива v */
//                short* table[], /* массив на массив, из которого читаются значения */
//                size_t len,     /* длина массива table (первая размерность) */
//                size_t count_v, /* число записанных в массив v значений (начальное значение 0) */
//                size_t indx_t, /* индекс для перебора указателей (первой размерности) массива table
//                (начальное
//                                  значение 0) */
//                size_t indx) /* индекс для перебора элементов массивов (условно, вторая размерность),
//                                на которые ссылается текущий указатель table[indx_t] (начальное значение
//                                0)*/
// {
//     // for (indx_t = 0; indx_t < len; indx_t++) {
//     //     for (indx = 0; table[indx_t][indx] != 0; indx++) {
//     //         v[count_v] = table[indx_t][indx];
//     //         // printf("%d = %d ", count_v, v[count_v]);
//     //         if (++count_v == max_len_v) return count_v;
//     //     }
//     // }

//     // return count_v;

//     if (indx_t < len && count_v < max_len_v) {
//         if (table[indx_t][indx]) {
//             v[count_v++] = table[indx_t][indx++];
//         } else {
//             indx_t++;
//             indx = 0;
//         }
//     } else {
//         return count_v;
//     }

//     return to_flat(v, max_len_v, table, len, count_v, indx_t, indx);
// }

// int main(void) {
//     short ar_1[] = {-4, 2, 3, 7, 0};
//     short ar_2[] = {11, 6, 10, 8, 13, 98, -5, 0};
//     short ar_3[] = {-47, 0};
//     short ar_4[] = {8, 11, 56, -3, -2, 0};

//     short* table[] = {ar_1, ar_4, ar_3, ar_2};

//     short flat[MAX_LENGTH];
//     size_t cnt = to_flat(flat, MAX_LENGTH, table, sizeof(table) / sizeof(*table), 0, 0, 0);

//     // printf("\n%d\n", (int)cnt);

//     for (size_t i = 0; i < cnt; i++) {
//         printf("%d ", flat[i]);
//     }
//     return 0;
// }

// #include <ctype.h>
// #include <stdio.h>
// #include <string.h>

// char* char_to_morse(char ch) {
//     char symbols[] = "AJS2BKT3CLU4DMV5ENW6FOX7GPY8HQZ9IR10 ";
//     size_t len = strlen(symbols);
//     char* morse[] = {".-",   ".---",  "...",  "..---", "-...",  "-.-",   "-",    "...--", "-.-.", ".-..",
//                      "..-",  "....-", "-..",  "--",    "...-",  ".....", ".",    "-.",    ".--",  "-....",
//                      "..-.", "---",   "-..-", "--...", "--.",   ".--.",  "-.--", "---..", "....", "--.-",
//                      "--..", "----.", "..",   ".-.",   ".----", "-----", "-...-"};
//     for (size_t i = 0; i < len; i++) {
//         if (symbols[i] == toupper(ch)) return morse[i];
//     }
//     return " ";
// }

// void str_to_morse(char* str) {
//     for (size_t i = 0; str[i] != '\0'; i++) {
//         printf("%s%s", char_to_morse(str[i]), str[i + 1] == '\0' ? "" : " ");
//     }
// }

// int main(void) {
//     char str[100] = {0};
//     fgets(str, sizeof(str) - 1, stdin);
//     char* ptr_n = strrchr(str, '\n');
//     if (ptr_n != NULL) *ptr_n = '\0';

//     str_to_morse(str);

//     return 0;
// }

// #include <stdio.h>
// #include <string.h>

// char morse_to_char(const char* str) {
//     const char symbols[] = "AJS2BKT3CLU4DMV5ENW6FOX7GPY8HQZ9IR10 ";
//     size_t len = strlen(symbols);
//     const char* morse[] = {".-",   ".---", "...",   "..---", "-...", "-.-",  "-",    "...--",
//                            "-.-.", ".-..", "..-",   "....-", "-..",  "--",   "...-", ".....",
//                            ".",    "-.",   ".--",   "-....", "..-.", "---",  "-..-", "--...",
//                            "--.",  ".--.", "-.--",  "---..", "....", "--.-", "--..", "----.",
//                            "..",   ".-.",  ".----", "-----", "-...-"};
//     for (size_t i = 0; i < len; i++) {
//         if (strcmp(morse[i], str) == 0) return symbols[i];
//     }
//     return ' ';
// }

// void morse_to_str(const char* str, size_t len) {
//     char s[6] = {0};
//     int count = 0;
//     for (size_t i = 0; i <= len; i++) {
//         if (str[i] == ' ' || str[i] == '\0') {
//             s[count] = '\0';
//             printf("%c", morse_to_char(s));
//             // printf("%s", s);
//             count = 0;
//             continue;
//         }
//         s[count++] = str[i];
//     }
// }

// int main(void) {
//     char str[100] = {0};
//     fgets(str, sizeof(str) - 1, stdin);
//     char* ptr_n = strrchr(str, '\n');
//     if (ptr_n != NULL) *ptr_n = '\0';
//     size_t len = strlen(str);
//     morse_to_str(str, len);

//     return 0;
// }

// #include <stdarg.h>
// #include <stdio.h>

// int sum(int count, ...) {
//     int s = 0;
//     va_list arg;  // указатель на параметр
//     va_start(arg, count);  // получение адреса первого вариадического параметра

//     for (int i = 0; i < count; ++i) {
//         s += va_arg(arg, int);  // получение значение вариадического параметра
//                                 // и переход к следующему параметру
//     }

//     va_end(arg);  // завершение процедуры перебора вариадических параметров

//     return s;
// }

// int main(void) {
//     int res = sum(5, 1, 2, 3, 4, 5);
//     printf("res = %d\n", res);

//     return 0;
// }

// #include <stdarg.h>
// #include <stdio.h>

// double mean(int total, ...) {
//     int res = 0;
//     va_list arg;  // указатель на параметр
//     va_start(arg, total);  // получение адреса первого вариадического параметра

//     for (int i = 0; i < total; i++) {
//         res += va_arg(arg, int);  // получение значение вариадического параметра
//                                   // и переход к следующему параметру
//     }

//     va_end(arg);  // завершение процедуры перебора вариадических параметров

//     return res / (double)total;
// }

// int main(void) {
//     double res = mean(7, 5, -10, 11, 0, 12, 4, 2);
//     printf("%.2lf", res);

//     return 0;
// }
// #include <stdarg.h>
// #include <stdio.h>
// #include <string.h>

// double v_norm2(char* format, ...) {
//     double res = 0;
//     va_list arg;
//     va_start(arg, format);
//     int total;
//     if (strcmp(format, "vector2") == 0)
//         total = 2;
//     else if (strcmp(format, "vector3") == 0)
//         total = 3;
//     else if (strcmp(format, "vector4") == 0)
//         total = 4;
//     else {
//         va_end(arg);
//         return 0.0;
//     }
//     for (int i = 0; i < total; i++) {
//         double coord = va_arg(arg, double);
//         res += coord * coord;
//     }

//     va_end(arg);

//     return res;
// }

// int main(void) {
//     double res = v_norm2("vector2", 1.0, 2.0);
//     printf("%.1lf", res);

//     return 0;
// }

// #include <stdarg.h>
// #include <stdio.h>
// #include <string.h>

// double sumf(const char* format, ...) {
//     double res = 0;
//     va_list arg;
//     va_start(arg, format);
//     int total = strlen(format);
//     for (int i = 0; i < total; i++) {
//         double num = va_arg(arg, double);
//         if (format[i] == '+') {
//             res += num;
//         }
//     }
//     return res;
// }

// int main(void) {
//     double res = sumf("++ + +", 1.0, 2.0, 3.0, 4.0, 5.0, 6.0);
//     printf("%.2f ", res);

//     return 0;
// }

#include <stdarg.h>
#include <stdio.h>
#define MAX 100
#define COUNT 5

void ar_fill(double* ar, size_t len, ...) {
    double res = 0;
    va_list* ar;
    va_list arg;
    va_start(arg, len);
    for (int i = 0; i < len; i++) {
        ar[i] = va_arg(arg, double);
    }
    va_end(arg);
    return;
}

int main(void) {
    double array[MAX] = {0}, *ptr = array;
    size_t count = COUNT;
    ar_fill("++ + +", 1.0, 2.0, 3.0, 4.0, 5.0, 6.0);
    for (int i = 0; i < COUNT; i++) {
        printf("%lf", ar[i]);
    }

    return 0;
}
