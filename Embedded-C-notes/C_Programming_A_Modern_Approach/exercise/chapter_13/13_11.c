#include<stdio.h>

#define SIZE 100

char my_strcmp(char *s, char *t);

int main(void)
{
    char str_1[SIZE] = "Hello world!";
    char str_2[SIZE] = "Hello world!";

    if(my_strcmp(str_1, str_2) == 0)
        printf("The result is equal.\n");
    else    
        printf("The result is unequal.\n");

    return 0;
}

char my_strcmp(char *s, char *t)
{
    char *p = s, *q = t;
    while(*p == *q)
    {
        if(*p == '\0')
            return 0;
        p ++;
        q ++;
    }
    return *p - *q;
}