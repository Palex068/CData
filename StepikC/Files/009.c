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

// #include <stdio.h>
// #include <string.h>

// #define MAXLEN 6

// int main(void) {
//     int count, arg, x = 0, y = 0;
//     char str[MAXLEN];
//     scanf("%d", &count);

//     for (int i = 0; i < count; i++) {
//         scanf("%s %d", str, &arg);
//         if (strcmp(str, "North") == 0) {
//             y += arg;
//         } else if (strcmp(str, "South") == 0) {
//             y -= arg;
//         } else if (strcmp(str, "East") == 0) {
//             x += arg;
//         } else {
//             x -= arg;
//         }
//     }

//     printf("%d %d", x, y);
//     return 0;
// }

/*
Комментарии
Удалить часть символьной строки, заключенную между последовательностями символов и */

// #include <stdio.h>
// #include <string.h>

// #define MAXLEN 100

// int main(void) {
//     int len, left_flag = 1, right_flag = 1, left_index = 0, right_index = 0;
//     char str[MAXLEN];
//     fgets(str, MAXLEN, stdin);
//     len = strlen(str);

//     for (int i = 0; i < len; i++) {
//         if (str[i] == '/' && str[i + 1] == '*') {
//             left_index += (i - 1) * left_flag;
//             left_flag = 0;
//         }

//         if (!left_flag && i != left_index + 2 && str[i] == '*' && str[i + 1] == '/') {
//             right_index += (i + 2) * right_flag;
//             right_flag = 0;
//         }
//     }

//     // printf("%d %d\n%d %d\n", right_flag, right_index, left_flag, left_index);

//     for (int i = 0; i < len; i++) {
//         if (!left_flag * !right_flag && i < right_index && i > left_index) {
//             continue;
//         } else {
//             printf("%c", str[i]);
//         }
//     }
//     return 0;
// }

/*
Форматированный вывод числа.
Написать программу, реализующую вывод числа N с разделением на триады цифр.
*/

// #include <stdio.h>
// #include <string.h>

// #define MAXLEN 9

// int main(void) {
//     int len;
//     char str[MAXLEN];
//     fgets(str, MAXLEN, stdin);
//     len = strlen(str) - 1;
//     for (int i = 0; i < len; i++) {
//         printf("%c%s", str[i], (i == (len - 1) % 3) || (i == (len - 1) % 3 + 3) ? " " : "");
//     }
//     return 0;
// }

// #include <ctype.h>
// #include <stdio.h>
// #include <string.h>

// int main() {
//     char str[21];
//     fgets(str, 21, stdin);
//     int len = strlen(str) - 1, I = 1, F = 2, i = 0;

//     if (str[len - 1] == '.' || str[0] == '.') {
//         printf("error");
//         return 0;
//     }

//     if (str[0] == '-') {
//         str[0] = '0';
//     }

//     while (str[i] != '\0' && str[i] != '\n' && I && F) {
//         if (str[i] == '.') {
//             F--;
//         } else if (!isdigit(str[i])) {
//             I--;
//         }
//         i++;
//     }

//     printf("%s", I * F ? F == 1 ? "float" : "int" : "error");
//     return 0;
// }

/*
Найти в строке слова, которые начинаются и оканчиваются одной и той же буквой. Слова разделяются пробелами.
*/

// #include <stdio.h>
// #include <string.h>

// int main() {
//     char str[52];
//     fgets(str, 52, stdin);

//     char* tok = strtok(str, " ");

//     while (tok != NULL) {
//         int len = strlen(tok) - 1;
//         if (tok[0] == tok[len] || (tok[len] == '\n' && tok[0] == tok[len - 1])) {
//             printf("%s ", tok);
//         }
//         tok = strtok(NULL, " ");
//     }
//     return 0;
// }

/*
В строке слова зашифрованы — каждое из них записано наоборот. Написать программу, расшифровывающую строку
*/

// #include <stdio.h>
// #include <string.h>

// int main(void) {
//     char word[40], c;

//     while (scanf("%39s%c", word, &c) == 2) {
//         int len = strlen(word);
//         for (int i = 0; i < len; i++) {
//             printf("%c%s", word[len - i - 1], i == len - 1 ? " " : "");
//         }
//         if (c == 10) break;
//     }
//     return 0;
// }

// #include <stdio.h>
// #include <string.h>

// int main(void) {
//     // объявляем строку
//     char str1[] = "Peace! ";

//     int l1 = strlen(str1);  // вычисляем длину первой строки

