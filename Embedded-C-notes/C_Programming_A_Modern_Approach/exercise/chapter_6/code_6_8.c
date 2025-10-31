#include<stdio.h>
int main(void)
{
    int number, start, day;
    printf("Enter number of days in month: ");
    scanf("%d", &number);
    printf("Enter starting day of the week (1=Sun, 7=Sat): ");
    scanf("%d", &start);

    for(int i = 1;i < start; i ++)
        printf("\t");

    day = start;
    for(int i = 1;i <= number;i ++, day ++)
    {
        if(day % 7 == 0)
        {
            printf("%2d\n", i);
        }
        else
        {
            printf("%2d\t", i);
        }
    }

    printf("\n");
    return 0;
}