#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 20


char text[][N] = {
    "hello",
    "good bye",
    "abc",
    "hell"
};

int cmp(const void *a, const void *b)
{
        return strcmp(a, b);
}

int main()
{
        int n = sizeof(text) / sizeof(*text);

        qsort(text, n, N, cmp);

        int i;
        for (i=0; i < n; ++i)
                printf("%s\n", text[i]);
}