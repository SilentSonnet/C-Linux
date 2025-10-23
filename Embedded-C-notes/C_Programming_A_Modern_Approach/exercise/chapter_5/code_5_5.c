// **表 5-7 美国某州单身居民个人所得税缴纳标准**

// | 收入（美元）      | 税金计算方式 |
// |------------------|-------------|
// | 未超过 750       | 收入的 1% |
// | 750 ～ 2250      | 7.50 美元 + 超出 750 美元部分的 2% |
// | 2250 ～ 3750     | 37.50 美元 + 超出 2250 美元部分的 3% |
// | 3750 ～ 5250     | 82.50 美元 + 超出 3750 美元部分的 4% |
// | 5250 ～ 7000     | 142.50 美元 + 超出 5250 美元部分的 5% |
// | 超过 7000        | 230.00 美元 + 超出 7000 美元部分的 6% |


#include<stdio.h>
int main(void)
{
    int income;
    float tax;
    printf("Enter your income:");
    scanf("%d", &income);

    if(income < 750)
        printf("The tax is:%.2f\n", income * 0.01f);
    else if(750 <= income && income <= 2250)
        printf("The tax is:%.2f\n", (income - 750) * 0.02 + 7.5f);
    else if(2250 <= income && income <= 3750)
        printf("The tax is:%.2f\n", (income - 2250) * 0.03 + 37.5f);
    else if(3750 <= income && income <= 5250)
        printf("The tax is:%.2f\n", (income - 3750) * 0.04 + 82.5f);
    else if(5250 <= income && income <= 7000)
        printf("The tax is:%.2f\n", (income - 5250) * 0.05 + 142.5f);
    else if(income > 7000)
        printf("The tax is:%.2f\n", (income - 7000) * 0.06 + 230.0f);


    return 0;
}