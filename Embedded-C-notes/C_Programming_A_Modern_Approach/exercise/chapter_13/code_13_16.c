// (b)
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SIZE 100

void reverse(char *message);

int main(void)
{
    char ch, arr[SIZE], *p;
    int i = 0;

    p = &arr[0];

    printf("Enter a message: ");

    while ((ch = getchar()) != '\n')
        arr[i++] = ch;
    arr[i] = '\0';

    reverse(arr);

    printf("Reversal is: %s\n", arr);

    return 0;
}

void reverse(char *message)
{
    char *p = message, *q = message + strlen(message) - 1, temp;
    while (p < q)
    {
        temp = *p;
        *p = *q;
        *q = temp;

        p++;
        q--;
    }
}