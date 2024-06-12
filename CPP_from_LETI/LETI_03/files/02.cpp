// class monster {
//     int health{0};
//     int ammo{0};

//    public:
//     monster(int he = 100, int am = 10) {
//         health = he;
//         ammo = am;
//     }
//     void draw(int x, int y, int scale, int position);
//     int getHealth() { return health; }
//     int getAmmo() { return ammo; }
// };
//
// #include <iostream>
// #include <string>
// using std::cout;
// using std::string;

// class Hero {
//    public:
//     string name;
//     int armor;
//     void move() { cout << name << " is moving" << '\n'; }
// };
// int main() {
//     Hero hero;
//     hero.name = "Tom";
//     hero.armor = 100;
//     cout << "Name: " << hero.name << "\tArmor: " << hero.armor << '\n';
//     hero.move();

//     return 0;
// }

// enum color { red, green, blue };  // Возможные значения цвета
// class Monster {
//     int health, ammo;
//     color skin;
//     char* name;

//    public:
//     Monster(int he = 100. int am = 10);
//     Monster(color sk);
//     Monster(char* nam);
//     int get_health() { return health; }
//     int get_ammo() { return ammo; }
//     ...
// };
// //--------
// Monster::Monster(int he, int am) {
//     health = he;
//     ammo = am;
//     skin = red;
//     name = 0;
// }
// //--------
// Monster::Monster(color sk) {
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
// //--------
// Monster::Monster(char* nam) {
//     name = new char[strlen(nam) + 1];
//     // К длине строки добавляется 1 для хранения нуль-символа
//     strcpy(name, nam) : health = 100;
//     ammo = 10;
//     sk1n = red;
// }
// //--------
// Monster* m = new monster("Ork") : Monster Green(green) :

// #include <iostream>

// class show_id {
//    public:
//     ~show_id() { std::cout << id; }
//     int id;
// };

// int main() { delete[] new show_id[3]{{0}, {1}, {2}}; }

// #include <iostream>
// using namespace std;

// class C {
//    public:
//     explicit C(int) { std::cout << "i"; };
//     C(double) { std::cout << "d"; };
// };

// int main() {
//     C c1(7);
//     C c2 = 7;
// }

// #include <iostream>

// class Obj {
//     ...
// };
// class pObj {
//    private:
//     Obj *p:
// };

// class pObj {
//    public:
//     static void *operator new(size_t size);

//    private:
//     union {
//         Obj *p;      // Указатель на объект
//         pObj *next;  // Указатель на следующую свободную ячейку
//     };
//     static const int BLOCK_SIZE;  // Размер блока
//     // Заголовок списка свободных ячеек:
//     static pObj *headOfFree;
// };

// void *pObj::operator new(size_t size) {
//     // Перенаправить запросы неверного количества памяти
//     // стандартной операции new:
//     if (size != sizeof(pObj)) return ::operator new(size);
//     pObj *p = headOfFree;  // Указатель на первую свободную ячейку
//     // Переместить указатель списка свободных ячеек:
//     if (p) headOfFree = p->next;
//     // Если свободной памяти нет, выделяем очередной блок:
//     else {
//         pObj *newblock = static_cast<pObj *>(::operator new(BLOCK_SIZE * sizeof(pObj)));
//         // Bee ячейки свободны, кроме первой (она будет
//         // занята), связываем их:
//         for (int i = 1; i < BLOCK_SIZE - 1; ++i) {
//             newblock[i].next = &newblock[i + 1];
//         }
//         newblock[BLOCK_SIZE - 1].next = 0;
//         // Устанавливаем начало списка свободных ячеек:
//         headOfFree = &newblock[1];
//         p = newblock;
//     }
//     return p;  // Возвращаем указатель на выделенную память

// }

// void pObj::operator delete(void *ObjToDie, size_t size) {
//     if (ObjToDie == 0) return;
//     if (size != sizeof(pObj)) {
//         ::operator delete(ObjToDie);
//         return;
//     }
//     pObj *p = static_cast<p0bj *>(0bjToDie);
//     p->next = headOfFree;
//     headOfFree = p;
// }

// #include <iostream>
// #include <stdlib.h>

// class Vect {
//    public:
//     explicit Vect(int n = 10);
//     Vect(const int a[], int n);  // инициализация массивом
//     ~Vect() { delete[] p; }
//     int& operator[](int i);
//     void Print();

//    private:
//     int* p;
//     int size;
// };

// Vect::Vect(int n) : size(n) { p = new int[size]; }

// Vect::Vect(const int a[], int n) : size(n) {
//     p = new int[size];
//     for (int i = 0; i < size; i++) p[i] = a[i];
// }

// // Перегрузка операции индексирования:
// int& Vect::operator[](int i) {
//     if (i < 0 || i >= size) {
//         std::cout << "Неверный индекс (i = " << i << ") " << endl;
//         std::cout << "Завершение программы" << endl;
//         exit(O);
//     }
//     return p[i];
// }
// void Vect::Print() {
//     for (int i = 0; i < size; i++) std::cout << p[i] << " ";
//     std::cout << endl;
// }

