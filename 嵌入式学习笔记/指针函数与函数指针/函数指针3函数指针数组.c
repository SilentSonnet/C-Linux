//����ָ��������ָһ�����飬���е�ÿ��Ԫ�ض���һ������ָ�롣���������������ʵ��һ�����ɱ�
//������������Ĳ�ͬ����̬�ص��ò�ͬ�ĺ�����������һ��ʾ��
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
/*������Ĵ����У����Ƕ������ĸ����� add��subtract��multiply �� divide���ֱ�������������мӡ������˺ͳ�������
??Ȼ�����Ƕ�����һ������ָ������ operation_func_t����ָ��һ�������������Ͳ�����û�з���ֵ�ĺ�����
??���ţ����Ƕ�����һ������ָ������ operations�����е�ÿ��Ԫ�ض���һ�� operation_func_t ���͵ĺ���ָ�룬�ֱ�ָ�� add��subtract��multiply �� divide ������
??�� main �����У�����ʹ�� for ѭ������ operations ���飬�����ε���ÿ������ָ����ָ��ĺ�������ÿ�ε��ú���֮ǰ�����ǿ��Ը�����Ҫ���� a �� b ��ֵ�����������ǾͿ��Զ�̬��ѡ��Ҫִ�еĲ���
*/
