#include <stdio.h>

int main(void)
{
#define M 10
#if M
    printf("#if M is successful!\n");
#ifdef M
    printf("#ifdef M is successful!\n");
#ifndef M 
    printf("#ifndef M 2is successful!\n");
#if defined(M)
    printf("#if defined(M) is successful!\n");
#if !defined(M)
    printf("#if !defined(M) is successful!\n");
    return 0;
}