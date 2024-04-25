// #include <stdio.h>
// /* Внешний блок кода */
// char name[] = "Variables";

// int main(void) {
//     int var_main; /* внутренняя переменная */
//     return 0;
// }

// int main(void) {
//     int var_main; /* внутренняя переменная */
//     double big_ar[100000];

//     return 0;
// }

// #include <stdio.h>
// /* Внешний блок кода */
// char name[] = "Variables";
// double big_ar[1000000];

// int main(void) {
//     int var_main; /* внутренняя переменная */
//     return 0;
// }

// #include <stdio.h>
// /* Внешний блок кода */
// char name[] = "Variables";
// int global_var_1 = 5;
// int global_var_2 = 5 * 7;
// int global_var_3 = sizeof(name) + 1;

// int main(void) {
//     int var_main; /* внутренняя переменная */
//     return 0;
// }

// #include <stdio.h>
// char name[] = "Variables";
// int global_var_1 = 5;
// int global_var_2 = 5 * 7;
// int global_var_3 = sizeof(name) + 1;

// int main(void) {
//     int a = 1;
//     int b = a * 2 + global_var_2;
//     int size = global_var_3 * 10;

//     return 0;
// }

// #include <stdio.h>

// int is_positive(int num) {
//     int res = num >= 0;
//     return res;
// }

// int main(void) {
//     int x;
//     while (scanf("%d", &x) == 1) {
//         if (is_positive(x)) printf("%d ", x);
//     }

//     return 0;
// }

// #include <stdio.h>
// #define RANGE_DOWN 1
// #define RANGE_UP 5
// #define MAX_LEN 20

// double mean_ar(const int *ar, size_t len_ar, int (*in_range)(int)) {
//     double res = 0;
//     int count = 0;
//     for (size_t i = 0; i < len_ar; i++) {
//         if (in_range(ar[i])) {
//             res += ar[i];
//             count++;
//         }
//     }
//     return res / count;
// }

// int in_range(int num) {
//     int res = (num >= RANGE_DOWN) * (num <= RANGE_UP);
//     return res;
// }

// int main(void) {
//     int marks[MAX_LEN] = {0};
//     int x, count = 0;
//     while (scanf("%d", &x) == 1 && count < MAX_LEN) {
//         marks[count++] = x;
//     }
//     double result = mean_ar(marks, count, in_range);

//     printf("%.1lf", result);

//     return 0;
// }

// #include <stdio.h>

// int main(void) {
//     int a = 1;

//     {
//         int b = 2;
//         printf("a = %d, b = %d\n", a, b);
//     }

//     printf("a = %d\n", a);

//     return 0;
// }

// #include <stdio.h>

// int main(void) {
//     int a = 1, b = 3;

//     if (a < b) {
//         int t = a;
//         a = b;
//         b = t;
//     }

//     printf("a = %d, b = %d\n", a, b);

//     return 0;
// }

// #include <stdio.h>

// int main(void) {
//     int a = 1, b = 3;
//     int t = a + b;

//     if (a < b) {
//         int t = a;
//         a = b;
//         b = t;
//     }

//     printf("a = %d, b = %d, t = %d\n", a, b, t);

//     return 0;
// }

// #include <stdio.h>

// int main(void) {
//     int t = 3;

//     while (t-- > 0) {
//         int t = 10;
//         t--;
//         printf("t = %d\n", t);
//     }

//     printf("main: t = %d\n", t);

//     return 0;
// }

// #include <stdio.h>

// int main(void) {
//     int t = 33;

//     for (int t = 0; t < 3; ++t) {
//         printf("t = %d\n", t);
//     }

//     printf("main: t = %d\n", t);

//     return 0;
// }

// #include <stdio.h>

// int main(void) {
//     int p = 1;
//     int n = 7;

//     for (register int i = 2; i <= n; ++i) p *= i;

//     return 0;
// }

// #include <stdio.h>

// int var = 0;

// int main(void) {
//     int var = 10;

//     {
//         int var = 20;
//         printf("%d\n", var);
//     }

//     printf("%d\n", var);

//     return 0;
// }

// #include <stdio.h>

// int main(void) {
//     int n = 10;
//     for (int i = 0; i < n; ++i) printf("%d ", i + 1);

//     printf("\n%d\n", i);

//     return 0;
// }

