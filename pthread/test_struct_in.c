#include <stdio.h>
#include <pthread.h>

typedef struct msg{
  char *first;
  char *second;
}msg;

typedef struct box{
  msg *m;
}box;

void showt( void * vp){

  box *p = (box *)malloc( sizeof( box));
  p = (box *) vp;
  
  printf("fist = %s second = %s", p->m->first, p->m->second);
}

int main(){

  msg *line = (msg *) malloc( sizeof(msg));
  line->first = "Hellow";line->second = "World";
  box *p = (box *)malloc( sizeof( box));
  p->m = line;
  
  pthread_t tid1,tid2;

  pthread_create( &tid1, NULL, (void *)&showt, (void *) p);
  pthread_create( &tid2, NULL, (void *)&showt, (void *) p);

}
