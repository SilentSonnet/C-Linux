#include<stdio.h>
#include<ctype.h>

#define SIZE 100

int main(void)
{
    char ch, arr[SIZE], *p;

    p = arr;

    printf("Enter a message: ");
    while((ch = getchar()) != '\n' && ch != EOF)
    {
        *p++ = ch;
    }

    printf("Reversal is: ");
    while(p != arr)
    {
        printf("%c", *--p);
    }
    printf("\n");

    return 0;
}