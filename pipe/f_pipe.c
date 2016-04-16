#include <stdio.h>
#include <string.h>

int main()
{
  int pipefd[2];
  pipe(pipefd);
  
  printf("pipefd[0] = %d pipefd[1] = %d\n", pipefd[0], pipefd[1]);

  char wbuf[] = "Hellow world";
  write( pipefd[1], wbuf, strlen(wbuf));

  char rbuf[20];
  int n = read( pipefd[0], rbuf, 20);
  rbuf[n] = 0;
  

  printf("%s\n", rbuf);
}
