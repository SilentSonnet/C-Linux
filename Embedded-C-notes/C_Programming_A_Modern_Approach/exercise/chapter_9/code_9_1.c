#include <stdio.h>
#include <stdbool.h>

int selection_sort(int arr[], int n);

int arr[100] = {
    37, 12, 65, 90, 21, 78, 3, 44, 29, 8,
    70, 18, 61, 49, 6, 95, 85, 1, 32, 25,
    72, 31, 87, 11, 66, 22, 76, 91, 38, 26,
    84, 59, 53, 23, 34, 4, 96, 10, 17, 92,
    40, 36, 7, 14, 73, 9, 58, 35, 41, 50,
    45, 28, 39, 79, 63, 64, 2, 55, 19, 20,
    71, 80, 86, 60, 62, 24, 16, 33, 47, 88,
    15, 30, 13, 74, 81, 48, 5, 67, 52, 97,
    68, 75, 43, 56, 46, 89, 42, 82, 27, 93,
    83, 57, 98, 94, 69, 99, 77, 51, 54, 0};

int main(void)
{
    for (int i = 0; i < 100; i++)
        printf("%2d ", arr[i]);
    printf("\n");

    selection_sort(arr, 100);

    for (int i = 0; i < 100; i++)
        printf("%2d ", arr[i]);
    printf("\n");

    return 0;
}

int selection_sort(int arr[], int n)
{
    int temp, max, index = n - 1;

    if (n == 1)
        return 0;
    else
    {
        max = arr[0];

        for (int i = 1; i < n; i++)
            if (max < arr[i])
            {
                max = arr[i];
                index = i;
            }

        temp = arr[n - 1];
        arr[n - 1] = max;
        arr[index] = temp;

        selection_sort(arr, n - 1);
    }

    return 0;
}