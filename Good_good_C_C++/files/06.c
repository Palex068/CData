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
#include <stdio.h>

#define SIZE 3

int is_win(int (*matrix)[SIZE]);
int ch_to_int(char ch);

int main(void) {
    int pole[SIZE][SIZE] = {0};
    int* ptr_p = &pole[0][0];
    int count = 0;
    while (count < SIZE * SIZE && scanf("%d", ptr_p) == 1) {
        *ptr_p = (*ptr_p == 1) ? 'x' : (*ptr_p == 2) ? 'o' : *ptr_p;
        ptr_p++;
        count++;
    }

    int result = is_win(pole);

    printf("%d", result);

    return 0;
}

int ch_to_int(char ch) {
    if (ch == 'x') return 1;
    if (ch == 'o') return 2;
    return 0;
}

int is_win(int (*matrix)[SIZE]) {
    // проверим строки
    for (int i = 0; i < SIZE; i++) {
        int row_count = 0;
        int nulls = 1;
        for (int j = 0; j < SIZE; j++) {
            if (matrix[i][j] == 0) {
                nulls = 0;
                break;
            }
            row_count += ch_to_int(matrix[i][j]);
        }
        if (nulls && row_count == 3) return 1;
        if (nulls && row_count == 6) return 2;
    }

    // проверим столбцы
    for (int i = 0; i < SIZE; i++) {
        int cell_count = 0;
        int nulls = 1;
        for (int j = 0; j < SIZE; j++) {
            if (matrix[j][i] == 0) {
                nulls = 0;
                break;
            }
            cell_count += ch_to_int(matrix[j][i]);
        }
        if (nulls && cell_count == 3) return 1;
        if (nulls && cell_count == 6) return 2;
    }

    // проверим диагонали
    int diag1_sum = 0;
    int diag2_sum = 0;
    int nulls = 1;
    for (int i = 0; i < SIZE; i++) {
        if (matrix[i][i] == 0) {
            nulls = 0;
            break;
        }
        diag1_sum += ch_to_int(matrix[i][i]);
        diag2_sum += ch_to_int(matrix[i][SIZE - i - 1]);
    }
    if (nulls && diag1_sum == 3) return 1;
    if (nulls && diag2_sum == 3) return 1;
    if (nulls && diag1_sum == 6) return 2;
    if (nulls && diag2_sum == 6) return 2;

    // проверим нули
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (matrix[i][j] == 0) {
                return 0;
            }
        }
    }
    return 3;
}