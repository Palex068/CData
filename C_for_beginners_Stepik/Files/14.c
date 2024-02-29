#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 1000

char* replace(const char* src) {
    const char* from = "bomb";
    const char* to = "watermelon";

    size_t len = strlen(from);

    char *p, *s, *dst;
    dst = malloc(strlen(src) * 3);
    dst[0] = '\0';
    p = (char*)src;
    while (NULL != (s = strstr(p, from))) {
        strncat(dst, p, s - p);
        strcat(dst, to);
        p = s + len;
    }
    strcat(dst, p);
    return dst;
}

int main() {
    char s[N];  // нужно объявить переменную - место для читаемой строки
    char* d;  // указатель на динамический массив, память еще не выделена

    while (NULL != fgets(s, N, stdin)) {  // пока можем прочитать строку
        d = replace(s);                   // тут память выделяем
        printf("+++%s+++\n", d);
        free(d);  // тут память освобождаем
    }
    return 0;
}