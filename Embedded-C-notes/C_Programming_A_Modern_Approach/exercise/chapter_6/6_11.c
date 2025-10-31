#include <stdio.h>
int main(void)
{
    int sum = 0;
    for (int i = 0; i < 10; i++)
    {
        if (i % 2)
            continue;
        printf("%d ", i);
        sum += i;
    }
    printf("\n");
    printf("%d\n", sum);
} 