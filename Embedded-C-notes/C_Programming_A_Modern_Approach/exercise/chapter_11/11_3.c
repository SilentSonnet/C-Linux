#include<stdio.h>

#define MAX 10

void avg_sum(double a[], int n, double *avg, double *sum);

int main(void)
{
    double number[10] = {0.0, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0}, avg, sum;
    avg_sum(number, MAX, &avg, &sum);

    printf("Avg is : %.1f, Sum is : %.1f\n", avg, sum);

    return 0;
}

void avg_sum(double a[], int n, double *avg, double *sum)
{
    int i;
    *sum = 0.0;
    for (i = 0; i < n; i++)
        *sum += a[i];
    *avg = *sum / n;
}