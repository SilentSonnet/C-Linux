#include<stdio.h>
int main(void)
{
    int number;
    float loan = 0.0f, rate = 0.0f, payment = 0.0f;
    printf("Enter amount of loan:");
    scanf("%f", &loan);
    printf("Enter interest rate:");
    scanf("%f", &rate);
    printf("Enter monthly payment:");
    scanf("%f", &payment);
    printf("Enter the number of month:");
    scanf("%d", &number);

    for(int i = 1;i <= number;i ++)
    {
        printf("Balance remaining after %d payment:%.2f\n", i, 
            loan * (1.0 + (rate / 1200)) - payment);
        loan = loan * (1.0 + (rate / 1200)) - payment;
    }

    return 0;
}

