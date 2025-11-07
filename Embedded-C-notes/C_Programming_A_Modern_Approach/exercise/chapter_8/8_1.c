#include<stdio.h>
int main(void)
{
    int a[10];
    // 模拟数组a的元素类型发生了变化
    double b[10];
    printf("%lu\n", sizeof(a) / sizeof(a[0]));
    printf("%lu\n", sizeof(b) / sizeof(int));

    return 0;
}