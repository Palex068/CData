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