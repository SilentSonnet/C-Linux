//函数指针数组是指一个数组，其中的每个元素都是一个函数指针。这种数组可以用于实现一个分派表，
//根据输入参数的不同，动态地调用不同的函数。以下是一个示例
#include <stdio.h>

void add(int a, int b)
{
    printf("%d + %d = %d\n", a, b, a + b);
}

void subtract(int a, int b)
{
    printf("%d - %d = %d\n", a, b, a - b);
}

void multiply(int a, int b)
{
    printf("%d * %d = %d\n", a, b, a * b);
}

void divide(int a, int b)
{
    if (b == 0)
    {
        printf("cannot divide by zero\n");
    }
    else
    {
        printf("%d / %d = %d\n", a, b, a / b);
    }
}

typedef void (*operation_func_t)(int, int);

int main()
{
    operation_func_t operations[] = {add, subtract, multiply, divide};
    size_t num_operations = sizeof(operations) / sizeof(operation_func_t);
    int a = 10, b = 5;
    for (size_t i = 0; i < num_operations;i++)
    {
      operations[i](a,b);
    }
    return 0;
}
/*在上面的代码中，我们定义了四个函数 add、subtract、multiply 和 divide，分别对两个整数进行加、减、乘和除操作。
??然后，我们定义了一个函数指针类型 operation_func_t，它指向一个接受两个整型参数并没有返回值的函数。
??接着，我们定义了一个函数指针数组 operations，其中的每个元素都是一个 operation_func_t 类型的函数指针，分别指向 add、subtract、multiply 和 divide 函数。
??在 main 函数中，我们使用 for 循环遍历 operations 数组，并依次调用每个函数指针所指向的函数。在每次调用函数之前，我们可以根据需要设置 a 和 b 的值。这样，我们就可以动态地选择要执行的操作
*/
