// #include <stdio.h>

// #define SIZE_BUFFER 1024

// int main(void) {
//     // Корректные объявления
//     double f[30];
//     char buffer[SIZE_BUFFER];
//     int marks[13];
//     short ar[8 * 5];
//     char bytes[sizeof(double)];

//     // Некорректные объявления
//     int n = 5;

//     float func[21.5];  // вещественное количество элементов
//     int array[n];      // нельзя было до стандарта C99
//     int null_ar[0];    // размер должен быть больше нуля

//     return 0;
// }

// #include <stdio.h>
// #define TOTAL_MARKS 13

// int main(void) {
//     int marks[TOTAL_MARKS];
//     return 0;
// }

// #include <stdio.h>

// #define TOTAL_MARKS 13

// int main(void) {
//     int marks[TOTAL_MARKS];
//     marks[2] = 4;
//     marks[0] = 2;
//     marks[12] = 5;
//     //       marks[13] = 1;               // никогда так не делайте!!!

//     for (int i = 0; i < TOTAL_MARKS; ++i) printf("%d ", marks[i]);

//     return 0;
// }

// #define TOTAL 1024

// int main(void) {
//     int total = 100;

//     unsigned short ar_1[100];
//     // long long ar_6[0.5 * 2];
//     signed char ar_4[total];  // (поддерживается не всеми компиляторами)
//     // long ar_5[0];
//     short int ar_8[(int)(0.5 * 3)];
//     long double ar_7[TOTAL / 2];
//     double ar_2[5 * 3 - 2];
//     float ar_3[sizeof(total) * 5];

//     return 0;
// }

// #include <stdio.h>
// #define BUFFER 1024

// int main(void) {
//     short buffer[BUFFER];
//     buffer[0] = 13;

//     return 0;
// }

// #include <stdio.h>
// #define MAX 28

// int main(void) {
//     double func[MAX], x;

//     scanf("%lf", x);

//     func[6] = x;

//     return 0;
// }

// #include <stdio.h>
// #define MAX 5

// int main(void) {
//     int digits[MAX];

//     for (int i = 0; i < MAX; i++) {
//         scanf("%d", &digits[i]);
//     }
//     for (int i = 0; i < MAX; i++) {
//         printf("%d ", digits[i]);
//     }
//     return 0;
// }

// #include <stdio.h>
// #define TOTAL 5

// int main(void) {
//     int ar_1[TOTAL];
//     int ar_2[TOTAL * 2];

//     for (int i = 0; i < TOTAL; i++) {
//         scanf("%d", &ar_1[i]);
//         ar_2[i] = ar_1[i];
//     }
//     for (int i = TOTAL; i < TOTAL * 2; i++) {
//         ar_2[i] = -1;
//     }

//     return 0;
// }

// #include <stdio.h>

// #define TOTAL_MARKS 13

// int main(void) {
//     int marks[TOTAL_MARKS];

//     marks[2] = 4;
//     marks[0] = 2 * 3;
//     marks[12] = 7 - 2;
//     //       marks[13] = 1;

//     for (int i = 0; i < TOTAL_MARKS; ++i) printf("%d ", marks[i]);

//     return 0;
// }

// #include <stdio.h>

// #define TOTAL_MARKS 13

// int month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

// int main(void) {
//     int marks[TOTAL_MARKS] = {1, 2, 3, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0};

//     for (int i = 0; i < TOTAL_MARKS; ++i) printf("%d ", marks[i]);

//     return 0;
// }

// #include <stdio.h>
// #include <stdlib.h>

// #define TOTAL_MARKS 13

// int month[] = {31, 28, 31 * 2, 30, 31, 30, 31, 31, 30, 31, 30, 31};

// int main(void) {
//     int val = -5;
//     int marks[TOTAL_MARKS] = {1, 2, 3, 4, val, abs(val), 0, 0, 0, 0, 0, 0,
//     0};

//     for (int i = 0; i < TOTAL_MARKS; ++i) printf("%d ", marks[i]);

//     return 0;
// }

// #include <stdio.h>
// #include <stdlib.h>

// #define TOTAL_MARKS 13

// int month[] = {31, 28, 31 * 2, 30, 31, 30, 31, 31, 30, 31, 30, 31};

// int main(void) {
//     int marks[TOTAL_MARKS];

//     printf("%u", sizeof *marks);

//     return 0;
// }

// #include <stdio.h>

// int main(void) {
//     int marks[5] = {0};
//     int a, b;

//     a = sizeof marks;
//     b = a / sizeof(*marks);

//     printf("%d %d", b, a);

//     return 0;
// }
// #include <stdio.h>

// int main(void) {
//     float pows[5] = {1, 2, 3, 4, 5};

//     int len = sizeof pows / sizeof(*pows);

//     for (int i = len - 1; i >= 0; i--) {
//         printf("%.1f ", pows[i]);
//     }

//     return 0;
// }

// #include <stdio.h>

// int main(void) {
//     long digits[128] = {[16] = 4, [32] = 5, [64] = 6};

//     return 0;
// }

// #include <stdio.h>

// int main(void) {
//     short ar_rnd[64] = {0};

//     for (size_t i = 0; i < 5; i++) {
//         scanf("%hd", &ar_rnd[i]);
//     }

//     return 0;
// }
// #include <stdio.h>

// int main(void) {
//     short marks[5] = {1, 2, 3, 4, 7};
//     double res = 0;

//     int len = sizeof marks / sizeof(*marks);

//     for (int i = 0; i < len; i++) {
//         res += marks[i];
//     }
//     res /= len;

//     printf("%.2lf", res);

//     return 0;
// }

// #include <stdio.h>

// int main(void) {
//     short ar[] = {4, 3, 2, 1, 5, 6, 7};
//     short *ptr_ar;

//     return 0;
// }
// #include <stdio.h>

// int main(void) {
//     char buff_1[] = {4, 3, 2, 1, 5, 6, 7};
//     char buff_2[] = {4, 3, 2, 1, 5, 6, 7};
//     char buffer[128];

//     char *ptr_ar;

//     ptr_ar = buffer;

//     int len_1 = sizeof(buff_1) / sizeof(*buff_1);
//     int len_2 = sizeof(buff_2) / sizeof(*buff_2);

