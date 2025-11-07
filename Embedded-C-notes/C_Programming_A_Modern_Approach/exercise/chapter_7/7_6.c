#include<stdio.h>
int main(void)
{
    char a;
    short int b, c;
    int d;

    a = 31;
    b = 365;
    c = 60 * 24;
    d = 60 * 60 * 24;

    printf("%d\n%d\n%d\n%d\n", a, b, c, d);

    return 0;
}