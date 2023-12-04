// #include <stdio.h>
// int main(void) {
//     char a;

//     scanf("%c", &a);

//     printf("%c", a - 32);

//     return 0;
// }

// #include <stdio.h>
// int main(void) {
//     char a;

//     scanf("%c", &a);

//     printf("%c %c", a - 1, a + 1);

//     return 0;
// }

// #include <ctype.h>
// #include <stdio.h>
// #define CHARS 26

// int main(void) {
//     int k, dir[CHARS] = {0};
//     scanf("%d", &k);
//     char ch;

//     for (int i = 0; i < k; i++) {
//         scanf(" %c", &ch);
//         dir[tolower(ch) - 97]++;
//     }

//     for (int i = 0; i < CHARS; i++) {
//         printf("%d ", dir[i]);
//     }

//     return 0;
// }

/*
Определить тип символа.
*/

// #include <stdio.h>

// int main(void) {
//     char k;

//     for (int i = 0; i < 255; i++) {
//         k = i;
//         printf("%d = %c%s", i, k, k % 10 ? "\t" : "\n");
//     }

//     return 0;
// }

// #include <ctype.h>
// #include <stdio.h>

// int main(void) {
//     char ch;
//     scanf("%c", &ch);

//     if (tolower(ch) <= 122 && tolower(ch) >= 97) {
//         printf("en");
//     } else if (ch <= 57 && ch >= 48) {
//         printf("digit");
//     } else {
//         printf("error");
//     }

//     return 0;
// }

// #include <stdio.h>
// #include <ctype.h>
// int main() {
//     int ch;
//     scanf("%c", &ch);
//     printf("%s\n", isalpha(ch)?"en":isdigit(ch)?"digit":"error");
//     return 0;
// }

/*
Вывести на экран K символ латинского алфавита в верхнем и нижнем регистре.
*/

// #include <stdio.h>
// #define CHARS 27

// int main(void) {
//     int num;
//     scanf("%d", &num);

//     for (int i = CHARS - num; i < CHARS; i++) {
//         printf("%c", i + 64);
//     }

//     return 0;
// }

/*
Длина строки.
Подсчитать количество символов в строке, без учёта нуль-символа.
*/

// #include <stdio.h>
// #include <string.h>

// #define MAXLEN 30

// int main(void) {
//     char str[MAXLEN];
//     fgets(str, 30, stdin);
//     int res = strlen(str) - 1;
//     printf("%d", res);

//     return 0;
// }

/*
Слова.
Подсчитать количество слов в строке. Под словом будем понимать непустую последовательность символов,
разделённую знаками пробела.
*/

// #include <stdio.h>

// #define MAXLEN 100

// int main(void) {
//     char str[MAXLEN];
//     fgets(str, 100, stdin);
//     int res = 0;

//     for (int i = 1; i < MAXLEN - 1; i++) {
//         if (str[i] == '\n') {
//             break;
//         } else if (str[i] != ' ' && (str[i + 1] == ' ' || str[i + 1] == '\n')) {
//             res++;
//         }
//     }

//     printf("%d", res);

//     return 0;
// }

/*
Поиск символа
Найти в строке заданный символ.
*/

// #include <stdio.h>

// int main(void) {
//     char ch, str;
//     scanf("%c%c", &ch, &str);
//     int res = -1, count = 0;

//     while (1) {
//         scanf("%c", &str);
//         if (str == '\n') {
//             break;
//         } else if (str == ch) {
//             res = count++;
//             break;
//         } else {
//             count++;
//         }
//     }
//     printf("%d", res);
//     return 0;
// }

/*
Системы счисления
Дана строка, изображающая двоичную запись целого положительного числа. Вывести строку, изображающую десятичную
запись этого же числа.
*/

// #include <math.h>
// #include <stdio.h>
// #include <string.h>

// int main(void) {
//     char str[21];
//     fgets(str, 21, stdin);
//     int res = 0, count = 0;

//     count = strlen(str);

//     for (int i = 0; i < count - 1; i++) {
//         res += pow(2, i) * (str[count - i - 2] - 48);
//     }

//     printf("%d", res);
//     return 0;
// }

/*
Лишние пробелы
Удалить из строки лишние пробелы.
*/

// #include <stdio.h>
// #include <string.h>

// #define MAXLEN 100

// int main(void) {
//     char str[MAXLEN];
//     fgets(str, MAXLEN, stdin);
//     int count, flag = 0;
//     count = strlen(str);

//     for (int i = 0; i < count - 1; i++) {
//         if (str[i] == ' ' && flag == 0) {
//             continue;
//         } else if (str[i] == ' ' && flag == 1) {
//             printf("%c", str[i]);
//             flag = 0;
//         } else if (str[i] != ' ') {
//             printf("%c", str[i]);
//             flag = 1;
//         }
//     }
//     return 0;
// }

/*
Расстояние Хэмминга.
Расстояние Хэмминга для двух слов одинаковой длины — это количество позиций, в которых различаются эти слова.
Для двух заданных строк найти расстояние между ними.
*/

// #include <stdio.h>
// #include <string.h>

// #define MAXLEN 15

// int main(void) {
//     char str1[MAXLEN];
//     char str2[MAXLEN];
//     fgets(str1, 15, stdin);
//     fgets(str2, 15, stdin);

//     int count, res = 0;
//     count = strlen(str1);

//     for (int i = 0; i < count - 1; i++) {
//         if (str1[i] != str2[i]) {
//             res++;
//         }
//     }
//     printf("%d", res);
//     return 0;
// }

/*
Остров сокровищ
Капитан Флинт зарыл клад на Острове сокровищ. Есть описание, как найти клад.
*/

#include <stdio.h>
#include <string.h>

#define MAXLEN 6

int main(void) {
    int count, arg, x = 0, y = 0;
    char str[MAXLEN];
    scanf("%d", &count);

    for (int i = 0; i < count; i++) {
        scanf("%s %d", str, &arg);
        if (strcmp(str, "North") == 0) {
            y += arg;
        } else if (strcmp(str, "South") == 0) {
            y -= arg;
        } else if (strcmp(str, "East") == 0) {
            x += arg;
        } else {
            x -= arg;
        }
    }

    printf("%d %d", x, y);
    return 0;
}
