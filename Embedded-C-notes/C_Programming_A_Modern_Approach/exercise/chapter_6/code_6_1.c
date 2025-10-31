#include<stdio.h>
int main(void)
{
    float number, max = 0, sum = 0;
    int abort = 1;
    while(1)
    {
        printf("Enter a number: ");
        scanf("%f", &number);

        if(number <= 0)
            break;
        else if(number > max)
            max = number;
    }
    printf("Max: %.2f\n", max);
    return 0;   
}