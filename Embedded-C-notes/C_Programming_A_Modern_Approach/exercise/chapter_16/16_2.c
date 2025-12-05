#include <stdio.h>

int main(void)
{
    struct {double real, imaginary} c1 = {0.0, 0.1}, c2 = {1.0, 0.0}, c3;

    printf("c1: real is : %.2f, imaginary is : %.2f\n", c1.real, c1.imaginary);
    printf("c2: real is : %.2f, imaginary is : %.2f\n", c2.real, c2.imaginary);
    
    c1 = c2;

    c3.real = c1.real + c2.real;
    c3.imaginary = c1.imaginary + c2.imaginary;

    printf("c3: real is : %.2f, imaginary is : %.2f\n", c3.real, c3.imaginary);

    return 0;
}