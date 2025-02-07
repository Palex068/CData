# Библиотеки и функции для работы со строками в си

![Библиотеки и функции для работы со строками в си](./Pictures/31_c_mastering_strings_theme.jpg)

Библиотека `string.h` предоставляет функции для работы со строками (zero-terminated strings) в си, а также несколько функций для работы с массивами, которые сильно упрощают жизнь. Рассмотрим функции с примерами.

## Содержание

+ [Копирование](#копирование)
+ [Конкатенация (склеивание)](#конкатенация-склеивание)
+ [Сравнение строк](#сравнение-строк)
+ [Поиск](#поиск)
+ [Длина строки и заполнение символами](#длина-строки-и-заполнение-символами)
+ [Перевод строка-число и число-строка](#перевод-строка-число-и-число-строка)
+ [Форматированный ввод и вывод в буфер](#форматированный-ввод-и-вывод-в-буфер)
+ [Работа с локалью](#работа-с-локалью)

## Копирование

```c
void * memcpy (void * destination, const void * source, size_t num);
```

Копирует участок памяти из `source` в `destination`, размером `num` байт. Функция очень полезная, с помощью неё, например, можно скопировать объект или перенести участок массива, вместо поэлементного копирования. Функция производит бинарное копирование, тип данных не важен. Например, удалим элемент из массива и сдвинем остаток массива влево.

```c
#include <conio.h>
#include <stdio.h>
#include <string.h>
 
#define SIZE 10
 
int main() {
    int a[SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    unsigned index;
    int i;
 
    printf("Enter index [0 .. 9]");
    scanf("%ud", &index);
    index = index < SIZE? index: SIZE-1;
    memcpy(&a[index], &a[index+1], sizeof(int) * (SIZE - index - 1));
 
    for (i = 0; i < SIZE; i++) {
        printf("%d ", a[i]);
    }
    getch();
}
```

Функция меняет местами две переменные:

```c
#include <conio.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
void swap(void* a, void* b, size_t size) {
    void *tmp = malloc(size);
    memcpy(tmp, a, size);
    memcpy(a, b, size);
    memcpy(b, tmp, size);
    free(tmp);
}
 
int main() {
    float a = 300.456;
    float b = 0.645;
 
    swap(&a, &b, sizeof(float));
    printf("a = %.3f\nb = %.3f", a, b);
    getch();
}
```

Здесь хотелось бы отметить, что функция выделяет память под временную переменную. Это дорогостоящая операция. Для улучшения производительности стоит передавать функции временную переменную, которая будет создана один раз.

```c
#include <conio.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
void swap(void* a, void* b, void* tmp, size_t size) {
    memcpy(tmp, a, size);
    memcpy(a, b, size);
    memcpy(b, tmp, size);
}
 
int main() {
    float a = 300.456;
    float b = 0.645;
    float tmp;
 
    swap(&a, &b, &tmp, sizeof(float));
    printf("a = %.3f\nb = %.3f", a, b);
    getch();
}
```

```c
void* memmove (void * destination, const void * source, size_t num);
```

Копирует блок памяти из `source` в `destination` размером `num` байт с той разницей, что области могут пересекаться. Во время копирования используется промежуточный буфер, который предотвращает перекрытие областей.

```c
#include <stdio.h>
#include <string.h>
#include <conio.h>
 
void main () {
    char str[] = "memmove can be very useful......";
    memmove (str + 20, str + 15, 11);
    puts(str);
    getch();
}
```

Пример взят из [cplusplus.com](https://www.cplusplus.com/reference/cstring/memmove/)

```c
char* strcpy (char * destination, const char* source );
```

Копирует одну строку в другую, вместе с нулевым символом. Также возвращает указатель на `destination`.

```c
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
 
void main () {
    char buffer[128];
    char *word = NULL;
 
    scanf("%127s", buffer);
    word = (char*) malloc(strlen(buffer)+1);
    strcpy(word, buffer);
 
    printf("%s", word);
    free(word);
    getch();
}
```

Можно копировать и по-другому

```c
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
 
void main () {
    char buffer[128];
    char *word = NULL;
    char *other = NULL;
 
    scanf("%127s", buffer);
    word = (char*) malloc(strlen(buffer)+1);
    other = strcpy(word, buffer);
 
    printf("%s", other);
    free(other);
    getch();
}
```

```c
char* strncpy (char* destination, const char* source, size_t num);
```

Копирует только `num` первых букв строки. `0` в конец не добавляется автоматически. При копировании из строки в эту же строку части не должны пересекаться (при пересечении используйте `memmove`)

```c
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
 
void main () {
    char word[] = "Aloha, Hawaii";
    char aloha[20];
    char hawaii[20];
 
    strncpy(aloha, word, 5);
    aloha[5] = 0;
    strncpy(hawaii, &word[7], 7);
 
    printf("%s, %s", aloha, hawaii);
    getch();
}
```

---
[Содержание](#содержание)

## Конкатенация (склеивание)

```c
char* strcat (char * destination, const char * source);
```

Добавляет в конец `destination` строку `source`, при этом затирая первым символом нулевой. Возвращает указатель на `destination`.

```c
char* strncat (char * destination, const char * source, size_t num);
```

Добавляет в конец строки `destination` num` символов второй строки. В конец добавляется нулевой символ.

```c
#include <stdio.h>
#include <string.h>
#include <conio.h>
 
void main () {
    char a[255];
    char b[128];
    scanf("%127s", a);
    scanf("%127s", b);
    strncat(a, b, strlen(b)/2);
    printf("%s", a);
    getch();
}
```

---
[Содержание](#содержание)

## Сравнение строк

```c
int strcmp (const char * str1, const char * str2);
```

Возвращает 0, если строки равны, больше нуля, если первая строка больше, меньше нуля, если первая строка меньше. Сравнение строк происходит посимвольно, сравниваются численные значения. Для сравнения строк на определённом языке используется `strcoll`

```c
int strcoll (const char * str1, const char * str2);
```

```c
int strncmp (const char * str1, const char * str2, size_t num);
```

сравнение строк по первым `num` символам

Пример - сортировка массива строк по первым трём символам:

```c
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
 
int cmp(const void *a, const void *b) {
    return strncmp((char*) a, (char*) b, 3);
}
 
void main() {
    char words[][128] = {
        "Solar",
        "Obscurus",
        "Tempestus",
        "Ultima",
        "Pacificus"
    };
    int i;
 
    qsort(words, 5, 128, cmp);
    for (i = 0; i < 5; i++) {
        printf("%s\n", words[i]);
    }
    getch();
}
```

```c
size_t strxfrm (char * destination, const char * source, size_t num);
```

Трансформация строки в соответствии с локалью. В строку `destination` копируется `num` трансформированных символов строки `source` и возвращается её длина. Если `num == 0` и `destination == NULL`, то возвращается просто длина строки.

```c
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <locale.h>
 
void main() {
    char input[128];
    char output[128];
 
    scanf("%127s", input);
    //Выводи введённую строку
    printf("%s\n", input);
    //Проводим преобразование, ничего не меняется
    strxfrm(output, input, 128);
    printf("%s\n", output);
    //Изменяем локаль
    setlocale(LC_ALL, ".1251");
    strxfrm(output, input, 128);
    printf("%s\n", output);
    getch();
}
```

---
[Содержание](#содержание)

## Поиск

```c
void* memchr (void * ptr, int value, size_t num);
```

Проводит поиск среди первых `num` байтов участка памяти, на который ссылается `ptr`, первого вхождения значения `value`, которое трактуется как `unsigned char`. Возвращает указатель на найденный элемент, либо `NULL`.

```c
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
 
void main() {
    char str[] = "Hello World!";
    char *ptr = NULL;
 
    ptr = (char*) memchr(str, '\0', 4000);
    if (ptr != NULL) {
        printf("first zero byte address is %p, strlen = %d", ptr, ptr - str);
    } else {
        printf("no null byte in memory block");
    }
    getch();
}
```

```c
char* strchr (char * str, int character);
```

Возвращает указатель на место первого вхождения `character` в строку `str`. Очень похожа на функцию `memchr`, но работает со строками, а не с произвольным блоком памяти.

```c
size_t strcspn ( const char * str1, const char * str2 );
```

Возвращает адрес первого вхождения любой буквы из строки `str2` в строке `str1`. Если ни одно включение не найдено, то возвратит длину строки.

Пример - найдём положение всех гласных в строке:

```c
#include <stdio.h>
#include <conio.h>
#include <string.h>
 
void main() {
    char str[] = "So if you want to love me\n"
                 "Then darling don't refrain\n"
                 "Or I'll just end up walking\n"
                 "In the cold November rain\n";
    char vowels[] = "aeiouy";
    int i;
 
    i = 0;
    while (str[i]) {
        i = i + strcspn(&str[i], vowels);
        printf("%d ", i);
        i++;
    }
    getch();
}
```

Здесь обратите внимание на строку `i++` после `printf`. Если бы её не было, то `strcspn` возвращал бы всегда 0, потому что в начале строки стояла бы гласная, и произошло зацикливание.

Для решения этой задачи гораздо лучше подошла функция, которая возвращает указатель на первую гласную.

```c
char* strpbrk (char * str1, const char * str2)
```

Функция очень похожа на `strcspn`, только возвращает указатель на первый символ из строки `str1`, который есть в строке `str2`. Выведем все гласные в строке:

```c
#include <stdio.h>
#include <conio.h>
#include <string.h>
 
void main() {
    char str[] = "Cos' it's a bittersweet symphony this life...\n"
                 "Trying to make ends meet, you're a slave to the money then you die.";
    char vowels[] = "aeiouy";
    char *p = NULL;
 
    p = strpbrk(str, vowels);
    while (p) {
        printf("%c ", *p);
        p++;
        p = strpbrk(p, vowels);
    }
    getch();
}
```

```c
char* strrchr (char * str, int character );
```

Возвращает указатель на последнее вхождение символа в троку.

```c
size_t strspn (const char * str1, const char * str2);
```

Возвращает длину куска строки `str1`, начиная от начала, который состоит только из букв строки `str2`.

Пример - вывести число, которое встречается в строке:

```c
#include <stdio.h>
#include <conio.h>
#include <string.h>
 
void main() {
    char str[] = "on 21st of May";
    char nums[] = "0123456789";
    char number[10];
    uintptr_t i;
 
    //Определяем, где начинаются цифры
    size_t start = strcspn(str, nums);
    //Определяем, где они заканчиваются, относительно start
    size_t end = strspn(&str[start], nums);
     
    for (i = 0; i < end; i++) {
        printf("%c", str[start+i]);
    }
 
    getch();
}
```

```c
char* strstr (char * str1, const char * str2);
```

Возвращает указатель на первое вхождение строки `str2` в строку `str1`.

```c
#include <stdio.h>
#include <conio.h>
#include <string.h>
 
void main() {
    char str[] = "I'll drown my beliefs\n"
                 "To have you be in peace\n"
                 "I'll dress like your niece\n"
                 "And wash your swollen feet\n";
    char niece[] = "niece";
     
    char* p = strstr(str, niece);
    printf("%s", p);
    getch();
}
```

```c
char* strtok (char * str, const char * delimiters);
```

Разбивает строку на токены. В данном случае токенами считаются последовательности символов, разделённых символами, входящими в группу разделителей.

```c
#include <stdio.h>
#include <conio.h>
#include <string.h>
 
void main() {
    char str[] = "After working in India during the late 1970s and 1980s, "
        "Shankar's profile in the West began to rise again in the mid-1990s "
        "as his music found its way into club DJ sets, particularly in London.";
    char delim[] = " \t\n\,.-";
    char *p = strtok(str, delim);
    while (p != NULL) {
        printf ("%s\n",p);
        p = strtok (NULL, delim);
    }
    getch();
}
```

---
[Содержание](#содержание)

## Длина строки и заполнение символами

```c
void * memset (void * ptr, int value, size_t num);
```

Заполняет блок памяти символами `value` числом `num` штук. Например, можно заполнить массив или структуру нулями.

```c
#include <stdio.h>
#include <conio.h>
#include <string.h>
 
void main() {
    int arr[10][10];
    int i;
 
    memset(arr, 0, 10*10*sizeof(int));
    for (i = 0; i < 10; i++) {
        arr[i][i] = 1;
    }
 
    for (i = 0; i < 10; i++) {
        int j;
        for (j = 0; j < 10; j++) {
            printf("%d", arr[i][j]);
        }
        printf("\n");
    }
    getch();
}
```

Самая популярная функция

```c
size_t strlen ( const char * str );
```

Возвращает длину строки - число символов от начала до первого вхождения нулевого.

---
[Содержание](#содержание)

## Перевод строка-число и число-строка

```c

int atoi (const char * str);
```

Переводит строку в целое

```c
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
 
void main() {
    char ex1[] = "   23  ";
    char ex2[] = "rule43";
    char ex3[] = "21st of May";
    printf("%d\n", atoi(ex1));
    printf("%d\n", atoi(ex2));
    printf("%d\n", atoi(ex3));
    getch();
}
```

```c
double atof (const char* str);
```

Переводит строку в число типа `double`.

```c
long int atol ( const char * str );
```

Переводит строку в число типа `long`

Все функции такого рода имеют название XtoY, где X и Y - сокращения типов. A обозначает ASCII.

Соответственно, имеется обратная функция itoa (больше нет). Таких функций в библиотеке `stdlib.h` очень много, все их рассматривать не хватит места.

---
[Содержание](#содержание)

## Форматированный ввод и вывод в буфер

Можно также выделить две функции `sprintf` и `sscanf`. Они отличаются от `printf` и `scanf` тем, что выводят данные и считывают их из буфера. Это, например, позволяет переводить строку в число и число в строку. Например:

```c
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
 
void main() {
    int i;
    float f;
    char buffer[128];
    scanf("%d", &i);
    scanf("%f", &f);
    sprintf(buffer, "%d", i);
    printf("%s\n", buffer);
    sprintf(buffer, "%.3f", f);
    printf("%s", buffer);
    getch();
}
```

Вообще, работа со строками - задача более глобальная, чем можно себе представить. Так или иначе, практически каждое приложение связано с обработкой текста.

---
[Содержание](#содержание)

## Работа с локалью

```c
char* setlocale (int category, const char* locale);
```

Устанавливает локаль для данного приложения. Если `locale` равно `NULL`, то `setlocale` может быть использована для получения текущей локали.

Локаль хранит информацию о языке и регионе, специфичную для работы функций ввода, вывода и трансформации строк. Во время работы приложения устанавливается локаль под названием "C", которая совпадает с настройками локали по умолчанию. Эта локаль содержит минимум информации, и работа программы максимально предсказуема. Локаль "C" также называется "". Константы `category` определяют, на что воздействует изменение локали.

**Значения параметра `category`:**

Имя | На что влияет
-- | --
LC_ALL | На всю локаль
LC_COLLATE | На поведение strcoll и strxfrm.
LC_CTYPE | На поведение функций, работающих с символами.
LC_NUMERIC | На десятичный разделитель в числах.
LC_TIME | На поведение strftime.

Строка `locale` содержит имя локали, например "En_US" или "cp1251"

---
[Содержание](#содержание)
