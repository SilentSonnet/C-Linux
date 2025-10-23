// 程序是合法的但不是合理的，无法得到字面的程序期望。
#include<stdio.h>
int main(void)
{
    int n = 5;
    if (n == 1 - 10) 
        printf("n is between 1 and 10\n"); 

    return 0;
}