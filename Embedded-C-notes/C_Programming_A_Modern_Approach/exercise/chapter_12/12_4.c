#include <stdbool.h> /* C99 only */
#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 100

/* external variables */
int contents[STACK_SIZE];
int top = 0;

int *top_ptr = contents;

void make_empty(void);
bool is_empty(void);
bool is_full(void);
void push(int i);
int pop(void);

int stack_overflow(void);
int stack_underflow(void);

int main(void)
{
    for(int i = 0;i < STACK_SIZE;i ++)
        push(i);
    for(int i = 0;i < STACK_SIZE;i ++)
        printf("%d ", pop());
    printf("\n");

    return 0;
}

void make_empty(void)
{
    top_ptr = contents;
}

bool is_empty(void)
{
    return top_ptr == contents;
}

bool is_full(void)
{
    return top_ptr == contents + STACK_SIZE;
}

void push(int i)
{
    if (is_full())
        stack_overflow();
    else
        *top_ptr++ = i;
}

int pop(void)
{
    if (is_empty())
    {
        stack_underflow();
        return 0;
    }
    else
        return *--top_ptr;
}

int stack_overflow(void)
{
    printf("The stack is overflowed!\n");
    exit(1);
}

int stack_underflow(void)
{
    printf("The stack is underflowed!\n");
    exit(1);
}