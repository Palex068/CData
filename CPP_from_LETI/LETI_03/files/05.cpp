// #include <iostream>

// class A {
//    public:
//     A() { std::cout << 'a'; }
//     ~A() { std::cout << 'A'; }
// };

// class B : public A {
//    public:
//     B() { std::cout << 'b'; }
//     ~B() { std::cout << 'B'; }
// };

// int main() { B b; }

// class A {
//    public:
//     virtual void f() { std::cout << 1; }
// };

// class B : public A {
//    public:
//     void f() { std::cout << 2; }
// };

// void g(A a) { a.f(); }

// int main() {
//     B b;
//     g(b);
// }

// #include <iostream>

// class X {
//    public:
//     int var1 : 3;
//     int var2;
// };

// int main() {
//     X x;
//     std::cout << (&x.var1 < &x.var2);
// }

// #include <iostream>

// class A {
//    public:
//     A() { std::cout << "a"; }
//     ~A() { std::cout << "A"; }
// };

// class B {
//    public:
//     B() { std::cout << "b"; }
//     ~B() { std::cout << "B"; }
// };

// class C {
//    public:
//     C() { std::cout << "c"; }
//     ~C() { std::cout << "C"; }
// };

// A a;

// void foo() { static C c; }
// int main() {
//     B b;
//     foo();
// }

#include <iostream>

class X {
   public:
    X() { std::cout << "a"; }
    X(const X &x) { std::cout << "b"; }
    const X &operator=(const X &x) {
        std::cout << "c";
        return *this;
    }
};

int main() {
    X x;
    X y(x);
    X z = y;
    z = x;
}