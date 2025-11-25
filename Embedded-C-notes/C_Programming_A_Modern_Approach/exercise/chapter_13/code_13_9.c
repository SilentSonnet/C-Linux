#include<stdio.h>
#include<ctype.h>

#define SIZE 100

int compute_vowel_count(const char *sentence);

int main(void)
{
    char sentence[SIZE], ch;
    int i = 0;

    printf("Enter a sentence: ");
    while((ch = getchar()) != '\n')
    {
        sentence[i ++] = ch;
    }
    sentence[i] = '\0';

    printf("Your sentence contains %d vowels.\n", compute_vowel_count(sentence));

    return 0;
}

int compute_vowel_count(const char *sentence)
{
    int sum = 0;
    const char *p = sentence;

    while(*p)
    {
        char ch = toupper(*p);
        if(ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')
            sum ++;
        p ++;
    }
    return sum;
}