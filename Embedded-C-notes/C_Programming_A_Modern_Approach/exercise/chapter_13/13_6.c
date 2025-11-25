#include <stdio.h>
#include <string.h>

#define SIZE 100

void censor(char s[]);

int main(void)
{
    char arr[SIZE] = "abcdefoofofoo&&fffoo";

    printf("The string is : %s\n", arr);

    censor(arr);

    printf("The string is : %s\n", arr);

    return 0;
}

void censor(char s[])
{
    for(int i = 0;s[i] != '\0';i ++)
        if(s[i] == 'f' && s[i + 1] == 'o' && s[i + 2] == 'o')
            s[i] = s[i + 1] = s[i + 2] = 'x';
}