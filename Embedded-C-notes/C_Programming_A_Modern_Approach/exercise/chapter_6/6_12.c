#include<stdio.h>
int main(void)
{
    int n = 100;
    int is_prime = 1;
    for (int d = 2; d * d < n; d++)
        if (n % d == 0)
            is_prime = 0;
    if (is_prime)
        printf("%d is prime\n", n);
    else
        printf("%d is not prime\n", n);
    return 0;
}