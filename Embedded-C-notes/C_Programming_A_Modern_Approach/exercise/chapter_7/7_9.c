#include <stdio.h>

int main(void)
{
    int i = 10;
    int j = 5;

    if (sizeof(i) == sizeof(int))
    {
        printf("i is of type: int\n");
    }

    if (sizeof(j) == sizeof(int))
    {
        printf("j is of type: int\n");
    }

    int result = i / j + 'a'; 
    if (sizeof(result) == sizeof(int))
    {
        printf("Result of i / j + 'a' is of type: int\n");
    }

    return 0;
}
