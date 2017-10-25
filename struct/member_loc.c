#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    struct st {
        char c;
        unsigned char uc;
        char d;
        char e;
        char f;
        int i;  // align to sizeof(int)
        char cc;
        unsigned char ucc;
        unsigned char uccc;
        unsigned char ucccc;
        unsigned char uccccc;
        long long ll; // align to sizeof(long long)
    };
    //}__attribute__((packed));

    struct st *foo = (struct st *) malloc(sizeof(struct st));

    printf("foo == &foo->c: %d\n", foo == (struct st *) &foo->c);
    printf("&foo->c: %lu\n", (unsigned long) &foo->c);
    printf("&foo->uc: %lu\n", (unsigned long) &foo->uc);
    printf("&foo->d: %lu\n", (unsigned long) &foo->d);
    printf("&foo->e: %lu\n", (unsigned long) &foo->e);
    printf("&foo->f: %lu\n", (unsigned long) &foo->f);
    printf("&foo->i: %lu\n", (unsigned long) &foo->i);
    printf("&foo->cc: %lu\n", (unsigned long) &foo->cc);
    printf("&foo->ucc: %lu\n", (unsigned long) &foo->ucc);
    printf("&foo->uccc: %lu\n", (unsigned long) &foo->uccc);
    printf("&foo->ucccc: %lu\n", (unsigned long) &foo->ucccc);
    printf("&foo->uccccc: %lu\n", (unsigned long) &foo->uccccc);
    printf("&foo->ll: %lu\n", (unsigned long) &foo->ll);
}
