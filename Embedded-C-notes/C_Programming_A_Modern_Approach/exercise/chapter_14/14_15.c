#include<stdio.h>

#define ENGLISH

int main(void)
{
#if defined ENGLISH
    printf("Insert Disk 1\n");
#elif defined FRENCH
    printf("Inserez Le Disque 1\n");
#elif defined SPANISH
    printf("Inserte El Disco 1\n");
#else
    printf("No language selected\n");
#endif
    return 0;
}