#include <stdbool.h> /* C99 only */
#include <stdio.h>

int main(void)
{
    int digit_count[10] = {0};
    int digit;
    long n;

    printf("Enter a number: ");
    while (1)
    {
        scanf("%ld", &n);
        if (n <= 0)
            break;

        while (n > 0)
        {
            digit = n % 10;
            digit_count[digit]++;
            n /= 10;
        }
    }

    printf("Digit:       ");

    for (int i = 0; i < 10; i++)
    {
        printf("%d ", i);
    }
    printf("\n");

    printf("Occurrences: ");
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", digit_count[i]);
    }
    printf("\n");

    return 0;
}
