#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> /* C99 only */

#define STACK_SIZE 100
/* external variables */

char contents[STACK_SIZE];
int top = 0;

void stack_overflow()
{
    printf("The stack is overflowed!\n");
    printf("Parenteses/braces are not nested properly\n");

    exit(1);
}

void stack_underflow()
{
    printf("The stack is underflowed!\n");
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

void push(int i)
{
    if (is_full())
        stack_overflow();
    else
        contents[top++] = i;
}

char pop(void)
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
    char ch;
    printf("Enter parenteses and/or braces: ");
    while ((ch = getchar()) != '\n')
    {
        if (ch == '(' || ch == '{')
            if (!is_full())
                push(ch);
            else
                stack_overflow();
        else if (ch == ')' || ch == '}')
        {
            char stack_top;
            stack_top = pop();
            if ((stack_top == '(' && ch == ')') || (stack_top == '{' && ch == '}'))
                ;
            else
                push(stack_top);
        }
        else
            printf("False input, ingored.\n");
    }

    if (is_empty())
        printf("Parenteses/braces are nested properly\n");
    else
        printf("Parenteses/braces are not nested properly\n");

    return 0;
}