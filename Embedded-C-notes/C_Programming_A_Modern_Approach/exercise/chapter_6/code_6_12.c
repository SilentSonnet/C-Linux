#include<stdio.h>
int main(void)
{
    double sum = 1.0, temp = 1.0, acc;
    printf("Please enter the accuracy: ");
    scanf("%le", &acc);

    for(int i = 1;;i ++)
    {
        temp *= i;
        sum += (1.0 / temp);
        if((1.0 / temp) < acc)
            break;
        // 看看循环了多少次
        // printf("%d\n", i);
    }

    printf("e is: %.15lf\n", sum);
    return 0;
}