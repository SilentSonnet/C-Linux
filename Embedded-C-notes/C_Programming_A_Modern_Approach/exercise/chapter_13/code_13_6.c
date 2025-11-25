/* planet.c (Chapter 13, page 304) */
/* Checks planet names */

#include <stdio.h>
#include <string.h>
#include<ctype.h>
#include<stdbool.h>

#define NUM_PLANETS 9

bool string_equal(char *s, char *t);

int main(int argc, char *argv[])
{
    char *planets[] = {"Mercury", "Venus", "Earth",
                       "Mars", "Jupiter", "Saturn",
                       "Uranus", "Neptune", "Pluto"};
    int i, j;

    for (i = 1; i < argc; i++)
    {
        for (j = 0; j < NUM_PLANETS; j++)
            if (string_equal(argv[i], planets[j]) == 0)
            {
                printf("%s is planet %d\n", argv[i], j + 1);
                break;
            }
        if (j == NUM_PLANETS)
            printf("%s is not a planet\n", argv[i]);
    }

    return 0;
}

bool string_equal(char *s, char *t)
{
    while(*s && *t)
    {
        if(toupper(*s) != toupper(*t))
            return false;
        s ++;
        t ++;
    }
    return *s == *t;
}