#include <stdio.h>
#define GCC_

#define WRITE_ONCE(x, val) ({x = val; val;})
#define READ_ONCE(x) (x)

#define offsetof(type, member) ((size_t)&((type *) 0)->member)
                                // & means 'address of'
#define gcc_offsetof(type, member) __builtin_offsetof (type, member)

#define container_of(ptr, type, member) ({ \
        const __typeof__( ((type *)0)->member ) *__mptr = (ptr); \
        (type *)( (char *)__mptr - offsetof(type, member) );})

typedef struct _test {
    int     num;
    int**   arr;
    char    data[0];
}test;

int main(int argc, char** argv)
{
    test* t = (test *) malloc(sizeof(test) + 10);

    WRITE_ONCE(t->num, 100);
    WRITE_ONCE(*(char *)(t +  gcc_offsetof(test, data) + 1), 'h');
    *(char *)(t +  gcc_offsetof(test, data) + 1) = 'h';
    t->data[0] = 'h';
    t->data[9] = 'e';
    printf("check the data[0] = %c\n", t->data[0]);
    printf("check the data[9] = %c\n", t->data[9]);

    //t->num = 100;
    //t->num;
    printf("t->num = %d\n", READ_ONCE(t->num));

    printf("offsetof(test, num) = %d\n",offsetof(test, num));
    printf("offsetof(test, arr) = %d\n",offsetof(test, arr));
    printf("offsetof(test, data) = %d\n",offsetof(test, data));
    printf("gcc_offsetof(test, data) = %d\n",gcc_offsetof(test, data));
    printf("sizeof(t) = %d\n", sizeof(*t));

    test* tt = container_of(&t->data, test, data);
    printf("tt == t => %c\n", t == tt? 'T': 'F');
    //const char *__mptr = (void *) &t->data;
    //test *tt = (test *)( (char *)__mptr - offsetof(test, data) );
}
