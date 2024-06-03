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

// #include <iostream>

// void swap(int& a, int& b) {
//     int tmp = a;
//     a = b;
//     b = tmp;
// }

// void sort_three(int& a, int& b, int& c) {
//     if (a > b) swap(a, b);
//     if (a > c) swap(c, a);
//     if (b > c) swap(c, b);
// }

// int main() {
//     int a, b, c;
//     std::cin >> a >> b >> c;
//     int a1, b1, c1;
//     std::cin >> a1 >> b1 >> c1;

//     sort_three(a, b, c);
//     sort_three(a1, b1, c1);

//     int result = 0;
//     if (a == a1 && b == b1 && c == c1)
//         result = 3;
//     else if (a <= a1 && b <= b1 && c <= c1)
//         result = 1;
//     else if (a >= a1 && b >= b1 && c >= c1)
//         result = 2;

//     switch (result) {
//         case 1:
//             puts("The first box is smaller than the second one");
//             break;
//         case 2:
//             puts("The first box is larger than the second one");
//             break;
//         case 3:
//             puts("Boxes are equal");
//             break;
//         default:
//             puts("Boxes are incomparable");
//             break;
//     }
//     return 0;
// }

// #include <iostream>

// int main() {
//     int n, i = 1;
//     std::cin >> n;

//     while (i * i <= n) {
//         printf("%d ", i * i);
//         i++;
//     }

//     return 0;
// }

// #include <iostream>

// int main() {
//     int n, i = 2;
//     std::cin >> n;

//     while (i <= n) {
//         if (n % i == 0) {
//             printf("%d", i);
//             break;
//         }
//         i++;
//     }
//     return 0;
// }

// #include <iostream>

// int main() {
//     int n, i = 1;
//     std::cin >> n;

//     while (i <= n) {
//         printf("%d ", i);
//         i *= 2;
//     }
//     return 0;
// }

// #include <iostream>

// int main() {
//     int n, i = 1, res = 1;
//     std::cin >> n;

//     while (i <= n) {
//         res = i;
//         i *= 2;
//     }
//     printf("%s", res == n ? "YES" : "NO");
//     return 0;
// }

// #include <iostream>

// int main() {
//     int n, count = 0;

//     while (std::cin >> n && n != 0) count++;

//     printf("%d", count);
//     return 0;
// }

// #include <iostream>

// int main() {
//     int n, sum = 0;

//     while (std::cin >> n && n != 0) sum += n;

//     printf("%d", sum);
//     return 0;
// }

// #include <iostream>

// int main() {
//     int n, max = 0, count = 0;

//     while (std::cin >> n && n != 0) {
//         if (n > max) {
//             max = n;
//             count = 0;
//         }
//         if (n == max) count++;
//     }
//     printf("%d", count);
//     return 0;
// }

// #include <iostream>

// int main() {
//     int n, max = 0, sec_max = 0;

//     while (std::cin >> n && n != 0) {
//         if (n >= max) {
//             sec_max = max;
//             max = n;
//         } else if (sec_max < n)
//             sec_max = n;
//     }
//     printf("%d", sec_max);
//     return 0;
// }

// #include <iostream>

// int main() {
//     size_t count;
//     int f0 = 0, f1 = 1, res = 1;

//     std::cin >> count;

//     for (size_t i = 1; i < count; i++) {
//         res = f0 + f1;
//         f0 = f1;
//         f1 = res;
//     }

//     printf("%d", res);
//     return 0;
// }

// #include <iostream>

// int main() {
//     int f0 = 0, f1 = 1, res = 1, number, count = 1;

//     std::cin >> number;

//     for (; res < number; count++) {
//         res = f0 + f1;
//         f0 = f1;
//         f1 = res;
//     }

//     printf("%d", f1 == number ? count : -1);
//     return 0;
// }

// #include <iostream>

// int main() {
//     int n, mem = 0, count = 0, max_count = 1;

