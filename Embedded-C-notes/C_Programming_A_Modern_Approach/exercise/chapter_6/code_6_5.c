#include <stdio.h>
int main(void)
{
    int number, m;
    printf("Enter a number:");
    scanf("%d", &number);
    printf("The reversal is: ");
    do
    {
        m = number % 10;
        number /= 10;
        printf("%d", m);
    } while (number != 0);

    printf("\n");
    return 0;
}