#include <stdio.h>

#define NUM_FLIGHTS 8

// departure and arrival times in minutes since midnight
int departures[NUM_FLIGHTS] = {
    8 * 60,
    9 * 60 + 43,
    11 * 60 + 19,
    12 * 60 + 47,
    14 * 60,
    15 * 60 + 45,
    19 * 60,
    21 * 60 + 45};

int arrivals[NUM_FLIGHTS] = {
    10 * 60 + 16,
    11 * 60 + 52,
    13 * 60 + 31,
    15 * 60,
    16 * 60 + 8,
    17 * 60 + 55,
    21 * 60 + 20,
    23 * 60 + 58};

void find_closest_flight(int desired_time, int *departure_time, int *arrival_time);

int main(void)
{
    int hour, min, cmp, departure_time, arrival_time;

    printf("Enter a 24-hour time: ");
    scanf("%d : %d", &hour, &min);

    cmp = hour * 60 + min;

    find_closest_flight(cmp, &departure_time, &arrival_time);

    int dep_hr = departure_time / 60;
    int dep_min = departure_time % 60;
    int arr_hr = arrival_time / 60;
    int arr_min = arrival_time % 60;

    if(dep_hr < 12)
        printf("Closest departure time is %d:%02d a.m.", dep_hr, dep_min);
    else
        printf("Closest departure time is %d:%02d p.m.", dep_hr, dep_min);
    
    if(arr_hr < 12)
        printf(", arriving at %d:%02d a.m. .\n", arr_hr, arr_min);
    else
        printf(", arriving at %d:%02d p.m. .\n", arr_hr, arr_min);
    
    return 0;
}

void find_closest_flight(int desired_time, int *departure_time, int *arrival_time)
{
    int closest = 0;
    for (int i = 1; i < NUM_FLIGHTS; i++)
    {
        int mid = (departures[i - 1] + departures[i]) / 2;
        if (desired_time < mid)
        {
            closest = i - 1;
            break;
        }
        // if not less than any mid, then closest = last flight
        closest = NUM_FLIGHTS - 1;
    }

    *departure_time = departures[closest];
    *arrival_time = arrivals[closest];
    // convert back to hour:minute format for printing


}