#include<stdio.h>

#define SIZE 100

int main(void)
{
    char sentence[SIZE];
    char *word_start, *word_end = sentence, end_symbol, ch;

    printf("Enter a sentence: ");

    while((ch = getchar()) != '\n')
    {
        if(ch == '.' || ch == '?' || ch == '!')
        {
            end_symbol = ch;
            break;
        }
        *word_end ++ = ch;
    }

    // find the end of the sentence
    word_end -= 1;

    while(word_end >= sentence)
    {
        while(word_end >= sentence && *word_end == ' ')
            word_end --;

        // aviod out-of-bounds memory access
        if(word_end < sentence)
            break;

        // find the end of one word
        char *end = word_end;
        // find the begin of one word
        while(word_end >= sentence && *word_end != ' ')
            word_end --;

        // obviously, now *word_end is ' '
        // so we need to mins 1 to find the begin of one word
        word_start = word_end + 1;

        while(word_start <= end)
            putchar(*word_start ++);

        if(word_end > sentence)
            putchar(' ');
    }
    printf("%c\n", end_symbol);

    return 0;
}