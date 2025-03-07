# Основы ООП. Введение в паттерны проектирования

Курс содержит теорию, необходимую для выполнения практических работ.
Всего необходимо выполнить несколько практических и курсовой проект, которые отражает приобретенные навыки и знания по ходу изучения дисциплины и контрольную точку.

Курс содержит 6 разделов:

# [1. Введение](/CPP_from_LETI/LETI_03/01.md)


+ [1.1 Информация по курсу](/CPP_from_LETI/LETI_03/01.md#11-информация-по-курсу)
    + [ООП?](/CPP_from_LETI/LETI_03/01.md#ооп)
	+ [Обо всем и ни о чём](/CPP_from_LETI/LETI_03/01.md#обо-всем-и-ни-о-чем)
	+ [Рекомендованная литература](/CPP_from_LETI/LETI_03/01.md#рекомендованная-литература)
+ [1.2 Стиль написания кода](/CPP_from_LETI/LETI_03/01.md#12-стиль-написания-кода)
	+ [Все имена следует записывать по-английски](/CPP_from_LETI/LETI_03/01.md#все-имена-следует-записывать-по-английски)
	+ [Имена переменных должны быть записаны в смешанном регистре, начиная с нижнего.](/CPP_from_LETI/LETI_03/01.md#имена-переменных-должны-быть-записаны-в-смешанном-регистре-начиная-с-нижнего)
	+ [Именованные константы должны быть записаны в верхнем регистре с нижним подчеркиванием в качестве разделителя](/CPP_from_LETI/LETI_03/01.md#именованные-константы-должны-быть-записаны-в-верхнем-регистре-с-нижним-подчеркиванием-в-качестве-разделителя)
	+ [Названия методов и функций должны быть глаголами, быть записанными в смешанном регистре и начинаться с нижнего](/CPP_from_LETI/LETI_03/01.md#названия-методов-и-функций-должны-быть-глаголами-быть-записанными-в-смешанном-регистре-и-начинаться-с-нижнего)
	+ [Следует называть имена типов в шаблонах одной заглавной буквой](/CPP_from_LETI/LETI_03/01.md#следует-называть-имена-типов-в-шаблонах-одной-заглавной-буквой)
	+ [Аббревиатуры и сокращения в именах должны записываться в нижнем регистре](/CPP_from_LETI/LETI_03/01.md#аббревиатуры-и-сокращения-в-именах-должны-записываться-в-нижнем-регистре)
	+ [Префикс is следует использовать только для булевых (логических) переменных и методов](/CPP_from_LETI/LETI_03/01.md#префикс-is-следует-использовать-только-для-булевых-логических-переменных-и-методов)
	+ [Имена должны передавать намерения программиста](/CPP_from_LETI/LETI_03/01.md#имена-должны-передавать-намерения-программиста)
	+ [Избегайте дезинформации](/CPP_from_LETI/LETI_03/01.md#избегайте-дезинформации)
	+ [Используйте осмысленные различия](/CPP_from_LETI/LETI_03/01.md#используйте-осмысленные-различия)
	+ [Используйте удобопроизносимые имена](/CPP_from_LETI/LETI_03/01.md#используйте-удобопроизносимые-имена)
	+ [Избегайте мысленных преобразований](/CPP_from_LETI/LETI_03/01.md#избегайте-мысленных-преобразований)
	+ [Добавьте содержательный контекст](/CPP_from_LETI/LETI_03/01.md#добавьте-содержательный-контекст)
	+ [Содержимое файлов не должно превышать 80 колонок](/CPP_from_LETI/LETI_03/01.md#содержимое-файлов-не-должно-превышать-80-колонок)
	+ [Директивы включения должны располагаться только в начале файла](/CPP_from_LETI/LETI_03/01.md#директивы-включения-должны-располагаться-только-в-начале-файла)
	+ [Следует избегать использования глобальных переменных](/CPP_from_LETI/LETI_03/01.md#следует-избегать-использования-глобальных-переменных)
	+ [Переменные следует объявлять в как можно меньшей области видимости](/CPP_from_LETI/LETI_03/01.md#переменные-следует-объявлять-в-как-можно-меньшей-области-видимости)
	+ [Нельзя включать в конструкцию for() выражения, не относящиеся к управлению циклом](/CPP_from_LETI/LETI_03/01.md#нельзя-включать-в-конструкцию-for-выражения-не-относящиеся-к-управлению-циклом)
	+ [Можно избегать циклов do-while](/CPP_from_LETI/LETI_03/01.md#можно-избегать-циклов-do-while)
	+ [Следует избегать использования break и continue в циклах](/CPP_from_LETI/LETI_03/01.md#следует-избегать-использования-break-и-continue-в-циклах)
	+ [Не следует использовать goto](/CPP_from_LETI/LETI_03/01.md#не-следует-использовать-goto)
	+ [Для бесконечных циклов следует использовать форму `while (true)`](/CPP_from_LETI/LETI_03/01.md#для-бесконечных-циклов-следует-использовать-форму-while-true)
	+ [Условие следует размещать в отдельной строке](/CPP_from_LETI/LETI_03/01.md#условие-следует-размещать-в-отдельной-строке)
	+ [Рекомендации к пробелам](/CPP_from_LETI/LETI_03/01.md#рекомендации-к-пробелам)
	+ [Не используйте комментарии там, где можно использовать функцию или переменную.](/CPP_from_LETI/LETI_03/01.md#не-используйте-комментарии-там-где-можно-использовать-функцию-или-переменную)
	+ [Сложный код, написанный с использованием хитрых ходов, следует не комментировать, а переписывать!](/CPP_from_LETI/LETI_03/01.md#сложный-код-написанный-с-использованием-хитрых-ходов-следует-не-комментировать-а-переписывать)

# [2. Классы](/CPP_from_LETI/LETI_03/02.md)

+ [2.1 Описание классов и объектов](/CPP_from_LETI/LETI_03/02.md#21-описание-классов-и-объектов)
    + [Описание класса](/CPP_from_LETI/LETI_03/02.md#описание-класса)
    + [Поля класса:](/CPP_from_LETI/LETI_03/02.md#поля-класса)
    + [Описание объектов](/CPP_from_LETI/LETI_03/02.md#описание-объектов)
    + [Указатели на объекты классов](/CPP_from_LETI/LETI_03/02.md#указатели-на-объекты-классов)
    + [Указатель this](/CPP_from_LETI/LETI_03/02.md#указатель-this)
    + [Рекомендации по составу класса](/CPP_from_LETI/LETI_03/02.md#рекомендации-по-составу-класса)
    + [Отличия структур и объединений от классов](/CPP_from_LETI/LETI_03/02.md#отличия-структур-и-объединений-от-классов)
    + [Задачи](/CPP_from_LETI/LETI_03/02.md#задачи-1)
+ [2.2 Конструкторы и деструкторы](/CPP_from_LETI/LETI_03/02.md#22-конструкторы-и-деструкторы)
    + [Конструкторы](/CPP_from_LETI/LETI_03/02.md#конструкторы)
    + [Конструктор копирования](/CPP_from_LETI/LETI_03/02.md#конструктор-копирования)
    + [Деструкторы](/CPP_from_LETI/LETI_03/02.md#деструкторы)
    + [Задачи](/CPP_from_LETI/LETI_03/02.md#задачи-2)
+ [2.3 Статические элементы класса](/CPP_from_LETI/LETI_03/02.md#23-статические-элементы-класса)
    + [Статические элементы класса](/CPP_from_LETI/LETI_03/02.md#статические-элементы-класса)
    + [Статические поля](/CPP_from_LETI/LETI_03/02.md#статические-поля)
    + [Статические методы](/CPP_from_LETI/LETI_03/02.md#статические-методы)
    + [Задачи](/CPP_from_LETI/LETI_03/02.md#задачи-3)
+ [2.4 Дружественные функции и классы](/CPP_from_LETI/LETI_03/02.md#24-дружественные-функции-и-классы)
    + [Дружественные функции и классы](/CPP_from_LETI/LETI_03/02.md#дружественные-функции-и-классы)
    + [Дружественная функция](/CPP_from_LETI/LETI_03/02.md#дружественная-функция)
+ [2.5 Перегрузка операций](/CPP_from_LETI/LETI_03/02.md#25-перегрузка-операций)
    + [Перегрузка операций](/CPP_from_LETI/LETI_03/02.md#перегрузка-операций)
    + [Перегрузка унарных операций](/CPP_from_LETI/LETI_03/02.md#перегрузка-унарных-операций)
    + [Перегрузка бинарных операций](/CPP_from_LETI/LETI_03/02.md#перегрузка-бинарных-операций)
    + [Перегрузка операции присваивания](/CPP_from_LETI/LETI_03/02.md#перегрузка-операции-присваивания)
    + [Перегрузка операций new и delete](/CPP_from_LETI/LETI_03/02.md#перегрузка-операций-new-и-delete)
    + [Перегрузка операции приведения типа](/CPP_from_LETI/LETI_03/02.md#перегрузка-операции-приведения-типа)
    + [Перегрузка операции вызова функции](/CPP_from_LETI/LETI_03/02.md#перегрузка-операции-вызова-функции)
    + [Перегрузка операции индексирования](/CPP_from_LETI/LETI_03/02.md#перегрузка-операции-индексирования)
    + [Задачи, надо доделать](/CPP_from_LETI/LETI_03/02.md#todo-1)
+ [2.6 Обработки исключений](/CPP_from_LETI/LETI_03/02.md#26-обработки-исключений)
    + [Обработка исключений](/CPP_from_LETI/LETI_03/02.md#обработка-исключений)
    + [Общий механизм обработки исключений](/CPP_from_LETI/LETI_03/02.md#общий-механизм-обработки-исключений)
    + [Синтаксис исключений](/CPP_from_LETI/LETI_03/02.md#синтаксис-исключений)
    + [Перехват исключений](/CPP_from_LETI/LETI_03/02.md#перехват-исключений)
    + [Список исключений функции](/CPP_from_LETI/LETI_03/02.md#список-исключений-функции)
    + [Исключения в конструкторах и деструкторах](/CPP_from_LETI/LETI_03/02.md#исключения-в-конструкторах-и-деструкторах)
    + [Иерархии исключений](/CPP_from_LETI/LETI_03/02.md#иерархии-исключений)

# [3. Объектно-ориентированная парадигма](/CPP_from_LETI/LETI_03/03.md)

+ [3.1 Фундаменты ООП](/CPP_from_LETI/LETI_03/03.md#31-фундаменты-ооп)
    + [Абстракция](/CPP_from_LETI/LETI_03/03.md#абстракция)
    + [Инкапсуляция](/CPP_from_LETI/LETI_03/03.md#инкапсуляция)
    + [Наследование](/CPP_from_LETI/LETI_03/03.md#наследование)
    + [Ключи доступа](/CPP_from_LETI/LETI_03/03.md#ключи-доступа)
    + [Простое наследование](/CPP_from_LETI/LETI_03/03.md#простое-наследование)
    + [Правила наследования различных методов](/CPP_from_LETI/LETI_03/03.md#правила-наследования-различных-методов)
    + [Виртуальные методы](/CPP_from_LETI/LETI_03/03.md#виртуальные-методы)
    + [Механизм позднего связывания](/CPP_from_LETI/LETI_03/03.md#механизм-позднего-связывания)
    + [Абстрактные классы](/CPP_from_LETI/LETI_03/03.md#абстрактные-классы)
    + [Множественное наследование](/CPP_from_LETI/LETI_03/03.md#множественное-наследование)
    + [Задачи](/CPP_from_LETI/LETI_03/03.md#задачи-1)
+ [3.2 Принципы SOLID ООП](/CPP_from_LETI/LETI_03/03.md#32-принципы-solid-ооп)
    + [Принцип единственной ответственности (SRP)](/CPP_from_LETI/LETI_03/03.md#принцип-единственной-ответственности-srp)
        + [Признак 1: непреднамеренное дублирование](/CPP_from_LETI/LETI_03/03.md#признак-1-непреднамеренное-дублирование)
        + [Признак 2: слияния](/CPP_from_LETI/LETI_03/03.md#признак-2-слияния)
        + [Решение](/CPP_from_LETI/LETI_03/03.md#решение)
    + [Принцип открытости/закрытости (OCP)](/CPP_from_LETI/LETI_03/03.md#принцип-открытостизакрытости-ocp)
    + [Принцип подстановки Барбары Лисков (LSP)](/CPP_from_LETI/LETI_03/03.md#принцип-подстановки-барбары-лисков-lsp)
        + [Проблема квадрат/прямоугольник](/CPP_from_LETI/LETI_03/03.md#проблема-квадратпрямоугольник)
    + [Принцип разделения интерфейса (ISP)](/CPP_from_LETI/LETI_03/03.md#принцип-разделения-интерфейса-isp)
    + [Принцип инверсии зависимостей (DIP)](/CPP_from_LETI/LETI_03/03.md#принцип-инверсии-зависимостей-dip)

# [4. Паттерны проектирования](/CPP_from_LETI/LETI_03/04.md)

+ [4.1 Виды паттернов проектирования](/CPP_from_LETI/LETI_03/04.md#41-виды-паттернов-проектирования)
    + [Паттерны проектирования](/CPP_from_LETI/LETI_03/04.md#паттерны-проектирования)
    + [Классификация паттернов](/CPP_from_LETI/LETI_03/04.md#классификация-паттернов)
+ [4.2 Порождающие паттерны проектирования](/CPP_from_LETI/LETI_03/04.md#42-порождающие-паттерны-проектирования)
    + [Виды порождающих паттернов проектирования](/CPP_from_LETI/LETI_03/04.md#виды-порождающих-паттернов-проектирования)
    + [Порождающие паттерны проектирования](/CPP_from_LETI/LETI_03/04.md#порождающие-паттерны-проектирования)
    + [Фабричный метод](/CPP_from_LETI/LETI_03/04.md#фабричный-метод)
    + [Пример использования Фабричного метода (Factory Method)](/CPP_from_LETI/LETI_03/04.md#пример-использования-фабричного-метода-factory-method)
        + [Реализация паттерна `Factory Method` на основе обобщенного конструктора](/CPP_from_LETI/LETI_03/04.md#реализация-паттерна-factory-method-на-основе-обобщенного-конструктора)
        + [Классическая реализация паттерна `Factory Method`](/CPP_from_LETI/LETI_03/04.md#классическая-реализация-паттерна-factory-method)
    + [Абстрактная фабрика](/CPP_from_LETI/LETI_03/04.md#абстрактная-фабрика)
    + [Пример использования Абстрактной фабрики](/CPP_from_LETI/LETI_03/04.md#пример-использования-абстрактной-фабрики)
    + [Строитель](/CPP_from_LETI/LETI_03/04.md#строитель)
    + [Пример использования Строителя](/CPP_from_LETI/LETI_03/04.md#пример-использования-строителя)
    + [Прототип](/CPP_from_LETI/LETI_03/04.md#прототип)
    + [Пример использования Прототипа](/CPP_from_LETI/LETI_03/04.md#пример-использования-прототипа)
    + [Одиночка](/CPP_from_LETI/LETI_03/04.md#одиночка)
    + [Пример использования Одиночки](/CPP_from_LETI/LETI_03/04.md#пример-использования-одиночки)
        + [Рассмотрим наиболее часто встречающуюся реализацию паттерна `Singleton`.](/CPP_from_LETI/LETI_03/04.md#рассмотрим-наиболее-часто-встречающуюся-реализацию-паттерна-singleton)
        + [Singleton Мэйерса](/CPP_from_LETI/LETI_03/04.md#singleton-мэйерса)
        + [Улучшенная версия классической реализации Singleton](/CPP_from_LETI/LETI_03/04.md#улучшенная-версия-классической-реализации-singleton)
        + [Использование нескольких взаимозависимых одиночек](/CPP_from_LETI/LETI_03/04.md#использование-нескольких-взаимозависимых-одиночек)
    + [Вопросы](/CPP_from_LETI/LETI_03/04.md#вопросы)
+ [4.3 Структурные паттерны проектирования](/CPP_from_LETI/LETI_03/04.md#43-структурные-паттерны-проектирования)
    + [Виды структурных паттернов проектирования](/CPP_from_LETI/LETI_03/04.md#виды-структурных-паттернов-проектирования)
    + [Адаптер](/CPP_from_LETI/LETI_03/04.md#адаптер)
    + [Пример использования паттерна `Адаптер`](/CPP_from_LETI/LETI_03/04.md#пример-использования-паттерна-адаптер)
    + [Мост](/CPP_from_LETI/LETI_03/04.md#мост)
    + [Пример использования паттерна `Мост`](/CPP_from_LETI/LETI_03/04.md#пример-использования-паттерна-мост)
    + [Компоновщик](/CPP_from_LETI/LETI_03/04.md#компоновщик)
    + [Пример использования паттерна Компоновщик (Composite)](/CPP_from_LETI/LETI_03/04.md#пример-использования-паттерна-компоновщик-composite)
    + [Декоратор](/CPP_from_LETI/LETI_03/04.md#декоратор)
    + [Пример использования паттерна Компоновщик (Component)](/CPP_from_LETI/LETI_03/04.md#пример-использования-паттерна-компоновщик-component)
    + [Фасад](/CPP_from_LETI/LETI_03/04.md#фасад)
    + [Пример использования паттерна Фасад (Facade)](/CPP_from_LETI/LETI_03/04.md#пример-использования-паттерна-фасад-facade)
    + [Примеры реализации паттерна Легковес (Flyweight)](/CPP_from_LETI/LETI_03/04.md#примеры-реализации-паттерна-легковес-flyweight)
    + [Примеры использования паттерна Заместитель (Proxy)](/CPP_from_LETI/LETI_03/04.md#примеры-использования-паттерна-заместитель-proxy)
    + [Вопросы](/CPP_from_LETI/LETI_03/04.md#вопросы-3)
+ [4.4 Поведенческие паттерны проектирования](/CPP_from_LETI/LETI_03/04.md#44-поведенческие-паттерны-проектирования)
    + [Виды поведенческих паттернов проектирования](/CPP_from_LETI/LETI_03/04.md#виды-поведенческих-паттернов-проектирования)
    + [Цепочка обязанностей](/CPP_from_LETI/LETI_03/04.md#цепочка-обязанностей)
    + [Итератор](/CPP_from_LETI/LETI_03/04.md#итератор)
    + [Пример использования паттерна Итератор (Iterator)](/CPP_from_LETI/LETI_03/04.md#пример-использования-паттерна-итератор-iterator)
    + [Посредник](/CPP_from_LETI/LETI_03/04.md#посредник)
    + [Пример использования паттерна Посредник (Mediator)](/CPP_from_LETI/LETI_03/04.md#пример-использования-паттерна-посредник-mediator)
    + [Пример использования паттерна Снимок (Memento)](/CPP_from_LETI/LETI_03/04.md#пример-использования-паттерна-снимок-memento)
    + [Состояние](/CPP_from_LETI/LETI_03/04.md#состояние)
    + [Примеры использования паттерна Состояние (State)](/CPP_from_LETI/LETI_03/04.md#примеры-использования-паттерна-состояние-state)
    + [Пример использования паттерна Стратегия (Strategy)](/CPP_from_LETI/LETI_03/04.md#пример-использования-паттерна-стратегия-strategy)
    + [Шаблонный метод](/CPP_from_LETI/LETI_03/04.md#шаблонный-метод)
    + [Примеры реализации паттерна Шаблонный метод (TemplateMethod)](/CPP_from_LETI/LETI_03/04.md#примеры-реализации-паттерна-шаблонный-метод-templatemethod)
    + [Посетитель](/CPP_from_LETI/LETI_03/04.md#посетитель)
    + [Примеры реализации паттерна Посетитель (Visitor)](/CPP_from_LETI/LETI_03/04.md#примеры-реализации-паттерна-посетитель-visitor)
    + [Вопросы](/CPP_from_LETI/LETI_03/04.md#вопросы-4)
+ [4.5 Задания на разработку](/CPP_from_LETI/LETI_03/04.md#45-задания-на-разработку)
    + [Введение в ООП: создание классов, конструкторов классов, методов классов; наследование ](/CPP_from_LETI/LETI_03/04.md#введение-в-ооп-создание-классов-конструкторов-классов-методов-классов-наследование)
    + [Интерфейсы классов, взаимодействие классов, перегрузка операций](/CPP_from_LETI/LETI_03/04.md#интерфейсы-классов-взаимодействие-классов-перегрузка-операций)
    + [Логическое разделение классов](/CPP_from_LETI/LETI_03/04.md#логическое-разделение-классов)
    + [Полиморфизм](/CPP_from_LETI/LETI_03/04.md#полиморфизм)
    + [Сериализация состояния программы](/CPP_from_LETI/LETI_03/04.md#сериализация-состояния-программы)
    + [Шаблонные классы](/CPP_from_LETI/LETI_03/04.md#шаблонные-классы)
+ [4.6 Курсовой проект](/CPP_from_LETI/LETI_03/04.md#46-курсовой-проект)

# [5. Проверка знаний](/CPP_from_LETI/LETI_03/05.md)

Требования к курсовой работе изложены в разделе "Курсовая работа".