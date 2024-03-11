// #include <stdio.h>

// void print_bin(int x) {
//     int result = 0, n = 1;
//     while (x > 0) {
//         result += (x % 2) * n;
//         x /= 2;
//         n *= 10;
//     }
//     printf("%08d", result);
// }

// int main() {
//     int x;
//     scanf("%d", &x);  // hh используеся для указания, что работа с char

//     print_bin(x);  // напечатать х и в конце напечатать \n

//     return 0;
// }

// #include <math.h>
// #include <stdio.h>

// int main() {
//     for (int r = 0, n, i = (scanf("%d", &n), 8); n || (printf("%08d", r), 0);
//          r += (n % 2) * pow(10, 8 - i), n /= 2, i--)
//         ;
//     return 0;
// }

// #include <math.h>
// #include <stdio.h>

// #define GENDER 1

// int main() {
//     unsigned int x;
//     scanf("%x", &x);
//     if ((x & GENDER) == 1)
//         printf("ma\n");  // мужчина
//     else
//         printf("fe\n");  // женщина
//     return 0;
// }

// #include <math.h>
// #include <stdio.h>

// #define GENDER 1
// #define CLEVER (1 << 1)
// #define HAT (1 << 2)
// #define TROUSES (1 << 3)

// int main() {
//     unsigned int x;
//     scanf("%x", &x);
//     if ((x & HAT) == HAT)
//         printf("ha\n");  // носит шляпу
//     else
//         printf("nh\n");  // не носит шляпу
// }

// #include <stdio.h>

// int main() {
//     unsigned int x;
//     scanf("%x", &x);
//     char * answer[] = {"bn", "rd", "bw", "bk"};
//     printf("%s", answer[(x >> 4) & 3]);
// }

// #include <stdio.h>

// int main() {
//     unsigned int x;
//     scanf("%x", &x);

//     char* matrix[6][4] = {{"fe", "ma"},
//                           {"du", "cl"},
//                           {"nh", "ha"},
//                           {"sk", "tr"},
//                           {"bn", "rd", "bw", "bk"},
//                           {"bu", "ge", "gy", "da"}};
//     for (unsigned int i = 0; i < 4; i++) {
//         printf("%s ", matrix[i][(x >> i) & 1]);
//     }
//     printf("%s ", matrix[4][((x >> 4) & 3)]);
//     printf("%s ", matrix[5][((x >> 6) & 3)]);
// }

// #include <stdio.h>

// int main() {
//     unsigned int all[3];
//     for (int i = 0; i < 3; i++) {
//         scanf("%1o", &all[i]);
//     }
//     char *rwx[] = {"r", "w", "x", "-"};
//     for (int i = 0; i < 3; i++) {
//         for (int j = 0; j < 3; j++) {
//             int res = (all[i] >> (2 - j)) & 1;
//             printf("%s", res ? rwx[j] : rwx[3]);
//         }
//     }
// }

// #include <stdio.h>
// #include <string.h>

// struct Man {
//     char str[3];
//     unsigned int volume;
//     unsigned int mask;
// };

// void print_bin(int x) {
//     int result = 0, n = 1;
//     while (x > 0) {
//         result += (x % 2) * n;
//         x /= 2;
//         n *= 10;
//     }
//     printf("%08d", result);
// }

// int main() {
//     unsigned int x = 0;
//     char character[3];

//     struct Man dict[] = {{"fe", 0, 1},  {"ma", 1, 1},  {"du", 0, 2},   {"cl", 1, 2},
//                          {"nh", 0, 4},  {"ha", 1, 4},  {"sk", 0, 8},   {"tr", 1, 8},
//                          {"bn", 0, 16}, {"rd", 1, 16}, {"bw", 1, 32},  {"bk", 2, 16},
//                          {"bu", 0, 64}, {"ge", 1, 64}, {"gy", 1, 128}, {"da", 2, 64}};

//     while (1 == scanf("%2s", character)) {
//         for (int i = 0; i < 16; i++) {
//             int cmp = strcmp(dict[i].str, character);
//             if (cmp == 0) {
//                 unsigned int volume = dict[i].volume;
//                 unsigned int mask = dict[i].mask;
//                 if (volume == 1) {
//                     x = x | mask;
//                 } else if (volume == 2) {
//                     x = x | mask;
//                     x = x | (mask * 2);
//                 } else {
//                     x = x & ~mask;
//                 }
//             }
//         }
//         printf("%02x ", x);
//         print_bin(x);
//         printf("\n");
//     }

//     return 0;
// }
#include <math.h>
#include <stdio.h>
#include <string.h>

#define LEN 8
#define MAX 6

int main() {
    int input[MAX][LEN] = {0}, x, counter = 0;

    while (1 == scanf("%d", &x)) {
        int result = 0, n = 1;
        while (x > 0) {
            result += (x % 2) * n;
            x /= 2;
            n *= 10;
        }
        int bit[3] = {0};
        for (int i = 2; i >= 0; i--) {
            bit[i] = result % 10;
            result /= 10;
        }
        for (int i = 0; i < 3; i++) {
            int m = counter % LEN;
            int n = counter - LEN * m;
            input[m][n] = bit[i];
            counter++;
        }
    }
    // печать массива
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < LEN; j++) {
            printf("%d", input[i][j]);
        }
        printf("\n");
    }

    // печать десятичных байтовых чисел
    for (int i = 0; i < MAX; i++) {
        int number = 0;
        for (int j = 0; j < LEN; j++) {
            number += input[i][j] * pow(2, LEN - j - 1);
        }
        if (counter > 0) {
            printf("%d ", number);
            counter -= 8;
        }
    }
    return 0;
}