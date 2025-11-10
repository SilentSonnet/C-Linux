#include <stdio.h>
int main(void)
{
    char sentence[100], ch, end_flag;
    int index[10], word = 0, length = 0, word_number;
    printf("Enter a sentence: ");

    // There are two symbols to mark the end of a word: '.' and ' '.
    while ((ch = getchar()) != '\n')
    {
        if (ch == '.' || ch == '?' || ch == '!')
        {
            end_flag = ch;
            index[word++] = length;
            break;
        }
        else
        {
            if (ch == ' ')
            {
                index[word++] = length;
            }
            sentence[length++] = ch;
        }
    }

#if 0
    printf("The number of words is: %d\n", word);
    printf("The length of the sentence is: %d\n", length);
    for(int i = 0; i < word; i++)
        printf("%d ", index[i]);
    printf("\n");

    for(int j = 0; j <= length; j++)
        printf("%c", sentence[j]);
    printf("\n");
#endif

    // you can cage a swallow can't you? (A well-known phrase used humorously)
    // The count of the words begins with 1.
    // Printing starts from the last word.
    word_number = word;
    for (int i = 0; i < word; i++)
    {
        // Set the start and the end of the word for each printed word
        int start, end;
        if ((word_number - 2) < 0)
        {
            start = 0;
            end = index[word_number - 1];
        }
        else
        {
            start = index[word_number - 2] + 1;
            end = index[word_number - 1];
        }

        // Print from the last word
        for (int j = start; j < end; j++)
        {
            printf("%c", sentence[j]);
        }
        word_number--;

        // When all the words are printed out, the value of word_number would be negative
        if(word_number > 0)
            printf(" ");
    }
    printf("%c\n", end_flag);

    return 0;
}
