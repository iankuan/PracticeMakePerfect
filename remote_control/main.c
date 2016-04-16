#include <stdio.h>
#include <stdlib.h>
#include "time.c"

int main()
{
  printf("Remote control start\n\n");

  /*time_t t1,t2;
  t1 = get_time();
  t2 = get_time();*/

  pid_t pid;
  pthead_t tid1, tid2;
  
  pid = fork();

  int pipefd[2];
  pipe(pipefd);

  if( pid > 0){//parent

    while(1)
    {
      
    }
}
