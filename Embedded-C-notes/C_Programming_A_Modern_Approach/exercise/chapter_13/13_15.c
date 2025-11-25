#include <stdio.h>

int f(char *s, char *t);

int main(void)
{
    printf("The result of f(\"abcd\", \"babc\") is %d\n", f("abcd", "babc")); 
    printf("The result of f(\"abcd\", \"bcd\")) is %d\n", f("abcd", "bcd"));
    return 0;
}

int f(char *s, char *t)
{
    char *p1, *p2;
    for (p1 = s; *p1; p1++)
    {
        for (p2 = t; *p2; p2++)
            if (*p1 == *p2)
                break;
        if (*p2 == '\0')
            break;
    }
    return p1 - s;
}