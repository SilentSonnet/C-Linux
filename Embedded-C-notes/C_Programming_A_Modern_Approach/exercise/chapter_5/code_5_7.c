#include<stdio.h>
int main(void)
{
    int i, j, k, l, max, min;
    printf("Enter four integers:");
    scanf("%d%d%d%d", &i, &j, &k, &l);

    if(i > j)
    {
        max = i;
        min = j;
    }
    else 
    {
        max = j;
        min = i;
    }
    if(max < k)
        max = k;
    else if(min > k)
        min = k;

    if(max < l)
        max = l;
    else if(min > l)
        min = l;
    
    printf("Largest:%d\n", max);
    printf("Smallest:%d\n", min);

    return 0;
}