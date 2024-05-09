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

// #include <cmath>
// #include <iostream>

// using namespace std;

// double triangle_sq(int a, int b, int c) {
//     double p = (a + b + c) / 2.0, res;
//     res = powf(p * (p - a) * (p - b) * (p - c), 0.5);
//     return res;
// }

// int main() {
//     int a, b, c;

//     cin >> a >> b >> c;

//     double res = triangle_sq(a, b, c);

//     printf("%.2lf", res);

//     return 0;
// }

// #include <cmath>
// #include <iostream>

// int module_id = -1;

// namespace params {
// int global_result = 0;
// }

// namespace triangle {
// double square(int a, int b, int c) {
//     double p = (a + b + c) / 2.0;
//     return sqrt(p * (p - a) * (p - b) * (p - c));
// }
// }  // namespace triangle

// namespace params {
// typedef union {
//     int res_int;
//     double res_dbl;
// } RESULT;
// }  // namespace params

// #include <cmath>
// #include <iostream>

// using namespace std;

// namespace triangle {
// int perimetr(int a, int b, int c) {
//     int p = a + b + c;
//     return p;
// }
// }  // namespace triangle

// namespace rectangle {
// int perimetr(int a, int b) {
//     int p = (a + b) * 2;
//     return p;
// }
// }  // namespace rectangle

// int main() {
//     int a0, a1, a2;

//     cin >> a0 >> a1 >> a2;

//     int res1 = triangle::perimetr(a0, a1, a2);
//     int res2 = rectangle::perimetr(a0, a1);

//     printf("%d %d", res1, res2);

//     return 0;
// }
// #include <cmath>
// #include <iostream>

// using namespace std;

// namespace math {
// int ar_compare(const short* a1, size_t len_a1, const short* a2, size_t len_a2) {
//     if (len_a1 != len_a2) {
//         return 0;
//     } else {
//         for (size_t i = 0; i < len_a1; i++) {
//             if (a1[i] != a2[i]) {
//                 return 0;
//             }
//         }
//     }
//     return 1;
// }
// }  // namespace math

// int main() {
//     short ar1[] = {1, 2, 3, 4, 5};
//     short ar2[] = {1, 2, 5, 3, 4};

//     int res = math::ar_compare(ar1, sizeof(ar1) / sizeof(*ar1), ar2, sizeof(ar2) / sizeof(*ar2));

//     printf("%d", res);

//     return 0;
// }

// #include <iostream>

// using namespace std;

// enum { max_len = 20 };

// namespace array_alg {

// typedef enum { sort_asc, sort_desc } TYPE_SORT;

// void swap(int* a, int* b) {
//     int tmp = *a;
//     *a = *b;
//     *b = tmp;
// }

// void sorted_int(int* ar, size_t len_ar, TYPE_SORT type) {
//     for (size_t i = 0; i < len_ar; i++) {
//         for (size_t j = i + 1; j < len_ar; j++) {
//             switch (type) {
//                 case sort_asc:
//                     if (ar[i] > ar[j]) swap(&ar[i], &ar[j]);
//                     break;

//                 case sort_desc:
//                     if (ar[i] < ar[j]) swap(&ar[i], &ar[j]);
//                     break;
//             }
//         }
//     }
// }

// }  // namespace array_alg

// int main() {
//     int array[max_len];

//     size_t count = 0;

//     while (count < max_len && cin.good()) {
//         cin >> array[count++];
//     }

//     array_alg::sorted_int(array, count - 1, array_alg::sort_asc);

//     for (size_t i = 0; i < count - 1; i++) {
//         cout << array[i] << ' ';
//     }

//     return 0;
// }

// #include <iostream>

// enum { max_len = 20 };

// namespace array_alg {

// typedef int (*PTR_FILTER_FUNC)(int);

// namespace filter_func {

// int even(int a) { return a % 2 == 0; }
// }  // namespace filter_func

// PTR_FILTER_FUNC func = filter_func::even;

// size_t filter_int(int* ar, size_t len_ar, PTR_FILTER_FUNC func) {
//     size_t count = 0;
//     for (size_t i = 0; i < len_ar; i++) {
//         if (func(ar[i])) ar[count++] = ar[i];
//     }
//     return count;
// }

// }  // namespace array_alg

// int main() {
//     int array[max_len];

//     size_t count = 0;

//     while (count < max_len && scanf("%d", &array[count]) == 1) count++;

//     count = array_alg::filter_int(array, count, array_alg::filter_func::even);

//     for (size_t i = 0; i < count; i++) {
//         printf("%d ", array[i]);
//     }

//     return 0;
// }

// #include <iostream>

// enum { max_len = 20, max_len_marks = 100 };

// namespace array_alg {

// typedef int (*PTR_FILTER_FUNC)(int);

// namespace filter_func {

// int mark_positive(int a) { return a >= 4; }
// }  // namespace filter_func

// PTR_FILTER_FUNC func = filter_func::mark_positive;

// size_t add_int(int* src, size_t start, size_t max_len_src, const int* dest, size_t len_dest,
//                PTR_FILTER_FUNC func) {
//     for (size_t i = 0; i < len_dest; i++) {
//         if (func(dest[i])) {
//             src[start++] = dest[i];
//             if (start == max_len_src) break;
//         }
//     }

//     return start;
// }

// }  // namespace array_alg

// int main() {
//     int marks[max_len_marks] = {3, 2, 5, 4, 3};
//     int ar[max_len];
//     size_t count = 0, count_marks = 5;

//     while (count < max_len && scanf("%d", &ar[count]) == 1) count++;

//     count = array_alg::add_int(marks, count_marks, max_len_marks, ar, count,
//                                array_alg::filter_func::mark_positive);

//     for (size_t i = 0; i < count; i++) {
//         printf("%d ", marks[i]);
//     }

//     return 0;
// }

// #include <iostream>

// enum { max_len_str = 50 };

// using std::cin;
// using std::cout;
// using std::endl;

// int main() {
//     char str[50];

//     cin >> str;
//     cout << str << endl;

//     return 0;
// }

// int global_var = 1;

// namespace test {
// typedef union {
//     char ch;
//     int vi;
//     double vd;
// } VAR;

// int odd(int x) { return x % 2 != 0; }
// }  // namespace test

// using AR_INT = int[10];
// using UINT = unsigned int;
// using TEST = test;  //
// using DATA = test::VAR;
// using VOLUME = struct {
//     int width, height, depth;
// };
// using PTR_STR = char*;
// using GVAR = global_var;     //
// using ptr_func = test::odd;  //

