// #include <stdio.h>

// int x; // неявная инициализация

// void foo() { x = x + 1; }

// int main()
// {
//     foo();
//     foo();
//     printf("%d\n", x);
//     return 0;
// }

// #include <stdio.h>

// void foo() {
//   static int x; // неявная инициализация
//   x = x + 1;
//   printf("%d ", x);
// }

// int main() {
//   foo();
//   foo();
//   return 0;
// }

// #include <stdio.h>

// void foo() {
//     static int x = 2;  // явная инициализация
//     x = x + 1;
//     printf("%d ", x);
// }

// int main() {
//     foo();
//     foo();
//     return 0;
// }

#include <stdio.h>

// int nod(int a, int b) {
//     if (a == b)
//         return b;
//     else {
//         if (a > b)
//             return nod(a - b, b);
//         else
//             return nod(a, b - a);
//     }
// }

// int nod(int a, int b) {
//     if (b == 0) return a;
//     return nod(b, a % b);
// }

// int main() {
//     int a, b;
//     scanf("%d %d", &a, &b);
//     printf("%d", nod(a, b));
//     return 0;
// }

// int ipow(int a, int n, int* depth) {
//     if (n <= 1) {
//         *depth = 1;
//         return (n && a) ? a : 1;  // если n = 1 то return a, n=0, то 1
//     } else if (n % 2 == 0) {
//         int res = ipow(a, n / 2, depth);
//         (*depth)++;
//         return res * res;  // НЕ надо дважды вычислять ipow(a,n/2,depth), надо запомнить вычисленный
//         результат
//     } else {
//         int res = ipow(a, n - 1, depth);
//         (*depth)++;
//         return a * res;
//     }
// }

// int main() {
//     int a, b, d;
//     scanf("%d %d", &a, &b);
//     printf("%d ", ipow(a, b, &d));
//     printf("%d", d);

//     return 0;
// }

int is_prime(unsigned int a) {
    for (unsigned int i = 2; i < a / 2 + 1; i++) {
        if (a % i == 0) {
            return 0;
        }
    }
    return 1;
}

void simpleFactors(unsigned int a, unsigned int last, unsigned int n) {
    for (unsigned int i = a; i >= last; i--) {
        if (is_prime(i)) {
            n = 0;
            while (a % i == 0 && a > 1) {
                n++;
                a /= i;
            }
            if (n == 0) continue;
            if (n == 1) printf("%d ", i);
            if (n > 1) printf("%d^%d ", i, n);
        } else
            continue;
    }
}

int main() {
    unsigned int a;
    scanf("%u", &a);
    simpleFactors(a, 2, 0);

    return 0;
}