#ifndef STACK_H
#define STACK_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 100

/* external variables */

extern int contents[];
extern int top;

void stack_overflow();
void stack_underflow();
void make_empty(void);
bool is_empty(void);
bool is_full(void);
void push(int number);
int pop(void);

#endif