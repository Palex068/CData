// #include <iostream>

// int main() {
//   std::cout << "Hello, Stepik!" << std::endl;
//   return 0;
// }

// #include <iostream>

// int main() {
//   puts("Hello, Stepik!");
//   return 0;
// }

// #include <iostream>

// int main() {
//     int n, k;
//     std::cin >> n >> k;
//     int result = k / n;
//     std::cout << result << std::endl;
//     return 0;
// }

// #include <iostream>

// int main() {
//     int n, k;
//     std::cin >> n >> k;
//     int result = k - (k / n) * n;
//     std::cout << result << std::endl;
//     return 0;
// }

// #include <iostream>

// int main() {
//     int n;
//     std::cin >> n;
//     int result = n % 10;
//     std::cout << result << std::endl;
//     return 0;
// }

// #include <iostream>

// int main() {
//     int n;
//     std::cin >> n;
//     int result = n / 10;
//     std::cout << result << std::endl;
//     return 0;
// }

// #include <iostream>

// int main() {
//     int n;
//     std::cin >> n;
//     int result = (n % 100) / 10;
//     std::cout << result << std::endl;
//     return 0;
// }

// #include <iostream>

// int main() {
//     int n;
//     std::cin >> n;
//     int result = 0;
//     while (n > 0) {
//         result += n % 10;
//         n /= 10;
//     }
//     std::cout << result << std::endl;
//     return 0;
// }

// #include <iostream>

// int main() {
//     int n;
//     std::cin >> n;
//     int result = ((n / 2) + 1) * 2;
//     std::cout << result << std::endl;
//     return 0;
// }

// #include <iostream>

// int main() {
//     int p[3];
//     std::cin >> p[0] >> p[1] >> p[2];
//     int result = 0;
//     for (int x : p) {
//         result += x / 2 + x % 2;
//     }
//     std::cout << result << std::endl;
//     return 0;
// }

// #include <iostream>

// int main() {
//     int a, b, n;
//     std::cin >> a >> b >> n;
//     const int result[2]{a * n + b * n / 100, b * n % 100};
//     printf("%d %d\n", result[0], result[1]);
//     return 0;
// }

// #include <iostream>

// int main() {
//     int n;
//     std::cin >> n;
//     const int result[3]{(n / 3600) % 24, (n / 60) % 60, n % 60};
//     printf("%02d:%02d:%02d\n", result[0], result[1], result[2]);
//     return 0;
// }

// #include <iostream>

// struct TIME {
//    private:
//     int hours;
//     int minutes;
//     int seconds;

//    public:
//     TIME(int hours = 0, int minutes = 0, int seconds = 0) {
//         this->hours = hours;
//         this->minutes = minutes;
//         this->seconds = seconds;
//     };
//     int total_seconds(TIME a) {
//         int res = a.hours * 3600 + a.minutes * 60 + a.seconds;
//         return res;
//     };
//     TIME difference(TIME a, TIME b) {
//         int n = total_seconds(b) - total_seconds(a);
//         TIME c;
//         c.hours = (n / 3600) % 24;
//         c.minutes = (n / 60) % 60;
//         c.seconds = n % 60;
//         return c;
//     };
// };

// int main() {
//     int h, m, s;
//     std::cin >> h >> m >> s;
//     TIME a(h, m, s);
//     std::cin >> h >> m >> s;
//     TIME b(h, m, s);

//     TIME result = result.difference(a, b);

//     printf("%d\n", result.total_seconds(result));
//     return 0;
// }

// #include <iostream>

// enum { mkad = 109 };

// int main() {
//     int v, t;
//     std::cin >> v >> t;
//     int result = ((v * t) % mkad + mkad) % mkad;
//     printf("%d\n", result);
//     return 0;
// }

// #include <iostream>

// int main() {
//     int n;
//     std::cin >> n;
//     int n1 = n / 1000;
//     int n2 = n / 100 % 10;
//     int n3 = n / 10 % 10;
//     int n4 = n % 10;

//     int result = !(n1 - n4) * !(n2 - n3);

//     printf("%d\n", result);
//     return 0;
// }

// #include <iostream>

// int main() {
//     int h, a, b;
//     std::cin >> h >> a >> b;

//     int result = 0, count = 0;

//     while (result + a < h) {
//         result += a - b;
//         count++;
//     }

//     printf("%d\n", count + 1);
//     return 0;
// }

// #include <iostream>

// /* bydlo language */
// #define sprosi std::cin
// #define skazhi std::cout
// #define op << std::endl
// #define v >>
// #define na <<
// #define iz <<
// #define _i_ &&
// #define ili ||
// #define poka while(
// #define ne !
// #define dumai {}
// #define verni return
// #define uhodi return
// #define ravno ==
// #define ne_ravno !=
// #define esli if(
// #define to )
// #define inache else
// #define glavnoe main()
// #define nachni {
// #define konchi }
// #define chetno % 2 == 0
// #define nechetno % 2 != 0
// #define bolshe >
// #define menshe <
// #define delai )
// #define dlya for (
// #define nakin ++
// #define otozhmi --
// #define cho_tam_v *
// #define dalshe continue
// #define zabei break
// #define dai new
// #define zabirai delete
// /* types */
// #define fakt bool
// #define bukva char
// #define chislo int
// #define bez_znaka unsigned
// #define veshch double
// #define stroka char*
// #define fraza const char*
// #define nichego void
// #define v_fakt (bool)
// #define v_chislo (int)
// #define v_bez_znaka (unsigned)
// #define v_veshch (double)
// #define da true
// #define net false

