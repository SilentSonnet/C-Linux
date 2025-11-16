#include<stdio.h>

float calculate_tax(int income);

int main(void)
{
    int income;
    float tax;
    printf("Enter your income:");
    scanf("%d", &income);

    printf("The tax is:%.2f\n", calculate_tax(income));

    return 0;
}

float calculate_tax(int income)
{
    float tax;
    if(income < 750)
        tax = income * 0.01f;
    else if(750 <= income && income <= 2250)
        tax = (income - 750) * 0.02 + 7.5f;
    else if(2250 <= income && income <= 3750)
        tax = (income - 2250) * 0.03 + 37.5f;
    else if(3750 <= income && income <= 5250)
        tax = (income - 3750) * 0.04 + 82.5f;
    else if(5250 <= income && income <= 7000)
        tax = (income - 5250) * 0.05 + 142.5f;
    else if(income > 7000)
        tax = (income - 7000) * 0.06 + 230.0f;

    return tax;
}