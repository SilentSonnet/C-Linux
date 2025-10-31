#include <stdio.h>
int main(void)
{
    int number, m = 0;
    printf("Enter a number:");
    scanf("%d", &number);

    if (number < 4)
    {
        printf("False input!");
        return 0;
    }

    int i = 1;
    while(1)
    {
        if (i % 2 == 0)
        {
            m = i * i;
            if (m <= number)
            {
                printf("%d\n", m);
            }
            else
                return 0;
        }
        i++;
    }

    return 0;
}