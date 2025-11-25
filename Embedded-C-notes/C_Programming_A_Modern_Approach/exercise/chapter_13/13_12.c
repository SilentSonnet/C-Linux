#include<stdio.h>
#include<string.h>
#include<stdbool.h>

#define SIZE 100

void get_extension(const char *file_name, char *extension);

int main(void)
{
    char file_name_1[SIZE] = "main.c";
    char file_name_2[SIZE] = "main", extension[SIZE];

    printf("The file name is : %s\n", file_name_1);
    get_extension(file_name_1, extension);
    printf("The extension of the file is : %s\n", extension);

    printf("The file name is : %s\n", file_name_2);
    get_extension(file_name_2, extension);
    printf("The extension of the file is : %s\n", extension);

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