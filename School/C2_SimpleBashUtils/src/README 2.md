# SimpleBashUtils guide School_21

Выполнено пиром: worfcris

## Content

### Предисловие

### CAT

1. Как работает cat
2. Аргументы командной строки
3. cat с одним файлом
4. cat с несколькими файлами
5. Структура
6. Парсим флаги
7. Парсим с помощью getopt (альтернативно)
8. Обработка флага -v
9. Тестирование
10. Обработка флагов -e и -t
11. Обработка флага -s
12. Обработка флагов -n и -b
13. Обработка GNU версии флагов
14. Декомпозиция, Makefile и сборка программы

### GREP

1. Как работает grep
2. Структура опций
3. Парсер аргументов
4. Debug информация
5. Парсинг опций -e и -f
6. Итоговый шаблон
7. Обработка флагов без -o
8. Обработка -o флага
9. Makefile и тесты

#### Предисловие

Рассмотрим собственную реализацию общеизвестных утилит cat и grep. Приведеные реализации значительно ограничены по сравнению с оригинальными, и не претендует на звание определенно точно польностью корректно работащих утилит. 

#### 1. Как работает cat

Всегда поможет:
`man cat`

Синопсис:
`cat [OPTION]... [FILE]...`

Возможные тестовые комбинации:
| Команда | Описание |
| ------  | ------ |
`cat` | дублирует построчно поток ввода.
`cat [file]` | выводит файл в консоль.
`cat [file1] [file2]` | выводит последовательно file1 и file2.
`cat [file1] - [file2]` | выводит file1 затем дублирует построчно поток ввода до `EOF` затем выводит file2. |
`cat -v [file]` | заменяет все символы с учетом ^ и M- notation.
`cat -n [file]` | нумерует все строки.
`cat -n [file] [file]` | нумерует все строки, начиная с начала для каждого файла .
`cat -e [file]` | выводит \n как $.
`cat -s [file]` | не выводит больше одной пустой строки подряд.
`cat -b [file]` | нумерует все не пустые строки.
`cat -t [file]` | выводит \t как ^I.
`cat -bensvt [file]` | всe выше перечисленные опции с учетом приоритетов.

#### 2. Аргументы командной строки

```c
int main(int argc, char *argv[]) {
  ...
  return 0;
}
```

argc - количество аргументов.
argv - массив аргументов в виде строк.

`argv[0] == "./[programm name]"`

#### 3. cat с одним файлом

Проверяем количество аргументов.
Если один аргумент, то работаем с потоком ввода, иначе открываем файл.

```c
int main(int argc, char *argv[]) {
  if (argc == 1) {
    cat_print(stdin);
  } else {
    cat_file(argc, argv);
  }
  return 0;
}
```

Считываем по одному символу пока не достигли конца файла, и выводим в stdout.

```c
void cat_print(FILE *fp) {
  char c;
  while ((c = fgetc(fp)) != EOF) fputc(c, stdout);
}
```

Пытаемся открыть файл на чтение, если удалось считываем файл посимвольно, иначе выводим ошибку.

```c
void cat_file(int argc, char *argv[]) {
  FILE *fp = fopen(argv[1], "r");
  if (fp) { 
    cat_print(fp);
    fclose(fp);
  } else {
    fprintf(stderr, "cat: %s: No such file or directory\n", argv[1]);
  }
}
```

#### 4. cat с несколькими файлами

Для того чтобы обработать несколько файлов достаточно добавить в функцию простой цикл. Просматриваем аргументы начиная с первого, так как в argv[0] содержится имя программы. Обрабатываем все аргументы, даже если не смогли прочитать какие-то из файлов ранее.

```c
for (int i = 1; i < argc; i++) {
  FILE *fp = fopen(argv[i], "r");
  ...
}

```
#### 5. Структура

Для организации хранения информации об используемых флагах можно применить структуру.
Подключим `stdbool.h` для использования более очевидных булевых переменных и объявим структуру с полями отображающими текущее состояние флагов. 

```c
#include <stdbool.h>

typedef struct options {
  bool non_blank_rows; // -b
  bool show_end; // -e
  bool all_rows; // -n
  bool squeezed; // -s
  bool show_tabs; // -t
  bool show_all; // -v
  int count;
} options;
```
#### 6. Парсим флаги

Необходимо проверить что приходящие в качестве аргументов флаги являются валидными. Стоит заметить что при первом же попавшемся не валидном флаге cat заканчивает свою работу с выводом ошибки. Так же нельзя передавать опции после передачи файлов, но можно обработать несколько опций подряд через пробел, обозначая их знаком `-`.