//     while (std::cin >> n && n != 0) {
//         if (n != mem) {
//             count = 0;
//             mem = n;
//         }
//         if (n == mem) count++;
//         if (max_count < count) max_count = count;
//     }

//     printf("%d", max_count);
//     return 0;
// }

// #include <iostream>

// int main() {
//     int n, n0 = 0, n1 = 0, n2 = 0, count = 0;

//     while (std::cin >> n && n != 0) {
//         n0 = n1;
//         n1 = n2;
//         n2 = n;
//         if (n0 < n1 && n1 > n2 && n0 != 0) count++;
//     }

//     printf("%d", count);
//     return 0;
// }

// #include <iostream>

// int main() {
//     int n, n0 = 0, n1 = 0, n2 = 0;
//     int max_count = 0, len = 0, min_len = 0;

//     while (std::cin >> n && n != 0) {
//         n0 = n1;
//         n1 = n2;
//         n2 = n;
//         if (n0 < n1 && n1 > n2 && n0 != 0) {
//             if (min_len == 0) min_len = len;
//             if (len < min_len) min_len = len;
//             max_count++;
//             len = 0;
//         }
//         if (max_count) len++;
//     }

//     printf("%d", min_len);
//     return 0;
// }

// #include <cmath>
// #include <iostream>

// int main() {
//     double n;

//     std::cin >> n;

//     double result = n - trunc(n);

//     std::cout << result;
//     return 0;
// }

// #include <iostream>

// int main() {
//     double n;

//     std::cin >> n;

//     double result = (int)(n * 10) % 10;

//     std::cout << result;
//     return 0;
// }

// #include <cmath>
// #include <iostream>

// int main() {
//     double a, b, c;

//     std::cin >> a >> b >> c;

//     double p = (a + b + c) / 2;
//     double result = sqrt(p * (p - a) * (p - b) * (p - c));

//     std::cout << result;
//     return 0;
// }

// #include <iostream>

// int main() {
//     double p, x, y;

//     std::cin >> p >> x >> y;

//     double rub = x * (1 + p / 100);
//     int res_rub = (int)rub;
//     double cop = y * (1 + p / 100) + rub * 100 - res_rub * 100;
//     res_rub += (int)cop / 100;
//     int res_cop = (int)cop % 100;

//     printf("%d %d", res_rub, res_cop);
//     return 0;
// }

// #include <iostream>

// int main() {
//     int p, x, y, k;
//     std::cin >> p >> x >> y >> k;

//     for (int i = 0; i < k; i++) {
//         int res = (x * 100 + y) * (p + 100) / 100;
//         x = res / 100;
//         y = res % 100;
//     }
//     printf("%d %d", x, y);

//     return 0;
// }

// #include <iostream>

// int main() {
//     int n, count = 0;
//     double result = 0;
//     while (std::cin >> n && n != 0) {
//         result += n;
//         count++;
//     }
//     std::cout.precision(9);
//     std::cout << result / count;
//     return 0;
// }

// #include <cmath>
// #include <iostream>
// #include <vector>

// int main() {
//     int n, count = 0;
//     std::vector<int> a;
//     double mean = 0;
//     while (std::cin >> n && n != 0) {
//         a.push_back(n);
//         mean += n;
//         count++;
//     }
//     mean /= count;

//     double result = 0;

//     for (int i = 0; i < count; i++) {
//         result += (a[i] - mean) * (a[i] - mean);
//     }

//     result = sqrt(result / --count);

//     printf("%.11lf\n", result);

//     return 0;
// }

// #include <cmath>
// #include <iomanip>
// #include <iostream>

// int main() {
//     using namespace std;
//     // входное число, счетчик чисел, сумма чисел, сумма квадратов чисел
//     int n, cnt = 0, sum = 0, sum2 = 0;
//     // результат - стандартное отклонение
//     double res;
//     while (cin >> n && n != 0) {
//         cnt++;
//         // находим сумму и сумму квадратов
//         sum += n;
//         sum2 += n * n;
//     }
//     // для увеличения точности все возможные операции до
//     // деления выполняем над целыми
//     res = sqrt((double)(cnt * sum2 - sum * sum) / (cnt * (cnt - 1)));  // средне квадратичное отклонение
//     cout << setprecision(11) << fixed;
//     cout << res;
//     return 0;
// }

