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

// #include <stdio.h>

// int main(void) {
//     double a, b, c;
//     if (scanf("%lf, %lf, %lf", &a, &b, &c) != 3) {
//         printf("Input error.");
//         return 0;
//     }

//     char res = (a < b + c) && (b < c + a) && (c < b + a);

//     printf("%s", res ? "yes" : "no");

//     return 0;
// }

// #include <stdio.h>

// int main(void) {
//     int k, m;
//     if (scanf("%d, %d", &k, &m) != 2) {
//         printf("Input error.");
//         return 0;
//     }

//     int min = k < m ? k : m;

//     printf("%d", min * min);

//     return 0;
// }

// #include <stdio.h>

// int main(void) {
//     int x;
//     if (scanf("%d", &x) != 1) {
//         printf("Input error.");
//         return 0;
//     }

//     int res = x > 0 ? x : 0;

//     printf("%d", res);

//     return 0;
// }

// #include <stdio.h>

// int main(void) {
//     int a, b;
//     if (scanf("%d; %d", &a, &b) != 2) {
//         printf("Input error.");
//         return 0;
//     }

//     int res = a == b;

//     printf("%s", res ? "square" : "rectangle");

//     return 0;
// }
// #include <stdio.h>

// int main(void) {
//     int width, height;
//     if (scanf("%d %d", &width, &height) != 2) {
//         printf("Input error.");
//         return 0;
//     }

//     int border = (width > height ? width : height) + 8;

//     printf("%d", border);

//     return 0;
// }

// #include <stdio.h>

// int main(void) {
//     short type = 0;
//     double w, h;

//     if (scanf("%hd %lf %lf", &type, &w, &h) != 3) {
//         printf("Input error.");
//         return 0;
//     }
//     switch (type) {
//         case 1:
//             printf("%.1lf", w * h);
//             break;
//         case 2:
//             printf("%.1lf", 2 * (w + h));
//             break;
//         default:
//             printf("-1");
//             break;
//     }

//     return 0;
// }

// int main(void) {
//     double a, b, c;
//     if (scanf("%lf, %lf, %lf", &a, &b, &c) != 3) {
//         printf("Input error.");
//         return 0;
//     }

//     // char res = (a < b + c) && (b < c + a) && (c < b + a);
//     char res = (a < b + c) ? (b < c + a) ? (c < b + a) ? 1 : 0 : 0 : 0;

//     printf("%s", res ? "yes" : "no");

//     return 0;
// }

// int main(void) {
//     double a, b, h;
//     if (scanf("%lf, %lf, %lf", &a, &b, &h) != 3) {
//         printf("Input error.");
//         return 0;
//     }

//     double res = h * (a + b) / 2;

//     printf("%.1lf", res);

//     return 0;
// }

// #include <stdio.h>

// int main(void) {
//     char symbol;
//     if (scanf("%c", &symbol) != 1) {
//         printf("Input error.");
//         return 0;
//     }

//     // switch (symbol) {
//     //     case 'a':
//     //         symbol = 'A';
//     //         break;
//     //     case 'b':
//     //         symbol = 'B';
//     //         break;
//     //     case 'c':
//     //         symbol = 'C';
//     //         break;
//     //     case 'd':
//     //         symbol = 'D';
//     //         break;
//     //     case 'e':
//     //         symbol = 'E';
//     //         break;
//     //     case 'f':
//     //         symbol = 'F';
//     //         break;

//     //     default:
//     //         return 0;
//     // }

//     if (symbol >= 'a' && symbol <= 'f') {
//         symbol += 'A' - 'a';
//     } else
//         return 0;

//     printf("%c", symbol);

//     return 0;
// }

// #include <stdio.h>

// int main(void) {
//     char menu_item;
//     short menu_number = 0;

//     printf(
//         "a) learning english\n
// b) learning C/C++\n
// c) learning mathematic\n
// d) learning Python\n");

//     if (scanf("%c", &menu_item) != 1) {
//         printf("Input error.");
//         return 0;
//     }

//     if (menu_item >= 'a' && menu_item <= 'd') {
//         menu_number = 1 + menu_item - 'a';
//     } else if (menu_item >= 'A' && menu_item <= 'D') {
//         menu_number = 1 + menu_item - 'A';
//     } else
//         menu_number = -1;

//     // switch(menu_item){
//     // case 'a':
//     // case 'A':menu_number = 1; break;
//     // case 'b':
//     // case 'B':menu_number = 2; break;
//     // case 'c':
//     // case 'C':menu_number = 3; break;
//     // case 'd':
//     // case 'D':menu_number = 4; break;
//     // default: menu_number = -1; break;
//     // }

//     printf("%d", menu_number);
//     return 0;
// }

// #include <stdio.h>

// int show_menu(void) {
//     char menu_item;

//     printf(
//         "a) learning english\n
// b) learning C/C++\n
// c) learning mathematic\n
// d) learning Python\n");

//     if (scanf("%c", &menu_item) != 1) {
//         printf("Input error.");
//         return -1;
//     }
//     switch (menu_item) {
//         case 'a':
//         case 'A':
//             return 1;
//         case 'b':
//         case 'B':
//             return 2;
//         case 'c':
//         case 'C':
//             return 3;
//         case 'd':
//         case 'D':
//             return 4;
//     }

//     return -1;
// }

// int main(void) {
//     int item = show_menu();

//     printf("%d", item);

//     return 0;
// }

// #include <stdio.h>
// #define DELIT 1000
// #define FIRST_DIGIT 3

// int main(void) {
//     int num;
//     if (scanf("%d", &num) != 1) {
//         printf("Input error.");
//         return 0;
//     }

