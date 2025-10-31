#include<stdio.h>
int main(void)
{
    int acc;
    float sum = 1.0, temp = 1.0;
    printf("Please enter the accuracy: ");
    scanf("%d", &acc);

    for(int i = 1;i < acc;i ++)
    {
        temp *= i;
        sum += (1.0 / temp);
    }

    printf("e is: %f\n", sum);
    return 0;
}