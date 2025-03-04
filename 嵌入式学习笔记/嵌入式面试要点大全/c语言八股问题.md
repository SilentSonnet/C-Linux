文件导读：此文件将存放 c的基础问题，包括但不限于，存放位置，编译链，#define和条件编译等等因问题太多 不做目录，请ctrl+f自行查询


全局变量局部变量分别存放在哪？

局部变量在栈，全局在静态存储区——啥叫栈
栈是现代计算机程序里最为重要的概念之一，栈在程序中用于维护函数调用上下文，函数中的参数和局部变量存储在栈上。 栈保存了一个函数调用所需的维护信息参数，返回地址，局部变量，调用上下文。
总体先说一遍c的存储区吧  
静态存储区：只读区初始化区未初始化区 在编译链接阶段确定，什么叫编译链接有本书叫做编译原理自行查阅

动态存储区：栈和堆
堆 手动申请常用函数malloc 任意出入  空间小读取速度快
栈 自动分配 数据先入后出 后进先出   空间大读取速度慢
两种状态 满栈和空栈 可存放 参数，局部变量，局部数组等作用范围在函数内部的数据，它的作用就是完成函数调用，在调用完成后返回栈指针初始位置等待下一次使用。也就是函数内部的没有staic的每一个变量都是新产生的，而非上一次的。所以返回值是局部变量的指针，返回的将是一个无效的内存地址，无法得到真实值。

堆的管理问题上一定要回答申请堆区个人会写注释并标记此处，防止忘记free回收内存造成内存泄漏，那傻逼要是问你什么叫内存泄漏，你就回答老师说的编码规范，具体问题自己都注意着，从来没出现过这个问题。因为内存泄漏是一个很严重的问题，这个问题的答案是申请的内存永远不会参与下一次使用，等待下次调用此函数时将导致函数不可用。

引申问题，什么叫野指针，野指针就是指向被free或者realloc释放了，内存可能参与重新分配了，原本指向的内存区域与现在内容不一致。


#define #ifdfine   #标识符类问题
第一 #define 本质是字符串代换  着重注意此条 #define 只代换不运算
第二#define 使用时可以使用\续行

无参#define和有参
顾名思义 有参就是#define  M(a+b)   这种
实际考题一般为
#define M (a+b)
main(){
int a{3},b;
printf("input a number: ");
scanf("%d",&b);
s=M*M;
printf("s=%d\n",a);
}
还有特别注意 在程序中多次#define  宏的话  不会报错 只会警告


上例程序中首先进行宏定义，定义M来替代表达式(a+b),在 s= M * M 中作了宏调用。在预处理时经宏展开后该语句变为： S=(a+b)*(a+b)
但要注意的是，在宏定义中表达式(a+b)两边的括号不能少。否则会发生错误。
如当作以下定义后：#difine M (a)+(b)
在宏展开时将得到下述语句：S= (a)+(b)*(a)+(b)

更简单题就是加法和乘法一样，但是更简单，你代换完了再运算就行

宏定义还要说明以下几点：
1. 宏定义是用宏名来表示一个字符串，在宏展开时又以该字符串取代宏名，这只是一种简单的代换，字符串中可以含任何字符，可以是常数，也可以是表达式，预处理程序对它不作任何检查。如有错误，只能在编译已被宏展开后的源程序时发现。
2. 宏定义不是说明或语句，在行末不必加分号，如加上分号则连分号也一起置换。
3. 宏定义必须写在函数之外，其作用域为宏定义命令起到源程序结束。如要终止其作用域可使用#undef命令

条件编译
#ifdef宏名
//语句段
#endif

最常见的条件编译是防止重复包含头文件的宏，几乎所有头文件都要采用下述的方法编辑以防止被重复包含，形式跟下面代码类似：

#ifndef ABCD_H
#define ABCD_H

// ... some declaration codes

#endif // #ifndef ABCD_H

