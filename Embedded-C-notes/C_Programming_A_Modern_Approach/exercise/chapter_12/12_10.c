#include<stdio.h>

#define SIZE 10

int *find_middle(int *a, int n);

int main(void)
{
    int a[SIZE] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    printf("%p\n", find_middle(a, SIZE));

    return 0;
}

int *find_middle(int *a, int n)
{
    return a + n / 2;
}