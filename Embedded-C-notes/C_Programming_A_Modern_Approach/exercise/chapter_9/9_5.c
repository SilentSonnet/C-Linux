#include<stdio.h>

int num_digits(int number);

int main(void)
{
    int number;
    printf("Enter a number : ");
    scanf("%d", &number);

    printf("The digits of number is : %d\n", num_digits(number));

    return 0;
}

int num_digits(int number)
{
    int sum = 0;

    // zero is also an one digit number!
    if(number == 0)
        return 1;
    
    if(number < 0)
        number = -number;

    while(number > 0)
    {
        sum ++;
        number  /= 10;
    }

    return sum;
}