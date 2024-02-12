# `check.h`

> This manual is for Check (version 0.15.2, 28 June 2020), a unit testing framework for C.

Это руководство предназначено для Check (версия 0.15.2, 28 июня 2020 г.) фреймворка модульного тестирования для C.

> Copyright © 2001–2014 Arien Malec, Branden Archer, Chris Pickett, Fredrik Hugosson, and Robert Lemmen.

Авторские права © 2001-2014 Ариен Малек, Бранден Арчер, Крис Пикетт, Фредрик Хьюгоссон и Роберт Леммен.

> Permission is granted to copy, distribute and/or modify this document under the terms of the GNU Free Documentation License, Version 1.2 or any later version published by the Free Software Foundation; with no Invariant Sections, no Front-Cover texts, and no Back-Cover Texts. A copy of the license is included in the section entitled “GNU Free Documentation License.”

Разрешается копировать, распространять и / или изменять этот документ в соответствии с условиями GNU Free Documentation License версии 1.2 или любой более поздней, опубликованной Фондом свободного программного обеспечения; без неизменяемых разделов, без текстов на первой и последней обложках. Копия лицензии включена в раздел, озаглавленный “GNU Лицензия на бесплатную документацию”.

> Please send corrections to this manual [to check-devel AT lists.sourceforge.net.](check-devel%20AT%20lists.sourceforge.net) We’d prefer it if you can send a unified diff (diff -u) against the ‘doc/check.texi’ file that ships with Check, but if that is not possible something is better than nothing.

Пожалуйста, отправьте исправления к этому руководству по адресу check-devel ПО адресу lists.sourceforge.net . Мы бы предпочли, чтобы вы могли отправить унифицированную разницу (diff -u) с файлом ‘doc / check.texi’, который поставляется вместе с Check, но если это невозможно, то что-нибудь лучше, чем ничего.

