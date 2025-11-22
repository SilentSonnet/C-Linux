#include <stdio.h>
#include <stdbool.h>

int daysInMonthNonLeap[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; // non-leap year
int daysInMonthLeap[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};    // leap year

void split_date(int day_of_year, int year, int *month, int *day);

int main(void)
{
    int day_of_year, year, month, day;
    printf("Enter the day of year : ");
    scanf("%d", &day_of_year);
    printf("Enter the year : ");
    scanf("%d", &year);

    split_date(day_of_year, year, &month, &day);
    printf("Now is %4d/%2d/%2d\n", year, month, day);

    return 0;
}

void split_date(int day_of_year, int year, int *month, int *day)
{
    bool isLeapYear = false;

    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
        isLeapYear = true;

    for (int i = 0; i < 12; i++)
    {
        if ((isLeapYear) && (day_of_year > daysInMonthLeap[i]))
            day_of_year -= daysInMonthLeap[i];
        else if ((isLeapYear) && (day_of_year <= daysInMonthLeap[i]))
        {
            *month = i + 1;
            *day = day_of_year;
            break;
        }

        if ((!isLeapYear) && (day_of_year > daysInMonthNonLeap[i]))
            day_of_year -= daysInMonthNonLeap[i];
        else if ((!isLeapYear) && (day_of_year <= daysInMonthNonLeap[i]))
        {
            *month = i + 1;
            *day = day_of_year;
            break;
        }
    }
}