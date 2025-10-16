#include<stdio.h>
int main(void)
{
    int number, first, second;
    printf("Enter a two-digit number:");
    scanf("%d", &number);
    first = number % 10;
    second = (number / 10) % 10;

    printf("The reversal is: %d\n", first * 10 + second);
    return 0;
}

