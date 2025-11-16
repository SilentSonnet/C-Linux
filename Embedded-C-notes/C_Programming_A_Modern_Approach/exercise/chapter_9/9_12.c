#include <stdio.h>

double inner_product(double a[], double b[], int n);

int main(void)
{
    double a[] = {-1.5, 0.0, 2.5, 3.0};
    double b[] = {4.0, -2.0, 1.0, 0.5};

    printf("The inner product is : %.1lf\n", inner_product(a, b, 4));
    return 0;
}

double inner_product(double a[], double b[], int n)
{
    double sum = 0;
    for (int i = 0; i < n; i++)
        sum += a[i] * b[i];

    return sum;
}