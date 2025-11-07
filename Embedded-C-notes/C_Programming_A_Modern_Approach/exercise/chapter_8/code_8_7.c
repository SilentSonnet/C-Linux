#include<stdio.h>
int main(void)
{
    int number[6][6] = {0};
    for(int i = 0;i < 5;i ++)
    {
        printf("Enter row %d:  ", i + 1);
        for(int j = 0;j < 5;j ++)
        {
            scanf("%d", &number[i][j]);
            number[i][5] += number[i][j];
            number[5][j] += number[i][j];
            number[5][5] += number[i][j];
        }
    }

    printf("Row totals:  ");
    for(int i = 0;i < 5;i ++)
        printf("%d ", number[i][5]);
    printf("\n");

    printf("Column totals:  ");
    for(int i = 0;i < 5;i ++)
        printf("%d ", number[5][i]);
    printf("\n");

    printf("Totals:  %d\n", number[5][5]);
        
    return 0;
}