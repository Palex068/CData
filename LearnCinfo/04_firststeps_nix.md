![04](/LearnCinfo/Pictures/04_01.PNG)

|[Пишем первую программу (Windows)](/LearnCinfo/03_firststeps.md)|[Оглавление](/LearnCinfo/README.md) | [Переменные](/LearnCinfo/05_variables.md)|
|:-|:-:|-:|

# Первая программа на си под linux

Академическое программирование на си на unix-like операционных системах достаточно тривиально. 

В курсе вы не будете делать сложных программ, которые будут зависеть от особенностей операционной системы и среды программирования, они не будут требовать наличия файлов сборки. Программа на си пишется в любом удобном для вас текстовом редакторе. Пример простой программы:

```c
#include <stdio.h>
  
int main(int argc, char* argv[]) {
    printf("Hello, World!");
    return 0;
}
```

Сохраните файл в удобном месте. Пусть он называется hello.c. Для компиляции в терминале вызовите команду cc или gcc и передайте в качестве аргумента имя вашего .c файла и имя выходного файла. Например, если вы находитесь в той же папке, что и ваш файл

```bash
сc hello.c –o hello
```

В результате вы получите исполняемый файл hello, который можно вызвать по имени.

```bash
./hello
```

Часто вновь созданный файл не имеет прав на исполнение, и вы получаете ошибку вроде

```bash
access denied
```

Для исправления ошибки необходимо назначить себе права на исполнение файла

```bash
chmod 760 hello
```

либо

```bash
chmod u+x hello
```

После чего файл можно будет исполнять.

В том случае, если у вас имеется несколько файлов, нужно передать компилятору имена всех си файлов, которые включены в проект. Например, пусть у вас есть три файла

simple.h

```c
#ifndef _SIMPLE_H_
#define _SIMPLE_H_
  
#include <stdio.h>
#include <conio.h>
  
void doSomething();
  
#endif
```

simple.c

```c
#include "simple.h"
  
void doSomething() {
    printf("It works!");
    _getch();
}
```

и main.c

```c
#include "simple.h"
  
int main(int argc, char* argv[]) {
    doSomething();
    return 0;
}
```

Вызов будет иметь вид

```bash
cc main.c simple.c -o hello
```

Сборку можно осуществлять с помощью make файла. Полное изучение возможностей make файлов не входит в нашу компетенцию.

Создайте файл с именем makefile и содержимым

```bash
hello:  hello.c simple.c
    gcc hello.c simple.c –o hello
clean:
    rm -rf hello
```

Здесь отступ – это единичная табуляция! Для компиляции и сборки вызовите команду make. make подхватит makefile и выполнит команду

```bash
gcc hello.c simple.c -o hello
```

Для удаления скомпилированного файла вызовите make clean.

|[Пишем первую программу (Windows)](/LearnCinfo/03_firststeps.md)|[Оглавление](/LearnCinfo/README.md) | [Переменные](/LearnCinfo/05_variables.md)|
|:-|:-:|-:|