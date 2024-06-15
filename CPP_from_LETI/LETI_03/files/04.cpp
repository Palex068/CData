// #include <iostream>
// #include <vector>
// #include <cassert>

// using namespace std;

// enum Warrior_ID { Infantryman_ID = 0, Archer_ID, Horseman_ID };

// // Иерархия классов игровых персонажей
// class Warrior {
//    public:
//     virtual void info() = 0;
//     virtual ~Warrior() {}
//     // Параметризированный статический фабричный метод
//     static Warrior* createWarrior(Warrior_ID id);
// };

// class Infantryman : public Warrior {
//    public:
//     void info() { cout << "Infantryman" << endl; }
// };

// class Archer : public Warrior {
//    public:
//     void info() { cout << "Archer" << endl; }
// };

// class Horseman : public Warrior {
//    public:
//     void info() { cout << "Horseman" << endl; }
// };

// // Реализация параметризированного фабричного метода
// Warrior* Warrior::createWarrior(Warrior_ID id) {
//     Warrior* p;
//     switch (id) {
//         case Infantryman_ID:
//             p = new Infantryman();
//             break;
//         case Archer_ID:
//             p = new Archer();
//             break;
//         case Horseman_ID:
//             p = new Horseman();
//             break;
//         default:
//             assert(false);
//     }
//     return p;
// };

// // Создание объектов при помощи параметризированного фабричного метода
// int main() {
//     vector<Warrior*> v;
//     v.push_back(Warrior::createWarrior(Infantryman_ID));
//     v.push_back(Warrior::createWarrior(Archer_ID));
//     v.push_back(Warrior::createWarrior(Horseman_ID));

//     for (int i = 0; i < v.size(); i++) v[i]->info();
//     // ...
// }

// #include <iostream>
// #include <vector>

// using namespace std;

// // Иерархия классов игровых персонажей
// class Warrior {
//    public:
//     virtual void info() = 0;
//     virtual ~Warrior() {}
// };

// class Infantryman : public Warrior {
//    public:
//     void info() { cout << "Infantryman" << endl; };
// };

// class Archer : public Warrior {
//    public:
//     void info() { cout << "Archer" << endl; };
// };

// class Horseman : public Warrior {
//    public:
//     void info() { cout << "Horseman" << endl; };
// };

// // Фабрики объектов
// class Factory {
//    public:
//     virtual Warrior* createWarrior() = 0;
//     virtual ~Factory() {}
// };

// class InfantryFactory : public Factory {
//    public:
//     Warrior* createWarrior() { return new Infantryman; }
// };

// class ArchersFactory : public Factory {
//    public:
//     Warrior* createWarrior() { return new Archer; }
// };

// class CavalryFactory : public Factory {
//    public:
//     Warrior* createWarrior() { return new Horseman; }
// };

// // Создание объектов при помощи фабрик объектов
// int main() {
//     InfantryFactory* infantry_factory = new InfantryFactory;
//     ArchersFactory* archers_factory = new ArchersFactory;
//     CavalryFactory* cavalry_factory = new CavalryFactory;

//     vector<Warrior*> v;
//     v.push_back(infantry_factory->createWarrior());
//     v.push_back(archers_factory->createWarrior());
//     v.push_back(cavalry_factory->createWarrior());

//     for (int i = 0; i < v.size(); i++) v[i]->info();
//     // ...
// }

// #include <iostream>
// #include <vector>

// using namespace std;

// // Абстрактные базовые классы всех возможных видов воинов
// class Infantryman {
//    public:
//     virtual void info() = 0;
//     virtual ~Infantryman() {}
// };

// class Archer {
//    public:
//     virtual void info() = 0;
//     virtual ~Archer() {}
// };

// class Horseman {
//    public:
//     virtual void info() = 0;
//     virtual ~Horseman() {}
// };

// // Классы всех видов воинов Римской армии
// class RomanInfantryman : public Infantryman {
//    public:
//     void info() { cout << "RomanInfantryman" << endl; }
// };

// class RomanArcher : public Archer {
//    public:
//     void info() { cout << "RomanArcher" << endl; }
// };

// class RomanHorseman : public Horseman {
//    public:
//     void info() { cout << "RomanHorseman" << endl; }
// };

// // Классы всех видов воинов армии Карфагена
// class CarthaginianInfantryman : public Infantryman {
//    public:
//     void info() { cout << "CarthaginianInfantryman" << endl; }
// };

// class CarthaginianArcher : public Archer {
//    public:
//     void info() { cout << "CarthaginianArcher" << endl; }
// };

// class CarthaginianHorseman : public Horseman {
//    public:
//     void info() { cout << "CarthaginianHorseman" << endl; }
// };

// // Абстрактная фабрика для производства воинов
// class ArmyFactory {
//    public:
//     virtual Infantryman* createInfantryman() = 0;
//     virtual Archer* createArcher() = 0;
//     virtual Horseman* createHorseman() = 0;
//     virtual ~ArmyFactory() {}
// };

// // Фабрика для создания воинов Римской армии
// class RomanArmyFactory : public ArmyFactory {
//    public:
//     Infantryman* createInfantryman() { return new RomanInfantryman; }
//     Archer* createArcher() { return new RomanArcher; }
//     Horseman* createHorseman() { return new RomanHorseman; }
// };