// #include <iomanip>
// #include <iostream>

// int main() {
//     using namespace std;
//     size_t count;
//     double n, x, result = 0;
//     cin >> count >> x;

//     for (size_t i = 0; i <= count; i++) {
//         cin >> n;
//         result *= x;
//         result += n;
//     }
//     cout << result;
//     return 0;
// }

// #include <cmath>
// #include <iomanip>
// #include <iostream>

// void swap(double& a, double& b) {
//     double tmp = a;
//     a = b;
//     b = tmp;
// }

// int main() {
//     double a, b, c;
//     std::cin >> a >> b >> c;

//     double D = b * b - 4 * a * c;

//     if (D < 0) return 0;

//     double x1 = (-b + sqrt(D)) / (2 * a);
//     double x2 = (-b - sqrt(D)) / (2 * a);

//     if (x1 == x2)
//         std::cout << x1;
//     else {
//         if (x1 > x2) swap(x1, x2);
//         std::cout << x1 << " " << x2 << std::endl;
//     }
//     return 0;
// }

// #include <cmath>
// #include <iomanip>
// #include <iostream>

// void swap(double& a, double& b) {
//     double tmp = a;
//     a = b;
//     b = tmp;
// }

// int main() {
//     double a, b, c;
//     std::cin >> a >> b >> c;

//     if (a == 0) {
//         if (b == 0) {
//             if (c == 0) {
//                 std::cout << 3;
//                 return 0;
//             } else {
//                 std::cout << 0;
//                 return 0;
//             }
//         } else {
//             std::cout << 1 << " " << (double)c / -b;
//             return 0;
//         }
//     }

//     double D = b * b - 4 * a * c;

//     if (D < 0) {
//         std::cout << 0;
//         return 0;
//     }

//     double x1 = (-b + sqrt(D)) / (2 * a);
//     double x2 = (-b - sqrt(D)) / (2 * a);

//     if (x1 == x2)
//         std::cout << 1 << " " << x1;
//     else {
//         if (x1 > x2) swap(x1, x2);
//         std::cout << 2 << " " << x1 << " " << x2;
//     }
//     std::cout << std::endl;
//     return 0;
// }

// #include <iostream>

// int main() {
//     double a, b, c, d, e, f;
//     std::cin >> a >> b >> c >> d >> e >> f;

//     double x = (b * f - d * e) / (b * c - d * a);
//     double y = (c * e - f * a) / (b * c - d * a);

//     std::cout << x << " " << y << std::endl;
//     return 0;
// }

// #include <cmath>
// #include <iostream>

// double eps = 0.000001;
// double norm(double x) { return fabs(x) <= eps ? 0 : x; }

// int main() {
//     double a, b, c, d, e, f;
//     std::cin >> a >> b >> c >> d >> e >> f;

//     double D = a * d - b * c;
//     double Dx = e * d - b * f;
//     double Dy = a * f - c * e;

//     if (D != 0) {
//         std::cout << 2 << ' ' << norm(Dx / D) << ' ' << norm(Dy / D);
//     } else {
//         if (Dx == 0 && Dy == 0) {
//             if (a == 0 && b == 0 && c == 0 && d == 0) {
//                 if (e != 0 || f != 0) {
//                     std::cout << 0;
//                 } else {
//                     std::cout << 5;
//                 }
//             } else {
//                 if (a == 0 && c == 0) {
//                     if (b != 0) {
//                         double y = e / b;
//                         std::cout << 4 << " " << y;
//                     } else {
//                         double y = f / d;
//                         std::cout << 4 << " " << y;
//                     }
//                 } else {
//                     if (b == 0 && d == 0) {
//                         if (a != 0) {
//                             double x = e / a;
//                             std::cout << 3 << " " << x;
//                         } else {
//                             double x = f / c;
//                             std::cout << 3 << " " << x;
//                         }
//                     } else {
//                         if (b != 0) {
//                             double n = e / b;
//                             double k = -a / b;
//                             std::cout << 1 << " " << k << " " << n;
//                         } else {
//                             double n = f / d;
//                             double k = -c / d;
//                             std::cout << 1 << " " << k << " " << n;
//                         }
//                     }
//                 }
//             }
//         } else {
//             std::cout << 0;
//         }
//     }
//     std::cout << std::endl;
//     return 0;
// }