//     for (int i = 0; i < len_1; i++) {
//         *(ptr_ar++) = *(buff_1 + i);
//     }
//     for (int i = 0; i < len_2; i++) {
//         *(ptr_ar++) = *(buff_2 + i);
//     }

//     return 0;
// }

// #include <stdio.h>

// int main(void) {
//     int value;

//     scanf("%d", &value);

//     int len = sizeof(int) / sizeof(char);

//     char ar_d[len];

//     char* bite = (char*)&value;

//     for (int i = 0; i < len; i++) {
//         ar_d[i] = *(bite + i);
//         printf("%d ", ar_d[i]);
//     }

//     return 0;
// }

// #include <stdio.h>
// #define MAX 10

// int main(void) {
//     int value, counter = MAX, res = 1;

//     while (scanf("%d", &value) == 1 && counter--) {
//         res *= (value > 0) * (value % 2);
//     }
//     printf("%d", res);

//     return 0;
// }

// #include <stdio.h>

// int main(void) {
//     double value, res = 0;
//     int counter = 0;
//     while (scanf("%lf", &value) == 1) {
//         res += value;
//         counter++;
//     }
//     res /= counter;

//     printf("%.2lf", res);

//     return 0;
// }

// #include <stdio.h>

// void bite_print(void* arg, int len) {
//     const unsigned char* ptr = (unsigned char*)arg;
//     for (int i = 0; i < len; i++) {
//         printf("%d ", *(ptr + i));
//     }
// }

// int main(void) {
//     short var_1;
//     int var_2;
//     long var_3;

//     scanf("%hd, %d, %ld", &var_1, &var_2, &var_3);

//     bite_print((void*)&var_1, sizeof(var_1));
//     bite_print((void*)&var_2, sizeof(var_2));
//     bite_print((void*)&var_3, sizeof(var_3));
//     return 0;
// }

// #include <stdio.h>

// int main(void) {
//     short ar[] = {4, 3, 2, 1, 5, 6, 7};
//     const short* ptr_1 = ar;
//     short* ptr_2 = ar;

//     return 0;
// }

// #include <stdio.h>

// const int marks[] = {1, 2, 3, 4, 5};

// int main(void) {
//     // программа, использующая массива marks
//     return 0;
// }

// #include <stdio.h>

// int main(void) {
//     const int code = 13;

//     return 0;
// }

// #include <stdio.h>

// int main(void) {
//     const int code = 13;
//     int item = 1;

//     switch (item) {
//         case code:
//             printf("error");
//     }

//     return 0;
// }
// #include <stdio.h>

// int main(void) {
//     int* ptr;
//     const int* ptr_cnst;
//     int* const cnst_ptr;

//     // *ptr_cnst = 10;
//     --ptr_cnst;
//     ptr_cnst = ptr;  //
//     // ptr = ptr_cnst;
//     ptr = cnst_ptr;
//     // cnst_ptr = ptr;
//     // cnst_ptr++;
//     *cnst_ptr = 77;

//     return 0;
// }
// #include <stdio.h>

// int main(void) {
//     const int var;
//     const int a = 5;
//     int b = a;
//     long const lg = 10;
//     const short sh = 100;
//     // char const cnst_ch;
//     // cnst_ch = 12;
//     // const char ch_cnst;
//     // ch_cnst = 12;

//     return 0;
// }

// #include <stdio.h>

// int main(void) {
//     const int total = 5;
//     int marks[100];

//     for (int i = 0; i < total; i++) {
//         scanf("%d", marks + i);
//     }
//     for (int i = total - 1; i >= 0; i--) {
//         printf("%d ", *(marks + i));
//     }

//     return 0;
// }

// #include <stdio.h>

// int main(void) {
//     int ar[100], count = 0, value;
//     int* const ptr_ar = ar;

//     while (scanf("%d", &value) == 1 && value != 78) {
//         ptr_ar[count] = value;
//         printf("%d ", ptr_ar[count++]);
//     }

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

// #define CELL_N(N) cell_##N

// int main(void) {
//     short cell_1 = 1;
//     // int n = 2;

//     int res_1 = CELL_N(1) + 10;
//     // int res_2 = CELL_N(n) * 2;
//     int res_3 = CELL_N(1 + 2) * 3;

//     printf("%d %d", res_1, res_3);

//     return 0;
// }

// #include <stdio.h>

// int main(void) {
//     float func_1[100] = {2.4, -3.8, 0, 10.2, 11.78, -5.43};
//     float func_2[50];

//     return 0;
// }

// #include <stdio.h>

// int main(void) {
//     float func_1[100] = {2.4, -3.8, 0, 10.2, 11.78, -5.43};
//     float func_2[50];

//     int size_1 = sizeof(func_1) / sizeof(func_1[0]);
//     int size_2 = sizeof(func_2) / sizeof(func_2[0]);
//     int size = (size_1 < size_2) ? size_1 : size_2;

//     for (int i = 0; i < size; ++i) func_2[i] = func_1[i];

//     return 0;
// }

// #include <stdio.h>

// #define TOTAL_MARKS 10

// int main(void) {
//     char marks[TOTAL_MARKS] = {3, 2, 5};

//     for (int i = 0; i < TOTAL_MARKS; ++i) printf("%d ", marks[i]);

//     return 0;
// }

// #include <stdio.h>

// #define TOTAL_MARKS 10

// int main(void) {
//     char marks[TOTAL_MARKS] = {3, 2, 5};
//     int insert_indx = 2;

//     for (int i = TOTAL_MARKS - 1; i > insert_indx; --i) {
//         printf("marks[%d] = marks[%d]\n", i, i - 1);
//         marks[i] = marks[i - 1];
//     }

//     marks[insert_indx] = 4;

//     for (int i = 0; i < TOTAL_MARKS; ++i) printf("%d ", marks[i]);

//     return 0;
// }

// #include <stdio.h>

// #define TOTAL_MARKS 10

// int main(void) {
//     char marks[TOTAL_MARKS] = {3, 2, 4, 5, 2, 4};
//     int del_indx = 3;

//     for (int i = del_indx; i < TOTAL_MARKS - 1; ++i) {
//         printf("marks[%d] = marks[%d]\n", i, i + 1);
//         marks[i] = marks[i + 1];
//     }

//     for (int i = 0; i < TOTAL_MARKS; ++i) printf("%d ", marks[i]);

