#include <stdio.h>

#define SIZE 100

const int arr[100] = {
    67, 89, 25, 11, 4, 97, 61, 68, 10, 88,
    91, 36, 33, 39, 18, 55, 49, 57, 78, 31,
    20, 28, 27, 77, 32, 99, 23, 75, 15, 37,
    92, 56, 71, 74, 30, 86, 5, 9, 94, 62,
    50, 65, 43, 87, 40, 60, 44, 3, 79, 42,
    64, 17, 83, 70, 98, 16, 73, 81, 8, 41,
    59, 13, 66, 82, 45, 76, 26, 51, 46, 21,
    53, 14, 80, 63, 52, 58, 85, 72, 22, 1,
    29, 69, 48, 24, 34, 12, 93, 38, 90, 84,
    19, 47, 2, 54, 35, 6, 0, 7, 95, 96};

void find_two_largest(const int *a, int n, int *largest, int *second_largest);

int main(void)
{
    int largest, second_largest;

    find_two_largest(arr, SIZE, &largest, &second_largest);

    printf("The largest number is : %d ", largest);
    printf("The second largest number is : %d\n", second_largest);

    return 0;
}

void find_two_largest(const int *a, int n, int *largest, int *second_largest)
{
    *largest = *second_largest = 0;
    for(const int *p = a;p < a + n;p ++)
    {
        if(*largest < *p)
        {
            *second_largest = *largest;
            *largest = *p;
        }
        else if(*second_largest < *p && *largest > *p)
            *second_largest = *p;
    }
}