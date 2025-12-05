#include <stdio.h>

#define SIZE 8

enum piece {
    BLANK = 0,
    PAWN = 1,
    KNIGHT = 2,
    BISHOP = 3,
    ROOK = 4,
    QUEEN = 5,
    KING = 6,
};

enum color {
    WHITE = 0,
    BLACK = 1,
};

typedef struct square {
    enum piece Piece;
    enum color Color;
} Square;

void print_board(Square board[SIZE][SIZE]);

int main(void)
{
    Square board[SIZE][SIZE] = {
        { {ROOK, BLACK}, {KNIGHT, BLACK}, {BISHOP, BLACK}, {QUEEN, BLACK}, {KING, BLACK}, {BISHOP, BLACK}, {KNIGHT, BLACK}, {ROOK, BLACK} },
        { {PAWN, BLACK}, {PAWN, BLACK}, {PAWN, BLACK}, {PAWN, BLACK}, {PAWN, BLACK}, {PAWN, BLACK}, {PAWN, BLACK}, {PAWN, BLACK} },
        { {BLANK, WHITE}, {BLANK, WHITE}, {BLANK, WHITE}, {BLANK, WHITE}, {BLANK, WHITE}, {BLANK, WHITE}, {BLANK, WHITE}, {BLANK, WHITE} },
        { {BLANK, WHITE}, {BLANK, WHITE}, {BLANK, WHITE}, {BLANK, WHITE}, {BLANK, WHITE}, {BLANK, WHITE}, {BLANK, WHITE}, {BLANK, WHITE} },
        { {BLANK, WHITE}, {BLANK, WHITE}, {BLANK, WHITE}, {BLANK, WHITE}, {BLANK, WHITE}, {BLANK, WHITE}, {BLANK, WHITE}, {BLANK, WHITE} },
        { {BLANK, WHITE}, {BLANK, WHITE}, {BLANK, WHITE}, {BLANK, WHITE}, {BLANK, WHITE}, {BLANK, WHITE}, {BLANK, WHITE}, {BLANK, WHITE} },
        { {PAWN, WHITE}, {PAWN, WHITE}, {PAWN, WHITE}, {PAWN, WHITE}, {PAWN, WHITE}, {PAWN, WHITE}, {PAWN, WHITE}, {PAWN, WHITE} },
        { {ROOK, WHITE}, {KNIGHT, WHITE}, {BISHOP, WHITE}, {QUEEN, WHITE}, {KING, WHITE}, {BISHOP, WHITE}, {KNIGHT, WHITE}, {ROOK, WHITE} }
    };

    print_board(board);

    return 0;
}

void print_board(Square board[SIZE][SIZE])
{
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", board[i][j].Piece);  // Print the piece number (for simplicity)
        }
        printf("\n");
    }
    printf("\n");
}