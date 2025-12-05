#include <stdio.h>

struct time {
    int hours, minutes, seconds;
};

struct time split_time(long total_seconds);

int main(void)
{
    long total_seconds;
    struct time t;

    printf("Enter the seconds : ");
    scanf("%ld", &total_seconds);

    t = split_time(total_seconds);
    printf("%02d:%02d:%02d\n", t.hours, t.minutes, t.seconds);

    return 0;
}

struct time split_time(long total_seconds)
{
    struct time t;

    total_seconds %= 24 * 60 * 60;

    t.seconds = total_seconds % 60;
    total_seconds /= 60;

    t.minutes = total_seconds % 60;
    total_seconds /= 60;

    t.hours = total_seconds;

    return t;
}