//     char res = num / DELIT == FIRST_DIGIT;

//     printf("%s", res ? "yes" : "no");

//     return 0;
// }

// #include <stdio.h>

// int main(void) {
//     unsigned char b, not_b;
//     scanf("%hhu", &b);

//     not_b = ~b;

//     printf("%hhu", not_b);

//     return 0;
// }

// #include <stdio.h>

// int main(void) {
//     unsigned char bits;
//     scanf("%hhu", &bits);

//     if ((bits & 40) == 40) {
//         printf("%hhu", bits);
//     } else {
//         printf("-1");
//     }

//     return 0;
// }

// #include <stdio.h>

// int main(void) {
//     unsigned char bits, res;
//     scanf("%hhu", &bits);

//     res = bits & ~192;

//     printf("%hhu", res);

//     return 0;
// }

// #include <stdio.h>

// int main(void) {
//     unsigned char bits, res;
//     scanf("%hhu", &bits);

//     res = bits | 21;

//     printf("%hhu", res);

//     return 0;
// }

// #include <stdio.h>

// int main(void) {
//     unsigned char bits, res;
//     scanf("%hhu", &bits);

//     res = bits ^ 9;

//     printf("%hhu", res);

//     return 0;
// }

// #include <stdio.h>

// int main(void) {
//     unsigned int bits, res;
//     scanf("%u", &bits);

//     res = bits >> 2;

//     printf("%u", res);

//     return 0;
// }

// #include <stdio.h>

// int main(void) {
//     unsigned int a, b, res;
//     scanf("%u %u", &a, &b);

//     res = (a >> 1) * (b >> 1);

//     printf("%u", res);

//     return 0;
// }

// #include <stdio.h>

// int main(void) {
//     unsigned int flags, mask;

//     scanf("%u %u", &flags, &mask);

//     char res = (flags & mask) == mask;

//     printf("%s", res ? "yes" : "no");

//     return 0;
// }

#include <stdio.h>

// void print_byte(unsigned int byte) {
//     const char *bit_rep[16] = {
//         [0] = "0000",  [1] = "0001",  [2] = "0010",  [3] = "0011",  [4] = "0100",  [5] = "0101",
//         [6] = "0110",  [7] = "0111",  [8] = "1000",  [9] = "1001",  [10] = "1010", [11] = "1011",
//         [12] = "1100", [13] = "1101", [14] = "1110", [15] = "1111",
//     };
//     printf("%s%s\n", bit_rep[byte >> 4], bit_rep[byte & 0x0F]);
// }

// int main(void) {
//     unsigned int flags, mask, res;

//     scanf("%u %u", &flags, &mask);

//     res = flags & mask;
//     // print_byte(flags);
//     // print_byte(mask);
//     // print_byte(res);

//     printf("%s", res ? "yes" : "no");

//     return 0;
// }

// #include <stdio.h>
// #include <stdlib.h>
// #define DIGITS 4

// int main(void) {
//     int nums[DIGITS];

//     for (int i = 0; i < DIGITS; i++) {
//         nums[i] = rand();
//     }
//     for (int i = 0; i < DIGITS; i++) {
//         printf("%d%s", nums[i], i != DIGITS - 1 ? " " : "");
//     }

//     return 0;
// }

// #include <stdio.h>
// #include <stdlib.h>
// #define DIGITS 7

// int main(void) {
//     int nums[DIGITS];
//     int N;
//     scanf("%d", &N);

//     for (int i = 0; i < DIGITS; i++) {
//         nums[i] = rand() % (N + 1);
//     }
//     for (int i = 0; i < DIGITS; i++) {
//         printf("%d%s", nums[i], i != DIGITS - 1 ? " " : "");
//     }

//     return 0;
// }

// #include <stdio.h>
// #include <stdlib.h>
// #define DIGITS 10
// #define RAND_MAX 32767

// int main(void) {
//     double nums[DIGITS];
//     int a, b;
//     scanf("%d %d", &a, &b);

//     for (int i = 0; i < DIGITS; i++) {
//         nums[i] = (rand() / (double)RAND_MAX) * (b - a) + a;
//     }
//     for (int i = 0; i < DIGITS; i++) {
//         printf("%.2lf%s", nums[i], i != DIGITS - 1 ? " " : "");
//     }

//     return 0;
// }

// #include <stdio.h>
// #include <stdlib.h>
// #include <time.h>

// int main(void) {
//     srand(time(NULL));
//     int r1, r2, r3, r4, r5;

//     r1 = rand();
//     r2 = rand();
//     r3 = rand();
//     r4 = rand();
//     r5 = rand();

//     return 0;
// }

// #include <math.h>
// #include <stdio.h>

// int main(void) {
//     unsigned short N;
//     scanf("%hu", &N);

//     int res = ceil(N * 7 / 100.0);
//     printf("%d", res);
//     return 0;
// }

// #include <stdio.h>

// int main(void) {
//     unsigned short N;
//     scanf("%hu", &N);

//     int res = round(N * 2.54);
//     printf("%d", res);

//     return 0;
// }

// #include <math.h>
// #include <stdio.h>

// #define PI 3.1415

// int main(void) {
//     double grad;
//     scanf("%lf", &grad);

//     double res = sin(grad * PI / 180);
//     printf("%.1lf", res);

//     return 0;
// }

#include <math.h>
#include <stdio.h>

#define PI 3.1415

int main(void) {
    int a, b;
    scanf("%d, %d", &a, &b);

    double tan = a / (double)b;
    double res = atan(tan);

    printf("%.2lf %.2lf", tan, res);

    return 0;
}
