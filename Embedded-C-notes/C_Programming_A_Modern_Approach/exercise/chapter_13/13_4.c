#include <stdio.h>
#include <ctype.h>

#define SIZE 10
#define BIG_SIZE 100

int read_line(char str[], int n);

int main(void)
{
    char myString[SIZE + 1];
    char yourString[SIZE + 1];

    printf("Enter a string : ");

    read_line(myString, SIZE);
    read_line(yourString, SIZE);

    printf("The string is : %s\n", myString);
    printf("The string is : %s\n", yourString);

    return 0;
}

#if 0
int read_line(char str[], int n)
{
    int ch, i = 0;
    while ((ch = getchar()) != '\n')
    {
        if(i == 0 && isspace(ch))
            continue;
        if (i < n)
            str[i++] = ch;
    }
    str[i] = '\0';
    return i;
}
#endif

#if 0
int read_line(char str[], int n)
{
    int ch, i = 0;
    while ((ch = getchar()) != '\n' && !isspace(ch))
        if (i < n)
            str[i++] = ch;
    str[i] = '\0';
    return i;
}
#endif

#if 0
int read_line(char str[], int n)
{
    int ch, i = 0;
    do
    {
        ch = getchar();
        if (i < n)
            str[i++] = ch;
    } while (ch != '\n');

    str[i] = '\0';
    return i;
}
#endif
#if 0
int read_line(char str[], int n)
{
    int ch, i = 0;
    while ((i < n) && (ch = getchar()) != '\n')
        str[i++] = ch;
    str[i] = '\0';
    return i;
}
#endif
int read_line(char str[], int n)
{
    int ch, i;

    for (i = 0; i < n; i++)
    {
        ch = getchar();
        if (ch == '\n')
            break;
        str[i] = ch;
    }
    str[i] = '\0';
    return i;
}