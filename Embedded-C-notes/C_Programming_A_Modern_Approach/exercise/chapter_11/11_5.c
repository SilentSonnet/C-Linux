#include<stdio.h>

void split_time(long total_sec, int *hr, int *min, int *sec);  

int main(void)
{
    long total_sec;
    int hr, min, sec;
    printf("Enter the total seconds: ");
    scanf("%ld", &total_sec);

    if(total_sec >= 24 * 60 * 60)
        total_sec %= 24 * 60 * 60;

    split_time(total_sec, &hr, &min, &sec);
    printf("The time is %2d:%2d:%2d\n", hr, min, sec);

    return 0;
}

void split_time(long total_sec, int *hr, int *min, int *sec)
{
    *sec = total_sec % 60;
    *min = (total_sec / 60) % 60;
    *hr = (total_sec / 3600) % 60;
}