//     // выводим на экран строку str1 и её длину
//     printf("%d\n", l1);

//     return 0;
// }

// #include <stdio.h>
// #include <string.h>

// int main(void) {
//     // объявляем три строки
//     char str1[19] = "Peace! ";
//     char str2[] = "Labor! ";
//     char str3[] = "May!";

//     // выводим строки на экран
//     printf("str1: %s\n", str1);
//     printf("str2: %s\n", str2);
//     printf("str3: %s\n\n", str3);

//     // присоединяем к первой строке вторую
//     strcat(str1, str2);
//     // теперь str1 = "Peace! Labor!"

//     // присоединяем к первой строке третью
//     strcat(str1, str3);
//     // теперь str1 = "Peace! Labor! May!"

//     // выводим на экран строку str1 и её длину
//     printf("str1: %s %d\n", str1, strlen(str1));

//     return 0;
// }

// #include <stdio.h>
// #include <string.h>

// int main(void) {
//     char str1[] = "hello world", str2[] = "hello world", str3[] = "hello World";
//     // сравниваем строки между собой
//     int n12 = strcmp(str1, str2);
//     int n13 = strcmp(str1, str3);
//     int n31 = strcmp(str3, str1);

//     // выводим строки и результат работы strcmp
//     printf(" %s i %s =  %d\n", str1, str2, n12);
//     printf(" %s i %s = %d\n", str1, str3, n13);
//     printf(" %s i %s = %d\n", str3, str1, n31);

//     // выводим седьмой символ в строке и его ASCII-код
//     printf("%c / %d\n", str1[6], str1[6]);
//     printf("%c / %d\n", str3[6], str3[6]);

//     return (0);
// }

// #include <stdio.h>
// #include <string.h>

// int main(void) {
//     char str1[] = "Hello World!", str2[] = "Hi man!";
//     printf("str1: %s \nstr2 %s\n\n", str1, str2);

//     strcpy(str1, str2);

//     printf("str1: %s \nstr2 %s\n", str1, str2);

//     return (0);
// }

/*
Программа приветствие
Допишите программу приветствие.
Программа должна склеивать строку, которая уже есть в программе и строку, введенную пользователем.
*/

// #include <stdio.h>
// #include <string.h>

// int main(void) {
//     char str1[40] = "Hello, ";
//     char str2[20];
//     scanf("%s", str2);

//     strcat(str1, str2);

//     printf("%s", str1);

//     return 0;
// }

/*
Имя файла.
Вывести полное название файла в формате
имя_файла.расширение
*/

// #include <stdio.h>
// #include <string.h>

// int main(void) {
//     char str1[30];
//     char str3[4];
//     scanf("%s ", str1);
//     scanf("%s", str3);

//     strcat(str1, ".");

//     strcat(str1, str3);

//     printf("%s", str1);

//     return 0;
// }

/*
Города
Определить можно ли из указанных слов составить цепочку для игры в "Города"
*/

// #include <ctype.h>
// #include <stdio.h>
// #include <string.h>

// int main(void) {
//     char str1[51];
//     char str2[51];
//     scanf("%50s ", str1);
//     scanf("%50s", str2);

//     int flag1 = tolower(str2[0]) == str1[strlen(str1) - 1];
//     int flag2 = tolower(str1[0]) == str2[strlen(str2) - 1];

//     printf("%s", flag1 || flag2 ? "yes" : "no");

//     return 0;
// }

/*
Сравнение строк
*/

// #include <ctype.h>
// #include <stdio.h>
// #include <string.h>

// int mystrcmp(char str1[], char str2[]);

// int main(void) {
//     char str1[51];
//     char str2[51];
//     fgets(str1, 50, stdin);
//     fgets(str2, 50, stdin);

//     printf("%s", mystrcmp(str1, str2) ? "no" : "yes");

//     return 0;
// }

// int mystrcmp(char str1[], char str2[]) {
//     int len1 = strlen(str1), len2 = strlen(str2), flag = 0;
//     if (len1 != len2) {
//         return len1 > len2 ? 1 : -1;
//     } else {
//         for (int i = 0; i < len1; i++) {
//             if (tolower(str1[i]) != tolower(str2[i])) {
//                 return str1[i] > str2[i] ? 1 : -1;
//             }
//         }
//     }
//     return flag;
// }

#include <stdio.h>

int main(void) {
    int sum[2] = {0}, digit;

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            scanf("%1d", &digit);
            sum[i] += digit;
        }
    }
    printf("%s", (sum[0] - sum[1]) ? "no" : "yes");
}