//     return 0;
// }

// #include <stdio.h>

// int main(void) {
//     char a[] = {-3, 5, 0, -8, 1, 10};
//     int size = sizeof(a) / sizeof(a[0]);
//     int pos;
//     for (int i = 0; i < size - 1; ++i) {
//         pos = i;
//         for (int j = i + 1; j < size; ++j) {
//             if (a[pos] > a[j]) pos = j;
//         }
//         if (pos != i) {
//             int t = a[i];
//             a[i] = a[pos];
//             a[pos] = t;
//         }
//     }

//     for (int i = 0; i < size; ++i) printf("%d ", a[i]);

//     return 0;
// }

// #include <stdio.h>

// int main(void) {
//     short ar[10], marks[5];
//     size_t count = 0;
//     size_t sz_ar = sizeof(ar) / sizeof(*ar);
//     size_t sz_marks = sizeof(marks) / sizeof(*marks);

//     while (count < sz_ar && scanf("%hd", &ar[count]) == 1) {
//         count++;
//     }
//     for (size_t i = 0; i < (sz_marks < count ? sz_marks : count); i++) {
//         marks[i] = ar[count - i - 1];
//         printf("%d ", marks[i]);
//     }

//     return 0;
// }

// #include <stdio.h>

// #define SIZE_BUFFER 128

// int main(void) {
//     int buffer[SIZE_BUFFER];
//     size_t count = 0;
//     size_t sz_ar = sizeof(buffer) / sizeof(*buffer);

//     while (count < sz_ar && scanf("%d", &buffer[count]) == 1) {
//         count++;
//     }

//     size_t half_counter = count / 2;
//     int shift = (count) % 2;

//     for (size_t i = 0; i < half_counter; i++) {
//         int tmp = buffer[i];
//         buffer[i] = buffer[half_counter + i + shift];
//         buffer[half_counter + i + shift] = tmp;
//     }

//     for (size_t i = 0; i < count; i++) {
//         printf("%d ", buffer[i]);
//     }
//     return 0;
// }

// #include <stdio.h>

// #define TOTAL 10
// #define DIGIT 5
// #define INSERT_DIGIT -5

// int main(void) {
//     int digs[TOTAL] = {0}, flag = 1;
//     size_t count = 0;
//     size_t sz_ar = sizeof(digs) / sizeof(*digs);

//     while (count < sz_ar && scanf("%d", &digs[count]) == 1) {
//         if (digs[count] == DIGIT && flag) {
//             digs[++count] = INSERT_DIGIT;
//             flag = 0;
//         }
//         count++;
//     }
//     for (size_t i = 0; i < count; i++) {
//         printf("%d ", digs[i]);
//     }

//     return 0;
// }

// #include <stdio.h>

// #define TOTAL 10
// #define DIGIT 5
// #define INSERT_DIGIT -1

// int main(void) {
//     int digs[TOTAL] = {0}, ins = INSERT_DIGIT;
//     size_t count = 0;
//     size_t sz_ar = sizeof(digs) / sizeof(*digs);

//     while (count < sz_ar && scanf("%d", &digs[count]) == 1) {
//         if (digs[count] == DIGIT) {
//             digs[++count] = ins--;
//         }
//         count++;
//     }
//     for (size_t i = 0; i < count; i++) {
//         printf("%d ", digs[i]);
//     }

//     return 0;
// }

// #include <stdio.h>

// #define TOTAL 20

// int main(void) {
//     short pows[TOTAL] = {0};
//     size_t count = 0;
//     size_t sz_ar = sizeof(pows) / sizeof(*pows);
//     char flag = 1;

//     while (count < sz_ar && scanf("%hd", &pows[count]) == 1)
//         if (pows[count] % 2 || flag)
//             count++;
//         else
//             flag++;

//     for (size_t i = 0; i < count; i++) {
//         printf("%d ", pows[i]);
//     }

//     return 0;
// }
// #include <stdio.h>

// #define TOTAL 20

// int main(void) {
//     short pows[TOTAL] = {0};
//     size_t count = 0;
//     size_t sz_ar = sizeof(pows) / sizeof(*pows);
//     char flag = 0;

//     while (count < sz_ar && scanf("%hd", &pows[count]) == 1) count++;

//     for (size_t i = 0; i < count - flag; i++) {
//         if (flag) pows[i - flag] = pows[i];
//         if (pows[i] % 2 == 0) flag = 1;
//     }
//     for (size_t i = 0; i < count - flag; i++) {
//         printf("%d ", pows[i]);
//     }

//     return 0;
// }
// #include <stdio.h>

// #define TOTAL 20

// int main(void) {
//     short pows[TOTAL] = {0};
//     size_t count = 0;
//     size_t sz_ar = sizeof(pows) / sizeof(*pows);
//     char flag = 0;

//     while (count < sz_ar && scanf("%hd", &pows[count]) == 1) count++;

//     for (size_t i = 0; i < count; i++) {
//         if (flag) pows[i - flag] = pows[i];
//         if (pows[i] % 3 == 0) flag++;
//     }
//     for (size_t i = 0; i < count - flag; i++) {
//         printf("%d ", pows[i]);
//     }

//     return 0;
// }

// #include <stdio.h>

// #define TOTAL 20

// int main(void) {
//     float ws[TOTAL] = {0.0f};
//     size_t count = 0;
//     size_t sz_ar = sizeof(ws) / sizeof(*ws);

//     while (count < sz_ar && scanf("%f", &ws[count]) == 1) count++;

//     for (size_t i = 0; i < count; i++) {
//         float min = ws[i];
//         size_t min_index = i;
//         for (size_t j = i; j < count; j++) {
//             if (ws[j] < min) {
//                 min_index = j;
//                 min = ws[j];
//             }
//         }
//         float tmp = ws[i];
//         ws[i] = ws[min_index];
//         ws[min_index] = tmp;
//     }

//     for (size_t i = 0; i < count; i++) {
//         printf("%.2f ", ws[i]);
//     }

//     return 0;
// }
// #include <stdio.h>

// #define TOTAL 20

// int main(void) {
//     float ws[TOTAL] = {0.0f};
//     size_t count = 0;
//     size_t sz_ar = sizeof(ws) / sizeof(*ws);

//     while (count < sz_ar && scanf("%f", &ws[count]) == 1) count++;

