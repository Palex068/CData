// #include <stdbool.h>
// #include <stdio.h>

// int main(void) {
//     double f = 0.0;
//     int i = 5, j = 5, k = 5;

//     bool res_1 = i < 5;
//     bool res_2 = i >= 5;
//     bool res_3 = f;
//     bool res_4 = i++ > 5;
//     bool res_5 = ++j > 5;
//     bool res_6 = 10 < k * 2;
//     bool res_7 = 12 == k * 3;

//     printf("%d\n%d\n%d\n%d\n%d\n%d\n%d\n", res_1, res_2, res_3,
//     res_4, res_5, res_6, res_7); return 0;
// }

// #include <stdio.h>

// int main(void) {
//     int num;
//     scanf("%d", &num);
//     printf("%d", 100 * (num % 5 == 0));
//     return 0;
// }
// #include <stdio.h>

// int main(void) {
//     double num;
//     scanf("%lf", &num);
//     printf("%d", 100 * ((int)num % 5 == 0));
//     return 0;
// }

// #include <stdio.h>
// #define MIN -5.45
// #define MAX 10.37

// int main(void) {
//     double num;
//     scanf("%lf", &num);

//     int res = (num - MIN >= 0 && num - MAX <= 0);

//     printf("%d", res);
//     return 0;
// }

// #include <stdio.h>
// #define MIN_A -10
// #define MAX_A 0
// #define MIN_B 5
// #define MAX_B 12

// int main(void) {
//     double num;
//     scanf("%lf", &num);
//     int a, b, c, d;

//     a = num - MIN_A >= 0;
//     b = num - MAX_A < 0;
//     c = num - MIN_B > 0;
//     d = num - MAX_B <= 0;

//     int res = a * b + c * d;

//     printf("%d", res);
//     return 0;
// }

// #include <stdio.h>
// #define MIN_X -5
// #define MAX_X 10
// #define MIN_Y 0
// #define MAX_Y 7

// int main(void) {
//     double x, y;
//     scanf("%lf %lf", &x, &y);
//     int a, b, c, d;

//     a = x - MIN_X > 0;
//     b = x - MAX_X < 0;
//     c = y - MIN_Y > 0;
//     d = y - MAX_Y < 0;

//     int res = a * b * c * d;

//     printf("%d", res);
//     return 0;
// }

// #include <stdio.h>
// #define MIN_X -5
// #define MAX_X 10
// #define MIN_Y 0
// #define MAX_Y 7

// int main(void) {
//     double x, y;
//     scanf("%lf %lf", &x, &y);
//     int a, b, c, d;

//     a = x - MIN_X > 0;
//     b = x - MAX_X < 0;
//     c = y - MIN_Y > 0;
//     d = y - MAX_Y < 0;

//     int res = (a * b * c * d) == 0;

//     printf("%d", res);
//     return 0;
// }

// #include <stdio.h>

// int main(void) {
//     int rect_width = 640, rect_height = 480;
//     int w = 1, h = 1;
//     scanf("%d; %d", &w, &h);

//     int count_w = rect_width / w;
//     int count_h = rect_height / h;

//     int a = rect_width - count_w * w > 0;
//     int b = rect_height - count_h * h > 0;
//     int c = a + b == 1;

//     int res = count_h * a + count_w * b + c;

//     printf("%d", res);

//     return 0;
// }

// #include <stdio.h>

// int main(void) {
//     short x, y;
//     if (scanf("%hd, %hd", &x, &y) != 2) {
//         printf("Input error.");
//         return 0;
//     }

//     short min = x < y ? x : y;

//     printf("%d", min);

//     return 0;
// }

// #include <stdio.h>

// int main(void) {
//     int m, n;
//     if (scanf("%d, %d", &m, &n) != 2) {
//         printf("Input error.");
//         return 0;
//     }

//     if (m % n)
//         printf("division error");
//     else
//         printf("%d", m / n);

//     return 0;
// }

// #include <stdio.h>

// int main(void) {
//     int m, n;
//     if (scanf("%d %d", &m, &n) != 2) {
//         printf("Input error.");
//         return 0;
//     }

//     if (m == n)
//         printf("%d", m);
//     else {
//         printf("%d ", m < n ? m : n);
//         printf("%d", m < n ? n : m);
//     }
//     return 0;
// }

// #include <stdio.h>

// int main(void) {
//     unsigned int a;
//     if (scanf("%u", &a) != 1 || a > 7) {
//         printf("не верный номер дня недели");
//         return 0;
//     }

//     char* lib[7] = {"понедельник", "вторник", "среда", "четверг",
//     "пятница", "суббота", "воскресенье"};

//     printf("%s", lib[a - 1]);

//     return 0;
// }

// #include <stdio.h>
// #define LAST_DIGIT 3

// int main(void) {
//     int a;
//     if (scanf("%d", &a) != 1) {
//         printf("Input error.");
//         return 0;
//     }

//     char res = a % 10 == LAST_DIGIT;

//     printf("%s", res ? "yes" : "no");

//     return 0;
// }

// #include <stdio.h>

// int main(void) {
//     int a, b, c;
//     if (scanf("%d %d %d", &a, &b, &c) != 3) {
//         printf("Input error.");
//         return 0;
//     }

//     int res = (b * b) - (4 * a * c);

//     if (res < 0)
//         printf("%d", res);
//     else
//         printf("real roots exist");

//     return 0;
// }

#include <stdio.h>

int main(void) {
    double a, b, c;
    if (scanf("%lf, %lf, %lf", &a, &b, &c) != 3) {
        printf("Input error.");
        return 0;
    }

    char res = (a < b + c) && (b < c + a) && (c < b + a);

    printf("%s", res ? "yes" : "no");

    return 0;
}