// #include <string.h>

// #include <iostream>

// using MEASURE = struct {
//     unsigned short width;
//     unsigned short height;
//     unsigned short depth;
// };

// using AUTO = struct {
//     char model[50];
//     unsigned short max_speed;
//     double weight;
//     MEASURE m;
// };

// int main() {
//     AUTO auto_sell;
//     char model[50];
//     unsigned short max_speed, width, height, depth;
//     double weight;

//     std::cin >> model >> max_speed >> weight >> width >> height >> depth;

//     strcpy(auto_sell.model, model);
//     auto_sell.max_speed = max_speed;
//     auto_sell.weight = weight;
//     auto_sell.m.width = width;
//     auto_sell.m.height = height;
//     auto_sell.m.depth = depth;

//     // __ASSERT_TESTS__

//     return 0;
// }

// #include <iostream>

// enum { max_len_str = 50 };

// using FIO_STR = char[max_len_str];

// using FIO = struct {
//     FIO_STR first;
//     FIO_STR otch;
//     FIO_STR last;
// };
// using std::cin;
// // using std::cout;

// int main() {
//     FIO fio;

//     cin >> fio.first >> fio.otch >> fio.last;

//     // cout << fio.first << ' ' << fio.otch << ' ' << fio.last;
//     // __ASSERT_TESTS__
//     return 0;
// }

// #include <iostream>

// enum { max_len_str = 50, max_things = 20 };

// using THING = struct {
//     char name[max_len_str];
//     double weight;
// };

// using std::cin;
// using std::cout;

// void swap_struct(THING* a, THING* b) {
//     THING tmp = *a;
//     *a = *b;
//     *b = tmp;
// }

// int main() {
//     THING th[max_things];
//     size_t count = 0;

//     while (count < max_things && cin >> th[count].name >> th[count].weight) count++;

//     for (size_t i = 0; i < count; i++) {
//         for (size_t j = i; j < count; j++) {
//             if (th[i].weight > th[j].weight) swap_struct(&th[i], &th[j]);
//         }
//     }

//     for (size_t i = 0; i < count; i++) {
//         cout << th[i].name << ' ';
//     }

//     return 0;
// }

// #include <iostream>

// enum { max_len_str = 50, max_things = 20 };

// using THING = struct {
//     char name[max_len_str];
//     unsigned weight;
// };

// using std::cin;
// using std::cout;

// void swap_struct(THING* a, THING* b) {
//     THING tmp = *a;
//     *a = *b;
//     *b = tmp;
// }

// void sort_struct(THING* things, size_t count) {
//     for (size_t i = 0; i < count; i++) {
//         for (size_t j = i; j < count; j++) {
//             if (things[i].weight < things[j].weight) swap_struct(&things[i], &things[j]);
//         }
//     }
// }

// int main() {
//     THING things[] = {{"карандаш", 20},  {"зеркальце", 100}, {"зонт", 500},    {"рубашка", 300},
//                       {"брюки", 1000},   {"бумага", 200},    {"молоток", 600}, {"пила", 400},
//                       {"удочка", 1200},  {"расческа", 40},   {"котелок", 820}, {"палатка", 5240},
//                       {"брезент", 2130}, {"спички", 10}};
//     size_t count = 14;

//     sort_struct(things, count);

//     unsigned weight;

//     cin >> weight;

//     weight *= 1000;

//     for (size_t i = 0; i < count; i++) {
//         if (weight && things[i].weight <= weight) {
//             cout << things[i].name << ' ';
//             weight -= things[i].weight;
//         }
//     }

//     return 0;
// }

// #include <iostream>

// using std::cout;

// int main() {
//     bool b_2 = false;
//     bool b_1 = true;
//     // bool b_3 = 10;
//     // bool b_4 = 5 - 5; //
//     // bool b_5 = b_1 & b_2;  // b_1, b_2 - булевы переменные
//     bool b_6 = b_1 | b_2;  // b_1, b_2 - булевы переменные

//     cout << b_1 << ' ' << b_2 << ' ' << b_6;
//     return 0;
// }

// #include <iostream>

// enum { max_len_numbers = 100 };

// using std::cout;

// int main() {
//     int numbers[max_len_numbers];
//     size_t count = 0;
//     bool fl_even = true;

//     while (scanf("%d", &numbers[count]) == 1 && numbers[count] != 0) {
//         fl_even *= (numbers[count] % 2 == 0);
//         count++;
//     }

//     cout << (fl_even ? "even" : "no");
//     return 0;
// }

// #include <iostream>

// enum { max_len_numbers = 100 };

// using std::cout;

// int main() {
//     int numbers[max_len_numbers];
//     size_t count = 0;
//     bool fl_even = false;

//     while (scanf("%d", &numbers[count]) == 1 && numbers[count] != 0) {
//         fl_even += (numbers[count] % 2 == 0);
//         count++;
//     }

//     cout << (fl_even ? "even" : "no");
//     return 0;
// }

// #include <iostream>

// bool positive(int x) { return x > 0; }

// using PTR_FUNC = bool (*)(int);

// bool all(const int* ar, size_t len, PTR_FUNC filter) {
//     for (size_t i = 0; i < len; i++) {
//         if (!filter(ar[i])) return false;
//     }
//     return true;
// }

// int main() {
//     const int numbers[] = {2, 3, 1, -10, 15};

//     PTR_FUNC filter = positive;

//     bool res = all(numbers, 5, filter);

//     std::cout << res;

//     return 0;
// }
// #include <iostream>
// #define RANGE_DOWN -0.5
// #define RANGE_UP 0.5

// using PTR_FUNC = bool (*)(double);

// bool range_out(double x) { return x < RANGE_DOWN || x > RANGE_UP; }

// bool any(const double* ar, size_t len, PTR_FUNC filter) {
//     for (size_t i = 0; i < len; i++) {
//         if (filter(ar[i])) return true;
//     }
//     return false;
// }

// int main() {
//     const double numbers[] = {0.1, 0.2, 0.3, -0.4, 1.4};

//     PTR_FUNC filter = range_out;

//     bool res = any(numbers, 5, filter);

//     std::cout << res;

//     return 0;
// }

// #include <iostream>

// int main() {
//     long ar[] = {2, 4, 8, 16, 3, 9, 27, 81, -10, -100, -1000};
//     size_t len = sizeof(ar) / sizeof(*ar);