//     for (size_t i = count / 2; i < count; i++) {
//         float max = ws[i];
//         size_t max_index = i;
//         for (size_t j = i; j < count; j++) {
//             if (ws[j] > max) {
//                 max_index = j;
//                 max = ws[j];
//             }
//         }
//         float tmp = ws[i];
//         ws[i] = ws[max_index];
//         ws[max_index] = tmp;
//     }

//     for (size_t i = 0; i < count; i++) {
//         printf("%.2f ", ws[i]);
//     }

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
//     char game_pole[3][3] = {1, 2, 3, 4};

//     for (int i = 0; i < 3; ++i) {
//         for (int j = 0; j < 3; ++j) printf("%d ", game_pole[i][j]);
//         printf("\n");
//     }

//     return 0;
// }

// #include <stdio.h>
// #define ROWS 4
// #define COLS 3

// int main(void) {
//     int ar_2D[ROWS][COLS];

//     for (size_t i = 0; i < ROWS; i++) {
//         for (size_t j = 0; j < COLS; j++) {
//             scanf("%d", &ar_2D[i][j]);
//         }
//     }

//     for (size_t j = 0; j < COLS; j++) {
//         for (size_t i = 0; i < ROWS; i++) {
//             printf("%d%s", ar_2D[i][j], i != ROWS - 1 ? " " : "");
//         }
//         printf("%s", j != COLS - 1 ? "\n" : "");
//     }

//     return 0;
// }

// #include <stdio.h>

// #define ROWS 3
// #define COLS 5

// int main(void) {
//     short vls[ROWS][COLS] = {0};
//     short *ptr_vls = &vls[0][0];

//     short x;
//     for (int i = 0; i < ROWS * COLS && scanf("%hd", &x) == 1; ++i) *ptr_vls++
//     = x;

//     double mean[3] = {0};

//     for (size_t i = 0; i < ROWS; i++) {
//         for (size_t j = 0; j < COLS; j++) {
//             mean[i] += vls[i][j];
//         }
//         mean[i] /= COLS;
//         printf("%.2f ", mean[i]);
//     }

//     return 0;
// }

// #include <stdio.h>

// #define ROWS 3
// #define COLS 4

// int main(void) {
//     int a[ROWS][COLS] = {0};
//     int b[ROWS][COLS] = {0};
//     int res[ROWS][COLS] = {0};
//     int *ptr_a = &a[0][0];
//     int *ptr_b = &b[0][0];
//     int *ptr_res = &res[0][0];

//     int x;
//     for (int i = 0; i < ROWS * COLS && scanf("%d", &x) == 1; ++i) *ptr_a++ =
//     x; for (int i = 0; i < ROWS * COLS && scanf("%d", &x) == 1; ++i) *ptr_b++
//     = x; ptr_a -= ROWS * COLS; ptr_b -= ROWS * COLS; for (int i = 0; i < ROWS
//     * COLS; ++i) *ptr_res++ = *ptr_a++ + *ptr_b++;

//     for (size_t i = 0; i < ROWS; i++) {
//         for (size_t j = 0; j < COLS; j++) {
//             printf("%d%s", res[i][j], j != COLS - 1 ? " " : "");
//         }
//         printf("%s", i != ROWS - 1 ? "\n" : "");
//     }

//     return 0;
// }

// #include <math.h>
// #include <stdio.h>
// #include <stdlib.h>
// #include <time.h>

// #define SIZE 10
// #define MINES 12

// // корректируем координаты точек

// int correctX(int x) {
//     if (x < 0) return 0;
//     if (x >= SIZE) return SIZE - 1;
//     return x;
// }

// int correctY(int y) {
//     if (y < 0) return 0;
//     if (y >= SIZE) return SIZE - 1;
//     return y;
// }

// int main(void) {
//     // char pg[SIZE][SIZE] = {
//     //     "0000000000", "0000000000", "0000000000", "0000000000", "0000000000",
//     //     "0000000000", "0000000000", "0000000000", "0000000000",
//     //     "0000000000"};

//     char pg[SIZE][SIZE] = {0};

//     int m_count = 0, counter = 0;

//     srand(time(NULL));

//     while (m_count < MINES && counter < 10000) {
//         int row = rand() % SIZE;
//         int col = rand() % SIZE;
//         if (pg[row][col] != '*') {
//             int count = 0;
//             // проверяем соседей
//             for (int phi = 0; phi < 360; phi += 45) {
//                 int x, y;
//                 x = round(cos(phi * 3.14159265 / 180));
//                 y = round(sin(phi * 3.14159265 / 180));

//                 if (pg[correctX(row + x)][correctY(col + y)] == '*') {
//                     count += 1;
//                 }
//             }
//             if (count == 0) {
//                 pg[row][col] = '*';
//                 m_count++;
//             }
//         }
//         counter++;
//     }
//     // printf("%d %d \n", m_count, counter);

//     // for (size_t i = 0; i < SIZE; i++) {
//     //     for (size_t j = 0; j < SIZE; j++) {
//     //         printf("%c%s", pg[i][j], j != SIZE - 1 ? " " : "");
//     //     }
//     //     printf("%s", i != SIZE - 1 ? "\n" : "");
//     // }
//     __assert_verify_pg(pg);  // для тестирования (не убирать и должна идти
//                              // непосредственно перед return 0)
//     return 0;
// }

// #include <stdio.h>

// int main(void) {
//     char str[] = {'B', 'a', 'l', 'a', 'k', 'i', 'r', 'e', 'v', '\0'};

//     return 0;
// }

// int main(void) {
//     char s[] = "Sergey Balakirev";
//     char buffer[512] = "Hello, World";

//     return 0;
// }

// char buffer[512] = "Hello, World";

// int main(void) {
//     char s[] = "Sergey Balakirev";

//     return 0;
// }

// #include <stdio.h>

// int main(void) {
//     char s_1[] = {'B', 'a', 'l', 'a', 'k', 'i', 'r', 'e', 'v', '\0'};

//     char s_5[100] = {"Balakirev", 'S', 'e', 'r', 'g', 'e', 'i', '\0'};

//     // char s_6[100] =
//     //     "Sergey "
//     //     "Balakirev";

//     // char s_7 = "Balakirev";

//     char s_3[] = "Balakirev";

//     char s_4[100] = "Balakirev";