// // Фабрика для создания воинов армии Карфагена
// class CarthaginianArmyFactory : public ArmyFactory {
//    public:
//     Infantryman* createInfantryman() { return new CarthaginianInfantryman; }
//     Archer* createArcher() { return new CarthaginianArcher; }
//     Horseman* createHorseman() { return new CarthaginianHorseman; }
// };

// // Класс, содержащий всех воинов той или иной армии
// class Army {
//    public:
//     ~Army() {
//         int i;
//         for (i = 0; i < vi.size(); ++i) delete vi[i];
//         for (i = 0; i < va.size(); ++i) delete va[i];
//         for (i = 0; i < vh.size(); ++i) delete vh[i];
//     }
//     void info() {
//         int i;
//         for (i = 0; i < vi.size(); ++i) vi[i]->info();
//         for (i = 0; i < va.size(); ++i) va[i]->info();
//         for (i = 0; i < vh.size(); ++i) vh[i]->info();
//     }
//     vector<Infantryman*> vi;
//     vector<Archer*> va;
//     vector<Horseman*> vh;
// };

// // Здесь создается армия той или иной стороны
// class Game {
//    public:
//     Army* createArmy(ArmyFactory& factory) {
//         Army* p = new Army;
//         p->vi.push_back(factory.createInfantryman());
//         p->va.push_back(factory.createArcher());
//         p->vh.push_back(factory.createHorseman());
//         return p;
//     }
// };

// int main() {
//     Game game;
//     RomanArmyFactory ra_factory;
//     CarthaginianArmyFactory ca_factory;

//     Army* ra = game.createArmy(ra_factory);
//     Army* ca = game.createArmy(ca_factory);
//     cout << "Roman army:" << endl;
//     ra->info();
//     cout << "\nCarthaginian army:" << endl;
//     ca->info();
//     // ...
// }

// #include <iostream>
// #include <vector>

// using namespace std;

// // Классы всех возможных родов войск
// class Infantryman {
//    public:
//     void info() { cout << "Infantryman" << endl; }
// };

// class Archer {
//    public:
//     void info() { cout << "Archer" << endl; }
// };

// class Horseman {
//    public:
//     void info() { cout << "Horseman" << endl; }
// };

// class Catapult {
//    public:
//     void info() { cout << "Catapult" << endl; }
// };

// class Elephant {
//    public:
//     void info() { cout << "Elephant" << endl; }
// };

// // Класс "Армия", содержащий все типы боевых единиц
// class Army {
//    public:
//     vector<Infantryman> vi;
//     vector<Archer> va;
//     vector<Horseman> vh;
//     vector<Catapult> vc;
//     vector<Elephant> ve;
//     void info() {
//         int i;
//         for (i = 0; i < vi.size(); ++i) vi[i].info();
//         for (i = 0; i < va.size(); ++i) va[i].info();
//         for (i = 0; i < vh.size(); ++i) vh[i].info();
//         for (i = 0; i < vc.size(); ++i) vc[i].info();
//         for (i = 0; i < ve.size(); ++i) ve[i].info();
//     }
// };

// // Базовый класс ArmyBuilder объявляет интерфейс для поэтапного
// // построения армии и предусматривает его реализацию по умолчанию

// class ArmyBuilder {
//    protected:
//     Army* p;

//    public:
//     ArmyBuilder() : p(0) {}
//     virtual ~ArmyBuilder() {}
//     virtual void createArmy() {}
//     virtual void buildInfantryman() {}
//     virtual void buildArcher() {}
//     virtual void buildHorseman() {}
//     virtual void buildCatapult() {}
//     virtual void buildElephant() {}
//     virtual Army* getArmy() { return p; }
// };

// // Римская армия имеет все типы боевых единиц кроме боевых слонов
// class RomanArmyBuilder : public ArmyBuilder {
//    public:
//     void createArmy() { p = new Army; }
//     void buildInfantryman() { p->vi.push_back(Infantryman()); }
//     void buildArcher() { p->va.push_back(Archer()); }
//     void buildHorseman() { p->vh.push_back(Horseman()); }
//     void buildCatapult() { p->vc.push_back(Catapult()); }
// };

// // Армия Карфагена имеет все типы боевых единиц кроме катапульт
// class CarthaginianArmyBuilder : public ArmyBuilder {
//    public:
//     void createArmy() { p = new Army; }
//     void buildInfantryman() { p->vi.push_back(Infantryman()); }
//     void buildArcher() { p->va.push_back(Archer()); }
//     void buildHorseman() { p->vh.push_back(Horseman()); }
//     void buildElephant() { p->ve.push_back(Elephant()); }
// };

// // Класс-распорядитель, поэтапно создающий армию той или иной стороны.
// // Именно здесь определен алгоритм построения армии.
// class Director {
//    public:
//     Army* createArmy(ArmyBuilder& builder) {
//         builder.createArmy();
//         builder.buildInfantryman();
//         builder.buildArcher();
//         builder.buildHorseman();
//         builder.buildCatapult();
//         builder.buildElephant();
//         return (builder.getArmy());
//     }
// };

