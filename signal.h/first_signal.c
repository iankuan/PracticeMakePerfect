#include <signal.h>
#include <unistd.h>
#include <stdio.h>

void sigr( int sig)
{
  switch(sig){
    case SIGHUP:
    printf("\nSIGHUP\n");
    break;
    case SIGINT:
    printf("\nSIGINT\n");
    break;
    case SIGQUIT:
    printf("\nSIGQUIT\n");
   }
}

int main()
{
  printf("pid = %d\n", getpid());
  if( signal(SIGHUP,sigr) == SIGHUP) printf("\nSignal return SIGHUP\n");
  if( signal(SIGINT,sigr) == SIGINT) printf("\nSignal return SIGINT\n");
  if( signal(SIGQUIT,sigr) == SIGQUIT) printf("\nSignal return SIGQUIT\n");
  while(1) ;
}