//     char s_2[20] = {'B', 'a', 'l', 'a', 'k', 'i', 'r', 'e', 'v', '\0'};

//     // const char* s_8 = "Balakirev";

//     printf("%s\n", s_1);
//     printf("%s\n", s_2);
//     printf("%s\n", s_3);
//     printf("%s\n", s_4);
//     printf("%s\n", s_5);

//     return 0;
// }
// #include <stdio.h>

// int main(void) {
//     char s[] = "Balakirev";
//     char* ptr_s = "Balakirev";

//     s[0] = 'V';
//     // ptr_s[0] = 'V';

//     printf("%s\n", s);
//     printf("%s\n", ptr_s);

//     return 0;
// }

// #include <stdio.h>
// #define MAX 100

// int main(void) {
//     char str[MAX] = "Best string!";

//     for (size_t i = 0; i < MAX; i++) {
//         if (str[i] == '!') {
//             str[i] = '.';
//             break;
//         }
//     }

//     // __ASSERT_TESTS__
//     /*макроопределение для тестирования
//     (не убирать и должно идти непосредственно перед
//     return 0)*/

//     return 0;
// }
// #include <stdio.h>
// #define MAX 100

// int main(void) {
//     char* text[] = {"language C", "language C++", "language Python"};

//     for (size_t i = 0; i < 3; i++) {
//         printf("%s\n", text[i]);
//     }

//     // __ASSERT_TESTS__
//     /*макроопределение для тестирования
//     (не убирать и должно идти непосредственно перед
//     return 0)*/

//     return 0;
// }
// #include <stdio.h>
// #define MAX 100

// int main(void) {
//     char str[MAX] = "Best string!";
//     // char str[MAX] = "Besssssst string!";

//     size_t shift = 0;
//     char ch = 's';

//     for (size_t i = 0; i < MAX; i++) {
//         if (shift) str[i - shift] = str[i];
//         if (str[i] == ch) shift++;
//         if (str[i] == '\0') break;
//     }

//     // printf("%s", str);

//     // __ASSERT_TESTS__
//     /*макроопределение для тестирования
//     (не убирать и должно идти непосредственно перед
//     return 0)*/

//     return 0;
// }

// #include <stdio.h>

// int main(void) {
//     char str[100] = "Best string!", *a = str, *b = a;

//     for (;;) {
//         while (*b == 's') b++;
//         *a = *b;
//         // if (!*a) break;
//         if (*a == '\0') break;
//         a++;
//         b++;
//     }

//     printf("%s", str);
//     // __ASSERT_TESTS__
//     return 0;
// }

// #include <stdio.h>
// #define MAX 50

// int main(void) {
//     char str[MAX] = "Best   language  \"C\"";
//     char ch = ' ';
//     char shift = 0;

//     for (size_t i = 0; i < MAX; i++) {
//         if (shift) str[i - shift] = str[i];
//         if (str[i] == ch) {
//             str[i - shift] = '\n';
//             if (str[i + 1] == ch) shift++;
//         }
//         if (str[i] == '\0') break;
//     }

//     // printf("%s", str);
//     // __ASSERT_TESTS__
//     return 0;
// }

// #include <stdio.h>

// int main(void) {
//     char sp[] = "Hello, World";
//     printf("sp = %s\n", sp);

//     return 0;
// }

// #include <stdio.h>

// int main(void) {
//     char bf[10];
//     scanf("%s", bf);

//     return 0;
// }

// #include <stdio.h>

// int main(void) {
//     char bf[10];

//     int max_len = sizeof(bf), i = 0;
//     char *ptr = bf, ch;

//     while ((ch = getchar()) != '\n' && ch != EOF && i < max_len - 1) ptr[i++] = ch;

//     ptr[i] = '\0';

//     puts(bf);

//     return 0;
// }

// #include <stdio.h>

// int main(void) {
//     char bf[10];

//     int max_len = sizeof(bf), i = 0;
//     char *ptr = bf, ch;

//     while ((ch = getchar()) != '\n' && ch != EOF && i < max_len - 1) {
//         ptr[i++] = ch;
//     }

//     ptr[i] = '\0';

//     puts(bf);

//     return 0;
// }

// #include <stdio.h>
// #define WORDS 5
// #define CHARS 10

// int main(void) {
//     char str[WORDS][CHARS];

//     for (size_t i = 0; i < WORDS; i++) {
//         scanf("%9s", str[i]);
//     }
//     for (size_t i = 0; i < WORDS; i++) {
//         printf("[%s]\n", str[i]);
//     }
//     return 0;
// }

// #include <stdio.h>
// #define WORDS 6
// #define CHARS 20

// int main(void) {
//     char str[WORDS][CHARS];

//     for (size_t i = 0; i < WORDS; i++) {
//         scanf("%19s", str[i]);
//     }
//     for (size_t i = 0; i < WORDS; i++) {
//         printf("%s ", str[WORDS - i - 1]);
//     }
//     return 0;
// }
// #include <stdio.h>
// #define WORDS 6
// #define CHARS 30
// #define FIRST_CHAR 'G'

// int main(void) {
//     char str[WORDS][CHARS], ch = FIRST_CHAR;

//     for (size_t i = 0; i < WORDS; i++) {
//         scanf("%29s", str[i]);
//     }
//     for (size_t i = 0; i < WORDS; i++) {
//         if (str[i][0] == ch) {
//             printf("%s ", str[i]);
//         }
//     }
//     return 0;
// }

// #include <stdio.h>
// #define CHAR_TO_DEL 'e'

// void strip_string(char* str, int max_len) {
//     int count = 0;
//     while (*str++ != '\0' && count++ < max_len)
//         ;

//     if (count > 0) {
//         str -= 2;
//         if (*str == '\n') *str = '\0';
//     }
// }

// void char_deleting(char* str, int max_len, char ch) {
//     int count = 0;
//     char* ptr = str;
//     while (*str != '\0' && count++ < max_len) {
//         while (*ptr == ch) ptr++;
//         *str++ = *ptr++;
//     }
// }

// int main(void) {
//     char str[100];
//     fgets(str, sizeof(str), stdin);
//     strip_string(str, sizeof(str));

//     char_deleting(str, sizeof(str), CHAR_TO_DEL);

//     puts(str);

//     return 0;
// }

