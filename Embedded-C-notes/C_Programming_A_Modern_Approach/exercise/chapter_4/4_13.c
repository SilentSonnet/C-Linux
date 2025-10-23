#include<stdio.h>
int main(void)
{
	int i = 1;
  printf("++i = %d\n", ++i);
  i = 1;
  printf("i++ = %d\n", i++);
  i = 1;
  printf("(i += 1) = %d\n", (i += 1));
  
  return 0;
}