常见的条件编译指令
1、#if：如果条件为真，则执行相应的操作。
2、#elif：类似于 elseif 的用法，当前面条件为假，再判断该条件是否为真，如果是真，则执行相应操作。
3、#else：如果前面所有条件均为假，则执行相应操作。
4、#ifdef：如果该宏已定义，则执行相应操作。
5、#ifndef：如果该宏没有定义，则执行相应操作。
6、#endif ：结束对应的条件编译指令。(不能省略)
defined ：与#if, #elif配合使用，判断某个宏是否被定义

#if，#elif，#else与#endif
#if 指令很像C语言中的 if 语句。#if 后面跟常量表达式，如果表达式为非0，则表达式为真，执行 #if 与 #endif 中间的所有C代码；如果表达式为0，则表达式为假，中间的代码不参与编译。

#if可与常量表达式配合使用。常用格式如下：

#if 常量表达式1
// ... some codes
#elif 常量表达式2
// ... other codes
#elif 常量表达式3
// ...
...
#else
// ... statement
#endif






上面的#if、#elif、#else可以与条件判断语句的if elseif else联系起来理解，同样地，#elif、#else也不是一定需要存在。
常量表达式可以是包含宏、算术运算、逻辑运算等等的合法C常量表达式，如果常量表达式为一个未定义的宏, 那么它的值被视为0。

#if MACRO_NON_DEFINED // 等价于

#if 0





在判断某个宏是否被定义时，应当避免使用#if，因为该宏的值可能就是被定义为0。而应当使用#ifdef或#ifndef。

下面举几个例子：
例1：

#if 0
//代码1
#endif





上面这种用法，相当于#if 0 和 #endif之间的代码被注释掉了，一般在IDE环境中会显示灰色。如果需要这段代码参与编译，那么把#if 0改为#if 1即可。但这种用法最好只是调试阶段临时用，没有太大的现实意义，因为这就跟/* */注释符号类似了。

例2：

#define FUNCTION 0

#if FUNCTION
//代码1
#endif





上面这种用法相对常用，即FUNCTION宏定义为0或者1，决定了#if FUNCTION和#endif之间的代码是否参与编译。
对FUNCTION的宏定义可以放在某个配置用的头文件中，便于集中管控。

例3：

#define FUNCTION 0

#if FUNCTION
//代码1
#else
//代码2
#endif





与例2类似，FUNCTION宏定义为0或者1，FUNCTION为1，则#if FUNCTION和#else之间的代码1参与编译，FUNCTION为0，则#else和#endif之间的代码2参与编译。

例4：

#define FUNCTION 0

#if (FUNCTION == 0)
//代码1
#elif (FUNCTION == 1)
//代码2
#elif (FUNCTION == 2)
//代码3
#endif






FUNCTION宏定义为0或者1或者2，FUNCTION为0，则代码1参与编译，FUNCTION为1，则代码2参与编译，FUNCTION为2，则代码3参与编译。
由于0,1,2不能直观理解，我们还能对0,1,2进行一层宏定义，以增加代码可阅读性，比如：

#define FUN_A 0
#define FUN_B 1
#define FUN_C 2

#define FUNCTION FUN_A

#if (FUNCTION == FUN_A)
//代码1
#elif (FUNCTION == FUN_B)
//代码2
#elif (FUNCTION == FUN_C)
//代码3
#endif







例5：

#define FUN_A 1
#define FUN_B 1

#if (FUN_A && FUN_B)
//代码1
#endif





只有当FUN_A和FUN_B同时定义为1时，代码1才参与编译，否则代码1不参与编译。

例6：

#define FUNCTION 1

#if (FUNCTION < 5)
//代码1
#endif




只有当FUNCTION的定义小于5时，代码1才参与编译，否则代码1不参与编译。

#ifdef，#ifndef，#else与#endif
条件编译中相对常用的预编译指令。模式如下：

#ifdef ABC
// ... codes while definded ABC
#elif (CODE_VERSION > 2)
// ... codes while CODE_VERSION > 2
#else
// ... remained cases
#endif // #ifdef ABC





#ifdef用于判断某个宏是否定义，和#ifndef功能正好相反，二者仅支持判断单个宏是否已经定义，上面例子中二者可以互换。
如果不需要多条件预编译的话，上面例子中的#elif和#else均可以不写。

