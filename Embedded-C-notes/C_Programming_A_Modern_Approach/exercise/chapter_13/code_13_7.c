#include <stdio.h>

const char *teens[] = {
    "ten", "eleven", "twelve", "thirteen", "fourteen",
    "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};

const char *tens_words[] = {
    "", "", "twenty", "thirty", "forty", "fifty",
    "sixty", "seventy", "eighty", "ninety"};

const char *ones_words[] = {
    "", "-one", "-two", "-three", "-four", "-five",
    "-six", "-seven", "-eight", "-nine"};

int main(void)
{
    int number, ones, tens;

    printf("Enter a two-digit number: ");
    scanf("%d", &number);

    if (number < 10 || number > 99)
    {
        printf("Error: input must be a two-digit number.\n");
        return 1;
    }

    printf("You entered the number ");

    if (number >= 10 && number < 20)
        printf("%s\n", teens[number - 10]);
    else
    {
        tens = number / 10;
        ones = number % 10;

        printf("%s", tens_words[tens]);
        printf("%s\n", ones_words[ones]);
    }

    return 0;
}
