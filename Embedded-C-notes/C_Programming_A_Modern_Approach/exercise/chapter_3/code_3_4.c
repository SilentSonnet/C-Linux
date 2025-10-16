#include<stdio.h>
int main(void)
{
    int number1, number2, number3;
    printf("Enter phone number [(xxx) xxx-xxxx]:");
    scanf("(%d)%d-%d", &number1, &number2, &number3);
    printf("%d.%d.%d\n", number1, number2, number3);

    return 0;
}

