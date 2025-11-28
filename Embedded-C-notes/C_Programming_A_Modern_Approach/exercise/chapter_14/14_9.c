#include<stdio.h>
#include<math.h>

#define CHECK(x,y,n)  (((0 <= (x) && (x) < n) && (0 <= (y) && (y) < n)) ? 1 : 0)
#define MEDIAN(x,y,z)   ((((y) <= (x) && (x) <= (z)) || ((z) <= (x) && (x) <= (y))) ? x : \
                        ((((x) <= (y) && (y) <= (z)) || ((z) <= (y) && (y) <= (x))) ? y : z))
#define POLYNOMIAL(x) (3 * pow(x, 5) + 2 * pow(x, 4) - 5 * pow(x, 3) - pow(x, 2) + 7 * (x) - 6)
#undef POLYNOMIAL
#define POLYNOMIAL(x) (3 * (x)*(x)*(x)*(x)*(x) + 2 * (x)*(x)*(x)*(x) - 5 * (x)*(x)*(x) - (x)*(x) + 7 * (x) - 6)

int main(void)
{
    if(CHECK(1, 2, 3))
        printf("The x and y is in the range of 0 ~ n - 1\n");
    
    printf("The median of x:%d y:%d z:%d is %d\n", 4, 8, 2, MEDIAN(4, 8, 2));

    printf("the res of polynomial is %.2f\n", POLYNOMIAL(3.0));

    return 0;
}