#include<stdio.h>
int main(void)
{
    int a, b, c, d;
    a = 'A';
    b = 0b1000001;
    c = 0101;
    d = 0x41;

    printf("%d\n%d\n%d\n%d\n", a, b, c, d);

    return 0;
}