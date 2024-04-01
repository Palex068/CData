// #include <stdio.h>

// int main(void) {
//     int count = 0;
//     int s = 0;

//     while (count++ <= 5) s += count;

//     printf("%d", s);

//     return 0;
// }

// #include <stdio.h>

// int main(void) {
//     int x;

//     while (scanf("%d", &x) == 1 && x != 0) printf("%d ", x * x);

//     return 0;
// }
// #include <stdio.h>

// int main(void) {
//     int x;
//     double sum;

//     scanf("%d", &x);

//     while (x > 0) {
//         sum += 1.0 / (x * x);
//         x--;
//     }

//     printf("%.3lf", sum);

//     return 0;
// }

// #include <stdio.h>

// int main(void) {
//     int x, sum;

//     scanf("%d", &x);

//     while (x > 0) {
//         sum += x % 10;
//         x /= 10;
//     }

//     printf("%d", sum);

//     return 0;
// }

// #include <stdio.h>

// int main() {
//     int x, num0 = 0, num1 = 1, num = 1, counter = 0;

//     scanf("%d", &x);

//     while (counter != x) {
//         printf("%d ", num);
//         num = num0 + num1;
//         num0 = num1;
//         num1 = num;
//         counter++;
//     }

//     return 0;
// }

// #include <stdio.h>

// int main() {
//     int n, m;

//     scanf("%d %d", &n, &m);

//     while (n <= m) {
//         if (n % 3 == 0) printf("%d ", n);
//         n++;
//     }

//     return 0;
// }

// #include <stdio.h>
// #define LEFT 100
// #define RIGHT 999

// int main() {
//     int n = LEFT;

//     while (n <= RIGHT) {
//         if (n % 47 == 6 || n % 53 == 45) printf("%d ", n);
//         n++;
//     }

//     return 0;
// }

// #include <math.h>
// #include <stdio.h>

// int main() {
//     int count = 0, n;

//     scanf("%d", &n);

//     // посчитаем количество знаков в числе
//     int ncopy = n;

//     while (ncopy > 0) {
//         ncopy /= 10;
//         count++;
//     }

//     count--;

//     char res = 1;

//     while (n >= 10) {
//         // вычислим первую и последнюю цифры и сравним их
//         int a = n / pow(10, count);
//         int b = n % 10;
//         // printf("%d %d\n", a, b); // проверочная печать
//         if (a != b) {  // если не равны выходим из цикла с res = 0
//             res = 0;
//             break;
//         }
//         // откидываем от n первую и последнюю цифры
//         n -= a * pow(10, count);
//         n /= 10;
//         // printf("%d\n", n); // проверочная печать
//         // уменьшаем счетчик знаков
//         count -= 2;
//     }
//     // печатаем через тернарный оператор ответ
//     printf("%s", res ? "yes" : "no");

//     return 0;
// }

#include <stdio.h>

int main() {
    int a, b;

    scanf("%d %d", &a, &b);

    while (b > 0) {
        if (a > b) {
            int tmp = a;
            a = b;
            b = tmp;
        }
        b %= a;
    }

    printf("%d", a);
    return 0;
}
