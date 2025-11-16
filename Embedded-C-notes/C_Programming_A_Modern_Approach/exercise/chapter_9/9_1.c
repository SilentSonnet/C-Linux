#include <stdio.h>

double triangle_area(double base, double height)
{
    double product = base * height;
    return product / 2;
}

int main(void)
{
    double base = 2.0, height = 1.0;

    printf("The base is %.lf and the height is %.lf\n", base, height);
    printf("the product is %.lf\n", triangle_area(base, height));

    return 0;
}