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

#include <math.h>
#include <stdio.h>

int main() {
    for (int r = 0, n, i = (scanf("%d", &n), 8); n || (printf("%08d", r), 0);
         r += (n % 2) * pow(10, 8 - i), n /= 2, i--)
        ;
    return 0;
}
