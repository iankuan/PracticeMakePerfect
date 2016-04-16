#include <stdio.h>
#include <fcntl.h>
#include "syscall.h"
#include <stdarg.h>
#include <stdlib.h>

#define PERMS 0666 //RM for owner, group, other

void error( char *, ...);

int main( int argc, char *argv[])
{
  int f1, f2, n;
  char buf[BUFSIZ];

  printf("BUFSIZ: %d byte\n", BUFSIZ);

  if ( argc != 3)
    error("Error Use");
  if( (f1 = open( argv[1], O_RDONLY, 0)) == -1)
    error("first file %s error", argv[1]);
  if( (f2 = creat( argv[2], PERMS)) == -1)
    error("second file %s creat error wit permition %03o", argv[2], PERMS);

  while( (n = read( f1, buf, BUFSIZ)) > 0)

    if( write( f2, buf, n) != n) error("write error to file2 %s", argv[2]);
      
  return 0;
}

void error( char *fmt, ...)
{
  va_list ap;
  va_start( ap, fmt);
  fprintf( stderr, "error: ");
  vfprintf( stderr, fmt, ap);
  fprintf( stderr, "\n");
  va_end( ap);
  exit(1);
}
