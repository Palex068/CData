// #include <iostream>

// struct vector3D {
//     double x, y, z;

//     double get_x() { return this->x; }
//     double get_y() { return y; }
//     static double norm2(double a, double b) { return a * a + b * b; }
// };

// int main(void) {
//     vector3D v1{0.5, 2.0, -5.4};

//     std::cout << v1.get_x() << std::endl;
//     std::cout << v1.norm2(1, 2) << std::endl;

//     return 0;
// }
// #include <iostream>

// struct volume {
//     double width, height, depth;
//     double get_volume() { return width * height * depth; }
// };

// int main(void) {
//     volume data;

//     std::cin >> data.width >> data.height >> data.depth;
//     double result = data.get_volume();
//     std::cout << result << std::endl;

//     return 0;
// }

// #include <iostream>
// #include <string>

// using std::cin;
// using std::cout;
// using std::endl;
// using std::getline;
// using std::string;

// enum { lib_size = 10 };
// struct book {
//     string title;
//     string author;
//     int price;
//     int npages;
//     double price_per_page() { return price / (double)npages; }
// };

// int main(void) {
//     book lib[lib_size];
//     size_t count = 0;
//     while (count < lib_size) {
//         if (getline(cin, lib[count].title)) {
//             getline(cin, lib[count].author);
//             cin >> lib[count].price >> lib[count].npages;
//             cout << (count == 0 ? "" : " ") << lib[count].price_per_page();
//             count++;
//         } else {
//             cout << endl;
//             break;
//         }
//     }

//     return 0;
// }

// #include <cmath>
// #include <iostream>

// enum { lib_size = 10 };
// struct vector4D {
//     double x, y, z, t;
//     void read_data(FILE* stream, char sep = ' ') {
//         fscanf(stream, "%lf %c %lf %c %lf %c %lf", &x, &sep, &y, &sep, &z, &sep, &t);
//         return;
//     }
//     double length() { return sqrt(x * x + y * y + z * z + t * t); }
// };

// int main(void) {
//     vector4D v1, v2;
//     char sep = ' ';
//     v1.read_data(stdin, sep);
//     v2.read_data(stdin, sep);

//     printf("%.3lf %.3lf", v1.length(), v2.length());

//     return 0;
// }

// #include <iostream>

// struct tag_price {
//     char name[100];
//     unsigned int rubs;
//     unsigned char kops;
//     unsigned int foreign_key;
// };
// tag_price price_100{"123", 1, 2, 3};

// int main(void) {
//     tag_price pr = price_100;

//     printf("%s %d %d %d", pr.name, pr.rubs, pr.kops, pr.foreign_key);
//     return 0;
// }

// #include <iostream>

// struct tag_time {
//     unsigned char hours;
//     unsigned char minutes;
//     unsigned char seconds;
//     char* get_time(char* str, size_t max_length) {
//         if (max_length > 9) {
//             sprintf(str, "%02d:%02d:%02d", hours, minutes, seconds);
//         }
//         return str;
//     }
//     static tag_time sum_time(const tag_time& t1, const tag_time& t2) {
//         tag_time res;
//         unsigned char over = 0;
//         res.seconds = time_sum(t1.seconds, t2.seconds, over, 60);
//         res.minutes = time_sum(t1.minutes, t2.minutes, over, 60);
//         res.hours = time_sum(t1.hours, t2.hours, over, 24);
//         return res;
//     }
//     static unsigned char time_sum(unsigned char t1, unsigned char t2, unsigned char& over,
//                                   unsigned char limit) {
//         unsigned char res = (t1 + t2 + over) % limit;
//         over = (t1 + t2 + over) / limit;
//         return res;
//     }
// };

// void read_time(tag_time& tm) {
//     int hours;
//     int minutes;
//     int seconds;
//     std::cin >> hours >> minutes >> seconds;
//     tm.hours = hours;
//     tm.minutes = minutes;
//     tm.seconds = seconds;
// }

// int main(void) {
//     tag_time tm1;
//     tag_time tm2;

//     read_time(tm1);
//     read_time(tm2);

//     tag_time time_res;

//     time_res = tag_time::sum_time(tm1, tm2);

//     char str[10];
//     time_res.get_time(str, sizeof(str));
//     std::cout << str << std::endl;
//     // __ASSERT_TESTS__
//     return 0;
// }

