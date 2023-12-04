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

#include <stdio.h>
#define CHARS 27

int main(void) {
    int num;
    scanf("%d", &num);

    for (int i = CHARS - num; i < CHARS; i++) {
        printf("%c", i + 64);
    }

    return 0;
}