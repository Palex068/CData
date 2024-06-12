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

#include <iostream>
#include <vector>

using namespace std;

// Абстрактные базовые классы всех возможных видов воинов
class Infantryman {
   public:
    virtual void info() = 0;
    virtual ~Infantryman() {}
};

class Archer {
   public:
    virtual void info() = 0;
    virtual ~Archer() {}
};

class Horseman {
   public:
    virtual void info() = 0;
    virtual ~Horseman() {}
};

// Классы всех видов воинов Римской армии
class RomanInfantryman : public Infantryman {
   public:
    void info() { cout << "RomanInfantryman" << endl; }
};

class RomanArcher : public Archer {
   public:
    void info() { cout << "RomanArcher" << endl; }
};

class RomanHorseman : public Horseman {
   public:
    void info() { cout << "RomanHorseman" << endl; }
};

// Классы всех видов воинов армии Карфагена
class CarthaginianInfantryman : public Infantryman {
   public:
    void info() { cout << "CarthaginianInfantryman" << endl; }
};

class CarthaginianArcher : public Archer {
   public:
    void info() { cout << "CarthaginianArcher" << endl; }
};

class CarthaginianHorseman : public Horseman {
   public:
    void info() { cout << "CarthaginianHorseman" << endl; }
};

// Абстрактная фабрика для производства воинов
class ArmyFactory {
   public:
    virtual Infantryman* createInfantryman() = 0;
    virtual Archer* createArcher() = 0;
    virtual Horseman* createHorseman() = 0;
    virtual ~ArmyFactory() {}
};

// Фабрика для создания воинов Римской армии
class RomanArmyFactory : public ArmyFactory {
   public:
    Infantryman* createInfantryman() { return new RomanInfantryman; }
    Archer* createArcher() { return new RomanArcher; }
    Horseman* createHorseman() { return new RomanHorseman; }
};

// Фабрика для создания воинов армии Карфагена
class CarthaginianArmyFactory : public ArmyFactory {
   public:
    Infantryman* createInfantryman() { return new CarthaginianInfantryman; }
    Archer* createArcher() { return new CarthaginianArcher; }
    Horseman* createHorseman() { return new CarthaginianHorseman; }
};

// Класс, содержащий всех воинов той или иной армии
class Army {
   public:
    ~Army() {
        int i;
        for (i = 0; i < vi.size(); ++i) delete vi[i];
        for (i = 0; i < va.size(); ++i) delete va[i];
        for (i = 0; i < vh.size(); ++i) delete vh[i];
    }
    void info() {
        int i;
        for (i = 0; i < vi.size(); ++i) vi[i]->info();
        for (i = 0; i < va.size(); ++i) va[i]->info();
        for (i = 0; i < vh.size(); ++i) vh[i]->info();
    }
    vector<Infantryman*> vi;
    vector<Archer*> va;
    vector<Horseman*> vh;
};

// Здесь создается армия той или иной стороны
class Game {
   public:
    Army* createArmy(ArmyFactory& factory) {
        Army* p = new Army;
        p->vi.push_back(factory.createInfantryman());
        p->va.push_back(factory.createArcher());
        p->vh.push_back(factory.createHorseman());
        return p;
    }
};

int main() {
    Game game;
    RomanArmyFactory ra_factory;
    CarthaginianArmyFactory ca_factory;

    Army* ra = game.createArmy(ra_factory);
    Army* ca = game.createArmy(ca_factory);
    cout << "Roman army:" << endl;
    ra->info();
    cout << "\nCarthaginian army:" << endl;
    ca->info();
    // ...
}