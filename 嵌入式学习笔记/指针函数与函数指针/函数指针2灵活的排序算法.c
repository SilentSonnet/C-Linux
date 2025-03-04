//排序算法是函数指针的另一个常见应用场景。通过传递不同的比较函数，我们可以在不同的排序算法中重用相同的代码。以下是一个示例：
//注：qsort()是Linux环境下的函数，需要包含stdlib.h头文件
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef int (*compare_func_t)        (const void *, const void *);//仔细看 别看错了

void sort(int *array, size_t size, compare_func_t compare_func)
{
    qsort(array, size, sizeof(int), compare_func);
}

int compare_int(const void *a, const void *b)
{
    return (*(int*)a - *(int*)b);
}

int compare_reverse_int(const void *a, const void *b)
{
    return (*(int*)b - *(int*)a);
}

int main()
{
    int array[] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};
    size_t size = sizeof(array) / sizeof(int);
    sort(array, size, compare_int);
    for (size_t i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
    sort(array, size, compare_reverse_int);
    for (size_t i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
    return 0;
}
/*
在上面的代码中，我们定义了一个 sort 函数，它接受三个参数：一个整型数组、数组大小和一个比较函数指针。
??比较函数指针指向一个函数，该函数接受两个指向常量 void 类型的指针，并返回一个整型结果。
??在 sort 函数中，我们使用标准库函数 qsort 来对整型数组进行排序，其中比较函数指针由调用者传递。
??在 main 函数中，我们定义了两个比较函数 compare_int 和compare_reverse_int，分别用于升序和降序排序。然后，我们调用 sort 函数来对整型数组进行排序，并打印出结果。
*/