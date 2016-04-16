#include <stdio.h>

int main()
{
  FILE *fp = fopen("fpf.txt", "wt");
  fprintf( fp, "I use fprintf at %d / %d / %d\n", 2016, 4, 8);
}
