#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

#define SIZE 100

void reverse_name(char *name);

int main(void)
{
    int i = 0;
    char name[SIZE], ch;
    printf("Enter a first and last name: ");

    while((ch = getchar()) != '\n')
        name[i ++] = ch;
    name[i] = '\0';

    reverse_name(name);

    return 0;
}

void reverse_name(char *name)
{
    char *p = name, firstLetter;
    while(isspace(*p))
        p ++;
    firstLetter = *p;

    while(!isspace(*p))
        p ++;

    while(isspace(*p))
        p ++;

    while(*p && !isspace(*p))
        printf("%c", *p++);
    
    printf(", %c\n", firstLetter);
}