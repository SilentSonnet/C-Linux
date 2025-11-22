#include <stdio.h>

#define N 10

int main(void)
{
    double ident[N][N];
    int count = 0;

    for(double *p = &ident[0][0];p < ident[0] + N * N;p ++, count ++)
        if(count % (N + 1) == 0)
            *p = 1.0;
        else
            *p = 0.0;

    for (int row = 0; row < N; row++)
    {
        for (int col = 0; col < N; col++)
            printf("%.f ", ident[row][col]);
        printf("\n");
    }

    return 0;
}