// #include <iostream>
// #include <vector>

// int main() {
//     size_t count;
//     std::cin >> count;
//     std::vector<int> a(count);

//     for (size_t i = 0; i < count; i++) {
//         std::cin >> a[i];
//     }

//     for (size_t i = 0; i < count; i++) {
//         if (a[i] % 2 == 0) std::cout << a[i] << " ";
//     }
//     std::cout << std::endl;
//     return 0;
// }

// #include <iostream>
// #include <vector>

// int main() {
//     size_t count;
//     std::cin >> count;
//     std::vector<int> a(count);

//     for (size_t i = 0; i < count; i++) {
//         std::cin >> a[i];
//     }
//     int result = 0;
//     for (size_t i = 0; i < count; i++) {
//         if (a[i] > 0) result++;
//     }
//     std::cout << result << std::endl;
//     return 0;
// }

// #include <iostream>
// #include <vector>

// int main() {
//     size_t count;
//     std::cin >> count;
//     std::vector<int> a(count);

//     for (size_t i = 0; i < count; i++) {
//         std::cin >> a[i];
//     }
//     int result = 0;
//     for (size_t i = 1; i < count; i++) {
//         if (a[i] > a[i - 1]) std::cout << a[i] << " ";
//     }
//     std::cout << std::endl;
//     return 0;
// }

// #include <iostream>
// #include <vector>

// int main() {
//     size_t count;
//     std::cin >> count;
//     std::vector<int> a(count);

//     for (size_t i = 0; i < count; i++) {
//         std::cin >> a[i];
//     }
//     int result = 0;
//     for (size_t i = 1; i < count; i++) {
//         if (a[i] > 0 && a[i - 1] > 0) {
//             std::cout << a[i - 1] << " " << a[i] << std::endl;
//             break;
//         }
//         if (a[i] < 0 && a[i - 1] < 0) {
//             std::cout << a[i] << " " << a[i - 1] << std::endl;
//             break;
//         }
//     }
//     return 0;
// }

// #include <iostream>
// #include <vector>

// int main() {
//     size_t count;
//     std::cin >> count;
//     std::vector<int> a(count);

//     for (size_t i = 0; i < count; i++) {
//         std::cin >> a[i];
//     }
//     int min_plus = INT32_MAX;
//     for (size_t i = 0; i < count; i++) {
//         if (a[i] > 0 && a[i] < min_plus) {
//             min_plus = a[i];
//         }
//     }
//     std::cout << min_plus << std::endl;
//     return 0;
// }

// #include <iostream>
// #include <vector>

// int main() {
//     size_t count;
//     std::cin >> count;
//     std::vector<int> a(count);
//     int min_odd = 0;

//     for (size_t i = 0; i < count; i++) {
//         std::cin >> a[i];
//         if (a[i] % 2) min_odd = a[i];
//     }

//     for (size_t i = 0; i < count; i++) {
//         if (a[i] % 2 && a[i] < min_odd) {
//             min_odd = a[i];
//         }
//     }

//     std::cout << min_odd << std::endl;
//     return 0;
// }

// #include <iostream>
// #include <vector>

// int main() {
//     size_t count;
//     std::cin >> count;
//     std::vector<int> a(count);

//     for (size_t i = 0; i < count; i++) {
//         std::cin >> a[i];
//     }

//     int result = 1;
//     for (size_t i = 1; i < count; i++) {
//         if (a[i] != a[i - 1]) result++;
//     }

