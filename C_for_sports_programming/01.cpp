#include <iostream>

using namespace std;

int main() {
    
    int a[]{ 77,97,121,32,116,104,101,32,102,111,114,99,101,32,98,101,32,119,105,116,104,32,89,111,117,33 };
    
    for (size_t i = 0; i < 26; i++) {
        cout << (char) a[i];
    }
        
    return 0;
}