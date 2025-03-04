#include <stdio.h>

int main()
{
    for(int i = 1;i <= 9;i ++)
    {
        for(int j = 1;j <= i;j ++)
        {
            printf("%d x %d = %2d ",j , i ,i * j); //强行占两位数
        }
        printf("\n");
    }
    return 0;
}
