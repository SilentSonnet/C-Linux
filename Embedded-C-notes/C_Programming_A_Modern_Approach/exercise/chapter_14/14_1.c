#include <stdio.h>

#define CUBE(x) ((x) * (x) * (x))
#define REMAINDER_FOUR(x) ((x) %= 4)
#define JUDGE(x, y) (((x) * (y)) < 100 ? 1 : 0)


int main(void)
{
    int x = 2, y = 3;

    printf("The square is %d\n", CUBE(x));
    printf("The remainder is %d\n", REMAINDER_FOUR(x));
    
    if(JUDGE(x, y))
        printf("The res is 1\n");
    else
        printf("The res is 0\n");

    return 0;
}