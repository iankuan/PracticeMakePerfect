#include <stdio.h>
#include <stdlib.h>

typedef struct _test{
    int a;
    char data[0];
} test;

int main()
{
    test tt = {.a = 100};
    test* t = (test *) malloc( sizeof(test) * 2);
    free(t+1);
    free(t);//double free detect

    return 0;
}
