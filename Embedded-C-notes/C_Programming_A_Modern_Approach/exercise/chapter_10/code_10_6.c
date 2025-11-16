#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> /* C99 only */

#define STACK_SIZE 100
/* external variables */

int contents[STACK_SIZE];
int top = 0;

void calculator(void);

void stack_overflow()
{
    printf("Expression is too complex\n");
    exit(1);
}

void stack_underflow()
{
    printf("Not enough operands in expression\n");
    exit(1);
}

void make_empty(void)
{
    top = 0;
}

bool is_empty(void)
{
    return top == 0;
}

bool is_full(void)
{
    return top == STACK_SIZE;
}

void push(int number)
{
    if (is_full())
        stack_overflow();
    else
        contents[top++] = number;
}

int pop(void)
{
    if (is_empty())
    {
        stack_underflow();
        return '\0';
    }
    else
        return contents[--top];
}

int main(void)
{
    while(1)
    {
        calculator();
    }

    return 0;
}

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