#include <stdio.h>

int fact(int n);

int main(void)
{
    int n;
    printf("Enter a number : ");
    scanf("%d", &n);

    printf("The fact of %d is : %d\n", n, fact(n));

    return 0;
}
int fact(int n)
{
    int res = 1;
    while(n > 0)
    {
        res *= n;
        n --;
    }

    return res;
}