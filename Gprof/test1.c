#include "stdio.h"
#include "stdlib.h"

void a(){
  printf("\t\t+---call a() function\n");
  }

void c(){
   printf("\t\t+---call c() function\n");
}

int b(){
   printf("\t+--- call b() function\n");
   a();
   c();
   return 0;
}
int main(){
   printf(" main() function()\n");
   b();
}
