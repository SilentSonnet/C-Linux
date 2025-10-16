#include<stdio.h>
int main(void)
{
    int day = 0, month = 0, year = 0;
    printf("Enter a date (mm/dd/yyyy):");
    scanf("%2d/%2d/%4d", &day, &month, &year);
    
    printf("You entered the date %4d%2d%.2d\n", year, month, day);
    return 0;
}