//     std::cout << result << std::endl;
//     return 0;
// }

// #include <iostream>
// #include <vector>

// void swap(int& a, int& b) {
//     int tmp = a;
//     a = b;
//     b = tmp;
// }

// int main() {
//     size_t count;
//     std::cin >> count;
//     std::vector<int> a(count);

//     for (size_t i = 0; i < count; i++) {
//         std::cin >> a[i];
//     }

//     for (size_t i = 1; i < count; i++) {
//         if (i % 2) swap(a[i], a[i - 1]);
//     }

//     for (size_t i = 0; i < count; i++) {
//         std::cout << a[i] << " ";
//     }
//     std::cout << std::endl;
//     return 0;
// }

// #include <iostream>
// #include <vector>

// enum { shift = 1 };

// int main() {
//     size_t count;
//     std::cin >> count;
//     std::vector<int> a(count);

//     for (size_t i = 0; i < count; i++) {
//         std::cin >> a[i];
//     }

//     for (size_t i = 0; i < count; i++) {
//         std::cout << a[(count + i + shift) % count] << " ";
//     }

//     std::cout << std::endl;
//     return 0;
// }

// #include <iostream>
// #include <vector>

// int main() {
//     size_t count;
//     std::cin >> count;
//     std::vector<int> a(count);

//     for (size_t i = 0; i < count; i++) {
//         std::cin >> a[i];
//     }

//     int result = 0;

//     for (size_t i = 0; i < count; i++) {
//         for (size_t j = i + 1; j < count; j++) {
//             if (a[i] == a[j]) result++;
//         }
//     }

//     std::cout << result << std::endl;
//     return 0;
// }

// #include <iostream>
// #include <vector>

// int main() {
//     size_t count;
//     std::cin >> count;
//     std::vector<int> a(count);

//     for (size_t i = 0; i < count; i++) {
//         std::cin >> a[i];
//     }

//     for (size_t i = 0; i < count; i++) {
//         int result = 0;
//         for (size_t j = 0; j < count; j++) {
//             if (i == j)
//                 continue;
//             else if (a[i] == a[j])
//                 result++;
//         }
//         if (result == 0) std::cout << a[i] << " ";
//     }

//     std::cout << std::endl;
//     return 0;
// }

// #include <cmath>
// #include <iostream>

// enum { rows = 8, columns = 2 };

// int main() {
//     int a[rows][columns];

//     for (size_t i = 0; i < rows; i++) {
//         for (size_t j = 0; j < columns; j++) {
//             std::cin >> a[i][j];
//         }
//     }
//     int result = 0;
//     for (size_t i = 0; i < rows; i++) {
//         for (size_t j = 0; j < rows; j++) {
//             if (i == j)
//                 continue;
//             else if (a[i][1] == a[j][1] || a[i][0] == a[j][0] ||
//                      abs(a[i][1] - a[j][1]) == abs(a[i][0] - a[j][0]))
//                 result++;
//         }
//     }

//     std::cout << (result == 0 ? "NO" : "YES") << std::endl;
//     return 0;
// }

// #include <iostream>
// #include <vector>

// int main() {
//     size_t count, throws, left, right;
//     std::cin >> count >> throws;
//     std::vector<int> a(count);

//     for (size_t i = 0; i < throws; i++) {
//         std::cin >> left >> right;
//         for (size_t j = left - 1; j < right; j++) {
//             a[j] = 1;
//         }
//     }

//     for (size_t i = 0; i < count; i++) {
//         if (a[i])
//             std::cout << ".";
//         else
//             std::cout << "I";
//     }
//     std::cout << std::endl;
//     return 0;
// }

// #include <iostream>

// int main() {
//     int n, m, n_max = 0, m_max = 0;
//     std::cin >> n >> m;
//     int a[n][m];
//     int max = INT32_MIN;
//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < m; j++) {
//             std::cin >> a[i][j];
//             if (a[i][j] > max) {
//                 max = a[i][j];
//                 n_max = i;
//                 m_max = j;
//             }
//         }
//     }

