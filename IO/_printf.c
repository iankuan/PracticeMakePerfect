#include <stdio.h>
#include <string.h>

int main()
{
  char s[30];//if we use char *s, it would cause segment fault
              //Maybe last char isn't '\0'
  int mom = 1;
  int bro = 20;

  sprintf( s, "sprintf:I have %d mom %d bro\n", mom, bro);
  printf("printf return %d\n", printf("%s",s) );

}
