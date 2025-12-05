#include <stdio.h>
#include <string.h>

struct dialing_code
{
    char *country;
    int code;
};

const struct dialing_code country_codes[] =
    {{"Argentina", 54}, {"Bangladesh", 880}, {"Brazil", 55}, 
    {"Burma (Myanmar)", 95}, {"China", 86}, {"Colombia", 57}, 
    {"Congo, Dem. Rep. of", 243}, {"Egypt", 20}, {"Ethiopia", 251}, 
    {"France", 33}, {"Germany", 49}, {"India ", 91}, {"Indonesia", 62}, 
    {"Iran", 98}, {"Italy", 39}, {"Japan", 81}, 
    {"Mexico", 52}, {"Nigeria", 234}, {"Pakistan", 92}, 
    {"Philippines", 63}, {"Poland", 48}, {"Russia", 7}, 
    {"South Africa", 27}, {"Korea", 82}, {"Spain", 34}, 
    {"Sudan", 249}, {"Thailand", 66}, {"Turkey", 90}, 
    {"Ukraine", 380}, {"United Kingdom", 44}, 
    {"United States", 1}, {"Vietnam", 84}
};

int length = sizeof(country_codes) / sizeof(country_codes[0]);

void search(const struct dialing_code country_codes[], int number)
{
    for (int i = 0; i < length; i++)
        if (country_codes[i].code == number)
        {
            printf("Find %d and the country is :%s.\n", number, country_codes[i].country);
            return;
        }
    printf("NOT find.\n");
}

int main(void)
{
    int number;

    for (;;)
    {
        printf("Enter the number to search :");
        if(scanf("%d", &number) != 1)
        {
            printf("Invalid input! Please enter a number.\n");
            while(getchar() != '\n');
            continue;
        }

        if (number == 0)
        {
            printf("Exiting the program ...\n");
            return 0;
        }

        search(country_codes, number);
    }
}
