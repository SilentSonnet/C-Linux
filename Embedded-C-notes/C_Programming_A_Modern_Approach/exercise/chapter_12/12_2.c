#include <stdio.h>

int a[] = {5, 15, 34, 54, 14, 2, 52, 72}; 
int *low = &a[1], *high = &a[5], *middle;

int main(void)
{
    middle = (int *)((long)middle + (long)(low - high));

    return 0;
}