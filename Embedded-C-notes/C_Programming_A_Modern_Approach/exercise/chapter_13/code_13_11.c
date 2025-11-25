#include <stdio.h>

#define SIZE 100

double compute_average_word_length(const char *sentence);

int main(void)
{
    char sentence[SIZE], ch;
    int i = 0;

        printf("Enter a sentence: ");
    while((ch = getchar()) != '\n')
        sentence[i ++] = ch;
    sentence[i] = '\0';

    printf("Average word length: %.1f\n", compute_average_word_length(sentence));
    
    return 0;
}

double compute_average_word_length(const char *sentence)
{
    int w_num = 1, c_num = 0;
    const char *p = sentence;
    double ave;

    while (*p)
    {
        if (*p == ' ')
            w_num++;
        else if (*p != ' ' && *p != '.')
            c_num++;
        p ++;
    }
    return c_num * 1.0f / w_num;
}