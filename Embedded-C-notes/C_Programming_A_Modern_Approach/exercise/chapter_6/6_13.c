#include<stdio.h>
int main(void)
{
    int n = 0, m = 100;
    for(;;)
    {
        if(m > 0)
        {
            m /= 2;
            n ++;
            printf("%d ", m);
        }
        else
        {
            printf("\n");
            break;
        }
    }

    return 0;
}