#include <stdio.h>
#include <stdlib.h>

void swap(char *a, char *b)
{
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
}

void str_rev_sub(char *str, int i)
{
    while(*(str + i) && *(str + i + 1))
    {
        swap(str, str + 1);
        str++;
    }
}

char *str_rev(char *str)
{
    
    for(int i = 0; *(str + i); i++)
        str_rev_sub(str, i);

    return str;
}

#define Usage "Usage:  ./str_rev <str>\n"

int main(int argc, char *argv[])
{
    //char str[] = "Jserv";

    if(argc != 2)
    {
        fprintf(stderr, Usage);
        exit(EXIT_FAILURE);
    }

    printf("%s\n", argv[1]);


    printf("%s\n", str_rev(argv[1]));
}
