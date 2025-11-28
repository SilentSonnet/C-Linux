#include <stdio.h>

#define SIZE 10
#define COUNT(x) (sizeof(x) / sizeof(x[0]))

int number[SIZE] = {0};

int main(void)
{
    printf("The number of the array is : %lu\n", COUNT(number));
    return 0;
}