|Команда|Результат|
| ------  | ------|
|`cat -f [file]`|`cat: invalid option -- 'f'`|
|`cat -benstvq [file]`|`cat: invalid option -- 'q'`|
|`cat -benkstv [file]`|`cat: invalid option -- 'k'`|
|`cat -b enstv [file]`|попытка вывода `[enstv]` и `[file]`|
|`cat [file] -b -enstv`|попытка вывода файлов: `[file],[-b],[-enstv]`|
|`cat -benstv [file]`|успешный вывод `[file]`|
|`cat -b -e -n -s -t -v [file]`|успешный вывод `[file]`|

Подключим библиотеку для работы со строками.

```c
#include <string.h>
```

Объявим функцию, которая будет парсить наши флаги и сохранять результат в структуру.

```c
void parse_options(int argc, char *argv[], options *s_opt);
```

Теперь убедимся что в аргументах действительно после названия программы начали поступать флаги и запустим наш парсер, однако если в аргументах не было флагов необходимо разделить поведение функции работы с файлами с учетом пропуска аргументов отвечающих за флаги. Так как опции пока не обрабатываются, выведем информацию о количестве аргументов, считанных как флаги. 

```c
int main(int argc, char *argv[]) {
  if (argc == 1) {
    cat_print(stdin);
  } else {
    if (argv[1][0] == '-') { //получили что-то похожее на флаг в качестве аргумента
      options s_opt = {0};
      parse_options(argc, argv, &s_opt);
      if (!s_opt.count) //если количество удачно считаных аргументов в качестве флага равно нулю
        fprintf(stderr, "s21_cat: invalid options\n");
      else {
        printf("Parsed options successfully: %d\n", s_opt.count);
        cat_file(argc, argv, &s_opt);//начинаем работать с файлами с учетом считанных опций
      }
    } else
      cat_file(argc, argv, NULL);//работаем с файлами без опций
  }
  return 0;
}
```

Учтем аргументы считанные как опции перед работой с файлами.

```c
void cat_file(int argc, char *argv[], options *s_opt) {
  int i = s_opt ? 1 + s_opt->count : 1;
  for (; i < argc; i++) {
    FILE *fp = fopen(argv[i], "r");
    ...
  }
}
```

Наконец-то приступаем к парсеру, необходимо пройтись по всем аргументам пока не наткнемся на что-то не похожее на флаг. Причем если после обработки аргумента окажется что в нем присутствуют не валидные флаги, нужно закончить процесс парсинга с нулевым результатом успешно считанных параметров. 

```c
void parse_options(int argc, char *argv[], options *s_opt) {
  for (int i = 1; i < argc; i++) {
    if (argv[i][0] == '-' && !strstr(argv[i] + 1, "-")) { //Если только первый символ в аргументе '-'
      s_opt->count++;
      parse_short(argv[i], s_opt);
    }
    if (!s_opt->count) break;
  }
}
```

В конце концов понадобится простыня из `switch-case` или `if-else`.
Стоит не забывать прервать процесс парсера если опция оказалась не валидной.

```c
void parse_short(char *arg, options *s_opt) {
  int len = strlen(arg);
  for (int j = 1; j < len; j++) {
    if (s_opt->count) {
      switch (arg[j]) {
        case 'b':
          s_opt->non_blank_rows = true;
          break;
        ...
        default: // если не валидный флаг, обнуляем результат
          s_opt->count = 0;
          break;
      }
    } else
      break;
  }
}
```

#### 7. Парсим с помощью getopt (альтернативно)

В качестве альтернативного способа можно воспользоваться готовой библиотекой `getopt.h`. Для обработки флагов с помощью данной библиотеки понадобится строка содержащая все короткие опции и массив структуры для длинных опций.

```c
#include <getopt.h>
#define SHORT_OPTIONS "bensvt"
```

Функция `getopt_long()` обрабатывает аргументы командной строки и в случае совпадения с какой-либо из заданных опций возвращает `int` значение данного символа. В ином случае возращает символ `'?'` если короткая опция, и `0` в случае длинной опции.

```c
void parse_options_alt(int argc, char *argv[], options *s_opt) {
  
  const struct option long_options[] = {
      {"number-nonblank", no_argument, NULL, 'b'},
      {"number", no_argument, NULL, 'n'},
      {"squeeze-blank", no_argument, NULL, 's'},
      {NULL, 0, NULL, 0}};

	int ch;
  while ((ch = getopt_long(argc, argv, SHORT_OPTIONS, long_options, NULL)) !=
         -1) {
    switch (ch) {
      case 'b':
        s_opt->non_blank_rows = true;
        break;
      ...
      case '?':
      default:
        s_opt->count = 1;
        break;
    }
  }
}
```

Так же как и с обычной реализацией парсера, обрабатываем полученные опции. Индекс последней обработанного аргумента флага хранится с помощью библиотеки в переменной `optind`, а поле `count` структуры можно использовать как идентификатор ошибки не валидных аргументов.

