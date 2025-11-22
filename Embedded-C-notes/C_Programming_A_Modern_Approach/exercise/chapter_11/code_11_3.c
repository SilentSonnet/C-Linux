#include<stdio.h>

void reduce(int numerator, int denominator, int *reduced_numerator, int *reduced_denominator);

int main(void)
{
    int numerator, denominator, reduced_numerator, reduced_denominator;
    printf("Enter a fraction: ");
    scanf("%d / %d", &numerator, &denominator);
 
    reduce(numerator, denominator, &reduced_numerator, &reduced_denominator);

    printf("In lowest terms: %d/%d\n", reduced_numerator, reduced_denominator);

    return 0;
}

void reduce(int numerator, int denominator, int *reduced_numerator, int *reduced_denominator)
{
    int temp, gcd;
    *reduced_numerator = numerator;
    *reduced_denominator = denominator;
    while(denominator != 0)
    {
        temp = denominator;
        denominator = numerator % denominator;
        numerator = temp;
    }
    gcd = numerator;

    *reduced_numerator /= gcd;
    *reduced_denominator /= gcd;
}
