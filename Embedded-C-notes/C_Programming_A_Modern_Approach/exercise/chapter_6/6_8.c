#include<stdio.h>
int main(void)
{
    for (int i = 10; i >= 1; i /= 2)
        printf("%d ", i++);
    printf("\n");

    return 0;
}