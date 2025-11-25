#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> /* C99 only */

#define STACK_SIZE 100
#define SIZE 100
/* external variables */

int contents[STACK_SIZE];
int top = 0;

void calculator(void);
int evaluate_RPN_expression(const char *expression);

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
    char ch, expression[SIZE];
    int i = 0;

    printf("Enter an RPN expression: ");
    while((ch = getchar()) != '\n')
        expression[i ++] = ch;
    expression[i] = '\0';

    printf("Value of expression: %d\n", evaluate_RPN_expression(expression));
}

int evaluate_RPN_expression(const char *expression)
{
    const char *p = expression;
        int res, op1, op2;

    while(*p)
    {
        if(*p == 'q')
            exit(0);
        if(*p == '=')
        {
            res = pop();
            make_empty();
            return res;
        }
        if(*p == '+' || *p == '-' || *p == '*' || *p == '/')
        {
            op1 = pop();
            op2 = pop();

            switch (*p)
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

        if('0' <= *p && *p <= '9')
            push(*p - '0');

        p ++;
    }
    return 1;
}