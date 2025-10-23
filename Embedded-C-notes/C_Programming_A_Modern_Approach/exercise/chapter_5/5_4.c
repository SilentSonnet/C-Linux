#include<stdio.h>
int main(void)
{
    int i, j;
    printf("Please enter i:\n");
    scanf("%d %d", &i, &j);

    (i < j)? (-1) : (i == j ? 0: 1);

    i >= j? !!(i - j) : -1;

    return 0;
}