// int main() {
//     Director dir;
//     RomanArmyBuilder ra_builder;
//     CarthaginianArmyBuilder ca_builder;

//     Army* ra = dir.createArmy(ra_builder);
//     Army* ca = dir.createArmy(ca_builder);
//     cout << "Roman army:" << endl;
//     ra->info();
//     cout << "\nCarthaginian army:" << endl;
//     ca->info();
//     // ...

//     return 0;
// }

// #include <iostream>
// #include <map>
// #include <vector>

// using namespace std;

// // Идентификаторы всех родов войск
// enum Warrior_ID { Infantryman_ID, Archer_ID, Horseman_ID };

// class Warrior;  // Опережающее объявление
// typedef map<Warrior_ID, Warrior*> Registry;

// // Реестр прототипов определен в виде Singleton Мэйерса
// Registry& getRegistry() {
//     static Registry _instance;
//     return _instance;
// }

// // Единственное назначение этого класса - помощь в выборе нужного
// // конструктора при создании прототипов
// class Dummy {};

// // Полиморфный базовый класс. Здесь также определен статический
// // обобщенный конструктор для создания боевых единиц всех родов войск
// class Warrior {
//    public:
//     virtual Warrior* clone() = 0;
//     virtual void info() = 0;
//     virtual ~Warrior() {}
//     // Параметризированный статический метод для создания воинов
//     // всех родов войск
//     static Warrior* createWarrior(Warrior_ID id) {
//         Registry& r = getRegistry();
//         if (r.find(id) != r.end()) return r[id]->clone();
//         return 0;
//     }

//    protected:
//     // Добавление прототипа в множество прототипов
//     static void addPrototype(Warrior_ID id, Warrior* prototype) {
//         Registry& r = getRegistry();
//         r[id] = prototype;
//     }
//     // Удаление прототипа из множества прототипов
//     static void removePrototype(Warrior_ID id) {
//         Registry& r = getRegistry();
//         r.erase(r.find(id));
//     }
// };

// // В производных классах различных родов войск в виде статических
// // членов-данных определяются соответствующие прототипы
// class Infantryman : public Warrior {
//    public:
//     Warrior* clone() { return new Infantryman(*this); }
//     void info() { cout << "Infantryman" << endl; }

//    private:
//     Infantryman(Dummy) { Warrior::addPrototype(Infantryman_ID, this); }
//     Infantryman() {}
//     static Infantryman prototype;
// };

// class Archer : public Warrior {
//    public:
//     Warrior* clone() { return new Archer(*this); }
//     void info() { cout << "Archer" << endl; }

//    private:
//     Archer(Dummy) { addPrototype(Archer_ID, this); }
//     Archer() {}
//     static Archer prototype;
// };

// class Horseman : public Warrior {
//    public:
//     Warrior* clone() { return new Horseman(*this); }
//     void info() { cout << "Horseman" << endl; }

//    private:
//     Horseman(Dummy) { addPrototype(Horseman_ID, this); }
//     Horseman() {}
//     static Horseman prototype;
// };

// Infantryman Infantryman::prototype = Infantryman(Dummy());
// Archer Archer::prototype = Archer(Dummy());
// Horseman Horseman::prototype = Horseman(Dummy());

// int main() {
//     vector<Warrior*> v;
//     v.push_back(Warrior::createWarrior(Infantryman_ID));
//     v.push_back(Warrior::createWarrior(Archer_ID));
//     v.push_back(Warrior::createWarrior(Horseman_ID));

//     for (int i = 0; i < v.size(); i++) v[i]->info();
//     // ...
// }

// #include <iostream>
// #include <vector>

// using namespace std;

// // Иерархия классов игровых персонажей
// // Полиморфный базовый класс
// class Warrior {
//    public:
//     virtual Warrior* clone() = 0;
//     virtual void info() = 0;
//     virtual ~Warrior() {}
// };

// // Производные классы различных родов войск
// class Infantryman : public Warrior {
//     friend class PrototypeFactory;

//    public:
//     Warrior* clone() { return new Infantryman(*this); }
//     void info() { cout << "Infantryman" << endl; }

//    private:
//     Infantryman() {}
// };

// class Archer : public Warrior {
//     friend class PrototypeFactory;

//    public:
//     Warrior* clone() { return new Archer(*this); }
//     void info() { cout << "Archer" << endl; }

//    private:
//     Archer() {}
// };

// class Horseman : public Warrior {
//     friend class PrototypeFactory;

//    public:
//     Warrior* clone() { return new Horseman(*this); }
//     void info() { cout << "Horseman" << endl; }

//    private:
//     Horseman() {}
// };

// // Фабрика для создания боевых единиц всех родов войск
// class PrototypeFactory {
//    public:
//     Warrior* createInfantryman() {
//         static Infantryman prototype;
//         return prototype.clone();
//     }
//     Warrior* createArcher() {
//         static Archer prototype;
//         return prototype.clone();
//     }
//     Warrior* createHorseman() {
//         static Horseman prototype;
//         return prototype.clone();
//     }
// };

// int main() {
//     PrototypeFactory factory;
//     vector<Warrior*> v;
//     v.push_back(factory.createInfantryman());
//     v.push_back(factory.createArcher());
//     v.push_back(factory.createHorseman());

