#include<stdio.h>

int gcd(int m, int n);

int main(void)
{
    int m, n, temp;
    printf("Enter two integers: ");
    scanf("%d %d", &m, &n);

    printf("Greatest common divisor: %d\n", gcd(m, n));
    return 0;
}

int gcd(int m, int n)
{
    int temp;
    while(n != 0)
    {
        temp = n;
        n = m % n;
        m = temp;
    }
    return m;
}