#ifdef 由于只能判定单个宏是否定义，那么自然没有#if 后面可以判定一个表达式那么多花样，所以就不能举大量的例子了。

#if defined
defined用来测试某个宏是否被定义。defined(name): 若宏被定义，则返回1，否则返回0。
它与#if、#elif、#else结合使用来判断宏是否被定义，乍一看好像它显得多余, 因为已经有了#ifdef和#ifndef。defined可用于在一条判断语句中声明多个判别条件；#ifdef和#ifndef则仅支持判断一个宏是否定义。

类似：

#if defined(VAX) && defined(UNIX) && !defined(DEBUG) 

当然，如果是判断单个条件，#if defined和#ifdef没有啥差别。

#if defined(VAX)
和
#ifdef VAX

#if !defined
#if !defined与#ifndef类似，都是用来判断宏没有被定义。
区别在于#if !defined可以判断多个（类似前面的#if defined）。

#if !defined(VAX)
和
#ifndef VAX

这两者效果一样。

#if !defined的本质还是#if defined，所以它们可以组合

#if defined(VAX) && defined(UNIX) && !defined(DEBUG) 
1
这个例子就是当VAX和UNIX都定义了，并且DEBUG没有被定义的情况下，则条件成立。





break 和continue 的作用和区别是什么

1 break和continue的作用都是用来控制循环结构的，主要作用是停止循环

2 区别
break用于跳出一个循环体或者完全结束一个循环，注意是完全

当break出现在switch时只是跳出该语句体，并不能完全终止循环

continue是结束本次循环后续的语句直接开启下次循环
continue并没有使整个循环终止


结构体和联合体的区别以及他们各自占几个单位的例子

首先struct是比较常用的结构体（struct）:用户自定义的可用的数据类型，允许存储不同类型的数据，结构体里的成员按定义先后顺序存放。


联合（union）:联合（共同体）是一种特殊的数据类型，它允许您在相同的内存位置存储不同数据类型的数据（但不同时），这样可以定义一个带有多成员的共用体，通过不同成员访问不同的存储空间。

联合（union）

基本格式：

union

{

unsigned char      var1;

unsigned short     var2;

unsigned int       var3;

};

存储：联合所占的内存大小为空间内最大内存成员的内存大小；联合内的成员占用同一个内存空间

 上述的union中，var1 为char类型，其所占1B内存；var2为short类型，占2B；var3为int类型占4B；由此可见，在这个联合中，最大内存成员是var3，所以这个联合所占内存空间与var3所占内存一样，是为4B


应用：联合的同一内存空间存放不同成员这个特性，可以辅助验证大端字节序与小端字节序  常考

例子：

#include <stdio.h>

#include <errno.h>

#include <string.h>

int main(int argc, char **argv)

{

    union

    {

            unsigned char    var1;

            unsigned short   var2;

            unsigned int     var3;

    }test;

    printf("union size:%d\n", sizeof(test));

    test.var3 = 0x12345678;

    //test.var2 = 0xAABB;

    printf("var1:0x%02x\n", test.var1);

    printf("var2:0x%04x\n", test.var2);

    printf("var3:0x%03x\n", test.var3);

    if(test.var1 == 0x78)

    {

        printf("LSB\n");

    }

    else if(test.var1 == 0x12)

    {

        printf("HSB\n");

    }

    else

    {

        printf("error:%s\n", strerror(errno));

        return -1;

    }

    return 0;

}

结构体（struct）

结构体由基本数据类型构造处一种新的符合数据类型，空间内按照定义顺序存储，结构体相当于一个箱子

结构体不可以嵌套定义

基本结构：

Struct  st_s

{

         char      a;

         int       b;

         float     c;    

};

两种存储数据方法：（在此之前，不分配存储空间给成员）

Struct st_s   stu = {“zhang”, male, 90};

Struct st_s   stu = {.a=“zhang”, .b=male, .c=90};

内存空间： 开辟空间很大，足以单独存储所有成员所占空间

可与typedef结合使用，定义一种新的数据类型（不展开，之前有过typedef的题目总结）

Typedef  struct   st_s

{

   ...........

}st_t;

其中，struct  st_s  等价于（==） st_t


例子：

#include <stdio.h>

