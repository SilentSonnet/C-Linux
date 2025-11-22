#include<stdio.h>

#define LEN 10

const int array[LEN][LEN] = {
    {72, 58, 94, 12, 37, 81, 45, 63, 28, 66},
    {89, 33, 71, 47, 16, 50, 39, 95, 22, 79},
    {44, 91, 84, 60, 10, 78, 56, 35, 17, 65},
    {26, 98, 73, 49, 24, 11, 90, 31, 67, 86},
    {59, 53, 40, 93, 75, 19, 32, 29, 80, 13},
    {36, 42, 64, 88, 20, 96, 85, 70, 27, 77},
    {18, 92, 34, 55, 38, 15, 62, 25, 46, 21},
    {97, 30, 41, 23, 14, 87, 52, 69, 43, 99},
    {51, 76, 61, 54, 48, 57, 74, 68, 83, 59},
    {82, 100, 19, 58, 36, 44, 66, 12, 71, 91}
};


int sum_two_dimensional_array(const int *a, int n);

int main(void)
{
    printf("The sum of the array is : %d\n", sum_two_dimensional_array(&array[0][0], LEN * LEN));
    return 0;
}

int sum_two_dimensional_array(const int *a, int n)  
{  
    int sum = 0;
    for(const int *p = a;p < a + n;p ++)
        sum += *p;

    return sum;  
}