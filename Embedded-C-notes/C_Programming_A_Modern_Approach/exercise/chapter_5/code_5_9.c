#include<stdio.h>
int main(void)
{
    int month1, day1, year1;
    int month2, day2, year2;
    printf("Enter first date (mm/dd/yy): ");
    scanf("%d / %d / %d", &month1, &day1, &year1);
    printf("Enter second date (mm/dd/yy): ");
    scanf("%d / %d / %d", &month2, &day2, &year2);


    if((year1 * 10000 + month1 * 100 + day1) > (year2 * 10000 + month2 * 100 + day2))
        printf("%d/%d/%d is earlier than %d/%d/%d\n", month2, day2, year2, month1, day1, year1);
    else
        printf("%d/%d/%d is earlier than %d/%d/%d\n", month1, day1, year1, month2, day2, year2);

    return 0;
}