#include <stdio.h>
int main(void)
{
    for (short i = 1; i < 32767; i++)
    {
        // printf("%10d%10d\n", i, i * i);
        if ((i * i) < 0)
        {
            printf("%d\n", i);
            break;
        }
        short res = (i * i);
        if (res < 0)
        {
            printf("%d\n", i);
            break;
        }
    }

    for (int i = 1; i < 2147483647; i++)
    {
        // printf("%10d%10d\n", i, i * i);
        if ((i * i) < 0)
        {
            printf("%d\n", i);
            break;
        }
    }

    for (long i = 1; i < 9223372036854775807; i++)
    {
        // printf("%10d%10d\n", i, i * i);
        if ((i * i) < 0)
        {
            printf("%ld\n", i);
            break;
        }
    }

    return 0;
}