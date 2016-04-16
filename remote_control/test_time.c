#include <stdio.h>
#include <stdlib.h>
#include "time.c"

int main()
{
  time_t t1,t2;

  t1 = get_time();
  printf("t1 = %d\n", t1);
  sleep(5);
  t2 = get_time();
  printf("t2 = %d\n", t2);
  printf("sleep(5) diff time is %lf\n", diff_time( t2, t1));
}