// #include <iostream>

// enum { total_points = 100 };

// struct tag_point_3d {
//     int x, y, z;
// };

// int main(void) {
//     tag_point_3d points[total_points];

//     size_t total = 0;

//     while (total < total_points &&
//            scanf("%d %d %d", &points[total].x, &points[total].y, &points[total].z) == 3)
//         total++;

//     printf("%d %d %d", points[0].x, points[0].y, points[0].z);

//     // __ASSERT_TESTS__
//     return 0;
// }

// #include <iostream>

// struct thing {
//    private:
//     unsigned int id;
//     double price;
//     double weight;

//    public:
//     unsigned get_id() { return this->id; }
//     void get_data(double& price, double& weight) {
//         price = this->price;
//         weight = this->weight;
//         return;
//     }
//     void set_data(unsigned id, double price, double weight) {
//         this->id = id;
//         this->price = price;
//         this->weight = weight;
//         return;
//     }
// };

// #include <iostream>

// struct point {
//    private:
//     int x, y;

//    public:
//     int get_x() { return this->x; }
//     int get_y() { return this->y; }
//     void get_coords(int& x, int& y) {
//         x = this->x;
//         y = this->y;
//         return;
//     }
//     void set_coords(int x, int y) {
//         this->x = x;
//         this->y = y;
//         return;
//     }
//     static point sum(point& p1, point& p2) {
//         point res;
//         res.set_coords(p1.get_x() + p2.get_x(), p1.get_y() + p2.get_y());
//         return res;
//     }
// };

// int main(void) {
//     point p1, p2;
//     int x1, y1, x2, y2;
//     std::cin >> x1 >> y1 >> x2 >> y2;

//     p1.set_coords(x1, y1);
//     p2.set_coords(x2, y2);

//     point res = point::sum(p1, p2);

//     printf("%d %d", res.get_x(), res.get_y());

//     return 0;
// }

// #include <iostream>

// enum data_type { data_none = 1, data_int, data_double };

// struct point {
//    private:
//     enum { max_coords = 3 };

//     union {
//         int v_int;
//         double v_double;
//     } coords[max_coords];

//     data_type type = data_none;

//    public:
//     void set_coords(int x, int y, int z) {
//         this->coords[0].v_int = x;
//         this->coords[1].v_int = y;
//         this->coords[2].v_int = z;
//         this->type = data_int;
//     }
//     void set_coords(double x, double y, double z) {
//         this->coords[0].v_double = x;
//         this->coords[1].v_double = y;
//         this->coords[2].v_double = z;
//         this->type = data_double;
//     }
//     data_type get_type() { return type; }

//     int get_size() { return max_coords; }

//     bool get_coords(int& x, int& y, int& z) {
//         if (type == data_int) {
//             x = this->coords[0].v_int;
//             y = this->coords[1].v_int;
//             z = this->coords[2].v_int;
//             return true;
//         }
//         return false;
//     }
//     bool get_coords(double& x, double& y, double& z) {
//         if (type == data_double) {
//             x = this->coords[0].v_double;
//             y = this->coords[1].v_double;
//             z = this->coords[2].v_double;
//             return true;
//         }
//         return false;
//     }
// };

// int main(void) {
//     point pt;
//     pt.set_coords(5, -8, 34);

//     if (pt.get_type() == data_int) {
//         int x, y, z;
//         pt.get_coords(x, y, z);
//         printf("%d %d %d", x, y, z);
//     }
//     if (pt.get_type() == data_double) {
//         double xd, yd, zd;
//         pt.get_coords(xd, yd, zd);
//         printf("%.1lf %.1lf %.1lf", xd, yd, zd);
//     }

//     // __ASSERT_TESTS__
//     return 0;
// }

// #include <iostream>

// enum { total_points = 128 };

// struct tag_point {
//     float x, y;
// };

// int main(void) {
//     tag_point ps[total_points];
//     double mean_x = 0, mean_y = 0;

//     for (size_t i = 0; i < total_points; i++) {
//         ps[i].x = (float)(rand()) / RAND_MAX * (200) - 100;
//         mean_x += ps[i].x;
//         ps[i].y = (float)(rand()) / RAND_MAX * (200) - 100;
//         mean_y += ps[i].y;
//     }
//     mean_x /= total_points;
//     mean_y /= total_points;
//     // __ASSERT_TESTS__
//     return 0;
// }

