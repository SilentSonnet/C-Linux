#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

int roll_dice(void);
bool play_game(void);

int main(void)
{
    char ch;
    int win = 0, lose = 0;

    srand(time(NULL));

    while (1)
    {
        if (play_game())
        {
            printf("\nYou win! ");
            win++;
        }
        else
        {
            printf("\nYou lose! ");
            lose++;
        }

        printf("\nPlay again? ");
        if ((ch = getchar()) == 'N' || ch == 'n')
        {
            printf("Wins: %d Losses: %d\n", win, lose);
            return 0;
        }
        else if (ch == 'Y' || ch == 'y')
        {   
            // capture the extra \n character
            while((ch = getchar()) != '\n' && ch != EOF);
            printf("\n");
            continue;
        }
        else
            return 0;
    }
}

int roll_dice(void)
{
    int dice_1, dice_2;
    dice_1 = rand() % 6 + 1;
    dice_2 = rand() % 6 + 1;

    return dice_1 + dice_2;
}

bool play_game(void)
{
    char ch;
    bool isFirst = true;
    int res, goal;
    while (1)
    {
        if (isFirst == true || (ch = getchar()) == '\n')
        {
            res = roll_dice();
            printf("You rolled: %d", res);

            if(!isFirst)
            {
                if (res == goal)
                    return true;
                else if(res == 7)
                    return false;
            }
        }

        if (isFirst)
        {
            if (res == 7 || res == 11)
                return true;
            else if (res == 2 || res == 3 || res == 12)
                return false;
            else
            {
                goal = res;
                isFirst = false;
                printf("\nYou point is %d", res);
            }
        }
    }
}