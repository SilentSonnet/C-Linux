#include<stdio.h>

#define SIZE 100

int count_spaces(const char *s);

int main(void)
{
    char str[SIZE] = "12 34 56 78";

    printf("There is %d space in the string of %s\n", count_spaces(str), str);

    return 0;
}

int count_spaces(const char *s)
{
    int count = 0;
    while(*s)
    {
        if(*s == ' ')
            count++;
        s ++;
    }
    return count;
}