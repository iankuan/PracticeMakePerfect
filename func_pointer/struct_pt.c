#include <stdio.h>

typedef struct s{

  double a;
  int b;
}s;

int main(){

  s var1,var3,var5;
  var1.a = 20;
  var3.a = 10;
  var1.b = 1;
  var3.b = 1;
  s *var2, *var4;
  var2 = &var1;
  var4 = &var3;


  printf("var2 = %o, var4 = %o, var1 = %o, var3 = %o, var5 = %o, &(var1.a) = %o, &(var1.b) = %o", var2, var4, var1, var3, var5, &(var1.a), &(var1.b));

  }
