// #include <stdio.h>
// #include <conio.h>
 
// void main() {
//     int a = 0x77, b = -20;
//     char c = 'F';
//     float f = 12.2341524;
//     double d = 2e8;
//     char* string = "Hello, World!";
 
//     printf("%s\n", string);
//     printf("a = %d, b = %d\n", a, b);
//     printf("a = %u, b = %u\n", a, b);
//     printf("a = %x, b = %X\n", a, b);
//     printf("dec a = %d, oct a = %o, hex a = %x\n", a, a, a);
//     printf("floating point f = %f, exp f = %e\n", f, f);
//     printf("double d = %f or %E\n", d, d);
//     printf("not all compiler support %a\n", f);
//     printf("character c = %c, as number c = %d\n", c, c);
//     printf("address of string is %p", string);
//     getch();
// }

// #include <stdio.h>
// #include <conio.h>
 
// void main() {
//     int a = 0x77, b = -20;
//     char c = 'F';
//     float f = 12.2341524;
//     double d = 2e2;
//     char* string = "Hello, World!";
 
//     printf("%.3f\n", f);
//     printf("%.*f\n", 2, f);
//     printf("%010.3f\n", d);
//     printf("%*d\n", 6, a);
//     printf("%+d\n", b);
//     printf("%0.6d\n", a);
//     printf("%.f\n", d);
//     printf("%.4s", string);
//     getch();
// }

#include <stdio.h>
#include <conio.h>
 
void main() {
    char backspace = 0x08;
    //Выводим с использованием символа переноса строки
    printf("Hello\nWorld\n");
    //Выводим символ переноса строки через его значение
    printf("Hello%cWorld\n", 0x0a);
    //"Выводим" сигнал
    printf("\a");
    //Выводим сигнал, как символ
    printf("%c", '\a');
    //Выводим сигнал через шестнадцатеричное значение
    printf("%c", 0x07);
    printf("This is sparta!!!\b\b%c", backspace);
    printf("   ");
    getch();
}