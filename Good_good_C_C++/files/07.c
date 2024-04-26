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
// #include <stdio.h>
// #define NOTES_COUNT 5

// typedef enum { _do = 1, _re = 2, _mi = 3, _fa = 4, _sol = 5, _la = 6, _si = 7 } NOTES;

// int get_major(NOTES note) {
//     int res = 0;
//     switch (note) {
//         case _do:
//         case _mi:
//         case _sol:
//             res = 1;
//             break;
//         default:
//             res = 0;
//     }
//     return res;
// }

// int main(void) {
//     NOTES accord[NOTES_COUNT];
//     for (size_t i = 0; i < NOTES_COUNT; i++) {
//         int note;
//         scanf("%d", &note);
//         accord[i] = note;
//     }

//     for (size_t i = 0; i < NOTES_COUNT; i++) {
//         if (get_major(accord[i])) printf("%d ", accord[i]);
//     }

//     return 0;
// }

// #include <stdio.h>
// #include <string.h>

// #define MAX_WORDS 20

// int is_correct(const char* str) {
//     int res = 0;
//     char* str_for_search[4] = {"RA", "Ra", "rA", "ra"};
//     for (size_t i = 0; i < 4; i++) {
//         if (strstr(str, str_for_search[i]) != NULL) {
//             res = 1;
//             break;
//         }
//     }
//     return res;
// }

// typedef int (*FUNC_CORRECT)(const char*);

// FUNC_CORRECT filter = is_correct;

// int get_correct_words(const char (*words)[50], int count_words, FUNC_CORRECT filter) {
//     int res = 0;
//     for (int i = 0; i < count_words; i++) {
//         // puts(words[i]);
//         if (filter(words[i])) res++;
//     }
//     return res;
// }

// int main() {
//     char words[MAX_WORDS][50];

//     int count = 0;
//     int result;

//     while (count < MAX_WORDS && scanf("%49s", words[count]) == 1) {
//         if (strlen(words[count]) < 2) break;
//         // puts(words[count]);
//         count++;
//     }

//     // for (size_t i = 0; i < count; i++) {
//     //     puts(words[i]);
//     // }

//     result = get_correct_words(words, count, filter);

//     printf("%d", result);

//     return 0;
// }
// #include <stdio.h>

// typedef struct tag_vector {
//     short x;
//     short y;
//     short z;
// } VECTOR;

// int main() {
//     VECTOR vector;

//     scanf("%hd %hd %hd", &vector.x, &vector.y, &vector.z);

//     // __ASSERT_TESTS__
//     // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0)

//     return 0;
// }

// #include <stdio.h>

// struct tag_price {
//     char name[100];
//     unsigned int rubs;
//     unsigned short kops;
//     unsigned int foreign_key;
// };

// struct tag_price price_100 = {};

// int main(void) {
//     struct tag_price pr = price_100;

//     printf("%s %d %d %d", pr.name, pr.rubs, pr.kops, pr.foreign_key);

//     // __ASSERT_TESTS__
//     // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0)
//     return 0;
// }

// #include <stdio.h>
// #include <string.h>

// typedef struct tag_fio {
//     char firstname[50];
//     char otch[50];
//     char lastname[50];
// } FIO;

// typedef struct tag_student {
//     FIO fio;
//     short old;
//     short height;
//     short weight;
// } STUDENT;

// void _getline(char* buffer, size_t max_len) {
//     fgets(buffer, max_len - 1, stdin);
//     char* ptr_n = strrchr(buffer, '\n');
//     if (ptr_n != NULL) *ptr_n = '\0';
// }

// int main(void) {
//     char fname[50], otch[50], lname[50];  // имя, отчество, фамилия
//     short old, height, weight;            // возраст, высота, вес

//     _getline(fname, sizeof(fname));
//     _getline(otch, sizeof(otch));
//     _getline(lname, sizeof(lname));

//     scanf("%hd, %hd, %hd", &old, &height, &weight);

//     STUDENT st = {.old = old, .height = height, .weight = weight};

//     strcpy(st.fio.firstname, fname);
//     strcpy(st.fio.otch, otch);
//     strcpy(st.fio.lastname, lname);

