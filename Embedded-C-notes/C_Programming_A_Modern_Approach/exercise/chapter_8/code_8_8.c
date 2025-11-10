#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(void)
{
    double student[5][7] = {0}, course[5][4] = {0}, max, min;
    srand(time(NULL));
    for (int i = 0; i < 5; i++)
    {
        printf("Student %d ", i + 1);
        for (int j = 0; j < 5; j++)
        {
            student[i][j] = rand() % 100;
            printf("%2.lf   ", student[i][j]);
            student[i][5] += student[i][j];
            course[j][0] += student[i][j];
        }
        
        printf("Sum: %2.f ", student[i][5]);
        printf("Ave: %2.f\n", student[i][6] = student[i][5] / 5.0);
        
    }

    printf("CourseSum ");
    for(int i = 0;i < 5;i ++)
    {
        printf("%3.f  ", course[i][0]);
    }
    printf("\n");

    printf("CourseAve ");
    for(int i = 0;i < 5;i ++)
    {
        printf("%2.f  ", course[i][0] / 5);
    }
    printf("\n");

    printf("CourseMax ");
    for(int i = 0;i < 5;i ++)
    {
        max = student[0][i];
        for(int j = 1;j < 5;j ++)
        {
            if(max < student[j][i])
                max = student[j][i];
        }
        printf("%2.f  ", max);
    }
    printf("\n");

    printf("CourseMin ");
    for(int i = 0;i < 5;i ++)
    {
        min = student[0][i];
        for(int j = 1;j < 5;j ++)
        {
            if(min > student[j][i])
                min = student[j][i];
        }
        printf("%2.f  ", min);
    }
    printf("\n");

    return 0;
}