# Содержание
1. [Введение (Introduction)](#введение-introduction)
2. [Модульное тестирование на C (Unit Testing in C)](#модульное-тестирование-на-c-unit-testing-in-c)
    + [Другие фреймворки для C (Other Frameworks for C)](#другие-фреймворки-для-c-other-frameworks-for-c)
3. [Учебное пособие: Базовое модульное тестирование (Tutorial: Basic Unit Testing)](#учебное-пособие-базовое-модульное-тестирование-tutorial-basic-unit-testing)
    + [Как написать тест (How to Write a Test)](#как-написать-тест-how-to-write-a-test)
    + [Настройка сборки Money с помощью Autotools (Setting Up the Money Build Using Autotools)](#настройка-сборки-money-с-помощью-autotools-setting-up-the-money-build-using-autotools)
    + [Настройка сборки Money с помощью CMake (Setting Up the Money Build Using CMake)](#настройка-сборки-money-с-помощью-cmake-setting-up-the-money-build-using-cmake)
    + [Немного тестируем, немного кодируем (Test a Little, Code a Little)](#немного-тестируем-немного-кодируем-test-a-little-code-a-little)
    + [Создание пакета (Creating a Suite)](#создание-пакета-creating-a-suite)
    + [Выходные данные SRunner (SRunner Output)](#выходные-данные-srunner-srunner-output)

4. [Расширенные функции (Advanced Features)](#расширенные-функции-advanced-features)
    + [Удобные функции тестирования (Convenience Test Functions)](#удобные-функции-тестирования-convenience-test-functions)
    + [Ведение журнала тестирования (Test Logging)](#ведение-журнала-тестирования-test-logging)
5. Поддерживаемых систем сборки	  	
6. Заключение и ссылки	  	
Приложение A Ссылка на переменную среды	  	
Приложение В, копирующее данное Руководство	  	
Указатель


+ [Интеграция check.h в проект](#интеграция-checkh-в-проект)

# Введение (Introduction)

> Check is a unit testing framework for C.

Check - это фреймворк модульного тестирования для C.

> It was inspired by similar frameworks that currently exist for most programming languages; the most famous example being [JUnit](http://www.junit.org/) for Java.

Он был вдохновлен аналогичными фреймворками, которые в настоящее время существуют для большинства языков программирования; самым известным примером является [JUnit](http://www.junit.org/) для Java.

>  There is a list of unit test frameworks for multiple languages at http://www.xprogramming.com/software.htm. 

Список фреймворков модульного тестирования для нескольких языков доступен по адресу http://www.xprogramming.com/software.htm.

> Unit testing has a long history as part of formal quality assurance methodologies, but has recently been associated with the lightweight methodology called Extreme Programming.

Модульное тестирование имеет долгую историю как часть формальных методологий обеспечения качества, но в последнее время его связывают с облегченной методологией, называемой экстремальным программированием.

> In that methodology, the characteristic practice involves interspersing unit test writing with coding (“test a little, code a little”).

В этой методологии характерной практикой является чередование написания модульных тестов с кодированием (“немного тестируй, немного кодируй”).

> While the incremental unit test/code approach is indispensable to Extreme Programming, it is also applicable, and perhaps indispensable, outside of that methodology.

Хотя подход инкрементного модульного тестирования / кодирования незаменим для экстремального программирования, он также применим и, возможно, незаменим вне этой методологии.

> The incremental test/code approach provides three main benefits to the developer:

Инкрементный подход к тестированию / кодированию предоставляет разработчику три основных преимущества:

> 1. Because the unit tests use the interface to the unit being tested, they allow the developer to think about how the interface should be designed for usage early in the coding process.

1. Поскольку модульные тесты используют интерфейс к тестируемому модулю, они позволяют разработчику подумать о том, каким должен быть интерфейс для использования на ранних этапах процесса кодирования.

> 2. They help the developer think early about aberrant cases, and code accordingly.

2. Они помогают разработчику заблаговременно подумать об отклоняющихся случаях и соответствующим образом разработать код.

> 3. By providing a documented level of correctness, they allow the developer to refactor (see http://www.refactoring.com) aggressively.

3. Обеспечивая документированный уровень корректности, они позволяют разработчику проводить активный рефакторинг (см. http://www.refactoring.com).

> That third reason is the one that turns people into unit testing addicts. 

Именно эта третья причина превращает людей в приверженцев модульного тестирования.

> There is nothing so satisfying as doing a wholesale replacement of an implementation, and having the unit tests reassure you at each step of that change that all is well. 

Нет ничего более приятного, чем полная замена реализации, и наличие модульных тестов, подтверждающих вас на каждом этапе этого изменения, что все хорошо.

> It is like the difference between exploring the wilderness with and without a good map and compass: without the proper gear, you are more likely to proceed cautiously and stick to the marked trails; with it, you can take the most direct path to where you want to go.

Это похоже на разницу между исследованием дикой природы с хорошей картой и компасом и без них: без надлежащего снаряжения вы, скорее всего, будете действовать осторожно и придерживаться отмеченных троп; с ним вы сможете выбрать самый прямой путь туда, куда хотите попасть.

> Look at the Check homepage for the latest information on Check: https://libcheck.github.io/check/.

Ознакомьтесь с последней информацией о проверке на домашней странице проверки: https://libcheck.github.io/check/.

[Содержание](#содержание)

# Модульное тестирование на C (Unit Testing in C)

>The approach to unit testing frameworks used for Check originated with Smalltalk, which is a late binding object-oriented language supporting reflection. 

Подход к фреймворкам модульного тестирования, используемый для проверки, возник в Smalltalk, который является объектно-ориентированным языком с поздней привязкой, поддерживающим рефлексию. 

>Writing a framework for C requires solving some special problems that frameworks for Smalltalk, Java or Python don’t have to face. 

Написание фреймворка для C требует решения некоторых особых проблем, с которыми фреймворкам для Smalltalk, Java или Python сталкиваться не приходится.

>In all of those language, the worst that a unit test can do is fail miserably, throwing an exception of some sort. 

На всех этих языках худшее, что может сделать модульный тест, - это с треском провалиться, выдав какое-либо исключение. 

>In C, a unit test is just as likely to trash its address space as it is to fail to meet its test requirements, and if the test framework sits in the same address space, goodbye test framework.

В C модульный тест с такой же вероятностью приведет к потере адресного пространства, как и к несоответствию требованиям к тестированию, и если тестовый фреймворк находится в том же адресном пространстве, прощай, тестовый фреймворк.

> To solve this problem, Check uses the fork() system call to create a new address space in which to run each unit test, and then uses message queues to send information on the testing process back to the test framework. 

Чтобы решить эту проблему, проверка использует fork() системный вызов для создания нового адресного пространства, в котором выполняется каждый модульный тест, а затем использует очереди сообщений для отправки информации о процессе тестирования обратно в платформу тестирования.

> That way, your unit test can do all sorts of nasty things with pointers, and throw a segmentation fault, and the test framework will happily note a unit test error, and chug along.

Таким образом, ваш модульный тест может вытворять всевозможные неприятные вещи с указателями и выдавать ошибку сегментации, а платформа тестирования с радостью заметит ошибку модульного тестирования и продолжит работу.

> The Check framework is also designed to play happily with common development environments for C programming. 

Платформа Check Framework также предназначена для совместной работы с распространенными средами разработки для программирования на C.

> The author designed Check around Autoconf/Automake (thus the name Check: make check is the idiom used for testing with Autoconf/Automake). 

Автор разработал проверку с использованием Autoconf / Automake (таким образом, название Check: make check - это идиома, используемая для тестирования с помощью Autoconf / Automake).

> Note however that Autoconf/Automake are NOT necessary to use Check; any build system is sufficient. 

Однако обратите внимание, что для использования проверки необязательно использовать Autoconf / Automake; достаточно любой системы сборки.

>The test failure messages thrown up by Check use the common idiom of ‘filename:linenumber:message’ used by gcc and family to report problems in source code. 

В сообщениях о сбое тестирования, выдаваемых Check, используется распространенная идиома ‘filename:linenumber:message’, используемая gcc и семейством для сообщения о проблемах в исходном коде.

> With (X)Emacs, the output of Check allows one to quickly navigate to the location of the unit test that failed; presumably that also works in VI and IDEs.

С помощью (X) Emacs результат проверки позволяет быстро перейти к местоположению модульного теста, который не прошел; предположительно, это также работает в VI и IDEs.

[Содержание](#содержание)

## Другие фреймворки для C (Other Frameworks for C)

>The authors know of the following additional unit testing frameworks for C:

Авторам известны следующие дополнительные фреймворки модульного тестирования для C:

### AceUnit

>AceUnit (Advanced C and Embedded Unit) bills itself as a comfortable C code unit test framework. It tries to mimic JUnit 4.x and includes reflection-like capabilities. AceUnit can be used in resource constraint environments, e.g. embedded software development, and importantly it runs fine in environments where you cannot include a single standard header file and cannot invoke a single standard C function from the ANSI / ISO C libraries. It also has a Windows port. It does not use forks to trap signals, although the authors have expressed interest in adding such a feature. See the [AceUnit homepage](http://aceunit.sourceforge.net/).

AceUnit (Advanced C и Embedded Unit) позиционирует себя как удобный фреймворк модульного тестирования кода на C. Он пытается имитировать JUnit 4.x и включает возможности, подобные reflection. AceUnit может использоваться в средах с ограниченными ресурсами, например, при разработке встроенного программного обеспечения, и, что важно, он отлично работает в средах, где вы не можете включить ни одного стандартного заголовочного файла и не можете вызвать ни одной стандартной функции C из библиотек ANSI / ISO C. У него также есть порт Windows. Он не использует forks для перехвата сигналов, хотя авторы выразили заинтересованность в добавлении такой функции. Смотрите [AceUnit homepage](http://aceunit.sourceforge.net/).

### GNU Autounit
>Much along the same lines as Check, including forking to run unit tests in a separate address space (in fact, the original author of Check borrowed the idea from GNU Autounit). GNU Autounit uses GLib extensively, which means that linking and such need special options, but this may not be a big problem to you, especially if you are already using GTK or GLib. See the [GNU Autounit homepage](http://autounit.tigris.org/).

Во многом аналогично Check, включая разветвление для запуска модульных тестов в отдельном адресном пространстве (фактически, первоначальный автор Check позаимствовал идею у GNU Autounit). GNU Autounit широко использует GLib, что означает, что для связывания и тому подобного нужны специальные опции, но для вас это может не быть большой проблемой, особенно если вы уже используете GTK или GLib. Смотрите  [GNU Autounit homepage](http://autounit.tigris.org/).

### cUnit
>Also uses GLib, but does not fork to protect the address space of unit tests. See the archived [cUnit homepage](http://cunit.sourceforge.net/).

Также использует GLib, но не использует fork для защиты адресного пространства модульных тестов. Смотрите [cUnit homepage](http://cunit.sourceforge.net/).

### CUnit
>Standard C, with plans for a Win32 GUI implementation. Does not currently fork or otherwise protect the address space of unit tests. In early development. See the [CUnit homepage](http://cunit.sourceforge.net/).

Стандартный C с планами реализации графического интерфейса Win32. В настоящее время не разветвляет и иным образом не защищает адресное пространство модульных тестов. На ранней стадии разработки. Смотрите [CUnit homepage](http://cunit.sourceforge.net/).

### CuTest
>A simple framework with just one .c and one .h file that you drop into your source tree. See the [CuTest homepage](http://cutest.sourceforge.net/).

Простой фреймворк с одним файлом .c и одним файлом .h, который вы добавляете в дерево исходных текстов. Посмотрите на [CuTest homepage](http://cutest.sourceforge.net/).

### CppUnit
>The premier unit testing framework for C++; you can also use it to test C code. It is stable, actively developed, and has a GUI interface. The primary reasons not to use CppUnit for C are first that it is quite big, and second you have to write your tests in C++, which means you need a C++ compiler. If these don’t sound like concerns, it is definitely worth considering, along with other C++ unit testing frameworks. See the [CppUnit homepage](http://cppunit.sourceforge.net/cppunit-wiki).

Лучший фреймворк модульного тестирования для C++; вы также можете использовать его для тестирования кода на C. Он стабилен, активно разрабатывается и имеет графический интерфейс. Основные причины не использовать CppUnit для C заключаются, во-первых, в том, что он довольно большой, а во-вторых, вы должны писать свои тесты на C++, что означает, что вам нужен компилятор C++. Если это не вызывает беспокойства, его определенно стоит рассмотреть вместе с другими фреймворками модульного тестирования C++. Смотрите [CppUnit homepage](http://cppunit.sourceforge.net/cppunit-wiki).

### embUnit
>embUnit (Embedded Unit) is another unit test framework for embedded systems. This one appears to be superseded by AceUnit. [Embedded Unit homepage](https://sourceforge.net/projects/embunit/).

embUnit (Embedded Unit) - это еще один фреймворк модульного тестирования для встраиваемых систем. Похоже, этот фреймворк заменен AceUnit. [Embedded Unit homepage](https://sourceforge.net/projects/embunit/).

### MinUnit

>A minimal set of macros and that’s it! The point is to show how easy it is to unit test your code. See the [MinUnit homepage](http://www.jera.com/techinfo/jtns/jtn002.html).

Минимальный набор макросов и все! Смысл в том, чтобы показать, насколько легко модульно тестировать ваш код. Смотрите [MinUnit homepage](http://www.jera.com/techinfo/jtns/jtn002.html).

### CUnit for Mr. Ando
> A CUnit implementation that is fairly new, and apparently still in early development. See the [CUnit for Mr.Ando homepage](http://park.ruru.ne.jp/ando/work/CUnitForAndo/html/).

Реализация CUnit, которая является довольно новой и, по-видимому, все еще находится на ранней стадии разработки. Смотрите [CUnit for Mr.Ando homepage](http://park.ruru.ne.jp/ando/work/CUnitForAndo/html/).

>This list was last updated in March 2008. If you know of other C unit test frameworks, please send an email plus description to check-devel AT lists.sourceforge.net and we will add the entry to this list.

Последний раз этот список обновлялся в марте 2008 года. Если вы знаете о других фреймворках модульного тестирования C, пожалуйста, отправьте электронное письмо с описанием на check-devel ПО адресу lists.sourceforge.net и мы добавим запись в этот список.

>It is the authors’ considered opinion that forking or otherwise trapping and reporting signals is indispensable for unit testing (but it probably wouldn’t be hard to add that to frameworks without that feature). 

Авторы придерживаются взвешенного мнения’ что для модульного тестирования необходимо разветвлять или иным образом перехватывать сигналы и сообщать о них (но, вероятно, было бы нетрудно добавить это в фреймворки без этой функции). 

>Try ’em all out: adapt this tutorial to use all of the frameworks above, and use whichever you like. Contribute, spread the word, and make one a standard.

Попробуйте все: адаптируйте это руководство для использования всех фреймворков, описанных выше, и используйте тот, который вам нравится. Вносите свой вклад, распространяйте информацию и сделайте его стандартом.

>Languages such as Java and Python are fortunate to have standard unit testing frameworks; it would be desirable that C have one as well.

Таким языкам, как Java и Python, повезло, что у них есть стандартные фреймворки модульного тестирования; было бы желательно, чтобы и на C они были.

[Содержание](#содержание)

# Учебное пособие: Базовое модульное тестирование (Tutorial: Basic Unit Testing)

> This tutorial will use the JUnit _Test Infected_ article as a starting point.<br>

В этом учебном пособии в качестве отправной точки будет использована статья JUnit о _Test Infected_. <br>

> We will be creating a library to represent money, libmoney, that allows conversions between different currency types. 

Мы создадим библиотеку для представления денег, libmoney которая позволяет осуществлять конвертацию между различными типами валют.<br>

>The development style will be “test a little, code a little”, with unit test writing preceding coding.

Стиль разработки будет “немного тестируй, немного кодируй”, при этом написанию модульного теста предшествует кодирование. 

>This constantly gives us insights into module usage, and also makes sure we are constantly thinking about how to test our code.

Это постоянно дает нам представление об использовании модуля, а также гарантирует, что мы постоянно думаем о том, как тестировать наш код.

[Содержание](#содержание)

## Как написать тест (How to Write a Test)

>Test writing using Check is very simple. The file in which the checks are defined must include ‘check.h’ as so:

Написание теста с использованием проверки очень просто. Файл, в котором определены проверки, должен содержать ‘check.h’ таким образом:

```c
#include <check.h>
```

>The basic unit test looks as follows:

Базовый модульный тест выглядит следующим образом:

```c
START_TEST (имя_теста)
{
 /* код модульного тестирования */
}
END_TEST
```

> The START_TEST/END_TEST pair are macros that setup basic structures to permit testing. It is a mistake to leave off the END_TEST marker; doing so produces all sorts of strange errors when the check is compiled.

Пара START_TEST/END_TEST - это макросы, которые настраивают базовые структуры для обеспечения тестирования. Было бы ошибкой не указывать END_TEST маркер; это приводит к всевозможным странным ошибкам при компиляции проверки.

[Содержание](#содержание)

## Настройка сборки Money с помощью Autotools (Setting Up the Money Build Using Autotools)

>Since we are creating a library to handle money, we will first create an interface in `money.h`, an implementation in `money.c`, and a place to store our unit tests, `check_money.c`.

Поскольку мы создаем библиотеку для работы с деньгами, мы сначала создадим интерфейс в `money.h`, реализацию в `money.c` и место для хранения наших модульных тестов, `check_money.c`. 

>We want to integrate these core files into our build system, and will need some additional structure.

Мы хотим интегрировать эти основные файлы в нашу систему сборки, и нам понадобится некоторая дополнительная структура.

>To manage everything we’ll use Autoconf, Automake, and friends (collectively known as Autotools) for this example.

Для управления всем этим мы будем использовать Autoconf, Automake и friends (совместно известные как Autotools) для этого примера.

>Note that one could do something similar with ordinary Makefiles, or any other build system.

Обратите внимание, что нечто подобное можно было бы сделать с обычными Make-файлами или любой другой системой сборки.

>It is in the authors’ opinion that it is generally easier to use Autotools than bare Makefiles, and they provide built-in support for running tests.

По мнению авторов, в целом проще использовать Autotools, чем простые Make-файлы, и они предоставляют встроенную поддержку для запуска тестов.

> Note that this is not the place to explain how Autotools works. If you need help understanding what’s going on beyond the explanations here, the best place to start is probably Alexandre Duret-Lutz’s excellent [Autotools tutorial](http://www.lrde.epita.fr/~adl/autotools.html).

Обратите внимание, что здесь не место объяснять, как работает Autotools. Если вам нужна помощь в понимании того, что происходит помимо приведенных здесь объяснений, вероятно, лучше всего начать с превосходного руководства по Autotools от Александра Дюре-Лутца [Autotools tutorial](http://www.lrde.epita.fr/~adl/autotools.html).

> The examples in this section are part of the Check distribution; you don’t need to spend time cutting and pasting or (worse) retyping them. Locate the Check documentation on your system and look in the ‘example’ directory. The standard directory for GNU/Linux distributions should be ‘/usr/share/doc/check/example’. This directory contains the final version reached the end of the tutorial. If you want to follow along, create backups of ‘money.h’, ‘money.c’, and ‘check_money.c’, and then delete the originals.

Примеры в этом разделе являются частью дистрибутива Check; вам не нужно тратить время на вырезание и вставку или (что еще хуже) перепечатывание их. Найдите документацию по проверке в вашей системе и загляните в каталог ‘example’. Стандартным каталогом для дистрибутивов GNU / Linux должен быть ‘/usr/share/doc/check/example’. Этот каталог содержит окончательную версию, дошедшую до конца учебного пособия. Если вы хотите продолжить, создайте резервные копии ‘money.h’, ‘money.c’ и ‘check_money.c’, а затем удалите оригиналы.

> We set up a directory structure as follows:

Мы настроили структуру каталогов следующим образом:

```
.
|-- Makefile.am
|-- README
|-- configure.ac
|-- src
|   |-- Makefile.am
|   |-- main.c
|   |-- money.c
|   `-- money.h
`-- tests
    |-- Makefile.am
    `-- check_money.c
```

>Note that this is the output of tree, a great directory visualization tool. The top-level ‘Makefile.am’ is simple; it merely tells Automake how to process sub-directories:

Обратите внимание, что это результат tree, отличного инструмента визуализации каталогов. ‘Makefile.am’ верхнего уровня прост; он просто сообщает Automake, как обрабатывать подкаталоги:

```
SUBDIRS = src . tests
```

> Note that tests comes last, because the code should be testing an already compiled library. ‘configure.ac’ is standard Autoconf boilerplate, as specified by the Autotools tutorial and as suggested by autoscan.

Обратите внимание, что tests это последнее, потому что код должен тестировать уже скомпилированную библиотеку. ‘configure.ac’ является стандартным шаблоном Autoconf, как указано в руководстве по Autotools и предложено autoscan.

> ‘src/Makefile.am’ builds ‘libmoney’ as a Libtool archive, and links it to an application simply called main. The application’s behavior is not important to this tutorial; what’s important is that none of the functions we want to unit test appear in ‘main.c’; this probably means that the only function in ‘main.c’ should be main() itself. In order to test the whole application, unit testing is not appropriate: you should use a system testing tool like Autotest. If you really want to test main() using Check, rename it to something like _myproject_main() and write a wrapper around it.

‘src /Makefile.am’ создает ‘libmoney’ как архив Libtool и связывает его с приложением, которое называется просто main. Поведение приложения не важно для этого руководства; важно то, что ни одна из функций, которые мы хотим модульно протестировать, не отображается в ‘main.c’; вероятно, это означает, что единственной функцией в ‘main.c’ должна быть main() она сама. Для тестирования всего приложения модульное тестирование не подходит: вы должны использовать инструмент системного тестирования, такой как Автотест. Если вы действительно хотите протестировать main() с помощью проверки, переименуйте ее во что-то вроде _myproject_main() и напишите оболочку вокруг нее.

>The primary build instructions for our unit tests are in ‘tests/Makefile.am’:

Основные инструкции по сборке для наших модульных тестов находятся в "tests /Makefile.am’:

```bash
## Process this file with automake to produce Makefile.in
## Обработайте этот файл с помощью automake для получения Makefile.in

TESTS = check_money
check_PROGRAMS = check_money
check_money_SOURCES = check_money.c $(top_builddir)/src/money.h
check_money_CFLAGS = @CHECK_CFLAGS@
check_money_LDADD = $(top_builddir)/src/libmoney.la @CHECK_LIBS@
```

> TESTS tells Automake which test programs to run for make check. Similarly, the check_ prefix in check_PROGRAMS actually comes from Automake; it says to build these programs only when make check is run. (Recall that Automake’s check target is the origin of Check’s name.) The check_money test is a program that we will build from ‘tests/check_money.c’, linking it against both ‘src/libmoney.la’ and the installed ‘libcheck.la’ on our system. The appropriate compiler and linker flags for using Check are found in @CHECK_CFLAGS@ and @CHECK_LIBS@, values defined by the AM_PATH_CHECK macro.

TESTS сообщает Automake, для каких тестовых программ запускать make check. Аналогично, check_ префикс в check_PROGRAMS на самом деле происходит от Automake; в нем говорится о сборке этих программ только при запуске make check. (Напомним, что check Цель Automake - происхождение названия Check.) check_money Тест - это программа, из которой мы будем создавать ‘tests/check_money.c’, связывающий его с обоими ‘src / libmoney.ла’ и установлен ‘libcheck.ла’ на нашем системы. Соответствующие флаги компилятора и компоновщика для использования проверки находятся в @CHECK_CFLAGS@ и @CHECK_LIBS@, значения определяются AM_PATH_CHECK макрокомандой.

> Now that all this infrastructure is out of the way, we can get on with development. ‘src/money.h’ should only contain standard C header boilerplate:

Теперь, когда вся эта инфраструктура устранена, мы можем приступить к разработке. ‘src / money.h' должен содержать только стандартный шаблон заголовка C:

```c
/*
 * Check: a unit test framework for C
 * Copyright (C) 2001, 2002 Arien Malec
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 51 Franklin St, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 */

#ifndef MONEY_H
#define MONEY_H

#endif /* MONEY_H */
```

```c
/*
 * Проверка: фреймворк модульного тестирования для C
 * Авторские права (C) 2001, 2002 Arien Malec
 *
 * Эта библиотека является свободным программным обеспечением; вы можете распространять ее и / или
 * измените его в соответствии с условиями GNU Lesser General Public
 * Лицензия, опубликованная Фондом свободного программного обеспечения; либо
 * версия 2.1 Лицензии, либо (по вашему выбору) любая более поздняя версия.
 *
 * Эта библиотека распространяется в надежде, что она будет полезна,
 * но БЕЗ КАКИХ-ЛИБО ГАРАНТИЙ; даже без подразумеваемых гарантий на 
 * ТОВАРНУЮ ПРИГОДНОСТЬ или ПРИГОДНОСТЬ ДЛЯ ОПРЕДЕЛЕННОЙ ЦЕЛИ. Смотрите GNU
 * Более подробную информацию можно получить по лицензии Lesser General Public.
 *
 * Вы должны были получить копию лицензии GNU Lesser General Public
 * вместе с этой библиотекой; если нет, напишите на
 * Фонд свободного программного обеспечения, Inc., ул. Франклина, 51, пятый этаж, Бостон,
 * Массачусетс 02110-1301, США.
 */

#ifndef MONEY_H
#define MONEY_H

#endif /* MONEY_H */
```

>‘src/money.c’ should be empty, and ‘tests/check_money.c’ should only contain an empty main() function:

‘src /money.c’ должен быть пустым, а ‘тесты / check_money.c’ должен содержать только пустую main() функцию:

```c
int main(void)
{
    return 0;
}
```

>Create the GNU Build System for the project and then build ‘main’ and ‘libmoney.la’ as follows:

Создайте систему сборки GNU для проекта, а затем создайте "main’ и "libmoney.la’ следующим образом:

```bash
$ autoreconf --install
$ ./configure
$ make
```

>(autoreconf determines which commands are needed in order for configure to be created or brought up to date. Previously one would use a script called autogen.sh or bootstrap, but that practice is unnecessary now.)

(autoreconf определяет, какие команды необходимы для configure создания или обновления. Раньше можно было использовать скрипт с именем autogen.sh или bootstrap, но сейчас в этой практике нет необходимости.)

>Now build and run the check_money test with make check. If all goes well, make should report that our tests passed. No surprise, because there aren’t any tests to fail. If you have problems, make sure to see [Supported Build Systems](https://libcheck.github.io/check/doc/check_html/check_5.html#Supported-Build-Systems).

Теперь соберите и запустите check_money тест с помощью make check. Если все пойдет хорошо, make должны сообщить, что наши тесты пройдены. Неудивительно, потому что нет тестов, которые могли бы завершиться неудачей. Если у вас возникли проблемы, обязательно ознакомьтесь с  [Supported Build Systems](https://libcheck.github.io/check/doc/check_html/check_5.html#Supported-Build-Systems).

>This was tested on the isadora distribution of Linux Mint GNU/Linux in November 2012, using Autoconf 2.65, Automake 1.11.1, and Libtool 2.2.6b. Please report any problems to check-devel@lists.sourceforge.net.

Это было протестировано в дистрибутиве isadora Linux Mint GNU / Linux в ноябре 2012 года с использованием Autoconf 2.65, Automake 1.11.1 и Libtool 2.2.6b. Пожалуйста, сообщайте о любых проблемах в check-devel@lists.sourceforge.net .

[Содержание](#содержание)

## Настройка сборки Money с помощью CMake (Setting Up the Money Build Using CMake)

>Since we are creating a library to handle money, we will first create an interface in ‘money.h’, an implementation in ‘money.c’, and a place to store our unit tests, ‘check_money.c’. We want to integrate these core files into our build system, and will need some additional structure. To manage everything we’ll use CMake for this example. Note that one could do something similar with ordinary Makefiles, or any other build system. It is in the authors’ opinion that it is generally easier to use CMake than bare Makefiles, and they provide built-in support for running tests.

Поскольку мы создаем библиотеку для работы с деньгами, мы сначала создадим интерфейс в ‘money.h’, реализацию в ‘money.c’ и место для хранения наших модульных тестов, ‘check_money.c’. Мы хотим интегрировать эти основные файлы в нашу систему сборки, и нам понадобится некоторая дополнительная структура. Чтобы управлять всем, мы будем использовать CMake для этого примера. Обратите внимание, что нечто подобное можно было бы сделать с обычными Make-файлами или любой другой системой сборки. По мнению авторов, в целом использовать CMake проще, чем голые Make-файлы, и они предоставляют встроенную поддержку для запуска тестов.

>Note that this is not the place to explain how CMake works. If you need help understanding what’s going on beyond the explanations here, the best place to start is probably the [CMake project’s homepage](http://www.cmake.org/).

Обратите внимание, что здесь не место объяснять, как работает CMake. Если вам нужна помощь в понимании того, что происходит помимо приведенных здесь объяснений, лучшее место для начала, вероятно, это [CMake project’s homepage](http://www.cmake.org/).

> The examples in this section are part of the Check distribution; you don’t need to spend time cutting and pasting or (worse) retyping them. Locate the Check documentation on your system and look in the ‘example’ directory, or look in the Check source. If on a GNU/Linux system the standard directory should be ‘/usr/share/doc/check/example’. This directory contains the final version reached the end of the tutorial. If you want to follow along, create backups of ‘money.h’, ‘money.c’, and ‘check_money.c’, and then delete the originals.

Примеры в этом разделе являются частью дистрибутива Check; вам не нужно тратить время на вырезание и вставку или (что еще хуже) перепечатывание их. Найдите документацию по проверке в вашей системе и загляните в каталог ‘example’ или загляните в исходный код проверки. Если в системе GNU / Linux стандартным каталогом должно быть ‘/usr/share/doc/check/example’. Этот каталог содержит окончательную версию, дошедшую до конца учебного пособия. Если вы хотите продолжить, создайте резервные копии ‘money.h’, ‘money.c’ и ‘check_money.c’, а затем удалите оригиналы.

> We set up a directory structure as follows:

Мы настроили структуру каталогов следующим образом:

```
.
|-- Makefile.am
|-- README
|-- CMakeLists.txt
|-- cmake
|   |-- config.h.in
|   |-- FindCheck.cmake
|-- src
|   |-- CMakeLists.txt
|   |-- main.c
|   |-- money.c
|   `-- money.h
`-- tests
    |-- CMakeLists.txt
    `-- check_money.c
```

>The top-level ‘CMakeLists.txt’ contains the configuration checks for available libraries and types, and also defines sub-directories to process. The ‘cmake/FindCheck.cmake’ file contains instructions for locating Check on the system and setting up the build to use it. If the system does not have pkg-config installed, ‘cmake/FindCheck.cmake’ may not be able to locate Check successfully. In this case, the install directory of Check must be located manually, and the following line added to ‘tests/CMakeLists.txt’ (assuming Check was installed under C:\\Program Files\\check):

‘CMakeLists.txt’ верхнего уровня содержит проверки конфигурации для доступных библиотек и типов, а также определяет подкаталоги для обработки. Файл ‘cmake / FindCheck.cmake’ содержит инструкции по поиску проверки в системе и настройке сборки для ее использования. Если в системе не установлена pkg-config, ‘cmake / FindCheck.cmake’, возможно, не удастся успешно найти Check. В этом случае каталог установки проверки должен быть найден вручную, а следующая строка добавлена в ‘tests/CMakeLists.txt’ (при условии, что проверка была установлена в разделе C:\\Program Files \\ check):

```
set(CHECK_INSTALL_DIR "C:/Program Files/check")
```

>Note that tests comes last, because the code should be testing an already compiled library.

Обратите внимание, что tests это последнее, потому что код должен тестировать уже скомпилированную библиотеку.

>‘src/CMakeLists.txt’ builds ‘libmoney’ as an archive, and links it to an application simply called main. The application’s behavior is not important to this tutorial; what’s important is that none of the functions we want to unit test appear in ‘main.c’; this probably means that the only function in ‘main.c’ should be main() itself. In order to test the whole application, unit testing is not appropriate: you should use a system testing tool like Autotest. If you really want to test main() using Check, rename it to something like _myproject_main() and write a wrapper around it.

‘src/CMakeLists.txt’ создает ‘libmoney’ в виде архива и связывает его с приложением, которое называется просто main. Поведение приложения не важно для этого руководства; важно то, что ни одна из функций, которые мы хотим модульно протестировать, не отображается в ‘main.c’; вероятно, это означает, что единственной функцией в ‘main.c’ должна быть main() она сама. Для тестирования всего приложения модульное тестирование не подходит: вы должны использовать инструмент системного тестирования, такой как Автотест. Если вы действительно хотите протестировать main() с помощью проверки, переименуйте ее во что-то вроде _myproject_main() и напишите оболочку вокруг нее.

>Now that all this infrastructure is out of the way, we can get on with development. ‘src/money.h’ should only contain standard C header boilerplate:

Теперь, когда вся эта инфраструктура устранена, мы можем приступить к разработке. ‘src / money.h' должен содержать только стандартный шаблон заголовка C:

```c
/*
 * Check: a unit test framework for C
 * Copyright (C) 2001, 2002 Arien Malec
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 51 Franklin St, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 */

#ifndef MONEY_H
#define MONEY_H

#endif /* MONEY_H */
```

>‘src/money.c’ should be empty, and ‘tests/check_money.c’ should only contain an empty main() function:

‘src /money.c’ должен быть пустым, а ‘тесты / check_money.c’ должен содержать только пустую main() функцию:

```c
/*
 * Check: a unit test framework for C
 * Copyright (C) 2001, 2002 Arien Malec
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 51 Franklin St, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 */

int main(void)
{
    return 0;
}
```

>Create the CMake Build System for the project and then build ‘main’ and ‘libmoney.la’ as follows for Unix-compatible systems:

Создайте систему сборки CMake для проекта, а затем создайте "main’ и "libmoney.la’ следующим образом для Unix-совместимых систем:

```bash
$ cmake .
$ make
```

and for MSVC on Windows:

```bash
$ cmake -G "NMake Makefiles" .
$ nmake
```

>Now build and run the check_money test, with either make test on a Unix-compatible system or nmake test if on Windows using MSVC. If all goes well, the command should report that our tests passed. No surprise, because there aren’t any tests to fail.

Теперь соберите и запустите check_money тест, используя либо make test Unix-совместимую систему, либо nmake test if в Windows с использованием MSVC. Если все идет хорошо, команда должна сообщить, что наши тесты пройдены. Неудивительно, потому что нет никаких тестов, которые могли бы завершиться неудачей.

>This was tested on Windows 7 using CMake 2.8.12.1 and MSVC 16.00.30319.01/ Visual Studios 10 in February 2014. Please report any problems to check-devel@lists.sourceforge.net.

Это было протестировано в Windows 7 с использованием CMake 2.8.12.1 и MSVC 16.00.30319.01 / Visual Studios 10 в феврале 2014 года. Пожалуйста, сообщайте о любых проблемах в check-devel@lists.sourceforge.net.

[Содержание](#содержание)

## Немного тестируем, немного кодируем (Test a Little, Code a Little)

>The Test Infected article starts out with a Money class, and so will we. Of course, we can’t do classes with C, but we don’t really need to. The Test Infected approach to writing code says that we should write the unit test before we write the code, and in this case, we will be even more dogmatic and doctrinaire than the authors of Test Infected (who clearly don’t really get this stuff, only being some of the originators of the Patterns approach to software development and OO design).

Статья о Test Infected начинается с Money класса, и мы тоже начнем. Конечно, мы не можем создавать классы на C, но нам это и не нужно. Подход к написанию кода, основанный на тестировании, гласит, что мы должны написать модульный тест до написания кода, и в этом случае мы будем еще более догматичными и доктринерскими, чем авторы Test Infected (которые явно на самом деле не разбираются в этом, являясь лишь некоторыми из создателей шаблонного подхода к разработке программного обеспечения и OO-дизайну).

>Here are the changes to ‘check_money.c’ for our first unit test:

Вот изменения в ‘check_money.c’ для нашего первого модульного теста:

```c
#include <check.h>
#include "../src/money.h"

START_TEST(test_money_create) {
    Money *m;

    m = money_create(5, "USD");
    ck_assert_int_eq(money_amount(m), 5);
    ck_assert_str_eq(money_currency(m), "USD");
    money_free(m);
}
END_TEST

 int main(void) {
     return 0;
 }
```

>A unit test should just chug along and complete. If it exits early, or is signaled, it will fail with a generic error message. (Note: it is conceivable that you expect an early exit, or a signal and there is functionality in Check to specifically assert that we should expect a signal or an early exit.) If we want to get some information about what failed, we need to use some calls that will point out a failure. Two such calls are ck_assert_int_eq (used to determine if two integers are equal) and ck_assert_str_eq (used to determine if two null terminated strings are equal). Both of these functions (actually macros) will signal an error if their arguments are not equal.

Модульный тест должен просто проходить медленно и завершаться. Если он завершится раньше, или будет подан сигнал, он завершится ошибкой с общим сообщением об ошибке. (Примечание: возможно, вы ожидаете раннего завершения или сигнала, и есть проверяемая функциональность, специально подтверждающая, что мы должны ожидать сигнал или ранний выход.) Если мы хотим получить некоторую информацию о том, что не удалось, нам нужно использовать некоторые вызовы, которые укажут на сбой. Двумя такими вызовами являются ck_assert_int_eq (используется для определения, равны ли два целых числа ) и ck_assert_str_eq (используется для определения, равны ли две строки, заканчивающиеся null ). Обе эти функции (фактически макросы) будут выдавать сообщение об ошибке если их аргументы не равны.

> An alternative to using ck_assert_int_eq and ck_assert_str_eq is to write the expression under test directly using ck_assert. This takes one Boolean argument which must be True for the check to pass. The second test could be rewritten as follows:

Альтернативой использованию ck_assert_int_eq и ck_assert_str_eq является запись тестируемого выражения напрямую с помощью ck_assert. Для этого требуется один логический аргумент, который должен быть True для прохождения проверки. Второй тест можно переписать следующим образом:

```c
ck_assert(strcmp (money_currency (m), "USD") == 0);
```

>ck_assert will find and report failures, but will not print any user supplied message in the unit test result. To print a user defined message along with any failures found, use ck_assert_msg. The first argument is a Boolean argument. The remaining arguments support varargs and accept printf-style format strings and arguments. This is especially useful while debugging. For example, the second test could be rewritten as:

ck_assert найдет ошибки и сообщит о них, но не напечатает ни одно сообщение, предоставленное пользователем, в результате модульного тестирования. Чтобы распечатать пользовательское сообщение вместе с любыми найденными ошибками, используйте ck_assert_msg. Первый аргумент является логическим аргументом. Остальные аргументы поддерживают varargs и принимают printf строки формата и аргументы в стиле. Это особенно полезно при отладке. Например, второй тест можно переписать как:

```c
ck_assert_msg(strcmp (money_currency (m), "USD") == 0,
         "Was expecting a currency of USD, but found %s", money_currency (m));
```

> If the Boolean argument is too complicated to elegantly express within ck_assert(), there are the alternate functions ck_abort() and ck_abort_msg() that unconditionally fail. The second test inside test_money_create above could be rewritten as follows:

Если логический аргумент слишком сложен для элегантного выражения внутри ck_assert(), существуют альтернативные функции ck_abort() и ck_abort_msg(), которые безоговорочно завершаются сбоем. Второй тест внутри test_money_create выше может быть переписан следующим образом:

```c
if (strcmp (money_currency (m), "USD") != 0) {
    ck_abort_msg ("Валюта неправильно установлена при создании"); 
}
```
> For your convenience ck_assert, which does not accept a user supplied message, substitutes a suitable message for you. (This is also equivalent to passing a NULL message to ck_assert_msg). So you could also write a test as follows:

Для вашего удобства ck_assert, который не принимает сообщение, предоставленное пользователем, заменяет его подходящим для вас сообщением. (Это также эквивалентно передаче нулевого сообщения в ck_assert_msg). Таким образом, вы также могли бы написать тест следующим образом:

```c
ck_assert (money_amount (m) == 5);
```

>This is equivalent to:

Это эквивалентно:

```c
ck_assert_msg (money_amount (m) == 5, NULL);
```

>which will print the file, line number, and the message "Assertion 'money_amount (m) == 5' failed" if money_amount (m) != 5.

который напечатает файл, номер строки и сообщение "Assertion 'money_amount (m) == 5' failed" если money_amount (m) != 5.

>When we try to compile and run the test suite now using make check, we get a whole host of compilation errors. It may seem a bit strange to deliberately write code that won’t compile, but notice what we are doing: in creating the unit test, we are also defining requirements for the money interface. Compilation errors are, in a way, unit test failures of their own, telling us that the implementation does not match the specification. If all we do is edit the sources so that the unit test compiles, we are actually making progress, guided by the unit tests, so that’s what we will now do.

Когда мы пытаемся скомпилировать и запустить набор тестов сейчас, используя make check, мы получаем целый ряд ошибок компиляции. Может показаться немного странным намеренно писать код, который не будет компилироваться, но обратите внимание, что мы делаем: создавая модульный тест, мы также определяем требования к интерфейсу money. Ошибки компиляции - это, в некотором смысле, собственные сбои модульного тестирования, говорящие нам о том, что реализация не соответствует спецификации. Если все, что мы делаем, это редактируем исходные тексты, чтобы модульный тест компилировался, мы действительно добиваемся прогресса, руководствуясь модульными тестами, так что именно этим мы сейчас и займемся.

>We will patch our header ‘money.h’ as follows:

Мы исправим наш заголовок "money.h’ следующим образом:

```c
 #ifndef MONEY_H
 #define MONEY_H
 
typedef struct Money Money;

Money *money_create(int amount, char *currency);
int money_amount(Money * m);
char *money_currency(Money * m);
void money_free(Money * m);

 #endif /* MONEY_H */
```

>Our code compiles now, and again passes all of the tests. However, once we try to use the functions in libmoney in the main() of check_money, we’ll run into more problems, as they haven’t actually been implemented yet.

Сейчас наш код компилируется и снова проходит все тесты. Однако, как только мы попытаемся использовать функции из libmoney в main() из check_money, мы столкнемся с новыми проблемами, поскольку на самом деле они еще не реализованы.

[Содержание](#содержание)

## Создание пакета (Creating a Suite)

>To run unit tests with Check, we must create some test cases, aggregate them into a suite, and run them with a suite runner. That’s a bit of overhead, but it is mostly one-off. Here’s a diff for the new version of ‘check_money.c’. Note that we include stdlib.h to get the definitions of EXIT_SUCCESS and EXIT_FAILURE.

Чтобы запустить модульные тесты с помощью проверки, мы должны создать несколько тестовых примеров, объединить их в пакет и запустить с помощью программы запуска пакета. Это небольшие накладные расходы, но в основном они разовые. Вот разница для новой версии ‘check_money.c’. Обратите внимание, что мы включаем stdlib.h, чтобы получить определения EXIT_SUCCESS и EXIT_FAILURE.

```c
#include <stdlib.h>
#include <check.h>
#include "../src/money.h"

START_TEST(test_money_create) {
    Money *m;

    m = money_create(5, "USD");
    ck_assert_int_eq(money_amount(m), 5);
    ck_assert_str_eq(money_currency(m), "USD");
    money_free(m);
}
END_TEST
 
Suite * money_suite(void) {
    Suite *s;
    TCase *tc_core;

    s = suite_create("Money");

    /* Core test case */
    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, test_money_create);
    suite_add_tcase(s, tc_core);

    return s;
}

int main(void) {
    int number_failed;
    Suite *s;
    SRunner *sr;

    s = money_suite();
    sr = srunner_create(s);

    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);
    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
```

>Most of the money_suite() code should be self-explanatory. We are creating a suite, creating a test case, adding the test case to the suite, and adding the unit test we created above to the test case. Why separate this off into a separate function, rather than inline it in main()? Because any new tests will get added in money_suite(), but nothing will need to change in main() for the rest of this example, so main will stay relatively clean and simple.

Большая часть money_suite() кода должна быть понятной. Мы создаем набор, создаем тестовый пример, добавляем тестовый пример в набор и добавляем модульный тест, который мы создали выше, в тестовый пример. Зачем выделять это в отдельную функцию, а не встроить в main()? Потому что любые новые тесты будут добавлены в money_suite(), но в main() ничего менять не нужно будет для остальной части этого примера, поэтому main останется относительно чистым и простым.

>Unit tests are internally defined as static functions. This means that the code to add unit tests to test cases must be in the same compilation unit as the unit tests themselves. This provides another reason to put the creation of the test suite in a separate function: you may later want to keep one source file per suite; defining a uniquely named suite creation function allows you later to define a header file giving prototypes for all the suite creation functions, and encapsulate the details of where and how unit tests are defined behind those functions. See the test program defined for Check itself for an example of this strategy.

Модульные тесты внутренне определены как статические функции. Это означает, что код для добавления модульных тестов в тестовые примеры должен находиться в том же модуле компиляции, что и сами модульные тесты. Это дает еще одну причину выделить создание набора тестов в отдельную функцию: возможно, позже вам захочется сохранить по одному исходному файлу для каждого набора; определение функции создания набора с уникальным именем позволяет вам позже определить заголовочный файл, содержащий прототипы для всех функций создания набора, и инкапсулировать сведения о том, где и как модульные тесты определяются за этими функциями. Смотрите тестовую программу, определенную для самой проверки, в качестве примера этой стратегии.

>The code in main() bears some explanation. We are creating a suite runner object of type SRunner from the Suite we created in money_suite(). We then run the suite, using the CK_NORMAL flag to specify that we should print a summary of the run, and list any failures that may have occurred. We capture the number of failures that occurred during the run, and use that to decide how to return. The check target created by Automake uses the return value to decide whether the tests passed or failed.

Код в main() содержит некоторые пояснения. Мы создаем объект типа suite runner SRunner из Suite, который мы создали в money_suite(). Затем мы запускаем пакет, используя флаг CK_NORMAL, чтобы указать, что мы должны распечатать сводку выполнения и перечислить все возможные сбои, которые могли произойти. Мы фиксируем количество сбоев, произошедших во время запуска, и используем это, чтобы решить, как выполнять возврат. check Цель, созданная Automake, использует возвращаемое значение, чтобы решить, прошли тесты или не прошли.

>Now that the tests are actually being run by check_money, we encounter linker errors again we try out make check. Try it for yourself and see. The reason is that the ‘money.c’ implementation of the ‘money.h’ interface hasn’t been created yet. Let’s go with the fastest solution possible and implement stubs for each of the functions in money.c. Here is the diff:

Теперь, когда тесты фактически выполняются check_money, мы снова сталкиваемся с ошибками компоновщика, которые мы пробуем make check. Попробуйте сами и убедитесь. Причина в том, что ‘money.c’ реализация интерфейса ‘money.h’ еще не создана. Давайте выберем максимально быстрое решение и реализуем заглушки для каждой из функций в money.c. Вот разница:

```c
#include <stdlib.h>
#include "money.h"

Money *money_create(int amount, char *currency) {
    return NULL;
}

int money_amount(Money * m) {
    return 0;
}

char *money_currency(Money * m) {
    return NULL;
}

void money_free(Money * m) {
    return;
}
```

>Note that we `#include <stdlib.h>` to get the definition of NULL. Now, the code compiles and links when we run make check, but our unit test fails. Still, this is progress, and we can focus on making the test pass.

Обратите внимание, что мы `#include <stdlib.h>` хотим получить определение NULL. Теперь код компилируется и связывается при запуске make check, но наш модульный тест завершается неудачей. Тем не менее, это прогресс, и мы можем сосредоточиться на прохождении теста.

[Содержание](#содержание)

## Выходные данные SRunner (SRunner Output)

>The functions to run tests in an SRunner are defined as follows:

Функции для запуска тестов в SRunner определены следующим образом:

```c
void srunner_run_all (SRunner * sr, enum print_output print_mode);

void srunner_run (SRunner *sr, const char *sname, const char *tcname,
                  enum print_output print_mode);
```

>Those functions do two things:

Эти функции выполняют две вещи:

>1. They run all of the unit tests for the selected test cases defined for the selected suites in the SRunner, and collect the results in the SRunner. The determination of the selected test cases and suites depends on the specific function used.<br>
`srunner_run_all` will run all the defined test cases of all defined suites except if the environment variables `CK_RUN_CASE` or `CK_RUN_SUITE` are defined. If defined, those variables shall contain the name of a test suite or a test case, defining in that way the selected suite/test case.<br>
srunner_run will run the suite/case selected by the sname and tcname parameters. A value of NULL in some of those parameters means “any suite/case”.

1. Они запускают все модульные тесты для выбранных тестовых наборов, определенных для выбранных наборов в SRunner, и собирают результаты в SRunner. Определение выбранных тестовых примеров и наборов зависит от конкретной используемой функции.<br>
`srunner_run_all` будут выполняться все определенные тестовые примеры всех определенных наборов, за исключением случаев, когда определены переменные среды `CK_RUN_CASE` или `CK_RUN_SUITE`. Если они определены, эти переменные должны содержать имя набора тестов или тестового набора, определяя таким образом выбранный набор / тестовый набор.<br>
`srunner_run` будет запущен набор / вариант, выбранный параметрами sname и tcname. Значение NULL в некоторых из этих параметров означает “любой набор / вариант”.

>2. They print the results according to the print_mode specified.

2. Они печатают результаты в соответствии с указанным print_mode.

>For `SRunners` that have already been run, there is also a separate printing function defined as follows:

Для `SRunners`, которые уже были запущены, также существует отдельная функция печати, определенная следующим образом:

```c
void srunner_print (SRunner *sr, enum print_output print_mode);
```

>The enumeration values of print_output defined in Check that parameter print_mode can assume are as follows:

Значения перечисления, print_output определенные в Check, которые этот параметр print_mode может принимать, следующие:


### CK_SILENT

>Specifies that no output is to be generated. If you use this flag, you either need to programmatically examine the SRunner object, print separately, or use test logging (see section Test Logging.)

Указывает, что выходные данные генерироваться не должны. Если вы используете этот флаг, вам нужно либо программно проверить объект SRunner, распечатать отдельно, либо использовать ведение журнала тестирования (см. [Test Logging](#ведение-журнала-тестирования-test-logging))

### CK_MINIMAL

> Only a summary of the test run will be printed (number run, passed, failed, errors).

Будет напечатана только сводка по тестовому запуску (количество запусков, пройдено, сбой, ошибки).

### CK_NORMAL

>Prints the summary of the run, and prints one message per failed test.

Выводит сводку выполнения и одно сообщение для каждого неудачного теста.

### CK_VERBOSE

>Prints the summary, and one message per test (passed or failed)

Выводит сводку и по одному сообщению для каждого теста (пройден или не пройден)

### CK_ENV

>Gets the print mode from the environment variable CK_VERBOSITY, which can have the values "silent", "minimal", "normal", "verbose". If the variable is not found or the value is not recognized, the print mode is set to CK_NORMAL.

Получает режим печати из переменной окружения CK_VERBOSITY, которая может иметь значения "тихий", "минимальный", "обычный", "подробный". Если переменная не найдена или значение не распознано, режим печати устанавливается на CK_NORMAL.

### CK_SUBUNIT

>Prints running progress through the [subunit](https://launchpad.net/subunit/) test runner protocol. See ’subunit support’ under the Advanced Features section for more information.

Выводит информацию о ходе выполнения с помощью протокола выполнения тестов subunit. Дополнительную информацию смотрите в разделе "Поддержка subunit" в разделе "Расширенные функции".

> With the CK_NORMAL flag specified in our main(), let’s rerun make check now. The output from the unit test is as follows:

С CK_NORMAL флагом, указанным в нашем main(), давайте повторим make check сейчас. Результат модульного теста следующий:

```c
Running suite(s): Money
0%: Checks: 1, Failures: 1, Errors: 0
check_money.c:9:F:Core:test_money_create:0: Assertion 'money_amount (m)==5' failed: 
money_amount (m)==0, 5==5
FAIL: check_money
=====================================================
1 of 1 test failed
Please report to check-devel@lists.sourceforge.net
=====================================================
```

>Note that the output from make check prior to Automake 1.13 will be the output of the unit test program. Starting with 1.13 Automake will run all unit test programs concurrently and store the output in log files. The output listed above should be present in a log file.

Обратите внимание, что выходные данные из make check до Automake 1.13 будут являться выходными данными программы модульного тестирования. Начиная с 1.13 Automake будет запускать все программы модульного тестирования одновременно и сохранять выходные данные в файлах журнала. Выходные данные, перечисленные выше, должны присутствовать в файле журнала.

>The first number in the summary line tells us that 0% of our tests passed, and the rest of the line tells us that there was one check in total, and of those checks, one failure and zero errors. The next line tells us exactly where that failure occurred, and what kind of failure it was (P for pass, F for failure, E for error).

Первое число в сводной строке сообщает нам, что 0% наших тестов пройдено, а остальная часть строки сообщает нам, что всего была проведена одна проверка, и из этих проверок один сбой и ноль ошибок. Следующая строка точно сообщает нам, где произошел этот сбой и какого рода это был сбой (P для pass, F для failure, E для error).

>After that we have some higher level output generated by Automake: the check_money program failed, and the bug-report address given in ‘configure.ac’ is printed.

После этого мы получаем результат более высокого уровня, сгенерированный Automake: check_money произошел сбой программы, и напечатан адрес отчета об ошибке, указанный в ‘configure.ac’.

>Let’s implement the `money_amount` function, so that it will pass its tests. We first have to create a Money structure to hold the amount, and then implement the function to return the correct amount:

Давайте реализуем `money_amount` функцию, чтобы она прошла тесты. Сначала нам нужно создать денежную структуру для хранения суммы, а затем реализовать функцию для возврата правильной суммы:

```c
#include <stdlib.h>
 #include "money.h"
 
struct Money {
    int amount;
};

Money *money_create(int amount, char *currency) {
    return NULL;
}

int money_amount(Money * m) {
    return m->amount;
}

char *money_currency(Money * m) {
    return NULL;
}

void money_free(Money * m) {
    return;
}
```

>We will now rerun make check and… what’s this? The output is now as follows:

Теперь мы повторно запустим make check и ... что это? Результат теперь выглядит следующим образом:

```bash
Running suite(s): Money
0%: Checks: 1, Failures: 0, Errors: 1
check_money.c:5:E:Core:test_money_create:0: (after this point) 
Received signal 11 (Segmentation fault)
```

>What does this mean? Note that we now have an error, rather than a failure. This means that our unit test either exited early, or was signaled. Next note that the failure message says “after this point”; This means that somewhere after the point noted (‘check_money.c’, line 5) there was a problem: `signal 11 (a.k.a. segmentation fault)`. The last point reached is set on entry to the unit test, and after every call to the `ck_assert()`, `ck_abort()`, `ck_assert_int_*()`, `ck_assert_str_*()`, or the special function `mark_point()`. For example, if we wrote some test code as follows:

Что это значит? Обратите внимание, что теперь у нас ошибка, а не сбой. Это означает, что наш модульный тест либо завершился досрочно, либо был подан сигнал. Далее обратите внимание, что в сообщении об ошибке говорится “после этой точки”; Это означает, что где-то после указанной точки (‘check_money.c’, line 5) возникла проблема: `signal 11 (a.k.a. segmentation fault)`. . Последняя достигнутая точка устанавливается при входе в модульный тест и после каждого вызова `ck_assert()`, `ck_abort()` `ck_assert_int_*()`, `ck_assert_str_*()`, или специальной функции `mark_point()`. Например, если бы мы написали некоторый тестовый код следующим образом:

```c
stuff_that_works ();
mark_point ();
stuff_that_dies ();
```
>then the point returned will be that marked by mark_point().

тогда возвращаемая точка будет отмечена mark_point().

>The reason our test failed so horribly is that we haven’t implemented money_create() to create any Money. We’ll go ahead and implement that, the symmetric money_free(), and money_currency() too, in order to make our unit test pass again, here is a diff:

Причина, по которой наш тест так ужасно провалился, заключается в том, что мы не реализовали money_create() для создания каких-либо Money. Мы продолжим и реализуем это, симметричное money_free(), и money_currency() также, чтобы наш модульный тест снова прошел, вот разница:

```c
#include <stdlib.h>
#include "money.h"

struct Money {
    int amount;
    char *currency;
};

Money *money_create(int amount, char *currency) {
    Money *m = malloc(sizeof(Money));

    if (m == NULL) {
        return NULL;
    }

    m->amount = amount;
    m->currency = currency;
    return m;
}
 
int money_amount(Money * m) {
    return m->amount;
}
 
char *money_currency(Money * m) {
    return m->currency;
}
 
void money_free(Money * m) {
    free(m);
    return;
}
```

[Содержание](#содержание)

# Расширенные функции (Advanced Features)

## Удобные функции тестирования (Convenience Test Functions)

>Using the `ck_assert` function for all tests can lead to lot of repetitive code that is hard to read. For your convenience Check provides a set of functions (actually macros) for testing often used conditions.

Использование функции `ck_assert` для всех тестов может привести к большому количеству повторяющегося кода, который трудно прочитать. Для вашего удобства проверка предоставляет набор функций (фактически макросов) для тестирования часто используемых условий.

>The typical size of an assertion message is less than 80 bytes. However, some of the functions listed below can generate very large messages (up to 4GB allocations were seen in the wild). To prevent this, a limit is placed on the assertion message size. This limit is 4K bytes by default. It can be modified by setting the `CK_MAX_MSG_SIZE` environment variable, or, if it is not set, by invoking the `check_set_max_msg_size()` function. If used, this function must be called, once, before the first assertion.

Типичный размер сообщения с утверждением составляет менее 80 байт. Однако некоторые из перечисленных ниже функций могут генерировать очень большие сообщения (в обычном режиме выделялось до 4 ГБ). Чтобы предотвратить это, на размер сообщения с утверждением установлено ограничение. По умолчанию это ограничение составляет 4k байт. Его можно изменить, установив `CK_MAX_MSG_SIZE` переменную среды или, если она не установлена, вызвав `check_set_max_msg_size()` функцию. Если используется, эта функция должна быть вызвана один раз перед первым утверждением.

### ck_abort

>Unconditionally fails test with default message.

Безоговорочный сбой теста с сообщением по умолчанию.

### ck_abort_msg

>Unconditionally fails test with user supplied message.

Безоговорочный сбой теста с сообщением, предоставленным пользователем.

### ck_assert

>Fails test if supplied condition evaluates to `false`.

Проверка завершается ошибкой, если заданное условие принимает значение `false`.

### ck_assert_msg

>Fails test if supplied condition evaluates to `false` and displays user provided message.

Проверка завершается ошибкой, если заданное условие принимает значение `false` и отображается сообщение, предоставленное пользователем.

### ck_assert_int_eq
### ck_assert_int_ne
### ck_assert_int_lt
### ck_assert_int_le
### ck_assert_int_gt
### ck_assert_int_ge

>Compares two signed integer values (`intmax_t`) and displays a predefined message with both the condition and input parameters on failure. The operator used for comparison is different for each function and is indicated by the last two letters of the function name. The abbreviations `eq`, `ne`, `lt`, `le`, `gt`, and `ge` correspond to `==`, `!=`, `<`, `<=`, `>`, and `>=` respectively.

Сравнивает два целых значения со знаком (`intmax_t`) и отображает предопределенное сообщение как с условием, так и с входными параметрами при сбое. Оператор, используемый для сравнения, отличается для каждой функции и обозначается двумя последними буквами названия функции. Сокращения `eq`, `ne`, `lt`, `le`, `gt` и `ge` соответствуют `==`, `!=`, `<`, `<=`, `>` и `>=`.

### ck_assert_uint_eq
### ck_assert_uint_ne
### ck_assert_uint_lt
### ck_assert_uint_le
### ck_assert_uint_gt
### ck_assert_uint_ge

>Similar to `ck_assert_int_*`, but compares two unsigned integer values (`uintmax_t`) instead.

Аналогично `ck_assert_int_*`, но вместо этого сравнивает два целых значения без знака (`uintmax_t`).

### ck_assert_float_eq
### ck_assert_float_ne
### ck_assert_float_lt
### ck_assert_float_le
### ck_assert_float_gt
### ck_assert_float_ge

>Compares two floating point numbers (float) and displays a predefined message with both the condition and input parameters on failure. The operator used for comparison is different for each function and is indicated by the last two letters of the function name. The abbreviations `eq`, `ne`, `lt`, `le`, `gt`, and `ge` correspond to `==`, `!=`, `<`, `<=`, `>`, and `>=` respectively. <br>
Beware using those operators for floating point numbers because of precision possible loss on every operation on floating point numbers. <br>
For example (1/3)*3==1 would return false, because 1/3==1.333... (or 1.(3) notation in Europe) and cannot be represented by computer logic. As another example 1.1f in fact could be 1.10000002384185791015625 and 2.1f could be 2.099999904632568359375 because of binary representation of floating point numbers. <br>
If you have different mathematical operations used on floating point numbers consider using precision comparisons or integer numbers instead. <br>
But in some cases those operators could be used. For example if you cyclically increment your floating point number only by positive or only by negative values than you may use <, <=, > and >= operators in tests. If your computations must end up with a certain value than == and != operators may be used.

Сравнивает два числа с плавающей запятой (float) и отображает предопределенное сообщение как с условием, так и с входными параметрами при сбое. Оператор, используемый для сравнения, отличается для каждой функции и обозначается двумя последними буквами названия функции. Сокращения `eq`, `ne`, `lt`, `le`, `gt` `ge`, соответствуют `==` и `!=`  `<`, `<=`,` >` и `>=`. <br>
Остерегайтесь использования этих операторов для чисел с плавающей запятой из-за возможной потери точности при каждой операции с числами с плавающей запятой. <br>
Например, (1/3)*3==1 вернет false, потому что 1/3 ==1.333... (или 1.(3) обозначения в Европе) и не могут быть представлены компьютерной логикой. В качестве другого примера 1.1f на самом деле может быть 1.1000000002384185791015625, а 2.1f может быть 2.09999904632568359375 из-за двоичного представления чисел с плавающей запятой. <br>
Если у вас используются другие математические операции с числами с плавающей запятой, рассмотрите возможность использования вместо них прецизионных сравнений или целых чисел. <br>
Но в некоторых случаях эти операторы могут быть использованы. Например, если вы циклически увеличиваете число с плавающей запятой только на положительные или только на отрицательные значения, вы можете использовать операторы <, <=, > и >= в тестах. Если ваши вычисления должны завершиться определенным значением, чем == и != могут использоваться операторы.

### ck_assert_double_eq
### ck_assert_double_ne
### ck_assert_double_lt
### ck_assert_double_le
### ck_assert_double_gt
### ck_assert_double_ge

>Similar to ck_assert_float_*, but compares two double precision floating point values (double) instead.

Аналогично ck_assert_float_*, но вместо этого сравнивает два значения с плавающей запятой двойной точности (double).

### ck_assert_ldouble_eq
### ck_assert_ldouble_ne
### ck_assert_ldouble_lt
### ck_assert_ldouble_le
### ck_assert_ldouble_gt
### ck_assert_ldouble_ge

>Similar to ck_assert_float_*, but compares two double precision floating point values (long double) instead.

Аналогично ck_assert_float_*, но вместо этого сравнивает два значения с плавающей запятой двойной точности (long double).

### ck_assert_float_eq_tol
### ck_assert_float_ne_tol
### ck_assert_float_le_tol
### ck_assert_float_ge_tol

>Compares two floating point numbers (float) with specified user tolerance set by the third parameter (float) and displays a predefined message with both the condition and input parameters on failure. The abbreviations eq, ne, le, and ge correspond to ==, !=, <=, and >= respectively with acceptable error (tolerance) specified by the last parameter. <br>
Beware using those functions for floating comparisons because of (1) errors coming from floating point number representation, (2) rounding errors, (3) floating point errors are platform dependent. Floating point numbers are often internally represented in binary so they cannot be exact power of 10. <br>
All these operators have significant error in comparisons so use them only if you know what you’re doing. Some assertions could fail on one platform and would be passed on another. For example expression 0.02<=0.01+10^-2 is true by meaning, but some platforms may calculate it as false. IEEE 754 standard specifies the floating point number format representation but it does not promise that the same computation carried out on all hardware will produce the same result.

Сравнивает два числа с плавающей запятой (float) с заданным пользователем допуском, установленным третьим параметром (float), и отображает предопределенное сообщение как с условием, так и с входными параметрами при сбое. Сокращения eq, ne, le и ge соответствуют ==, !=, <= и >= соответственно с допустимой ошибкой (допуском), указанной в последнем параметре. <br>
Остерегайтесь использования этих функций для сравнений с плавающей запятой из-за (1) ошибок, возникающих при представлении чисел с плавающей запятой, (2) ошибок округления, (3) ошибок с плавающей запятой зависят от платформы. Числа с плавающей запятой часто внутренне представлены в двоичном формате, поэтому они не могут быть точной степенью 10. <br>
Все эти операторы допускают значительную ошибку при сравнении, поэтому используйте их, только если вы знаете, что делаете. Некоторые утверждения могут завершиться ошибкой на одной платформе и будут переданы на другой. Например, выражение 0.02<=0.01+10^-2 истинно по смыслу, но некоторые платформы могут вычислить его как false . Стандарт IEEE 754 определяет формат представления чисел с плавающей запятой, но он не гарантирует, что одинаковые вычисления, выполняемые на всех аппаратных средствах, приведут к одинаковому результату.

### ck_assert_double_eq_tol
### ck_assert_double_ne_tol
### ck_assert_double_le_tol
### ck_assert_double_ge_tol

>Similar to ck_assert_float_*_tol, but compares two double precision floating point values (double) instead.

Аналогично ck_assert_float_*_tol, но вместо этого сравнивает два значения с плавающей запятой двойной точности (double).

### ck_assert_ldouble_eq_tol
### ck_assert_ldouble_ne_tol
### ck_assert_ldouble_le_tol
### ck_assert_ldouble_ge_tol

>Similar to ck_assert_float_*_tol, but compares two double precision floating point values (long double) instead.

Аналогично ck_assert_float_*_tol, но вместо этого сравнивает два значения с плавающей запятой двойной точности (long double).

### ck_assert_float_finite

>Checks that a floating point number (float) is finite and displays a predefined message with both the condition and input parameter on failure. Finite means that value cannot be positive infinity, negative infinity or NaN ("Not a Number").

Проверяет, что число с плавающей запятой (float) является конечным, и отображает предопределенное сообщение как с условием, так и с входным параметром при сбое. Конечное означает, что значение не может быть положительной бесконечностью, отрицательной бесконечностью или NaN ("Не число").

### ck_assert_double_finite

>Similar to ck_assert_float_finite, but checks double precision floating point value (double) instead.

Аналогично ck_assert_float_finite, но вместо этого проверяет значение с плавающей запятой двойной точности (double).

### ck_assert_ldouble_finite

>Similar to ck_assert_float_finite, but checks double precision floating point value (long double) instead.

Аналогично ck_assert_float_finite, но вместо этого проверяет значение с плавающей запятой двойной точности (long double).

### ck_assert_float_infinite

>Checks that a floating point number (float) is infinite and displays a predefined message with both the condition and input parameter on failure. Infinite means that value may only be positive infinity or negative infinity.

Проверяет, что число с плавающей запятой (float) бесконечно, и при сбое выводит предопределенное сообщение как с условием, так и с входным параметром. Бесконечность означает, что значение может быть только положительной бесконечностью или отрицательной бесконечностью.

### ck_assert_double_infinite

>Similar to ck_assert_float_infinite, but checks double precision floating point value (double) instead.

Аналогично ck_assert_float_infinite, но вместо этого проверяет значение с плавающей запятой двойной точности (double).

### ck_assert_ldouble_infinite

>Similar to ck_assert_float_infinite, but checks double precision floating point value (long double) instead.

Аналогично ck_assert_float_infinite, но вместо этого проверяет значение с плавающей запятой двойной точности (long double).

### ck_assert_float_nan

>Checks that a floating point number (float, double or long double abbreviated as ldouble) is NaN ("Not a Number") and displays a predefined message with both the condition and input parameter on failure.

Проверяет, является ли число с плавающей запятой (float, double или long double ldouble сокращенно как,,,) NaN ("Не числом") и отображает предопределенное сообщение как с условием, так и с входным параметром при сбое.

### ck_assert_double_nan

>Similar to ck_assert_float_nan, but checks double precision floating point value (double) instead.

Аналогично ck_assert_float_nan, но вместо этого проверяет значение с плавающей запятой двойной точности (double).

### ck_assert_ldouble_nan

>Similar to ck_assert_float_nan, but checks double precision floating point value (long double) instead.

Аналогично ck_assert_float_nan, но вместо этого проверяет значение с плавающей запятой двойной точности (long double).

### ck_assert_float_nonnan

>Checks that a floating point number (float) is not NaN ("Not a Number") and displays a predefined message with both the condition and input parameter on failure.

Проверяет, что число с плавающей запятой (float) не является NaN ("Не число"), и отображает предопределенное сообщение как с условием, так и с входным параметром при сбое.

### ck_assert_double_nonnan

>Similar to ck_assert_float_nonnan, but checks double precision floating point value (double) instead.

Аналогично ck_assert_float_nonnan, но вместо этого проверяет значение с плавающей запятой двойной точности (double).

### ck_assert_ldouble_nonnan

>Similar to ck_assert_float_nonnan, but checks double precision floating point value (long double) instead.

Аналогично ck_assert_float_nonnan, но вместо этого проверяет значение с плавающей запятой двойной точности (long double).

### ck_assert_str_eq
### ck_assert_str_ne
### ck_assert_str_lt
### ck_assert_str_le
### ck_assert_str_gt
### ck_assert_str_ge

>Compares two null-terminated `char *` string values, using the `strcmp()` function internally, and displays predefined message with condition and input parameter values on failure. The comparison operator is again indicated by last two letters of the function name. `ck_assert_str_lt(a, b)` will pass if the unsigned numerical value of the character string a is less than that of b. If a NULL pointer is be passed to any comparison macro the check will fail.

Сравнивает два null-завершенной `char *` строку значений, используя `strcmp()` функцию внутренне, и отображает предопределенный сообщение с состоянием и ввод значений параметров при сбое. Оператор сравнения снова обозначается двумя последними буквами названия функции. `ck_assert_str_lt(a, b)` пройдет, если числовое значение без знака символьной строки a меньше, чем у b. Если нулевой указатель будет передан любому макросу сравнения, проверка завершится ошибкой.

### ck_assert_pstr_eq
### ck_assert_pstr_ne

>Similar to ck_assert_str_* macros, but able to check undefined strings. If a NULL pointer would be passed to a comparison macro it would mean that a string is undefined. If both strings are undefined ck_assert_pstr_eq would pass, but ck_assert_pstr_ne would fail. If only one of strings is undefined ck_assert_pstr_eq macro would fail and ck_assert_pstr_ne would pass.

Аналогично ck_assert_str_* макросам, но с возможностью проверки неопределенных строк. Если бы нулевой указатель был передан макросу сравнения, это означало бы, что строка не определена. Если обе строки не определены, ck_assert_pstr_eq пройдет, но ck_assert_pstr_ne завершится ошибкой. Если только одна из строк не определена, ck_assert_pstr_eq макрос завершится ошибкой и ck_assert_pstr_ne пройдет.

### ck_assert_ptr_eq
### ck_assert_ptr_ne

>Compares two pointers and displays predefined message with condition and values of both input parameters on failure. The operator used for comparison is different for each function and is indicated by the last two letters of the function name. The abbreviations eq and ne correspond to == and != respectively.

Сравнивает два указателя и отображает предопределенное сообщение с условием и значениями обоих входных параметров при сбое. Оператор, используемый для сравнения, отличается для каждой функции и обозначается двумя последними буквами названия функции. Сокращения eq и ne соответствуют == и != соответственно.

### ck_assert_ptr_null
### ck_assert_ptr_nonnull

>Compares a pointers against null and displays predefined message with condition and value of the input parameter on failure. ck_assert_ptr_null checks that pointer is equal to NULL and ck_assert_ptr_nonnull checks that pointer is not equal to NULL. ck_assert_ptr_nonnull is highly recommended to use in situations when a function call can return NULL as error indication (like functions that use malloc, calloc, strdup, mmap, etc).

Сравнивает указатели a с null и отображает предопределенное сообщение с условием и значением входного параметра при сбое. ck_assert_ptr_null проверяет, что указатель равен NULL, и ck_assert_ptr_nonnull проверяет, что указатель не равен NULL. ck_assert_ptr_nonnull настоятельно рекомендуется использовать в ситуациях, когда вызов функции может возвращать значение NULL в качестве указания на ошибку (например, функции, использующие malloc, calloc, strdup, mmap и т.д.).

### ck_assert_mem_eq
### ck_assert_mem_ne
### ck_assert_mem_lt
### ck_assert_mem_le
### ck_assert_mem_gt
### ck_assert_mem_ge

>Compares contents of two memory locations of the given length, using the memcmp() function internally, and displays predefined message with condition and input parameter values on failure. The comparison operator is again indicated by last two letters of the function name. ck_assert_mem_lt(a, b) will pass if the unsigned numerical value of memory location a is less than that of b.

Сравнивает содержимое двух ячеек памяти заданной длины, используя внутреннюю функцию memcmp(), и отображает предопределенное сообщение с условием и значениями входных параметров при сбое. Оператор сравнения снова обозначается двумя последними буквами названия функции. ck_assert_mem_lt(a, b) пройдет, если числовое значение ячейки памяти без знака a меньше, чем у b.

### fail

>(Deprecated) Unconditionally fails test with user supplied message.

(Устарело) Безоговорочный сбой теста с сообщением, предоставленным пользователем.

### fail_if

>(Deprecated) Fails test if supplied condition evaluates to true and displays user provided message.

(Устарело) Тест завершается ошибкой, если заданное условие оценивается как true и отображается сообщение, предоставленное пользователем.

### fail_unless

>(Deprecated) Fails test if supplied condition evaluates to false and displays user provided message.

(Устарело) Тест завершается ошибкой, если заданное условие принимает значение false и отображается сообщение, предоставленное пользователем.

[Содержание](#содержание)

## Запуск нескольких обращений (Running Multiple Cases)



[Содержание](#содержание)

## Ведение журнала тестирования (Test Logging)

[Содержание](#содержание)


# Интеграция check.h в проект
Источник: https://adamyagreenenergy.com/kak-ustanovit-checkh-na-macos

Для интеграции библиотеки `check.h` в ваш проект на Mac OS вам потребуется выполнить следующие шаги:
1. Установите check.h с помощью менеджера пакетов Homebrew. Откройте терминал и выполните команду:

```bash
brew install check
```

2. Создайте файл с исходным кодом вашего проекта с расширением .c или .cpp. Например, main.c.
3. Добавьте необходимые директивы препроцессора в начало вашего файла:

```c
#include <check.h>
```

4. Определите ваш тестовый набор с помощью макроса `Suite`. Например:

```c
Suite *my_suite(void) {
    Suite *s;
    TCase *tc_core;
    /* Создаем новый тестовый набор */
    s = suite_create("My Suite");
    /* Создаем новый тестовый контейнер для ядра тестов */
    tc_core = tcase_create("Core");
    /* Добавляем тесты в тестовый контейнер */
    tcase_add_test(tc_core, test_my_function);
    /* Добавляем тестовый контейнер в тестовый набор */
    suite_add_tcase(s, tc_core);
    return s;
}
```

5. Реализуйте вашу функцию, которую требуется протестировать. Например:

```c
int my_function(int a, int b) {
    return a + b;
}
```

6. Создайте тестовую функцию, которая будет проверять правильность работы вашей функции. Например:

```c
void test_my_function(void) {
    int result = my_function(2, 3);
    ck_assert_int_eq(result, 5);
}
```

7. Создайте функцию, которая будет запускать все тестовые наборы. Например:

```c
int main(void) {
    int number_failed;
    Suite *s;
    SRunner *sr;
    /* Создаем новый тестовый набор */
    s = my_suite();
    /* Создаем новый запускатель тестов */
    sr = srunner_create(s);
    /* Запускаем все тесты */
    srunner_run_all(sr, CK_NORMAL);
    /* Получаем количество неудачных тестов */
    number_failed = srunner_ntests_failed(sr);
    /* Освобождаем ресурсы */
    srunner_free(sr);
    return (number_failed == 0) ? 0 : 1;
}
```

8. Настройте ваш проект для сборки и линковки с использованием библиотеки check.h. В вашем Makefile или CMakeLists.txt добавьте следующие строки:

```bash
CC = gcc
CFLAGS = -I/usr/local/include
LDFLAGS = -L/usr/local/lib -lcheck
target: main.c
$(CC) $(CFLAGS) -o target main.c $(LDFLAGS)
```

Соберите и запустите ваш проект:

```
make
```

Получите результаты тестовой проверки. Если все тесты прошли успешно, будет выведено сообщение о том, что все тесты прошли. В противном случае, будет выведено сообщение с информацией о тестах, которые завершились неудачей.

