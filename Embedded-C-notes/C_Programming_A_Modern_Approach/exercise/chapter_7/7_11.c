#include <stdio.h>

int main(void)
{
    int i = 10;
    float f = 5.0f;
    double d = 5.0;

    if (sizeof(i) == sizeof(int))
    {
        printf("i is of type: int\n");
    }

    if (sizeof(f) == sizeof(float))
    {
        printf("f is of type: long float\n");
    }

    double result = i * f / d; 
    if (sizeof(result) == sizeof(double))
    {
        printf("Result of i * f / d is of type: double\n");
    }

    return 0;
}