// chislo glavnoe nachni chislo h, a, b;
// sprosi v h v a v b;
// skazhi iz((h - b) + (a - b) - 1) / (a - b) op;
// verni 0;
// konchi

// #include <iostream>

// int main() {
//     int a, b;

//     std::cin >> a >> b;

//     std::cout << (a > b ? a : b) << std::endl;

//     return 0;
// }

// #include <iostream>

// int main() {
//     int a, b;

//     std::cin >> a >> b;

//     std::cout << (a > b ? 1 : 2) * (a != b) << std::endl;

//     return 0;
// }

// #include <iostream>

// int max(int a, int b) { return a > b ? a : b; }

// int main() {
//     int a, b, c;

//     std::cin >> a >> b >> c;

//     int result = max(a, max(b, c));

//     std::cout << result << std::endl;

//     return 0;
// }

// #include <iostream>

// int main() {
//     int a, b, c;
//     std::cin >> a >> b >> c;
//     if (a < b) a = b;
//     if (a < c) a = c;
//     std::cout << a;
//     return 0;
// }

// #include <iostream>

// int main() {
//     int a, b, c;

//     std::cin >> a >> b >> c;

//     int result = ((a + b) > c) && ((a + c) > b) && ((c + b) > a);

//     std::cout << (result ? "YES" : "NO") << std::endl;

//     return 0;
// }

// #include <iostream>

// int main() {
//     int a, b, c;

//     std::cin >> a >> b >> c;

//     int result = ((a + b) > c) && ((a + c) > b) && ((c + b) > a);

//     std::cout << (result ? "YES" : "NO") << std::endl;

//     return 0;
// }

// #include <iostream>

// int main() {
//     int a, b, c;

//     std::cin >> a >> b >> c;

//     int result = (a == b) + (a == c) + (c == b);

//     std::cout << (result == 1 ? 2 : result) << std::endl;

//     return 0;
// }

// #include <iostream>

// int main() {
//     int a, b, c, d;

//     std::cin >> a >> b >> c >> d;

//     int result = (a == c) || (b == d);

//     std::cout << (result ? "YES" : "NO") << std::endl;

//     return 0;
// }

// #include <cmath>
// #include <iostream>

// int main() {
//     int a, b, c, d;

//     std::cin >> a >> b >> c >> d;

//     int result = abs(a - c) <= 1 && abs(b - d) <= 1;

//     std::cout << (result ? "YES" : "NO") << std::endl;

//     return 0;
// }

// #include <cmath>
// #include <iostream>

// int main() {
//     int a, b, c, d;

//     std::cin >> a >> b >> c >> d;

//     int result = abs(a - c) == abs(b - d);

//     std::cout << (result ? "YES" : "NO") << std::endl;

//     return 0;
// }

// #include <cmath>
// #include <iostream>

// int main() {
//     int a, b, c, d;

//     std::cin >> a >> b >> c >> d;

//     int result = abs(a - c) == abs(b - d) || (a == c) || (b == d);

//     std::cout << (result ? "YES" : "NO") << std::endl;

//     return 0;
// }

// #include <cmath>
// #include <iostream>

// int main() {
//     int a, b, c, d;

//     std::cin >> a >> b >> c >> d;

//     int result = abs(a - c) == 1 && abs(b - d) == 2 || abs(a - c) == 2 && abs(b - d) == 1;

//     std::cout << (result ? "YES" : "NO") << std::endl;

//     return 0;
// }

// #include <cmath>
// #include <iostream>

// int min(int a, int b) { return a < b ? a : b; }
// void swap(int* a, int* b) {
//     int tmp = *a;
//     *a = *b;
//     *b = tmp;
// }

// int main() {
//     int a, b, c, d;

//     std::cin >> a >> b >> c >> d;

//     if (a > b) swap(&a, &b);

//     int result = min(c, min(d, min(abs(a - c), abs(b - d))));

//     std::cout << result << std::endl;

//     return 0;
// }

// #include <iostream>

// void swap(int* a, int* b) {
//     int tmp = *a;
//     *a = *b;
//     *b = tmp;
// }

// int main() {
//     int a, b, c;

//     std::cin >> a >> b >> c;

//     if (a > b) swap(&a, &b);
//     if (a > c) swap(&c, &a);
//     if (b > c) swap(&c, &b);

//     printf("%d %d %d", a, b, c);

//     return 0;
// }
#include <iostream>

void swap(int& a, int& b) {
    int tmp = a;
    a = b;
    b = tmp;
}

void sort_three(int& a, int& b, int& c) {
    if (a > b) swap(a, b);
    if (a > c) swap(c, a);
    if (b > c) swap(c, b);
}

int main() {
    int a, b, c;
    std::cin >> a >> b >> c;
    int a1, b1, c1;
    std::cin >> a1 >> b1 >> c1;

    sort_three(a, b, c);
    sort_three(a1, b1, c1);

    int result = 0;
    if (a == a1 && b == b1 && c == c1)
        result = 3;
    else if (a <= a1 && b <= b1 && c <= c1)
        result = 1;
    else if (a >= a1 && b >= b1 && c >= c1)
        result = 2;

    switch (result) {
        case 1:
            puts("The first box is smaller than the second one");
            break;
        case 2:
            puts("The first box is larger than the second one");
            break;
        case 3:
            puts("Boxes are equal");
            break;
        default:
            puts("Boxes are incomparable");
            break;
    }
    return 0;
}