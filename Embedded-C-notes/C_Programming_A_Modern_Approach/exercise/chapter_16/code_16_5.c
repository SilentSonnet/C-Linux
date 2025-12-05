#include <stdio.h>

#define SIZE 8

struct flight_message
{
    int flight_start;
    int flight_arrive;
};

int main(void)
{
    int hour, min, cmp;

    struct flight_message schedule[SIZE] =
        {
            {8 * 60, 10 * 60 + 16},
            {9 * 60 + 43, 11 * 60 + 52},
            {11 * 60 + 19, 13 * 60 + 31},
            {12 * 60 + 47, 15 * 60},
            {14 * 60, 16 * 60 + 8},
            {15 * 60 + 45, 17 * 60 + 55},
            {19 * 60, 21 * 60 + 20},
            {21 * 60 + 45, 23 * 60 + 58}};

    printf("Enter a 24-hour time: ");
    scanf("%d : %d", &hour, &min);

    cmp = hour * 60 + min;

    for (int i = 0; i < 8; i++)
    {
        if (cmp < (schedule[i].flight_start + schedule[i + 1].flight_arrive) / 2)
        {
            printf("Closest departure time is %d:%02d", schedule[i].flight_start / 60, schedule[i].flight_start % 60);
            printf("a.m., arriving at %d:%02d a.m.\n", schedule[i + 1].flight_arrive / 60, schedule[i + 1].flight_arrive % 60);
            return 0;
        }
    }

    return 0;
}