#include<stdio.h>
#include<math.h>
int main(void)
{
    double x, y_new = 0, y_old = 1.0, ave;
    printf("Enter a positive number: ");
    scanf("%lf", &x);

    while(1)
    {
        y_new = (y_old + x / y_old) / 2;

        if(fabs(y_new - y_old) < 0.00001)
            break;

        y_old = y_new;
    }

    printf("%f\n", y_new);

    return 0;
}