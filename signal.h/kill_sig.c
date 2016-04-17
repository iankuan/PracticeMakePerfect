#include <stdio.h>
#include <ctype.h>
#include <signal.h>
#include <assert.h>

void prt_sig( int sig)
{
  if (sig == SIGINT)
    printf("ptr_sig:I got the inrerrupt\n");
  else
    printf("I can't read the sig %d\n",sig);
}

int main()
{
  pid_t pd;
  pd = fork();

  if( pd > 0)
  {
    printf("I am Parent I will interrupt the child process\n");
    sleep(1);
    if( kill( pd, SIGINT) < 0)
      assert("kill function return error");
  }
  else if( pd == 0)
  {
    signal( SIGINT, prt_sig);
    printf("I am Child I going to infinite loop\n");
    while(1) ;
  }
}
    
