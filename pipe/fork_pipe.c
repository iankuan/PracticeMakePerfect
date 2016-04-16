#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(){

  int pipefd[2];
  pipe(pipefd);
  char rbuf[30];

  pid_t pid = fork();

  if( pid == 0)//child
  {
    close( pipefd[0]);
    char s[30] = "child want to tell u";
    printf("child say strlen = %d\n", (int) strlen(s));
    write( pipefd[1], s, strlen(s)+1);
    close( pipefd[1]);
  }
  else if( pid > 0){//parent

    close(pipefd[1]);
    read( pipefd[0], rbuf, 30);
    printf("PARENT GET :%s\n",rbuf);
    close( pipefd[0]);
  }
  else{

    //fprintf( stderr, "fork error...");
    exit(0);
  }

  return 0;
}

