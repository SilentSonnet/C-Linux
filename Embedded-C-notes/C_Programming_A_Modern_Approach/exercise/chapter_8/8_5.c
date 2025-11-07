#include<stdio.h>
int main(void)
{
    int a[40] = {0, 1};
    printf("%d\n%d\n", a[0], a[1]);

    for(int i = 2;i < 40;i ++)
    {
        a[i] = a[i - 1] + a[i - 2];
        printf("%d\n", a[i]);
    }

    return 0;
}
