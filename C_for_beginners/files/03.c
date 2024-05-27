// #include <stdio.h>

// int main() {
//     int nday;
//     int days;
//     int count;
//     int weekd;

//     scanf("%d %d", &days, &nday);
//     // количество понедельников
//     count = (days - nday) / 7;

//     // какой день недели в последний день месяца
//     weekd = (days - nday - count * 7) % 7 + 1;

//     printf("%d\n", weekd);
//     return 0;
// }

// #include <stdio.h>

// int main() {
//     unsigned int K;
//     unsigned int M;
//     unsigned int B;
//     unsigned int fact;
//     unsigned int pay;
//     scanf("%u", &K);
//     scanf("%u", &M);
//     scanf("%u", &B);
//     scanf("%u", &fact);

//     pay = !!(fact / (K + 1)) * B + fact * M;
//     printf("%u\n", pay);
// }

#include <stdio.h>
#include <stdlib.h>

int main() {
    char a, b, res;
    scanf("%c %c", &a, &b);
    int factor = !((5 + b - a) / 5);
    char delt = b - a;
    res = delt * !factor + (5 - delt) * factor - 1;
    printf("%d\n", res);
    return 0;
}