//     // printf("%s\n%s\n%s\n%d\n%d\n%d", st.fio.firstname, st.fio.otch, st.fio.lastname, st.height, st.old,
//     // st.weight);

//     // __ASSERT_TESTS__
//     // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0)
//     return 0;
// }

// #include <stdio.h>

// typedef struct tag_time {
//     unsigned char hours;
//     unsigned char minutes;
//     unsigned char seconds;
// } TIME;

// int main(void) {
//     TIME tm1, tm2, tm_sum;

//     char shift_minutes = 0;
//     char shift_hours = 0;

//     scanf("%d %d %d", &tm1.hours, &tm1.minutes, &tm1.seconds);
//     scanf("%d %d %d", &tm2.hours, &tm2.minutes, &tm2.seconds);

//     tm_sum.seconds = (tm1.seconds + tm2.seconds) % 60;
//     shift_minutes = tm1.seconds + tm2.seconds < 60 ? 0 : 1;
//     tm_sum.minutes = (tm1.minutes + tm2.minutes + shift_minutes) % 60;
//     shift_hours = tm1.minutes + tm2.minutes + shift_minutes < 60 ? 0 : 1;
//     tm_sum.hours = tm1.hours + tm2.hours + shift_hours;

//     printf("%02d:%02d:%02d", tm_sum.hours, tm_sum.minutes, tm_sum.seconds);

//     // __ASSERT_TESTS__
//     // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0)
//     return 0;
// }

// #include <stdio.h>

// typedef struct tag_point_3d {
//     int x;
//     int y;
//     int z;
// } POINTS_3D;

// int main(void) {
//     enum { total_points = 100 };

//     POINTS_3D points[total_points];

//     size_t i;

//     for (i = 0; i < total_points; i++) {
//         if (scanf("%d %d %d", &points[i].x, &points[i].y, &points[i].z) != 3) break;
//     }
//     i--;
//     printf("%d %d %d", points[i].x, points[i].y, points[i].z);

//     // __ASSERT_TESTS__
//     // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0)
//     return 0;
// }

// #include <stdio.h>

// typedef struct tag_geom {
//     char type;   // тип геометрической фигуры
//     int x0, y0;  // координаты верхнего левого угла
//     int x1, y1;  // координаты нижнего правого угла
// } GEOM;

// int main(void) {
//     GEOM geom = {1, 10, 20, 50, 30};

//     GEOM* ptr_geom = &geom;

//     printf("%d %d %d %d %d", ptr_geom->type, ptr_geom->x0, ptr_geom->y0, ptr_geom->x1, ptr_geom->y1);

//     // __ASSERT_TESTS__
//     // макроопределение для тестирования (не убирать)
//     return 0;
// }

// #include <stdio.h>
// #include <stdlib.h>

// typedef struct tag_rub {
//     double ratio_usd;  // курс доллара к рублю (1$ = xx рублей)
//     int rubs;          // количество рублей
// } RUB;

// int main(void) {
//     RUB* account_r = malloc(sizeof(RUB));

//     account_r->ratio_usd = 91.32;

//     scanf("%d", &account_r->rubs);

//     printf("%.2lf", account_r->rubs / account_r->ratio_usd);

//     // __ASSERT_TESTS__
//     // макроопределение для тестирования (не убирать)

//     free(account_r);
//     return 0;
// }

// #include <stdio.h>
// #include <stdlib.h>

// typedef struct {
//     double re;  // действительная часть
//     double im;  // мнимая часть
// } COMPLEX;

// COMPLEX complex_sum(COMPLEX cmp1, COMPLEX cmp2) {
//     COMPLEX res = {cmp1.re + cmp2.re, cmp1.im + cmp2.im};
//     return res;
// }

// int main(void) {
//     COMPLEX cmp_1, cmp_2;

//     scanf("%lf, %lf, %lf, %lf", &cmp_1.re, &cmp_1.im, &cmp_2.re, &cmp_2.im);

//     COMPLEX result = complex_sum(cmp_1, cmp_2);

