#include <stdio.h>
int main(void)
{
    char c = '\1';
    short s = 2;
    int i = -3;
    long m = 5;
    float f = 6.5f;
    double d = 7.5;

    printf("%d\n", c * i);
    printf("%ld\n", s + m);
    printf("%f\n", f / c);
    printf("%f\n", d / s);
    printf("%f\n", f - d);
    printf("%d\n", (int)f);

    return 0;
}