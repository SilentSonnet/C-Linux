#include<stdio.h>
int main(void)
{
    int m, n, a, b, temp, gcd;
    printf("Enter a fraction: ");
    scanf("%d / %d", &m, &n);
 
    a = m;
    b = n;
    while(n != 0)
    {
        temp = n;
        n = m % n;
        m = temp;
    }
    gcd = m;

    printf("In lowest terms: %d/%d\n", a / gcd, b / gcd);

    return 0;
}