//     // не проходит так как 0 элемент пропущен
//     // size_t count = 0;
//     // do {
//     //     std::cout << ar[++count] << " ";
//     // } while (count < len);

//     // ОК
//     // size_t count = 0;
//     // do {
//     //     std::cout << ar[count++] << " ";
//     // } while (count < len);

//     // OR
//     // size_t count = 0;
//     // while (count < len) printf("%d ", (int)ar[count++]);

//     // OK
//     // for (long x : ar) std::cout << x << " ";

//     // OK
//     // for (size_t i = 0; i < len; ++i) std::cout << ar[i] << " ";

//     // не проходит так как 0 элемент пропущен
//     // size_t count = 0;
//     // while (count < len) printf("%d ", (int)ar[++count]);

//     return 0;
// }

// #include <iostream>

// enum { matrix_size = 4 };

// using std::cin;
// using std::cout;

// int main() {
//     short matrix[matrix_size][matrix_size] = {0};

//     short *ptr_matrix = &(*matrix)[0];

//     size_t count = 0;

//     while (count < matrix_size * matrix_size && cin >> *(ptr_matrix + count)) count++;

//     for (size_t i = 0; i < matrix_size; i++) {
//         for (size_t j = 0; j < matrix_size; j++) {
//             cout << matrix[i][j] << (j + 1 == matrix_size ? "" : " ");
//         }
//         cout << (i + 1 == matrix_size ? "" : "\n");
//     }

//     return 0;
// }

// auto var_1{0.5f};
// auto var_2{0};
// auto var_3{245u};
// auto var_4(486L);
// auto var_5{4.86L};
// auto var_6('d');
// auto var_7 = (short)-5;

// const char symbol_f = 'f';
// const short* ptr_sh;
// int count = 0;
// const int& lnk = count;

// auto var_1 = symbol_f;
// auto var_2 = &symbol_f;
// auto var_3 = ptr_sh;
// auto var_4 = &count;
// auto var_5 = lnk;
// auto var_6 = *ptr_sh;

// #include <cmath>
// #include <iostream>

// enum { corners = 4 };

// struct point {
//     int x, y;
// };

// double distance(point* a, point* b) {
//     double result = sqrt(pow((a->x - b->x), 2) + pow((a->y - b->y), 2));
//     return result;
// }

// double giron_area(point* a, point* b, point* c) {
//     double ab = distance(a, b);
//     double ac = distance(a, c);
//     double bc = distance(b, c);
//     double p = (ab + ac + bc) / 2.0;
//     double result = sqrt(p * (p - ab) * (p - ac) * (p - bc));
//     return result;
// }

// double quadrangle_area(point* a, point* b, point* c, point* d) {
//     double result = giron_area(a, b, c) + giron_area(a, d, c);
//     return result;
// }

// double quadrangle_area_point(point* a, point* b, point* c, point* d, point* e) {
//     double result = giron_area(a, b, e) + giron_area(b, c, e) + giron_area(c, d, e) + giron_area(a, d, e);
//     return result;
// }

// bool in_area(point* a, point* b, point* c, point* d, point* e) {
//     bool result = (quadrangle_area_point(a, b, c, d, e) - quadrangle_area(a, b, c, d)) < 0.000001;
//     return result;
// }

// int main() {
//     point figure[corners];
//     point pt;

//     int count = 0;
//     while (count < corners && scanf("%d; %d", &figure[count].x, &figure[count].y) == 2) count++;

//     if (count != corners) {
//         puts("Неверное количество или формат входных данных.");
//         return 1;
//     }

//     if (scanf("%d; %d", &pt.x, &pt.y) != 2) {
//         puts("Неверное количество или формат входных данных.");
//         return 2;
//     }

//     bool result = in_area(&figure[0], &figure[1], &figure[2], &figure[3], &pt);

//     printf("%s", result ? "yes" : "no");

//     return 0;
// }

// const char symbol_f = 'f';
// const short* ptr_sh;
// int count = 0;
// const int& lnk = count;

// decltype(symbol_f) var_1 = 'd';
// decltype(&symbol_f) var_2;
// decltype(ptr_sh) var_3;
// decltype(&count) var_4 = &count;
// decltype(lnk) var_5 = count;

// int var{-54};
// int* ptr_v{&var};
// short marks[] = {4, 3, 5, 2, 5};

// int& lnk_8 = &ptr_v;  //
// int& lnk_4 = *ptr_v;
// short& lnk_7{marks[3]};
// int& lnk_2{&var};
// short& lnk_6{*marks};
// int& lnk_3(ptr_v);
// int& lnk_1 = var;
// short& lnk_5 = marks;

// const double pi = 3.1415;
// unsigned int width = 27;

// int &lnk_3 = width;
// double &lnk_2 = pi;
// const double &lnk_1 = pi;
// const unsigned int &lnk_5 = width;
// short &lnk_7 = -1;
// const short &lnk_6 = 100;
// unsigned int &lnk_4 = width;

// #include <iostream>

// enum { total_marks = 23 };

// using std::cin;
// using std::cout;
// using std::endl;

// int main() {
//     short marks[total_marks] = {0};
//     size_t count = 0;

//     while (count < total_marks && cin >> marks[count]) count++;

//     for (auto &i : marks) {
//         if (i < 3) i = 0;
//         cout << i << ' ';
//     }
//     cout << endl;

//     return 0;
// }
// #include <cmath>
// #include <iostream>

// struct POINT {
//     double x, y;
// };

// double get_length(const POINT& a, const POINT& b) {
//     double result = sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
//     return result;
// }

// using std::cin;
// using std::cout;
// using std::endl;

// int main() {
//     POINT a{-2.5, 7.8}, b{11.4, 43.2};

//     double result = get_length(a, b);

//     printf("%.2lf", result);

//     return 0;
// }

// #include <cmath>
// #include <iostream>

// struct point {
//     double x, y;
// };

// double get_length(const point& a, const point& b) {
//     double result = sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
//     return result;
// }

// double sq_tr(const point& a, const point& b, const point& c) {
//     double ab = get_length(a, b);
//     double bc = get_length(b, c);
//     double ac = get_length(a, c);
//     double p = (ab + bc + ac) / 2;
//     double res = sqrt(p * (p - ab) * (p - bc) * (p - ac));
//     return res;
// }

// using std::cin;
// using std::cout;
// using std::endl;

// int main() {
//     point a, b, c;

//     cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y;

//     double result = sq_tr(a, b, c);

//     printf("%.2lf", result);

//     return 0;
// }