// #include <stdio.h>

// int main(void) {
//     int n = 7;
//     while (n-- > 0) {
//         int n = 5;
//         printf("%d\n", n);
//         n++;
//     }

//     printf("%d\n", n);

//     return 0;
// }

// #include <stdio.h>

// int main(void) {
//     int n;

//     scanf("%d", &n);
//     // Выведем 1, на единицу всё делиться без остатка
//     printf("%d ", 1);

//     // Достаточно проверять до половины n
//     for (int i = 2; i <= n / 2; i++) {
//         if (n % i == 0) printf("%d ", i);
//     }
//     // если n = 1, то не будем печатать её второй раз
//     if (n > 1) printf("%d", n);

//     return 0;
// }

// #include <stdio.h>

// int main(void) {
//     int n;

//     scanf("%d", &n);

//     for (int i = 2; i <= n; i++) {
//         while (n % i == 0) {
//             printf("%d ", i);
//             n /= i;
//         }
//     }

//     return 0;
// }

// #include <stdio.h>
// #define MAX 20

// int main(void) {
//     int n, m, result = 0;

//     scanf("%d %d", &n, &m);

//     for (int i = 0; i <= n; i++) {
//         for (int j = 0; j <= m; j++) {
//             int sum = i + j;
//             if (sum == MAX) goto A;
//             result += sum;
//         }
//     }

// A:
//     printf("%d", result);
//     return 0;
// }

// #include <stdio.h>

// int get_step(int start) {
//     static int step = start;
//     return step++;
// }

// int main(void) {
//     printf("step: %d\n", get_step(5));
//     printf("step: %d\n", get_step(5));
//     printf("step: %d\n", get_step(5));

//     return 0;
// }

// #include <stdio.h>
// #define START_STEP 2
// #define FUNC_RUNS 7

// // int range(void) {
// //     static int step = START_STEP;
// //     step += 3;
// //     return step;
// // }

// int range(void) {
//     static int i;
//     return 5 + 3 * i++;
// }

// int main(void) {
//     for (size_t i = 0; i < FUNC_RUNS; i++) {
//         printf("%d ", range());
//     }

//     return 0;
// }

// #include <stdio.h>

// int range(int start, int stop, int step) {
//     static int i = 0;
//     if ((start + step * i) > stop) i = 0;
//     if ((start + step * i) == stop) {
//         i++;
//         return stop;
//     }
//     int res = (start + step * i++) % (stop - start);
//     return res;
// }

// int main(void) {
//     int start, stop, step;
//     scanf("%d %d %d", &start, &stop, &step);

//     for (int i = 0; i < 20; ++i) printf("%d ", range(start, stop, step));

//     return 0;
// }

// #include <stdio.h>

// extern int ex_var_1;
// extern int ex_var_2;

// int main(void) {
//     printf("%d ", ex_var_1);
//     printf("%d", ex_var_2);
//     return 0;
// }

// int ex_var_1 = 10;
// int ex_var_2 = 7;

// #include <stdio.h>
// #include <stdlib.h>

// int main(void) {
//     int* ptr = malloc(4);
//     char* ptr_str;
//     free(ptr_str);
// }

// #include <stdio.h>
// #include <stdlib.h>
// #define DATA_LEN 4

// int main(void) {
//     short* data = malloc(sizeof(short) * DATA_LEN);
//     const short ins[] = {-4, 3, 0, 100};

//     if (data != NULL) {
//         for (size_t i = 0; i < DATA_LEN; i++) {
//             data[i] = ins[i];
//         }
//     }

//     // __ASSERT_TESTS__
//     // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0)

//     if (data != NULL) free(data);
//     return 0;
// }

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #define DATA_LEN 20

// int main(void) {
//     double digits[DATA_LEN];
//     size_t count = 0;

//     while (scanf("%lf", &digits[count]) == 1 && count < DATA_LEN) count++;
//     printf("%d\n", count);
//     for (size_t i = 0; i < count; i++) {
//         printf("%.2lf ", digits[i]);
//     }
//     printf("\n");

//     double* ptr_d = malloc(sizeof(double) * count);

//     if (ptr_d != NULL) memcpy(ptr_d, digits, sizeof(double) * count);

//     // __ASSERT_TESTS__
//     // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0)