//     // __ASSERT_TESTS__
//     // макроопределение для тестирования (не убирать)

//     return 0;
// }
// #include <stdio.h>
// #include <stdlib.h>

// typedef struct {
//     int x;
//     int y;
// } POINT;

// int rect_square(const POINT* left_up, const POINT* right_down) {
//     int res = (right_down->x - left_up->x) * (right_down->y - left_up->y);
//     return res;
// }

// int main(void) {
//     POINT p1, p2;

//     scanf("%d %d %d %d", &p1.x, &p1.y, &p2.x, &p2.y);

//     int result = rect_square(&p1, &p2);

//     printf("%d", result);

//     return 0;
// }

// #include <stdio.h>
// #include <stdlib.h>
// #define MAX 20

// typedef struct {
//     int x;
//     int y;
// } POINT;

// typedef struct {
//     double mean_x;
//     double mean_y;
// } DATA;

// DATA get_means(const POINT points[], size_t count) {
//     DATA res = {0, 0};
//     for (size_t i = 0; i < count; i++) {
//         res.mean_x += points[i].x;
//         res.mean_y += points[i].y;
//     }
//     res.mean_x /= count;
//     res.mean_y /= count;

//     return res;
// }

// int main(void) {
//     POINT points[MAX];

//     size_t count = 0;
//     for (size_t i = 0; i < MAX; i++) {
//         if (scanf("%d %d", &points[i].x, &points[i].y) == 2)
//             count++;
//         else
//             break;
//     }

//     DATA result = get_means(points, count);

//     printf("%.2lf %.2lf", result.mean_x, result.mean_y);

//     return 0;
// }

// #include <stdarg.h>
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// typedef struct {
//     char fname[100];  // строка максимальной длиной 100 символов (фамилия)
//     char old;         // возраст;
//     char stag;        // стаж;
//     int salary;       // зарплата;
//     double efs;       // эффективность труда сотрудника;
// } PERSON;

// void fill_data(PERSON* p, char* str, ...) {
//     va_list arg;
//     char* ptr = str;
//     // puts(str);
//     va_start(arg, str);
//     while (ptr != NULL) {
//         switch (*(++ptr)) {
//             case 'f':
//                 strcpy(p->fname, va_arg(arg, char*));
//                 // puts(p->fname);
//                 break;
//             case 'o':
//                 p->old = va_arg(arg, int);
//                 // printf("%d\n", p->old);
//                 break;
//             case 'g':
//                 p->stag = va_arg(arg, int);
//                 // printf("%d\n", p->stag);
//                 break;
//             case 's':
//                 p->salary = va_arg(arg, int);
//                 // printf("%d\n", p->salary);
//                 break;
//             case 'e':
//                 p->efs = va_arg(arg, double);
//                 // printf("%.2lf\n", p->efs);
//                 break;
//             default:
//                 break;
//         }
//         ptr = strpbrk(ptr, "#");
//         // if (ptr != NULL) puts(ptr);
//     }
//     va_end(arg);
// }

// int main(void) {
//     PERSON user;

//     fill_data(&user, "#o #e #s #f", 47, 23.5, 500000, "Alexander");

//     return 0;
// }

#include <stdio.h>
#include <stdlib.h>

typedef struct tag_obj {
    int data;
    struct tag_obj* next;
} OBJ;

OBJ* push(OBJ* top, int data) {
    OBJ* ptr = malloc(sizeof(OBJ));
    ptr->data = data;
    ptr->next = top;
    return ptr;
}

OBJ* pop(OBJ* top) {
    if (top == NULL) return top;

    printf("Deleted: %d\n", top->data);

    OBJ* ptr_next = top->next;
    free(top);

    return ptr_next;
}

void show_stack(const OBJ* top) {
    const OBJ* current = top;
    while (current != NULL) {
        printf("%d\n", current->data);
        current = current->next;
    }
}

int main(void) {
    OBJ* top = NULL;

    top = push(top, 1);
    top = push(top, 2);
    top = push(top, 3);
    top = push(top, 4);

    show_stack(top);

    while (top) top = pop(top);

    return 0;
}