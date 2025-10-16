#include<stdio.h>
#include<stdlib.h>
int main(void)
{
    int number, day, month, year;
    float price;
    printf("Enter item number:");
    scanf("%d", &number);
    printf("Enter unit price:");
    scanf("%f", &price);
    printf("Enter purchase date (mm/dd/yyyy):");
    scanf("%d/%d/%d", &month, &day, &year);

    printf("Item\t\tUnit\t\tPurchase\n");
    printf("\t\tPrice\t\tDate\n");
    printf("%d\t\t$%7.2f\t%.2d\\%.2d\\%4d\n", number, price, month, day, year);

    return 0;
}