// #include <cmath>
// #include <iostream>

// using std::max;
// using std::min;

// enum { corners = 4 };

// struct point {
//     int x, y;
// };

// struct min_max_point {
//     int min_x;
//     int max_x;
//     int min_y;
//     int max_y;
// };

// double get_length(const point& a, const point& b) {
//     double result = sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
//     return result;
// }

// double giron_area(const point& a, const point& b, const point& c) {
//     double ab = get_length(a, b);
//     double bc = get_length(b, c);
//     double ac = get_length(a, c);
//     double p = (ab + bc + ac) / 2;
//     double res = sqrt(p * (p - ab) * (p - bc) * (p - ac));
//     return res;
// }

// double quadrangle_area(const point& a, const point& b, const point& c, const point& d) {
//     double result = giron_area(a, b, c) + giron_area(a, d, c);
//     return result;
// }

// double quadrangle_area_point(const point& a, const point& b, const point& c, const point& d, const point&
// e) {
//     double result = giron_area(a, b, e) + giron_area(b, c, e) + giron_area(c, d, e) + giron_area(a, d, e);
//     return result;
// }

// bool in_area(point* figure, const int& x, const int& y) {
//     point a = {figure[0].x, figure[0].y};
//     point b = {figure[1].x, figure[1].y};
//     point c = {figure[2].x, figure[2].y};
//     point d = {figure[3].x, figure[3].y};
//     point e = {x, y};
//     bool result = (quadrangle_area_point(a, b, c, d, e) - quadrangle_area(a, b, c, d)) < 0.000001;
//     return result;
// }

// min_max_point min_max(point* figure) {
//     min_max_point res;

//     res.min_x = min(min(figure[0].x, figure[1].x), min(figure[2].x, figure[3].x));
//     res.max_x = max(max(figure[0].x, figure[1].x), max(figure[2].x, figure[3].x));
//     res.min_y = min(min(figure[0].y, figure[1].y), min(figure[2].y, figure[3].y));
//     res.max_y = max(max(figure[0].y, figure[1].y), max(figure[2].y, figure[3].y));

//     return res;
// }

// int point_counter(point* figure) {
//     min_max_point points = min_max(figure);

//     int count = 0;

//     for (int x = points.min_x; x <= points.max_x; x++) {
//         for (int y = points.min_y; y <= points.max_y; y++) {
//             if (in_area(figure, x, y)) count++;
//         }
//     }
//     return count;
// }

// int main() {
//     point figure[corners];

//     int count = 0;
//     while (count < corners && scanf("%d; %d", &figure[count].x, &figure[count].y) == 2) count++;

//     if (count != corners) {
//         puts("Неверное количество или формат входных данных.");
//         return 1;
//     }

//     int result = point_counter(figure);

//     std::cout << result << std::endl;

//     return 0;
// }

// #include <iostream>
// #include <string>

// std::string s_3{"Hello, C++"};

// std::string str;
// std::string s_5 = str;

// std::string s_7{"Sergey" + "Balakirev"};

// const std::string s_4("Hello, C++");

// std::string s1{"A"}, s2{"B"};
// std::string s_9 = s1 + s2;

// std::string str;
// const std::string s_7 = str;

// const std::string str;
// std::string s_6 = str;

// std::string s_1;

// std::string s_8{
//     "Sergey"
//     "Balakirev"};

// std::string s_10{'A'};

// const std::string s_2;

// #include <iostream>
// #include <string>

// using std::cin;
// using std::cout;
// using std::endl;
// using std::string;

// int main() {
//     string fname, lname;
//     cin >> fname >> lname;
//     string fio{fname + ", " + lname};

//     cout << fio << endl;
//     // __ASSERT_TESTS__

//     return 0;
// }

// #include <iostream>
// #include <string>

// using std::cin;
// using std::cout;
// using std::endl;
// using std::string;
// using std::to_string;  // для конвертации чисел в строки

// int main() {
//     int width, height;
//     cin >> width >> height;
//     string data_str{"Переменная width = " + to_string(width) + ", переменная height = " +
//     to_string(height)};

//     cout << data_str << endl;
//     // __ASSERT_TESTS__
//     return 0;
// }

// #include <iostream>
// #include <string>

// enum { chars_to_print = 4 };

// using std::cin;
// using std::cout;
// using std::endl;
// using std::string;

// int main() {
//     string msg;

//     getline(cin, msg);

//     for (size_t i = 0; i < chars_to_print; i++) {
//         putchar(msg[i]);
//     }

//     // __ASSERT_TESTS__
//     return 0;
// }
// #include <iostream>
// #include <string>

// enum { chars_to_print = 3 };

// using std::cin;
// using std::cout;
// using std::endl;
// using std::string;

// int main() {
//     string msg;

//     getline(cin, msg);

//     for (int i = 0; i < chars_to_print; i++) {
//         putchar(*(msg.cend() - i - 1));
//     }

//     // __ASSERT_TESTS__
//     return 0;
// }
// #include <iostream>
// #include <string>

// enum { max_cities = 10, min_chars = 5 };

// using std::cin;
// using std::cout;
// using std::endl;
// using std::string;

// int main() {
//     string cities[max_cities], res{""};

//     size_t count = 0;

//     while (count < max_cities && cin >> cities[count]) count++;

//     for (size_t i = 0; i < count; i++) {
//         if (cities[i].size() > min_chars) res += cities[i] + " ";
//     }

//     cout << res << endl;

//     // __ASSERT_TESTS__
//     return 0;
// }
// #include <iostream>
// #include <string>
// #define CHAR_TO_DEL '-'

// using std::cin;
// using std::cout;
// using std::endl;
// using std::string;

// int main() {
//     string str;
//     char res[100];
//     cin >> str;

//     size_t shift = 0;

//     for (size_t i = 0; i < str.size(); i++) {
//         while (str[i + shift] == CHAR_TO_DEL && str[i + 1 + shift] == CHAR_TO_DEL) shift++;
//         res[i] = str[i + shift];
//     }

//     printf(res);

//     // cout << res << res.size() << endl;

//     return 0;
// }
// #include <iostream>
// #include <string>
// #define CHAR_TO_DEL '-'

// using std::cin;
// using std::cout;
// using std::endl;
// using std::string;

// int main() {
//     string str;
//     cin >> str;

//     size_t shift = 0;

//     for (size_t i = 0; i < str.size(); i++) {
//         while (str[i + shift] == CHAR_TO_DEL && str[i + 1 + shift] == CHAR_TO_DEL) shift++;
//         str[i] = str[i + shift];
//     }

