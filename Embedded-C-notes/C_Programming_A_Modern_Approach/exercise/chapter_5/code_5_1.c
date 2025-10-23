#include<stdio.h>
int main(void)
{
    int number;
    printf("Enter a number:");
    scanf("%d", &number);

    if(number > 999)
        printf("4\n");
    else if(number > 99)
        printf("3\n");
    else if(number > 9)
        printf("2\n");
    else
        printf("1\n");

    return 0;
}