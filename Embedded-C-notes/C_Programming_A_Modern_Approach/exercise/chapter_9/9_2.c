#include<stdio.h>
#include<stdbool.h>

bool check(int x, int y, int n);

int main(void)
{
    int x, y, n;
    printf("Enter the x and y: ");
    scanf("%d%d", &x, &y);
    printf("Enter the range of n: ");
    scanf("%d", &n);

    if(check(x, y, n))
        printf("X and Y is in the range of n!\n");
    else 
        printf("X and Y is not in the range of n!\n");

    return 0;
}

bool check(int x, int y, int n)
{
    if((0 <= x && x <= n - 1) && (0 <= y && y <= n - 1))
        return true;
    else 
        return false;
}