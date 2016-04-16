#include <stdio.h>
#include <stdlib.h>

typedef struct object Object;
typedef int (* func_t)( Object *);

struct object{

  int a,b;
  func_t add,sub;
};

static int add_impl( Object * self){ return self->a + self->b;}
static int sub_impl( Object * self){ return self->a - self->b;}

int init_object( Object **self){

  if( NULL == (*self = malloc(sizeof( Object)))) return -1;
  (*self)->add = add_impl;(*self)->sub = sub_impl;
  return 0;
}

int main(int argc, char *argv[])
{
  Object *o = NULL;
  init_object( &o);
  o->a = 9922; o->b =5566;
  printf("add = %d, sub = %d\n", o->add(o), o->sub(o));
  return 0;
}
