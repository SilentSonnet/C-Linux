#include <stdio.h>
int main(void)
{
    double number, res;
    char op;
    printf("Enter an expression: ");

    // 先获取第一个数字
    scanf("%lf", &res);
    while (1)
    {
        scanf("%c", &op);
        if (op == '\n')
            break;
        scanf("%lf", &number);
        if (op == '+')
            res += number;
        else if (op == '-')
            res -= number;
        else if (op == '*')
            res *= number;
        else if (op == '/')
            res /= number;
    }
    printf("Value of expression: %.2f\n", res);

    return 0;
}