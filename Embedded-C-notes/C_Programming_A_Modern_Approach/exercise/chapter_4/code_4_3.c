#include<stdio.h>
int main(void)
{
    int number, first, second, third;
    printf("Enter a two-digit number: ");
    scanf("%1d%1d%1d", &third, &second, &first);

    printf("The reversal is: %1d%1d%1d\n", first, second, third);
    return 0;
}

