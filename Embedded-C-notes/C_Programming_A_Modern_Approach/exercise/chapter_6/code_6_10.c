#include <stdio.h>
int main(void)
{
    int month1, day1, year1;
    int month2 = 99, day2 = 99, year2 = 99;

    while(1)
    {
        printf("Enter a date (mm/dd/yy): ");
        scanf("%d / %d / %d", &month1, &day1, &year1);

        if ((month1 == 0) && (day1 == 0) && (year1 == 0))
            break;

        if ((year1 * 10000 + month1 * 100 + day1) < (year2 * 10000 + month2 * 100 + day2))
        {
            year2 = year1;
            month2 = month1;
            day2 = day1;
        }
            
    }

    printf("%2d/%2d/%.2d is the earliest date\n", month2, day2, year2);

    return 0;
}