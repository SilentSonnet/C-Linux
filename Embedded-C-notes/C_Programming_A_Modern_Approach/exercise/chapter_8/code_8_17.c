#include <stdio.h>
int main(void)
{
    int dimension, next_x, next_y, before_x, before_y, count = 0;
    printf("This program creates a magic square of a specified size.\n");
    printf("The size must be an odd number between 1 and 99.\n");
    printf("Enter size of magic square: ");

    scanf("%d", &dimension);
    if (dimension % 2 == 0)
    {
        printf("Negative input!");
        return 0;
    }

    int square[dimension][dimension];
    for (int i = 0; i < dimension; i++)
    {
        for (int j = 0; j < dimension; j++)
            square[i][j] = 0;
    }

    for (int i = 0; i < dimension * dimension; i++)
    {
        if (i == 0)
        {
            next_x = ((dimension + 1) / 2) - 1;
            next_y = 0;
            square[next_y][next_x] = ++count;
        }
        else
        {
            if (next_x + 1 >= dimension)
            {
                before_x = next_x;
                next_x = 0;
            }
            else
            {
                before_x = next_x;
                next_x += 1;
            }

            if (next_y - 1 < 0)
            {
                before_y = next_y;
                next_y = dimension - 1;
            }
            else
            {
                before_y = next_y;
                next_y -= 1;
            }
                
            // check if there is already has a number
            if (square[next_y][next_x] == 0)
                square[next_y][next_x] = ++count;
            else
            {
                next_x = before_x;
                next_y = before_y + 1;
                square[next_y][next_x] = ++count;
            }
        }
    }

    for (int i = 0; i < dimension; i++)
    {
        for (int j = 0; j < dimension; j++)
            printf("%2d ", square[i][j]);
        printf("\n");
    }

    return 0;
}