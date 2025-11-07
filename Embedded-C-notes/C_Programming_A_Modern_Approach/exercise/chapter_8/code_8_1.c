#include <stdbool.h> /* C99 only */
#include <stdio.h>

int main(void)
{
    bool digit_seen[10] = {false}, digit_rep[10] = {false}, isrepeated = false;
    int digit;
    long n;

    printf("Enter a number: ");
    scanf("%ld", &n);

    while (n > 0)
    {
        digit = n % 10;
        if (!digit_seen[digit])
        {
            digit_seen[digit] = true;
        }
        else if (digit_seen[digit])
        {
            digit_rep[digit] = true;
            isrepeated = true;
        }
        n /= 10;
    }

    if (isrepeated)
    {
        printf("Repeated digit: ");
        for (int i = 0; i < 10; i++)
        {
            if (digit_rep[i])
                printf("%d ", i);
        }
        printf("\n");
    }
    else
        printf("No repeated digit\n");

    return 0;
}