//     str.resize(str.size() - shift);

//     cout << str << endl;

//     return 0;
// }

// #include <fstream>

// using std::ios;

// int main() {
//     std::ifstream ifs;
//     ifs.open("study/my_marks.dat");

//     ifs.close();

//     return 0;
// }

// #include <fstream>

// using std::ios;

// int main() {
//     std::ofstream ofs;
//     // здесь будет располагаться введенная команда

//     ofs.open("my_table.txt", ios::app);

//     ofs.is_open();

//     ofs.close();

//     return 0;
// }

// #include <fstream>
// #include <iostream>

// using std::ifstream;
// using std::ofstream;

// int main() {
//     ofstream fs("my_marks.dat");

//     if (!fs) {
//         std::cout << "Невозможно открыть файл";
//         return 0;
//     }

//     short marks[] = {3, 3, 2, 3, 4, 3, 2};
//     for (size_t i = 0; i < sizeof(marks) / sizeof(*marks); ++i) fs << marks[i] << "; ";

//     fs.close();

//     return 0;
// }

// #include <fstream>
// #include <iostream>

// using std::ifstream;
// using std::ofstream;

// int main() {
//     ifstream fs("my_marks.dat");

//     if (!fs) {
//         std::cout << "Невозможно открыть файл";
//         return 0;
//     }

//     short marks[10] = {0};
//     int count = 0;
//     while (count < 10 && fs >> marks[count]) count++;

//     fs.close();

//     for (const int& x : marks) std::cout << x << " ";

//     return 0;
// }

// #include <fstream>
// #include <iostream>

// using std::ifstream;
// using std::ofstream;

// int main() {
//     short sh = 10;
//     double d = -0.56;
//     char ch = 'a';

//     ofstream ofs("my_data.dat");

//     if (!ofs) {
//         std::cout << "Невозможно открыть файл";
//         return 0;
//     }

//     ofs << sh << " " << d << " " << ch;

//     ofs.close();

//     return 0;
// }

// #include <fstream>
// #include <iostream>

// using std::ifstream;
// using std::ofstream;

// int main() {
//     short sh;
//     double d;
//     char ch;

//     ifstream ifs("my_data.dat");

//     if (!ifs) {
//         std::cout << "Невозможно открыть файл";
//         return 0;
//     }

//     ifs >> sh >> d >> ch;

//     ifs.close();

//     return 0;
// }

// #include <fstream>
// #include <iostream>

// using std::ios;

// int main() {
//     short marks[] = {3, 3, 4, 3, 2, 2};

//     std::ofstream ofs("my_data.dat", ios::out | ios::binary);

//     if (!ofs) {
//         std::cout << "Невозможно открыть файл";
//         return 1;
//     }

//     ofs << "hello" << std::endl;
//     ofs.write((char *)marks, sizeof(marks));

//     ofs.close();
//     return 0;
// }

// #include <fstream>
// #include <iostream>

// using std::ios;

// int main() {
//     short marks[6];

//     std::ifstream ifs("my_data.dat", ios::in | ios::binary);

//     // здесь будет располагаться записанная команда (оператор)
//     ifs.read((char *)marks, sizeof(marks));

//     for (auto x : marks) std::cout << x << " ";

//     ifs.close();

//     return 0;
// }

// #include <fstream>
// #include <iostream>

// using std::ios;

// int main() {
//     double digits[10] = {0.5, 0.3, 0.6};
//     int count = 3;

//     std::ofstream ofs("digits.dat", ios::out | ios::binary);

//     // здесь будет располагаться записанная команда (оператор)
//     ofs.write((char *)digits, sizeof(double) * count);

//     ofs.close();

//     return 0;
// }

// #include <fstream>
// #include <iostream>

// struct car {
//     char model[50];
//     unsigned short max_speed;
//     double power;
//     unsigned int weight;
// };

// int main() {
//     car my_auto = {"BMW X5", 240, 215.6, 1743};
//     std::ofstream ofs("autos.db", std::ios::out | std::ios::binary);

//     // здесь будет располагаться записанная команда (оператор)
//     ofs.write((char *)&my_auto, sizeof(car));

//     ofs.close();
//     return 0;
// }

// #include <fstream>
// #include <iostream>

// struct car {
//     char model[50];
//     unsigned short max_speed;
//     double power;
//     unsigned int weight;
// };

// int main() {
//     car my_auto;
//     std::ifstream ifs("autos.db", std::ios::in | std::ios::binary);

//     // здесь будет располагаться записанная команда (оператор)
//     ifs.read((char *)&my_auto, sizeof(car));

//     ifs.close();
//     return 0;
// }

// #include <stdio.h>

// int main(void) {
//     int n = 7;
//     while (n-- > 0) {
//         int n = 5;
//         printf("%d\n", n);
//         n++;
//     }

//     printf("%d\n", n);

//     return 0;
// }

// #include <stdio.h>

// int func_overload(int x) { return 0; }

// int func_overload(int x, int y) { return 1; }

// // double func_overload(int x) { return 3; }

// int func_overload(short x) { return 5; }

// int func_overload(double x) { return 2; }

// // int func_overload(const int x) { return 6; }

// // int func_overload(int y) { return 4; }

// int func_overload(unsigned int x) { return 7; }

// int main(void) { return 0; }

// #include <stdio.h>

// int perimetr(unsigned a, unsigned b) { return 2 * (a + b); }

// float perimetr(float a, float b) { return 2.0f * (a + b); }

// int main(void) {
//     int res_1 = perimetr(10, 20);
//     float res_2 = perimetr(10, 20);
//     float res_3 = perimetr(10.0f, 20.0f);
//     int res_4 = perimetr(10u, 20u);
//     float res_5 = perimetr(10u, 20u);
//     float res_6 = perimetr(10.0, 20.0);
//     double res_7 = perimetr(10.0f, 20.0f);
//     return 0;
// }

// int get_perimetr(int a, int b, int c) {
//     int res = a + b + c;
//     return res;
// }
// int get_perimetr(int a, int b) {
//     int res = (a + b) * 2;
//     return res;
// }

// #include <cmath>
// #include <iostream>

// double get_square(int a, int b, int c) {
//     double p = (a + b + c) / 2.0;
//     double res = sqrt(p * (p - a) * (p - b) * (p - c));
//     return res;
// }

// int get_square(int a, int b) {
//     int res = a * b;
//     return res;
// }

