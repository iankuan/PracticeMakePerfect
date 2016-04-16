#include <stdio.h>
#include <stdarg.h>

void minprintf( char* , ...);

int main( int argc, char* argv[])
{

  char s[30] = "Today is %d / %d / %d / %f pm\n";
  char ss[30] = "Math: %d * %f = %f\n";

  minprintf( "%s", s);
  minprintf( s, 2016, 4, 10, 00.59);
  minprintf( "%s", ss);
  minprintf( ss, 2, 1.7, 3.4);

  return 0;
}
//                       it`s "...", no doubt. Just like "argv"
void minprintf( char* fmt, ...)
{
  va_list ap; //TODO:points to each unnamed arg in turn
  va_start( ap, fmt);

  char *ctmp = fmt, *sval;
  int ival;
  //float fval;
  double fval;

  for( ; *ctmp; ctmp++)
  {
    if( *ctmp != '%')
      putchar(*ctmp);
    else{
      switch( * ++ctmp){

      case 'd':
        ival = va_arg( ap, int);//TODO:get int at
        printf("%d", ival);
        break;

      case 'f':
        //fval = va_arg( ap, float); //TODO: NO FLOAT, should use DOUBLE
        fval = va_arg( ap, double);
        printf("%f", fval);
        break;
      case 's':
        for( sval = va_arg( ap, char *); *sval; sval++)
          putchar( *sval);
        break;
      }
    }
  }

  va_end( ap);
}


