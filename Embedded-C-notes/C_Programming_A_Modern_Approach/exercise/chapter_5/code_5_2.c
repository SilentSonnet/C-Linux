#include<stdio.h>
int main(void)
{
    int hour, min;
    printf("Enter a 24-hour time:");
    scanf("%d : %d" ,&hour ,&min);

    if(hour <= 12)
        printf("Equivalent 12-hour time:%d:%.2d AM\n", hour, min);
    else if(hour > 12)
        printf("Equivalent 12-hour time:%d:%.2d PM\n", hour - 12, min);

    return 0;
}