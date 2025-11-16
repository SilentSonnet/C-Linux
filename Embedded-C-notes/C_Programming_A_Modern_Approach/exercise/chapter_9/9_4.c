#include <stdio.h>

int day_of_year(int month, int day, int year);

int main(void)
{
    int month, day, year;
    printf("Enter the month/day/year: ");
    scanf("%d / %d / %d", &month, &day, &year);

    printf("The sum of the day before is : %d\n", day_of_year(month, day, year));
    return 0;
}

int day_of_year(int month, int day, int year)
{
    // 1 3 5 7 8 10 12 - 31
    int sum = 0;
    switch (month)
    {
    case 12:
    case 11:
        sum += 31;
    case 10:
        sum += 31;
    case 9:
        sum += 31;
    case 8:
        sum += 31;
    case 7:
        sum += 30;
    case 6:
        sum += 31;
    case 5:
        sum += 30;
    case 4:
        sum += 31;
    case 3:
        if(((year % 4 == 0) && (year % 100 != 0)) || year % 400 == 0 )
            sum += 29;
        else 
            sum += 28;
    case 2:
        sum += 31;
    case 1:
        break;
    }

    sum += day;

    return sum;
}