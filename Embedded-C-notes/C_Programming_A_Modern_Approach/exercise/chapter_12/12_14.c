#include <stdio.h>
#include<stdbool.h>

#define HOUR 24
#define WEEKDAY 7

bool search(const int a[], int n, int key);

int main(void)
{
    const int temperatures[WEEKDAY][HOUR] = {
        {12, 14, 13, 11, 10, 9, 8, 7, 10, 15, 18, 20, 23, 25, 26, 24, 22, 20, 18, 16, 14, 13, 12, 11},
        {11, 13, 12, 10, 9, 8, 7, 6, 9, 14, 17, 19, 22, 24, 25, 23, 21, 19, 17, 15, 13, 12, 11, 10},
        {10, 12, 11, 9, 8, 7, 6, 5, 8, 13, 16, 18, 21, 23, 24, 22, 20, 18, 16, 14, 12, 11, 10, 9},
        {13, 15, 14, 12, 11, 10, 9, 8, 11, 16, 19, 21, 24, 26, 27, 25, 23, 21, 19, 17, 15, 14, 13, 12},
        {9, 11, 10, 8, 7, 6, 5, 4, 7, 12, 15, 17, 20, 22, 23, 21, 19, 17, 15, 13, 11, 10, 9, 8},
        {8, 10, 9, 7, 6, 5, 4, 3, 6, 11, 14, 16, 19, 21, 22, 20, 18, 16, 14, 12, 10, 9, 8, 7},
        {7, 9, 8, 6, 5, 4, 3, 2, 5, 10, 13, 15, 18, 20, 21, 19, 17, 15, 13, 11, 9, 8, 7, 6}};

    int number;
    
    printf("Enter the number to search :");
    scanf("%d", &number);

    if(search(&temperatures[0][0], WEEKDAY * HOUR, number))
        printf("Exist\n");
    else
        printf("Not exist\n");
        
    return 0;
}

bool search(const int *a, int n, int key)
{
    for(const int *p = a;p < a + n;p ++)
        if(*p == key)
            return true;

    return false;
}
