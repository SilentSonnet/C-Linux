#include<stdio.h>

int max(int a[], int n);
double ave(int a[], int n);
int count(int a[], int n);

int main(void)
{
    int test[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    printf("The max of array Test is : %d\n", max(test, 10));
    printf("The ave of array Test is : %.1lf\n", ave(test, 10));
    printf("The count of array Test is : %d\n", count(test, 10));
    return 0;
}

int max(int a[], int n)
{
    int max = a[0];
    for(int i = 1;i < n;i ++)
        if(max < a[i])
            max = a[i];

    return 0;
}

double ave(int a[], int n)
{
    double sum = 0;
    for(int i = 0;i < n;i ++)
        sum += a[i];

    return sum / n;
}

int count(int a[], int n)
{
    int count = 0;
    for(int i = 0;i < n;i ++)
        if(a[i] > 0)
            count ++;

    return count;
}