// #include <iostream>

// struct money {
//    private:
//     int total_money;

//    public:
//     money() { total_money = 0; }
//     money(int x) { total_money = x; }
//     int get_money() { return total_money; }
//     void set_money(int volume) { total_money = volume; }
// };

// int main(void) {
//     money rubs(100);
//     std::cout << rubs.get_money() << std::endl;
//     // __ASSERT_TESTS__
//     return 0;
// }

// #include <iostream>

// struct triangle {
//    private:
//     int a, b, c;

//    public:
//     triangle() { a = 0, b = 0, c = 0; }
//     triangle(int a, int b, int c) {
//         this->a = a;
//         this->b = b;
//         this->c = c;
//     }
//     bool is_triangle() { return ((a + b) > c) * ((a + c) > b) * ((c + b) > a); }
//     void get_lengths(int& a, int& b, int& c) {
//         a = this->a;
//         b = this->b;
//         c = this->c;
//     }
//     void set_lengths(int a, int b, int c) {
//         this->a = a;
//         this->b = b;
//         this->c = c;
//     }
// };

// int main(void) {
//     triangle tr_1;
//     triangle tr_2(7, 4, 8);

//     // __ASSERT_TESTS__
//     return 0;
// }

// #include <cmath>
// #include <iostream>

// struct point3D {
//    private:
//     int x, y, z;

//    public:
//     point3D() { x = 0, y = 0, z = 0; }
//     point3D(int x, int y, int z) {
//         this->x = x;
//         this->y = y;
//         this->z = z;
//     }
//     void get_coords(int& x, int& y, int& z) {
//         x = this->x;
//         y = this->y;
//         z = this->z;
//     }
//     void set_coords(int x, int y, int z) {
//         this->x = x;
//         this->y = y;
//         this->z = z;
//     }
// };

// struct line3D {
//    private:
//     point3D p0, p1;

//    public:
//     line3D() {
//         this->p0 = {0, 0, 0};
//         this->p1 = {0, 0, 0};
//     }
//     line3D(point3D p0, point3D p1) {
//         this->p0 = p0;
//         this->p1 = p1;
//     }
//     ~line3D() {
//         int x0, y0, z0, x1, y1, z1;
//         p0.get_coords(x0, y0, z0);
//         p1.get_coords(x1, y1, z1);
//         printf("Deleted line: (%d, %d, %d) (%d, %d, %d)", x0, y0, z0, x1, y1, z1);
//     }
//     double length() {
//         int x0, y0, z0, x1, y1, z1;
//         p0.get_coords(x0, y0, z0);
//         p1.get_coords(x1, y1, z1);
//         double res = sqrt((x0 - x1) * (x0 - x1) + (y0 - y1) * (y0 - y1) + (z0 - z1) * (z0 - z1));
//         return res;
//     }
//     const point3D& get_coords_start() const { return this->p0; }
//     const point3D& get_coords_end() const { return this->p1; }
// };

// int main(void) {
//     point3D start_pt = {-5, 100, 45};
//     point3D end_pt = {0, 32, -42};
//     line3D line(start_pt, end_pt);

//     // __ASSERT_TESTS__
//     return 0;
// }

// #include <iostream>
// #include <string>

// struct dtime {
//    private:
//     unsigned char hs;
//     unsigned char ms;
//     unsigned char sc;

//    public:
//     dtime(unsigned char hs = 0, unsigned char ms = 0, unsigned char sc = 0) {
//         this->hs = hs;
//         this->ms = ms;
//         this->sc = sc;
//     }
//     std::string get_time() {
//         char str[10];
//         sprintf(str, "%02d:%02d:%02d", hs, ms, sc);
//         std::string res(str);
//         return res;
//     }

//     void set_time(unsigned char hours, unsigned char minutes, unsigned char seconds) {
//         this->hs = hours;
//         this->ms = minutes;
//         this->sc = seconds;
//     }

