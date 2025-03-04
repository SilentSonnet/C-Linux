//?���ݷ���һ�����һЩ����Ż�������㷨����ͨ��ʹ�õݹ���ʵ�֡�����ָ���������ʵ�ֻ��ݷ��㷨��һЩ�ؼ����֡�


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
/*������Ĵ����У����Ƕ�����һ������ permute�����ڼ��������������С�
??�� permute �����У�����ʹ�õݹ����������п��ܵ����У���ʹ�ú���ָ�� callback ��ָ��ÿ����������һ������ʱӦ�õ��õĺ�����
??�ڱ����У����ǽ� print_array ������Ϊ�ص��������ݸ��� permute ����������ζ��ÿ�� permute ��������һ������ʱ����������� print_array ��������ӡ������С�
??�� main �����У����Ƕ�����һ�������������������� nums����ʹ�� permute �������������������������С���ÿ������һ������ʱ��permute ����������� print_array ��������ӡ������С�

*/
