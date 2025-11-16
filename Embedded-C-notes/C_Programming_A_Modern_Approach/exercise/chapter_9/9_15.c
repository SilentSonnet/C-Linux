#include <stdio.h>

double median(double x, double y, double z);

int main(void)
{
    double a[3];
    printf("Enter three number : ");
    for(int i = 0;i < 3;i ++)
        scanf("%lf", &a[i]);

    printf("The middle of %.lf %.lf %.lf is : %.lf\n", a[0], a[1], a[2], median(a[0], a[1], a[2]));

    return 0;
}

double median(double x, double y, double z)
{
    double middle;
    if((x <= y && y <= z) || (z <= y && y <= x))
        middle = y;
    else if((x <= z && z <= y) || (y <= z && z <= x))
        middle = z;
    else 
        middle = x;

    return middle;
}