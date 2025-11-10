#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// the index to find if the direction is reachable
#define UP 0
#define RIGHT 1
#define LEFT 2
#define DOWN 3
#define ROW 10
#define COLUMN 10

int main(void)
{
    int row = 0, col = 0, direction_num = 0, dir;
    char snake = 'A';
    char board[ROW][COLUMN];
    bool direction[4] = {false};

    // initiate char array
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            board[i][j] = '.';

    board[row][col] = snake;
    // set the random seed
    srand(time(NULL));

    // until the string is finished
    while (snake < 'Z')
    {
        // check if the direction is reachable
        // the coordinate of the snake is (row, col)
        // so the up direction is (row - 1, col)

        // initiate the number of reachable number
        direction_num = 0;

        // check UP
        if (((row - 1) >= 0) && (board[row - 1][col] == '.'))
        {
            direction[UP] = true;
            direction_num++;
        }
        // check DOWN
        if (((row + 1) < 10) && (board[row + 1][col] == '.'))
        {
            direction[DOWN] = true;
            direction_num++;
        }
        // check LEFT
        if (((col - 1) >= 0) && (board[row][col - 1] == '.'))
        {
            direction[LEFT] = true;
            direction_num++;
        }
        // check RIGHT
        if (((col + 1) < 10) && (board[row][col + 1] == '.'))
        {
            direction[RIGHT] = true;
            direction_num++;
        }

        // if there is still space remain
        if (direction_num > 0)
        {
            // if the direction is unreachable, just try again.
            while (direction[(dir = rand() % 4)] != true)
                ;
            if (dir == UP)
            {
                row--;
            }
            if (dir == DOWN)
            {
                row++;
            }
            if (dir == RIGHT)
            {
                col++;
            }
            if (dir == LEFT)
            {
                col--;
            }

            board[row][col] = ++snake;

            // reset the director of the direction 
            for(int i = 0;i < 4;i ++)
                direction[i] = false;
        }
        else
            break;
    }

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
            printf("%c ", board[i][j]);
        printf("\n");
    }

    return 0;
}