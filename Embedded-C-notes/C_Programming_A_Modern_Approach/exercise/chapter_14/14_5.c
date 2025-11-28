#include <stdio.h>
#include <string.h>

#define SIZE 100
#define TOUPPER(c) ('a' <= (c) && (c) <= 'z' ? (c) - 'a' + 'A' : (c))

int main(void)
{
    char s[SIZE];
    int i;

    strcpy(s, "abcd");
    i = 0;
    putchar(TOUPPER(s[++i]));

    strcpy(s, "0123");
    i = 0;
    putchar(TOUPPER(s[++i]));

    return 0;
}