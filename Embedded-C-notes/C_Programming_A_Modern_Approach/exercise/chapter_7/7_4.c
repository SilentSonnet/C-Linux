#include <stdio.h>
int main(void)
{
    int i;
    char c;
    i += c; /* i has type int */
    c = 2 * c - 1;
    putchar(c);
    printf(c);

    return 0;
}
