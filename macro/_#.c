#include <stdio.h>

#define NUM(n) n
#define SNUM(n) #n
#define PRINT_NUM(n) printf(#n"\n");

/*IMPORTANT: n = #n, n would not be treat by varble
    SNUM(i) = "i" not i = 1 2 3 ...*/

int main()
{
  int i;
  for( i = 0; i < 10; i++)
    printf("NUM %d\n",NUM(i));
  for( i = 0; i < 10; i++)
    printf(SNUM(i) "\n");
  for( i = 0; i < 10; i++)
     printf(SNUM( NUM(i)) "\n");
  for( i = 0; i < 10; i++)
    PRINT_NUM(i);
  return 0;
}
