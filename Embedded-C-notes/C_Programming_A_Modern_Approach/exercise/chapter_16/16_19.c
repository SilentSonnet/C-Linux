#include <stdio.h>

#define STRING_SIZE 40

enum types
{
    EM,
    SS,
};

struct pinball_machine
{
    char name[STRING_SIZE + 1];
    int year;
    enum types type;
    int players;
};

char *string[2] = {"EM", "SS"};

void print_pinball_machine(struct pinball_machine p);

int main(void)
{
    struct pinball_machine p = {
        .name = "Space Invaders",
        .year = 1980,
        .type = SS, 
        .players = 4
    };

    print_pinball_machine(p);

    return 0;
}

void print_pinball_machine(struct pinball_machine p)
{
    printf("The name is :%s\n", p.name);
    printf("The year is :%d\n", p.year);
    printf("The type is :%s\n", string[p.type]);
    printf("The number of players is :%d\n", p.players);
}