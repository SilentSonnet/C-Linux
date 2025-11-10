#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int hour, min, cmp, diff, index_flight = 0;
    int flight_start[8] = {0}, flight_arrive[8] = {0};
    printf("Enter a 24-hour time: ");
    scanf("%d : %d", &hour, &min);

    flight_start[0] = 8 * 60;
    flight_start[1] = 9 * 60 + 43;
    flight_start[2] = 11 * 60 + 19;
    flight_start[3] = 12 * 60 + 47;
    flight_start[4] = 14 * 60;
    flight_start[5] = 15 * 60 + 45;
    flight_start[6] = 19 * 60;
    flight_start[7] = 21 * 60 + 45;

    flight_arrive[0] = 10 * 60 + 16;
    flight_arrive[1] = 11 * 60 + 52;
    flight_arrive[2] = 13 * 60 + 31;
    flight_arrive[3] = 15 * 60;
    flight_arrive[4] = 16 * 60 + 8;
    flight_arrive[5] = 17 * 60 + 55;
    flight_arrive[6] = 21 * 60 + 20;
    flight_arrive[7] = 23 * 60 + 58;

    cmp = hour * 60 + min;
    diff = abs(cmp - flight_start[0]);
    for (int i = 1; i < 8; i++)
    {
        if (diff > abs(cmp - flight_start[i]))
        {
            diff = abs(cmp - flight_start[i]);
            index_flight = i;
        }
    }

    printf("Closest departure time is %d:%02d",flight_start[index_flight] / 60, flight_start[index_flight] % 60);
    printf("a.m., arriving at %d:%02d a.m.\n", flight_arrive[index_flight] / 60, flight_arrive[index_flight] % 60);

    return 0;
}