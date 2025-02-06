# 28. Указатели на функции

![Указатели на функции](./Pictures/28_c_function_pointers_theme.jpg)

## Содержание

+ [Указатели на функции](#указатели-на-функции)
+ [Массив указателей на функции](#массив-указателей-на-функции)
+ [qsort и bsearch](#qsort-и-bsearch)

## Указатели на функции

Как уже обсуждалось ранее функции – это набор команд, которые расположены в соответствующей области памяти.

Вызов функции – это сохранение состояния, передача аргументов и переход по адресу, где располагается функция.

В си есть возможность создавать указатели на функции. Указатели на функции позволяют упростить решение многих задач. Совместно с `void` указателями можно создавать функции общего назначения (например, сортировки и поиска).

Указатели позволяют создавать функции высших порядков (функции, принимающие в качестве аргументов функции):

+ отображение,
+ свёртки,
+ фильтры и пр.

Указатели на функции позволяют уменьшать цикломатическую сложность программ, создавать легко масштабируемые конструкции. Рассмотрим пример. Создадим функцию и указатель на эту функцию

```c
#include <conio.h>
#include <stdio.h>
 
int sum(int a, int b) {
    return a + b;
}
 
void main () {
    //Объявляем указатель на функцию
    int (*fptr)(int, int) = NULL;
    int result;
    //Присваиваем указателю значение - адрес функции
    //Это похоже на работу с массивом: операцию взятия адреса использовать не нужно
    fptr = sum;
    //Вызов осуществляется также, как и обычной функции
    result = fptr(10, 40);
    printf("%d", result);
    getch();
}
```

Синтаксис объявления указателей на функцию

```c
<возвращаемый тип> (* <имя>)(<тип аргументов>);
```

```c
#include <conio.h>
#include <stdio.h>
 
int dble(int a) {
    return 2*a;
}
 
int deleteEven(int a) {
    if (a % 2 == 0) {
        return 0;
    } else {
        return a;
    }
}
 
//Функция принимает массив, его размер и указатель на функцию,
//которая далее применяется ко всем элементам массива
void map(int *arr, unsigned size, int (*fun)(int)) {
    unsigned i;
    for (i = 0; i < size; i++) {
        arr[i] = fun(arr[i]);
    }
}
 
void main () {
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    unsigned i;
    map(a, 10, deleteEven);
    for (i = 0; i < 10; i++) {
        printf("%d ", a[i]);
    }
    map(a, 10, dble);
    printf("\n");
    for (i = 0; i < 10; i++) {
        printf("%d ", a[i]);
    }
    getch();
}
```

В этом примере мы создали функцию отображения, которая применяет ко всем элементам массива функцию, которая передаётся ей в качестве аргумента. Когда мы вызываем функцию `map`, достаточно просто передавать имена функций (они подменяются указателями). Запишем теперь функцию `map`, которая получает в качестве аргумента массив типа `void`:

```c
#include <conio.h>
#include <stdio.h>
 
void dbleInt(void *a) {
    *((int*) a) *= 2;
}
 
void deleteEvenInt(void* a) {
    int tmp = *((int*) a);
    if (tmp % 2 == 0) {
        *((int*) a) = 0;
    }
}
 
void dbleDouble(void *a) {
    *((double*) a) *= 2.0;
}
 
void deleteEvenDouble(void* a) {
    int tmp = *((double*) a);
    if (tmp % 2 == 0) {
        *((double*) a) = 0;
    }
}
 
//Функция принимает массив, его размер, размер одного элемента и указатель на функцию,
//которая далее применяется ко всем элементам массива
void map(void *arr, unsigned num, size_t size, void (*fun)(void *)) {
    unsigned i;
    char *ptr = (char*) arr;
    for (i = 0; i < num; i++) {
        fun((void*) (ptr + i*size));
    }
}
 
void main () {
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    double b[] = {1., 2., 3., 4., 5., 6., 7., 8., 9., 10.};
    unsigned i;
    //Работаем с массивом типа int
    map(a, 10, sizeof(int), deleteEvenInt);
    for (i = 0; i < 10; i++) {
        printf("%d ", a[i]);
    }
    map(a, 10, sizeof(int), dbleInt);
    printf("\n");
    for (i = 0; i < 10; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    //Работаем с массивом типа double
    map(b, 10, sizeof(double), deleteEvenDouble);
    for (i = 0; i < 10; i++) {
        printf("%.3f ", b[i]);
    }
    map(b, 10, sizeof(double), dbleDouble);
    printf("\n");
    for (i = 0; i < 10; i++) {
        printf("%.3f ", b[i]);
    }
    getch();
}
```

Вот где нам понадобились указатели типа `void`. Так как `map` получает указатель на функцию, то все функции должны иметь одинаковые аргументы и возвращать один и тот же тип. Но аргументы функций должны быть разного типа, поэтому мы делаем их типа `void`. Функция `map` получает указатель типа `void (*)(void*)`, поэтому ей теперь можно передавать любую из четырёх функций.

Пример другой функции: функция `filter` получает указатель на массив и возвращает размер нового массива, оставляя в нём только те элементы, для которых переданный предикат возвращает логическую истину (предикат – функция, которая возвращает истину или ложь). Сначала напишем для массива типа `int`:

```c
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
 
int isOdd(int a) {
    return (a % 2 != 0);
}
 
int isGtThree(int a) {
    return a > 3;
}
 
unsigned int filter(int *arr, unsigned size, int (*pred)(int), int** out) {
    unsigned i;
    unsigned j; //размер возвращаемого масива   
    *out = (int*) malloc(sizeof(int)*size);
    for (i = 0, j = 0; i < size; i++) {
        if (pred(arr[i])) {
            (*out)[j] = arr[i];
            j++;
        }
    }
    *out = (int*) realloc(*out, j*sizeof(int));
    return j;
}
 
void main () {
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int *aOdd = NULL;
    int *aGtThree = NULL;
    unsigned i;
    unsigned size;
 
    size = filter(a, 10, isOdd, &aOdd);
    for (i = 0; i < size; i++) {
        printf("%d ", aOdd[i]);
    }
    printf("\n");
    size = filter(a, 10, isGtThree, &aGtThree);
    for (i = 0; i < size; i++) {
        printf("%d ", aGtThree[i]);
    }
    free(aOdd);
    free(aGtThree);
    getch();
}
```

Теперь для массива типа `void`

```c
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
 
int isOddInt(void *a) {
    return (*((int*) a) % 2 != 0);
}
 
int isGtThreeInt(void* a) {
    return *((int*) a) > 3;
}
 
int isOddDouble(void* a) {
    return (int)*((double*) a) / 2 != 0;
}
 
int isGtThreeDouble(void* a) {
    return *((double*) a) > 3.0;
}
 
unsigned int filter(void *arr, unsigned num, size_t size, int (*pred)(void*), void** out) {
    unsigned i;
    unsigned j; //размер возвращаемого масива   
    char* ptrIn = (char*) arr;
    char* ptrOut = NULL;
    *out = (void*) malloc(num*size);
    ptrOut = (char*) (*out);
    for (i = 0, j = 0; i < num; i++) {
        if (pred(ptrIn + i*size)) {
            memcpy(ptrOut + j*size, ptrIn + i*size, size);
            j++;
        }
    }
    *out = (void*) realloc(*out, j*size);
    return j;
}
 
void main () {
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    double b[] = {1., 2., 3., 4., 5., 6., 7., .8, .9, 10.,};
    int *aOdd = NULL;
    int *aGtThree = NULL;
    double *bOdd = NULL;
    double *bGtThree = NULL;
    unsigned i;
    unsigned size;
 
    size = filter(a, 10, sizeof(int), isOddInt, (void**)&aOdd);
    for (i = 0; i < size; i++) {
        printf("%d ", aOdd[i]);
    }
    printf("\n");
    size = filter(a, 10, sizeof(int), isGtThreeInt, (void**)&aGtThree);
    for (i = 0; i < size; i++) {
        printf("%d ", aGtThree[i]);
    }
    printf("\n");
    size = filter(b, 10, sizeof(double), isOddDouble, (void**)&bOdd);
    for (i = 0; i < size; i++) {
        printf("%.3f ", bOdd[i]);
    }
    printf("\n");
    size = filter(b, 10, sizeof(double), isGtThreeDouble, (void**)&bGtThree);
    for (i = 0; i < size; i++) {
        printf("%.3f ", bGtThree[i]);
    }
 
    free(aOdd);
    free(bOdd);
    free(aGtThree);
    free(bGtThree);
    getch();
}
```

Ещё одна функция – свёртка. Она получает в качестве аргументов массив и функцию от двух аргументов.

Эта функция действует следующим образом:

+ сначала она применяется к первым двум аргументам,
+ затем она применяется к третьему аргументу и результату предыдущего вызова,
+ затем к четвёртому аргументу и результату предыдущего вызова и т.д.

С помощью свёртки можно, например, найти сумму всех элементов массива, максимальный элемент массива, факториал числа и т.п.

```c
#include <conio.h>
#include <stdio.h>
 
int sum(int a, int b) {
    return a + b;
}
 
int maxx(int a, int b) {
    return (a > b)? a: b;
}
 
int mul(int a, int b) {
    return a*b;
}
 
void fold(int *arr, unsigned size, int (*fun)(int, int), int *acc) {
    unsigned i;
    *acc = fun(arr[0], arr[1]);
    for (i = 2; i < size; i++) {
        *acc = fun(*acc, arr[i]);
    }
}
 
void main () {
    int a[] = {1, 2, 3, 4, 5, 10, 9, 8, 7, 6};
    int result;
     
    fold(a, 10, sum, &result);
    printf("%d\n", result);
    fold(a, 10, maxx, &result);
    printf("%d\n", result);
    fold(a, 10, mul, &result);
    printf("%d\n", result);
 
    getch();
}
```

Последний пример: функция сортировки вставками для массива типа `void`. Так как тип массива не известен, то необходимо передавать функцию сравнения.

```c
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
int cmpIntDesc(void *a, void* b) {
    return *((int*) a) < *((int*) b);
}
 
int cmpIntAsc(void *a, void* b) {
    return *((int*) a) > *((int*) b);
}
 
int cmpDoubleAsc(void *a, void* b) {
    return *((double*) a) < *((double*) b);
}
 
int cmpDoubleDesc(void *a, void* b) {
    return *((double*) a) > *((double*) b);
}
 
void insertionSort(void* arr, unsigned num, size_t size, int (*cmp)(void *a, void *b)) {
    unsigned i, j;
    char *ptr = (char*) arr;
    char *tmp = (char*) malloc(size);
    for (i = 1; i < num; i++) {
        if (cmp(ptr + i*size, ptr + (i-1)*size)) {
            j = i;
            while (cmp(ptr + j*size, ptr + (j-1)*size) && j > 0) {
                memcpy(tmp, ptr + j*size, size);
                memcpy(ptr + j*size, ptr + (j-1)*size, size);
                memcpy(ptr + (j-1)*size, tmp, size);
                j--;
            }
        }
    }
}
 
void main () {
    int a[] = {1, 2, 3, 4, 5, 10, 9, 8, 7, 6};
    double b[] = {1, 2, 3, 4, 5, 10, 9, 8, 7, 6};
    int i;
 
    insertionSort(a, 10, sizeof(int), cmpIntAsc);
    for (i = 0; i < 10; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    insertionSort(a, 10, sizeof(int), cmpIntDesc);
    for (i = 0; i < 10; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    insertionSort(b, 10, sizeof(double), cmpDoubleAsc);
    for (i = 0; i < 10; i++) {
        printf("%.3f ", b[i]);
    }
    printf("\n");
    insertionSort(b, 10, sizeof(double), cmpDoubleDesc);
    for (i = 0; i < 10; i++) {
        printf("%.3f ", b[i]);
    }
 
    getch();
}
```

---
[Содержание](#содержание)

## Массив указателей на функции

Массив указателей на функции определяется точно также, как и обычный массив – с помощью квадратных скобок после имени:

```c
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
 
#define ERROR_DIV_BY_ZERO -2
#define EPSILON 0.000001f
 
float doSum(float a, float b) {
    return a + b;
}
 
float doSub(float a, float b) {
    return a - b;
}
 
float doMul(float a, float b) {
    return a * b;
}
 
float doDiv(float a, float b) {
    if (fabs(b) <= EPSILON) {
        exit(ERROR_DIV_BY_ZERO);
    }
    return a / b;
}
 
void main() {
    float (*menu[4])(float, float);
    int op;
    float a, b;
    menu[0] = doSum;
    menu[1] = doSub;
    menu[2] = doMul;
    menu[3] = doDiv;
    printf("enter a: ");
    scanf("%f", &a);
    printf("enter b: ");
    scanf("%f", &b);
    printf("enter operation [0 - add, 1 - sub, 2 - mul, 3 - div]");
    scanf("%d", &op);
    if (op >= 0 && op < 4) {
        printf("%.6f", menu[op](a, b));
    }
    getch();
}
```

Точно также можно было создать массив динамически

```c
void main() {
    float (**menu)(float, float) = NULL;
    int op;
    float a, b;
    menu = (float(**)(float, float)) malloc(4*sizeof(float(*)(float, float)));
    menu[0] = doSum;
    menu[1] = doSub;
    menu[2] = doMul;
    menu[3] = doDiv;
    printf("enter a: ");
    scanf("%f", &a);
    printf("enter b: ");
    scanf("%f", &b);
    printf("enter operation [0 - add, 1 - sub, 2 - mul, 3 - div]");
    scanf("%d", &op);
    if (op >= 0 && op < 4) {
        printf("%.6f", menu[op](a, b));
    }
    free(menu);
    getch();
}
```

Часто указатели на функцию становятся громоздкими. Работу с ними можно упростить, если ввести новый тип. Предыдущий пример можно переписать так:

```c
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
 
#define ERROR_DIV_BY_ZERO -2
#define EPSILON 0.000001f
 
typedef float (*operation)(float, float);
 
float doSum(float a, float b) {
    return a + b;
}
float doSub(float a, float b) {
    return a - b;
}
float doMul(float a, float b) {
    return a * b;
}
float doDiv(float a, float b) {
    if (fabs(b) <= EPSILON) {
        exit(ERROR_DIV_BY_ZERO);
    }
    return a / b;
}
 
void main() {
    operation *menu = NULL;
    int op;
    float a, b;
    menu = (operation*) malloc(4*sizeof(operation));
    menu[0] = doSum;
    menu[1] = doSub;
    menu[2] = doMul;
    menu[3] = doDiv;
    printf("enter a: ");
    scanf("%f", &a);
    printf("enter b: ");
    scanf("%f", &b);
    printf("enter operation [0 - add, 1 - sub, 2 - mul, 3 - div]");
    scanf("%d", &op);
    if (op >= 0 && op < 4) {
        printf("%.6f", menu[op](a, b));
    }
    free(menu);
    getch();
}
```

Ещё один пример: функция `any` возвращает 1, если в переданном массиве содержится хотя бы один элемент, удовлетворяющий условию `pred` и 0 в противном случае.

```c
#include <conio.h>
#include <stdio.h>
 
typedef int (*Predicat)(void*);
 
int isBetweenInt(void* a) {
    return *((int*) a) > 10 && *((int*) a) < 12;
}
 
int isBetweenDouble(void* a) {
    return *((double*) a) > 10.0 && *((double*) a) < 12.0;
}
 
int any(void* arr, unsigned num, size_t size, Predicat pred) {
    unsigned i;
    char* ptr = (char*) arr;
    for (i = 0; i < num; i++) {
        if (pred(ptr + i*size)) {
            return 1;
        }
    }
    return 0;
}
 
void main() {
    int a[10] = {1, 1, 2, 2, 3, 0, 1, 2, 1, 3};
    double b[10] = {1, 2, 11, 2, 3, 4, 5, 6, 7, 10};
 
    printf("has 'a' any value > 10 and < 12? %d\n", any(a, 10, sizeof(int), isBetweenInt));
    printf("has 'b' any value > 10 and < 12? %d", any(b, 10, sizeof(double), isBetweenDouble));
 
    getch();
}
```

---
[Содержание](#содержание)

## qsort и bsearch

В библиотеке `stdlib` си имеется несколько функций, которые получают в качестве аргументов указатели на функции.

Функция `qsort` получает такие же аргументы, как и написанная нами функция `insertionSort`:

+ массив типа void,
+ размер массива,
+ размер элемента и
+ указатель на функцию сравнения.

Давайте посмотрим простой пример - сортировка массива строк:

```c
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
 
#define SIZE 10
 
//qsort передаёт функции сравнения указатели на элементы.
//но наш массив - это массив указателей, так что qsort будет
//передавать указатели на указатели
int cmpString(const void* a, const void* b) {
    return strcmp(*(const char**) a, *(const char**) b);
}
 
void main() {
    char *words[SIZE];
    char buffer[128];
    int i, length;
 
    printf("Enter %d words:", SIZE);
    for (i = 0; i < SIZE; i++) {
        scanf("%127s", buffer);
        length = strlen(buffer);
        words[i] = (char*) malloc(length+1);
        strcpy(words[i], buffer);
    }
 
    printf("\n");
    qsort(words, SIZE, sizeof(char*), cmpString);
    for (i = 0; i < SIZE; i++) {
        printf("%s\n", words[i]);
        free(words[i]);
    }
    getch();
}
```

Функция `bsearch` проводит бинарный поиск в отсортированном массиве и получает указатель на функцию сравнения, такую же, как и функция `qsort`. В случае, если элемент найден, то она возвращает указатель на этот элемент, если элемент не найден, то `NULL`.

```c
#include <stdio.h>
#include <conio.h>
 
int cmpInt(const void* a, const void* b) {
    return *(int*) a - *(int*) b;
}
 
void main() {
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int elm;
    int *index;
    printf("Enter number to search: ");
    scanf("%d", &elm);
    index = (int*) bsearch(&elm, a, 10, sizeof(int), cmpInt);
    if (index == NULL) {
        printf("element not found");
    } else {
        printf("index = %d", (index - a));
    }
    getch();
}
```

---
[Содержание](#содержание)
