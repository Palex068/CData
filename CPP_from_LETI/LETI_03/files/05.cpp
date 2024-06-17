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