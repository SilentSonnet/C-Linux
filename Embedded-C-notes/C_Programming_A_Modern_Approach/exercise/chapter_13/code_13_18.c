#include<string.h>
#include<stdio.h>

#define NUM_MONTHS 13

    const char *months[NUM_MONTHS] = {
        "", "January", "February", "March", "April", "May", "June", 
        "July", "August", "September", "October", "November", "December"
    };

int main(void)
{
    int year, month, day;

    printf("Enter a date (mm/dd/yyyy): ");
    scanf("%d/%d/%d", &month, &day, &year);
    printf("You entered the date %s %d, %d\n", months[month], day, year);

    return 0;
}