typedef struct a_s

{

    int         a;

    short       b;

    char        c;

}a_t;

typedef struct b_s

{

    short       b;

    int         a;

    char        c;

}b_t;

int main(int argc, char **argv)

{

    printf("size a_t :%d\n", sizeof(a_t));

    printf("size b_t :%d\n", sizeof(b_t));

    return 0;

}

结构体和联合两者的区别总结：

结构体：各成员各自拥有自己的内存，各自使用互不干涉，同时存在的，遵循内存对齐原则。一个struct变量的总长度等于所有成员的长度之和。

联合（覆盖）： 各成员共用一块内存空间，并且同时只有一个成员可以得到这块内存的使用权(对该内存的读写)，各变量共用一个内存首地址。因而，联合体比结构体更节约内存。一个union变量的总长度至少能容纳最大的成员变量，而且要满足是所有成员变量类型大小的整数倍。




typedef和define有什么区别

ypedef和define都是替一个对象取一个别名，以此增强程序的可读性，区别如下：

（1）原理不同

#define是C语言中定义的语法，是预处理指令，在预处理时进行简单而机械的字符串替换，不作正确性检查，只有在编译已被展开的源程序时才会发现可能的错误并报错。

typedef是关键字，在编译时处理，有类型检查功能。它在自己的作用域内给一个已经存在的类型一个别名，但不能在一个函数定义里面使用typedef。用typedef定义数组、指针、结构等类型会带来很大的方便，不仅使程序书写简单，也使意义明确，增强可读性。

（2）功能不同

typedef用来定义类型的别名，起到类型易于记忆的功能。另一个功能是定义机器无关的类型。如定义一个REAL的浮点类型，在目标机器上它可以获得最高的精度：typedef long double REAL， 在不支持long double的机器上，看起来是这样的，typedef double REAL，在不支持double的机器上，是这样的，typedef float REAL

#define不只是可以为类型取别名，还可以定义常量、变量、编译开关等。

（3）作用域不同

#define没有作用域的限制，只要是之前预定义过的宏，在以后的程序中都可以使用，而typedef有自己的作用域。

#define没有作用域的限制，只要是之前预定义过的宏，在以后的程序中都可以使用。
而typedef有自己的作用域。

void   fun()   
  {   
      #define   A   int   
  }   
    
  void   gun()   
  {   
        //在这里也可以使用A，因为宏替换没有作用域，   
        //但如果上面用的是typedef，那这里就不能用A  ，不过一般不在函数内使用typedef
  }
  4.对指针的操作不同
#define INTPTR1 int*

typedef int* INTPTR2;

INTPTR1 p1, p2;

INTPTR2 p3, p4;

声明一个指针变量p1和一个整型变量p2
声明两个指针变量p3、p4

#define INTPTR1 int*

typedef int* INTPTR2;

int a = 1;

int b = 2;

int c = 3;

const INTPTR1 p1 = &a;

const INTPTR2 p2 = &b;

INTPTR2 const p3 = &c;


const INTPTR1 p1是一个常量指针，即不可以通过p1去修改p1指向的内容，但是p1可以指向其他内容。

const INTPTR2 p2是一个指针常量，不可使p2再指向其他内容。因为INTPTR2表示一个指针类型，因此用const限定，表示封锁了这个指针类型。

INTPTR2 const p3是一个指针常量



算法特征：确定性，有穷性/有限性，输入，输出，可行性

数组指针和指针数组
数组指针 int（*）p[n]本质上是指针，p是指针 指向长度为n的数组  *p在前

指针数组 int* p[n]本质上是数组，里面的数据类型是指针


（x=4*5,x*5）,x+25
最后等于几
答案45 因为,优先级  括号内部等于20,20+25
逗号表达式，是c语言中的逗号运算符，优先级别最低，它将两个及其以上的式子联接起来，从左往右逐个计算表达式，整个表达式的值为最后一个表达式的值     

构造函数可以是内联函数，构造函数可以没有参数

字符串处理函数
strcpy  是字符串赋值
strcmp是字符串比较

malloc函数进行动态，静态内存分配是在什么阶段 转载阶段和执行阶段



