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

#include <stdio.h>

int main() {
    unsigned int all[3];
    for (int i = 0; i < 3; i++) {
        scanf("%1o", &all[i]);
    }
    char *rwx[] = {"r", "w", "x", "-"};
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int res = (all[i] >> (2 - j)) & 1;
            printf("%s", res ? rwx[j] : rwx[3]);
        }
    }
}