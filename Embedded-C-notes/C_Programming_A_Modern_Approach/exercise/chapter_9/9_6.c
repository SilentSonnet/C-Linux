#include<stdio.h>

int digit(int number, int k);

int main(void)
{
    int number, k, flag;
    printf("Enter a number : ");
    scanf("%d %d", &number, &k);

    if(digit(number, k) != -1)
        printf("The digit at position %d from the right is: %d\n", k, digit(number, k));
    else 
        printf("The number doesn't have %d digits.\n", k);

    return 0;
}

int digit(int number, int k)
{
    if(number == 0)
        return (k == 1) ? 0 : -1;
    
    if(number < 0)
        number = -number;

    for(int i = 1;i < k;i ++)
        number /= 10;
    if(number == 0)
        return -1;
    
    return number % 10;
}