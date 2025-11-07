#include<stdio.h>
#include<ctype.h>
int main(void)
{
    char ch;
    int sum = 0;
    printf("Enter a sentence: ");
    while((ch = getchar()) != '\n')
    {
        ch = toupper(ch);
        if(ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')
            sum ++;
    }

    printf("Your sentence contains %d vowels.\n", sum);

    return 0;
}