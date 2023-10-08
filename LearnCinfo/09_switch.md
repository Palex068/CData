![09](/LearnCinfo/Pictures/09_01.PNG)

|[Ветвления](/LearnCinfo/08_branches.md)|[Оглавление](/LearnCinfo/README.md) | [Логические операторы](/LearnCinfo/10_logic_operators.md)|
|:-|:-:|-:|

# Оператор Switch

Рассмотрим пример из темы "ветвления". Программа выводит название дня недели по порядковому номера

```c
#include<conio.h>
#include<stdio.h>
 
int main() {
    unsigned day;
 
    printf("Enter day ");
    scanf("%d", &day);
 
    if (day > 7) {
        day = day % 7;
    }
 
    if (day == 0) {
        printf("Sunday");
    } else if (day == 1) {
        printf("Monday");
    } else if (day == 2) {
        printf("Tuesday");
    } else if (day == 3) {
        printf("Wednesday");
    } else if (day == 4) {
        printf("Thursday");
    } else if (day == 5) {
        printf("Friday");
    } else if (day == 6) {
        printf("Saturday");
    } 
 
    getch();
}
```

Этот код состоит из семи идущих друг за другом операторов if. Его код можно упростить с помощью оператора switch

```c
#include<conio.h>
#include<stdio.h>
 
int main() {
    unsigned day;
 
    printf("Enter day ");
    scanf("%d", &day);
 
    if (day > 7) {
        day = day % 7;
    }
 
    switch (day) {
    case 0:
        printf("Sunday");
        break;
    case 1:
        printf("Monday");
        break;
    case 2:
        printf("Tuesday");
        break;
    case 3:
        printf("Wednesday");
        break;
    case 4:
        printf("Thursday");
        break;
    case 5:
        printf("Friday");
        break;
    default:
        printf("Saturday");
    }
 
    getch();
}
```

Оператор switch принимает в качестве аргумента число, и в зависимости от его значения выполняет те или иные команды.

```c
switch (<переменная>) {
    case <значение 1>:
        <ветвь 1>
    [case <значение 2>:
        <ветвь 2>]
    [default:
        <действия по умолчанию>]
}
```

Если значение переменной не соответствует ни одному case, то выполняется default ветвь. Она может отсутствовать, тогда вообще ничего не выполняется.

В примере выше каждая ветвь оканчивается оператором break. Это важно. Когда компьютер видит оператор break, он выходит из оператора switch. Если бы он отсутствовал, то программа "провалилась" бы дальше, и стала выполнять следующие ветви.

```c
#include<conio.h>
#include<stdio.h>
 
int main() {
    unsigned day;
 
    printf("Enter day ");
    scanf("%d", &day);
 
    if (day > 7) {
        day = day % 7;
    }
 
    switch (day) {
    case 0:
        printf("Sunday");
    case 1:
        printf("Monday");
    case 2:
        printf("Tuesday");
    case 3:
        printf("Wednesday");
    case 4:
        printf("Thursday");
    case 5:
        printf("Friday");
    default:
        printf("Saturday");
    }
 
    getch();
}
```

Введите значение, например 3, и вы увидите, что программа выведет

>WednesdayThursdayFridaySaturday

то есть все ветви, после найденной.

Операторы каждой из ветвей могут быть обрамлены фигурными скобками (и так даже лучше). Тогда каждая из ветвей будет отдельным блоком, в котором можно определять свои переменные. Пример программы, которая запрашивает у пользователя число, оператор и второе число и выполняет действие.

```c
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
 
int main() {
    float a, b, c;
    char op;
 
    scanf("%f %c %f", &a, &op, &b);
    switch (op) {
        case '+': {
            c = a + b;
            break;
        }
        case '-': {
            c = a - b;
            break;
        }
        case '/': {
            if (b != 0.0) {
                c = a / b;
            } else {
                printf("Error: divide by zero");
                getch();
                exit(1);
            }
            break;
        }
        case '*': {
            c = a * b;
            break;
        }
        default:
            printf("No operation defined");
            getch();
            exit(1);
    }
 
    printf("%.6f", c);
    getch();
}
```

Если ввести

>1 + 2

то будет выведен результат операции 1 + 2 = 3

Хочу обратить внимание, что литеры типа '+' и т.п. воспринимаются в качестве чисел, поэтому их можно использовать в операторе switch. 

В этой программе использовалась функция exit из библиотеки stdlib. Функция останавливает работу программы и возвращает результат её работы. 

Если возвращается истина (ненулевое значение), то это значит, что программа была выполнена с ошибкой.

Ветвь default может располагаться в любом месте, не обязательно в конце. Этот код также будет нормально работать

```c
switch (day) {
case 0:
    printf("Sunday");
    break;
case 1:
    printf("Monday");
    break;
case 2:
    printf("Tuesday");
    break;
case 3:
    printf("Wednesday");
    break;
case 4:
    printf("Thursday");
    break;
default:
    printf("Saturday");
    break;
case 5:
    printf("Friday");
    break;
}
```

`default` здесь также нуждается в операторе `break`, как и другие ветви, иначе произойдёт сваливание вниз. 

Несмотря на то, что так можно писать, это плохой стиль программирования. 

Ветвь `default` логически располагается в конце, когда других вариантов больше нет.

Возможные значения аргумента оператора `switch` могут располагаться в любом порядке, но должны быть константными значеними. 

Это значит, что следующий код не заработает

```c
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
  
int main() {
//Это, конечно, константа, но не может быть использована как
//значение для оператора switch
    const int monday = 0;
    unsigned day;
  
    printf("Enter day ");
    scanf("%d", &day);
  
    if (day > 7) {
        day = day % 7;
    }
  
    switch (day) {
    case monday:
        printf("Sunday");
        break;
    case 1:
        printf("Monday");
        break;
    case 2:
        printf("Tuesday");
        break;
    case 3:
        printf("Wednesday");
        break;
    case 4:
        printf("Thursday");
        break;
    default:
        printf("Saturday");
        break;
    case 5:
        printf("Friday");
        break;
    }
  
    getch();
}
```
[Содержание](#содержание)

<hr>

|[Ветвления](/LearnCinfo/08_branches.md)|[Оглавление](/LearnCinfo/README.md) | [Логические операторы](/LearnCinfo/10_logic_operators.md)|
|:-|:-:|-:|