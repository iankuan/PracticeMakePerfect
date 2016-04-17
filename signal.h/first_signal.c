#include <signal.h>
#include <unistd.h>
#include <stdio.h>

#define pSIGERR(sig) printf("error return by signal(" #sig ",sigr) Maybe it is init call\n")
#define pSIGSUC(sig) printf(#sig "success\n")
#define CHOOSE(type,sig) pSIG ## type(sig)
/*I has tried pSIG ## type ## ( ## sig ## )
I found that ## is only use in argument, the ## maybe has left to right or right to left, so above will get error
*/

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
  if( signal(SIGHUP,sigr) > 0) CHOOSE( SUC, SIGHUP); else CHOOSE( ERR, SIGHUP);
  if( signal(SIGINT,sigr) > 0) CHOOSE( SUC, SIGINT); else CHOOSE( ERR, SIGINT);
  if( signal(SIGQUIT,sigr)> 0) CHOOSE( SUC, SIGQUIT); else CHOOSE( ERR, SIGQUIT);
  while(1) ;
}
