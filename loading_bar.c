#include <stdio.h>
#include <unistd.h>

int main()
{
    for(int i = 0; i < 100; i++) {
        for(int j = 0; j < 80; j++) {
            printf(".");
            fflush(stdout);//TODO: important
            sleep(1);
        }
        printf("\n");
    }
}
