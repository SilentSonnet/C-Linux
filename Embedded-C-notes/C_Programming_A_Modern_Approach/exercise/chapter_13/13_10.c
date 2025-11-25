#include <stdio.h>
#include <string.h>

#define SIZE 100

void duplicate(const char *p, char *q);

int main(void)
{
    char string[SIZE] = "string";
    char string_copy[SIZE];
    duplicate(string, string_copy);
    printf("The string is : %s\n", string_copy);

    return 0;
}

void duplicate(const char *p, char *q)
{
    strcpy(q, p);
}