// int ma1n() {
//     int агг[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//     Vect а(аrr, 10);
//     a.Print();
//     std::cout << a[5] << endl;
//     std::cout << a[12] << endl;
//     return 0;
// }

// #include <cmath>
// #include <iostream>
// #include <string>

// class Complex {
//    public:
//     double re;
//     double im;
//     char oper;

//     Complex() : re(0.0), im(0.0) {
//         if (im < 0) {
//             this->oper = '-';
//         } else {
//             this->oper = '+';
//         }
//     }
//     Complex(double real) : re(real), im(0.0) {
//         if (im < 0) {
//             this->oper = '-';
//         } else {
//             this->oper = '+';
//         }
//     }
//     Complex(double real, double imag) : re(real), im(imag) {
//         if (im < 0) {
//             this->oper = '-';
//         } else {
//             this->oper = '+';
//         }
//     }

//     void get_data(double& re, double& im) {
//         if (im < 0) {
//             this->oper = '-';
//         } else {
//             this->oper = '+';
//         }
//         re = this->re;
//         im = this->im;
//     }

//     void set_data() {
//         char i;
//         std::cin >> re >> oper >> im >> i;
//         if (oper == '-') {
//             im = -im;
//         }
//     }

//     void out_data(std::string operation = "") {
//         std::cout << operation;
//         if (re == 0 && im == 0) {
//             std::cout << '0' << std::endl;
//             return;
//         }
//         if (re != 0) {
//             if (re - (int)re == 0) {
//                 std::cout << (int)re << " ";
//             } else {
//                 std::cout << re << " ";
//             }
//         }
//         if (im != 0) {
//             if (im < 0) {
//                 oper = '-';
//             } else {
//                 oper = '+';
//             }
//             std::cout << oper << " ";

//             if (oper == '-') {
//                 if (im - (int)im == 0) {
//                     std::cout << -(int)im;
//                 } else {
//                     std::cout << -im;
//                 }
//             } else {
//                 if (im - (int)im == 0) {
//                     std::cout << (int)im;
//                 } else {
//                     std::cout << im;
//                 }
//             }
//             std::cout << 'i';
//         }
//         std::cout << std::endl;
//     }

//     const Complex& add(const Complex& other) {
//         this->re += other.re;
//         this->im += other.im;
//         if (im < 0) {
//             this->oper = '-';
//         } else {
//             this->oper = '+';
//         }
//         return *this;
//     }

//     const Complex& sub(const Complex& other) {
//         this->re -= other.re;
//         this->im -= other.im;
//         if (im < 0) {
//             this->oper = '-';
//         } else {
//             this->oper = '+';
//         }
//         return *this;
//     }

//     const Complex& prod(const Complex& other) {
//         double temp_re = this->re * other.re - this->im * other.im;
//         double temp_im = this->re * other.im + this->im * other.re;

//         this->re = round(temp_re * 100) / 100.0;
//         this->im = round(temp_im * 100) / 100.0;

//         if (im < 0) {
//             this->oper = '-';
//         } else {
//             this->oper = '+';
//         }
//         return *this;
//     }

//     const Complex& quot(const Complex& other) {
//         double divisor = other.re * other.re + other.im * other.im;
//         double temp_re = (this->re * other.re + this->im * other.im) / divisor;
//         double temp_im = (this->im * other.re - this->re * other.im) / divisor;

//         this->re = round(temp_re * 100) / 100.0;
//         this->im = round(temp_im * 100) / 100.0;

//         if (im < 0) {
//             this->oper = '-';
//         } else {
//             this->oper = '+';
//         }
//         return *this;
//     }
// };

// Complex addition(const Complex& first, const Complex& second) {
//     Complex result = first;
//     result.add(second);
//     if (result.im < 0) {
//         result.oper = '-';
//     } else {
//         result.oper = '+';
//     }
//     return result;
// }

// Complex subtraction(const Complex& first, const Complex& second) {
//     Complex result = first;
//     result.sub(second);
//     if (result.im < 0) {
//         result.oper = '-';
//     } else {
//         result.oper = '+';
//     }
//     return result;
// }

// Complex product(const Complex& first, const Complex& second) {
//     Complex result = first;
//     result.prod(second);
//     if (result.im < 0) {
//         result.oper = '-';
//     } else {
//         result.oper = '+';
//     }
//     return result;
// }

// Complex quotient(const Complex& first, const Complex& second) {
//     Complex result = first;
//     result.quot(second);
//     if (result.im < 0) {
//         result.oper = '-';
//     } else {
//         result.oper = '+';
//     }
//     return result;
// }

// int main() {
//     Complex a, b;
//     a.set_data();
//     b.set_data();

//     Complex c = addition(a, b);
//     Complex d = subtraction(a, b);
//     Complex e = product(a, b);
//     Complex f = quotient(a, b);

//     c.out_data("addition: ");
//     d.out_data("subtraction: ");
//     e.out_data("product: ");
//     f.out_data("quotient: ");

//     return 0;
// }