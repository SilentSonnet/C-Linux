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

    int days_in_months[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int days_in_months_leap[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int sum = 0;

    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
    {
        for (int i = 0; i < month - 1; i++)
        {
            sum += days_in_months_leap[i];
        }
    }
    else
    {
        for (int i = 0; i < month - 1; i++)
        {
            sum += days_in_months[i];
        }
    }

    sum += day;

    return sum;
}