//     for (int i = 0; i < v.size(); i++) v[i]->info();
//     // ...
// }

// // Singleton.h
// class Singleton {
//    private:
//     static Singleton* p_instance;
//     // Конструкторы и оператор присваивания недоступны клиентам
//     Singleton() {}
//     Singleton(const Singleton&);
//     Singleton& operator=(Singleton&);

//    public:
//     static Singleton* getInstance() {
//         if (!p_instance) p_instance = new Singleton();
//         return p_instance;
//     }
// };

// // Singleton.cpp
// #include "Singleton.h"

// Singleton* Singleton::p_instance = 0;

// // Singleton.h
// class Singleton {
//    private:
//     Singleton() {}
//     Singleton(const Singleton&);
//     Singleton& operator=(Singleton&);

//    public:
//     static Singleton& getInstance() {
//         static Singleton instance;
//         return instance;
//     }
// };

// // Singleton.h
// class Singleton;  // опережающее объявление

// class SingletonDestroyer {
//    private:
//     Singleton* p_instance;

//    public:
//     ~SingletonDestroyer();
//     void initialize(Singleton* p);
// };

// class Singleton {
//    private:
//     static Singleton* p_instance;
//     static SingletonDestroyer destroyer;

//    protected:
//     Singleton() {}
//     Singleton(const Singleton&);
//     Singleton& operator=(Singleton&);
//     ~Singleton() {}
//     friend class SingletonDestroyer;

//    public:
//     static Singleton& getInstance();
// };

// // Singleton.cpp
// #include "Singleton.h"

// Singleton* Singleton::p_instance = 0;
// SingletonDestroyer Singleton::destroyer;

// SingletonDestroyer::~SingletonDestroyer() { delete p_instance; }
// void SingletonDestroyer::initialize(Singleton* p) { p_instance = p; }
// Singleton& Singleton::getInstance() {
//     if (!p_instance) {
//         p_instance = new Singleton();
//         destroyer.initialize(p_instance);
//     }
//     return *p_instance;
// }

// Singleton.h
// class Singleton1 {
//    private:
//     Singleton1() {}
//     Singleton1(const Singleton1&);
//     Singleton1& operator=(Singleton1&);

//    public:
//     static Singleton1& getInstance() {
//         static Singleton1 instance;
//         return instance;
//     }
// };

// class Singleton2 {
//    private:
//     Singleton2(Singleton1& instance) : s1(instance) {}
//     Singleton2(const Singleton2&);
//     Singleton2& operator=(Singleton2&);
//     Singleton1& s1;

//    public:
//     static Singleton2& getInstance() {
//         static Singleton2 instance(Singleton1::getInstance());
//         return instance;
//     }
// };

// // main.cpp
// #include "Singleton.h"

// int main() {
//     Singleton2& s = Singleton2::getInstance();
//     return 0;
// }

// #include <iostream>

// using namespace std;

// // Уже существующий класс температурного датчика окружающей среды
// class FahrenheitSensor {
//    public:
//     // Получить показания температуры в градусах Фаренгейта
//     float getFahrenheitTemp() {
//         float t = 32.0;
//         // ... какой то код
//         return t;
//     }
// };

// class Sensor {
//    public:
//     virtual ~Sensor() {}
//     virtual float getTemperature() = 0;
// };

// class Adapter : public Sensor {
//    public:
//     Adapter(FahrenheitSensor* p) : p_fsensor(p) {}
//     ~Adapter() { delete p_fsensor; }
//     float getTemperature() { return (p_fsensor->getFahrenheitTemp() - 32.0) * 5.0 / 9.0; }

//    private:
//     FahrenheitSensor* p_fsensor;
// };

// int main() {
//     Sensor* p = new Adapter(new FahrenheitSensor);
//     cout << "Celsius temperature = " << p->getTemperature() << endl;
//     delete p;
//     return 0;
// }

// #include <iostream>

// using namespace std;

// class FahrenheitSensor {
//    public:
//     float getFahrenheitTemp() {
//         float t = 32.0;
//         // ...
//         return t;
//     }

//    protected:
//     void adjust() {}  // Настройка датчика (защищенный метод)
// };

// class Sensor {
//    public:
//     virtual ~Sensor() {}
//     virtual float getTemperature() = 0;
//     virtual void adjust() = 0;
// };

// class Adapter : public Sensor, private FahrenheitSensor {
//    public:
//     Adapter() {}
//     float getTemperature() { return (getFahrenheitTemp() - 32.0) * 5.0 / 9.0; }
//     void adjust() { FahrenheitSensor::adjust(); }
// };

// int main() {
//     Sensor* p = new Adapter();
//     p->adjust();
//     cout << "Celsius temperature = " << p->getTemperature() << endl;
//     delete p;
//     return 0;
// }

/**
 * Реализация устанавливает интерфейс для всех классов реализации. Он не должен
 * соответствовать интерфейсу Абстракции. На практике оба интерфейса могут быть
 * совершенно разными. Как правило, интерфейс Реализации предоставляет только
 * примитивные операции, в то время как Абстракция определяет операции более
 * высокого уровня, основанные на этих примитивах.
 */

// #include <iostream>

// using namespace std;

