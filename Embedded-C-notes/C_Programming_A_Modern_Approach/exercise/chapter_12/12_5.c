#include <stdio.h>

int *p, a[5] = {0};

int main(void)
{
    p = a;
    
    printf("%d\n", p == a[0]);
    printf("%d\n", p == &a[0]);
    printf("%d\n", *p == a[0]);
    printf("%d\n", p[0] == a[0]);

    return 0;
}