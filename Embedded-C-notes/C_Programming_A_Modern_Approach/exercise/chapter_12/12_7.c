#include<stdio.h>
#include<stdbool.h>

#define SIZE 10

bool search(const int a[], int n, int key);

int main(void)
{
    const int a[SIZE] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int number;

    printf("Enter the number to search : ");
    scanf("%d", &number);

    if(search(a, SIZE, number))
        printf("Exist\n");
    else    
        printf("Not exits\n");

    return 0;
}

bool search(const int a[], int n, int key)
{
    const int *p;
    for(p = a;p < a + n;p ++)
        if(*p == key)
            return true;

    return false;
}