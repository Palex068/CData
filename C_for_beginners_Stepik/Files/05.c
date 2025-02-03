#include <stdio.h>

typedef struct {
    int h;    // часы
    int min;  // минуты (от 0 до 59)
} TicTac;

void printTic(TicTac a);

// получает показание часов a и возвращает показание этих часов
// через min минут, .
TicTac after(TicTac a, int min) {
    TicTac result;
    result.min = (a.min + min) % 60;
    result.h = (a.h + (a.min + min) / 60) % 12;
    return result;
}

// "переводит" вперед стрелки этих часов (me)
// на a.h часов и a.min минут
void forward(TicTac* me, TicTac a) {
    me->h = (me->h + a.h + (me->min + a.min) / 60) % 12;
    me->min = (me->min + a.min) % 60;
}

// "переводит" назад стрелки этих часов (me)
// на a.h часов и a.min минут
void backward(TicTac* me, TicTac a) {
    int min = (me->min - a.min) < 0 ? -1 : 0;
    me->h = (12 + me->h - a.h + min) % 12;
    me->min = (60 + me->min - a.min) % 60;
}

// проверяет совпадают ли показания часов a и b
// если совпадают, возвращает 1, если нет - 0
int isEqualTime(TicTac a, TicTac b) {
    if (a.h == b.h && a.min == b.min) return 1;
    return 0;
}

// печатает показания этих часов в формате hh:mm\n
void printTic(TicTac a) { printf("%02d:%02d\n", a.h, a.min); }

int main() {
    TicTac a, b, c;
    int mk;

    scanf("%d:%d", &(a.h), &(a.min));
    scanf("%d", &mk);
    scanf("%d:%d", &(b.h), &(b.min));

    printf("equal: %d\n", isEqualTime(a, b));
    c = after(a, mk);
    printf("after: ");
    printTic(c);

    c = a;
    printf("forward: ");
    forward(&a, b);
    printTic(a);

    printf("backward: ");
    backward(&c, b);
    printTic(c);

    return 0;
}