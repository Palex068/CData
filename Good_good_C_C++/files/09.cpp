// Первая программа на языке С++
// #include <iostream>

// int main() {
//     std::cout << "Hello World!" << std::endl;

//     return 0;
// }

// #include <iostream>

// int main() {
//     std::cout << "I love C++" << std::endl;

//     return 0;
// }

// #include <iostream>

// int main() {
//     int a, b;
//     std::cin >> a >> b;
//     std::cout << a << "; " << b << std::endl;

//     return 0;
// }

// #include <iostream>

// int main() {
//     int a, b;
//     std::cin >> a >> b;
//     for (int i = a; i <= b; i++) {
//         if (i % 3 == 0) std::cout << i << " ";
//     }
//     std::cout << std::endl;

//     return 0;
// }

// #include <iostream>

// using namespace std;

// enum { max_size_ar = 20 };

// int main() {
//     int data[max_size_ar];
//     size_t count = 0;
//     char ch;
//     while (count < max_size_ar && cin.good()) {
//         cin >> data[count] >> ch;
//         count++;
//     }

//     cout << count << '\n';

//     for (size_t i = 0; i < count; i++) {
//         cout << data[i] << ' ';
//     }

//     cout << std::endl;

//     return 0;
// }
// #include <iostream>

// enum { max_size_name = 50 };
// using namespace std;

// typedef struct {
//     unsigned id;
//     char name[max_size_name];
//     double weight;
//     unsigned price;
// } THING;

// int main() {
//     THING box;

//     cin >> box.id >> box.name >> box.weight >> box.price;

//     cout << box.name << ' ' << box.id << ": " << box.weight << ", " << box.price << endl;

//     return 0;
// }

#include <cmath>
#include <iostream>

using namespace std;

double triangle_sq(int a, int b, int c) {
    double p = (a + b + c) / 2.0, res;
    res = powf(p * (p - a) * (p - b) * (p - c), 0.5);
    return res;
}

int main() {
    int a, b, c;

    cin >> a >> b >> c;

    double res = triangle_sq(a, b, c);

    printf("%.2lf", res);

    return 0;
}
