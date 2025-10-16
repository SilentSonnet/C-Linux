#include<stdio.h>
int main(void)
{
    int number, o1, o2, o3, o4, o5;
    printf("Enter a number between 0 and 32767: ");
    scanf("%d", &number);

    o5 = number % 8;
    number /= 8;
    o4 = number % 8;
    number /= 8;
    o3 = number % 8;
    number /= 8;
    o2 = number % 8;
    number /= 8;
    o1 = number % 8;
    number /= 8;

    printf("In octal, your number is: %1d%1d%1d%1d%1d\n", o1, o2, o3, o4, o5);

    return 0;
}