// class Implementation {
//    public:
//     virtual ~Implementation() {}
//     virtual std::string OperationImplementation() const = 0;
// };

// /**
//  * Каждая Конкретная Реализация соответствует определённой платформе и реализует
//  * интерфейс Реализации с использованием API этой платформы.
//  */
// class ConcreteImplementationA : public Implementation {
//    public:
//     std::string OperationImplementation() const override {
//         return "ConcreteImplementationA: Here's the result on the platform A.\n";
//     }
// };
// class ConcreteImplementationB : public Implementation {
//    public:
//     std::string OperationImplementation() const override {
//         return "ConcreteImplementationB: Here's the result on the platform B.\n";
//     }
// };

// /**
//  * Абстракция устанавливает интерфейс для «управляющей» части двух иерархий
//  * классов. Она содержит ссылку на объект из иерархии Реализации и делегирует
//  * ему всю настоящую работу.
//  */

// class Abstraction {
//     /**
//      * @var Implementation
//      */
//    protected:
//     Implementation* implementation_;

//    public:
//     Abstraction(Implementation* implementation) : implementation_(implementation) {}

//     virtual ~Abstraction() {}

//     virtual std::string Operation() const {
//         return "Abstraction: Base operation with:\n" + this->implementation_->OperationImplementation();
//     }
// };
// /**
//  * Можно расширить Абстракцию без изменения классов Реализации.
//  */
// class ExtendedAbstraction : public Abstraction {
//    public:
//     ExtendedAbstraction(Implementation* implementation) : Abstraction(implementation) {}
//     std::string Operation() const override {
//         return "ExtendedAbstraction: Extended operation with:\n" +
//                this->implementation_->OperationImplementation();
//     }
// };

// /**
//  * За исключением этапа инициализации, когда объект Абстракции связывается с
//  * определённым объектом Реализации, клиентский код должен зависеть только от
//  * класса Абстракции. Таким образом, клиентский код может поддерживать любую
//  * комбинацию абстракции и реализации.
//  */
// void ClientCode(const Abstraction& abstraction) {
//     // ...
//     std::cout << abstraction.Operation();
//     // ...
// }
// /**
//  * Клиентский код должен работать с любой предварительно сконфигурированной
//  * комбинацией абстракции и реализации.
//  */

// int main() {
//     Implementation* implementation = new ConcreteImplementationA;
//     Abstraction* abstraction = new Abstraction(implementation);
//     ClientCode(*abstraction);
//     std::cout << std::endl;
//     delete implementation;
//     delete abstraction;

//     implementation = new ConcreteImplementationB;
//     abstraction = new ExtendedAbstraction(implementation);
//     ClientCode(*abstraction);

//     delete implementation;
//     delete abstraction;

//     return 0;
// }

// #include <iostream>
// using namespace std;

// int main() {
//     int array[33];
//     if (&array[4] < &array[23]) {
//         std::cout << "Привет мир" << std::endl;
//     }
//     return 0;
// }

// const int x = 5;

// int main() {
//     int x[x];
//     int y = sizeof(x) / sizeof(int);
//     cout << y;
//     return 0;
// }

// int x = 5;
// int main() {
//     int x = x;
//     return 0;
// }

// int main() {
//     int a = 5, b = 2;
//     std::cout << a++ ++ +b;
// }

// #include <iostream>

// typedef long long ll;

// void foo(unsigned ll) { std::cout << "1"; }

// void foo(unsigned long long) { std::cout << "2"; }

// int main() { foo(2ull); }

// #include <iostream>

// int main() {
//     void* p = &p;
//     std::cout << bool(p);
// }

// #include <assert.h>

// #include <iostream>
// #include <vector>

// using namespace std;

// // Component
// class Unit {
//    public:
//     virtual int getStrength() = 0;
//     virtual void addUnit(Unit* p) { assert(false); }
//     virtual ~Unit() {}
// };

// // Primitives
// class Archer : public Unit {
//    public:
//     virtual int getStrength() { return 1; }
// };

// class Infantryman : public Unit {
//    public:
//     virtual int getStrength() { return 2; }
// };

// class Horseman : public Unit {
//    public:
//     virtual int getStrength() { return 3; }
// };

// // Composite
// class CompositeUnit : public Unit {
//    public:
//     int getStrength() {
//         int total = 0;
//         for (int i = 0; i < c.size(); ++i) total += c[i]->getStrength();
//         return total;
//     }
//     void addUnit(Unit* p) { c.push_back(p); }
//     ~CompositeUnit() {
//         for (int i = 0; i < c.size(); ++i) delete c[i];
//     }

//    private:
//     std::vector<Unit*> c;
// };

// // Вспомогательная функция для создания легиона
// CompositeUnit* createLegion() {
//     // Римский легион содержит:
//     CompositeUnit* legion = new CompositeUnit;
//     // 3000 тяжелых пехотинцев
//     for (int i = 0; i < 3000; ++i) legion->addUnit(new Infantryman);
//     // 1200 легких пехотинцев
//     for (int i = 0; i < 1200; ++i) legion->addUnit(new Archer);
//     // 300 всадников
//     for (int i = 0; i < 300; ++i) legion->addUnit(new Horseman);

//     return legion;
// }

