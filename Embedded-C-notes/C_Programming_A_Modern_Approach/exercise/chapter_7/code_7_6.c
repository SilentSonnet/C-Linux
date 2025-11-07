#include <stdio.h>
int main(void)
{
    printf("%lu\t%lu\t%lu\t%lu\t%lu\t%lu\n", sizeof(int), sizeof(short), sizeof(long), sizeof(float), sizeof(double), sizeof(long double));

    return 0;
}