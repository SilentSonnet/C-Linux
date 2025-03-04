//�����㷨�Ǻ���ָ�����һ������Ӧ�ó�����ͨ�����ݲ�ͬ�ıȽϺ��������ǿ����ڲ�ͬ�������㷨��������ͬ�Ĵ��롣������һ��ʾ����
//ע��qsort()��Linux�����µĺ�������Ҫ����stdlib.hͷ�ļ�
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef int (*compare_func_t)        (const void *, const void *);//��ϸ�� �𿴴���

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
������Ĵ����У����Ƕ�����һ�� sort ����������������������һ���������顢�����С��һ���ȽϺ���ָ�롣
??�ȽϺ���ָ��ָ��һ���������ú�����������ָ���� void ���͵�ָ�룬������һ�����ͽ����
??�� sort �����У�����ʹ�ñ�׼�⺯�� qsort ����������������������бȽϺ���ָ���ɵ����ߴ��ݡ�
??�� main �����У����Ƕ����������ȽϺ��� compare_int ��compare_reverse_int���ֱ���������ͽ�������Ȼ�����ǵ��� sort ����������������������򣬲���ӡ�������
*/