```c
int main(int argc, char *argv[]) {
  if (argc == 1) {
    cat_print(stdin);
  } else {
    if (argv[1][0] == '-') {
      options s_opt = {0};
      parse_options_alt(argc, argv, &s_opt);
      if (!s_opt.count && optind) { //если не было ошибки и считаны опции 
        printf("Parsed options successfully: %d\n", optind - 1);
        cat_file(argc, argv, &s_opt);
      }
    } else
      cat_file(argc, argv, NULL);
  }
  return 0;
}

void cat_file(...) {
  int i = optind ? optind : 1;
  ...
}
```

#### 8. Обработка флага -v

Обработаем самый простой с точки зрения реализации флаг, преобразующий все неотображаемые символы в `^` и `M-` обозначениях (за исключением `\n` и `\t`). Для начала слегка изменим реализацию функции вывода. Теперь будем передавать в нее структуру с опциями, и если она существует перед выводом символа обработаем (приготовим) флаги. 

```c
void cat_print(FILE *fp, options *s_opt) {
  int c;
  while ((c = fgetc(fp)) != EOF) {
    if (s_opt) cat_cook(&c, s_opt);
    fputc(c, stdout);
  }
}

void cat_cook(int *c, options *s_opt) {
  cook_non_printed(c, s_opt);
}
```
Таблица ASCII:
![ASCII](https://i.stack.imgur.com/8JmRU.png)

Перевод в `^` и `M-` обозначения подразумевает смещение всех неотображаемых символов по таблице `ASCII` на символы привычные для понимания с префиксной записью `^` обозначающей `Ctrl + key` и `M-^` обозначающей `Meta` символ, или сочетание `Alt + key` в некоторых терминалах.

```c
void cook_non_printed(int *c, options *s_opt) {
  if (*c == '\n' || *c == '\t')
    ;
  else if (s_opt->show_all) {
    if (*c <= 31) {
      printf("^");
      *c += 64;
    } else if (*c == 127) {
      printf("^");
      *c = '?';
    } else if (*c >= 128 && *c < 128 + 32) {
      printf("M-^");
      *c -= 64;
    }
  }
}
```

В результате получим:

|Char|Dec|
|---|---|
|^@|0|
|^A|1|
...|...
|^_|31|
...|...
|M-^@|128|
|M-^A|129|
...|...
|M-^_|159|

#### 9. Тестирование

На данном этапе уже было бы неплохо протестировать получившуюся программу. Для этого придется сгенерировать тестовые файлы. 

```c
int main(int argc, char *argv[]) {
  srand(time(NULL) * atoi(argv[1]));
  for (int i = 2; i < argc; i++) generate_file(argv[i]);
}
```

Учтем что могут быть пустые файлы, одна или несколько пустых строк в начале, в конце, да и в любом месте файла. 

```c
void generate_file(char *file_name) {
  FILE *fp = fopen(file_name, "w");
  if (!strstr(file_name, "rand"))
    generate_rand(fp);
  else if (!strcmp(file_name, "empty"))
    ;
  else if (!strcmp(file_name, "lines"))
    generate_lines(fp);
  fclose(fp);
}

void generate_lines(FILE *fp) {
  int n = rand() % 4 + 1;
  for (int i = 0; i < n; i++) fwrite("\n", sizeof(char), 1, fp);
}
```

Так же будем использовать все возможные символы от 0 до 255, и все способы разделения текста.

```c
void generate_spaces(FILE *fp) {
  char spaces[] = {0x09, 0x0a, 0x0b, 0x0c, 0x0d};
  int n = rand() % 10 + 1;
  for (int i = 0; i < n; i++)
    fwrite(spaces + (rand() % sizeof(spaces)), sizeof(char), 1, fp);
}

void generate_rand(FILE *fp) {
  int n = rand() % 254 + 1;
  if (rand() % 2) generate_lines(fp);
  if (rand() % 2) generate_spaces(fp);
  for (int i = 0; i < n; i++) {
    char c = rand() % 255;
    if(c == 138) c++;
    fwrite(&c, sizeof(char), 1, fp);
  }
  if (rand() % 2) generate_lines(fp);
}
```


Напишем `bash` скрипт для тестирования текущей версии программы. Создадим тестовую дирректорию, скомпилируем утилиту и генератор тестовых файлов.

```bash
mkdir -p test
gcc -Wall -Wextra -Werror cat.c -o test/s21_cat
gcc -Wall -Wextra -Werror test_generate.c -o test/test_gen
cd test/
```

Зададим параметры и опции теста.

```bash
test_number=0
test_count=64
failed_count=0
files_list="rand1 rand2 rand3 empty lines"
options=(-v)
```

Генерируем тестовые файлы, и сверяем результат работы оригинальной утилиты с самописной.

```bash
while [ $test_count != 0 ]; do
    test_count=$((test_count -1))
		./test_gen $test_number $files_list
    for opt in ${options[@]}
    do
        echo -e "TEST NUMBER $test_number:"
        ./s21_cat $opt $files_list > s21_res
        cat $opt $files_list > cat_res
        echo -e "$(diff -s cat_res s21_res)\n"
        if [[ $(diff -q cat_res s21_res) ]]
        then
            echo "____________________________________________________________"
            echo -e "\nFAIL: test failed at $opt\n"
            failed_count=$((failed_count + 1))
        fi
        test_number=$((test_number + 1))
    done
done
```
Осталось обработать результат тестирования.

```bash
cd ..

echo "____________________________________________________________"
if [ $failed_count == 0 ]
	then
		echo -e "\nSUCCESS\n"
		rm -rf ./test
	else
		echo -e "\nFAIL COUNT: $failed_count\n"
fi
```

#### 10. Обработка флагов -e и -t

Для обработки флагов `-e` и `-t` достаточно дописать пару условий в функцию обработки флага `-v`, и не забывать что оба этих флага предполагают что была использована и опция `-v`, даже если она не указана явно. 

```c
void cook_non_printed(int *c, options *s_opt) {
  if (*c == '\n') {
    if (s_opt->show_end) printf("$");
  } else if (*c == '\t') {
    if (s_opt->show_tabs) {
      printf("^");
      *c = 'I';
    }
  } else if (s_opt->show_all) {
    ...
  }
}
```

#### 11. Обработка флага -s

Флаг `-s` подразумевает вывод не больше одной пустой строки подряд. Поэтому для начала добавим функционал подсчета пустых строк. Для этого модифируем структуру, добавив еще одно поле.

```c
typedef struct options {
  ...
  int empty_lines;
} options;
```

Чтобы понять, пустая ли попалась строка при посимвольной обработке, придется хранить предыдущий считанный символ. В начале считывания файла считаем что последний символ был `\n`. Также сбрасываем счетчик пустык строк в начале обработки файла и добавим на будущее проверку на конец файла. 

```c
void cat_print(FILE *fp, options *s_opt) {
  int c;
  int prev = '\n';
  if (s_opt) {
    s_opt->empty_lines = 0;
  }
  while ((c = fgetc(fp)) != EOF) {
    if (s_opt) cat_cook(&c, &prev, s_opt, fp);
    if (c != EOF) fputc(c, stdout);
    prev = c;
  }
}
```

Напишем функцию подсчета пустых строк, и функцию обработки флага -s, и добавим в меню готовки cat.

```c
void cook_empty(int *c, int *prev, options *s_opt) {
  if (*prev == '\n' && *c == '\n')
    s_opt->empty_lines++;
  else
    s_opt->empty_lines = 0;
}

void cat_cook(int *c, int *prev, options *s_opt, FILE *fp) {
  cook_empty(c, prev, s_opt);
  cook_squeezed(c, fp, s_opt);
  if(*c != EOF) cook_non_printed(c, s_opt);
}
```

Сама функция обработки флага будет продолжать считывать символы из файла, пока не упрется в непустую строку. Так как есть возможность достигнуть конца файла еще во время обработки,ранее была добавлена на такой случай.

```c
void cook_squeezed(int *c, FILE *fp, options *s_opt) {
  if (s_opt->squeezed && s_opt->empty_lines > 1) {
    while (*c == '\n') *c = fgetc(fp);
    s_opt->empty_lines = 0;
  }
}
```

#### 12. Обработка флагов -n и -b

Воспользуемся полем структуры `count` в качестве счетчика строк. Так как каждый файл нумеруется с начала, добавим сброс счетчика строк.

```c
void cat_print(FILE *fp, options *s_opt) {
  ...
  if (s_opt) {
    s_opt->empty_lines = 0;
    s_opt->count = 1;
  }
  ...
}
```

Добавим обработку номеров строк с учетом приоритетов.

```c
void cat_cook(int *c, int *prev, options *s_opt, FILE *fp) {
  cook_empty(c, prev, s_opt);
  cook_squeezed(c, fp, s_opt);
  if (*c != EOF) {
    cook_numbers(*prev, s_opt);
    cook_non_printed(c, s_opt);
  }
}
```

Сама функция проверяет началась ли новая строка, и если были использованы флаги -b или -n выводит соответственно номера для не пустых строк или номера всех строк.

```c
void cook_numbers(int prev, options *s_opt) {
  if (prev == '\n' && (s_opt->all_rows || s_opt->non_blank_rows)) {
    if (!(s_opt->non_blank_rows && s_opt->empty_lines > 0)) {
      printf("%6d\t", s_opt->count);
      s_opt->count++;
    }
  }
}
```

#### 13. Обработка GNU версии флагов

Добавим обаботку `GNU` версии флагов. Для коротких версий дополним полотно `switch-case`, с учетом того, что они не подразумевают опцию `-v`.

```c
void parse_short(char *arg, options *s_opt) {
  int len = strlen(arg);
  for (int j = 1; j < len; j++) {
    if (s_opt->count) {
      switch (arg[j]) {
        ...
        case 'E':
          s_opt->show_end = true;
          break;
        case 'T':
          s_opt->show_tabs = true;
          break;
        default:
          s_opt->count = 0;
          break;
      }
    } else
      break;
  }
}
```

Обработаем длинные версии флагов. Для этого придется немного модифицировать функцию парсера флагов. Теперь она разделена на обработку случаев коротких и длинных флагов.

```c
void parse_options(int argc, char *argv[], options *s_opt) {
  for (int i = 1; i < argc; i++) {
    if (argv[i][0] == '-') {
      s_opt->count++;
      if (!strstr(argv[i] + 1, "-"))
        parse_short(argv[i], s_opt);
      else if (argv[i][1] == '-')
        parse_options_long(argv[i], s_opt);
    }
    if (!s_opt->count) break;
  }
}
```

Ну и наконец обработаем необходимые варианты опций.

```c
void parse_options_long(char *argv, options *s_opt) {
  if (!strcmp(argv + 2, "number-nonblank"))
    s_opt->non_blank_rows = true;
  else if (!strcmp(argv + 2, "number"))
    s_opt->all_rows = true;
  else if (!strcmp(argv + 2, "squeeze-blank"))
    s_opt->squeezed = true;
  else {
    s_opt->count = 0;
  }
}
```

#### 14. Декомпозиция, Makefile и сборка программы

В заключении можно разбить функции на несколько модулей, и организовать сборку с помощью Makefile. Разберем случай с одним файлом исходного кода.

```Makefile
FLAGS=-Wall -Werror -Wextra
all: s21_cat

s21_cat: cat.o
	gcc $(FLAGS) cat.c -o s21_cat

cat_test: cat_test.sh
	bash cat_test.sh

cat.o: cat.c
	gcc $(FLAGS) -c cat.c

clean:
	rm -rf *.o
	rm -rf s21_cat
	rm -rf test
```

Дополним тесты всеми опциями, которые можем проверить и оставим этап компиляции утилиты на Makefile.

```bash
rm -rf test
mkdir -p test
cp s21_cat test/
gcc -Wall -Wextra -Werror test_generate.c -o test/test_gen
cd test/

...

options=(-s -e -n -v -b -t)
```

##### ADDITIVE TEST CASES

```
cat [file] //Если файл не существует
cat -benfstv [file] //Не валидный флаг

```

### GREP

#### 1. Как работает grep

Естественно, куда же без:
`man grep`

Синопсис:
`grep [options] template [file_name]`

Возможные тестовые комбинации:
| Команда | Описание |
| ------  | ------ |
`grep [template] [file]` | Выводит все строки из файла в которых найден соответстующий шаблон.
`grep -e [template1] -e [template2] [file]` | Выводит все строки из файла в которых найден соответстующий первый шаблон или второй.
`grep -f [template_file] [file]` | Выводит все строки из файла в которых найден соответствующие шаблоны из `[template_file]`.
`grep [template] [file1] [file2]` |  Выводит все строки из первого файла в которых найден соответстующий шаблон, затем так же из второго. Выводит перед строками имя файла, в котором они были найдены. |
`grep -i [template] [file]` | Игнорирует регистр.
`grep -v [template] [file]` | Инвертирует смысл поиска соответствий.
`grep -c [template] [file]` | Выводит только количество совпадающих строк.
`grep -l [template] [file]` | Выводит только совпадающие файлы.
`grep -n [template] [file]` | Выводит дополнительно номер строки.
`grep -h [template] [file]` | Подавляет вывод имени файла.
`grep -s [template] [file]` | Подавляет сообщения об ошибках чтения файла.
`grep -o [template] [file]` | Выводит только совпадающие (непустые) части из подходящей строки.

#### 2. Структура опций

Так же как и для cat создадим структуру для хранения основных состояний и опций программы. В данном случае необходимо сохранить информацию об считанных шаблонах, файлах откуда считывать шаблоны, и файлах для обработки. Ко всему этому понадобится строка шаблона для обработки регулярных выражений, состояние флагов. Счетчик количества полученных в аргументах файлов и счетчик подходящих совпадений.

```c
#include <stdbool.h>
#define SIZE 16
#define BUF_SIZE 2048

typedef struct options {
  char *patterns[SIZE];
  char *pattern_files[SIZE];
  char *files[SIZE];
  char pattern[BUF_SIZE];
  bool e_flag, i_flag, v_flag, c_flag, l_flag, n_flag, h_flag, s_flag, f_flag,
      o_flag;
  int files_count;
  int matches_count;
} options;
```

#### 3. Парсер аргументов

В отличие от cat, теперь могут попадаться опции подразумевающие аргумент сразу после них. Такие случаи необходимо учитывать и отдавать им приоритет. Но наивысшим приоритетом обладает шаблон, без которого утилита работать не будет. Это обязательный параметр и первый аргумент переденный в командной строке, который не будет считан как опция воспримется как шаблон а все последующие как файлы для обработки. Разберем большую функцию по кусочкам.

```c
void parse_options(int argc, char *argv[], options *s_opt) {
```

Объявим необходимые счетчики и переменную отвечающую за корректность ввода аргументов. 

```c
 int files_count = 0;
  int patterns_count = 0;
  int pattern_files_count = 0;
  bool is_valid = true;
```

Если корректность аргументов где-либо нарушена, прекратим парсинг. В порядке приоритетов: если попалась опция и это `-e` или `-f`, необходимо обработать сначала их. Если же это не опция, и шаблона еще не было, добавляем шаблон. В остальных случаем записываем как файл для обработки.

```c
for (int i = 1; i < argc; i++) {
  if (is_valid) {
    if (argv[i][0] == '-') {  //если встретилось что-то похожее на опцию
      if (argv[i][1] == 'e') {
        // parse e flag
      } else if (argv[i][1] == 'f') {
        // parse f flag
      } else {
        // обработка флагов
      }
    } else if (!s_opt->e_flag && !s_opt->f_flag) {  //если еще не было шаблона                 
      s_opt->e_flag = true; //считываем как шаблон
      s_opt->patterns[patterns_count++] = argv[i];
    } else  //если уже был шаблон считываем как файл
      s_opt->files[files_count++] = argv[i];
  } else {
    puts("illegal options");
    files_count = 0;
    break;
  }
}
```

Для обработки коротких опций уже стандартное полотно `switch-case`:

```c
switch (argv[i][j]) {
  case 'i':
    s_opt->i_flag = true;
    break;
  ...
  case 'e':
    //case e 
    break;
  case 'f':
    // case f
    break;
  default:
    is_valid = false;
    break;
  }
```

После обработки аргументов выведем полезную информацию для понимания что все работает как надо.

```c
if (is_valid) {
    printf("patterns: %d\n", patterns_count);
    printf("patterns files: %d\n", pattern_files_count);
  }
  s_opt->files_count = files_count;
}
```

#### 4. Debug информация

Рассмотрим как работает текущая версия программы, ожидается что она должна принимать первый аргумент вне зависимости от опций как шаблон а все последующие как файлы. Тогда порядок вызова функций временно определим как:

```c
int main(int argc, char *argv[]) {
  options s_opt = {0};
  parse_options(argc, argv, &s_opt);
  print_debug(s_opt);
  return 0;
}
```

Функция вывода debug информации пройдется по данным в структуре и выведет результат обработки аргументов.

```c
void print_arr(char *list[]) {
  int i = 0;
  while (list[i]) {
    putc('\t', stdout);
    puts(list[i]);
    i++;
  }
}

void print_debug(options s_opt) {
  if (s_opt.files_count) {
    printf("files count: %d\n", s_opt.files_count);
    puts("patterns:");
    print_arr(s_opt.patterns);
    puts("patterns files:");
    print_arr(s_opt.pattern_files);
    puts("files:");
    print_arr(s_opt.files);
    puts("final pattern:");
    if (s_opt.pattern) puts(s_opt.pattern);
  }
}
```

И в результате ожидаем результат работы в виде:

`./s21_grep temp file1 file2 file3`

```
patterns: 1
patterns files: 0
files count: 3
patterns:
        temp
patterns files:
files:
        file1
        file2
        file3
final pattern:
```

#### 5. Парсинг опций -e и -f

Добавим функции обработки опций с обязательным аргументом. 

```c
if (argv[i][1] == 'e') {
  parse_e_flag(s_opt, argv, &i, 2, &patterns_count);
} else if (argv[i][1] == 'f') {
  parse_f_flag(s_opt, argv, &i, 2, &pattern_files_count);
} else {
  ...
  switch(){
    ...
    case 'e':
      parse_e_flag(s_opt, argv, &i, j + 1, &patterns_count);
      j = len;
      break;
    case 'f':
      parse_f_flag(s_opt, argv, &i, j + 1, &pattern_files_count);
      j = len;
      break;
    ...
  }
} 
```

По окончанию работы с аргументами учтем что некоторые флаги несовместимы. 

```c
if (s_opt->o_flag && (s_opt->l_flag || s_opt->v_flag || s_opt->c_flag))
    s_opt->o_flag = 0;
```

В реализации рассматриваем все что идет после флага как дополнительный агрумент опции, или же следующий аргумент если это был последний символ. Используется статическая память для строк, так как, вероятно для такого проекта этого будет более чем достаточно. Можно улучшить утилиту заменив статику на динамическое изменение размера строки в случае необходимости.

```c
void parse_e_flag(options *s_opt, char *argv[], int *i, int j,
                  int *patterns_count) {
  s_opt->e_flag = true;
  if (argv[*i][j] != '\0') {
    char buf[BUF_SIZE] = "";
    strcat(buf, argv[*i] + j);
    s_opt->patterns[(*patterns_count)++] = buf;
  } else {
    s_opt->patterns[(*patterns_count)++] = argv[++(*i)];
  }
}

void parse_f_flag(options *s_opt, char *argv[], int *i, int j,
                  int *pattern_files_count) {
  s_opt->f_flag = true;
  if (argv[*i][j] != '\0') {
    char buf[BUF_SIZE] = "";
    strcat(buf, argv[*i] + j);
    s_opt->pattern_files[(*pattern_files_count)++] = buf;
  } else {
    s_opt->pattern_files[(*pattern_files_count)++] = argv[++(*i)];
  }
}
```

И в результате ожидаем результат работы в виде:

`./s21_grep temp1 -e temp2 -f patfile file1 file2 file3`

```
patterns: 2
patterns files: 1
files count: 3
patterns:
        temp1
        temp2
patterns files:
        patfile
files:
        file1
        file2
        file3
Final pattern:
```

#### 6. Итоговый шаблон

Необходимо объеденить все считанные шаблоны в одной строке, для передачи в качестве регулярного выражения. Переместим вывод получившегося шаблона и вызовем функцию после парсера и вывода debug информации.

```c
void grep_it(options *s_opt) {
  cook_pattern(s_opt);
  puts("Final pattern:");
  puts(s_opt->pattern);
}
```

Пройдемся по всем ранее записанным шаблонам и добавим их к строке финального шаблона. Затем тоже самое сделаем с каждым файлом шаблонов. Если попадется пустой шаблон, заменяем его на `.`, что в регулярных выражениях соответствует любому символу. 

```c
void cook_pattern(options *s_opt) {
  for (int i = 0; s_opt->patterns[i]; i++)
    strcat(strcat(s_opt->pattern, !strlen(s_opt->pattern) ? "" : "|"),
           !strlen(s_opt->patterns[i]) ? "." : s_opt->patterns[i]);
  for (int i = 0; s_opt->pattern_files[i]; i++) cook_pattern_files(s_opt, i);
}
```

Шаблоны из файла считываются построчно, где каждая строка новый шаблон. Очищаем строки от символа переноса строки и добавляем к итоговому шаблону.

```c
void cook_pattern_files(options *s_opt, int num) {
  char buf[BUF_SIZE];
  FILE *fp = fopen(s_opt->pattern_files[num], "r");
  if (fp) {
    while (fgets(buf, BUF_SIZE, fp)) {
      char *c = buf + strlen(buf) - 1;
      if (*c == '\n') *c = '\0';
      strcat(strcat(s_opt->pattern, !strlen(s_opt->pattern) ? "" : "|"),
             !strlen(buf) ? "." : buf);
    }
  } else
    fprintf(stderr, "s21_grep: %s: No such file or directory\n",
            s_opt->pattern_files[num]);
}
```
В результате работы такой программы получим:

`./s21_grep -e temp2 -f patfile file1 file2 file3`

```
patterns: 1
patterns files: 1
files count: 3
patterns:
        temp2
patterns files:
        patfile
files:
        file1
        file2
        file3
Final pattern:
temp2|temp1|.|temp3
```

Используется тестовый файл patfile с содержанием:

```
temp1\n
\n
temp3
```

#### 7. Обработка флагов без -o

Избавляемся от всех функций вывода дополнительной информации, и начинаем обработку флагов. Для каждого файла из полученных в качестве аргументов построчно обрабатываем их содержимое. Сначала основные опции, затем все что косается подсчета или доп информации. В случае отсутствия файла, и опции подавляющей вывод ошибок связанных с файлом, выводим соответствующую ошибку.

```c
void grep_it(options *s_opt) {
  cook_pattern(s_opt);
  for (int i = 0; i < s_opt->files_count; i++) {
    FILE *fp = fopen(s_opt->files[i], "r");
    if (fp) {
      char buf[BUF_SIZE];
      int num = 1;
      while (fgets(buf, BUF_SIZE, fp)) {
        int len = strlen(buf); //обрабатываем последнюю строку
        if (buf[len - 1] != '\n') {
          buf[len + 1] = 0;
          buf[len] = '\n';
        }
        cook_main_data(s_opt, buf, s_opt->files[i], num);
        num++;
      }
      cook_aux_data(s_opt, s_opt->files[i]);
      fclose(fp);
    } else if (!s_opt->s_flag)
      fprintf(stderr, "s21_grep: %s: No such file or directory", s_opt->files[i]);
  }
}
```

Для работы с регулярными выражениями можно использовать библиотеку `regex.h`.

```c
#include <regex.h>
```

Функция `regcomp` вернет 0 в случае успешной копиляции шаблона в заданной строке. Последний параметр определяет игнориурется ли регистр. Функция `regexec` сравнит скомпилированный шаблон с заданной строкой и вернет 0 в случае успешно найденного совпадения или ненулевой код ошибки в случае провала. Тут же применяем флаг инвертированного вывода. Далее исходя из приоритета, если не нужно выводить количественную информацию, выводим соответстующую обработанным флагам дополнительную информацию и строку с совпадением. В случае флага `-o` обрабатываем строку иным способом.

```c
void cook_main_data(options *s_opt, char *line, char *file_name, int num) {
  regex_t regex;
  if (!regcomp(&regex, s_opt->pattern,
               s_opt->i_flag ? REG_ICASE : REG_EXTENDED)) {
    if (regexec(&regex, line, 0, NULL, 0) == s_opt->v_flag) {
      s_opt->matches_count++;
      if ((s_opt->c_flag || s_opt->l_flag) == 0) {
        if (s_opt->files_count > 1 && !s_opt->h_flag) printf("%s:", file_name);
        if (s_opt->n_flag) printf("%d:", num);
        if (!s_opt->o_flag)
          fputs(line, stdout);
        else
          cook_with_o(regex, line, s_opt);
      }
    }
    regfree(&regex);
  }
}
```

При выводе колличественной информации, проверяем только пару флагов и выводим соответствующие значения.

```c
void cook_aux_data(options *s_opt, char *file_name) {
  if (s_opt->c_flag) {
    if (s_opt->l_flag) {
      s_opt->files_count > 1 ? printf("%s:1\n", file_name) : printf("1\n");
    } else {
      if (s_opt->files_count > 1) printf("%s:", file_name);
      printf("%d\n", s_opt->matches_count);
    }
  }
  if (s_opt->l_flag && s_opt->matches_count) printf("%s\n", file_name);
}
```

#### 8. Обработка -o флага

Самый особенный и самый сложный для понимания флаг, заставляющий утилиту выводить только найденные совпадения, и тут же лежащий подводный камень с инвертацией флага.

```c
void cook_with_o(regex_t regex, char *line, grep_opt *s_options) {
  while (!regexec(&regex, line, 0, NULL, 0)) { //Пока есть совпадения в строке
    char buf[BLOCK_SIZE] = "";
    strcpy(buf, line);
    int left = 0; //индекс крайнего левого символа в совпадающем участке
    int right = strlen(buf); //индекс крайнего правого символа в совпадающем участке
    while (!regexec(&regex, buf + left, 0, NULL, 0)) left++; //пока есть совпадение смещаем левый индекс
    left--; //перескочив, важно вернутся
    while (!regexec(&regex, buf + left, 0, NULL, 0)) { //затем правый, попутно обнуляя неподходящие символы
      right--;
      buf[right] = 0;
    }
    buf[right] = line[right];
    right++; //тот же принцип что и с левым
    if (!s_options->v_flag) printf("%s\n", buf + left); //выводим найденное совпадение
    int len = right - left + 1;
    for (int i = 0; i < len; i++) { //удаляем из строки найденное совпадение
      line[left++] = line[right++];
    }
  }
  if (s_options->v_flag) printf("%s", line); //если была опцияя с инвертацие выводим оставшуюся без совпадений строку
}
```

#### 9. Makefile и тесты

Практически идентичный makefile как в cat.

```Makefile
FLAGS=-Wall -Werror -Wextra
all: s21_grep

s21_grep: grep.o
	gcc $(FLAGS) grep.c -o s21_grep

test: grep_test.sh
	bash grep_test.sh

grep.o: grep.c
	gcc $(FLAGS) -c grep.c

clean:
	rm -rf *.o
	rm -rf s21_grep
	rm -rf test
```

Теперь протестируем самописную утилиту. Создадим `bash` скрипт, в нем создадим директорию и перенесем необходимые файлы. Заодно обозначим необходимые переменные.

```bash
mkdir -p test
cp ./s21_grep test/
cp test.txt test/
cp test2.txt test/
cp pat.txt test/
cd test/

test_number=0
```

В отличие от cat, тестировать grep немного сложнее, можно обойтись заданным набором тестовых комбинаций.

```bash
declare -a test_list=("-e seven -e 504 test.txt"
    "-f pat.txt -e seven test.txt"
    ...
    "-c seven test.txt"
    "-n seven test.txt"
    "-o seven test.txt"
    "seven test.txt")
```

Точно так же сравниваем поведение оригинальной утилиты с самописной

```bash
for test in "${test_list[@]}"
do
    echo "Test number: $test_number"
    ./s21_grep $test > s21_result
    grep $test > grep_result
    echo -e "$(diff -s grep_result s21_result)\n"
    if [[ $(diff -q grep_result s21_result) ]]
    then
        echo "____________________________________________________________"
        echo -e "\nThe wrong test in \n\t$test\n"
        exit
    fi
    test_number=$((test_number + 1))
done

cd ..
rm -rf ./test
```

На этом выполнение проекта завершено, спасибо за внимание!