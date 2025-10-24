#include<stdio.h>
int main(void)
{
    int hour, min, cmp;
    int flight1, flight2, flight3, flight4, flight5, flight6, flight7, flight8;
    printf("Enter a 24-hour time: ");
    scanf("%d : %d", &hour, &min);

    flight1 = 8 * 60;
    flight2 = 9 * 60 + 43;
    flight3 = 11 * 60 + 19;
    flight4 = 12 * 60 + 47;
    flight5 = 14 * 60;
    flight6 = 15 * 60 + 45;
    flight7 = 19 * 60;
    flight8 = 21 * 60 + 45;

    cmp = hour * 60 + min;
    if(cmp < (flight1 + flight2) / 2) // 小于第一个航班，那么第一个航班就是最接近的。
        printf("Closest departure time is 8:00 a.m., arriving at 10:16 a.m.\n");
    else if(cmp < (flight2 + flight3) / 2)
         printf("Closest departure time is 9:43 a.m., arriving at 11:52 a.m.\n");
    else if(cmp < (flight3 + flight4) / 2)
         printf("Closest departure time is 11:19 a.m., arriving at 1:31 p.m.\n");
    else if(cmp < (flight4 + flight5) / 2)
         printf("Closest departure time is 12.47 p.m., arriving at 3:00 p.m.\n");
    else if(cmp < (flight5 + flight6) / 2)                  
         printf("Closest departure time is 2:00 p.m., arriving at 4:08 p.m.\n");
    else if(cmp < (flight6 + flight7) / 2)
        printf("Closest departure time is 3:45 p.m., arriving at 5:55 p.m.\n");
    else if(cmp <(flight7 + flight8) / 2)
        printf("Closest departure time is 7:00 p.m., arriving at 9:20 p.m.\n");
    else
        printf("Closest departure time is 9:45 p.m., arriving at 11:58 p.m.\n");
        
    return 0;
}