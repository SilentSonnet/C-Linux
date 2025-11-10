#include <stdio.h>
#include <ctype.h>

#define MAX_NAME_LENGTH 20

int main(void)
{
    int i = 0, j = 0;
    char name[MAX_NAME_LENGTH], surname[MAX_NAME_LENGTH], ch;
    printf("Enter a first and last name: ");

    while((ch = getchar()) == ' ' || ch == '\t');
    while((ch = getchar()) != ' ')
    {
        name[i ++] = ch;
    }

    while ((ch = getchar()) != '\n')
    {
        if ('A' <= toupper(ch) && toupper(ch) <= 'Z')
        {
            surname[j ++] = ch;
        }
    }

    for(int i = 0;i < j;i ++)
    {
        printf("%c", surname[i]);
    }   
    printf(", %c.\n", toupper(name[0]));

    return 0;
}