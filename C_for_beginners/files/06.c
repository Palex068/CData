// #include <stdio.h>
// #include <stdlib.h>

// typedef struct {
//     int h;    // часы
//     int min;  // минуты
// } Timer;

// // эта функция ничего не печатает!!!
// int isTimeCorrect(Timer a) {
//     // часы должны быть не менее 0 и не более 23
//     // а минуты - от 0 до 59

//     // notH - содержит результат логической операции (0 или 1)
//     int notH = 0 <= a.h && a.h < 24;
//     // notMin - содержит результат логической операции (0 или 1)
//     int notMin = a.min && a.min < 60;
//     // code содержит код проблемы: 0, 1, 2 или 3
//     // если notH == 1 и notMin == 1, то все в порядке (3)
//     // если notH == 1 и notMin == 0, то минуты не верны (1)
//     // если notH == 0 и notMin == 1, то минуты не верны (2)
//     // если notH == 0 и notMin == 0, то все не верно (0)
//     int code = notH + 2 * notMin;
//     // возвращаем code
//     return code;
// };

// int main() {
//     Timer tm;
//     scanf("%d:%d", &tm.h, &tm.min);
//     // часы должны быть не менее 0 и не более 23
//     // а минуты - от 0 до 59

//     int code = isTimeCorrect(tm);
//     // code - для проверки какое условие выбирать
//     switch (code) {
//             // если code ==  0
//         case 0:
//             printf("NO\n");
//             // break прерывает выполнение switch
//             break;
//             // если code ==  1
//         case 1:
//             printf("NO\n");
//             printf("минуты не верно\n");
//             break;
//             // если code ==  2
//         case 2:
//             printf("NO\n");
//             printf("часы не верно\n");
//             break;
//             // если code ==  3
//         case 3:
//             printf("YES\n");
//     }

//     return 0;
// }

// #include <stdio.h>
// #include <stdlib.h>

// typedef struct {
//     int h;    // часы
//     int min;  // минуты
// } Timer;

// // эта функция ничего не печатает!!!
// int isTimeCorrect(Timer a) {
//     // часы должны быть не менее 0 и не более 23
//     // а минуты - от 0 до 59

//     // notH - содержит результат логической операции (0 или 1)
//     int notH = 0 <= a.h && a.h < 24;
//     // notMin - содержит результат логической операции (0 или 1)
//     int notMin = a.min && a.min < 60;
//     // code содержит код проблемы: 0, 1, 2 или 3
//     // если notH == 1 и notMin == 1, то все в порядке (3)
//     // если notH == 1 и notMin == 0, то минуты не верны (1)
//     // если notH == 0 и notMin == 1, то минуты не верны (2)
//     // если notH == 0 и notMin == 0, то все не верно (0)
//     int code = notH + 2 * notMin;
//     // возвращаем code
//     return code;
// };

// int main() {
//     Timer tm;
//     scanf("%d:%d", &tm.h, &tm.min);
//     // часы должны быть не менее 0 и не более 23
//     // а минуты - от 0 до 59

//     int code = isTimeCorrect(tm);
//     // code - для проверки какое условие выбирать
//     switch (code) {
//             // если code ==  0
//         case 0:
//             printf("NO\n");
//             // break прерывает выполнение switch
//             // но здесь не написан, значит будут выполнены
//             // все остальные инструкции до break или конца
//             // если code ==  1
//         case 1:
//             printf("минуты не верно\n");
//             // если code ==  2
//         case 2:
//             printf("часы не верно\n");
//             break;
//             // если code ==  3
//         case 3:
//             printf("YES\n");
//     }

//     return 0;
// }

// #include <stdio.h>
// #include <stdlib.h>

// typedef struct {
//     int h;    // часы
//     int min;  // минуты
// } Timer;

// // эта функция ничего не печатает!!!
// int isTimeCorrect(Timer a) {
//     // часы должны быть не менее 0 и не более 23
//     // а минуты - от 0 до 59

