#include <stdio.h>

void create_magic_square(int n, int magic_square[n][n]);
void print_magic_square(int n, int magic_square[n][n]);

int main(void)
{
    int dimension;
    printf("This program creates a magic square of a specified size.\n");
    printf("The size must be an odd number between 1 and 99.\n");
    printf("Enter size of magic square: ");

    scanf("%d", &dimension);
    if (dimension % 2 == 0)
    {
        printf("Negative input!");
        return 0;
    }

    int magic_square[dimension][dimension];

    create_magic_square(dimension, magic_square);
    print_magic_square(dimension, magic_square);

    return 0;
}

void create_magic_square(int n, int magic_square[n][n])
{
    int next_x, next_y, before_x, before_y, count = 0;;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            magic_square[i][j] = 0;
    }

    for (int i = 0; i < n * n; i++)
    {
        if (i == 0)
        {
            next_x = ((n + 1) / 2) - 1;
            next_y = 0;
            magic_square[next_y][next_x] = ++count;
        }
        else
        {
            if (next_x + 1 >= n)
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
                next_y = n - 1;
            }
            else
            {
                before_y = next_y;
                next_y -= 1;
            }

            // check if there is already has a number
            if (magic_square[next_y][next_x] == 0)
                magic_square[next_y][next_x] = ++count;
            else
            {
                next_x = before_x;
                next_y = before_y + 1;
                magic_square[next_y][next_x] = ++count;
            }
        }
    }
}
void print_magic_square(int n, int magic_square[n][n])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%2d ", magic_square[i][j]);
        printf("\n");
    }
}