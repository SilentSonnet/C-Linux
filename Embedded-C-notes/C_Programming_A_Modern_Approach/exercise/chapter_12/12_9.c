#include<stdio.h>

#define SIZE 10

double a[SIZE] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
double b[SIZE] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

double inner_product(const double *a, const double *b, int n);

int main(void)
{
    printf("%.2f\n", inner_product(a, b, SIZE));

    return 0;
}

double inner_product(const double *a, const double *b, int n)
{
    const double *p, *q;
    double sum = 0;
    for(p = a, q = b;p < a + n && q < b + n;p ++, q ++)
        sum += *p * *q;

    return sum;
}