/*
 * QCoreApplication Подключена изначально,
 * используется для создания программной оболочки Qt
 */
#include <QCoreApplication>

/*
 * QDebug Предоставляет потоки ввода/вывода (как cin, cout) qInfo, qDebug,
 * qWarning (они работают с QString)
 */
#include <QDebug>

/*
 * QtCreator сразу не скажет что это нужно подключать,
 * будет ошибка QSqlQuery не полный тип
 * эти библиотеки предоставляют классы для работы с базами данных.
 * Большая часть библиотек подключается программистами, когда среда на что-то
 * ругается
 */
#include <QDateTime>     // Класс для работы со временем
#include <QSqlDatabase>  // Класс реализующий функционал подключения к БД (База Данных)
#include <QSqlError>  // Класс реализующий функционал ошибки запроса
#include <QSqlQuery>  // Класс реализующий функционал запроса
#include <QSqlRecord>  // Класс реализующий функционал строки результата
#include <QSqlResult>  // Класс реализующий функционал ответа БД
#include <QString>
#include <QVariant>  // Универсальный тип данных, умеет интерпретировать данные в любые типы

int main(int argc, char *argv[]) {
  QCoreApplication a(argc, argv);
  /*
   * Создаем экземпляр класса QSqlDatabase (SQL совместимая База Данных)
   * (не сама БД, а подключение к такой),
   * передаем название драйвера - QODBC (Qt аналог 0DBC драйвера),
   * он поддерживает множество баз данных,
   * но также имеются собственные драйвера для каждой БД)
   */
  QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
  /*
   * Создаем строку подключения
   * в документации на драйвер описывается формат и все аргументы
   */
  QString connectString = "{MySQL 0DBC 8.0 Unicode Driver};";
  connectString.append("Server=localhost;");  // IP,Port
  connectString.append("Database=logs;");     // Schema
  connectString.append("Uid=root; ");         // User
  connectString.append("Pwd=password;");      // Password
  connectString.append("MULTI HOST=l ;");  // соединяем все в одну строку

  /*
   * Передаем строку подключения как имя
   *(оно воспринимается и как строка подключения)
   *можно также использовать методы класса QSqlDatabase для подключения,
   *но они не заработали в моем случае
   */
  db.setDatabaseName(connectString);  // Открываем соединение, получаем
                                      // результат - открылось или нет

  bool ок = db.open();

  /*
   * Читаем последнюю ошибку,
   * конкретно то что ответила БД,
   * также можно прочитать интерпретацию драйвера.
   */

  QString err = db.lastError().databaseText();

  // Выводим все что узнали в консоль
  qInfo() << ок << db.isOpenError() << err;

  /*
   * Создаем экземпляр класса QSqlQuery “Запрос”,
   * сразу передаем ему экземпляр класса ”Подключение к БД”
   */

  QSqlQuery query(db);

  /*
   * Подготавливаем запрос (передаем строку с SQL кодом)
   * (в строке могут присутствовать идентификаторы, начинающиеся с ":"
   */
  query.prepare("INSERT INTO logs.logs (err) VALUES (:err)");

  for (int i = 0; i < 12; i++) {
    /*
     * Биндим (соединяем) (bind - англ. связывать) идентификаторы и значения
     * (при запросе идентификаторы заменяются на значения)
     */
    query.bindValue(":err", i);
    // Выполняем запрос к БД (ехес - от англ. execute - выполнить)
    query.exec();
  };
  // Создаем новый запрос
  QSqlQuery query_get(db);

  // Вводим SQL для получения последних 5 строк
    query_get.prepare("SELECT * 
                        FROM logs.logs 
                        ORDER ВУ id 
                        DESC 
                        LIMIT 5");
    query_get.exec();// Выполняем запрос
    
    qInfo() << Qt::endl;
    /*
    * Запрос возвращает множество строк (массив),
    * мы можем перемещаться по элементам массива с помощью метода next,
    * этот метод двигает ”курсор” по массиву, изначально курсор не выставлен,
    * поэтому первый вызов next() передвигает на первую запись
    */
    while (query_get.next()) {
    /*
     * Читаем значения под курсором
     *по их названиям и преобразуем в соответствующие типы данных
     */
    uint id = query_get.value("id").toUInt();
    QDateTime time = query_get.value("time").toDateTime();
    uint err = query_get.value("err").toUInt();

    // Выводим в консоль

    qInfo()
            // Настраиваем поток вывода
            .noquote()
        << id
        << " "
        // Преобразуем дату в текстовый формат
        << time.toString("yyyy ММ dd hh тт ss") << " " << err << Qt::endl;
    }
    return а.exec();
}
