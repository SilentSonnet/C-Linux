//接前文指针函数1  本文导读  回调函数  函数指针参数化  如何实现灵活的排序算法

/*回调函数
回调函数指的是某个事件发生时会被调用的函数，通常，回调函数是在某个库函数或者框架
函数中注册的，当条件满足时，库函数或者框架函数会调用回调函数来执行相应的操作
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
    printf("咸鱼无敌");
}

int main()
{
    handle_event(1,callback_function);
    handle_event(2,NULL);
    handle_event(3,callback_function1);
    return 0;
}

/*
先运行一下  然后由果推因  你发现了什么

在上面的代码中，我们定义了一个handle_event函数，它接受两个参数：一个是事件类型
一个是函数指针，如果函数指针不为空，则会调用指定的函数
在main中，我们调用handle_event函数来触发事件，第一个函数注册了回调函数callback_function
第二个事件没有注册回调函数。
下面类似
*/
/*
int Callback_1(int a)   ///< 回调函数1
{
    printf("Hello, this is Callback_1: a = %d ", a);
    return 0;
}
 
int Callback_2(int b)  ///< 回调函数2
{
    printf("Hello, this is Callback_2: b = %d ", b);
    return 0;
}
 
int Callback_3(int c)   ///< 回调函数3
{
    printf("Hello, this is Callback_3: c = %d ", c);
    return 0;
}
 
int Handle(int x, int (*Callback)(int)) ///< 注意这里用到的函数指针定义
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