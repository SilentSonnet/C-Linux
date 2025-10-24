#include<stdio.h>
int main(void)
{
	int i, j;
	i = 1, j = 2;
  printf("i += j = %d\n", i += j);
  printf("i-- = %d\n", i--);
  printf("i * j / i = %d\n", i * j / i);
  printf("i %% ++j = %d\n", i % ++j);
  
  return 0;
}