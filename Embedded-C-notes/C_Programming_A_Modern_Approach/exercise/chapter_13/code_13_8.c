#include<stdio.h>
#include<ctype.h>

#define SIZE 100

int compute_scrabble_value(const char *word);

int main(void)
{
    char word[SIZE];

    printf("Enter a word: ");
    scanf("%s", word);

    printf("Scrabble value: %d\n", compute_scrabble_value(word));
    return 0;
}

int compute_scrabble_value(const char *word)
{
    int sum = 0;
    const char *p = word;
    while(*p)
    {
        char ch = toupper(*p);
        // AEILNORSTU
        if(ch == 'A' || ch == 'E' || ch == 'I' || ch == 'L' || ch == 'N' || ch == 'O' || ch == 'R' || ch == 'S' || ch == 'T' || ch == 'U')
        {
            sum += 1;
        }
        // DG
        if(ch == 'D' || ch == 'G')
        {
            sum += 2;
        }
        // BCMP
        if(ch == 'B' || ch == 'C' || ch == 'M' || ch == 'P')
        {
            sum += 3;
        }
        // FHVWY
        if(ch == 'F' || ch == 'H' || ch == 'V' || ch == 'W' || ch == 'Y')
        {
            sum += 3;
        }
        // K
        if(ch == 'K')
        {
            sum += 4;
        }
        // JX
        if(ch == 'J' || ch == 'X')
        {
            sum += 5;
        }
        // QZ
        if(ch == 'Q' || ch == 'Z')
        {
            sum += 5;
        }
        p ++;
    }
    return sum;
}