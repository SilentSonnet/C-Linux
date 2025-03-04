#include <stdio.h>

int main()
{
    for(int number = 100;number <=999; number ++)
    {
        int a, b, c;
        a = number % 10; //获取number的个位
        b = (number / 10) % 10; //获取number的十位
        c = number /100; //获取number的百位

        if (a * a * a + b * b * b + c * c * c == number )
            printf("%d\n", number);
    }
    return 0;
}