#include<stdio.h>
#include<stdbool.h>
#include<ctype.h>

#define SIZE 100

int main(void)
{
    char ch, arr[SIZE], *start = arr, *end = arr;
    bool isPalindrome = true;

    printf("Enter a message: ");
    while((ch = getchar()) != '\n' && ch != EOF)
    {
        if('a' <= tolower(ch) && tolower(ch) <= 'z')
            *end ++ = ch;
    }

    while(start < end)
    {
        if(tolower(*start ++) != tolower(* -- end))
        {
            isPalindrome = false;
            break;
        }
    }

    if(isPalindrome)
        printf("Palindrome\n");
    else    
        printf("Not a palindrome\n");

    return 0;
}