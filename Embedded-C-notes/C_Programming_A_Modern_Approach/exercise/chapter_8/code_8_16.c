#include<stdio.h>
#include<ctype.h>
int main(void)
{
    int count[26] = {0}, sum = 0;
    char ch;

    printf("Enter first word: ");
    while((ch = getchar()) != '\n')
    {
        count[tolower(ch) - 'a'] ++;
    }

    printf("Enter second word: ");
    while((ch = getchar()) != '\n')
    {
        count[tolower(ch) - 'a'] --;
    }

    for(int i = 0;i < 26;i ++)
        sum += count[i];
    if(sum == 0)
        printf("The words are anagrams.\n");
    else 
        printf("The words are not anagrams.\n");

    return 0;
}