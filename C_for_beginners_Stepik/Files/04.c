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

int nod(int a, int b) {
    if (b == 0) return a;
    return nod(b, a % b);
}

int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%d", nod(a, b));
    return 0;
}