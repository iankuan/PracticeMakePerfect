#include <stdio.h>

int main()
{
  FILE *fp = fopen("fpf.txt", "rt");
  int year,month,day;
  fscanf( fp, "I use fprintf at %d / %d / %d", &year, &month, &day);

  printf("year: %d, month: %d, day: %d\n", year, month, day);
}