//     std::cout << n_max << " " << m_max << std::endl;
//     return 0;
// }
// #include <iostream>

// int main() {
//     int n;
//     std::cin >> n;
//     int a[n][n] = {};

//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < n; j++) {
//             if (i == j || n - i - 1 == j || i == n / 2 || j == n / 2) {
//                 a[i][j] = 1;
//             }
//         }
//     }
//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < n; j++) {
//             std::cout << (a[i][j] ? "*" : ".") << (j == n - 1 ? "\n" : " ");
//         }
//     }
//     std::cout << std::endl;
//     return 0;
// }

// #include <iostream>

// enum { max = 100 };

// int main() {
//     int n;
//     std::cin >> n;
//     int a[max][max] = {};

//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < n; j++) {
//             if (i < j) {
//                 a[i][j] = (n - i + j) % n;
//                 a[j][i] = a[i][j];
//             }
//         }
//     }
//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < n; j++) {
//             std::cout << a[i][j] << (j == n - 1 ? "\n" : " ");
//         }
//     }
//     return 0;
// }

// #include <iostream>

// int main() {
//     using namespace std;
//     int n;
//     cin >> n;
//     int a[100][100];
//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < n; j++) {
//             a[i][j] = abs(i - j);
//             cout << a[i][j] << " ";
//         }
//         cout << endl;
//     }
//     return 0;
// }

// #include <iostream>

// int main() {
//     int n;
//     std::cin >> n;
//     int a[100][100];

//     for (int i = 0; i < n; i++)
//         for (int j = 0; j < n - i; j++) {
//             a[i][i + j] = j;
//             a[i + j][i] = j;
//         }

//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < n; j++) std::cout << a[i][j] << " ";
//         std::cout << std::endl;
//     }
//     return 0;
// }

// #include <iostream>
// using namespace std;
// int main() {
//     int n;
//     cin >> n;
//     int i = n * n;
//     while (i-- > 0) cout << abs(i / n - i % n) << (i % n ? " " : "\n");
// }

// #include <iostream>

// enum { max = 100 };

// void swap(int& a, int& b) {
//     int tmp = a;
//     a = b;
//     b = tmp;
// }

// int main() {
//     int n, m;
//     std::cin >> n >> m;
//     int a[max][max] = {};

//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < m; j++) {
//             std::cin >> a[i][j];
//         }
//     }

//     int b, c;
//     std::cin >> b >> c;

//     for (int i = 0; i < n; i++) {
//         swap(a[i][b], a[i][c]);
//     }

//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < m; j++) {
//             std::cout << a[i][j] << (j == m - 1 ? "\n" : " ");
//         }
//     }
//     return 0;
// }
// #include <iostream>

// enum { max = 100 };

// int main() {
//     int n;
//     std::cin >> n;
//     int a[max][max] = {};

//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < n; j++) {
//             std::cin >> a[i][j];
//         }
//     }
//     int result = 0;
//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < n; j++) {
//             if (i == j) continue;
//             if (a[i][j] != a[j][i]) result++;
//         }
//     }

//     std::cout << (result ? "NO" : "YES");
//     return 0;
// }

// #include <iostream>

// enum { max = 100 };

// int main() {
//     int n;
//     std::cin >> n;
//     int a[max][max] = {};

//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < n; j++) {
//             std::cin >> a[i][j];
//         }
//     }
//     int k;
//     std::cin >> k;

//     for (int i = 0; i < n; i++) {
//         int row = i + k;
//         if (row < 0 || row > n - 1)
//             continue;
//         else
//             std::cout << a[row][i] << " ";
//     }
//     std::cout << std::endl;
//     return 0;
// }
// #include <iostream>

// enum { max = 1000 };

// int main() {
//     int n, m;
//     std::cin >> n >> m;
//     int a[max][max] = {};

//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < m; j++) {
//             std::cin >> a[i][j];
//         }
//     }

