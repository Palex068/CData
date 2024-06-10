// #include <iostream>

// int main() {
//     float a, b;
//     std::cin >> a >> b;

//     std::cout << a + b << std::endl;
//     std::cout << a - b << std::endl;
//     std::cout << a * b << std::endl;
//     std::cout << a / b << std::endl;

//     return 0;
// }

// #include <iostream>

// int main() {
//     std::cout << "Привет," << std::endl;
//     std::cout << "я" << std::endl;
//     std::cout << "студент" << std::endl;
//     std::cout << "ЛЭТИ!" << std::endl;

//     return 0;
// }

// #include <iostream>
// using namespace std;

// int main() {
//     int i = 100000, k;
//     short j = 10000, m;
//     k = j;  // Короткое целое преобразуется к целому без потерь
//     m = i;  // Преобразование целого к короткому целому приводит к искажению данных
//     cout << k << "      " << m << endl;  // На экран будет выведено:   10000    -31072

//     k = 12500;
//     m = k;                               // Потери данных нет
//     cout << k << "      " << m << endl;  // На экран будет выведено:   12500   12500

//     double d = 1.8234, n1, n2;
//     n1 = i;  // Без ошибок
//     n2 = j;  // Без ошибок
//     k = d;   // С потерей точности
//     j = d;   // С потерей точности
//     /* На экран будет выведено:    100000    10000   1     1   */
//     cout << n1 << "      " << n2 << "      " << k << "      " << j << endl;

//     d = 1e+100;
//     k = d;  // С потерей данных
//     m = d;  // С потерей данных
//     /* На экран будет выведено:    1е+100     -2147483648     0   */
//     cout << d << "      " << k << "      " << m << endl;

//     system("Pause");
//     return 0;
// }

// #include <iostream>
// using namespace std;

// int main() {
//     int i = 7, j = 30, k;
//     cout << i * j << endl;        // 210
//     cout << (k = i * j) << endl;  // 210
//     cout << k << endl;            // 210

//     system("Pause");
//     return 0;
// }

#include <iostream>
using namespace std;

int main() {
    int i = 7, j = 30, k, l, m, n;
    k = l = m = n = i + j;
    cout << k << "      " << l << "      " << m << "      " << n << "      " << endl;  // 37 37 37 37

    system("Pause");
    return 0;
}