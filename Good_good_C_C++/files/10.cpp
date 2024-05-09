#include <iostream>

struct vector3D {
    double x, y, z;

    double get_x() { return this->x; }
    double get_y() { return y; }
    static double norm2(double a, double b) { return a * a + b * b; }
};

int main(void) {
    vector3D v1{0.5, 2.0, -5.4};

    std::cout << v1.get_x() << std::endl;
    std::cout << v1.norm2(1, 2) << std::endl;

    return 0;
}