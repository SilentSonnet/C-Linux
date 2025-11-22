#include <stdio.h>

#define SIZE 10

void store_zeros(int *a, int n);

int main(void)
{
    int a[SIZE] = {0};
    for (int *p = a; p < a + SIZE; p++)
    {
        *p = p - a;
        printf("%d ", *p);
    }
    printf("\n");

    store_zeros(a, SIZE);

    for (int *p = a; p < a + SIZE; p++)
        printf("%d ", *p);
    printf("\n");

    return 0;
}

void store_zeros(int *a, int n)
{
    int *p;
    for (p = a; p < a + n; p++)
        *p = 0;
}
