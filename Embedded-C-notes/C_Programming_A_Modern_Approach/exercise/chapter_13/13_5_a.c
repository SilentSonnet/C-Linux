#include<stdio.h>
#include<string.h>
#include<ctype.h>

#define SIZE 100

void capitalize(char *a, int n);

int main(void)
{
    char arr[SIZE] = "aBCdeFGHIJK!@#$";

    capitalize(arr, strlen(arr));

    printf("The output is : %s\n", arr);

    return 0;
}

void capitalize(char *a, int n)
{
    for(int i = 0;i < n;i ++)
        if('a' <= a[i] && a[i] <= 'z')
            a[i] = toupper(a[i]);
}