// int main() {
//     int a, b, c, d, e;
//     std::cin >> a >> b >> c >> d >> e;

//     double tr_sq = get_square(a, b, c);
//     int qr_sq = get_square(d, e);

//     printf("%.1lf %.1lf", tr_sq, (double)qr_sq);

//     return 0;
// }
// #include <cmath>
// #include <iostream>

// double min2(double a, double b) { return a < b ? a : b; }

// int min2(int a, int b) { return a < b ? a : b; }

// int main() {
//     int a;
//     double b;

//     std::cin >> a >> b;

//     double result = min2((double)a, b);

//     printf("%.1lf", result);

//     return 0;
// }

// #ifdef __cplusplus
// #include <iostream>
// #else
// #include <stdio.h>
// #endif

// double mean_2(int a, int b) {
//     double res = (a + b) / (double)2;
//     return res;
// }

// int main() {
//     int a, b;

//     scanf("%d %d", &a, &b);

//     double result = mean_2(a, b);

//     printf("%.1lf", result);

//     return 0;
// }

// #include <iomanip>
// #include <iostream>

// enum { max_ar_len = 100 };

// double get_mean(const short* d, const size_t len) {
//     double res = 0;
//     for (size_t i = 0; i < len; i++) {
//         res += d[i];
//     }
//     return res / len;
// }
// double get_mean(const int* d, const size_t len) {
//     double res = 0;
//     for (size_t i = 0; i < len; i++) {
//         res += d[i];
//     }
//     return res / len;
// }
// double get_mean(const double* d, const size_t len) {
//     double res = 0;
//     for (size_t i = 0; i < len; i++) {
//         res += d[i];
//     }
//     return res / len;
// }

// int main() {
//     short ar[max_ar_len];
//     size_t count = 0;

//     while (count < max_ar_len && std::cin >> ar[count]) count++;

//     double result = get_mean(ar, count);

//     std::cout << std::fixed << std::setprecision(2) << result << std::endl;

//     return 0;
// }

// #include <iostream>

// using calc_type = enum { calc_perimetr, calc_square };

// int get_rect_value(int w, int h, calc_type type = calc_perimetr) {
//     int res = 0;
//     switch (type) {
//         case calc_square:
//             res = w * h;
//             break;

//         case calc_perimetr:
//             res = (w + h) * 2;
//             break;

//         default:
//             puts("Invalid type");
//             break;
//     }
//     return res;
// }

// int main() {
//     int a, b;

//     std::cin >> a >> b;

//     int result = get_rect_value(a, b);

//     std::cout << result << std::endl;

//     return 0;
// }
// #include <cstring>
// #include <iostream>
// #include <string>

// bool check_password(char* str, const char* chars = "$%!?@#") {
//     bool res = (strlen(str) >= 8 && strpbrk(str, chars) != nullptr);
//     return res;
// }

// int main() {
//     char str[100];

//     scanf("%s", str);

//     bool result = check_password(str);

//     std::cout << (result ? "yes" : "no") << std::endl;

//     return 0;
// }

// #include <iostream>
// #include <string>

// using std::cin;
// using std::cout;
// using std::string;

// bool check_password(string password, string chars = "$%!?@#") {
//     return password.size() >= 8 && password.find_first_of(chars) != string::npos;
// }

// int main() {
//     string s;
//     cin >> s;

//     check_password(s) ? cout << "yes" : cout << "no";

//     return 0;
// }

// #include <string.h>

// #include <iostream>
// #include <string>

// enum { tag_const = 5 };  // посчитаем <...> </...>

// std::string char_copy(char* src) {
//     std::string dest = "";
//     size_t count = strlen(src);
//     for (size_t i = 0; i < count; i++) {
//         dest += src[i];
//     }
//     return dest;
// }
// void string_copy(char* dest, std::string src) {
//     for (char ch : src) {
//         *dest++ = ch;
//     }
//     *dest = '\0';
//     return;
// }

// void set_tag(char str[], int len, char tag[] = "h1") {
//     if ((int)(strlen(str) + strlen(tag) + tag_const) < len) {
//         std::string res{"<" + char_copy(tag) + ">" + char_copy(str) + "</" + char_copy(tag) + ">"};
//         string_copy(str, res);
//     }

//     return;
// }

// int main() {
//     std::string title, tag;

//     getline(std::cin, title);
//     getline(std::cin, tag);

//     char char_title_1[100];
//     char char_title_2[100];
//     char char_tag[100];
//     string_copy(char_title_1, title);
//     string_copy(char_title_2, title);
//     string_copy(char_tag, tag);

//     set_tag(char_title_1, 100);
//     set_tag(char_title_2, 100, char_tag);

//     std::cout << char_title_1 << std::endl;
//     std::cout << char_title_2 << std::endl;

//     return 0;
// }
// #include <string.h>

// #include <iostream>
// #include <string>

// enum { tag_const = 5 };  // посчитаем <...> </...>

// void set_tag(char str[], int len, char tag[20] = "h1") {
//     if ((int)(strlen(str) + strlen(tag) + tag_const) < len) {
//         char res[100];
//         sprintf(res, "<%s>%s</%s>", tag, str, tag);
//         strcpy(str, res);
//     }

//     return;
// }

// int main() {
//     std::string title, tag;

//     getline(std::cin, title);
//     getline(std::cin, tag);

//     char char_title_1[100];
//     char char_title_2[100];
//     char char_tag[100];

//     strcpy(char_title_1, title.data());
//     strcpy(char_title_2, title.data());
//     strcpy(char_tag, tag.data());

//     set_tag(char_title_1, 100);
//     set_tag(char_title_2, 100, char_tag);

//     std::cout << char_title_1 << std::endl;
//     std::cout << char_title_2 << std::endl;

//     return 0;
// }

// #include <iostream>

// using calc_type = enum { calc_perimetr, calc_square };

// int get_rect(int w, int h, calc_type type = calc_perimetr) {
//     int res = 0;
//     switch (type) {
//         case calc_square:
//             res = w * h;
//             break;
//         default:
//             res = (w + h) * 2;
//             break;
//     }
//     return res;
// }
// double get_rect(double w, double h, calc_type type = calc_perimetr) {
//     double res = 0;
//     switch (type) {
//         case calc_square:
//             res = w * h;
//             break;
//         default:
//             res = (w + h) * 2;
//             break;
//     }
//     return res;
// }

// int main() {
//     int a, b;
//     double c, d;

//     std::cin >> a >> b >> c >> d;

