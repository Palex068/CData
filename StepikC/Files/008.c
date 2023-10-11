#include <stdio.h>
#include <conio.h>
// #include <locale.h>
// #include <math.h> // подключаем math.h

int main() {
    int N; scanf("%d", &N);
    int digits[N], revers[N], temp, i, j;

    for (i = 0; i < N; i++) scanf("%d", &digits[i]);
    for (i = 0; i < N; i++) revers[N - 1 - i] = digits[i];
    for (i = 0; i < N; i++) printf("%d%s", digits[i], i == N - 1 ? "" : " ");
    
    getch();  
    return 0;
}