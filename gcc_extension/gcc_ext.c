#include <stdio.h>

#define FOR int i = 10; for(int i; i < 5; i++)
#define type(i) ({ __typeof__(i) __a = i;1000;})
#define max(a, b) ({ __typeof__(a) _a = (a);\
                     __typeof__(b) _b = (b);\
                     (void)  (&_a == &_b);\
                     _a > _b ? _a : _b;})

int main()
{
    FOR
        ;
    //type(i) a = 15;
    printf("%d\n",type(i));

    int A = 10;
    int B = 11;
    //float B = 11;
    printf("max(10, 11) = %d\n",max(A, B));
}
