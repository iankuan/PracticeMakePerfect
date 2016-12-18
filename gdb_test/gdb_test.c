#include <stdio.h>

#ifdef test_%
#else
#endif

int add(int a, int b)
{
    return a + b;
}

int main(int argc, char** argv)
{
    int a = 1;
    a = 2;
    a = add(a, a);
    a = add(a, a);
    int *b = NULL;
    *b = 10;

    for(int i = i; i < 10; i++) {
        a += i;
    }

    return 0;
}
