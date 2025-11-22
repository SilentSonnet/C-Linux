#include<stdio.h>

void swap(int *p, int *q);  
int main(void)
{
    int i = 1, j = 2;
    printf("Before swappnig i : %d and j : %d\n", i, j);

    swap(&i, &j);

    printf("After swappnig i : %d and j : %d\n", i, j);

    return 0;
}

void swap(int *p, int *q)
{
    int temp;
    temp = *p;
    *p = *q;
    *q = temp;
}