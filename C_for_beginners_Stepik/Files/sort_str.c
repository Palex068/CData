#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 20

int cmp_str(const void * p1, const void * p2)
{
    // а и b адреса начала строк
    const char * a = *(const char **)p1;  
    const char * b = *(const char **)p2;
    
    return strcmp(a, b);
}

int main()
{
    size_t n, i;
    char * a[] = {
        "hello",
        "good bye",
        "abc",
        "hell"
    };
    char text[][N] = {
        "hello",
        "good bye",
        "abc",
        "hell"
    };
    
    n = sizeof(a) / sizeof(a[0]);
    // отладочная печать, поверяем, что строки есть
    for(i = 0; i < n; i++)
        printf("%s\n", a[i]);
    
    qsort(a, n, sizeof(char *), cmp_str);
    
    printf("--------------\n");
    
    for(i = 0; i < n; i++)
        printf("%s\n", a[i]);
    
    n = sizeof(text)/sizeof(text[0]);
    printf("%zd=%zd/%zd\n", n, sizeof(text), sizeof(text[0]));
    char ** text1 = malloc(n * sizeof(char*));
    for(i = 0; i < n; i++)
        text1[i] = text[i];
    
    qsort(text1, n, sizeof(text1[0]), cmp_str);
    
    printf("===============\n");
    
    for(i = 0; i < n; i++)
        printf("%s\n", text1[i]);
    
    free(text1);
    return 0;
}