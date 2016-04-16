#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

void fcpy( FILE *, FILE *);

int main( int argc, char *argv[])
{
  //printf("%s %s\n\n", argv[0], argv[1]);
  //assert( strcmp( argv[0], "cat") == 0 && "cant find cat");
  /*********************************************
   *
   *argv[0] always = ./a.out( execute file)
   *
   ********************************************
   */
  //assert( FALSE will print) 
  assert( strcmp( argv[1], "cat") == 0 && "cant find cat");

  if( argc < 3)
  {
    perror("no file for cat");
    exit(0);
  }
  else
  {
    int i = 2;
    while( i < argc)
    {
      FILE *fp;
      assert( (fp = fopen( argv[i], "r")) != NULL);
      fcpy( fp, stdout);
      fclose(fp);
      i++;
    }
  }
  return 0;
}

void fcpy( FILE *in, FILE *out)
{
  int c;
  while( (c = getc( in)) != EOF )
    putc( c, out);
}
