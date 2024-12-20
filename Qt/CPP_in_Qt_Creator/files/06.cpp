#include <QCoreApplication>
#include <QFile>
#include <QTextStream>
#include <iostream>

int main(int argc, char *argv[]) {
  QCoreApplication a(argc, argv);
  QFile fileInt("C:/Projects/QtProj\\CPP_QFile\\fileInt.txt");
  QFile file(
      "C:/Projects/QtProj\\CPP_QFile\\file.txt");  // Передаем путь к файлу,
                                                   // обратные слеши либо
                                                   // экранируем повторным
                                                   // слешем, либо ставим
                                                   // одинарные обычные слеши /
  // Пытаемся открыть файл, для этого передаем в функцию open параметры
  // открытия, это перечисления которые есть в классе QIODevice, обращаемся к
  // ним с помощью :: Мы можем написать неограниченное количество флагов,
  // разделяя из вертикальной чертой |, вертикальная черта - это бинарное или
  // например, QIODevice::ReadWrite = 3, а QIODevice::ReadOnly = 1.
  // При бинарном "или" используется бинарное представление числа соответственно

  QIODevice::ReadWrite = 00000011,
  а QIODevice::ReadOnly = 00000001

      // после бинарного "или" получится 00000011, наибольшие права доступа.
      // Так сделано во всех функциях, которые принимают флаги.

      if (file.open(QIODevice::ReadWrite | QIODevice::Text) &&
          fileInt.open(QIODevice::ReadWrite | QIODevice::Truncate))
  // Функция open возвращает true, если файл открыт и false, если произошла
  // ошибка
  {
    QTextStream ts(&file);  // Создаем текстовый поток ввода-вывода, на основе
                            // открытого файла, передаем адрес файла
    ts << " world!";  // Если пишем в поток ввода-вывода, используем операторы
                      // <<
    char data0[100];
    ts >> data0;  // Для чтения >> аналогично cout/cin
    std::cout << data0 << std::endl;
    char data1[100] = "Hello!";
    char data2[100];
    file.write(data1, 100);  // Если нужно писать бинарную информацию, пишем
                             // прямо в файл, из массива
    // если мы используем массив символов char, то все работает
    int dataINT[200] = {
        1, 2, 3};  // но с массивами других типов это не сработает, так как
                   // нужно передавать количество байт а не ячеек
    fileInt.write((char *)dataINT,
                  200);  // поэтому нужно использовать явное преобразование, для
                         // этого перед переменной ставится (char *)
    std::cout << sizeof(dataINT)
              << std::endl;  // важно помнить, что при явном преобразовании мы
                             // меняем размер ячейки
    // Когда мы объявляли int dataINT[200], мы выделили 200 * sizeof(int) = 800
    // байт После чего преобразовали в тип char и выражение :200 * sizeof(сhar)
    // = 200 байт уже не верно После преобразования массива из int в char размер
    // массива вырос в 4 раза, ячеек стало 800
    fileInt.write((char *)dataINT, 800);  // Так мы запишем весь массив в файл

    char dataIntRead[800];
    fileInt.seek(0);  // устанавливаем курсор в файле на позицию 0, при записи
                      // мы также можем менять положение курсора в файле, данные
                      // будут заменяться, а не вставляться в строку

    fileInt.read(dataIntRead, 100);  // также можем прочитать из файла в массив
                                     // символов, а потом преобразовать
    std::cout << ((int *)dataIntRead)[0] << "_" << ((int *)dataIntRead)[1]
              << "_" << ((int *)dataIntRead)[2]
              << std::endl;  // Здесь необходимы дополнительные скобки перед
                             // взятием индекса. И после такого преобразования
                             // количество ячеек в массиве сократилось в 4 раза

    std::cout << data2 << std::endl;
    fileInt.seek(0);  // Устанавливаем курсор в файле на позицию 0
    QByteArray BArr = fileInt.read(100);  // читаем с начала тот же файл
    std::cout << ((int *)BArr.data())[0] << "_" << ((int *)BArr.data())[1]
              << "_" << ((int *)BArr.data())[2] << std::endl;
    file.close();
    fileInt.close();
  }
  else {
    std::cout << "file not open" << std::endl;
  }
  return a.exec();
}

// QObject -> QIODevice -> QFileDevice -> QFile -> QTemporaryFile
//  -> QSaveFile
// Классы наследуются в таком порядке, соответственно у класса QFile есть все
// методы классов QFileDevice, QIODevice и QObject Нет необходимости
// преобразовывать класс, QFile для доступа к методам класса QIODevice Так
// происходит во всей системе классов во всех языках программирования
// поддерживающих классы.