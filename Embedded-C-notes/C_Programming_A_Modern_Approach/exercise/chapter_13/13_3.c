#include<stdio.h>

#define SIZE 100

int main(void)
{
    char s[SIZE];
    int i, j;
    printf("Enter something : ");
    
    scanf("%d%s%d", &i, s, &j);

    printf("i is : %d\n", i);
    printf("s is : %s\n", s);
    printf("j is : %d\n", j);

    return 0;
}