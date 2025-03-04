#include <stdio.h>

int main() {
    int arr[10] = {3, 5, 7, 2, 9, 0, 6, 1, 8, 4};  //乱序的
    int len = 10, temp,count = 0;
    //请编写代码对以上数组进行排序
    for(int i = 0;i < len - 1;i ++)
    {
        int flag=0;
        for(int j = 0;j < len - 1 - i;j ++)
        {
            if(arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                flag=1;
                count ++;
            }
        }
        if(flag == 0) // 假如说某次循环没有发生交换的话，就提前跳出大循环，因为此时数组已经是有序的了
            break;
    }
    for(int i = 0;i < len;i ++)
        printf("%d", arr[i]);

    printf("\n%d", count);
    return 0;
}