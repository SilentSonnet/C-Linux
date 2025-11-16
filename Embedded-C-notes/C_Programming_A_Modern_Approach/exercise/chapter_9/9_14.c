#include <stdio.h>
#include <stdbool.h>

bool has_zero(int a[], int n);

int main(void)
{
    int a[10] = {1, 2, 3, 4, 5, 0, 6, 7, 8, 9};
    if(has_zero(a, 10))
        printf("Contains zero.\n");
    else 
        printf("Does not contain zero.\n");

    return 0;
}

bool has_zero(int a[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        if (a[i] == 0)
            return true;

    return false;
}