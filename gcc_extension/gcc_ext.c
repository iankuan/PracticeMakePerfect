#include <stdio.h>

#define FOR int i = 10; for(int i; i < 5; i++)
#define type(i) ({ __typeof__(i) __a = i;1000;})
#define max(a, b) ({ __typeof__(a) _a = (a);\
                     __typeof__(b) _b = (b);\
                     (void)  (&_a == &_b);\
                     __typeof__(a) _tmp = _a > _b ? _a : _b;\
                     _tmp; })

#define max3(a,b,c) max(a, max(b,c))

//varible length
void foo(int s) { char str[s]; printf("LOCAL:sizeof(str) = %d\n", sizeof(str));}

int main()
{
    FOR
        ;
    //type(i) a = 15;
    printf("%d\n",type(i));

    int A = 10;
    int B = 11;
    int C = 12;
    //float B = 11;
    printf("max(10, 11) = %d\n",max(A, B));
    printf("max3(10, 11, 12) = %d\n",max3(A, B, C));

    int arr[] = { [0 ... 5] = 1, [ 6 ... 100] = 2};

    foo(10);
    //FIXME: fail... str is local varible
    //printf("sizeof(str) = %d\n", sizeof(str));
}