//     static dtime sum_time(const dtime& t1, const dtime& t2) {
//         dtime res;
//         unsigned char over = 0;
//         res.sc = time_sum(t1.sc, t2.sc, over, 60);
//         res.ms = time_sum(t1.ms, t2.ms, over, 60);
//         res.hs = time_sum(t1.hs, t2.hs, over, 24);
//         return res;
//     }
//     static unsigned char time_sum(unsigned char t1, unsigned char t2, unsigned char& over,
//                                   unsigned char limit) {
//         unsigned char res = (t1 + t2 + over) % limit;
//         over = (t1 + t2 + over) / limit;
//         return res;
//     }
// };

// void read_time(dtime& tm) {
//     int hours;
//     int minutes;
//     int seconds;
//     std::cin >> hours >> minutes >> seconds;
//     tm.set_time(hours, minutes, seconds);
// }

// int main(void) {
//     dtime tm1;
//     dtime tm2;

//     read_time(tm1);
//     read_time(tm2);

//     dtime time_res;

//     time_res = dtime::sum_time(tm1, tm2);

//     std::string res = time_res.get_time();
//     std::cout << res << std::endl;
//     // __ASSERT_TESTS__
//     return 0;
// }

// #include <string.h>

// #include <iostream>
// #include <string>

// static unsigned long global_id = 1;
// enum { name_max_len = 50 };

// struct thing {
//     unsigned long id;
//     char name[name_max_len];
//     unsigned int price;
//     double weight;

//     thing(char* name = "", unsigned int price = 0, double weight = 0) {
//         id = global_id++;
//         strcpy(this->name, name);
//         this->price = price;
//         this->weight = weight;
//     }
// };

// int main(void) {
//     thing* ptr_th;
//     char name[name_max_len];
//     unsigned int price;
//     double weight;
//     std::cin >> name >> price >> weight;
//     ptr_th = new thing(name, price, weight);

//     std::cout << ptr_th->price << std::endl;

//     delete ptr_th;

//     // __ASSERT_TESTS__
//     return 0;
// }

// #include <iostream>

// struct rectangle {
//     int x0, y0, x1, y1;

//     rectangle(int x0 = 0, int y0 = 0, int x1 = 0, int y1 = 0) {
//         this->x0 = x0;
//         this->y0 = y0;
//         this->x1 = x1;
//         this->y1 = y1;
//     }
//     bool is_in_rect(int x, int y) { return (x >= x0 && x =< x1) && (y => y0 && y =< y1); }
//     void set_coords(int x0, int y0, int x1, int y1) {
//         this->x0 = x0;
//         this->y0 = y0;
//         this->x1 = x1;
//         this->y1 = y1;
//     }
//     void get_coords(int& x0, int& y0, int& x1, int& y1) {
//         x0 = this->x0;
//         y0 = this->y0;
//         x1 = this->x1;
//         y1 = this->y1;
//     }
// };

// int main(void) {
//     rectangle* ptr_r = new rectangle(-5, 4, 8, 32);

//     int x, y;

//     std::cin >> x >> y;

//     std::cout << (ptr_r->is_in_rect(x, y) ? "yes" : "no") << std::endl;

//     delete ptr_r;
//     return 0;
// }

// #include <iostream>
// using namespace std;

// struct rectangle {
//    private:
//     int x0, y0;
//     int x1, y1;

//    public:
//     rectangle() : x0(0), y0(0), x1(0), y1(0) {}

//     rectangle(int x0, int y0, int x1, int y1) : x0(x0), y0(y0), x1(x1), y1(y1) {}

//     bool is_in_rect(int x, int y) { return x >= x0 && x <= x1 && y >= y0 && y <= y1; }

//     void set_coords(int x0, int y0, int x1, int y1) {
//         this->x0 = x0;
//         this->y0 = y0;
//         this->x1 = x1;
//         this->y1 = y1;
//     }

//     void get_coords(int& x0, int& y0, int& x1, int& y1) {
//         x0 = this->x0;
//         y0 = this->y0;
//         x1 = this->x1;
//         y1 = this->y1;
//     }
// };

// int main(void) {
//     rectangle* ptr_r = new rectangle(-5, 4, 8, 32);

//     int x, y;
//     cin >> x >> y;

//     cout << (ptr_r->is_in_rect(x, y) ? "yes" : "no") << endl;

//     delete ptr_r;

//     return 0;
// }

// #include <iostream>

// int main(void) {
//     double *ptr_d = new double[10];

