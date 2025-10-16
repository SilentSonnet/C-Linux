#include<stdio.h>
int main(void)
{
    float x = 0.0f;
    printf("Please enter the value of x:");

    scanf("%f", &x);

    printf("The value of the polynomial is:%.2f\n", 
            ((((3 * x + 2) * x - 5)  * x - 1) * x + 7) * x - 6 );
    return 0;
}

