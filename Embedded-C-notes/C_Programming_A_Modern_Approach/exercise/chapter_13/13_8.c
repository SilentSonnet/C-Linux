#include <stdio.h>
#include <string.h>

#define SIZE 100

int main(void)
{
    char str[SIZE];

    strcpy(str, "tire-bouchon");
    strcpy(&str[4], "d-or-wi");
    strcat(str, "red?");

    printf("The string is : %s\n", str);

    return 0;
}