//     for (int j = 0; j < m; j++) {
//         for (int i = 0; i < n; i++) {
//             std::cout << a[i][j] << (i == n - 1 ? "\n" : " ");
//         }
//     }
//     std::cout << std::endl;
//     return 0;
// }
// #include <iostream>

// enum { max = 100 };

// int main() {
//     int n, m;
//     std::cin >> n >> m;
//     int a[max][max] = {};

//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < m; j++) {
//             std::cin >> a[i][j];
//         }
//     }

//     for (int j = 0; j < m; j++) {
//         for (int i = 0; i < n; i++) {
//             std::cout << a[n - 1 - i][j] << (i == n - 1 ? "\n" : " ");
//         }
//     }
//     std::cout << std::endl;
//     return 0;
// }
// #include <iostream>

// enum { max = 100 };

// int main() {
//     int n, m;
//     std::cin >> n >> m;
//     int a[max][max] = {};
//     int count = 0;
//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < m; j++) {
//             int column = i % 2 ? m - 1 - j : j;
//             a[i][column] = ++count;
//         }
//     }

//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < m; j++) {
//             printf("%4d%s", a[i][j], (j == m - 1 ? "\n" : ""));
//         }
//     }
//     return 0;
// }
// #include <iostream>

// enum { max = 100 };

// int main() {
//     int n, m;
//     std::cin >> n >> m;
//     int a[max][max] = {};
//     int count = 0;
//     for (int k = 0; k < n + m - 1; k++) {
//         for (int i = 0; i < n; i++) {
//             for (int j = 0; j < m; j++) {
//                 if (i == k - j || j == k - i) {
//                     a[i][j] = ++count;
//                 }
//             }
//         }
//     }

//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < m; j++) {
//             printf("%4d%s", a[i][j], (j == m - 1 ? "\n" : ""));
//         }
//     }
//     return 0;
// }
// #include <iostream>

// enum { max = 100 };

// int main() {
//     int n, m;
//     std::cin >> n >> m;
//     int a[max][max] = {};
//     int count = 0;
//     for (int k = 0; k < n + m - 1; k++) {
//         for (int i = 0; i < n; i++) {
//             for (int j = 0; j < m; j++) {
//                 if (i == k - j || j == k - i) {
//                     a[i][j] = ++count;
//                 }
//             }
//         }
//     }

//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < m; j++) {
//             printf("%4d%s", a[i][j], (j == m - 1 ? "\n" : ""));
//         }
//     }
//     return 0;
// }
// #include <iostream>

// enum { max = 100 };

// int main() {
//     int n, m;
//     std::cin >> n >> m;
//     int a[max][max] = {};
//     int count = 0;

//     for (int k = 0; k < n + m; k++) {
//         for (int i = 0; i < n + m; i++) {
//             int j = k - i;
//             if (j >= 0 && i >= 0 && j < m && i < n) {
//                 a[i][j] = ++count;
//             }
//         }
//     }

//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < m; j++) {
//             printf("%4d%s", a[i][j], (j == m - 1 ? "\n" : ""));
//         }
//     }
//     return 0;
// }

// #include <iostream>

// enum { max = 100 };

// int main() {
//     int N, M;
//     std::cin >> N >> M;
//     int a[max][max] = {};
//     int left, right, up, down, flag, counter;
//     left = right = up = down = flag = counter = 0;

//     while (counter < N * M) {
//         if (flag == 0) {  // >
//             for (int i = left; i < M - right; i++) {
//                 a[up][i] = ++counter;
//             }
//             flag = 1;
//             up++;
//         } else if (flag == 1) {  // v
//             for (int i = up; i < N - down; i++) {
//                 a[i][M - right - 1] = ++counter;
//             }
//             flag = 2;
//             right++;
//         } else if (flag == 2) {  // <
//             for (int i = M - right - 1; i > left - 1; i--) {
//                 a[N - down - 1][i] = ++counter;
//             }
//             flag = 3;
//             down++;
//         } else if (flag == 3) {  // ^
//             for (int i = N - down - 1; i > up - 1; i--) {
//                 a[i][left] = ++counter;
//             }
//             flag = 0;
//             left++;
//         }
//     }
//     for (int i = 0; i < N; i++) {
//         for (int j = 0; j < M; j++) {
//             printf("%4d%s", a[i][j], (j == M - 1 ? "\n" : ""));
//         }
//     }

