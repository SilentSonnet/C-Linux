#include<stdio.h>
#include<ctype.h>

#define SIZE 100

int main(void)
{
    char ch, arr[SIZE], index = 0;

    printf("Enter a message: ");
    while((ch = getchar()) != '\n' && ch != EOF)
    {
        arr[index ++] = ch;
    }

    printf("Reversal is: ");
    while(index != 0)
    {
        printf("%c", arr[--index]);
    }
    printf("\n");

    return 0;
}