// int main() {
//     // Римская армия состоит из 4-х легионов
//     CompositeUnit* army = new CompositeUnit;
//     for (int i = 0; i < 4; ++i) army->addUnit(createLegion());

//     cout << "Roman army damaging strength is " << army->getStrength() << endl;
//     // …
//     delete army;
//     return 0;
// }

// #include <iostream>
// #include <string>
// #include <vector>

// using namespace std;
// /**
//  * Базовый интерфейс Компонента определяет поведение, которое изменяется
//  * декораторами.
//  */
// class Component {
//    public:
//     virtual ~Component() {}
//     virtual std::string Operation() const = 0;
// };
// /**
//  * Конкретные Компоненты предоставляют реализации поведения по умолчанию. Может
//  * быть несколько вариаций этих классов.
//  */
// class ConcreteComponent : public Component {
//    public:
//     std::string Operation() const override { return "ConcreteComponent"; }
// };
// /**
//  * Базовый класс Декоратора следует тому же интерфейсу, что и другие компоненты.
//  * Основная цель этого класса - определить интерфейс обёртки для всех конкретных
//  * декораторов. Реализация кода обёртки по умолчанию может включать в себя поле
//  * для хранения завёрнутого компонента и средства его инициализации.
//  */
// class Decorator : public Component {
//     /**
//      * @var Component
//      */
//    protected:
//     Component* component_;

//    public:
//     Decorator(Component* component) : component_(component) {}
//     /**
//      * Декоратор делегирует всю работу обёрнутому компоненту.
//      */
//     std::string Operation() const override { return this->component_->Operation(); }
// };
// /**
//  * Конкретные Декораторы вызывают обёрнутый объект и изменяют его результат
//  * некоторым образом.
//  */
// class ConcreteDecoratorA : public Decorator {
//     /**
//      * Декораторы могут вызывать родительскую реализацию операции, вместо того,
//      * чтобы вызвать обёрнутый объект напрямую. Такой подход упрощает расширение
//      * классов декораторов.
//      */
//    public:
//     ConcreteDecoratorA(Component* component) : Decorator(component) {}
//     std::string Operation() const override { return "ConcreteDecoratorA(" + Decorator::Operation() + ")"; }
// };
// /**
//  * Декораторы могут выполнять своё поведение до или после вызова обёрнутого
//  * объекта.
//  */
// class ConcreteDecoratorB : public Decorator {
//    public:
//     ConcreteDecoratorB(Component* component) : Decorator(component) {}

//     std::string Operation() const override { return "ConcreteDecoratorB(" + Decorator::Operation() + ")"; }
// };
// /**
//  * Клиентский код работает со всеми объектами, используя интерфейс Компонента.
//  * Таким образом, он остаётся независимым от конкретных классов компонентов, с
//  * которыми работает.
//  */
// void ClientCode(Component* component) {
//     // ...
//     std::cout << "RESULT: " << component->Operation();
//     // ...
// }

// int main() {
//     /**
//      * Таким образом, клиентский код может поддерживать как простые компоненты...
//      */
//     Component* simple = new ConcreteComponent;
//     std::cout << "Client: I've got a simple component:\n";
//     ClientCode(simple);
//     std::cout << "\n\n";
//     /**
//      * ...так и декорированные.
//      *
//      * Обратите внимание, что декораторы могут обёртывать не только простые
//      * компоненты, но и другие декораторы.
//      */
//     Component* decorator1 = new ConcreteDecoratorA(simple);
//     Component* decorator2 = new ConcreteDecoratorB(decorator1);
//     std::cout << "Client: Now I've got a decorated component:\n";
//     ClientCode(decorator2);
//     std::cout << "\n";

//     delete simple;
//     delete decorator1;
//     delete decorator2;

//     return 0;
// }

// #include <iostream>
// #include <string>
// #include <vector>

// using namespace std;

// /**
//  * Подсистема может принимать запросы либо от фасада, либо от клиента напрямую.
//  * В любом случае, для Подсистемы Фасад – это еще один клиент, и он не является
//  * частью Подсистемы.
//  */
// class Subsystem1 {
//    public:
//     std::string Operation1() const { return "Subsystem1: Ready!\n"; }
//     // ...
//     std::string OperationN() const { return "Subsystem1: Go!\n"; }
// };
// /**
//  * Некоторые фасады могут работать с разными подсистемами одновременно.
//  */
// class Subsystem2 {
//    public:
//     std::string Operation1() const { return "Subsystem2: Get ready!\n"; }
//     // ...
//     std::string OperationZ() const { return "Subsystem2: Fire!\n"; }
// };

