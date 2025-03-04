//?回溯法是一种求解一些组合优化问题的算法，它通常使用递归来实现。函数指针可以用于实现回溯法算法的一些关键部分。


#include <stdio.h>
#include <stdlib.h>

typedef void (*callback_func_t)(const int *, size_t);

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void permute(int *nums, size_t len, size_t depth, callback_func_t callback) {
    if (depth == len)
    {
        callback(nums, len);
        return;
    }
    for (size_t i = depth; i < len; i++)
    {
        swap(&nums[depth], &nums[i]);
        permute(nums, len, depth + 1, callback);
        swap(&nums[depth], &nums[i]);
    }
}

void print_array(const int *arr, size_t len)
{
    for (size_t i = 0; i < len; i++) 
    { 
      printf("%d ", arr[i]); }
      printf("\n"); 
  
}

int main()
{
  int nums[] = {1, 2, 3};
  permute(nums, sizeof(nums) / sizeof(int), 0, print_array); 
  return 0;
}
/*在上面的代码中，我们定义了一个函数 permute，用于计算给定数组的排列。
??在 permute 函数中，我们使用递归来生成所有可能的排列，并使用函数指针 callback 来指定每当我们生成一个排列时应该调用的函数。
??在本例中，我们将 print_array 函数作为回调函数传递给了 permute 函数。这意味着每当 permute 函数生成一个排列时，它都会调用 print_array 函数来打印这个排列。
??在 main 函数中，我们定义了一个包含三个整数的数组 nums，并使用 permute 函数来计算这个数组的所有排列。在每次生成一个排列时，permute 函数都会调用 print_array 函数来打印这个排列。

*/
