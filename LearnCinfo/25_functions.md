# Функции

![Функции](./Pictures/25_01_c_functions_theme.jpg)

## Содержание

+ [Введение](#введение)
+ [Формальные и фактические параметры](#формальные-и-фактические-параметры)
+ [Передача аргументов](#передача-аргументов)
+ [Объявление функции и определение функции. Создание собственной библиотеки](#объявление-функции-и-определение-функции-создание-собственной-библиотеки)
+ [Передача массива в качестве аргумента](#передача-массива-в-качестве-аргумента)

## Введение

Чем дальше мы изучаем си, тем больше становятся программы. Мы собираем все действия в одну функцию main и по несколько раз копируем одни и те же действия, создаём десятки переменных с уникальными именами. Наши программы распухают и становятся всё менее и менее понятными, ветвления становятся всё длиннее и ветвистее.

Но из сложившейся ситуации есть выход! Теперь мы научимся создавать функции на си. Функции, во-первых, помогут выделить в отдельные подпрограммы дублирующийся код, во-вторых, помогут логически разбить программу на части, в-третьих, с функциями в си связано много особенностей, которые позволят использовать новые подходы к структурированию приложений.

**Функция** – это именованная часть программы, которая может быть многократно вызвана из другого участка программы (в котором эта функция видна). Функция может принимать фиксированное либо переменное число аргументов, а может не иметь аргументов. Функция может как возвращать значение, так и быть пустой (void) и ничего не возвращать.

Мы уже знакомы с многими функциями и знаем, как их вызывать – это функции библиотек `stdio`, `stdlib`, `string`, `conio` и пр. Более того, `main` – это тоже функция. Она отличается от остальных только тем, что является точкой входа при запуске приложения.
Функция в си определяется в глобальном контексте. Синтаксис функции:

```c
<возвращаемый тип> <имя функции>(<тип1> <арг1>, <тип1> <арг2>, ...) {
    <тело функции>
}
```

Самый простой пример – функция, которая принимает число типа `float` и возвращает квадрат этого числа

```c
#include <conio.h>
#include <stdio.h>
 
float sqr(float x) {
    float tmp = x*x;
    return tmp;
}
 
void main() {
    printf("%.3f", sqr(9.3f));
    getch();
}
```

Внутри функции sqr мы создали локальную переменную, которой присвоили значение аргумента. В качестве аргумента функции передали число 9,3. Служебное слово return возвращает значение переменной tmp. Можно переписать функцию следующим образом:

```c
float sqr(float x) {
    return x*x;
}
```

В данном случае сначала будет выполнено умножение, а после этого возврат значения. В том случае, если функция ничего не возвращает, типом возвращаемого значения будет void. Например, функция, которая печатает квадрат числа:

```c
void printSqr(float x) {
    printf("%d", x*x);
    return;
}
```

в данном случа return означает выход из функции. Если функция ничего не возвращает, то return можно не писать. Тогда функция доработает до конца и произойдёт возврат управления вызывающей функции.

```c
void printSqr(float x) {
    printf("%d", x*x);
}
```

Если функция не принимает аргументов, то скобки оставляют пустыми. Можно также написать слово void:

```c
void printHelloWorld() {
    printf("Hello World");
}
```

эквивалентно

```c
void printHelloWorld(void) {
    printf("Hello World");
}
```

---
[Содержание](#содержание)

## Формальные и фактические параметры

При объявлении функции указываются формальные параметры, которые потом используются внутри самой функции. При вызове функции мы используем фактические параметры. Фактическими параметрами могут быть переменные любого подходящего типа или константы.

Например, пусть есть функция, которая возвращает квадрат числа и функция, которая суммирует два числа.

```c
#include <conio.h>
#include <stdio.h>
 
//Формальные параметры имеют имена a и b
//по ним мы обращаемся к переданным аргументам внутри функции
int sum(int a, int b) {
    return a+b;
}
 
float square(float x) {
    return x*x;
}
 
void main() {
    //Фактические параметры могут иметь любое имя, в том числе и не иметь имени
    int one = 1;
    float two = 2.0;
 
    //Передаём переменные, вторая переменная приводится к нужному типу
    printf("%d\n", sum(one, two));
    //Передаём числовые константы
    printf("%d\n", sum(10, 20));
    //Передаём числовые константы неверного типа, они автоматически приводится к нужному
    printf("%d\n", sum(10, 20.f));
    //Переменная целого типа приводится к типу с плавающей точкой
    printf("%.3f\n", square(one));
    //В качестве аргумента может выступать и вызов функции, которая возвращает нужное значение
    printf("%.3f\n", square(sum(2 + 4, 3)));
 
    getch();
}
```

Обращаю внимание, что приведение типов происходит неявно и только тогда, когда это возможно. Если функция получает число в качестве аргумента, то нельзя ей передать переменную строку, например "20" и т.д. Вообще, лучше всегда использовать верный тип или явно приводить тип к нужному.

Если функция возвращает значение, то оно не обязательно должно быть сохранено. Например, мы пользуемся функцией `getch`, которая считывает символ и возвращает его.

```c
#include <conio.h>
#include <stdio.h>
 
void main() {
    char c;
 
    do {
        //Сохраняем возвращённое значение в переменную
        c = getch();
        printf("%c", c);
    } while(c != 'q');
    //Возвращённое значение не сохраняется
    getch();
}
```

---
[Содержание](#содержание)

## Передача аргументов

При передаче аргументов происходит их копирование. Это значит, что любые изменения, которые функция производит над переменными, имеют место быть только внутри функции. Например

```c
#include <conio.h>
#include <stdio.h>
 
void change(int a) {
    a = 100;
    printf("%d\n", a);
}
 
void main() {
    int d = 200;
    printf("%d\n", d);
    change(d);
    printf("%d", d);
    getch();
}
```

Программы выведет

```sh
200
100
200
```

Понятно почему. Внутри функции мы работаем с переменной x, которая является копией переменной d. Мы изменяем локальную копию, но сама переменная d при этом не меняется. После выхода из функции локальная переменная будет уничтожена. Переменная d при этом никак не изменится.

Каким образом тогда можно изменить переменную? Для этого нужно передать адрес этой переменной. Перепишем функцию, чтобы она принимала указатель типа `int`

```c
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
 
void init(int *a, unsigned size) {
    a = (int*) malloc(size * sizeof(int));
}
 
void main() {
    int *a = NULL;
    init(a, 100);
    if (a == NULL) {
        printf("ERROR");
    } else {
        printf("OKAY...");
        free(a);
    }
    getch();
}
```

Но эта функция выведет `ERROR`. Мы передали адрес переменной. Внутри функции `init` была создана локальная переменная `a`, которая хранит адрес массива. После выхода из функции эта локальная переменная была уничтожена. Кроме того, что мы не смогли добиться нужного результата, у нас обнаружилась утечка памяти: была выделена память на куче, но уже не существует переменной, которая бы хранила адрес этого участка.

Для изменения объекта необходимо передавать указатель на него, в данном случае – указатель на указатель.

```c
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
 
void init(int **a, unsigned size) {
    *a = (int*) malloc(size * sizeof(int));
}
 
void main() {
    int *a = NULL;
    init(&a, 100);
    if (a == NULL) {
        printf("ERROR");
    } else {
        printf("OKAY...");
        free(a);
    }
    getch();
}
```

Вот теперь всё работает как надо.

Ещё подобный пример. Напишем функцию, которая принимает в качестве аргумента строку и возвращает указатель на область памяти, в которую скопирована эта строка.

```c
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
char* initByString(const char *str) {
    char *p = (char*) malloc(strlen(str) + 1);
    strcpy(p, str);
    return p;
}
 
void main() {
    char *test = initByString("Hello World!");
    printf("%s", test);
    free(test);
    getch();
}
```

В этом примере утечки памяти не происходит. Мы выделили память с помощью функции `malloc`, скопировали туда строку, а после этого вернули указатель. Локальные переменные были удалены, но переменная `test` хранит адрес участка памяти на куче, поэтому можно его удалить с помощью функции `free`.

---
[Содержание](#содержание)

## Объявление функции и определение функции. Создание собственной библиотеки

В си можно объявить функцию до её определения. Объявление функции, её прототип, состоит из возвращаемого значения, имени функции и типа аргументов. Имена аргументов можно не писать. Например

```c
#include <conio.h>
#include <stdio.h>
 
//Прототипы функций. Имена аргументов можно не писать
int odd(int);
int even(int);
 
void main() {
    printf("if %d odd? %d\n", 11, odd(11));
    printf("if %d odd? %d\n", 10, odd(10));
    getch();
}
 
//Определение функций
int even(int a) {
    if (a) {
        odd(--a);
    } else {
        return 1;
    }
}
 
int odd(int a) {
    if (a) {
        even(--a);
    } else {
        return 0;
    }
}
```

Это смешанная рекурсия – функция `odd` возвращает `1`, если число нечётное и `0`, если чётное.

Обычно объявление функции помещают отдельно, в `.h` файл, а определение функций в `.c` файл. Таким образом, заголовочный файл представляет собой интерфейс библиотеки и показывает, как с ней работать, не вдаваясь в содержимое кода.

Давайте создадим простую библиотеку. Для этого нужно будет создать два файла – один с расширением `.h` и поместить туда прототипы функций, а другой с расширением `.c` и поместить туда определения этих функций. Если вы работаете с IDE, то `.h` файл необходимо создавать в папке Заголовочные файлы, а файлы кода в папке Файлы исходного кода. Пусть файлы называются `File1.h` и `File1.c`

Перепишем предыдущий код. Вот так будет выглядеть заголовочный файл `File1.h`

```c
#ifndef _FILE1_H_
#define _FILE1_H_
 
int odd(int);
int even(int);
 
#endif
```

Содержимое файла исходного кода `File1.c`

```c
#include "File1.h"
 
int even(int a) {
    if (a) {
        odd(--a);
    } else {
        return 1;
    }
}
 
int odd(int a) {
    if (a) {
        even(--a);
    } else {
        return 0;
    }
}
```

Наша функция `main`

```c
#include <conio.h>
#include <stdio.h>
#include "File1.h"
 
void main() {
    printf("if %d odd? %d\n", 11, odd(11));
    printf("if %d odd? %d\n", 10, odd(10));
    getch();
}
```

Рассмотрим особенности каждого файла. Наш файл, который содержит функцию `main`, подключает необходимые ему библиотеки а также заголовочный файл `File1.h`. Теперь компилятору известны прототипы функций, то есть он знает возвращаемый тип, количество и тип аргументов и имена функций.

Заголовочный файл, как и оговаривалось ранее, содержит прототип функций. Также здесь могут быть подключены используемые библиотеки. Макрозащита `#define _FILE1_H_` и т.д. используется для предотвращения повторного копирования кода библиотеки при компиляции. Эти строчки можно заменить одной

```c
#pragma once
 
int odd(int);
int even(int);
```

Файл `File1.c` исходного кода подключает свой заголовочный файл. Всё как обычно логично и просто. В заголовочные файлах принято кроме прототипов функций выносить константы, макроподстановки и определять новые типы данных. Кроме того, именно в заголовочных файлах можно обширно комментировать код и писать примеры его использования.

---
[Содержание](#содержание)

## Передача массива в качестве аргумента

Как уже говорилось ранее, имя массива подменяется на указатель, поэтому передача одномерного массива эквивалентна передаче указателя. Пример: функция получает массив и его размер и выводит на печать:

```c
#include <conio.h>
#include <stdio.h>
 
void printArray(int *arr, unsigned size) {
    unsigned i;
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
}
 
void main() {
    int x[10] = {1, 2, 3, 4, 5};
    printArray(x, 10);
    getch();
}
```

В этом примере функция может иметь следующий вид

```c
void printArray(int arr[], unsigned size) {
    unsigned i;
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
}
```

Также напомню, что правило подмены массива на указатель не рекурсивное. Это значит, что необходимо указывать размерность двумерного массива при передаче

```c
#include <conio.h>
#include <stdio.h>
 
void printArray(int arr[][5], unsigned size) {
    unsigned i, j;
    for (i = 0; i < size; i++) {
        for (j = 0; j < 5; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}
 
void main() {
    int x[][5] = { 
        { 1, 2, 3, 4, 5},
        { 6, 7, 8, 9, 10}};
    printArray(x, 2);
    getch();
}
```

Либо, можно писать

```c
#include <conio.h>
#include <stdio.h>
 
void printArray(int (*arr)[5], unsigned size) {
    unsigned i, j;
    for (i = 0; i < size; i++) {
        for (j = 0; j < 5; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}
 
void main() {
    int x[][5] = {
        { 1, 2, 3, 4, 5},
        { 6, 7, 8, 9, 10}};
    printArray(x, 2);
    getch();
}
```

Если двумерный массив создан динамически, то можно передавать указатель на указатель.

Например функция, которая получает массив слов и возвращает массив целых, равных длине каждого слова:

```c
#include <conio.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
#define SIZE 10
 
unsigned* getLengths(const char **words, unsigned size) {
    unsigned *lengths = NULL;
    unsigned i;
    lengths = (unsigned*) malloc(size * sizeof(unsigned));
    for (i = 0; i < size; i++) {
        lengths[i] = strlen(words[i]);
    }
    return lengths;
}
 
void main() {
    char **words = NULL;
    char buffer[128];
    unsigned i;
    unsigned *len = NULL;
    words = (char**) malloc(SIZE * sizeof(char*));
 
    for (i = 0; i < SIZE; i++) {
        printf("%d. ", i);
        scanf("%127s", buffer);
        words[i] = (char*) malloc(128);
        strcpy(words[i], buffer);
    }
 
    len = getLengths(words, SIZE);
    for (i = 0; i < SIZE; i++) {
        printf("%d ", len[i]);
        free(words[i]);
    }
    free(words);
    free(len);
    getch();
}
```

Можно вместо того, чтобы возвращать указатель на массив, передавать массив, который необходимо заполнить

```c
#include <conio.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
#define SIZE 10
 
void getLengths(const char **words, unsigned size, unsigned *out) {
    unsigned i;
    for (i = 0; i < size; i++) {
        out[i] = strlen(words[i]);
    }
}
 
void main() {
    char **words = NULL;
    char buffer[128];
    unsigned i;
    unsigned *len = NULL;
    words = (char**) malloc(SIZE * sizeof(char*));
 
    for (i = 0; i < SIZE; i++) {
        printf("%d. ", i);
        scanf("%127s", buffer);
        words[i] = (char*) malloc(128);
        strcpy(words[i], buffer);
    }
 
    len = (unsigned*) malloc(SIZE * sizeof(unsigned));
    getLengths(words, SIZE, len);
    for (i = 0; i < SIZE; i++) {
        printf("%d ", len[i]);
        free(words[i]);
    }
    free(words);
    free(len);
    getch();
}
```

На этом первое знакомство с функциями заканчивается: тема очень большая и разбита на несколько статей.

---
[Содержание](#содержание)