// /**
//  * Класс Фасада предоставляет простой интерфейс для сложной логики одной или
//  * нескольких подсистем. Фасад делегирует запросы клиентов соответствующим
//  * объектам внутри подсистемы. Фасад также отвечает за управление их жизненным
//  * циклом. Все это защищает клиента от нежелательной сложности подсистемы.
//  */
// class Facade {
//    protected:
//     Subsystem1 *subsystem1_;
//     Subsystem2 *subsystem2_;
//     /**
//      * В зависимости от потребностей вашего приложения вы можете предоставить
//      * Фасаду существующие объекты подсистемы или заставить Фасад создать их
//      * самостоятельно.
//      */
//    public:
//     /**
//      * In this case we will delegate the memory ownership to Facade Class
//      */
//     Facade(Subsystem1 *subsystem1 = nullptr, Subsystem2 *subsystem2 = nullptr) {
//         this->subsystem1_ = subsystem1 ?: new Subsystem1;
//         this->subsystem2_ = subsystem2 ?: new Subsystem2;
//     }
//     ~Facade() {
//         delete subsystem1_;
//         delete subsystem2_;
//     }
//     /**
//      * Методы Фасада удобны для быстрого доступа к сложной функциональности
//      * подсистем. Однако клиенты получают только часть возможностей подсистемы.
//      */
//     std::string Operation() {
//         std::string result = "Facade initializes subsystems:\n";
//         result += this->subsystem1_->Operation1();
//         result += this->subsystem2_->Operation1();
//         result += "Facade orders subsystems to perform the action:\n";
//         result += this->subsystem1_->OperationN();
//         result += this->subsystem2_->OperationZ();
//         return result;
//     }
// };

// /**
//  * Клиентский код работает со сложными подсистемами через простой интерфейс,
//  * предоставляемый Фасадом. Когда фасад управляет жизненным циклом подсистемы,
//  * клиент может даже не знать о существовании подсистемы. Такой подход позволяет
//  * держать сложность под контролем.
//  */
// void ClientCode(Facade *facade) {
//     // ...
//     std::cout << facade->Operation();
//     // ...
// }
// /**
//  * В клиентском коде могут быть уже созданы некоторые объекты подсистемы. В этом
//  * случае может оказаться целесообразным инициализировать Фасад с этими
//  * объектами вместо того, чтобы позволить Фасаду создавать новые экземпляры.
//  */

// int main() {
//     Subsystem1 *subsystem1 = new Subsystem1;
//     Subsystem2 *subsystem2 = new Subsystem2;
//     Facade *facade = new Facade(subsystem1, subsystem2);
//     ClientCode(facade);

//     delete facade;

//     return 0;
// }

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

// /**
//  * Паттерн Легковес
//  *
//  * Назначение: Позволяет вместить бóльшее количество объектов в отведённую
//  * оперативную память. Легковес экономит память, разделяя общее состояние
//  * объектов между собой, вместо хранения одинаковых данных в каждом объекте.
//  */

// struct SharedState {
//     std::string brand_;
//     std::string model_;
//     std::string color_;

//     SharedState(const std::string &brand, const std::string &model, const std::string &color)
//         : brand_(brand), model_(model), color_(color) {}

//     friend std::ostream &operator<<(std::ostream &os, const SharedState &ss) {
//         return os << "[ " << ss.brand_ << " , " << ss.model_ << " , " << ss.color_ << " ]";
//     }
// };

// struct UniqueState {
//     std::string owner_;
//     std::string plates_;

//     UniqueState(const std::string &owner, const std::string &plates) : owner_(owner), plates_(plates) {}

//     friend std::ostream &operator<<(std::ostream &os, const UniqueState &us) {
//         return os << "[ " << us.owner_ << " , " << us.plates_ << " ]";
//     }
// };

// /**
//  * Легковес хранит общую часть состояния (также называемую внутренним
//  * состоянием), которая принадлежит нескольким реальным бизнес-объектам.
//  * Легковес принимает оставшуюся часть состояния (внешнее состояние, уникальное
//  * для каждого объекта)  через его параметры метода.
//  */
// class Flyweight {
//    private:
//     SharedState *shared_state_;

//    public:
//     Flyweight(const SharedState *shared_state) : shared_state_(new SharedState(*shared_state)) {}
//     Flyweight(const Flyweight &other) : shared_state_(new SharedState(*other.shared_state_)) {}
//     ~Flyweight() { delete shared_state_; }
//     SharedState *shared_state() const { return shared_state_; }
//     void Operation(const UniqueState &unique_state) const {
//         std::cout << "Flyweight: Displaying shared (" << *shared_state_ << ") and unique (" << unique_state
//                   << ") state.\n";
//     }
// };
// /**
//  * Фабрика Легковесов создает объекты-Легковесы и управляет ими. Она
//  * обеспечивает правильное разделение легковесов. Когда клиент запрашивает
//  * легковес, фабрика либо возвращает существующий экземпляр, либо создает новый,
//  * если он ещё не существует.
//  */
// class FlyweightFactory {
//     /**
//      * @var Flyweight[]
//      */
//    private:
//     std::unordered_map<std::string, Flyweight> flyweights_;
//     /**
//      * Возвращает хеш строки Легковеса для данного состояния.
//      */
//     std::string GetKey(const SharedState &ss) const { return ss.brand_ + "_" + ss.model_ + "_" + ss.color_;
//     }

//    public:
//     FlyweightFactory(std::initializer_list<SharedState> share_states) {
//         for (const SharedState &ss : share_states) {
//             this->flyweights_.insert(
//                 std::make_pair<std::string, Flyweight>(this->GetKey(ss), Flyweight(&ss)));
//         }
//     }

