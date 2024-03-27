// #include <stdio.h>
// #define MAX 3

// int main(void) {
//     int input[MAX];
//     for (int i = 0; i < MAX; i++) {
//         input[i] = getchar();
//     }
//     for (int i = MAX - 1; i >= 0; i--) {
//         putchar(input[i]);
//     }
//     return 0;
// }

// #include <stdio.h>

// int main(void) {
//     char ch = 'u';
//     short sh = -55;
//     int var_i = 1024;
//     double var_d = 3.1415;

//     printf("%c %d %d %f", ch, sh, var_i, var_d);

//     return 0;
// }

// #include <stdio.h>

// int main(void) {
//     char byte = 65;
//     unsigned short height = 1055;
//     int distance = 1000000;
//     float pi = 3.1415f;

//     printf("%c\n%d\n%d\n%f", byte, height, distance, pi);

//     return 0;
// }

// #include <stdio.h>

// int main(void) {
//     unsigned height = 12345012;
//     long long dist = 1234567890LL;
//     long double weight = 45.7845;

//     printf("%d %lld %.4Lf", height, dist, weight);

//     return 0;
// }

// #include <stdio.h>

// int main(void) {
//     int a1 = -123, a2 = 6, a3 = 1024;

//     printf("[%5d]\n[%5d]\n[%5d]", a1, a2, a3);

//     return 0;
// }

// #include <stdio.h>

// int main(void) {
//     double d = 546e-3;

//     printf("%.3lf", d);

//     return 0;
// }

// #include <stdio.h>

// int main(void) {
//     unsigned char h = 11, m = 8, s = 1;

//     printf("%02d:%02d:%02d", h, m, s);

//     return 0;
// }

// #include <stdio.h>

// int main(void) {
//     unsigned char h = 17, m = 45, s = 5;

//     printf("%#04x:%#04x:%#04x", h, m, s);

//     return 0;
// }

// #include <stdio.h>

// int main(void) {
//     char m, n;

//     int res = scanf("%c%c", &m, &n);

//     printf("res = %d, m = %c, n = %c\n", res, m, n);

//     return 0;
// }

// #include <stdio.h>

// int main(void) {
//     int a;
//     short b;
//     float c;
//     double d;

//     scanf("%d %hd %f %lf", &a, &b, &c, &d);
//     printf("%d %hd %.2f %.2lf", a, b, c, d);

//     return 0;
// }

// #include <stdio.h>

// int main(void) {
//     int a, b;

//     scanf("%d; %d", &a, &b);
//     printf("%d %d", a, b);

//     return 0;
// }

// #include <stdio.h>

// int main(void) {
//     int a, b;
//     float c;

//     scanf("%d, %d, %*f, %f", &a, &b, &c);
//     printf("%d %d %.2lf", a, b, c);

//     return 0;
// }

// #include <stdio.h>

// int main(void) {
//     int a;
//     float b, c;

//     scanf("%d %f %f", &a, &b, &c);
//     printf("%d %.2lf %.2lf", a, b, c);

//     return 0;
// }

// #include <stdio.h>

// int main(void) {
//     long long var_ll = 0;
//     long double var_ld = 0.;
//     short sh = 0;

//     scanf("%lld, %Lf, %hd", &var_ll, &var_ld, &sh);
//     printf("%lld %d", var_ll, sh);

//     return 0;
// }

// #include <stdio.h>
// #define MAX 10
// #define OUT 5

// int main(void) {
//     double temp[MAX] = {0};
//     for (int i = 0; i < MAX; i++) {
//         scanf("%lf%*c", &temp[i]);
//     }
//     for (int i = OUT; i < MAX; i++) {
//         printf("%0.1lf ", temp[i]);
//     }

//     return 0;
// }

// #include <stdio.h>

// int main(void) {
//     int a, b;

//     scanf("%d %d", &a, &b);
//     int tmp = a;
//     a = b;
//     b = tmp;

//     printf("%d %d", a, b);

//     return 0;
// }

// #include <math.h>
// #include <stdio.h>

// int main(void) {
//     double res = 6.0 * pow(1.0 / 3.0, 2) - 15.0 / 3.0;
//     printf("%.2lf", res);
//     return 0;
// }

// #include <stdio.h>

// int main(void) {
//     int h, w;
//     scanf("%d %d", &h, &w);

//     double res = (double)h / (double)w;
//     printf("%.2lf", res);

//     return 0;
// }

