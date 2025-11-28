#include<stdio.h>

#define DOUBLE(x) 2*x  

int main(void)
{
    printf("The result of DOUBLE(1+2) is : %d\n", DOUBLE(1 + 2));
    printf("The result of 4/DOUBLE(2) is : %d\n", 4/DOUBLE(2));
#undef DOUBLE
#define DOUBLE(x) (2 * (x)) 
    printf("The result of DOUBLE(1+2) is : %d\n", DOUBLE(1 + 2));
    printf("The result of 4/DOUBLE(2) is : %d\n", 4/DOUBLE(2));

    return 0;
}