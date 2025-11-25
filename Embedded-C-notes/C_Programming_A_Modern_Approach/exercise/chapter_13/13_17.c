#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<ctype.h>

#define SIZE 100

bool test_extension(const char *file_name, const char *extension);
void get_extension(const char *file_name, char *extension);

int main(void)
{
    char file_name_1[SIZE] = "main.txt";
    char file_name_2[SIZE] = "main", extension[SIZE];

    if(test_extension(file_name_1, "TXT"))
        printf("Match!\n");
    else
        printf("Don't match!\n");

    return 0;
}

void get_extension(const char *file_name, char *extension)
{
    const char *p = file_name;
    bool found = false;
    while(*p != '\0')
    {
        if(*p == '.')
        {
            found = true;
            break;
        }
        p ++;
    }
    if(found && *(p + 1) != '\0')
        strcpy(extension, p + 1);
    else
        strcpy(extension, "");
}

bool test_extension(const char *file_name, const char *extension)
{
    char file_extension[SIZE], *p = file_extension;

    get_extension(file_name, file_extension);

    while(*p)
    {
        *p = toupper(*p);
        p ++;
    }

    if(strcmp(file_extension, extension) == 0)
        return true;
    else 
        return false;
}