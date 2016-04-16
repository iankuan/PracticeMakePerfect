
//TODO: know about void (*signal(int sig, void (*func)(int)))(int)

#include <stdio.h>

void my_num( int ynum)
{
  printf("hey hey My num alway bigger 1 than you : %d\n", ynum + 1);
}

void Print_funct( int printnum) { printf("Print %d\n", printnum);}

//TODO:IMPORTANT This is a function pointer with two argument(int and func) and this function pointer
void (* your_num( int num, void(* func)( int))) (int)
{
  printf("Show your num is %d\n", num);
  
  //TODO: All i want to know
  my_num( num);
  //Yu, I was confused by the argument of function pointer and fuction pointer

  
  //TODO:I can also return a function poiner
  return Print_funct;
}


int main()
{
  int num = 70;
  void (* f_ptr)(int);

  f_ptr = your_num( num, my_num);
  f_ptr(9999999);

  return 0;
}



