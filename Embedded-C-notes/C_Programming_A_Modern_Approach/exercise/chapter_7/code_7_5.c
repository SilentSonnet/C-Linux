#include<stdio.h>
#include<ctype.h>
int main(void)
{
    int sum = 0;
    char ch;
    printf("Enter a word: ");
    while((ch = getchar()) != '\n')
    {
        ch = toupper(ch);
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
    }

    printf("Scrabble value: %d\n", sum);
    return 0;
}