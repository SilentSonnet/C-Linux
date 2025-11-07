#include <stdio.h>
#include <ctype.h>
int main(void)
{
    char time;
    int hour, min, cmp;
    int flight1, flight2, flight3, flight4, flight5, flight6, flight7, flight8;
    printf("Enter a 12-hour time: ");
    scanf("%d : %d %c", &hour, &min, &time);

    time = toupper(time);
    if (time == 'A')
    {
        // 处理12:00AM的特殊情况，这个时间表示午夜
        if (hour == 12 && min == 0)
        {
            hour = 0;
        }
    }
    else if (time == 'P')
    {
        if (hour == 12 && min == 0)
        {
            // nothing
        }
        else
        {
            hour += 12;
        }
    }

    printf("Equivalent 24-hour time: %2d:%2d\n", hour, min);
    return 0;
}