#include <stdio.h>

struct complex
{
    double real, imaginary;
};

struct complex c1, c2, c3;

struct complex make_complex(double real, double imaginary)
{
    struct complex c;

    c.real = real;
    c.imaginary = imaginary;

    return c;
}

struct complex add_complex(struct complex c1, struct complex c2)
{
    struct complex c;
    c.real = c1.real + c2.real;
    c.imaginary = c1.imaginary + c2.imaginary;

    return c;
}

int main(void)
{
    c1.real = 1.0, c1.imaginary = 2.0;
    c2.real = 3.0, c2.imaginary = 4.0;

    printf("c1: real is : %.2f, imaginary is : %.2f\n", c1.real, c1.imaginary);
    printf("c2: real is : %.2f, imaginary is : %.2f\n", c2.real, c2.imaginary);

    printf("Plus c1 and c2.\n");
    c3 = add_complex(c1, c2);

    printf("c3: real is : %.2f, imaginary is : %.2f\n", c3.real, c3.imaginary);

    printf("Plus c1 and c2.\n");
    c1 = make_complex(5.0, 6.0);
    
    printf("c1: real is : %.2f, imaginary is : %.2f\n", c1.real, c1.imaginary);
    printf("c2: real is : %.2f, imaginary is : %.2f\n", c2.real, c2.imaginary);
    printf("c3: real is : %.2f, imaginary is : %.2f\n", c3.real, c3.imaginary);

    return 0;
}