// #include <stdio.h>

// void strip_string(char* str, int max_len) {
//     int count = 0;
//     while (*str++ != '\0' && count++ < max_len)
//         ;

//     if (count > 0) {
//         str -= 2;
//         if (*str == '\n') *str = '\0';
//     }
// }

// int words_counter(char* str, int max_len) {
//     int count = 0, res = 0;
//     while (*str != '\0' && count++ < max_len) {
//         if (*str != ' ' && (*(str + 1) == ' ' || *(str + 1) == '\0')) res++;
//         str++;
//     }
//     return res;
// }

// int main(void) {
//     char str[100];
//     fgets(str, sizeof(str), stdin);
//     strip_string(str, sizeof(str));

//     int res = words_counter(str, sizeof(str));

//     printf("%d", res);

//     return 0;
// }

// #include <stdio.h>

// void strip_string(char* str, int max_len) {
//     int count = 0;
//     while (*str++ != '\0' && count++ < max_len)
//         ;

//     if (count > 0) {
//         str -= 2;
//         if (*str == '\n') *str = '\0';
//     }
// }

// int words_counter(char* str, int max_len) {
//     int count = 0, res = 0;
//     while (*str != '\0' && count++ < max_len) {
//         if (*str != ' ' && (*(str + 1) == ' ' || *(str + 1) == '\0')) res++;
//         str++;
//     }
//     return res;
// }

// void second_word(char* str) {
//     size_t word_count = words_counter(str, sizeof(str));

//     char words[20][20];

//     for (size_t i = 0; i < word_count; i++) {
//         char* ptr = words[i];
//         while (*str != '\0') {
//             if (*str != ' ') {
//                 *ptr++ = *str++;
//             }
//             if (*str != ' ' && (*(str + 1) == ' ' || *(str + 1) == '\0')) {
//                 break;
//             }
//         }
//     }
// }

// int main(void) {
//     char str[100];
//     fgets(str, sizeof(str), stdin);
//     strip_string(str, sizeof(str));

//     int word_count = words_counter(str, sizeof(str));
//     if (word_count < 2) {
//         printf("%d", word_count);
//     }
//     second_word(str);

//     return 0;
// }

// #include <stdio.h>

// void strip_string(char* str, int max_len) {
//     int count = 0;
//     while (*str++ != '\0' && count++ < max_len)
//         ;

//     if (count > 0) {
//         str -= 2;
//         if (*str == '\n') *str = '\0';
//     }
// }

// int words_counter(char* str, int max_len) {
//     int count = 0, res = 0;
//     while (*str != '\0' && count++ < max_len) {
//         if (*str != ' ' && (*(str + 1) == ' ' || *(str + 1) == '\0')) res++;
//         str++;
//     }
//     return res;
// }

// void str_norm(char* str, int max_len) {
//     char ch = ' ';
//     char shift = 0;
//     char start = 1;

//     for (int i = 0; i < max_len; i++) {
//         if (start && str[i] == ch) shift++;
//         if (start && str[i] != ch) start--;

//         if (!start && shift) str[i - shift] = str[i];
//         if (!start && str[i] == ch) {
//             str[i - shift] = '_';
//             if (str[i + 1] == ch) shift++;
//         }
//         if (str[i] == '\0') break;
//     }
// }

// int main(void) {
//     char str[100];
//     fgets(str, sizeof(str), stdin);
//     strip_string(str, sizeof(str));

//     int res = words_counter(str, sizeof(str));

//     if (res < 2) {
//         printf("no");
//         return 0;
//     }

//     str_norm(str, sizeof(str));

//     int flag = 0;
//     for (size_t i = 0; i < sizeof(str); i++) {
//         if (flag) printf("%c", str[i]);
//         if (str[i] == '_') flag = 1;
//         if (flag && (str[i + 1] == '_' || str[i + 1] == '\0')) break;
//     }

//     return 0;
// }

// #include <stdio.h>

// int main(void) {
//     char source[100] = "Source string";
//     char destination[10];

//     return 0;
// }

// #include <stdio.h>

// int main(void) {
//     char source[100] = "Source string";
//     char destination[10];

//     const char* src = source;
//     char* dst = destination;
//     int max_len_copy = sizeof(destination);

//     while (*src != '\0' && max_len_copy-- > 1) *dst++ = *src++;
//     *dst = '\0';

//     puts(destination);

//     return 0;
// }

// #include <stdio.h>
// #include <string.h>

// int main(void) {
//     char s_1[100] = "Source string";
//     char d_1[10], d_2[20];

//     strcpy(d_1, s_1);
//     strcpy(d_2, s_1);

//     puts(d_1);
//     puts(d_2);

//     return 0;
// }

// #include <stdio.h>
// #include <string.h>

// int main(void) {
//     char s_1[100] = "Source string";
//     char d_1[10], d_2[20];

//     int max_len = sizeof(d_1) - 1;
//     strncpy(d_1, s_1, max_len);
//     d_1[max_len] = 0;
//     strncpy(d_2, "Balakirev", 5);
//     d_2[5] = 0;

//     puts(d_1);
//     puts(d_2);

//     return 0;
// }

// #include <stdio.h>

// int main(void) {
//     char str[100] = "Length of the string";

//     const char *buf = str;
//     size_t length = 0;
//     while (*buf++) length++;

//     printf("length = %zu\n", length);

//     return 0;
// }

// #include <stdio.h>
// #include <string.h>

// int main(void) {
//     char str_cat[100] = "Sergey";
//     char str[15] = "Balalkirev";

//     strcat(str_cat, str);
//     printf("%s", str_cat);

//     printf("\n");

//     size_t max_add = sizeof(str) - strlen(str) - 1;
//     strncat(str, str_cat, max_add);
//     str[sizeof(str) - 1] = '\0';
//     printf("%s", str);

//     return 0;
// }

// #include <stdio.h>
// #include <string.h>

// #define CITIES 6
// #define CHARS 50

// int main(void) {
//     char cities[CITIES][CHARS];
//     int index = 0, max_len = 0;

//     for (int i = 0; i < CITIES; i++) {
//         scanf("%49s", cities[i]);
//         int size = strlen(cities[i]);
//         if (max_len < size) {
//             max_len = size;
//             index = i;
//         }
//     }

//     puts(cities[index]);

