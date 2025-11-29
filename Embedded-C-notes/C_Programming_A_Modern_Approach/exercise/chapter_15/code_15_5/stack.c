#include "stack.h"

int contents[STACK_SIZE];
int top = 0;

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