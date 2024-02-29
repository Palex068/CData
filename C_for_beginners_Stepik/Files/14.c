// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// #define N 1000

// char* replace(const char* src) {
//     const char* from = "bomb";
//     const char* to = "watermelon";

//     size_t len = strlen(from);

//     char *p, *s, *dst;
//     dst = malloc(strlen(src) * 3);
//     dst[0] = '\0';
//     p = (char*)src;
//     while (NULL != (s = strstr(p, from))) {
//         strncat(dst, p, s - p);
//         strcat(dst, to);
//         p = s + len;
//     }
//     strcat(dst, p);
//     return dst;
// }

// int main() {
//     char s[N];  // нужно объявить переменную - место для читаемой строки
//     char* d;  // указатель на динамический массив, память еще не выделена

//     while (NULL != fgets(s, N, stdin)) {  // пока можем прочитать строку
//         d = replace(s);                   // тут память выделяем
//         printf("+++%s+++\n", d);
//         free(d);  // тут память освобождаем
//     }
//     return 0;
// }

// #include <stdio.h>
// #include <stdlib.h>

// #define N 100
// typedef struct {
//     char* a;            // number is a[0]*10^0 + a[1]*10^1 + ..+ a[n]*10^n
//     unsigned int n;     // наибольшая степень десяти
//     unsigned int size;  // размер выделенной динамической памяти в а
// } Decimal;

// void elong_add(const Decimal* a, const Decimal* b, Decimal* res) {
//     if (a->n == 0 && a->a[0] == 0 && b->a[0] == 0 && b->n == 0) {  // 0*10**0
//         res->size = 1;
//         res->n = 0;
//         res->a = malloc(res->size);
//         res->a[0] = 0;
//         return;
//     }

//     res->size = 101;
//     res->a = malloc(res->size);

//     unsigned int over = 0, n;

//     n = (a->n >= b->n ? a->n : b->n);

//     for (unsigned int i = 0; i <= n + 1; i++) {
//         unsigned int result = (i <= a->n ? a->a[i] : 0) + (i <= b->n ? b->a[i] : 0) + over;
//         res->a[i] = result % 10;
//         over = result / 10;
//     }
//     res->n = n + res->a[n + 1];
//     res->size = res->n + 1;
//     res->a = realloc(res->a, res->size);
// }

// void elong_set_int(Decimal* px, unsigned int number) {
//     if (number == 0) {  // 0*10**0
//         px->size = 1;
//         px->n = 0;
//         px->a = malloc(px->size);
//         px->a[0] = 0;
//         return;
//     }

//     // number точно меньше 10 в 100, выделим память с запасом
//     px->size = 100;
//     px->a = malloc(px->size);

//     for (px->n = 0; number > 0; px->n++) {
//         px->a[px->n] = number % 10;
//         number /= 10;
//     }
//     px->n--;

//     // выделим памяти точно под хранение числа
//     px->size = px->n + 1;
//     px->a = realloc(px->a, px->size);
// }

// void elong_destroy(Decimal* px) {
//     free(px->a);  // освобождаем желтый массив с цифрами
// }

// void elong_print(Decimal x) {
//     for (unsigned int i = 0; i <= x.n; i++) {
//         printf("%d", x.a[x.n - i]);
//     }
// }

// int main() {
//     Decimal a;
//     Decimal b;
//     Decimal res;

//     elong_set_int(&a, 999);  // 147
//     elong_set_int(&b, 1);    // 13

//     elong_add(&a, &b, &res);  // res = a+b = 147+13 = 160

//     elong_print(res);  // print 160

//     elong_destroy(&a);
//     elong_destroy(&b);
//     elong_destroy(&res);

//     return 0;
// }

// #include <stdio.h>
// #include <stdlib.h>

// #define N 100
// typedef struct {
//     char* a;            // number is a[0]*10^0 + a[1]*10^1 + ..+ a[n]*10^n
//     unsigned int n;     // наибольшая степень десяти
//     unsigned int size;  // размер выделенной динамической памяти в а
// } Decimal;

// Decimal* elong_add(const Decimal* a, const Decimal* b) {
//     Decimal* res = malloc(sizeof(Decimal));

//     if (a->n == 0 && a->a[0] == 0 && b->a[0] == 0 && b->n == 0) {  // 0*10**0
//         res->size = 1;
//         res->n = 0;
//         res->a = malloc(res->size);
//         res->a[0] = 0;
//         return res;
//     }