//     int result_1 = get_rect(a, b);
//     double result_2 = get_rect(c, d);

//     std::cout << result_1 << "\n" << result_2 << std::endl;

//     return 0;
// }
// #include <iostream>

// using type_sort = enum { sort_asc, sort_desc };

// void swap(short& a, short& b) {
//     short tmp = a;
//     a = b;
//     b = tmp;
//     return;
// }

// int sort(short* ar, size_t len, type_sort type = sort_asc) {
//     int res = 0;
//     int cpy[len];
//     for (size_t i = 0; i < len; i++) {
//         cpy[i] = ar[i];
//     }
//     for (size_t i = 0; i < len; i++) {
//         for (size_t j = i + 1; j < len; j++) {
//             if (type == sort_asc && ar[i] > ar[j]) {
//                 swap(ar[i], ar[j]);
//             }
//             if (type == sort_desc && ar[i] < ar[j]) {
//                 swap(ar[i], ar[j]);
//             }
//         }
//     }
//     for (size_t i = 0; i < len; i++) {
//         if (cpy[i] != ar[i]) res++;
//     }

//     return res;
// }

// int main() {
//     short ar[] = {-5, 4, 10, 0, -100, -1, -2, 98};

//     int result = sort(ar, sizeof(ar) / sizeof(ar[0]));

//     std::cout << result << std::endl;

//     return 0;
// }

// #include <algorithm>
// #include <iostream>

// enum type_sort { sort_asc, sort_desc };

// int sort(short* ar, unsigned len, type_sort type = sort_asc) {
//     short* b_arr = new short[len];
//     std::copy_n(ar, len, b_arr);
//     if (type)
//         std::sort(ar, ar + len, [](short a, short b) { return a > b; });
//     else
//         std::sort(ar, ar + len);
//     int cnt = 0;
//     for (size_t i = 0; i < len; i++)
//         if (ar[i] != b_arr[i]) cnt++;
//     delete[] b_arr;
//     return cnt;
// }

// int main() {
//     short ar[] = {-5, 4, 10, 0, -100, -1, -2, 98};

//     int result = sort(ar, sizeof(ar) / sizeof(ar[0]));

//     std::cout << result << std::endl;

//     return 0;
// }

// #include <iostream>

// inline int get_max_3(int a, int b, int c) {
//     if (a > b) {
//         if (a > c) return a;
//     } else {
//         if (b > c) return b;
//     }
//     return c;
// }

// int main() {
//     int a, b, c;

//     std::cin >> a >> b >> c;

//     int result = get_max_3(a, b, c);

//     std::cout << result << std::endl;
//     return 0;
// }

// #include <iostream>

// enum { max_len = 10 };

// inline int sum_ar_int(int ar[], size_t count) {
//     int res = 0;
//     for (size_t i = 0; i < count; i++) {
//         res += ar[i];
//     }
//     return res;
// }

// int main() {
//     int ar[max_len];

//     for (size_t i = 0; i < max_len; i++) {
//         std::cin >> ar[i];
//     }

//     int result = sum_ar_int(ar, max_len);

//     std::cout << result << std::endl;
//     return 0;
// }
// #include <iostream>

// enum { max_len = 10 };

// inline void range(int ar[], int count, int start, int stop, int step) {
//     for (int i = 0; i < count; i++) {
//         int value = start + i * step;
//         if (value < stop)
//             ar[i] = value;
//         else
//             break;
//     }
//     return;
// }

// int main() {
//     int ar[max_len] = {0}, a, b, c;

//     std::cin >> a >> b >> c;

//     range(ar, max_len, a, b, c);

//     for (size_t i = 0; i < max_len; i++) {
//         std::cout << ar[i] << " ";
//     }

//     std::cout << std::endl;
//     return 0;
// }

// #include <iostream>

// enum { max_size = 20 };

// bool is_even(int num) { return num % 2 == 0; }

// using fn = bool (*)(int);

// fn even = is_even;

// int sum_ar(const int *ar, size_t len_ar, fn even) {
//     int res = 0;
//     for (size_t i = 0; i < len_ar; i++) {
//         if (even(ar[i])) res += ar[i];
//     }
//     return res;
// }

// int main(void) {
//     int marks[max_size] = {0};
//     int x;
//     size_t count = 0;
//     while (count < max_size && std::cin >> x) {
//         marks[count] = x;
//         count++;
//     }

//     int result = sum_ar(marks, count, even);

//     std::cout << result << std::endl;

//     return 0;
// }

// #include <iostream>

// enum { max_size = 20 };

// void reverse(short* ar, int count) {
//     for (int i = 0; i < count / 2; i++) {
//         short tmp = ar[i];
//         ar[i] = ar[count - i - 1];
//         ar[count - i - 1] = tmp;
//     }
// }

// int main(void) {
//     short digs[max_size];
//     int count = 0;
//     while (count < max_size && std::cin >> digs[count]) count++;

//     reverse(digs, count);

//     for (int i = 0; i < count; i++) {
//         std::cout << digs[i] << " ";
//     }

//     return 0;
// }

// const char symbol_f = 'f';
// const short* ptr_sh;
// int count = 0;
// const int& lnk = count;

// auto var_1 = symbol_f;
// auto var_2 = &symbol_f;
// auto var_3 = ptr_sh;
// auto var_4 = &count;
// auto var_5 = lnk;
// auto var_6 = *ptr_sh;

// #include <iostream>

// int main(void) {
//     // auto lmd_2 = [](const char* msg) { std::cout << msg; };
//     // lmd_2("Hello");
//     // auto rec = [](int x) {
//     //     if (x < 10) rec(x - 1);
//     // };

//     // rec(2);
//     // auto r = [](int x, int y = 0) { return x + y; };
//     // r(1);
//     // auto lmd = [](int a, int b) { return 2 * (a + b); };
//     // lmd(1, 2);
//     // auto lmd_3 = [](int a, int b, int c) {
//     //     int p = a + b + c;
//     //     return p;
//     // };
//     // auto f = []() { return -1; };
//     // auto f = [](int x) { return (x < 0) ? -x : x; };
//     // auto f = [](double a) { (a > 0.0 && a < 10.0) ? std::cout << "yes" : std::cout << "no"; }(5);

//     return 0;
// }

// #include <cmath>
// #include <iostream>

// int main(void) {
//     int a, b, c;
//     std::cin >> a >> b >> c;

//     auto sq_tr = [](int a, int b, int c) {
//         double p = (a + b + c) / 2.0;
//         return sqrt(p * (p - a) * (p - b) * (p - c));
//     };

