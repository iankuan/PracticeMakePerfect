#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

void print_msg( void * msg);

int main(){
  
  pthread_t *tid = (pthread_t *) malloc ( 2 * sizeof( pthread_t));
  char *s1 = "Hellow ";
  char *s2 = "World!";
  pthread_create( tid, NULL, (void *) &print_msg, (void *) s1);
  pthread_create( tid+1, NULL, (void *) &print_msg, (void *) s2);
  
  pthread_join( tid[0], NULL);
  pthread_join( tid[1], NULL);

  /*exit(0);*/
}

void print_msg(void * msg)
{
  char *str;
  str = (char *) msg;
  printf("%s", str);
  pthread_exit(0);
}
