#include <stdio.h>

enum
{
    NORTH,
    SOUTH,
    EAST,
    WEST
} direction;

int main(void)
{
    int x = 0, y = 0;
    char ch;

    printf("The starting coordinates for x and y is (%d, %d)\n", x, y);
    printf("Enter the operation:");
    for(;;)
    {
        scanf("%c", &ch);

        switch (ch)
        {
        case 'w':
            direction = NORTH;
            break;
        case 'a':
            direction = WEST;
            break;
        case 's':
            direction = SOUTH;
            break;
        case 'd':
            direction = EAST;
            break;
        case 'q': 
            printf("The program is exiting ...\n");
            return 0;
            break;
        case '\n':
            continue;
            break;
        default:
            printf("False input!\n");
            continue;
            break;
        }

        switch (direction)
        {
        case NORTH:
            y -= 1;
            break;
        case SOUTH:
            y += 1;
            break;
        case EAST:
            x += 1;
            break;
        case WEST:
            x -= 1;
            break;
        default:
            printf("False input!\n");
            break;
        }
        printf("Now the coordinates for x and y is (%d, %d)\n", x, y);
        printf("Enter the operation:");
    }

    return 0;
}