#include <stdio.h>
#include<stdbool.h>

#define HOUR 24
#define WEEKDAY 7

int *find_largest(int *a, int n);

int main(void)
{
    int temperatures[WEEKDAY][HOUR] = {
        {12, 14, 13, 11, 10, 9, 8, 7, 10, 15, 18, 20, 23, 25, 26, 24, 22, 20, 18, 16, 14, 13, 12, 11},
        {11, 13, 12, 10, 9, 8, 7, 6, 9, 14, 17, 19, 22, 24, 25, 23, 21, 19, 17, 15, 13, 12, 11, 10},
        {10, 12, 11, 9, 8, 7, 6, 5, 8, 13, 16, 18, 21, 23, 24, 22, 20, 18, 16, 14, 12, 11, 10, 9},
        {13, 15, 14, 12, 11, 10, 9, 8, 11, 16, 19, 21, 24, 26, 27, 25, 23, 21, 19, 17, 15, 14, 13, 12},
        {9, 11, 10, 8, 7, 6, 5, 4, 7, 12, 15, 17, 20, 22, 23, 21, 19, 17, 15, 13, 11, 10, 9, 8},
        {8, 10, 9, 7, 6, 5, 4, 3, 6, 11, 14, 16, 19, 21, 22, 20, 18, 16, 14, 12, 10, 9, 8, 7},
        {7, 9, 8, 6, 5, 4, 3, 2, 5, 10, 13, 15, 18, 20, 21, 19, 17, 15, 13, 11, 9, 8, 7, 6}};


    for(int day = 0;day < WEEKDAY;day ++)
    {
        printf("The largest temperature of day %d", day + 1);
        find_largest(temperatures[day], HOUR);
    }
        
    return 0;
}

int *find_largest(int *a, int n)
{
    int largest = a[0], *index = a;
    for(int *p = a;p < a + n;p ++)
        if(largest < *p)
        {
            largest = *p;
            index = p;
        }

    printf(" is : %d\n", largest);
    return index;
}