#include <stdio.h>

int add( int a, int b) { printf("add(2,3) is ok without lval\n");return a+b;}

int main()
{
  add( 2, 3);

  return 0;
}