//     return 0;
// }

// #include <iostream>

// int min(int a, int b) { return a > b ? b : a; }

// int min4(int a, int b, int c, int d) { return min(min(a, b), min(c, d)); }

// int main() {
//     int a, b, c, d;
//     std::cin >> a >> b >> c >> d;

//     int result = min4(a, b, c, d);

//     std::cout << result << std::endl;

//     return 0;
// }

// #include <cmath>
// #include <iostream>

// double distance(double a, double b, double c, double d) {
//     double res = sqrt((a - c) * (a - c) + (b - d) * (b - d));
//     return res;
// }

// int main() {
//     double a, b, c, d;
//     std::cin >> a >> b >> c >> d;

//     double result = distance(a, b, c, d);

//     std::cout << result << std::endl;

//     return 0;
// }

// #include <cmath>
// #include <iostream>
// enum { left = -1, right = 1 };

// bool IsPointInSquare(double x, double y) {
//     bool res = (x >= left) * (y >= left) * (x <= right) * (y <= right);
//     return res;
// }

// int main() {
//     double x, y;
//     std::cin >> x >> y;

//     bool result = IsPointInSquare(x, y);

//     std::cout << (result ? "YES" : "NO") << std::endl;

//     return 0;
// }

// #include <cmath>
// #include <iostream>

// enum { left = -1, right = 1 };

// bool IsPointInSquare(double x, double y) {
//     bool res = fabs(x) + fabs(y) <= right;
//     return res;
// }

// int main() {
//     double x, y;
//     std::cin >> x >> y;

//     bool result = IsPointInSquare(x, y);

//     std::cout << (result ? "YES" : "NO") << std::endl;

//     return 0;
// }
// #include <cmath>
// #include <iostream>

// bool IsPointInCircle(double x, double y, double xc, double yc, double r) {
//     bool res = (xc - x) * (xc - x) + (yc - y) * (yc - y) <= r * r;
//     return res;
// }

// int main() {
//     double x, y, xc, yc, r;
//     std::cin >> x >> y >> xc >> yc >> r;

//     bool result = IsPointInCircle(x, y, xc, yc, r);

//     std::cout << (result ? "YES" : "NO") << std::endl;

//     return 0;
// }

#include <cmath>
#include <iostream>

bool IsPointInCircle(double x, double y, double xc = -1, double yc = 1, double r = 2) {
    bool res = (xc - x) * (xc - x) + (yc - y) * (yc - y) <= r * r;
    return res;
}
bool IsPointInCircleOut(double x, double y, double xc = -1, double yc = 1, double r = 2) {
    bool res = (xc - x) * (xc - x) + (yc - y) * (yc - y) < r * r;
    return res;
}
bool IsPointInArea(double x, double y, double n1 = 2, double k1 = 2, double n2 = -1, double k2 = 0) {
    bool res1 = IsPointInCircle(x, y);
    // std::cout << res1;
    bool res2 = (n1 * x + k1 <= y);
    // std::cout << res2;
    bool res3 = (n2 * x + k2 <= y);
    // std::cout << res3;
    bool res4 = IsPointInCircleOut(x, y);
    // std::cout << !res4;
    bool res5 = (n1 * x + k1 >= y);
    // std::cout << res5;
    bool res6 = (n2 * x + k2 >= y);
    // std::cout << res6;
    bool res = res1 * res2 * res3 || !res4 * res5 * res6;
    return res;
}

int main() {
    double x, y;
    std::cin >> x >> y;

    bool result = IsPointInArea(x, y);

    std::cout << (result ? "YES" : "NO") << std::endl;

    return 0;
}