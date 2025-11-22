#include <stdio.h>
#include <ctype.h>

#define WIDTH 8
#define LENGTH 8
int evaluate_position(char *board);

// （Q=9，R=5，B=3，N=3，P=1）

char midgame_board[WIDTH][LENGTH] = {
    {'r', '.', '.', '.', 'k', '.', '.', 'r'},
    {'p', 'p', 'p', 'q', '.', 'p', 'p', 'p'},
    {'.', '.', 'n', '.', '.', '.', '.', '.'},
    {'.', 'b', '.', 'p', 'P', '.', '.', '.'},
    {'.', '.', 'P', '.', 'N', 'B', '.', '.'},
    {'.', '.', '.', '.', '.', '.', '.', '.'},
    {'P', 'P', '.', 'Q', '.', 'P', 'P', 'P'},
    {'R', 'N', 'B', '.', 'K', '.', '.', 'R'}};

char endgame_board[WIDTH][LENGTH] = {
    {'.', '.', '.', '.', 'k', '.', '.', '.'},
    {'.', '.', '.', '.', '.', '.', '.', '.'},
    {'.', '.', '.', '.', '.', '.', '.', '.'},
    {'.', '.', '.', '.', 'p', '.', '.', '.'},
    {'.', '.', '.', '.', 'P', '.', '.', '.'},
    {'.', '.', '.', '.', '.', '.', '.', '.'},
    {'.', '.', '.', '.', '.', '.', '.', '.'},
    {'.', '.', '.', '.', 'K', '.', '.', 'R'}};

int main(void)
{
    if (evaluate_position(&midgame_board[0][0]) > 0)
        printf("White advanced!\n");
    else if (evaluate_position(&midgame_board[0][0]) < 0)
        printf("Black advanced!\n");
    else
        printf("Even position.\n");

    if (evaluate_position(&endgame_board[0][0]) > 0)
        printf("White advanced!\n");
    else if (evaluate_position(&endgame_board[0][0]) < 0)
        printf("Black advanced!\n");
    else
        printf("Even position.\n");

    return 0;
}

int evaluate_position(char *board)
{
    int black = 0, white = 0;
    for (char *p = board; p < board + WIDTH * LENGTH; p++)
    {
        switch (*p)
        {
        case 'q':
            black += 9;
            break;
        case 'r':
            black += 5;
            break;
        case 'b':
            black += 3;
            break;
        case 'n':
            black += 3;
            break;
        case 'p':
            black += 1;
            break;
        case 'Q':
            white += 9;
            break;
        case 'R':
            white += 5;
            break;
        case 'B':
            white += 3;
            break;
        case 'N':
            white += 3;
            break;
        case 'P':
            white += 1;
            break;
        default:
            break;
        }
    }

    return white - black;
}
