//��ǰ��ָ�뺯��1  ���ĵ���  �ص�����  ����ָ�������  ���ʵ�����������㷨

/*�ص�����
�ص�����ָ����ĳ���¼�����ʱ�ᱻ���õĺ�����ͨ�����ص���������ĳ���⺯�����߿��
������ע��ģ�����������ʱ���⺯�����߿�ܺ�������ûص�������ִ����Ӧ�Ĳ���
*/

#include <stdio.h>

void handle_event(int even_type,void (*callback)(void))
{
    printf(":event %d occurred\n",even_type);
    if(callback)
    {
        callback();
    }
}
void callback_function()
{
    printf("callback function called\b");
}
void callback_function1()
{
    printf("�����޵�");
}

int main()
{
    handle_event(1,callback_function);
    handle_event(2,NULL);
    handle_event(3,callback_function1);
    return 0;
}

/*
������һ��  Ȼ���ɹ�����  �㷢����ʲô

������Ĵ����У����Ƕ�����һ��handle_event����������������������һ�����¼�����
һ���Ǻ���ָ�룬�������ָ�벻Ϊ�գ�������ָ���ĺ���
��main�У����ǵ���handle_event�����������¼�����һ������ע���˻ص�����callback_function
�ڶ����¼�û��ע��ص�������
��������
*/
/*
int Callback_1(int a)   ///< �ص�����1
{
    printf("Hello, this is Callback_1: a = %d ", a);
    return 0;
}
 
int Callback_2(int b)  ///< �ص�����2
{
    printf("Hello, this is Callback_2: b = %d ", b);
    return 0;
}
 
int Callback_3(int c)   ///< �ص�����3
{
    printf("Hello, this is Callback_3: c = %d ", c);
    return 0;
}
 
int Handle(int x, int (*Callback)(int)) ///< ע�������õ��ĺ���ָ�붨��
{
    Callback(x);
}
 
int main()
{
    Handle(4, Callback_1);
    Handle(5, Callback_2);
    Handle(6, Callback_3);
    return 0;
}
*/