#include <stdio.h>

int sum_array(const int *a, int n);

int main(void)
{
    int a[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    printf("%d\n", sum_array(a, 10));

    return 0;
}

int sum_array(const int *a, int n)  
{  
    const int *p;  
    int sum = 0;  
    for (p = a; p < a + n;p ++)  
        sum += *p;  
    return sum;  
}