// #include <stdio.h>

// int main(void) {
//     int count = 0;
//     scanf("%d", &count);

//     printf("%d", count + 1);

//     return 0;
// }

// #include <stdio.h>

// int main(void) {
//     int total = 0;
//     scanf("%d", &total);

//     printf("%d", total - 2);

//     return 0;
// }

// #include <stdio.h>

// int main(void) {
//     int a1;   // первый член прогрессии
//     int a50;  // 50-й член прогрессии

//     scanf("%d, %d", &a1, &a50);

//     int res = (int)(a1 + a50) / 2.0 * 50;
//     printf("%d", res);
//     return 0;
// }

// #include <math.h>
// #include <stdio.h>

// int main(void) {
//     int b1;  // первый член прогрессии
//     int q;   // знаменатель прогрессии

//     scanf("%d, %d", &b1, &q);

//     int res = (int)(pow(q, 4) - 1) * b1 / (q - 1);
//     printf("%d", res);
//     return 0;
// }

// #include <math.h>
// #include <stdio.h>

// int main(void) {
//     int a;

//     scanf("%d", &a);

//     double res = sqrt(3.0) * a / 6;

//     printf("%.3lf", res);
//     return 0;
// }

// #include <stdio.h>
// #define PI 3.1415

// int main(void) {
//     double R;

//     scanf("%lf", &R);

//     double res = 2 * PI * R;

//     printf("%.3lf", res);
//     return 0;
// }

// #include <stdio.h>

// int main(void) {
//     int a, b, h;

//     scanf("%d, %d, %d", &a, &b, &h);

//     double res = (a + b) * h / 2.0;

//     printf("%.1lf", res);
//     return 0;
// }

// #include <stdio.h>

// int main(void) {
//     int angle;
//     scanf("%d", &angle);

//     int res = angle % 360;
//     printf("%d", res);
//     return 0;
// }

// #include <stdio.h>

// int main(void) {
//     int rect_width = 1280, rect_height = 720;
//     int w = 8, h = 8;
//     scanf("%d; %d", &w, &h);

//     int res_w = rect_width % w;
//     int res_h = rect_height % h;

//     printf("%d %d", res_w, res_h);

//     return 0;
// }

// #include <stdio.h>

// int main(void) {
//     unsigned short time_h = 10;  // часы
//     unsigned short time_m = 33;  // минуты
//     unsigned short time_s = 5;   // секунды

//     unsigned short h, m, s;  // добавляемое время: h - часы; m - минуты; s -
//     секунды scanf("%hu; %hu; %hu", &h, &m, &s);

//     int total_time = time_s + s + (time_m + m) * 60 + (time_h + h) * 3600;

//     unsigned short total_h = total_time / 3600;
//     unsigned short total_m = (total_time - total_h * 3600) / 60;
//     unsigned short total_s = total_time % 60;

//     printf("%02hu:%02hu:%02hu", total_h, total_m, total_s);

//     return 0;
// }

// #include <stdio.h>

// int main(void) {
//     double a;
//     scanf("%lf", &a);

//     printf("%.1lf", --a);
//     return 0;
// }

// #include <stdio.h>

// int main(void) {
//     int h, w;
//     scanf("%d, %d", &h, &w);

//     printf("%d", ++h * ++w);
//     return 0;
// }

// #include <stdio.h>

// int main(void) {
//     int rect_width = 640, rect_height = 480;
//     int w = 1, h = 1;
//     scanf("%d; %d", &w, &h);

//     int res = (rect_width / w) * (rect_height / h);
//     printf("%d", res);

//     return 0;
// }

// #include <stdio.h>

// int main(void) {
//     int a, b;
//     scanf("%d %d", &a, &b);

//     int res = (a *= 3) * (b -= 10);
//     printf("%d", res);

//     return 0;
// }

// #include <stdio.h>

// int main(void) {
//     double a, b;
//     scanf("%lf %lf", &a, &b);

//     double res = (a + b) * 2;
//     printf("Периметр: %.1lf", res);

//     return 0;
// }

// #include <stdio.h>

// int main(void) {
//     double s, m;
//     scanf("%lf %lf", &s, &m);

//     double res = s * (1 - m / 100.0) * 2;
//     printf("%.2lf", res);

//     return 0;
// }

#include <stdio.h>

int main(void) {
    int x;
    scanf("%d", &x);

    double res = x * 3600. / 1000.0;
    printf("%.1lf", res);

    return 0;
}