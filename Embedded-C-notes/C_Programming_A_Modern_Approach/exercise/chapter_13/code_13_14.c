#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

#define SIZE 100

bool are_anagrams(const char *word1, const char *word2);

int main(void)
{
    char word1[SIZE], word2[SIZE];

    printf("Enter first word: ");
    scanf("%s", word1);

    printf("Enter second word: ");
    scanf("%s", word2);

    if (are_anagrams(word1, word2))
        printf("The words are anagrams.\n");
    else
        printf("The words are not anagrams.\n");

    return 0;
}

bool are_anagrams(const char *word1, const char *word2)
{
    int sum = 0, count[26] = {0};
    const char *p = word1, *q = word2;

    while (*p)
    {
        if (isalpha(*p))
            count[tolower(*p++) - 'a']++;
        else
            p++;
    }

    while (*q)
    {
        if (isalpha(*q))
            count[tolower(*q++) - 'a']--;
        else
            q++;
    }

    for (int i = 0; i < 26; i++)
        sum += count[i];

    return sum == 0;
}