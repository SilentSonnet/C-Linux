#include<stdio.h>

#define SIZE 100

int arr[SIZE] = {
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

int *find_largest(int a[], int n);

int main(void)
{
    int *pointer = find_largest(arr, SIZE);
    printf("The pointer is : %p\n", pointer);
    return 0;
}

int *find_largest(int a[], int n)
{
    int largest = 0, *index;
    for(int i = 0;i < n;i ++)
        if(largest < a[i])
        {
            largest = a[i];
            index = &a[i];
        }

    printf("The largest number is : %d\n", largest);
    return index;
}