#include <array>
#include <iostream>
#include <vector>

using namespace std;

template <typename T>
class MyTemplateClass {
public:
    MyTemplateClass() {}
    void test() {}
    int test2() { return 12; }
    int data;
};

void testAutocomplete()
{
    auto mtc = new MyTemplateClass<int>();
    mtc->test();
    mtc->test2();
    vector<int> vi;
    vi.push_back(1);
    vi.push_back(3);
    delete mtc;
}

void testCodeAnalyze()
{
    int i = 12;
    double d = 13;
    auto b = (d == 12);
    float f = d;
}

void testMemoryAnalyzer()
{
    auto mtc = new MyTemplateClass<int>();
    mtc->data = 12;
    mtc->test();
}

void printSomething()
{
    cout << "Something";
}

void loop100()
{
    for (int i = 0; i < 100; ++i) {
        cout << i;
    }
}

void loop200()
{
    for (int i = 0; i < 200; ++i) {
        cout << i;
    }
}

void loop100AndPrintSomething()
{
    for (int i = 0; i < 100; ++i) {
        cout << i;
        printSomething();
    }
}

void testFnctionProfiler()
{
    loop100();
    loop200();
    loop100AndPrintSomething();
}

int main()
{
    testAutocomplete();
    testMemoryAnalyzer();
    testFnctionProfiler();
    return 0;
}
