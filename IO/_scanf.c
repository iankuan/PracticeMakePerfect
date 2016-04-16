#include <stdio.h>

int main()
{
  char s[20],today[20] = "2016 4 7";
  int year, month, day;

  sscanf( today, "%d %d %d", &year, &month, &day);
  printf("year: %d month: %d day: %d\n", year, month, day);
}

