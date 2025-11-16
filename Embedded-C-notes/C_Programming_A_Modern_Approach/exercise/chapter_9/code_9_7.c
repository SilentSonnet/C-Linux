#include<stdio.h>

int calculate_polynomial(int x);
int power(int x, int n);
int main(void)
{
    int x;
    printf("Enter a number : ");
    scanf("%d", &x);

    printf("The result of the polynomial is : %d\n", calculate_polynomial(x));

    return 0;
}

int calculate_polynomial(int x)
{
    int res;
    res = 3 * power(x, 5) + 2 * power(x, 4) - 5 * power(x, 3) - power(x, 2) + 7 * x - 6;

    return res;
}

int power(int x, int n)
{
    if (n == 0)
        return 1;
    else if( n % 2 == 0)
    {
        int res = power(x, n / 2);
        return res * res;
    }
    else 
        return x * power(x, n -1);
}