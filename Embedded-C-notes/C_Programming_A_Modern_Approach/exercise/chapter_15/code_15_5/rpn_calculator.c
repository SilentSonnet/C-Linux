#include "rpn_calculator.h"

void calculator(void)
{
    char ch;
    int res, op1, op2;

    printf("Enter an RPN expression: ");
    while(1)
    {
        ch = getchar();
        if(ch == 'q')
            exit(0);
        if(ch == '=')
        {
            printf("Value of expression: %d\n", res);
            make_empty();
            return ;
        }
        if(ch == '+' || ch == '-' || ch == '*' || ch == '/')
        {
            op1 = pop();
            op2 = pop();

            switch (ch)
            {
            case '+':
                res = op2 + op1;
                push(res);
                break;
            case '-':
                res = op2 - op1;
                push(res);
                break;
            case '*':
                res = op2 * op1;
                push(res);
                break;
            case '/':
                res = op2 / op1;
                push(res);
                break;
            
            default:
                break;
            }
        }
        if('0' <= ch && ch <= '9')
            push(ch - '0');
    }
}