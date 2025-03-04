#include <stdio.h>

int arr[] = {2, 7, 9, 3, 1}, size = 5, result;
int dp[] = {2, 7, 0, 0, 0};

int max(int number_1, int number_2)
{
    if(number_1 > number_2)
        return number_1;
    else
        return number_2;
}

int getDP(int index)
{
    if(index == 1)
        return arr[1];
    else if(index == 0)
        return arr[0];
    else
        return max(getDP(index - 1), getDP(index - 2) + arr[index]);
}

int DP_BsiteSolution()
{
    int array[] = {2, 7, 9, 3, 1};

    int dp_arr[size];

    dp_arr[0] = array[0];
    dp_arr[1] = array[1] > array[0] ? array[1] : array[0];
    for(int i = 2;i < size;i ++)
        dp_arr[i] = dp_arr[i - 1] > dp_arr[i - 2] + array[i] ? dp_arr[i - 1]: dp_arr[i - 2] + array[i];
    printf("%d", dp_arr[size - 1]);
    return dp_arr[size -1];
}

int main()
{
    result = max(getDP(size - 1), getDP(size - 2));
    printf("%d\n", result);
    DP_BsiteSolution();
    return 0;
}