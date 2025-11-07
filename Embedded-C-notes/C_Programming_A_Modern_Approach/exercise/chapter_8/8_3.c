#include<stdio.h>
#include<stdbool.h>
int main(void)
{
	bool weekend[7] = {true, false, false, false, false, false, true};
    for(int i = 0;i < 7;i ++)
    {
        printf("%d ", weekend[i]);
    }
    printf("\n");

    return 0;
}