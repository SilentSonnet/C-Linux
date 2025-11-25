#include <stdio.h>
#include <string.h>

#define SIZE 20

int main(void)
{
    char smallest_word[SIZE], largest_word[SIZE], word[SIZE];

    printf("Enter word: ");
    scanf("%s", word);

    if(strlen(word) == 4)
    {
        printf("Error!\n");
        return 0;
    }

    strcpy(smallest_word, word);
    strcpy(largest_word, word);

    while (1)
    {
        printf("Enter word: ");
        scanf("%s", word);

        if (strlen(word) == 4)
            break;

        if (strcmp(smallest_word, word) > 0)
            strcpy(smallest_word, word);
        if (strcmp(largest_word, word) < 0)
            strcpy(largest_word, word);
    }

    printf("Smallest word: %s\n", smallest_word);
    printf("Largest word: %s\n", largest_word);

    return 0;
}