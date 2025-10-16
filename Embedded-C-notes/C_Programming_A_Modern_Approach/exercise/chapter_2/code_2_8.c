#include<stdio.h>
int main(void)
{
    float loan = 0.0f, rate = 0.0f, payment = 0.0f, left_payment = 0.0f;
    float first = 0.0f, second = 0.0f, third = 0.0f;
    printf("Enter amount of loan:");
    scanf("%f", &loan);
    printf("Enter interest rate:");
    scanf("%f", &rate);
    printf("Enter monthly payment:");
    scanf("%f", &payment);

    first = loan * (1.0 + (rate / 1200)) - payment;
    second = first * (1.0 + (rate / 1200)) - payment;
    third = second * (1.0 + (rate / 1200)) - payment;
    printf("Balance remaining after first payment:%.2f\n", first);
    printf("Balance remaining after second payment:%.2f\n", second);
    printf("Balance remaining after third payment:%.2f\n", third);

    return 0;
}

