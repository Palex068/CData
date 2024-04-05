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
//     int marks[TOTAL_MARKS] = {1, 2, 3, 4, val, abs(val), 0, 0, 0, 0, 0, 0, 0};

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

#include <stdio.h>

void bite_print(void* arg, int len) {
    const unsigned char* ptr = (unsigned char*)arg;
    for (int i = 0; i < len; i++) {
        printf("%d ", *(ptr + i));
    }
}

int main(void) {
    short var_1;
    int var_2;
    long var_3;

    scanf("%hd, %d, %ld", &var_1, &var_2, &var_3);

    bite_print((void*)&var_1, sizeof(var_1));
    bite_print((void*)&var_2, sizeof(var_2));
    bite_print((void*)&var_3, sizeof(var_3));
    return 0;
}