#include <stdio.h>

// нужно хранить другие данные в стеке?
// Измени тип хранимых данных в одном месте.
typedef int Data;

#define N 8
typedef struct {
    Data a[N];       // место для данных
    unsigned int n;  // сколько данных хранится
} Stack;

// печать стека
void print(Stack* s) {
    for (unsigned int i = 0; i < s->n; i++) printf("%d ", s->a[i]);
    printf("\n");
}

int main() {
    Stack stack = {{7, 4, 1}, 3};
    print(&stack);

    return 0;
}