// #include <iomanip>
// #include <iostream>

// int main() {
//   int a = 123;
//   std::cout << std::setfill('.') << std::setw(10) << a << std::endl;
//   return 0;
// }

// #include <iostream>

// int main() {
//   int a = 3;
//   int b = 4;
//   unsigned c;
//   c = a - b;
//   std::cout << c;
// }

// #include <iostream>

// int main() {
//     int a, b;
//     std::cin >> a >> b;

//     printf("%d %d %d %d", a + b, a - b, a * b, a / b);
//     return 0;
// }
// #include <iostream>

// int main() {
//     int a;
//     std::cin >> a;

//     int result = (a / 10) % 10;

//     std::cout << result << std::endl;

//     return 0;
// }
// #include <iostream>

// int main() {
//     int a;
//     std::cin >> a;

//     int result = a % 10;

//     std::cout << result << std::endl;

//     return 0;
// }
// #include <iostream>

// int main() {
//     int a;
//     std::cin >> a;

//     int result = a % 10 + a / 10;

//     std::cout << result << std::endl;

//     return 0;
// }
#include <iostream>

int main() {
    int a;
    std::cin >> a;
    int result = 0;
    while (a > 0) {
        result = result * 10 + a % 10;
        a /= 10;
    }
    printf("%04d", result);
    return 0;
}