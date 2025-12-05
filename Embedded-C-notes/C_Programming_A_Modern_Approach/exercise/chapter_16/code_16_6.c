#include<stdio.h>

struct date {
    int year;
    int month;
    int day;
};

int days_in_months_common_year[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int days_in_months_leap_year[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int day_of_year(struct date d);
int compare_dates(struct date d1, struct date d2);

int main(void)
{
    struct date d1, d2;
    printf("Enter first date (mm/dd/yy): ");
    scanf("%d / %d / %d", &d1.month, &d1.day, &d1.year);
    printf("Enter second date (mm/dd/yy): ");
    scanf("%d / %d / %d", &d2.month, &d2.day, &d2.year);


    if(compare_dates(d1, d2) == -1)
        printf("%d/%d/%d is earlier than %d/%d/%d\n", d1.month, d1.day, d1.year, d2.month, d2.day, d2.year);
    else if(compare_dates(d1, d2) == 1)
        printf("%d/%d/%d is earlier than %d/%d/%d\n", d2.month, d2.day, d2.year, d1.month, d1.day, d1.year);
    else
        printf("The two dates are equal: %d/%d/%d\n", d1.month, d1.day, d1.year);
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