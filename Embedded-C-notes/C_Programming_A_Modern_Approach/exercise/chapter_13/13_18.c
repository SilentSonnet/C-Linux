#include<stdio.h>
#include<ctype.h>
#include<string.h>

#define SIZE 100

void remove_filename(char *url);

int main(void)
{
    char url[SIZE] = "http://www.knking.com/index.html";

    remove_filename(url);

    printf("The string is : %s\n", url);

    return 0;
}

void remove_filename(char *url)
{
    char *str = url + strlen(url) - 1;
    while(*str)
    {
        if(*str == '/')
        {
            *str = '\0';
            break;
        }
        str --;
    }
}