#include<stdio.h>
int main(void)
{
    int m, n, temp, gcd;
    printf("Enter two integers: ");
    scanf("%d %d", &m, &n);
    while(n != 0)
    {
        temp = n;
        n = m % n;
        m = temp;
    }
    gcd = m;

    printf("Greatest common divisor: %d\n", gcd);
    return 0;
}