//     // delete ptr_d;
//     delete[] ptr_d;  // Правильный ответ
//     // delete (ptr_d);
//     // delete (*ptr_d);
//     // delete[] *ptr_d;
//     // delete *ptr_d;

//     return 0;
// }

// #include <iostream>

// int main(void) {
//     short *ptr_ar = new short[15];

//     for (size_t i = 0; i < 15; i++) {
//         ptr_ar[i] = -1;
//     }
//     ptr_ar[4] = 100;

//     // __ASSERT_TESTS__
//     return 0;
// }

// #include <iostream>

// struct Node {
//    public:
//     double data;
//     Node* next;

//    public:
//     Node(double data) {
//         this->data = data;
//         this->next = NULL;
//     }
// };

// struct OneLinkedList {
//    public:
//     Node *head, *tail;

//    public:
//     OneLinkedList() { this->head = this->tail = NULL; }

//     ~OneLinkedList() {
//         while (head != NULL) pop_front();
//     }

//     void pop_front() {
//         if (head == NULL) return;
//         if (head == tail) {
//             delete tail;
//             head = tail = NULL;
//             return;
//         }

//         Node* node = head;
//         head = node->next;
//         delete node;
//     }

//     void push_back(double data) {
//         Node* node = new Node(data);
//         if (head == NULL) head = node;
//         if (tail != NULL) tail->next = node;
//         tail = node;
//     }

//     void push_front(double data) {
//         Node* node = new Node(data);
//         node->next = head;
//         head = node;
//         if (tail == NULL) tail = node;
//     }

//     void pop_back() {
//         if (tail == NULL) return;
//         if (head == tail) {
//             delete tail;
//             head = tail = NULL;
//             return;
//         }

//         Node* node = head;
//         for (; node->next != tail; node = node->next)
//             ;

//         node->next = NULL;
//         delete tail;
//         tail = node;
//     }

//     Node* getAt(int k) {
//         if (k < 0) return NULL;

//         Node* node = head;
//         int n = 0;
//         while (node && n != k && node->next) {
//             node = node->next;
//             n++;
//         }

//         return (n == k) ? node : NULL;
//     }

//     void insert(int k, double data) {
//         Node* left = getAt(k);
//         if (left == NULL) return;

//         Node* right = left->next;
//         Node* node = new Node(data);

//         left->next = node;
//         node->next = right;
//         if (right == NULL) tail = node;
//     }

//     void erase(int k) {
//         if (k < 0) return;
//         if (k == 0) {
//             pop_front();
//             return;
//         }

//         Node* left = getAt(k - 1);
//         Node* node = left->next;
//         if (node == NULL) return;

//         Node* right = node->next;
//         left->next = right;
//         if (node == tail) tail = left;
//         delete node;
//     }
// };

// int main(void) {
//     OneLinkedList lst;
//     lst.push_front(1);
//     lst.push_back(2);

//     Node* n = lst.getAt(0);
//     double d = (n != NULL) ? n->data : 0;
//     std::cout << d << std::endl;

//     lst.erase(1);
//     lst.insert(0, 5);
//     lst.insert(0, 2);

//     for (Node* node = lst.head; node != NULL; node = node->next) {
//         std::cout << node->data << " ";
//     }
//     return 0;
// }

// struct point {
//     int x, y;
// };

// point* p6 = new point();

// struct point* p2(new point);

// point* p5 = new point{};

// point* p3{new point(1, 2)};

// point* p4{new point{1, 2}};

// point* p1 = new point;

// #include <iostream>

// struct complex {
//     double re, im;
// };

// int main(void) {
//     complex* vc{new complex[7]{}};

//     for (size_t i = 0; i < 7; i++) {
//         printf("%.1lf %.1lf ", vc[i].im, vc[i].re);
//     }

//     // __ASSERT_TESTS__
//     delete[] vc;
//     return 0;
// }

// #include <iostream>

// struct box {
//     unsigned short a, b, c;
//     box() {
//         a = b = c = 0;
//         puts("Empty box");
//     }
//     box(int a, int b, int c) {
//         this->a = a;
//         this->b = b;
//         this->c = c;
//         printf("Box: %d, %d, %d\n", a, b, c);
//     }
// };

// int main(void) {
//     box* ar_box(new box[5]{{1, 2, 3}, {6, 2, 1}, {0, 0, 0}, {11, 13, 19}, {23, 5, 7}});