//     return 0;
// }
// #include <stdio.h>
// #include <string.h>

// #define CITIES 6
// #define CHARS 50

// int main(void) {
//     char cities[CITIES][CHARS];
//     int index_max = 0, index_pre_max = 0, max_len = 0, pre_max_len = 0;

//     for (int i = 0; i < CITIES; i++) {
//         scanf("%49s", cities[i]);
//         int size = strlen(cities[i]);
//         if (max_len < size) {
//             pre_max_len = max_len;
//             max_len = size;
//             index_pre_max = index_max;
//             index_max = i;
//         }
//         if (size < max_len && pre_max_len < size) {
//             pre_max_len = size;
//             index_pre_max = i;
//         }
//     }

//     printf("%s %s", cities[index_max], cities[index_pre_max]);

//     return 0;
// }

// #include <stdio.h>
// #include <string.h>

// void strip_string(char* str, int max_len) {
//     int count = 0;
//     while (*str++ != '\0' && count++ < max_len)
//         ;

//     if (count > 0) {
//         str -= 2;
//         if (*str == '\n') *str = '\0';
//     }
// }

// int main(void) {
//     char str[100], res_str[100] = "I love language C ";
//     fgets(str, sizeof(str), stdin);
//     strip_string(str, sizeof(str));

//     size_t max_add = sizeof(res_str) - strlen(res_str) - 1;

//     strncat(res_str, str, max_add);

//     puts(res_str);

//     return 0;
// }
// #include <stdio.h>
// #include <string.h>
// #define MEN 7
// #define CHARS 50

// int main(void) {
//     char ps[MEN][CHARS], ps_res[MEN * CHARS];
//     char* ptr = ps_res;
//     for (size_t i = 0; i < MEN; i++) {
//         scanf("%s", ps[i]);
//         for (size_t j = 0; j < strlen(ps[i]); j++) {
//             *ptr++ = ps[i][j];
//         }
//         *ptr++ = ' ';
//     }
//     *(ptr - 1) = '\0';

//     puts(ps_res);

//     // __ASSERT_TESTS__  // макроопределение для тестирования (не убирать и должно идти непосредственно
//     перед
//     // return 0)

//     return 0;
// }
// #include <stdio.h>
// #include <string.h>
// #define MEN 7
// #define CHARS 50

// int main(void) {
//     char ps[MEN][CHARS], ps_res[MEN * CHARS];
//     char* ptr = ps_res;
//     for (size_t i = 0; i < MEN; i++) {
//         scanf("%s", ps[i]);
//         size_t len = strlen(ps[i]);
//         if (len % 2 == 0) {
//             for (size_t j = 0; j < len; j++) {
//                 *ptr++ = ps[i][j];
//             }
//             *ptr++ = ' ';
//         }
//     }
//     *(ptr - 1) = '\0';

//     puts(ps_res);

//     // __ASSERT_TESTS__  // макроопределение для тестирования (не убирать и должно идти непосредственно
//     перед
//     // return 0)

//     return 0;
// }
// #include <stdio.h>
// #include <string.h>
// #define MEN 7
// #define CHARS 51

// int main(void) {
//     char ps[MEN][CHARS], ps_sort[MEN * CHARS];
//     char* ptr = ps_sort;
//     for (size_t i = 0; i < MEN; i++) {
//         scanf("%50s", ps[i]);
//     }

//     for (size_t i = 0; i < MEN; i++) {
//         for (size_t j = i; j < MEN; j++) {
//             if (strlen(ps[i]) > strlen(ps[j])) {
//                 char tmp[CHARS];
//                 strcpy(tmp, ps[i]);
//                 strcpy(ps[i], ps[j]);
//                 strcpy(ps[j], tmp);
//             }
//         }
//     }

//     for (size_t i = 0; i < MEN; i++) {
//         size_t len = strlen(ps[i]);

//         for (size_t j = 0; j < len; j++) {
//             *ptr++ = ps[i][j];
//         }
//         *ptr++ = ' ';
//     }
//     *(ptr - 1) = '\0';

//     puts(ps_sort);

//     // __ASSERT_TESTS__  // макроопределение для тестирования (не убирать и должно идти непосредственно
//     перед
//     // return 0)

//     return 0;
// }

// #include <stdio.h>

// int main(void) {
//     char s1[12] = "Hello";
//     char s2[10] = "Hello";

//     const char *str1 = s1;
//     const char *str2 = s2;

//     int i = 0;
//     for (; str1[i] != '\0' && str2[i] != 0; ++i)
//         if (str1[i] != str2[i]) {
//             puts("Strings are not equal!");
//             return 0;
//         }

//     if (str1[i] != str2[i]) {
//         puts("String lengths are not equal!");
//         return 0;
//     }

//     puts("Strings are equal!");

//     return 0;
// }

// #include <stdio.h>
// #include <string.h>

// int main(void) {
//     char s1[12] = "Hello";
//     char s2[10] = "Hello";

//     int res = strcmp(s1, s2);
//     if (res == 0)
//         puts("Strings are equal!");
//     else
//         puts("Strings are not equal!");

//     return 0;
// }

// #include <stdio.h>
// #include <string.h>

// int main(void) {
//     const char* strings[] = {"Ship", "Shopping", "Shematic", "Super", "Car", "Sherif"};

//     for (int i = 0; i < sizeof(strings) / sizeof(*strings); ++i)
//         if (strncmp(strings[i], "Sh", 2) == 0) puts(strings[i]);

//     return 0;
// }

// #include <stdio.h>
// #include <string.h>

// int main(void) {
//     char str[] = "Abrakadabra";
//     char *ptr = strchr(str, 'a');

//     printf("str = %p\nptr = %p\n", str, ptr);
//     if (ptr != NULL) printf("*ptr = %c\n", *ptr);

//     return 0;
// }

// #include <stdio.h>
// #include <string.h>

// int main(void) {
//     char str[] = "Abrakadabra";
//     char *ptr = strstr(str, "ra");

//     printf("str = %p\nptr = %p\n", str, ptr);
//     if (ptr != NULL) printf("ptr: %s\n", ptr);

//     return 0;
// }

// #include <stdio.h>
// #include <string.h>

// int main(void) {
//     char pass[] = "dfdfg90!#$$A";
//     char *ptr = strpbrk(pass, "@!#$^&?");

