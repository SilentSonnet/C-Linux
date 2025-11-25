#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define NUM 21
#define LENGTH 31

int main(void)
{
    char word[NUM][LENGTH], ch, symbol;
    int number = 0, length = 0;

    printf("Enter a sentence: ");

    while ((ch = getchar()) != '\n')
    {
        if (ch == '?' || ch == '.' || ch == '!')
        {
            word[number][length] = '\0';
            symbol = ch;
            break;
        }

        if (!isspace(ch))
            word[number][length++] = ch;
        else
        {
            word[number][length] = '\0';
            number++;
            length = 0;
        }
    }

    for (int i = number; i >= 0; i--)
    {
        printf("%s", word[i]);

        if(i)
            printf(" ");
    }
    printf("%c\n", symbol);
}