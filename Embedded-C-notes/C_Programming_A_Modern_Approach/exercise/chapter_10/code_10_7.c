#include <stdio.h>

#define MAX_DIGITS 10
#define ROWS 3
#define COLS_PER_DIGIT 4

int segments[10][7] = {
    {1, 1, 1, 1, 1, 1, 0}, // 0
    {0, 1, 1, 0, 0, 0, 0}, // 1
    {1, 1, 0, 1, 1, 0, 1}, // 2
    {1, 1, 1, 1, 0, 0, 1}, // 3
    {0, 1, 1, 0, 0, 1, 1}, // 4
    {1, 0, 1, 1, 0, 1, 1}, // 5
    {1, 0, 1, 1, 1, 1, 1}, // 6
    {1, 1, 1, 0, 0, 0, 0}, // 7
    {1, 1, 1, 1, 1, 1, 1}, // 8
    {1, 1, 1, 1, 0, 1, 1}, // 9
};

char digits[ROWS][MAX_DIGITS * COLS_PER_DIGIT];

void clear_digits_array(void);
void process_digit(int digit, int position);
void print_digits_array(void);

int main(void)
{
    int count = 0;
    int ch;

    clear_digits_array();

    printf("Enter a number: ");
    while ((ch = getchar()) != '\n' && ch != EOF)
    {
        if (ch >= '0' && ch <= '9')
        {
            if (count < MAX_DIGITS)
            {
                process_digit(ch - '0', count);
                count++;
            }
        }
    }

    print_digits_array();
    return 0;
}

void clear_digits_array(void)
{
    int r, c;
    for (r = 0; r < ROWS; r++)
    {
        for (c = 0; c < MAX_DIGITS * COLS_PER_DIGIT; c++)
        {
            digits[r][c] = ' ';
        }
    }
}

void process_digit(int digit, int position)
{
    int off = position * COLS_PER_DIGIT;
    // 0
    if (segments[digit][0])
        digits[0][off + 1] = '_';
    // 1
    if (segments[digit][1])
        digits[1][off + 2] = '|';
    // 2
    if (segments[digit][2])
        digits[2][off + 2] = '|';
    // 3
    if (segments[digit][3])
        digits[2][off + 1] = '_';
    // 4
    if (segments[digit][4])
        digits[2][off] = '|';
    // 5
    if (segments[digit][5])
        digits[1][off] = '|';
    // 6
    if (segments[digit][6])
        digits[1][off + 1] = '_';
}

void print_digits_array(void)
{
    int row, col;
    for (row = 0; row < ROWS; row ++)
    {
        for (col = 0; col < MAX_DIGITS * COLS_PER_DIGIT; col ++)
        {
            putchar(digits[row][col]);
        }
        putchar('\n');
    }
}