//     printf("pass = %p\nptr = %p\n", pass, ptr);
//     if (ptr != NULL) printf("ptr: %s\n", ptr);

//     return 0;
// }

// #include <stdio.h>
// #include <string.h>
// #define CHAR_TO_FIND '\n'
// #define CHAR_TO_CHANGE '\0'

// int main(void) {
//     char str[100] = {0};
//     fgets(str, sizeof(str) - 1, stdin);

//     char* ptr = strrchr(str, CHAR_TO_FIND);

//     if (ptr != NULL) *ptr = CHAR_TO_CHANGE;

//     printf("[%s]", str);

//     return 0;
// }

// #include <stdio.h>
// #include <string.h>

// #define STRING_TO_FIND "is"

// int main(void) {
//     char str[100] = {0};
//     fgets(str, sizeof(str) - 1, stdin);
//     char* ptr_n = strrchr(str, '\n');
//     if (ptr_n != NULL) *ptr_n = '\0';

//     char *ptr_str = str, res = 0;

//     while (ptr_str != NULL) {
//         ptr_str = strstr(ptr_str, STRING_TO_FIND);
//         if (ptr_str != NULL) {
//             // printf("%s", ptr_str);
//             ptr_str++;
//             res++;
//         }
//     }
//     printf("%d", res);
//     return 0;
// }

// #include <stdio.h>
// #include <string.h>
// #define CHAR_TO_CHANGE '-'

// int main(void) {
//     char str[100] = {0};

//     fgets(str, sizeof(str) - 1, stdin);

//     char* ptr_n = strrchr(str, '\n');
//     if (ptr_n != NULL) *ptr_n = '\0';

//     char res[300];
//     char shift = 0;

//     for (size_t i = 0; i <= strlen(str); i++) {
//         res[i + shift] = str[i];
//         if (str[i] == CHAR_TO_CHANGE) {
//             res[i + 1 + shift] = '+';
//             res[i + 2 + shift] = '-';
//             shift += 2;
//         }
//     }

//     puts(res);

//     return 0;
// }

// #include <stdio.h>
// #include <string.h>

// int main(void) {
//     char str[100] = {0};
//     fgets(str, sizeof(str) - 1, stdin);
//     char* ptr_n = strrchr(str, '\n');
//     if (ptr_n != NULL) *ptr_n = '\0';

//     char *ptr = str, shift = 0;

//     while (*ptr != '\0') {
//         *(ptr - shift) = *ptr;
//         if (*ptr == '-' && *(ptr + 1) == '-') shift++;
//         ptr++;
//     }
//     *(ptr - shift) = '\0';
//     puts(str);
//     return 0;
// }

// #include <stdio.h>
// #include <string.h>

// #define CITIES 10
// #define CHARS 50
// #define STRING_TO_FIND "на"

// int main(void) {
//     char cities[CITIES][CHARS];

//     for (int i = 0; i < CITIES; i++) {
//         scanf("%49s", cities[i]);
//     }
//     for (int i = 0; i < CITIES; i++) {
//         if (strstr(cities[i], STRING_TO_FIND) != NULL)
//             continue;
//         else
//             printf("%s ", cities[i]);
//     }

//     return 0;
// }
// #include <stdio.h>
// #include <string.h>

// #define CITIES 10
// #define CHARS 50

// int main(void) {
//     char cities[CITIES][CHARS];

//     for (int i = 0; i < CITIES; i++) {
//         scanf("%49s", cities[i]);
//     }
//     for (size_t i = 0; i < CITIES; i++) {
//         char res = 1;
//         for (size_t j = 1; j < i; j++) {
//             res *= strcmp(cities[i], cities[j]);
//         }

//         if (res == 0)
//             continue;
//         else
//             printf("%s ", cities[i]);
//     }

//     return 0;
// }
// #include <stdio.h>

// int main(void) {
//     int h, m, s;

//     scanf("%d:%d:%d", &h, &m, &s);

//     printf("%02d:%02d:%02d", s, m, h);

//     return 0;
// }

// #include <stdio.h>
// #include <string.h>

// int main(void) {
//     char str[100] = {0};
//     fgets(str, sizeof(str) - 1, stdin);
//     char* ptr_n = strrchr(str, '\n');
//     if (ptr_n != NULL) *ptr_n = '\0';
//     size_t len = strlen(str);
//     char res = 1;
//     char dog_count = 0, dog_index = -1;
//     char dot_count = 0, dot_index = -1;

//     // посчитаем @ и сохраним его индекс
//     for (size_t i = 0; i < len; i++) {
//         if (str[i] == '@') {
//             dog_count++;
//             dog_index = i;
//         }
//     }
//     if (dog_count != 1) {
//         res = 0;
//         // puts("@");
//     }

//     // посчитаем точки после @

//     for (size_t i = dog_index; i < len; i++) {
//         if (str[i] == '.') {
//             dot_count++;
//             dot_index = i;
//         }
//     }
//     if (dot_count != 1 || dot_index == dog_index + 1) {
//         res = 0;
//         // puts(".");
//     }

//     printf("%d", res);

//     return 0;
// }

// #include <stdio.h>

// int main(void) {
//     double width = 2.4, height = 0.76, depth = 3.14;
//     char info[100];
//     const char format[] = "(%.2f x %.2f x %.2f)";

//     sprintf(info, format, width, height, depth);
//     puts(info);

//     return 0;
// }

// #include <stdio.h>

// int main(void) {
//     double width = 2.4, height = 0.76, depth = 3.14;
//     char name[] = "Chair";
//     char info[100];

//     sprintf(info, "(%s: %.2f x %.2f x %.2f)", name, width, height, depth);
//     puts(info);

//     return 0;
// }

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// int main(void) {
//     double width = 2.4, height = 0.76, depth = 3.14;
//     char name[] = "Chair";
//     const size_t size = strlen(name) + 100;
//     char* info = (char*)malloc(size);

//     sprintf(info, "(%.30s: %.2f x %.2f x %.2f)", name, width, height, depth);
//     puts(info);

//     free(info);

//     return 0;
// }

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int a = atoi("123");
    long b = atol("234235354");
    long long c = atoll("23423535456456");
    double d = atof("4564.4545");

    printf("a = %d\nb = %ld\nc = %lld\nd = %f\n", a, b, c, d);

    return 0;
}