//     /**
//      * Возвращает существующий Легковес с заданным состоянием или создает новый.
//      */
//     Flyweight GetFlyweight(const SharedState &shared_state) {
//         std::string key = this->GetKey(shared_state);
//         if (this->flyweights_.find(key) == this->flyweights_.end()) {
//             std::cout << "FlyweightFactory: Can't find a flyweight, creating new one.\n";
//             this->flyweights_.insert(std::make_pair(key, Flyweight(&shared_state)));
//         } else {
//             std::cout << "FlyweightFactory: Reusing existing flyweight.\n";
//         }
//         return this->flyweights_.at(key);
//     }
//     void ListFlyweights() const {
//         size_t count = this->flyweights_.size();
//         std::cout << "\nFlyweightFactory: I have " << count << " flyweights:\n";
//         for (std::pair<std::string, Flyweight> pair : this->flyweights_) {
//             std::cout << pair.first << "\n";
//         }
//     }
// };

// // ...
// void AddCarToPoliceDatabase(FlyweightFactory &ff, const std::string &plates, const std::string &owner,
//                             const std::string &brand, const std::string &model, const std::string &color) {
//     std::cout << "\nClient: Adding a car to database.\n";
//     const Flyweight &flyweight = ff.GetFlyweight({brand, model, color});
//     // Клиентский код либо сохраняет, либо вычисляет внешнее состояние и
//     // передает его методам легковеса.
//     flyweight.Operation({owner, plates});
// }

// /**
//  * Клиентский код обычно создает кучу предварительно заполненных легковесов на
//  * этапе инициализации приложения.
//  */

// int main() {
//     FlyweightFactory *factory = new FlyweightFactory({{"Chevrolet", "Camaro2018", "pink"},
//                                                       {"Mercedes Benz", "C300", "black"},
//                                                       {"Mercedes Benz", "C500", "red"},
//                                                       {"BMW", "M5", "red"},
//                                                       {"BMW", "X6", "white"}});
//     factory->ListFlyweights();

//     AddCarToPoliceDatabase(*factory, "CL234IR", "James Doe", "BMW", "M5", "red");

//     AddCarToPoliceDatabase(*factory, "CL234IR", "James Doe", "BMW", "X1", "red");
//     factory->ListFlyweights();
//     delete factory;

//     return 0;
// }

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

/**
 * Интерфейс Субъекта объявляет общие операции как для Реального Субъекта, так и
 * для Заместителя. Пока клиент работает с Реальным Субъектом, используя этот
 * интерфейс, вы сможете передать ему заместителя вместо реального субъекта.
 */
class Subject {
   public:
    virtual void Request() const = 0;
};
/**
 * Реальный Субъект содержит некоторую базовую бизнес-логику. Как правило,
 * Реальные Субъекты способны выполнять некоторую полезную работу, которая к
 * тому же может быть очень медленной или точной – например, коррекция входных
 * данных. Заместитель может решить эти задачи без каких-либо изменений в коде
 * Реального Субъекта.
 */
class RealSubject : public Subject {
   public:
    void Request() const override { std::cout << "RealSubject: Handling request.\n"; }
};
/**
 * Интерфейс Заместителя идентичен интерфейсу Реального Субъекта.
 */
class Proxy : public Subject {
    /**
     * @var RealSubject
     */
   private:
    RealSubject *real_subject_;

    bool CheckAccess() const {
        // Некоторые реальные проверки должны проходить здесь.
        std::cout << "Proxy: Checking access prior to firing a real request.\n";
        return true;
    }
    void LogAccess() const { std::cout << "Proxy: Logging the time of request.\n"; }

    /**
     * Заместитель хранит ссылку на объект класса РеальныйСубъект. Клиент может
     * либо лениво загрузить его, либо передать Заместителю.
     */
   public:
    Proxy(RealSubject *real_subject) : real_subject_(new RealSubject(*real_subject)) {}

    ~Proxy() { delete real_subject_; }
    /**
     * Наиболее распространёнными областями применения паттерна Заместитель
     * являются ленивая загрузка, кэширование, контроль доступа, ведение журнала и
     * т.д. Заместитель может выполнить одну из этих задач, а затем, в зависимости
     * от результата, передать выполнение одноимённому методу в связанном объекте
     * класса Реального Субъект.
     */
    void Request() const override {
        if (this->CheckAccess()) {
            this->real_subject_->Request();
            this->LogAccess();
        }
    }
};
/**
 * Клиентский код должен работать со всеми объектами (как с реальными, так и
 * заместителями) через интерфейс Субъекта, чтобы поддерживать как реальные
 * субъекты, так и заместителей. В реальной жизни, однако, клиенты в основном
 * работают с реальными субъектами напрямую. В этом случае, для более простой
 * реализации паттерна, можно расширить заместителя из класса реального
 * субъекта.
 */
void ClientCode(const Subject &subject) {
    // ...
    subject.Request();
    // ...
}

int main() {
    std::cout << "Client: Executing the client code with a real subject:\n";
    RealSubject *real_subject = new RealSubject;
    ClientCode(*real_subject);
    std::cout << "\n";
    std::cout << "Client: Executing the same client code with a proxy:\n";
    Proxy *proxy = new Proxy(real_subject);
    ClientCode(*proxy);

    delete real_subject;
    delete proxy;
    return 0;
}