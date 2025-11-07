#include<stdio.h>
int main(void)
{
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    printf("%d ", a['0' - '0']);
    printf("%d ", a['1' - '0']);
    printf("%d ", a['2' - '0']);
    printf("%d ", a['3' - '0']);
    printf("%d ", a['4' - '0']);
    printf("%d ", a['5' - '0']);
    printf("%d ", a['6' - '0']);
    printf("%d ", a['7' - '0']);
    printf("%d ", a['8' - '0']);
    printf("%d\n", a['9' - '0']);

    return 0;
}