//     // __ASSERT_TESTS__

//     delete[] ar_box;

//     return 0;
// }

// #include <iostream>

// int main(void) {
//     long* ar_long{new long[1000]{}};

//     ar_long[4] = -7;

//     // __ASSERT_TESTS__

//     delete[] ar_long;

//     return 0;
// }

// #include <iostream>

// struct vector {
//     int x, y, z;

//     ~vector() { printf("Deleted vector: %d, %d, %d\n", x, y, z); }
// };

// int main(void) {
//     int x, y, z;
//     std::cin >> x >> y >> z;
//     vector *volume{new vector{x, y, z}};

//     delete volume;

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

// using UINT = unsigned int;
// using PTR_STR = char*;
// using DATA = test::VAR;
// using TEST = test;
// using ptr_func = test::odd;
// using GVAR = global_var;
// using VOLUME = struct {
//     int width, height, depth;
// };
// using AR_INT = int[10];

// #include <iostream>
// #include <memory>

// int main(void) {
//     int x;
//     std::cin >> x;

//     std::unique_ptr<int> p_int{std::make_unique<int>()};

//     *p_int = x;

//     std::cout << *p_int << std::endl;

//     // __ASSERT_TESTS__
//     return 0;
// }

// #include <iostream>
// #include <memory>

// struct thing {
//     unsigned long uid;
//     unsigned width, height, depth;
// };

// int main(void) {
//     std::unique_ptr<thing> p_th;
//     p_th = std::make_unique<thing>();

//     p_th->uid = 1;
//     p_th->width = 10;
//     p_th->height = 43;
//     p_th->depth = 108;

//     // __ASSERT_TESTS__
//     return 0;
// }

// #include <iostream>
// #include <memory>

// struct object {
//    private:
//     short data;
//     object* next;

//    public:
//     object(short d) {
//         this->data = d;
//         next = nullptr;
//     }
//     object* get_next() { return this->next; }
//     short get_data() { return this->data; }
//     void set_next(object* ptr) { this->next = ptr; }
//     void set_data(short d) { this->data = d; }
// };

// int main(void) {
//     std::unique_ptr<object> top;
//     std::unique_ptr<object> ptr;

//     ptr = std::make_unique<object>(1);
//     top = std::make_unique<object>(2);
//     top->set_next(ptr.get());

//     // __ASSERT_TESTS__
//     return 0;
// }

// #include <iostream>
// #include <memory>

// struct object {
//    private:
//     short data;
//     object* next;

//    public:
//     object(short d) {
//         this->data = d;
//         next = nullptr;
//     }
//     object* get_next() { return this->next; }
//     short get_data() { return this->data; }
//     void set_next(object* ptr) { this->next = ptr; }
//     void set_data(short d) { this->data = d; }
// };

// using st_unique_ptr = std::unique_ptr<object>;

// void push(st_unique_ptr& top, short data) {
//     st_unique_ptr ptr;

//     ptr = std::make_unique<object>(data);
//     top = std::make_unique<object>();
//     top->set_next(ptr.get());
// }

// int main(void) {
//     st_unique_ptr top;

//     for (int i = 1; i <= 7; ++i) push(top, i);

//     // __ASSERT_TESTS__
//     return 0;
// }

// #include <iostream>
// #include <memory>

// int main(void) {
//     int x;
//     std::cin >> x;

//     std::shared_ptr<short> p_val;
//     p_val = std::make_shared<short>((short)x);

//     unsigned char* ptr_ch = (unsigned char*)p_val.get();

//     printf("%d %d", *ptr_ch, *(ptr_ch + 1));
//     // __ASSERT_TESTS__
//     return 0;
// }

// #include <iostream>
// #include <memory>

// enum { max_size_ar = 10 };

// using shared_ari_ptr = std::shared_ptr<int[]>;

// int sum_ar(const shared_ari_ptr& ar, size_t len) {
//     int res = 0;
//     for (size_t i = 0; i < len; i++) {
//         res += ar[i];
//     }
//     return res;
// }

// int main(void) {
//     shared_ari_ptr ar{new int[max_size_ar]{0}};
//     unsigned count = 0;

//     while (count < max_size_ar && std::cin >> ar[count]) count++;

//     std::cout << sum_ar(ar, count);

//     return 0;
// }