# s21_3DViewer

## О возможностях программы

Программа предоставляет возможность:

- Загружать каркасную модель из файла формата obj (поддержка только списка вершин и поверхностей);
- Перемещать модель на заданное расстояние относительно осей X, Y, Z;
- Поворачивать модель на заданный угол относительно своих осей X, Y, Z;
- Масштабировать модель на заданное значение.

Графический пользовательский интерфейс содержит:

- Кнопку для выбора файла с моделью и поле для вывода его названия;
- Зону визуализации каркасной модели;
- Кнопки и поля ввода для перемещения модели;
- Кнопки и поля ввода для поворота модели;
- Кнопки и поля ввода для масштабирования модели;
- Информацию о загруженной модели - название файла, кол-во вершин и ребер.

Дополнительные возможности:

- Программа позволяет настраивать тип проекции (параллельная и центральная);
- Программа позволяет настраивать тип (сплошная, пунктирная), цвет и толщину ребер, способ отображения (отсутствует, круг, квадрат), цвет и размер вершинж;
- Программа позволяет выбирать цвет фона;
- Настройки сохраняются между перезапусками программы;
- Программа позволяет сохранять полученные ("отрендеренные") изображения в файл в форматах bmp и jpeg;
- Программа позволяет записывать небольшие "скринкасты" - текущие пользовательские аффинные преобразования загруженного объекта в gif-анимацию (640x480, 10fps, 5s).

### Установка программы

В терминале перейдите в папку проекта и запустите `make install`.

### Запуск программы

В терминале перейдите в папку проекта и запустите `make start`.

### Удаление программы

В терминале перейдите в папку проекта и запустите `make uninstall`.

### Сделано

[christik@student.21-school.ru](christik@student.21-school.ru)  
[pickling@student.21-school.ru](pickling@student.21-school.ru)  
[melodiea@student.21-school.ru](melodiea@student.21-school.ru)  

[GitHub](https://github.com/pickling-21/s21_3dViewer)