//     // notH - содержит результат логической операции (0 или 1)
//     int notH = 0 <= a.h && a.h < 24;
//     // notMin - содержит результат логической операции (0 или 1)
//     int notMin = a.min && a.min < 60;
//     int negMin = a.min < 0;
//     int negH = a.h < 0;
//     // code содержит код проблемы: 0, 1, 2 или 3
//     // если notH == 1 и notMin == 1, то все в порядке (3)
//     // если notH == 1 и notMin == 0, то минуты не верны (1)
//     // если notH == 0 и notMin == 1, то минуты не верны (2)
//     // если notH == 0 и notMin == 0, то все не верно (0)
//     int code = notH + 2 * notMin + 10 * negMin + 20 * negH;
//     // возвращаем code
//     return code;
// };

// int main() {
//     Timer tm;
//     scanf("%d:%d", &tm.h, &tm.min);
//     // часы должны быть не менее 0 и не более 23
//     // а минуты - от 0 до 59

//     int code = isTimeCorrect(tm);
//     // code - для проверки какое условие выбирать
//     switch (code) {
//             // если code ==  0
//         case 0:
//             printf("NO\n");
//             // break прерывает выполнение switch
//             // но здесь не написан, значит будут выполнены
//             // все остальные инструкции до break или конца
//             // если code ==  1
//         case 1:
//             printf("минуты не верно\n");
//             // если code ==  2
//         case 2:
//             printf("часы не верно\n");
//             break;
//             // если code ==  3
//         case 3:
//             printf("YES\n");
//             break;
//             // default будет выполняться для всех отальных значений,
//             // не упомянутых в case
//         default:
//             printf("Все отрицательное\n");
//     }

//     return 0;
// }

// #include <stdio.h>
// #include <stdlib.h>

// // Если в функциях есть вызов других
// // функций, еще не реализованных,
// // то вначале делаются ОБЪЯВЛЕНИЯ
// // этих функций
// // Иначе компилятор не сможет найти вызываемую функцию

// void aboutGoat();  // основная функция про козлика
// void askYou();     // функция, задающая вопрос
// void listenYou();  // функция, получающая ответ

// // Каждая из функций явно вызывает не саму себя,
// // а ДРУГУЮ функцию.
// // Однако, каждая из функций вызывает себя
// // косвенно через вызов в другой функции

// // Таким образом также получается рекурсивный вызов

// void askYou() {
//     printf("Рассказать тебе сказку о сереньком козлике?\n");
//     // В listenYou() есть вызов askYou()
//     listenYou();
// };

// void listenYou() {
//     char answer[200];
//     scanf("%s", answer);
//     printf("Все говорят, %s.\n", answer);
//     // в askYou() есть вызов listenYou()
//     askYou();
// };
// void aboutGoat() { askYou(); };

// int main() {
//     aboutGoat();
//     return 0;
// }

// #include <stdio.h>
// #include <stdlib.h>
// int nod(int a, int b) {
//     int res;
//     if (a < b) {
//         // обмен значениями  a  и b
//         // для указателей не применять!! (проверьте почему)
//         a = a - b;
//         b = b + a;
//         a = b - a;
//     }
//     printf("a: %d b: %d\n", a, b);
//     // Условие на выход из функции по получению
//     // элементарного результата
//     if (a == b) {
//         printf("%d == %d\n return\n", a, b);
//         return b;
//     }
//     // Действия перед вызовом
//     // Изменение параметров функции
//     a = a - b;

//     // Вызов рекурсивной функции
//     res = nod(a, b);
//     // Действия после вызова - присваивание результата к res
//     printf("res: %d return \n", res);
//     return res;
// }

// int main() {
//     int a, b, res;
//     scanf("%d%d", &a, &b);
//     res = nod(a, b);
//     printf("%d\n", res);
//     return 0;
// }

#include <stdio.h>
#include <stdlib.h>
int nod(int a, int b) {
    int res;
    if (a == b) {
        return b;
    }
    res = (a > b) ? nod(a - b, b) : nod(b, b - a);
    return res;
}

int main() {
    int a, b, res;
    scanf("%d%d", &a, &b);
    res = nod(a, b);
    printf("%d\n", res);
    return 0;
}