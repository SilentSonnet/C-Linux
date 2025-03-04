#include <stdio.h>

int FibonacciSequence_Bsite()
{
    int target = 5, result; // target是要取的数，result是最终的结果
    int a = 1, b = 1, c;
    for (int i = 2; i < target; i++)
    {
        c = a + b;
        a = b;
        b = c;
    }
    result = c;
    printf("%d", c);

    return 0;
}

int FibonacciSequence_Myslf()
{
    int input = 0, i = 1, j = 1, count = 1;
    scanf("%d", &input);

    if (input == 1 || input == 2)
        printf("1");
    else if (input > 2)
    {
        int temp;
        while (count <= input - 2)
        {
            temp = j;
            j = i + j;
            i = temp;
            count++;
        }
        printf("%d", j);
    }
}

int sum = 0;

int Recursion(int index)
{
    if (index >= 3) // FibonacciSequence是从第三位开始计算的，所以应当从第三位才开始用公式
    {
        sum = Recursion(index - 1) + Recursion(index - 2);
        return sum;
    }
    else if (index == 2)
    {
        sum = 1; // 递归终点，第二个数是1
        return sum;
    }
    else if (index == 1)
    {
        sum = 1; // 递归终点，第一个数是1
        return sum;
    }
}

int FibonacciSequence_Recursion(int number) { Recursion(number); }

int FibonacciSequence_Bsite_Recursion(int target)
{
    int dp[target];
    dp[0] = dp[1] = 1;
    for (int i = 2; i < target; i++)
        dp[i] = dp[i - 1] + dp[i - 2];

    return dp[target - 1];
}

int main()
{
    // FibonacciSequence_Bsite();
    FibonacciSequence_Recursion(7);
    printf("%d %d", sum, FibonacciSequence_Bsite_Recursion(7));
    return 0;
}
