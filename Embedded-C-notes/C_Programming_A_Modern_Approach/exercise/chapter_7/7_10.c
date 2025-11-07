#include <stdio.h>

int main(void)
{
    int i = 10;
    long int j = 5;
    unsigned int k = 5;

    if (sizeof(i) == sizeof(int))
    {
        printf("i is of type: int\n");
    }

    if (sizeof(j) == sizeof(long int))
    {
        printf("j is of type: long int\n");
    }

    int result = i + (int)j * k; 
    if (sizeof(result) == sizeof(unsigned int))
    {
        printf("Result of i + (int)j * k is of type: unsigned int\n");
    }

    return 0;
}