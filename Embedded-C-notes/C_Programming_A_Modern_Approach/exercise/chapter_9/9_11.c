#include <stdio.h>
#include <ctype.h>

float compute_GPA(char grades[], int n);

int main(void)
{
    char grade[] = {'A', 'B', 'C', 'D', 'F'};

    printf("The GPA is : %.1lf\n", compute_GPA(grade, 5));

    return 0;
}

float compute_GPA(char grades[], int n)
{
    float ave = 0;
    for(int i = 0;i < n;i ++)
    {
        if('A' <= toupper(grades[i]) && toupper(grades[i]) <= 'D')
            ave += 1 - (toupper(grades[i]) - 'D');
    }

    return ave / n;
}