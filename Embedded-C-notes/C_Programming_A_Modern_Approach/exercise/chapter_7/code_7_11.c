#include <stdio.h>
#include <ctype.h>
int main(void)
{
    int flag = 0;
    char name, ch;
    printf("Enter a first and last name: ");

    // skip leading spaces before the first name
    while((ch = getchar()) == ' ' || ch == '\t');
    // store the first initial
    name = ch;

    while ((ch = getchar()) != '\n')
    {
        if (flag)
        {
            if(ch == ' ' || ch == '\t')
            {
                break;
            }
            printf("%c", ch);
        }

        // skip all letters before the last name
        if ('A' <= ch && ch <= 'Z')
        {
            printf("%c", ch);
            flag = 1;
        }
    }

    printf(", %c.\n", name);

    return 0;
}