//     res->size = 101;
//     res->a = malloc(res->size);

//     unsigned int over = 0, n;

//     n = (a->n >= b->n ? a->n : b->n);

//     for (unsigned int i = 0; i <= n + 1; i++) {
//         unsigned int result = (i <= a->n ? a->a[i] : 0) + (i <= b->n ? b->a[i] : 0) + over;
//         res->a[i] = result % 10;
//         over = result / 10;
//     }
//     res->n = n + res->a[n + 1];
//     res->size = res->n + 1;
//     res->a = realloc(res->a, res->size);
//     return res;
// }

// Decimal* elong_set_int(unsigned int number) {
//     // сначала выделим память под саму структуру (фиолетовый прямоугольник)
//     Decimal* px = malloc(sizeof(Decimal));

//     if (number == 0) {  // 0*10**0
//         px->size = 1;
//         px->n = 0;
//         px->a = malloc(px->size);
//         px->a[0] = 0;
//         return px;
//     }

//     // number точно меньше 10 в 100, выделим память с запасом
//     px->size = 100;
//     px->a = malloc(px->size);

//     for (px->n = 0; number > 0; px->n++) {
//         px->a[px->n] = number % 10;
//         number /= 10;
//     }
//     px->n--;

//     // выделим памяти точно под хранение числа
//     px->size = px->n + 1;
//     px->a = realloc(px->a, px->size);
//     return px;
// }

// void elong_destroy(Decimal* px) {
//     free(px->a);  // освобождаем желтый массив с цифрами
//     free(px);  // освобождаем фиолетовый прямогольник, саму структуру
// }

// void elong_print(const Decimal* x) {
//     for (unsigned int i = 0; i <= x->n; i++) {
//         printf("%d", x->a[x->n - i]);
//     }
// }

// int main() {
//     Decimal* a;
//     Decimal* b;
//     Decimal* res;

//     a = elong_set_int(147);  // 147
//     b = elong_set_int(13);   // 13

//     res = elong_add(a, b);  // res = a+b = 147+13 = 160

//     elong_print(res);  // print 160

//     elong_destroy(a);
//     elong_destroy(b);
//     elong_destroy(res);

//     return 0;
// }

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 101

typedef struct {
    char* dig;  // массив для хранения числа:
                // a[0] * 100^0 + a[1] * 100^1 + .. + a[n - 1] * 100^(n-1)
    int n;      // размер числа в разрядах
    char sign;  // для положительных чисел и нуля, знак sign записывается как 0, для отрицательных - как 1
} LongN;

LongN* getLongN(char* s) {
    // сначала выделим память под саму структуру (фиолетовый прямоугольник)
    LongN* px = malloc(sizeof(LongN));

    px->sign = 0;

    if (s[0] == '0') {  // 0*10**0
        px->n = 0;
        px->dig = malloc(px->n + 1);
        px->dig[0] = 0;
        return px;
    }

    if (s[0] == '-') {
        px->sign = 1;
    }
    int len = strlen(s) - 1;
    int digits[N * 2] = {0};
    for (int i = 0; i <= len - px->sign; i++) {
        digits[i] = (s[len - i] - '0');
    }

    px->n = len - px->sign;
    px->dig = malloc(px->n);
    int j = 0;
    for (int i = 0; i <= len; i += 2, j++) {
        px->dig[j] = digits[i] + (i == len ? 0 : digits[i + 1]) * 10;
    }
    px->n = j - 1;
    // выделим памяти точно под хранение числа
    px->dig = realloc(px->dig, j);
    return px;
}

void longN_destroy(LongN* px) {
    free(px->dig);  // освобождаем желтый массив с цифрами
    free(px);  // освобождаем фиолетовый прямогольник, саму структуру
}

void longN_print(const LongN* x) {
    printf("%s", x->sign ? "- " : "");

    for (int i = 0; i <= x->n; i++) {
        printf("%d ", x->dig[x->n - i]);
        // printf("\n");
    }
}

int main() {
    LongN* a;
    LongN* b;
    LongN* c;

    a = getLongN("0");           // res = 0
    b = getLongN("123456789");   // res = 0
    c = getLongN("-123456789");  // res = 0

    longN_print(a);  // print 0
    printf("\n");
    longN_print(b);  // print 0
    printf("\n");
    longN_print(c);  // print 0
    printf("\n");

    longN_destroy(a);
    longN_destroy(b);
    longN_destroy(c);

    return 0;
}
