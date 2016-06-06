#include <stdio.h>

void static_local_val(void)
{
    static int x = 1; // 只會初始化一次
    printf("x = %d\n", x);
    ++x;
}

void local_val(void)
{
    int x = 1; 
    printf("x = %d\n", x);
    ++x;
}

void main(void)
{
    printf("local value ++\n");
    for (int i=0; i<5; ++i)
    {  local_val();  }
    printf("static local value ++\nonly once declaration\n");
    for (int i=0; i<5; ++i)
    {  static_local_val();  }
}
