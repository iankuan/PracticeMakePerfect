#include <stdio.h>

int _global;

int add( int a, int b) {return a+b;}

double mul( double a, double b) {return a*b;}

int main(){
  
  int (* func_padd)( int a, int b);
  func_padd = add;
  double (* func_pmul)( double, double);
  func_pmul = mul;
  printf(" 1 add 2 = %d\n", func_padd( 1, 2));
  printf(" 3 mul 6 = %lf\n", func_pmul( 3, 6));
}
