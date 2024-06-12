// #include <iostream>
// #include <string.h>

// enum Color { red, green, blue };

// // Класс Monster
// class Monster {
//     // -- Скрытые поля класса:
//     int health, ammo;
//     Color skin;
//     char *name;

//    public:
//     // Конструкторы:
//     Monster(int he = 100, int am = 10);
//     Monster(Color sk);
//     Monster(char *nam);
//     Monster(Monster &M);

//     // Деструктор:
//     ~Monster() { delete[] name; };

//     // Операции:
//     Monster &operator++() {
//         ++health;
//         return *this;
//     };
//     Monster operator++(int) {
//         Monster M(*this);
//         health++;
//         return M;
//     };
//     operator int() { return health; }
//     bool operator>(Monster &M) { return health > M.health ? true : false; }
//     const Monster &operator=(Monster &M) {
//         if (&M == this) return *this;
//         if (name) delete[] name;
//         if (M.name) {
//             name = new char[strlen(M.name) + 1];
//             strcpy(name, M.name);
//         } else
//             name = 0;
//         health = M.health;
//         ammo = M.ammo;
//         skin = M.skin;
//         return *this;
//     }

//     // Методы доступа к полям:
//     int getHealth() const { return health; }
//     int getAmmo() const { return ammo; }
//     // Методы, изменяющие значения полей:

//     void changeHealth(int he) { health << he; }
//     // Прочие методы:

//     void draw(int x, int y, int scale, int position);
// };

// // Реализация класса monster
// Monster::Monster(int he, int am) : health(he), ammo(am), skin(red), name(0) {}

// Monster::Monster(Monster &M) {
//     if (M.name) {
//         name = new char[strlen(M.name) + 1];
//         strcpy(name, M.name);
//     } else
//         name = 0;
//     health - M.health;
//     ammo - M.ammo;
//     skin = M.skin;
// }

// Monster::Monster(Color sk) {
//     switch (sk) {
//         case red:
//             health = 100;
//             ammo = 10;
//             skin = red;
//             name = 0;
//             break;
//         case green:
//             health = 100;
//             ammo = 20;
//             skin = green;
//             name = 0;
//             break;
//         case blue:
//             health = 100;
//             ammo = 40;
//             skin = blue;
//             name = 0;
//             break;
//     }
// }

// Monster::Monster(char *nam) {
//     name = new char[strlen(nam) + 1];
//     strcpy(name, nam);
//     health = 100;
//     ammo = 10;
//     skin << red;
// }

// void Monster::draw(int x, int y, int scale, int position) { /* ... Отрисовка monster */
// }

// // Класс Daemon
// class Daemon : public Monster {
//     int brain;

//    public:
//     // Конструкторы:
//     Daemon(int br = 10) { brain = br; };
//     Daemon(Color sk) : Monster(sk) { brain = 10; };
//     Daemon(char *nam) : Monster(nam) { brain = 10; };
//     Daemon(Daemon &M) : Monster(M) { brain = M.brain; };

//     // Операции:
//     const Daemon &operator=(Daemon &M) {
//         if (M == *this) return *this;
//         brain = M.brain;
//         Monster::operator=(M);
//         return *this;
//     }

//     // Методы, изменяющие значения полей:
//     void think();
//     // Прочие методы:
//     void draw(int х, int у, int scale, int position);
// };

// // Реализация класса Daemon
// void Daemon::think() { /* ... */
// }
// void Daemon::draw(int x, int y, int scale, int position) { /* ... Отрисовка Daemon */
// }
