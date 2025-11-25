#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#define SIZE 100

bool is_palindrome(const char *message);

int main(void)
{
    int i = 0;
    char ch, arr[SIZE];
    bool isPalindrome = true;

    printf("Enter a message: ");
    while ((ch = getchar()) != '\n')
        if ('a' <= tolower(ch) && tolower(ch) <= 'z')
            arr[i ++] = ch;
    arr[i] = '\0';

    if (is_palindrome(arr))
        printf("Palindrome\n");
    else
        printf("Not a palindrome\n");

    return 0;
}

bool is_palindrome(const char *message)
{
    const char *start = message, *end;
    end = start + strlen(message) - 1;

    while (start < end)
    {
        if (tolower(*start ++) != tolower(*end --))
        {
            return false;
        }
    }
    return true;
}