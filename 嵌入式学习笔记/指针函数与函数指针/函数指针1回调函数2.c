//本文导读  定义及小例子 以及大例子

//如果要笔试回答回调函数定义的话
/*回调函数就是一个通过函数指针调用的函数。如果你把函数的指针（地址）作为参数传递给另一个函
数，当这个指针被用来调用其所指向的函数时，我们就说这是回调函数。回调函数不是由该函数的实现
方直接调用，而是在特定的事件或条件发生时由另外的一方调用的，用于对该事件或条件进行响应。
*/
/*简单理解

把一段可执行的代码像参数传递那样传给其他代码，而这段代码会在某个时刻被调用执行，这就叫做回调。

如果代码立即被执行就称为同步回调，如果过后再执行，则称之为异步回调。

回调函数就是一个通过函数指针调用的函数。如果你把函数的指针（地址）作为参数传递给另一个函数，当这个指针被用来调用其所指向的函数时，我们就说这是回调函数。

回调函数不是由该函数的实现方直接调用，而是在特定的事件或条件发生时由另外的一方调用的，用于对该事件或条件进行响应


在回调中，主程序把回调函数像参数一样传入库函数  重点
只要我们改变传进库函数的参数，就可以实现不同的功能，这样有没有觉得很灵活？并且当库函数很复
杂或者不可见的时候利用回调函数就显得十分优秀。

*/
#include <stdio.h>
#include <stdlib.h>
 
/****************************************
 * 函数指针结构体
 ***************************************/
typedef struct _OP {
    float (*p_add)(float, float); 
    float (*p_sub)(float, float); 
    float (*p_mul)(float, float); 
    float (*p_div)(float, float); 
} OP; 
 
/****************************************
 * 加减乘除函数
 ***************************************/
float ADD(float a, float b) 
{
    return a + b;
}
 
float SUB(float a, float b) 
{
    return a - b;
}
 
float MUL(float a, float b) 
{
    return a * b;
}
 
float DIV(float a, float b) 
{
    return a / b;
}
 
/****************************************
 * 初始化函数指针
 ***************************************/
void init_op(OP *op)
{
    op->p_add = ADD;
    op->p_sub = SUB;
    op->p_mul = MUL;
    op->p_div = DIV;
}
 
/****************************************
 * 库函数
 ***************************************/
float add_sub_mul_div(float a, float b, float (*op_func)(float, float))
{
    return (*op_func)(a, b);
}
 
int main(int argc, char *argv[]) 
{
    OP *op = (OP *)malloc(sizeof(OP)); 
    init_op(op);
    
    /* 直接使用函数指针调用函数 */ 
    printf("ADD = %f, SUB = %f, MUL = %f, DIV = %f\n", (op->p_add)(1.3, 2.2), (*op->p_sub)(1.3, 2.2), 
            (op->p_mul)(1.3, 2.2), (*op->p_div)(1.3, 2.2));
     
    /* 调用回调函数 */ 
    printf("ADD = %f, SUB = %f, MUL = %f, DIV = %f\n", 
            add_sub_mul_div(1.3, 2.2, ADD), 
            add_sub_mul_div(1.3, 2.2, SUB), 
            add_sub_mul_div(1.3, 2.2, MUL), 
            add_sub_mul_div(1.3, 2.2, DIV));
 
    return 0; 
}
//大例子
/*
一个GPRS模块联网的小项目，使用过的同学大概知道2G、4G、NB等模块要想实现无线联网功能都需要经历模块上电初始化、
注册网络、查询网络信息质量、连接服务器等步骤，这里的的例子就是，利用一个状态机函数（根据不同状态依次调用不同实现
方法的函数），通过回调函数的方式依次调用不同的函数，实现模块联网功能，如下：

/*********  工作状态处理  ********

typedef struct
{
 uint8_t mStatus;
 uint8_t (* Funtion)(void); //函数指针的形式
} M26_WorkStatus_TypeDef;  //M26的工作状态集合调用函数
 
 
/**********************************************
** >M26工作状态集合函数
***********************************************/
/*
M26_WorkStatus_TypeDef M26_WorkStatus_Tab[] =
{    
    {GPRS_NETWORK_CLOSE,  M26_PWRKEY_Off  }, //模块关机
    {GPRS_NETWORK_OPEN,  M26_PWRKEY_On  }, //模块开机
    {GPRS_NETWORK_Start,   M26_Work_Init  }, //管脚初始化
    {GPRS_NETWORK_CONF,  M26_NET_Config  }, /AT指令配置
    {GPRS_NETWORK_LINK_CTC,  M26_LINK_CTC  }, //连接调度中心  
    {GPRS_NETWORK_WAIT_CTC, M26_WAIT_CTC  },  //等待调度中心回复 
    {GPRS_NETWORK_LINK_FEM, M26_LINK_FEM  }, //连接前置机
    {GPRS_NETWORK_WAIT_FEM, M26_WAIT_FEM  }, //等待前置机回复
    {GPRS_NETWORK_COMM,  M26_COMM   }, //正常工作    
    {GPRS_NETWORK_WAIT_Sig,  M26_WAIT_Sig  },  //等待信号回复
    {GPRS_NETWORK_GetSignal,  M26_GetSignal  }, //获取信号值
    {GPRS_NETWORK_RESTART,  M26_RESET   }, //模块重启
}
/**********************************************
** >M26模块工作状态机，依次调用里面的12个函数   
**********************************************
uint8_t M26_WorkStatus_Call(uint8_t Start)
{
    uint8_t i = 0;
    for(i = 0; i < 12; i++)
    {
        if(Start == M26_WorkStatus_Tab[i].mStatus)
        {          
      return M26_WorkStatus_Tab[i].Funtion();
        }
    }
    return 0;
}
*/