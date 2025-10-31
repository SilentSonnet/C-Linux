#include<stdio.h>
int main(void)
{
    int i = 10;
    while (i < 10) {
        printf("%d ", i++);
    }
    printf("\n");
    i = 10;
    for (; i < 10;) {
        printf("%d ", i++);
    }
    printf("\n");
    i = 10;
    do {
        printf("%d ", i++);
    } while (i < 10);
    printf("\n");

    return 0;
}