//     printf("%.2lf", sq_tr(a, b, c));

//     // __ASSERT_TESTS__
//     return 0;
// }
// #include <cmath>
// #include <iostream>

// using fn = bool (*)(int);

// int main(void) {
//     fn func_filter[] = {[](int x) { return x % 2 == 0; }, [](int x) { return x < 0; },
//                         [](int x) { return x > 0; }};

//     int a;

//     std::cin >> a;

//     printf("%d", func_filter[1](a));

//     // __ASSERT_TESTS__
//     return 0;
// }

// #include <iostream>

// enum { max_length_ar = 20 };
// using filter_func = bool (*)(short);

// void remove_elem(short* ar, int& len, filter_func filter) {
//     int shift = 0;
//     for (int i = 0; i + shift < len; i++) {
//         while (filter(ar[i + shift])) shift++;
//         ar[i] = ar[i + shift];
//         // printf("%d ", ar[i]);
//     }
//     len -= shift;
// }

// int main(void) {
//     short marks[max_length_ar] = {0};
//     int count = 0;
//     while (count < max_length_ar && std::cin >> marks[count]) count++;

//     remove_elem(marks, count, [](short x) { return x < 3; });

//     for (int i = 0; i < count; i++) {
//         std::cout << marks[i] << " ";
//     }
//     std::cout << std::endl;

//     return 0;
// }

// #include <iostream>

// enum { max_length_ar = 20 };
// using filter_func = bool (*)(int);

// int sum_elem(const int* ar, size_t len, filter_func filter) {
//     int res = 0;
//     for (size_t i = 0; i < len; i++) {
//         if (filter(ar[i])) res += ar[i];
//     }
//     return res;
// }

// int main(void) {
//     int marks[max_length_ar] = {0};
//     int count = 0;
//     while (count < max_length_ar && std::cin >> marks[count]) count++;

//     int result = sum_elem(marks, (size_t)count, [](int x) -> bool { return x % 6 == 0; });

//     std::cout << result << std::endl;

//     return 0;
// }
// #include <iostream>

// enum { max_length_ar = 20 };
// using filter_func = bool (*)(int, int);

// int sum_elem(const int* ar, size_t len, filter_func filter) {
//     int res = 0;
//     for (size_t i = 1; i < len; i++) {
//         if (filter(ar[i - 1], ar[i])) res += ar[i];
//     }
//     return res;
// }

// int main(void) {
//     int marks[max_length_ar] = {0};
//     int count = 0;
//     while (count < max_length_ar && std::cin >> marks[count]) count++;

//     int result =
//         sum_elem(marks, (size_t)count, [](int a, int b) -> bool { return a % 2 == 0 && b % 3 == 0; });

//     std::cout << result << std::endl;

//     return 0;
// }

// #include <iostream>

// int main(void) {
//     int ar[10];
//     int size_ar = sizeof(ar);

//     return 0;
// }

// #include <iostream>

// int main(void) {
//     char msg[] = "hello";
//     int count = 0;
//     int& lnk = count;
//     char* ptr = msg;

//     auto lmd_1 = [msg, count, lnk, ptr]() { return count + 1; };
//     auto lmd_5 = [ptr](int step) { *ptr += step; };
//     auto lmd_2 = [=]() { std::cout << msg; };
//     auto lmd_7 = [lnk](int step) { lnk += step; };
//     auto lmd_3 = [&count](int step) { count += step; };
//     auto lmd_4 = [&lnk](int step) { lnk += step; };
//     auto lmd_6 = [*ptr](int step) { *ptr += step; };

//     return 0;
// }

// #include <iostream>

// int main(void) {
//     int count = 1;
//     int& lnk = count;

//     auto r = [lnk](int step) mutable { lnk += step; };

//     r(5);
//     std::cout << count << std::endl;

//     return 0;
// }

// #include <iostream>

// int main(void) {
//     int w, h;
//     std::cin >> w >> h;

//     auto sum_ab = [w, h]() { return w + h; };

//     int result = sum_ab();

//     std::cout << result << std::endl;

//     // __ASSERT_TESTS__
//     return 0;
// }

// #include <iostream>
// #include <string>

// void get_line(char* buff, size_t max_buff) {
//     std::string line;
//     getline(std::cin, line);

//     int i = 0;
//     for (; i < line.length() && i < max_buff - 1; ++i) buff[i] = line[i];
//     buff[i] = '\0';
// }

// int main(void) {
//     char str[100];
//     //  get_line(str, sizeof(str));

//     auto gl = [&str]() {
//         size_t max_buff = sizeof(str);
//         std::string line;
//         getline(std::cin, line);

//         size_t i = 0;
//         for (; i < line.length() && i < max_buff - 1; ++i) str[i] = line[i];
//         str[i] = '\0';
//     };

//     gl();

//     std::cout << str << std::endl;
//     return 0;
// }

#include <cmath>
#include <iostream>

enum { size_pole = 10 };

int is_verify(char (*pg)[size_pole], int x, int y) {
    for (int i = -1; i <= 1; ++i)
        for (int j = -1; j <= 1; ++j) {
            int xx = x + i, yy = y + j;
            if (xx < 0 || xx >= size_pole || yy < 0 || yy >= size_pole) continue;
            if (pg[xx][yy] == '*') return 0;
        }
    return 1;
}

int main(void) {
    char pg[size_pole][size_pole] = {0};

    auto is_v = [&pg](int x, int y) {
        for (int phi = 0; phi < 360; phi += 45) {
            int i = round(cos(phi * 3.14159265 / 180));
            int j = round(sin(phi * 3.14159265 / 180));
            int xx = x + i, yy = y + j;
            if (xx < 0 || xx >= size_pole || yy < 0 || yy >= size_pole) continue;
            if (pg[xx][yy] == '*') return 0;
        }
        return 1;
    };

    int mines = 0;
    do {
        int i = rand() % size_pole;
        int j = rand() % size_pole;
        if (is_v(i, j)) {
            pg[i][j] = '*';
            mines++;
        }
    } while (mines < 12);

    //----------- вывод поля в консоль ---------------------------------
    for (int i = 0; i < size_pole; ++i) {
        for (int j = 0; j < size_pole; ++j) printf("%c ", (pg[i][j] == 0) ? '#' : '*');
        putchar('\n');
    }
    //----------- завершение вывода поля в консоль ----------------------

    // __ASSERT_TESTS__
    return 0;
}