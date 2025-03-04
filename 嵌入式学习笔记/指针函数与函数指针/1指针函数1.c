/*指针函数与函数指针   常考常用*/

#include <stdio.h>
#include <stdlib.h>
//本质上是一个函数 但是返回值是指针  叫做指针函数  注意这个函数的返回值要么是static
//要么是全局变量，因为函数内部的变量局部变量会在函数结束之后回收
int * func_sum(int n)
{
    if(n<0)
    {
        printf("error:n must >0\n");
        exit(-1);
    }
    static int sum=0;
    int *p=&sum;
    for (int i=0;i<n;i++)
    {
        sum+=i;
    }
return p;
}


/*
函数指针   函数指针本质上是指针  这个指针的地址是一个函数    
也可以说函数指针是指向代码段中函数入口地址的指针
ex: ret (*p)(args, ...);   *p是指向的函数名   ret是返回值类型  args是参数表
*/
int max(int a, int b)
{
    return a > b ? a : b;
}
/*
/*
为什么要使用函数指针？
那么，有不少人就觉得，本来很简单的函数调用，搞那么复杂干什么？其实在这样比较简单的代码实现中不容易看出来，当项目比较大，代码变得复杂了以后，函数指针就体现出了其优越性。
举个例子，如果我们要实现数组的排序，我们知道，常用的数组排序方法有很多种，比如快排，插入排序，冒泡排序，选择排序等，如果不管内部实现，你会发现，除了函数名不一样之外，返回值，包括函数入参都是相同的，这时候如果要调用不同的排序方法，就可以使用指针函数来实现，我们只需要修改函数指针初始化的地方，而不需要去修改每个调用的地方（特别是当调用特别频繁的时候）。
函数指针的一个非常典型的应用就是回调函数。
什么是回调函数？
回调函数就是一个通过指针函数调用的函数。其将函数指针作为一个参数，传递给另一个函数。
回调函数并不是由实现方直接调用，而是在特定的事件或条件发生时由另外一方来调用的。
同样我们来看一个回调函数的例子：
*/
int fun_sum1(int n)//普通函数
{
    int sum=0;
    if(n<0)
    {
        printf("n must be >0");
        exit(-1);
    }
    for (int i=0;i<n;i++)
    {
        sum+=i;
    }
    return sum;
}
//回调函数    第二个参数是一个函数指针 ，通过函数指针调用普通函数 并把结果返回给主调函数
int callback(int n,int (*p)(int ))
{
    return p(n);
}

int main(void)
{
    int num=0;
    int * p=0;//用来接收返回值   
    int (*P)(int,int);//函数指针的定义
    int (*P1)();
    int (*P2)(int a,int b);
    P=max;
    P1=max;
    P2=max;
    printf("please input one number:");
    scanf("%d",&num);
    p=func_sum(num);//接收返回值地址
    printf("指针函数调用结果 sum:%d\n",*p);
    int ret=P(10,15);
    int ret1=(*max)(10,16);
    int ret2=(*P2)(10,17);
    printf("函数指针三种方法初始化和结果max=%d    %d      %d\n",ret,ret1,ret2);
    printf("回调函数结果=%d \n",callback(num,fun_sum1));
    return 0;
}
