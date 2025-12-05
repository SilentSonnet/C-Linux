#include <stdio.h>

struct date {
    int year, month, day;
};

int days_in_months_common_year[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int days_in_months_leap_year[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int day_of_year(struct date d);
int compare_dates(struct date d1, struct date d2);

int main(void)
{
    struct date d1 = {2024, 12, 2}, d2 = {2023, 12, 3};
    printf("The day of year %d is %d\n", d1.year, day_of_year(d1));

    printf("The res is :%d\n", compare_dates(d1, d2));

    return 0;
}

int day_of_year(struct date d)
{
    int day = 0;
    int *days = ((d.year % 4 == 0 && d.year % 100 != 0) || d.year % 400 == 0) ?
                    days_in_months_leap_year : days_in_months_common_year;

    for(int i = 1;i < d.month;i ++)
        day += days[i];

    return (day + d.day);
}

int compare_dates(struct date d1, struct date d2)
{
    if(d1.year != d2.year)
    {
        if(d1.year > d2.year)
            return 1;
        else
            return -1;
    }

    int day_1 = day_of_year(d1);
    int day_2 = day_of_year(d2);

    if((day_1 - day_2) == 0)
        return 0;
    else if((day_1 - day_2) > 0)
        return 1;
    else
        return -1;
}
