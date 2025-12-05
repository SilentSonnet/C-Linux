#include <stdio.h>

enum WEEK
{
    MON = 1,
    TUE,
    WED,
    THU,
    FRI,
    SAT,
    SUN,
};

typedef enum WEEK Week;

int main(void)
{
    enum WEEK week_1 = MON;
    Week week_2 = TUE;

    printf("week_1: %d, week_2: %d\n", week_1, week_2); 

    return 0;
}
