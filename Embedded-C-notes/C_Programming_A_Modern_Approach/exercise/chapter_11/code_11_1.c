#include<stdio.h>

#define TWENTY 20
#define TEN 10
#define FIVE 5
#define ONE 1

void pay_amount(int dollars, int *twenties, int *tens, int *fives, int *ones);

int main(void)
{
    int dollars, twenties = 0, tens = 0, fives = 0, ones = 0;
    printf("Enter the dollars: ");
    scanf("%d", &dollars);

    pay_amount(dollars, &twenties, &tens, &fives, &ones);
    printf("The change is %d twneny, %d ten, %d five, %d one.\n", twenties, tens, fives, ones);
    return 0;
}

void pay_amount(int dollars, int *twenties, int *tens, int *fives, int *ones)
{
    *twenties = dollars / 20;
    dollars %= 20;
    *tens = dollars / 10;
    dollars %= 10;
    *fives = dollars / 5;
    dollars %= 5;
    *ones = dollars;
}