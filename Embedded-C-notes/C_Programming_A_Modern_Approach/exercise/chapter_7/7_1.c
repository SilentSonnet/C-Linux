#include<stdio.h>
int main(void)
{
    int a, b, c;
    
    a = 077;
    b = 0x77;
    c = 0xABC;

    printf("%d %d %d", a, b, c);

    return 0;
}