//     if (ptr_d != NULL) free(ptr_d);
//     return 0;
// }

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #define DATA_LEN 20

// int main(void) {
//     int lengths[DATA_LEN];
//     size_t count = 0;

//     while (scanf("%d", &lengths[count]) == 1 && count < DATA_LEN) count++;
//     // printf("%d\n", count);
//     // for (size_t i = 0; i < count; i++) {
//     //     printf("%d ", lengths[i]);
//     // }
//     // printf("\n");

//     int* ptr_lens = calloc(DATA_LEN, sizeof(int));

//     if (ptr_lens != NULL) {
//         // for (size_t i = 0; i < DATA_LEN; i++) {
//         //     printf("%d ", ptr_lens[i]);
//         // }
//         // printf("\n");
//         memcpy(ptr_lens, lengths, sizeof(int) * count);
//         for (size_t i = 0; i < DATA_LEN; i++) {
//             printf("%d ", ptr_lens[i]);
//         }
//     }
//     // __ASSERT_TESTS__
//     // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0)

//     if (ptr_lens != NULL) free(ptr_lens);
//     return 0;
// }

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// #define TOTAL 10
// #define FILL -1

// void* expand_array(const short* ptr, size_t* len, short fill) {
//     size_t new_len = *len * 2;
//     short* ar = malloc(sizeof(short) * new_len);
//     if (ar != NULL) {
//         memcpy(ar, ptr, sizeof(short) * *len);
//         for (size_t i = *len; i < new_len; i++) {
//             ar[i] = fill;
//         }
//         *len = new_len;
//     }
//     return ar;
// }

// int main(void) {
//     short* ptr_d = calloc(TOTAL, sizeof(short));
//     size_t len = TOTAL;
//     if (ptr_d == NULL) return 0;

//     int count = 0;
//     while (count < TOTAL && scanf("%hd", &ptr_d[count]) == 1) count++;

//     ptr_d = expand_array(ptr_d, &len, FILL);

//     if (ptr_d != NULL) {
//         for (size_t i = 0; i < len; i++) {
//             printf("%d ", ptr_d[i]);
//         }
//         free(ptr_d);
//     }

//     return 0;
// }

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// void getline1(char* buffer, size_t max_len) {
//     fgets(buffer, max_len - 1, stdin);
//     char* ptr_n = strrchr(buffer, '\n');
//     if (ptr_n != NULL) *ptr_n = '\0';
// }

// char* merge_string(const char* str1, const char* str2) {
//     size_t len_1 = strlen(str1);
//     size_t len_2 = strlen(str2);

//     char* res = malloc(sizeof(char) + (len_1 + len_2));
//     if (res != NULL) {
//         res = memcpy(res, str1, sizeof(char) * len_1);
//         res[len_1] = '\0';
//         res = strcat(res, str2);
//     }
//     return res;
// }

// int main(void) {
//     char str_1[200] = {0};
//     char str_2[200] = {0};

//     getline1(str_1, sizeof(str_1));
//     getline1(str_2, sizeof(str_2));

//     char* str = merge_string(str_1, str_2);

//     puts(str);
//     free(str);
//     return 0;
// }

// #include <stdio.h>

// enum menu_item { item_exit = 1, item_c = 2, item_python = 3, item_java = 4 };

// int main(void) {
//     enum menu_item menu;
//     int num;
//     scanf("%d", &num);

//     menu = num;

//     switch (menu) {
//         case item_exit:
//             puts("Выход");
//             break;
//         case item_c:
//             puts("Язык Си");
//             break;
//         case item_python:
//             puts("Язык Python");
//             break;
//         case item_java:
//             puts("Язык Java");
//             break;
//         default:
//             puts("Не верный пункт меню");
//     }

//     return 0;
// }
#include <stdio.h>

typedef enum calc_types { _perimetr = 1, _square = 2 } types;

double calc_rect(double width, double height, types form) {
    double res = 0;
    switch (form) {
        case _perimetr:
            res = (width + height) * 2;
            break;
        case _square:
            res = width * height;
            break;
        default:
            puts("Wrong type");
    }
    return res;
}

int main(void) {
    types oper;
    int num;
    double w, h;
    scanf("%d %lf %lf", &num, &w, &h);

    oper = num;

    double result = calc_rect(w, h, oper);

    printf("%.1lf", result);

    return 0;
}