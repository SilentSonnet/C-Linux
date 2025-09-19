# C-Linux学习笔记

吕聪 2025年3月2日08:37:24

## 一、基本概念

## C语言背景知识

C语言发展史:
	1960   原型A语言->ALGOL语言
	1963   CPL语言
	1967   BCPL语言
	1970   B语言
	1973   C语言

C语言特点:
	1、基础性语言
	2、语法简洁，紧凑，方便，灵活
	3、运算符，数据结构丰富
	4、结构化，模块化编程思想
	5、移植性好，执行效率高
	6、允许直接对硬件操作(最重要的特性）

C语言学习建议:
	1、概念的正确性
	2、动手能力，能够耐得住寂寞，没有程序员是培训出来的
	3、阅读优秀的程序段
	4、大量练习、面试题

C语言课程讲解思路:
	1、基本概念
	2、数据类型，运算符和表达式是如何生成的
	3、输入输出专题
	4、流程控制
	5、数组
	6、指针
	7、函数
	8、构造类型
	9、动态内存管理
	10、调试工具和调试技巧(GDB,make) GDB主要是用来已经明确了错误的位置，然后进行调试的时候，效率很高 
	11、常用库函数
	

### 平台介绍

​	B站老师所用的平台：64位的redhat6,vim,gccc(make)。
​	个人平台：使用Win11和WSL2作为学习平台。

### 用GCC编译Hello World

​	一个hello.c编译为可执行文件的全过程为：

```
.c源文件 -> 预处理 -> 编译 -> 汇编 -> 链接 -> 可执行文件
```

​	编译时使用的编译器就是gcc，一般情况下并不会直接使用gcc，但gcc有一个比较常用的点在于可以直接打印出当前出错的行号。

```c
gcc -E hello.c
```
​	所有带有#的都是在预处理阶段处理掉的 比如说#include ，#define等等，因此可以看到预处理之后，gcc就将头文件给包含了进来。因为shell命令是默认输出到终端的，但生成的文件还需要进行下一步的编译操作，因此就需要将输出重定向到一个新的.i文件中去，所使用的命令如下所示。

```c
gcc -E hello.c > hello.i
```
​	然后就会生成一个新的hello.i文件。
```c
gcc -S hello.i 
```
​	这一条命令不需要指定重定向的文件名字，gcc会自动创建一个新的hello.s文件，这就是一个汇编文件，最后执行汇编操作。
```c
gcc -c hello.s 
```
​	就可以得到最后的可执行文件，可能教程中的gcc编译器的版本较早，当前的gcc编译器版本需要指定生成的.o文件才行。
```c
gcc -c hello.s -o hello.o
```
​	这样才会生成.o的目标文件，最后再进行链接操作就可以生成可执行文件。
```c
gcc hello.o -o hello
```
​	然后就可以在目录中看到一个绿色的可执行文件了，使用 ./hello 就可以执行当前目录下的hello可执行文件，当然并不是每次都需要这样进行操作的，懒狗的方式就是直接：
```c
gcc hello.c 
```
​	运行这条命令的时候，gcc会默认将刚才的流程全部走一遍，在运行的过程中并没有任何步骤上的优化，并且在运行之后会默认生成一个a.out的文件。当然也可以指定可执行文件的文件名是什么。

```c
gcc hello.c -o myhello
```
这条命令相当于直接执行的刚才所有操作中的最后一步。
```c
gcc hello.c -Wall
```
​	这个选项的意思就是 all warnings ，这一条命令的作用就是输出所有的错误也就是warning，warning的含义就是这个显示的东西并不影响程序的运行，或者说是可执行文件的生成。但是gcc说话比较圆滑，所以说存在两种情况，一种就是gcc显示的错误就是单纯的错误，另一种就是真正的error了。程序在编译的过程中除非是你能够明确地知道并能够解释出这个警告出现的具体的原因，并且知道这个警告对程序的运行并没有什么影响，在这种情况下才可以不去管它，否则的话最好是把程序调试到没有任何警告为止。
​	比如说定义了一个int i变量但是没有使用，这种警告就是没有影响的警告，因为一个进程在运行的时候就已经会占用非常多的内存空间了，当然了说完全没有影响也不对，只能说这是一个几乎可以忽略不计的警告，但最好还是一个警告都不要出现，可能会有未定义的行为出现。
​	在找不到函数原型的情况下，编译器会默认把函数的返回值当作是 int 整形，所以没有包括头文件的时候就有可能出现函数的返回值不匹配的这种警告的出现，这就是最底层的原理，在IDE环境下编程的时候，IDE或许会直接提示我们没有包含某一个库，但上面所说的调试技巧是在无法安装IDE的终端产生的有限提示，因此这是有必要进行学习的。	 

### main函数的多种写法

​	C语言一开始的时候就没有void类型，所以当时的编译器就认为main函数返回的是int类型，但是后来增加了void类型之后，就认为main函数是特殊的，因为main函数作为进程的入口、出口、程序是不需要返回值的，其中的argc、argv是命令行的参数，所以如果不需要命令行传入参数的话，就将参数写成void，具体怎么样要看代码的运行环境。

```c
	void main(void)
	void main(int argc, char **argv) // 其中argv也可以写作 char *argv[]
	int main(int argc, char **argv);
	int main(void);
```
### make:

​	make相比于gcc的好处在于不会出现文件覆盖，比如说使用gcc用Tab自动补全的时候，gcc hello.c -o hello.c的时候源文件就会被直接覆盖掉，但是make后面直接跟的就是一个target目标文件，然后make会根据这个目标文件的名字去找相应的后缀是.c的源文件，然后自动调用cc hello.c -o hello 这样的一条命令，所以这个时候再使用自动补全的话，也不会出现源文件被覆盖的情况，因为这个时候相当于make去找的是hello.c.c这样的一个源文件，所以并不能找到这样的一个源文件，因此命令也就不会被执行了。
​	cc 是编译器的参数 默认是gcc

### vim:

​	vim的配置文件和常用的快捷方式。
​	一定要有意识地去使用vi和vim的快捷方式，但是不要刻意去记忆，在使用过程中继续记忆。
​	vim的配置文件在vimrc中 /etc/vimrc 中
​	最好的是将vimrc拷贝到家目录中

```bash
cp /etc/vimrc ~/.vimrc
```

​	etc目录下的vimrc是针对所有的用户有效，而家目录里面的文件是只对自己有效，并且设置成隐藏的就不会误操作了。代码对其的操作就是，先用ESC退出编辑模式，然后按下V进入可视化模式，选择代码之后按下等号就会自动对齐了。
​	因为vimrc是在vim启动的时候运行的，所以重新启动vimrc即可重新导入新的配置,使用vim进行补全的操作就是用ctrl+P即可，然后如果想看某一个函数的手册的话，将光标放在想要查找的函数名字上面之后shift+K即可直接跳转到这个函数的man手册中，然后想要回到vim界面的话，就直接按两下Q键即可，非常方便。



### 怎么写好代码

以helloworld程序为例对写程序的思路提出如下要求:
	1）头文件包含的重要性
	在c中，如果没有出现函数原型，就默认函数的返回值是int

```c
#include <stdio.h>

int main()
{
<<<<<<< HEAD
    int *num = malloc(sizeof(int));
    *num = 100;

    printf("%d\n",*num);
=======

    int *num = (int *)malloc(sizeof(int));

>>>>>>> d8201497ccb6ce60411ef4f1d6347921a54e7c22
>>>>>>> return 0;
>>>>>>> }
```

```c
hello.c: 在函数‘main’中:
hello.c:5:23: 警告：隐式声明函数‘malloc’ [-Wimplicit-function-declaration]
    5 |     int *num = (int *)malloc(sizeof(int));
          |                       ^~~~~~
          hello.c:5:23: 警告：隐式声明与内建函数‘malloc’不兼容
```

- 正确写法

```c
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int *num = (int *)malloc(sizeof(int));
    return 0;
}
```

​	2）以函数为单位来进行程序的编写
​	涉及到多线程的内容时，其实main()就是线程的入口，比如说要写一个能够加减乘除的功能，如果说是都写在一个函数里面的话，在以后调用的时候会产生不必要的系统开销，但是携程加减乘除四个小的函数的话，就能够增加函数的复用性，减小了未来的工作量。至于说为什么要将函数打散或者是聚合在一起，还是看未来是否会调用这个功能或者说是函数，如果这么一段的代码在有可能需要调用的话，最好还是写开，但如果未来在编程的时候不太可能会用得到的话，将函数的代码都写在一起也能够增加代码的可维护性。	
​	3）声明部分+实现部分
​	在程序前方，头文件和函数的真正具体实现部分中间就是整个程序的声明部分，而在一个函数的上方就是一个函数的声明部分。
​	4)return 0和exit(0)的区别
​	return 0的意思是结束当前函数，而exit(0)的意思是结束当前进程，一般情况下来说，在单线程单进程中这两者几乎是没有什么区别的，需要注意的是return 0返回的是父进程也就是给父进程看的，不能说给Shell看的，在当前所学习的内容中，这个父进程就是Shell，并非完全是课本上面所说的操作系统，但并非所有程序的父进程都是Shell，这一点需要注意。具体的使用的话，可以用 echo $? 这个命令，它输出的是上一条命令的执行状态，如果 return 0 成功运行的话，那么很显然在终端上出现的就是 0 ,这个和Shell脚本的真假刚好是对立的，所以在这一点需要注意。其次需要注意的就是，假如说 hello.c 没有return 0 的语句的话，这个程序并不是会默认返回 0 的， 正常情况下返回为 0 ，然后在出错的情况下返回为非零值，这个只是程序员约定俗成的一个观念，并不是实际的情况，就这个程序本身而言，假如说没有return 语句的话，那么返回的应该是13，因为算上字母 空格 和换行符一共有13个，这个就是printf的返回值。
​	5）适当地多用空格和空行
​	6）适当地在程序中多用注释
​	如果是注释掉函数的话，可以用#if 0 然后 在函数的末尾 #endif 这样的形式注释掉函数，会显得更加专业一点。
2.算法：解决问题的方法。
​	方法是不需要考虑成本和开销的，只是去思考问题解决的步骤。
​	（流程图，NS图，有限状态机-FSM）
3.程序：用某种语言实现算法
4.进程：一个程序开始运行的时候叫做进程
5.防止写越界，防止内存泄漏，谁打开谁关闭，谁申请谁释放。如果能够做到这几点就是很好的程序员了。


## 二、数据类型 运算符 表达式

- 基本类型
  - 数值类型
    - 整形
      - 短整型 short 
      - 整型 int
      - 长整型 long
    - 浮点型
      - 单精度型 float
      - 双精度型 double
  - 字符类型
    - 字符类型 char
- 构造类型
  - 数组 (和很多初学者想的不一样，数组其实就已经是构造类型了)
  - 结构体 struct
  - 共用体 union
  - 枚举类型 enum
- 指针类型
- 空类型 void (经典C中并没有void类型，是后来的标准中加入的)

​	需要注意的是，数据类型所占字节数随机器硬件不同而不同，本人所使用的系统基本数据类型的具体定义如下，在 **Ubuntu 20.04 (64位)** 下，C语言的基本数据类型的范围通常遵循 **LP64** 模型，也就是：

|   数据类型    | 字节数（sizeof） |                             范围                             |
| :-----------: | :--------------: | :----------------------------------------------------------: |
|    char    |      1 byte      |           -128 到 127（有符号）0 到 255（无符号）            |
|    short    |     2 bytes      |       -32,768 到 32,767（有符号）0 到 65,535（无符号）       |
|     int     |     4 bytes      | -2,147,483,648 到 2,147,483,647（有符号）0 到 4,294,967,295（无符号） |
|    long     |     8 bytes      | -9,223,372,036,854,775,808 到 9,223,372,036,854,775,807（有符号）0 到 18,446,744,073,709,551,615（无符号） |
|  long long  |     8 bytes      |               同 `long`（在 LP64 架构下相同）                |
|    float    |     4 bytes      |           约 ±3.4E-38 到 ±3.4E+38，6~7 位有效数字            |
|   double    |     8 bytes      |         约 ±1.7E-308 到 ±1.7E+308，15~16 位有效数字          |
| long double | 16 bytes（通常） |        约 ±3.4E-4932 到 ±1.1E+4932，18~19 位有效数字         |



对于数据类型需要思考的问题：
	1）所占字节数
	2）存储区别
	3）不同类型的数据间如何进行转换
	4）特殊性：布尔类型bool，这个代表一个逻辑值，逻辑真和逻辑假。float类型，本质上就是一个数值范围，因为就像一个只有厘米刻度的尺子要取到1.5cm的话就非常容易取到1.5000001或者1.499999这样的数据，这就是浮点数的精确度的一个问题，本质上来源于2进制对于小数的模拟只是一个近似，因为在小数点后都是2的幂运算。char类型的符号是未定义的行为。不同形式的0值：0，‘0’，“0”，‘\0'。数据类型与后续代码中所使用的输入输出要相匹配，比如说定一个一系列的无符号数做一些的图像处理，但是后边IO的时候忘记掉了，printf的时候使用了%d这样的一个有符号数来打印无符号数就会导致数据截半变成负数。

在标准C中对于任何一种数据类型所占的字节大小或者叫所占的位数，都没有严格意义上的规定，标准C中只规定int类型所占字长为一个机器字长，而short int类型要小于等于int类型，long int类型要大于等于int类型，char类型要小于int类型，float类型和double类型要大于int类型，仅仅是一个范围上的规定。实型数据其实也有正负之分，只不过这种正负之分体现在定义上。在C语言程序中不能识别二进制，八进制、十进制、十六进制都可以识别。

​	正数的补码就是其二进制码本身，负数的补码就是它的绝对值的二进制码取反再加一，二进制的获取就是除2取余倒序排列。

基本的进制转换

```C
254 -> unsigned int -> 32bit -> 4byte
    -> int -> 32bit
// 整形数的本身都是通过补码来进行存储的
-254 -> 254 -> 1111 1110 取反 + 1
// unsigned int 和 int的区别就是最高位代表的是符号位还是正常的有效数值，如果是无符号数的话最高位是零还是一并不代表符号，如果是有符号数为0的时候代表的是正数，为1的时候代表的是负数。
// 转化为八进制就可以3个一组，转化为16进制就可以4个一组
(254)10 = (1111 1110)2 = (376)8 = (FE)16

// 写成这种写法什么都不带就是十进制形式
254
// 二进制可以写在程序里面但是不能赋值给变量
B11111110(c不认识这个表示)
// 0开头就是八进制
0376
// 0x开头就是十六进制
0xFE
    
// float浮点类型的表示方式，只需要在意精度和指数部分是多少，double比float多出来的32为都是放在了精度部分，因此能够表示的数据范围更大。
3.14
0.314 * 10^1
```



![image-20250401091356196](images/image-20250401091356196.png)



ASII码表

| 十进制 | 十六进制  | 字符 | 控制符 | 描述         |
| ------ | --------- | ---- | ------ | ------------ |
| 0      | 0x00      | NUL  | NUL    | 空字符       |
| 1      | 0x01      | SOH  | SOH    | 标题开始     |
| 2      | 0x02      | STX  | STX    | 正文开始     |
| 3      | 0x03      | ETX  | ETX    | 正文结束     |
| 4      | 0x04      | EOT  | EOT    | 传输结束     |
| 5      | 0x05      | ENQ  | ENQ    | 询问         |
| 6      | 0x06      | ACK  | ACK    | 确认         |
| 7      | 0x07      | BEL  | BEL    | 响铃         |
| 8      | 0x08      | BS   | BS     | 退格         |
| 9      | 0x09      | TAB  | HT     | 水平制表符   |
| 10     | 0x0A      | LF   | NL     | 换行         |
| 11     | 0x0B      | VT   | VT     | 垂直制表符   |
| 12     | 0x0C      | FF   | NP     | 换页         |
| 13     | 0x0D      | CR   | CR     | 回车         |
| 14     | 0x0E      | SO   | SO     | 移出         |
| 15     | 0x0F      | SI   | SI     | 移入         |
| 16     | 0x10      | DLE  | DLE    | 数据链路转义 |
| 17     | 0x11      | DC1  | XON    | 设备控制1    |
| 18     | 0x12      | DC2  | XOFF   | 设备控制2    |
| 19     | 0x13      | DC3  | DC3    | 设备控制3    |
| 20     | 0x14      | DC4  | DC4    | 设备控制4    |
| 21     | 0x15      | NAK  | NAK    | 否定确认     |
| 22     | 0x16      | SYN  | SYN    | 同步空闲     |
| 23     | 0x17      | ETB  | ETB    | 块结束       |
| 24     | 0x18      | CAN  | CAN    | 取消         |
| 25     | 0x19      | EM   | EM     | 媒介结束     |
| 26     | 0x1A      | SUB  | SUB    | 替换         |
| 27     | 0x1B      | ESC  | ESC    | 转义         |
| 28     | 0x1C      | FS   | FS     | 文件分隔符   |
| 29     | 0x1D      | GS   | GS     | 群组分隔符   |
| 30     | 0x1E      | RS   | RS     | 记录分隔符   |
| 31     | 0x1F      | US   | US     | 单元分隔符   |
| 32     | 0x20      | 空格 |        | 空格         |
| 33     | 0x21      | !    |        | 感叹号       |
| 34     | 0x22      | "    |        | 双引号       |
| 35     | 0x23      | #    |        | 井号         |
| 36     | 0x24      | $    |        | 美元符号     |
| 37     | 0x25      | %    |        | 百分号       |
| 38     | 0x26      | &    |        | 与符号       |
| 39     | 0x27      | '    |        | 单引号       |
| 40     | 0x28      | (    |        | 左括号       |
| 41     | 0x29      | )    |        | 右括号       |
| 42     | 0x2A      | *    |        | 星号         |
| 43     | 0x2B      | +    |        | 加号         |
| 44     | 0x2C      | ,    |        | 逗号         |
| 45     | 0x2D      | -    |        | 减号         |
| 46     | 0x2E      | .    |        | 句点         |
| 47     | 0x2F      | /    |        | 斜杠         |
| 48-57  | 0x30-0x39 | 0-9  |        | 数字 0 到 9  |
| 58     | 0x3A      | :    |        | 冒号         |
| 59     | 0x3B      | ;    |        | 分号         |
| 60     | 0x3C      | <    |        | 小于号       |
| 61     | 0x3D      | =    |        | 等号         |
| 62     | 0x3E      | >    |        | 大于号       |
| 63     | 0x3F      | ?    |        | 问号         |
| 64     | 0x40      | @    |        | ＠符号       |
| 65-90  | 0x41-0x5A | A-Z  |        | 大写字母     |
| 91     | 0x5B      | [    |        | 左方括号     |
| 92     | 0x5C      | \    |        | 反斜杠       |
| 93     | 0x5D      | ]    |        | 右方括号     |
| 94     | 0x5E      | ^    |        | 脱字符       |
| 95     | 0x5F      | _    |        | 下划线       |
| 96     | 0x60      | `    |        | 反引号       |
| 97-122 | 0x61-0x7A | a-z  |        | 小写字母     |
| 123    | 0x7B      | {    |        | 左大括号     |
| 124    | 0x7C      |      |        |              |
| 125    | 0x7D      | }    |        | 右大括号     |
| 126    | 0x7E      | ~    |        | 波浪号       |
| 127    | 0x7F      | DEL  | DEL    | 删除         |

char类型在C语言中的符号问题是未定义的行为。

需要记住几个特殊的，比如0，A，a的这几个。

类型转换

大的往小的转换就会造成精度丢失

隐式转换，显示转换

``` c
int i;
float f;
doubel d;
char ch;

ch + i -> i
f -d -> d

(ch + i) - (float -double) -> double
   int   -       double   这就是隐式转换
后边再讲强制类型转换符
```

#### bool

``` c
#incldue <stdio.h>
#include <stdlib.h>
#include <stdbool.h> // 布尔值的标准库

int main() {
  bool a = false;
  printf("a = %d\n", a);
  exit(0);
}
```

#### 浮点型的失真问题

``` c++
// flow类型没有办法直接界定0的这个范围，因此可以让这个数和零相减的绝对值小于一个很小的数字来判断是不是0，归根结底在于flow类型没有办法直接和一个数进行比较，因为没有办法和一个不准确的数字进行比较。
int func(float f) {
  if (f < 0) {
    return -1;
  } else if (fabs(f-0) <= 1e-6) {
    return 0;
  } else {
  return 1;
  }
}
```

####  char

**在iso c中 `char`有无符号是未定义行为**

#### 0

``` c++
0(整形) '0'(字符常量) "0"(字符串常量) '\0'(字符常量)
```

#### 输入输出

数据类型要和后续代码中所使用的输入输出要相匹配(小心自相矛盾)

``` c++
#include <stdlib.h>
#include <stdio.h>

int main() {
  unsigned int a;
  a = 1 << 31;
  printf("%d", a);
}

```

正确

``` c++
#include <stdlib.h>
#include <stdio.h>

int main() {
  unsigned int a;
  a = 1 << 31;
  printf("%ud", a);
}

```

### 常量与变量

#### 常量

在程序执行过程中值不会发生变化的量，数组名就是一个很典型的常量，当数组被定义之后GCC编译器就会

分类：整形常量、实型常量、字符常量、字符串常量、标识常量。

- 整形常量： 1，790,76,52
- 实型常量： 3.14，5.26
- 字符常量： 由单引号引起来的单个的字符或转义字符，'\t' '\n' '\0' '\015'(8进制) '\x7f' '\018'(错误的表示！！八进制数中没有8，f)
- 字符串常量：由双引号引起来的一个或多个的字符组成的序列， ""空串占一个字节，尾零 "a" "abXYZ" "abc\n\021\010"(a b c \n \021 \0 1 8)
- 标识常量 ：#define，直跟的是宏名，宏名后面的是宏体。宏定义是在预处理阶段用宏体完整替换宏名，并不做语法检查，因此也可以定义一个表达式。宏定义的一个很重要的作用就是批量管理使用到的常量。处理在程序的预处理阶段，占编译时间，一改全改，不检查语法，只是单纯的宏体与宏名之间的替换。
常量一定不会在赋值的左边。
##### 宏的用法

``` c++
// 使用gcc -E define.c > define.i可以查看
#include <stdlib.h>
#include <stdio.h>

#define PI 3.1415926
#define ADD 2+3 // 会出现优先级问题
// 正确写法
//#define ADD (2+3)
int main() {
  printf("%f\n", PI);
  printf("%d\n", ADD * ADD);
}

```

``` c++
# 6 "pi.c"
int main() {
  printf("%f\n", 3.1415926);
  printf("%d\n", 2+3 * 2+3);
}
```
```C++
#include <stdlib.h>
#include <stdio.h>
// 带参数的宏的使用
#define MAX(a,b) (a > b ? a : b)

int main()
{
	int i = 5, j = 3;
    // 较大的那个会自增两次
	printf("i = %D\tj = %d\n", i , j);
	printf("%d\n", MAX(i++, j++));
	printf("i = %D\tj = %d\n", i , j);
	
	exit(0);
}
```
带参数的宏和函数的区别在于是，#占用的是编译时间而函数占用的是程序运行时间，函数是要在调用的位置对当前的执行现场进行一个压栈保存，然后跳转到需要执行的函数入口地址去执行，会有一个压栈、去到别的地址执行，回来弹栈，恢复现场等过程，这些占用的是系统运行时间。那该怎么使用呢？相比于完成一样功能的函数来讲的话，宏定义的使用是非常危险的，但是非常节省程序的运行时间，如果能够节省非常多的时间就用宏，函数的话一般就是在应用层面，系统层面的开发的时候使用函数，因为对于应用层来说最主要的是性能但是在内核层面的情况下，最主要的是性能，内核能够提速1s的话，反应到用户层面的感受是不一样的。要求稳定用函数，要求效率和性能使用宏。
```C++
#include <stdlib.h>
#include <stdio.h>
// 带参数的宏的使用
#define MAX(a,b) (a > b ? a : b)

#if 0
int max(int a, int b)
{
	return a > b ? a : b; 
}
#endif

int main()
{
	int i = 5, j = 3;
    // 较大的那个会自增两次
	printf("i = %D\tj = %d\n", i , j);
	printf("%d\n", MAX(i++, j++));
	printf("i = %D\tj = %d\n", i , j);
	
	exit(0);
}
```
``` c++
// 解决自增两次的问题，创建两个变量在临时存储，这样就只会存储i++，这样的话i就是只会自增一次了，使用反斜线就可以在下一样书写表达式了。
#include <stdlib.h>
#include <stdio.h>
// 带参数的宏的使用
// #define MAX(a,b) (a > b ? a : b)
#define MAX(a,b) ({int A=a,B=b; ((A) > (B) ? (A) : (B));})

int main() {
  int a = 3, b = 5;
  printf("%d\n",MAX(a++, b++));
  printf("%d\n",MAX(a++, b++));
}

```

``` c++
#include <stdlib.h>
#include <stdio.h>
// 因为刚才的代码只能适用于int类型，因此就可以使用typeof()获取到a 的类型之后，就可以根据传入的数据的类型来定义新的变量了。
#define MAX(a,b) ({typeof(a) A=a,B=b; ((A) > (B) ? (A) : (B));})

int main() {
  int a = 3, b = 5;
  printf("%d\n",MAX(a++, b++));
  printf("%d\n",MAX(a++, b++));
}

```

在程序的预处理阶段，占编译时间，不占运行时间(没有函数调用的消耗)，但不检查语法(比较危险)

#### 变量

变量：用来保存一些特定内容，并且在程序执行过程中随时会发生变化的量。
定义：[存储类型] 数据类型 标识符 = 值
            TYPE     NAME  = VALUE

给某一个内存空间取的名字就是这个NAME，这个NAME本质上是对地址的抽象，就像是送快递只会送到什么街道，不会直接送到经纬度位置，但地名本质上就是对经纬度的一个抽象表达。

标识符：由字母，数字，下划线组成且不能以数字开头的一个标识序列。写标识符的时候尽量做到见名知意，
数据类型：基本数据类型+构造类型
值：注意匹配。
存储类型：涉及到的关键字auto static register extern(说明型)
前面没有指定存储类型就是因为没有指定的情况下默认就是auto类型。

- auto：默认，自动分配空间，自动回收空间，这个类型在栈上。

- register：建议型关键字，只是建议编译器把这个变量放到寄存器中，但是GCC不一定放进去。寄存器类型，寄存器运算很快因为其位于CPU中，相对于普通的寻址取数运算放回的操作，寄存器类型直接就是取CPU内部的数据，拉进了取数的距离。使用这个存储类型的时候需要满足条件，只能定义局部变量，不能定义全局变量，并且大小有限制，只能定义32位大小的数据类型，比如double就不可以。因为寄存器没有地址，所以一个register类型的变量无法打印出地址查看或使用。
- extern：说明型，说明我定义的变量不在这里，需要去其它的地方找，意味着不能改变被说明的量的值或类型，可以用来扩展外部变量的作用域
- static：静态型，自动初始化为0值或空值，并且static变量的值有继承性。另外常用来修饰一个变量或者函数(防止当前函数对外扩展，简单来说就是限制了全局变量的作用域仅在当前的文件中相当于变相提供接口来进行调用但是不直接展示这个函数，将函数隐藏了起来)。这个就是相当于申请了一段固定的内存地址，此后在程序运行的整个周期，该变量所对应的内存地址都不会被修改。静态变量和全局变量的区别仅在于作用域，可以认为static就是一个受限制的全局变量。
  变量的生命周期和作用范围
  - 全局变量和局部变量，全局变量的作用范围从变量定义开始到程序结束，局部变量的作用范围是从定义开始到块作用域结束。
  - 局部变量和局部变量
  - 参考表格，存储类型比较


### 变量存储类型

| 变量类型 | 局部变量          |  局部变量                  |         局部变量           |             外部变量       | 外部变量          |
|:--------:|:-----------------:|:------------------:|:------------------:|:------------------:|:-----------------:|
| 存储类别 | auto              | register           | 局部 static        | 外部 static        | 外部              |
| 存储方式 | 动态              | 动态               | 静态               | 静态               | 静态              |
| 存储位置 | 动态区            | 寄存器             | 静态存储区         | 静态存储区         | 静态存储区        |
| 生命周期 | 函数调用时开始至结束 | 函数调用时开始至结束 | 程序整个运行期间 | 程序整个运行期间 | 程序整个运行期间 |
| 作用域   | 定义变量的函数或复合语句内 | 定义变量的函数或复合语句内 | 定义变量的函数或复合语句内 | 本文件             | 其他文件          |
| 赋初值   |每次函数调用时|每次函数调用时|编译时赋初值，只赋一次|编译时赋初值，只赋一次|编译时赋初值，只赋一次|
| 未赋初值 | 不确定            | 不确定             | 自动赋初值0或空字符 |  自动赋初值0或空字符    | 自动赋初值0或空字符 |

---

### 补充说明：

- 局部变量默认为 `auto` 类型  
- `register` 类型变量个数有限，且不能为 `long`、`double`、`float` 类型  
- 局部 `static` 变量具有全局生命周期和局部可见性 
- 外部 `static` 变量具有可继承性，文件内可见性（不能被其他文件访问）  
- `extern` 不是变量定义，可扩展外部变量作用域  

``` c++
#include <stdlib.h>
#include <stdio.h>

void func() {
  static int x = 1;
  x++;
  printf("%p->%d\n", &x, x);
}

int main() {
  func();
  func();
  func();
}

2
3
4
```
作用域永远是内部的屏蔽外部的。
```C++
#include <stdio.h>
#include <stdlib.h>

int i = 100;
int main()
{
	int i = 3;
	{
		int i = 5;
		printf("%d", i);
	}
	printf("%d", i);
	
	exit(0)
}
```
当前模块对全局变量的修改会影响到其它模块对该变量的使用。
```C++
int i = 0;

void print_star(void)
{
	for(i = 0;i < 5;i ++)
		printf("*");
    printf("\n");
    // 自动匹配当前语句匹配的函数名
    printf("[%s]i = %d\n", __FUNCTION__, i);
}
int main()
{
	for(i = 0;i < 5;i ++)
		printf_star();
    printf("[%s]i = %d\n", __FUNCTION__, i);
    exit(0);
}
```


vim * -p
vim * -p 是一个使用Vim编辑器的命令，其中的*是一个通配符，代表当前目录下所有的文件。具体地说，命令vim * -p会打开当前目录下所有的文件，并将它们显示在Vim中的不同标签页上，这样你可以在这些文件之间轻松切换和编辑。
对函数修饰static就是限制了其只能在当前文件中被调用，在别的文件中就是不可见的，防止函数对外扩展。
``` c++
// main.c
#include <stdio.h>
#include <stdlib.h>

#include "proj.h"

int i = 10;

int main() 
{
  	printf("[%s]%d\n", __FUNCTION__, i);
	exit(0);
}
```
``` c++
// proj.c
#include <stdio.h>
#include <stdlib.h>

#include "proj.h"

extern int i; // 不定义 而是引用了其他地方的i，使用extern 的时候不能给变量赋初始值就是因为extern不能修改变量的值。甚至于使用extern的时候可以不说明变量的类型，这就是告诉编译器我要用到某一个变量，但是可读性就实在是太差了。
int func() 
{
  	printf("[%s]%d\n", __FUNCTION__, i);
    exit(0);
}
// 注意这里的主调函数call_func()要在被调函数func()之下。因为此时的func()只能在当前的文件中使用，而call_func()没有用static来进行修饰，所以能够被main.c进行调用，进而也就调用了func()，此时func()就相当于被隐藏了起来。
void call_func()
{
	func();
	exit(0);
}
```
``` c++
#ifndef PROJ_H__
#define PROJ_H__

static void func();

#endif
```
## 运算符和表达式

### 表达式

表达式和语句的区别，没有加分号的就是表达式，加了分号之后就称作其整体为语句。变量和运算符组成的内容就叫做表达式。
	运算符部分：

1. 每个运算符所需要的参与运算的操作数个数。
2. 结合性
3. 优先级
4. 运算符的特殊用法：%的左右两边必须都是整数。自增自减运算，运算符在前就先进行计算，再取变量值使用，变量在前就先取变量值使用，再进行计算。=和==，逻辑运算符的短路特性。
```C++
int i = 1;
i++ --> 表达式的值为1，i值为2 
++i --> 表达式的值为2，i值为2

int i = 1, j = 10, value;
value = i++ + ++j;// 结果是12

int i = 1, j = 10, value;
value = --i + j++;// 结果是10
```
5. 位运算的重要意义

### C 语言运算符分类

| 运算符类别   | 运算符                           |
| ------------ | -------------------------------- |
| 算术运算符   | `+` `-` `*` `/` `%` `++` `--`    |
| 关系运算符   | `<` `<=` `==` `>` `>=` `!=`      |
| 逻辑运算符   | `!` `&&` `||`                    |
| 位运算符     | `<<` `>>` `|` `&` `~` `^`            |
| 赋值运算符   | `=` 及其扩展（如 `+=`、`-=` 等） |
| 条件运算符   | `?:`                             |
| 逗号运算符   | `,`(逗号运算表达式的值就是最后一个表达式的值)        |
| 指针运算符   | `*` `&`                          |
| 求字节数     | `sizeof`                         |
| 强制类型转换 | `(类型)`                         |
| 分量运算符   | `.` `->`                         |
| 下标运算符   | `[]`                             |
| 其它         | `()`                             |

### 运算符优先级表（从高到低）

| 优先级 | 运算符                                | 结合性   |
| ------ | ------------------------------------- | -------- |
| 1      | `()` `[]` `.` `->`                    | 从左到右 |
| 2      | `!` `+`（正） `-`（负） `~` `++` `--` | 从右到左 |
| 3      | `*` `/` `%`                           | 从左到右 |
| 4      | `+` `-`                               | 从左到右 |
| 5      | `<<` `>>`                             | 从左到右 |
| 6      | `<` `<=` `>` `>=` `instanceof`        | 从左到右 |
| 7      | `==` `!=`                             | 从左到右 |
| 8      | `&`（按位与）                         | 从左到右 |
| 9      | `^`（按位异或）                       | 从左到右 |
| 10     | `|`（按位或）                         | 从左到右 |
| 11     | `&&`                                  | 从左到右 |
| 12     | `||`                                  | 从左到右 |
| 13     | `?:`                                  | 从右到左 |
| 14     | `= += -= *= /= %= &= |= ^= <<= >>=`   | 从右到左 |
### 逻辑运算符 真值表

#### `&&` 运算符（与运算符）

| op1 | op2 | op1 && op2 |
|-----|-----|-----------|
|  0  |  0  |     0     |
|  0  |  1  |     0     |
|  1  |  0  |     0     |
|  1  |  1  |     1     |

#### `||` 运算符（或运算符）

| op1 | op2 | op1  \|\|  op2 |
|-----|-----|-----------|
|  0  |  0  |     0     |
|  0  |  1  |     1     |
|  1  |  0  |     1     |
|  1  |  1  |     1     |

#### 逻辑运算符的短路性

``` c++
#include <stdio.h>
#include <stdlib.h>

int main() {
  int a = 1, b = 2, c = 3, d = 4;
  int m = 1, n = 1;
  // 当运算符的左边为假的时候，右边的语句是不会再进行计算的，所以此时的n值为1
  	(m = a > b) && (n = c > d);
	(m = a > b) || (n = c > d);
  
  	printf("m = %d\n n = %d\n", m, n); // m : 0 n : 1
    
    
    
    int a = 9;
    a -= a *= a += 3;//答案是0，记住是从右往左算的，这时重点
    a+= 3 -> 9
        a*=9->81
        a-=81=0
        
    op1 ? op2 : op3
	// 如果op1值为真就取op2的值，否则取op3的值
}
```

#### sizeof

sizeof不是一个函数，是一个运算符

``` c++
#include <stdio.h>
#include <stdlib.h>

int main() {
  printf("%lu, %lu, %lu, %lu, %lu, %lu, %lu\n",
         sizeof(int),sizeof(short), sizeof(long),
         sizeof(double), sizeof(float), sizeof(char), sizeof(void*));
}

4, 2, 8, 8, 4, 1, 8

```

#### 强制类型转换

强制类型转换的转换是一个中间过程，相当于其只是生成了一个中间变量进行赋值操作，然后再舍弃掉，并不会修改掉原来变量的值，本质上只是把一个值当作一个值来对待了，对原来的值并没有任何影响。

#### 位运算

- | 按位或
- & 按位与
- ^ 按位异或
- ~ 按位取反

> 需要掌握的操作

将操作数中的第n位置1 其他位不变 num = num | 1 << n;
将操作数中的第n位置0 其他位不变 num = num & ~(1<<n);
测试第n位: if(num & (1<<n))
从一个指定宽度的数中取出某几位：(result) = (num >> pos) & ((1 << len) - 1);

左移一位就是右补零，右移一位就是左边补零，左移右移就相当于乘二除以二的操作。

按位或的计算原则是统一为二者有一位为真就为真，如果两者都为假才为假。

异或是相同为零，不同为1
```C++
# 假设 a = 5 (0b0101), b = 3 (0b0011)

# 按位或 |
  0101
| 0011
---------
= 0111  -> 7

# 按位与 &
  0101
& 0011
---------
= 0001  -> 1

# 按位异或 ^
  0101
^ 0011
---------
= 0110  -> 6

# 按位取反 ~a
~ 0101
---------
= 1010 (在补码中为 -6)
      
# 将 num 的第 n 位（n = 1）设置为 1
# 原 num = 0100 (即 4)
# 1 << 1 = 0010
  0100
| 0010
---------
= 0110  -> 6

# 将 num 的第 n 位（n = 2）清零（设置为 0）
# 原 num = 0111 (即 7)
# ~(1 << 2) = ~0100 = 1011
  0111
& 1011
---------
= 0011  -> 3
```

## 三、输入输出

input & output --> I/O

IO分为标准IO和文件IO，输入输出是任何系统都非常重要的功能

基本函数介绍

1.格式化输入输出函数：scanf、printf

int printf (const char *format,  ...);一般而言是很少能见到使用char来进行传参的函数，因为其数据大小比较窄，所以一般都是使用int来进行传参的，包括getchar和puchar都是使用int来进行传参的。
format ：“%[修饰符] 格式字符” 参照图片

int scanf (const char *format,  ...); 省略的就是地址表项
format：抑制符*，抑制输入就相当于是吃掉多少内容，接收输入但是不赋给任何变量

%s的使用是很危险的，因为不知道存储空间的大小，scanf放在循环结构中要注意能否接收到正常有效的内容

还需要注意的就是字面量123等数值一定要使用变量传参，不然没有单位的数值没有意义，谁也不知道这是几进制的数据。是在需要使用的时候就是在后面加上L这样的修饰符，例如
5*1024*1024*1024
5*1024LL 后面加上LL
#define SEC_YEAR  （60LL*60LL*24LL*365LL）、

调试技巧
```C++
// 后面的两个宏能够显示所在的函数和行号
printf("[%s:%d]",__FUNCTION__,__LINE__);
```
函数名相同参数类型或者数量不同的叫做函数重载，这种是在CPP的环境中的叫法，在C语言的环境中就是变参函数来实现的。如何区别就是加多参数，报语法错误的话就是定参函数重载，如果只是隐含的警告就是变参函数。

修饰符是可以省略的，但是格式字符是不可以省略掉的

2.字符输入输出函数：getchar，putchar
3.字符串输入输出函数：gets(!)，puts

gets这个函数非常危险是因为它并不对缓冲区溢出做任何的检查，因此标准库不允许使用gets，转而使用fgets，但是这也是治标不治本的行为，fgets虽然更加安全了但是只能保证不会出错而不能保证获取到我们需要的字符串，有一个方言getline可以完整拿进来一个字符串，它使用动态内存来实现的，所以不管字符串有多大都可以实现字符串的读取，这个不是c89也不是c99。

- printf
- ![image-20250527113236602](images/image-20250527113236602.png)

![image-20250527114225198](images/image-20250527114225198.png)

#### 变长参数 

``` c++
int main() {
  int i = 123;
  printf("%4d\n", i);
  
  float f = 1.23455;
  printf("%.3f\n", f);
  
  char* s= "helloworld";
  printf("%10.5s\n", s);
}
```

#### 刷新缓冲区

现在用到的终端设备，默认是全缓冲模式，因为涉及到终端设备所以变成了行缓冲模式

printf是遇到\n或者缓冲区满了才自动刷新缓冲区的，所以说\n其实就是在强制刷新缓冲区，没有这个就会把before放在缓冲区中，要么等程序结束，要么等强制刷新函数，要么就是等缓冲区满了自动刷新。

`stdout` 默认是**全缓冲模式**，**但是**如果它连接的是“终端”（如控制台/屏幕），标准库会自动将它切换为**行缓冲模式**。

如果你把 `printf()` 输出到一个文件中，它是**全缓冲**；

如果你把 `printf()` 输出到终端，它就是**行缓冲**；

但如果你没写换行符 `\n`，行缓冲也不会触发输出！


``` c++
int main() {
  printf("[%s:%d] before while().", __FUNCTION__, __LINE__);
  while(1);
  printf("[%s:%d] after while().", __FUNCTION__, __LINE__);
}
```

流程是这样的：

1. `printf()` 把内容写入 `stdout` 缓冲区。
2. 由于没有 `\n`，**行缓冲没被触发**。
3. `while(1);` 死循环，程序**永远不会刷新缓冲区**。
4. 所以你**看不到输出**。

正确写法

``` c++
#include <stdlib.h>
#include <stdio.h>

int main() {
  printf("[%s:%d] before while().]\n", __FUNCTION__, __LINE__);
  // 或者
  //printf("[%s:%d] before while().", __FUNCTION__, __LINE__);
  //fflush(stdout); 
  while(1);
  printf("[%s:%d] after while().", __FUNCTION__, __LINE__);
}

```

- scanf

``` c++
int main() {
  int i;
    // 一般不会在scanf中输入什么提示符，因为你输入什么就要原样输入
    // 其次就是中间不要有分隔符，否则就会导致字符串被切断的现象发生
  scanf("%d", &i);
  printf("%d\n", i);
}
```

> scanf 在使用 `%s` 的时候要特别小心

``` c++
#include <stdio.h>
#include <stdlib.h>

int main() {
  char S[3];

  scanf("%s", S); // 如果输入 abcdef
  printf("%s", S); // 可能会出现段错误，不会报错但是会溢出，是一种典型的缓冲区溢出攻击
}

```

> scanf 在循环中使用的时候要特别小心

``` c++
// 当输入a的时候，a并不会匹配%d，因为a是一个char类型，就会重复使用输入缓冲区内容，也就是上一次输入的内容
// 因此将scanf放在循环中一定要对scanf进行返回值的校验
int main() 
{
  int ret = 0;
  int d = 0;
  
  while(1) 
  {
    ret = scanf("%d, d);
    if (ret == -1) 
    {
      perror("Error");
      break;
    }
    printf("&d\n", d);
  }
  exit(0);
}
```

> 处理换行连续输入的问题可以通过使用抑制符和getchar来吃掉换行符

``` c++
int main() {
  int i = 0;
  char c = 0;
  
  scanf("%d", &i);
  scanf("%*c%c", &c);
  // 或者
  //getchar();
  //scanf("%c", &c);
  printf("i = %d, c = %c", i, c);
}
```

输入输出部分练习题

一个水分子的质量大约是3.0e-23g，一夸脱水大约有950g，编写一程序，要求从终端输入水的夸脱数，然后显示这么多夸脱水中包含有大概多少水分子。

``` c++
#include <stdio.h>
#include <stdlib.h>

#define WEIGHT 3.0e-23
#define QUART 950

// 使用static来修饰就是禁止了water函数的外部扩展性。
static void water (void)
{
    float num;
    float sum;
    
    // 注意一定要加上换行符，否则程序会不正常运行
    printf("Please input for num:\n");
    scanf("%f", &num);
    // 报错
    if (num <= 0)
    {
        fprintf(stderr, "Input error!\n");
        exit(1);
    }
    
    // 注意这里其实是进行了一个隐式类型转换，QUART其实是一个整型常量
    sum = num * QUART / WEIGHT;
    // 因为数字会很大，可以来使用科学计数法来输出
    printf("total is %e\n", sum);
    
    // 如果遇到非常严格的编译器，可能会让你返回一个值
    return ;
}

int main()
{
    water();
    exit(0);
}
```

从终端输入三角形的三边长，求面积

s = 1/2 x (a+b+c)

area = sqrt(s x (s-a) x (s -b) x (s - c))

这个叫做海伦公式

给定三角形三边长 \(a\)、\(b\)、\(c\)，海伦公式先计算半周长：
$$
s = \frac{a+b+c}{2}
$$
然后三角形面积为：
$$
\text{area} = \sqrt{s(s-a)(s-b)(s-c)}
$$


``` c++
#include <stdio.h>
#include <stdlib.h>
// 使用sqrt的时候需要加上 -lm的链接参数
// 可以直接在makefile文件中加上 CFLAGS+=-lm，意思就是在命令行中直接加上-lm
// -lm 告诉链接器把 libm（math library）也一起链接进可执行文件。
#include <math.h>

static void area(void)
{
    // 可以给出的边长不是整数
	float a, b, c;
    float s, area;
    printf("Please input:");
    // 不在缓冲区中可以不对返回值进行校验。
    // 但是在循环中就需要校验返回值否则就会导致输入数据无法取出而导致死循环。
    scanf("%f%f%f",&a, &b, &c);
    // 对是否能构成三角形来进行判断，EINVAL是设定好的宏值
    if (a + b <= c || b + c <= a || a + c <= b)
    {
        fprintf(stderr, "EINVAL\n");
        exit(1);
    }
    
    // 输出就是零的原因就是1/2被转化为了0
    s = 1/2.0 * (a + b + c);
    area = sqrt(s * (s - a) * (s - b) * (s - c));
    
    printf("area = %f\n", area);
}

int main()
{
    area();
 	exit(0);   
}
```

从终端输入a,b,c的值，求方程的根

例如：求ax^2 + bx + c = 0,设bxb -4ac > 0
x1 = （-b+sqrt(bxb - 4ac)）/ 2a
x2 = （-b-sqrt(bxb - 4ac)）/ 2a

```c++
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

static void root()
{
	float a, b, c;
    float dis, p, q, x1, x2;
    printf("Please input:");
    scanf("%f%f%f",&a,&b,&c);
    // 比较长的公式最好不要一次性写出来，这样也不便于测试
    if(((b *b) - (4 * a * c)) <= 0)
    {
        fprintf(stderr, "EINVAL\n");
        exit(1);
    }
    dis = (b *b) - (4 * a * c);
    p = -b / 2 * a;
    q = sqrt(disc) / 2 * a;
    
    x1 = p + q;
    x2 = p - q;
    
    printf("x1 = %f\nx2 = %f\n", x1, x2);
    return ;
}

int main(void)
{
    root();
    
    // 正常返回的时候用
    exit(0);
}
```



# 流程控制

C语言的三大结构

顺序、选择、循环

NS图 流程图 linux下的工具有DIA，dia最强力的点在于可以使用文本语言进行保存

简单结构与复杂结构：区别在于一个程序的自然流程是什么，如果一个程序的自然流程是结构化的，它的结构就叫做简单结构，如果一个程序的自然流程是非结构化的，那么它就是复杂结构。自然流程就是人类天生的解决问题的流程就是自然流程，或者说就是能够使用顺序选择循环来实现的流程就是自然流程。

顺序：语句主句执行
选择：出现了一种以上的情况
循环：在某个条件成立的情况下，重复执行某个动作

关键字：
选择：**if、else、switch-case**
循环：**While、do-while、for、if-goto**
辅助控制：**continue、break**

详解：**if-else**
格式：**if（exp）cmd；** 或者 **if(exp) cmd1; else cmd2;**
if只与和它最近的else相匹配

```C++
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a = 9, b = 10;
    if(b ++ < a)
    {
        printf("1\n");
    }
    else
    {
        printf("0\n");
    }
    printf("a = %d, b = %d\n",a ,b);
    printf("%d\n",(++ b < a, ++a, b++));
    
    if(a == b)
        if(b == c)
            printf("a == b == c\n");
    // 这里需要注意的也就是else和最近的if匹配
    else
        printf("a != C\n");
    
    
    exit(0);
}
```

成绩分类函数,if-else 的使用实例 

```c++
#include <stdio.h>
#include <stdlib.h>

/*
* score [90-100] A
*		[80-90)	 B
*		[70-80)  C
*		[60-70)  D
*		[0-60)   E
*
*/
int main()
{
    int score;
    
    printf("Enter a score:[0,100]");
    scanf("%d", &score);
     

    if(score < 0 || score > 100)
    {
        fprintf(stderr, "Input error!\n");
        exit(1);
    }
    if(score >= 90)
        puts("A");
    else if(score >= 80)
        puts("B");
    else if(score >= 70)
        pus("C");
    else if(score >= 60)
        puts("D");
    else 
        puts("E");
#ifdef DEBUG
    if(90 <= score && score <= 100)
        puts("A");
    if(80 <= score && score < 90)
        puts("B");
    if(70 <= score && score < 80)
        puts("C");
    if(60 <= score && score < 70)
        puts("D");
    if(0 <= score && score < 60)
        puts("E");
#endif
    exit(0);
}

```

闰年判断依据：能被4整除但不能被100整除，或者能被400整除

```C++
#include <stdio.h>
#include <stdlib.h>

int main (void)
{
    int year;
    scanf("%d", &year);
    if(year < 0)
    {
        fprintf(stderr, "EINVAL");
        exit(1);
    }
    else if(((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
        printf("Yes.");
    else 
        printf("No.");
	exit(0);
}
```

详解Switch-case
语法格式：

```c++
switch(exp)
{
    case 常量表达式：
        // 如果没有break语句，switch就会继续向下执行
    	break；
   case 常量表达式：
    	break；
    ......
    default：
}
```

使用举例

```C++
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int score;
	
	printf("Please enter:\n");
	scanf("%d", &score);
	
	if(score < 0 || score > 100)
	{
		fprintf(stderr, "EINVAL\n");
		exit(1);
	}
    
// 正常情况下都是不会这样写的，会把人给累死的
#ifdef DEBUG
    switch(score)
    {
        case 100:
        case 99:
        case 98:
		...
        case 90:
            puts("A");
            break;
        case 89:
        case 88:
        ...
        case 80:
            puts("B");
        	break;    
        ...
    }
#endif
    // 聪明的写法就是取整
    switch(score / 10)
    {
        case 10:
        case 9:
            puts("A");
            break;
        case 8:
            puts("B");
            break;
        case 7:
            puts("C");
            break;
        case 6:
            puts("D");
            break;
    /*
        case 5:
        case 4:
        case 3:
        case 2:
        case 1:
        case 0:
            puts("E");
            break;
    */
        // 因为错误情况已经在最开始剔除掉了，所以最好的方法就是把不及格放在default中
        default:
            puts("E");
            break;
    }
	
	exit(0);
}
```

程序设计一定要注意意外情况报错

```C++
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // 如果程序只有两种情况，不能写成if-else两个判断的形式，一定要假设存在意外情况并报错
    if(1)
        cmd();
    else if(2) 
        cmd();
    else 
        // 对意外情况进行捕获并抛出
        error();
    
    // 程序只有两种情况的话，也一定要使用default兜底并且结束程序
    switch(op)
    {
        // 注意 case后面的是常量表达式。
        // 形如 case score / 10 > 9 :这种东西不对，这是一个关系表达式。
        case 1:
            ...;
        	break;
        case 2:
            ...;
            break;
        default:
            // 带下划线的exit函数相比不带的区别就是什么都不做，IO也不刷新，钩子函数也不调用。
            // 还有一种处理方式是给一个杀死进程的信号，然后就能在GDB中进行调试。
            // 这个是在进程相关的课程中进行讲解
            _exit(0);
            break;
    }
    exit(0);
}
```

字典函数

```C++
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int ch;
	ch = getchar();
    
    switch(ch)
    {
        case 'a':
        case 'A':
            printf("Ant:A small insect that lives in group.\n");
            break;
        case 'b':
        case 'B':
            printf("Butterfly:A flying insect with a long thin body.\n");
            break;
        case 'c':
        case 'C':
            printf("Cobra:A highly dangerous snake.\n");
            break;
        case 'd':
        case 'D':
            printf("Donkey:A animal with short legs and long ears.\n");
            break;
        default:
            printf("Input error!\n");
            break;
    }
}
```

详解循环：while do-while for if-goto

```c++
语法格式：
while：每次执行之前先判断表达式是否成立，最少的执行次数是零次
    // 当条件为真的时候，就执行循环体，如果条件不成立，一次也不执行
	while(exp)
		loop
    // 先执行一遍循环体，再判断条件是否为真，如果条件成立就继续执行循环体，
do-while:最少执行一次
		do
        {
            loop;
        }while(exp);
```

高斯计数

```c++
#include <stdio.h>
#include <stdlib.h>

#define LEFT 1
#define RIGHT 100

int main()
{
    int i;
    int sum;
    
    i = LEFT;
    
    while(i <= RIGHT)
    {
        sum += i;
        i ++;
    }
    printf("sum = %d\n", sum);
    
	exit(0);	
}
```

do while

```c++
#include <stdio.h>
#include <stdlib.h>

#define LEFT 1
#define RIGHT 100

int main()
{
    int i;
    int sum;
    
    i = LEFT;
	do
	{
		sum += i;
		i ++;
	}while(i <= RIGHT);
	
    printf("sum = %d\n", sum);
	exit(0);	
}
```

while 和 do-while的区别

```C++
#include <stdio.h>
#include <stdlib.h>

#define DEBUG
int main()
{
	int i, start, end = 10;
    // 需要进行初始化
    int sum = 0;
    
    printf("Please enter:");
    scanf("%d", &start);

#ifdef DEBUG
    while(start <= end)
    {
        sum += start;
        start ++;
    }
#else
    // do-while不管你的条件成立还是不成立，一定会执行一次
    // 这个的适用场景主要是必须在判断之前先执行一次的场景，比如说是先展示给用户菜单，再收集用户选项
    // 因为菜单是一定要给用户看到才能让用户进行选择的，所以一定要先执行一遍才行
    /*
    	do
    	{
    		menu();
    		scanf();
    		if()
    			do something;
    	}while();
    */
    do
    {
        sum += start;
        start ++;
    }while(start <= end);
#endif
    printf("start = %d\n", start);
    printf("sum = %d\n", sum);
    
    exit(0);
}
```

for循环语法：

```
// 执行逻辑是先执行exp1，再判断exp2是否成立，如果成立就执行循环体，然后执行exp3，再继续判断exp2
// 如果不成立就直接跳出循环，因此最少的循环次数也是零次
for(exp1;exp2;exp3)
	loop;
```

使用for循环来进行高斯求和

```C++
#include <stdio.h>
#include <stdlib.h>

#define LEFT 1
#define RIGHT 100
#define DEBUG

int main()
{
    int i, start, end = 10;
    int sum = 0;
#ifdef DEBUG
    for(i = LEFT; i <= RIGHT; i++)
    {
        sum += i;
    }
#else
    // for循环的三个表达式都是可以省略掉的，但是这两个分号是不能省略掉的
    // 其实这样for循环就会退化为一个普通的while循环
    for( ; ; )
    {
        sum += i;
        i ++;
        if(i > RIGHT)
            break;
    }
#endif
    printf("sum = %d\n", sum);
    
    exit(0);
}
```

if-goto构成的循环 这个可读性太差了
goto实现的本意是为了实现无条件跳转，能够跳转到任何指定的语句标识的位置

使用goto语句来实现

```C++
#include <stdio.h>
#include <stdlib.h>

#define LEFT 1
#define RIGHT 100
#define DEBUG

int main()
{
    int i, start, end = 10;
    int sum = 0;
    
    i = LEFT;
    // 知道怎么使用就行了，goto实现的是无条件的跳转，它会破坏结构化模块化的编程，且不能跨函数跳转。
    // 因为把标记符写到另一个函数里面的意思是，执行权交了过去但是现场没有切换过去。
    // 函数在进行正常调用的时候，原来的现场是需要入栈保存的。
    // 回到原来的位置也是会弹栈恢复的，使用goto就会跳过这一步骤。
loop:
    sum += i;
    i ++;
    
    if(i <= RIGHT)
        goto loop;
    printf("sum = %d\n", sum);
    
    exit(0);
}
```

goto语句不能进行跨函数的跳转其实是缺陷，也有实现的方式。类似于C++中的异常抛出和异常接收的机制，这个异常捕获的机制其实就是安全长距离跳转的一个机制（原来是这样）。
在 C 语言中，类似于 `goto` 的跨函数跳转通常指的是使用 **`longjmp`** 和 **`setjmp`** 函数。

这些函数是标准库中的一部分，定义在 `<setjmp.h>` 头文件中。它们可以用来实现从一个函数跳转到另一个函数的行为（通常用于错误处理或非线性控制流）。这种跳转并不遵循常规的程序执行流，而是通过保存和恢复程序的状态来实现。

```c++
// setjmphe longjmp
// setjmp用来保存程序的状态
// longjmp用来恢复到先前使用setjmp保存的状态，从而实现跳转
#include <stdio.h>
#include <setjmp.h>

jmp_buf buf;  // 声明一个 jmp_buf 类型的变量，用于保存程序的状态

void funcB() {
    printf("In funcB, before longjmp.\n");
    longjmp(buf, 1);  // 跳转回 setjmp 所在的地方，第二个参数可以用于区分不同的跳转
    printf("This will never be printed.\n");
}

void funcA() {
    if (setjmp(buf) == 0) {
        printf("In funcA, calling funcB.\n");
        funcB();
    } else {
        printf("Back in funcA after longjmp.\n");
    }
}

int main() {
    funcA();  // 调用 funcA
    return 0;
}
// 这种方式相对较少用，通常在异常处理、嵌套的错误恢复中见得较多。如果是常规的程序控制流，通常还是推荐使用更明确的结构，比如 if、while 或 switch 等。
```

死循环：操作系统本身就是死循环，嵌入式开发中经常会用到死循环

```
while(1);
for( ; ; );

ctrl + c可以杀死 死循环程序，这个本质上是发送了一个中断信号，来终止掉当前的进程
辅助控制的关键字
break; 跳出循环或者switch-case语句
continue; 跳过下面的语句，继续下一次循环，相当于跳出本层循环
```

没有简单的程序，只有头脑简单的程序员，代码量一定要积累

选择循环部分习题：
投资问题：A以每年10%的单利息投资了100美元，B以每年5%的符合利息投资了100美元。编写一程序，计算需要多少年B的投资总额才会超过A，并且显示出到那个时刻两个人的各自的资产总额。

```C++
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define EPSILON 1e-6  // 允许的误差范围

int main()
{
	float A = 100.0, B = 100.0;
    int year = 0;
    
    do
    {
        A += 10.0;
        B *= 1.1;
        year ++;
        // 这个地方是一个很重要的陷阱，就是浮点数之间不能进行大小间的比较
    }while(fabs(B - A) < EPSILON);
    printf("A = %.2f\tB = %.2f\n", A, B);
    printf("Year = %d\n", year);
	exit(0);
}
```

C语言中浮点数之间的大小比较：由于浮点数（`float`）的表示方式有限，直接比较两个浮点数是否相等可能会导致不准确的结果，因为float本质上只是数值的一个近似值，很可能两个1.0最末尾的数字是不相同的。为了更准确地比较浮点数，可以使用一个“容差”值，通常称为“epsilon”，它表示允许的误差范围。

以下是比较两个 `float` 类型的数值的常见方法：

```C++
#include <stdio.h>
#include <math.h>

#define EPSILON 1e-6  // 允许的误差范围

int compare_floats(float a, float b) {
    return fabs(a - b) < EPSILON;
}

int main() {
    float x = 3.141592;
    float y = 3.141593;
    
    if (compare_floats(x, y)) {
        printf("x and y are equal\n");
    } else {
        printf("x and y are not equal\n");
    }

    return 0;
}

```

从终端读入数据，直到输入0值为止，计算其中的偶数的个数及平均值和奇数的个数和及平均值

```C++
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // odd是奇数，even是偶数
    int ch, odd = 0, even = 0;
    while((ch = getchar()) != '0')
    {
        if(ch == ' ')
            continue;
        else if((ch - '0') % 2 == 0)
            even ++;
        else if((ch - '0') % 2 == 1)
            odd ++;
    }
    printf("ODD = %d\tEVEN = %d", odd, even);
    
    exit(0);
}
```

从终端上输入若干字符，对其中的元音字母进行统计

- **`getchar() != '0'`**：这里首先执行的是 `getchar() != '0'`，这个表达式会先计算 `getchar()` 的结果与字符 `'0'` 是否不相等。
  - `getchar()` 返回一个字符值，然后与字符 `'0'` 进行比较，得到的是布尔值 `true` 或 `false`，即 `1` 或 `0`。
  - 因为比较的结果是 `1` 或 `0`，所以这个结果会被赋值给 `ch`。
- **`(ch = getchar() != '0')`**：最终赋给 `ch` 的值并不是 `getchar()` 返回的字符，而是比较结果 `1` 或 `0`。这就导致了程序的逻辑错误。

这段代码的问题在于，`ch` 被赋予了布尔值 `1` 或 `0`，而不是字符，因此在后续的循环中，`ch` 的值可能并不符合预期。

```C++
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // 简单考虑，以零结尾的时候就停止
    int ch, count = 0;
    // 优先级出现的问题，最好的情况是
    while(((ch = getchar()) != '0'))
    {
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' )
            count ++;
        else if(ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U' )
            count ++;
    }
    printf("The sum is %d\n", count);
    
    exit(0);
}
```

写出fibonacci数列的前40项(不能用数组实现)

1 1 2 3 5 8 13 21

```c++
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int A = 1, B = 1, number = 0;
    for(int i = 1;i <= 40;i ++)
    {
        if(i == 1)
            printf("The %d  is %d\n", i, A);
        else if(i == 2)
            printf("The %d  is %d\n", i, B);
        else if(i > 2)
        {
            // 第二项之后就是前两项相加了
            number = A + B;
            A = B;
            B = number;
            printf("The %d  is %d\n", i, number);
        }
    }
    
    exit(0);
}
```

输出九九乘法表

```c++
#include <stdio.h>
#include <stdlib.h>

int main()
{
    for(int i = 1;i <= 9;i ++)
    {
        for(int j = 1;j <= i;j ++)
            printf("%4d x %4d = %4d\t", j, i, i * j);
        printf("\n");
    }
    
    exit(0);
}
```

视频课程中前面的题目没有，但我的程序都是久经考验的

百钱买百鸡：鸡翁一，值钱五；鸡母一，值钱三；三鸡雏，值钱一，百钱买百鸡，问鸡翁、鸡母、鸡雏各几何？

```C++
#include <stdio.h>
#include <stdlib.h>

#define SOLUTION_2

int main()
{
#ifdef SOLUTION_1
    // 解法一
	int i, j, k;
    // 不用纠结是小于还是小于等于20，因为如果是20的话一定不满足百鸡
    // 可以不买，所以最小值就是0
    for(i = 0;i <= 100 / 5;i ++)
        for(j = 0;j <= 33;j ++)
            for(k = 0;k <= 100;k ++)
                if((k % 3 == 0) && (5 * i + 3 * j + k/3 == 100))
                    if(i + j + k == 100)
                    	printf("鸡翁 = %d\t鸡母 = %d\t鸡雏 = %d\n", i, j, k);
#endif
#ifdef SOLUTION_2
    // 解法二的思路也就是将第三个的循环去掉了，因为百鸡的限定条件前两个算出来第三个也就算出来了
    int i, j, k;
    for(i = 0;i < 100 / 5;i ++)
    {
        for(j = 0;j < 33;j ++)
        {
            k = 100 - i - j;
            if((k % 3 == 0) && (5 * i + 3 * j + k/3 == 100))
                printf("鸡翁 = %d\t鸡母 = %d\t鸡雏 = %d\n", i, j, k);
        }
    }
#endif
    exit(0);
}
```

求出1000以内的水仙花数：个位的立方、十位的立方、百位的立方加起来等于它本身。 

```c++
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // 因为水仙花数它至少要是一个三位数，所以起始计算的位置应该是100，最大的三位数是999
    int number;
    for(number = 100;number <  1000;number ++)
    {
        int ones, tens, hundreds;
        ones = number % 10;
       	tens = (number / 10) % 10;
        hundreds = (number / 100) % 10;
        
        if(ones * ones * ones + tens * tens * tens + hundreds * hundreds * hundreds == number)
            printf("The number is %d\n", number);
        
    }
    exit(0);
}
```

求出1000以内的所有质数

```c++
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int prime = 0;
    for(int i = 1;i <= 1000;i ++)
    {
        // 这个地方的判断可以除以2或者是sqrt开方，具体的快慢要看浮点指令集的支持
        // 这里需要注意1既不是质数也不是合数
        for(int j = 2;j <= i;j ++)
        {
            if(i % j == 0)
            {
                if(j == 1)
                    continue;
                else if(j == i)
                    continue;
                else
                {
                    prime = 1;
                    break;
                }
            }
        }
        if(prime == 0)
        {
            printf("%d is prime number.\n", i);
        }
        else
        {
            prime = 0;
            continue;
        }
    }
    exit(0);
}
```

```c++
// 这个是老师的解法
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int prime = 0, mark;
    for(int i = 2;i < 1000;i ++)
    {
        mark = 1;
        for(int j = 2;j < i;j ++)
        {
        	if(i % j == 0)
            {
                mark = 0;
                break;
            }
        }
        if(mark)
            printf("%d is a prime.\n", i);
    }
    exit(0);
}
```

在终端上实现如下输出：
ABCDEF
BCDEF
CDEF
DEF
EF
F

```c++
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int ch = 'A';
    for(int i = 6, count = 0;i > 0;i --, count ++)
    {
        for(int j = 0;j < i;j ++)
            printf("%c", ch + j + count);
        printf("\n");
    }
    exit(0);
}
```

```C++
// 老师的解法
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int line = 6, chars = 6;
    int i;
    char ch;
    
    for(i = 0;i < line;i ++)
    {
        for(ch = 'A' + i;ch < 'A' + chars;ch ++)
        {
            printf("%c", ch);
        }
        printf("\n");
    }
}
```

包括钻石型

```
  *
 * *
* * *
 * *
  *
```

```c++
// 这一道题不会写，主要是没有明白这道题是要干什么的
#include <stdio.h>
#include <stdlib.h>

int main()
{
    for(int i;i <= 4;i ++)
    {
        for(int j = 1;j <= 4 - i;j ++)
            printf(" ");
        for(int k = 1;k <= 2 * i - 1;k ++)
            printf("*");
        printf("\n");
    }
    for(int i = 1;i <= 3;i ++)
    {
        for(int j = 1;j <= i;j ++)
            printf(" ");
        // 最多是7个，所以是7 - 2 * i
        for(int k = 1;k <= 7 - 2 * i;k ++)
            printf("*");
        printf("\n");
    }
    exit(0);
}
```

从终端输入N个数(以字母Q/q作为终止)，求和

```c++
// 这个函数只能处理中间有间隔的字符串的输入120 会识别为1,2,3而不是一百二十
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int ch, sum = 0;
	while(1)
    {
        ch = getchar();
        // 终止信号，直接跳出循环
        if((ch == 'Q') || (ch == 'q'))
        {
            break;
        }
        // 把空格给消除掉
        else if(ch == ' ')
            continue;
        else
            sum += (ch - '0');
    }
    printf("Sum = %d\n", sum);
    
    exit(0);
}
```

```C++
// 老师的答案
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num;
    int sum = 0;
    printf("Please enter the first integer(q to quit):\n");
    // 这里并不一定是q才能退出，只要scanf不成立就会退出，打a也会退出
    // 因为需要输入的是一个整形数字，字符就会不匹配，导致scanf返回失败
    // 大部分的数据其实并不会从终端一点点输入，大部分都是从文件、数据库或者其它的设备导入的
    // 养成良好的习惯，如果有输入就要有提示符或者menu、help来提示
    while(scanf("%d", &num) == 1)
    {
        sum += num;
        printf("Please enter the next integer(q to quit):\n");
    }
    printf("sum = %d\n", sum);
}
```

从半径为1开始，输出圆的面积，直到面积大于100为止

```c++
#include <stdio.h>
#include <stdlib.h>

#define PI 3.14
// 送分题
int main()
{
    float area = 0.0;
	for(int i = 1;(area = i * i *PI) < 100.0;i ++)
    {
        printf("Area = %.2f\n", area);   
    }
    exit(0);
}
```



# 数组

数组是构造类型的一种，本质是在内存中是连续存放的用来存放相同数据类型的一块空间，是为了解决批量使用变量时，命名和引用所产生的困难而被设计的。

## 一维数组

### 1.定义

[存储类型] 数据类型 标识符[下标] 
下标必须是整形的常量或者是常量表达式

```c++
#include <stdio.h>
#include <stdlib.h>

#define M 3

int main()
{
    int i;
    int arr_1[M]; // 定义数组的关键字是省略的，所以就是auto类型，不赋初值时不会清理内存空间
    int arr_2[i]; // 这个就是变长数组，因为i的值可以发生变化
    
    // 数组的大小就是数据类型 x 个数
    printf("%d\n", sizeof(arr_1));
    // 数组名就是数组的起始位置
    printf("arr = %p\n", arr_1);
    
    for(i = 0;i < M;i ++)
        scanf("%d", &arr_1[i]);
    
    // 通过打印地址来验证数组在内存中是连续存放的，其地址是连续的
    for(i = 0;i < M;i ++)
        printf("%p-->%d\n", &arr_1[i], arr_1[i]);
    
    
    exit(0);
}
```



### 2.初始化

- 不初始化
- 全部初始化
- 部分初始化

```c++
int a[3] = {1}; // 其余的元素会自动初始化为0
```



- static

``` c++
static int a[10]; // 即使没有初始化，也会全部赋值为0
```

- 等号后面加{}

``` c++
int a[3] = {1, 2, 3};
```

### 元素引用

数组名+下标 注意下标是从0开始计数的

- arr[i]
- arr+i

#### 数组名

一个**常量**（常量就是在程序执行过程中不会发生变化的量），代表的是当前数组的起始位置，数组名本身就是一个表示地址的一个常量

``` c++
#include <stdio.h>
#include <stdlib.h>

int main() 
{
    int arr[3] = {1, 2, 3};
    printf("%ld\n", sizeof(arr));
    // 下面这句是错的
    arr = {4, 5, 6};
    for (int i = 0;i < sizeof(arr)/sizeof(int);i++) 
    {
        printf("%d", *(arr+i));
    }
}
```





### 数组越界

C语言不对数组进行越界检查，需要格外小心
因为使用数组就相当于在使用指针

```C++
a[i] = *(a + i); // 数组偏移之所以会出现就是因为数组本质上是用指针实现的，而内存空间都是有地址的
```



### 练习

#### 1.求fibonacci数列的前10项，并在数组中逆序存放

``` c++
#include <stdio.h>
#include <stdlib.h>

int main() 
{
    int fib[10] = {1, 1};
    for (int i = 2;i < 10;i++) 
    {
        fib[i] = fib[i-1]+ fib[i-2];
    }
    for (int i = 0;i < 10;i++) 
    {
        printf("%d ", fib[i]);
    }
}

```

**逆序存放**

```C++
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i, j, tmp, fib[10] = {1, 1};
    
    for(i = 2;i < sizeof(fib) / sizeof(fib[0]);i ++)
        fib[i] = fib[i - 1] + fib[i - 2];
    for(i = 0;i < sizeof(fib) / sizeof(fib[0]);i ++)
        printf("%d ", fib[i]);
    printf("\n");
    
    i = 0;
    j = sizeof(fib) / sizeof(fib[0]) - 1;
    
    // 交换次序的写法很简单，就是首尾相连就可以了
    while(i < j)
    {
        tmp = fib[i];
        fib[i] = fib[j];
        fib[j] = tmp;
        
        i ++;
        j --;
    }
    for(i = 0;i < sizeof(fib) / sizeof(fib[0]);i ++)
        printf("%d ", fib[i]);
    printf("\n");
    
    exit(0);
}
```



#### 2.数据排序：冒泡排序、选择法排序、快速排序

#### 初始数组：

```
[5, 7, 6, 8, 9, 2, 1, 4, 3]
```

#### 冒泡排序过程：

1. **第一趟排序**：

   - 比较第一个和第二个元素，`5` 和 `7`，不交换。
   - 比较第二个和第三个元素，`7` 和 `6`，交换，数组变为 `[5, 6, 7, 8, 9, 2, 1, 4, 3]`。
   - 比较第三个和第四个元素，`7` 和 `8`，不交换。
   - 比较第四个和第五个元素，`8` 和 `9`，不交换。
   - 比较第五个和第六个元素，`9` 和 `2`，交换，数组变为 `[5, 6, 7, 8, 2, 9, 1, 4, 3]`。
   - 比较第六个和第七个元素，`9` 和 `1`，交换，数组变为 `[5, 6, 7, 8, 2, 1, 9, 4, 3]`。
   - 比较第七个和第八个元素，`9` 和 `4`，交换，数组变为 `[5, 6, 7, 8, 2, 1, 4, 9, 3]`。
   - 比较第八个和第九个元素，`9` 和 `3`，交换，数组变为 `[5, 6, 7, 8, 2, 1, 4, 3, 9]`。

   **第一趟结束后数组**：`[5, 6, 7, 8, 2, 1, 4, 3, 9]`
    9 被排到最后的位置。

2. **第二趟排序**：

   - 比较第一个和第二个元素，`5` 和 `6`，不交换。
   - 比较第二个和第三个元素，`6` 和 `7`，不交换。
   - 比较第三个和第四个元素，`7` 和 `8`，不交换。
   - 比较第四个和第五个元素，`8` 和 `2`，交换，数组变为 `[5, 6, 7, 2, 8, 1, 4, 3, 9]`。
   - 比较第五个和第六个元素，`8` 和 `1`，交换，数组变为 `[5, 6, 7, 2, 1, 8, 4, 3, 9]`。
   - 比较第六个和第七个元素，`8` 和 `4`，交换，数组变为 `[5, 6, 7, 2, 1, 4, 8, 3, 9]`。
   - 比较第七个和第八个元素，`8` 和 `3`，交换，数组变为 `[5, 6, 7, 2, 1, 4, 3, 8, 9]`。

   **第二趟结束后数组**：`[5, 6, 7, 2, 1, 4, 3, 8, 9]`
    8 被排到倒数第二的位置。

3. **第三趟排序**：

   - 比较第一个和第二个元素，`5` 和 `6`，不交换。
   - 比较第二个和第三个元素，`6` 和 `7`，不交换。
   - 比较第三个和第四个元素，`7` 和 `2`，交换，数组变为 `[5, 6, 2, 7, 1, 4, 3, 8, 9]`。
   - 比较第四个和第五个元素，`7` 和 `1`，交换，数组变为 `[5, 6, 2, 1, 7, 4, 3, 8, 9]`。
   - 比较第五个和第六个元素，`7` 和 `4`，交换，数组变为 `[5, 6, 2, 1, 4, 7, 3, 8, 9]`。
   - 比较第六个和第七个元素，`7` 和 `3`，交换，数组变为 `[5, 6, 2, 1, 4, 3, 7, 8, 9]`。

   **第三趟结束后数组**：`[5, 6, 2, 1, 4, 3, 7, 8, 9]`
    7 被排到倒数第三的位置。

4. **第四趟排序**：

   - 比较第一个和第二个元素，`5` 和 `6`，不交换。
   - 比较第二个和第三个元素，`6` 和 `2`，交换，数组变为 `[5, 2, 6, 1, 4, 3, 7, 8, 9]`。
   - 比较第三个和第四个元素，`6` 和 `1`，交换，数组变为 `[5, 2, 1, 6, 4, 3, 7, 8, 9]`。
   - 比较第四个和第五个元素，`6` 和 `4`，交换，数组变为 `[5, 2, 1, 4, 6, 3, 7, 8, 9]`。
   - 比较第五个和第六个元素，`6` 和 `3`，交换，数组变为 `[5, 2, 1, 4, 3, 6, 7, 8, 9]`。

   **第四趟结束后数组**：`[5, 2, 1, 4, 3, 6, 7, 8, 9]`
    6 被排到倒数第四的位置。

5. **第五趟排序**：

   - 比较第一个和第二个元素，`5` 和 `2`，交换，数组变为 `[2, 5, 1, 4, 3, 6, 7, 8, 9]`。
   - 比较第二个和第三个元素，`5` 和 `1`，交换，数组变为 `[2, 1, 5, 4, 3, 6, 7, 8, 9]`。
   - 比较第三个和第四个元素，`5` 和 `4`，交换，数组变为 `[2, 1, 4, 5, 3, 6, 7, 8, 9]`。
   - 比较第四个和第五个元素，`5` 和 `3`，交换，数组变为 `[2, 1, 4, 3, 5, 6, 7, 8, 9]`。

   **第五趟结束后数组**：`[2, 1, 4, 3, 5, 6, 7, 8, 9]`
    5 被排到倒数第五的位置。

6. **第六趟排序**：

   - 比较第一个和第二个元素，`2` 和 `1`，交换，数组变为 `[1, 2, 4, 3, 5, 6, 7, 8, 9]`。
   - 比较第二个和第三个元素，`2` 和 `4`，不交换。
   - 比较第三个和第四个元素，`4` 和 `3`，交换，数组变为 `[1, 2, 3, 4, 5, 6, 7, 8, 9]`。

   **第六趟结束后数组**：`[1, 2, 3, 4, 5, 6, 7, 8, 9]`
    4 被排到倒数第六的位置。

### 最终排序结果：

```
[1, 2, 3, 4, 5, 6, 7, 8, 9]
```

通过每一趟的比较和交换，较大的元素逐步向后移动，直到所有元素有序。


``` c++
// 老师的程序写的有点不清楚，特别是数组定义的有点不清晰。
// 学习还是先学概念，尽信书不如无书，老师教的也不一定是最好的
#include <stdio.h>
#include <stdlib.h>

int main() 
{ 
    int arr[] = {2, 3, 5, 4, 6, 7, 1, 9};
    
    printf("%d\n", sizeof(arr));
    printf("%d\n", sizeof(arr) / sizeof(arr[0]));
    
    for (int i = 0;i < sizeof(arr) / sizeof(int);i ++) 
    {
    	for (int j = 0;j < sizeof(arr) / sizeof(int) - 1 - i;j ++) 
    	{
            // 写程序的时候要明白这个是把大的放到了后面还是前面
            if(arr[j] > arr[j + 1]) 
            {
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
    	}
    }
    for (int i = 0;i < sizeof(arr) / sizeof(int);i ++) 
    {
        printf("%d ", arr[i]); 
    }
}

```



**选择排序**

选择排序（Selection Sort）是一种简单的排序算法，它的基本思想是：在未排序的部分中选出最小（或最大）元素，将其与未排序部分的第一个元素交换，直到所有元素都被排序。选择排序的最大特点是它只进行一趟交换，每次从剩余的未排序部分中选择最小值（或最大值），然后与当前排序区域的第一个元素交换位置。

### 选择排序的详细过程：

假设我们有一个数组 `[5, 7, 6, 8, 9, 2, 1, 4, 3]`。

1. **第一趟排序：**
   - 从整个数组中选择最小的元素（1）并将其与第一个元素（5）交换位置。
   - 数组变为 `[1, 7, 6, 8, 9, 2, 5, 4, 3]`。
2. **第二趟排序：**
   - 从未排序的部分 `[7, 6, 8, 9, 2, 5, 4, 3]` 中选择最小的元素（2）并将其与第二个元素（7）交换位置。
   - 数组变为 `[1, 2, 6, 8, 9, 7, 5, 4, 3]`。
3. **第三趟排序：**
   - 从未排序的部分 `[6, 8, 9, 7, 5, 4, 3]` 中选择最小的元素（3）并将其与第三个元素（6）交换位置。
   - 数组变为 `[1, 2, 3, 8, 9, 7, 5, 4, 6]`。
4. **第四趟排序：**
   - 从未排序的部分 `[8, 9, 7, 5, 4, 6]` 中选择最小的元素（4）并将其与第四个元素（8）交换位置。
   - 数组变为 `[1, 2, 3, 4, 9, 7, 5, 8, 6]`。
5. **第五趟排序：**
   - 从未排序的部分 `[9, 7, 5, 8, 6]` 中选择最小的元素（5）并将其与第五个元素（9）交换位置。
   - 数组变为 `[1, 2, 3, 4, 5, 7, 9, 8, 6]`。
6. **第六趟排序：**
   - 从未排序的部分 `[7, 9, 8, 6]` 中选择最小的元素（6）并将其与第六个元素（7）交换位置。
   - 数组变为 `[1, 2, 3, 4, 5, 6, 9, 8, 7]`。
7. **第七趟排序：**
   - 从未排序的部分 `[9, 8, 7]` 中选择最小的元素（7）并将其与第七个元素（9）交换位置。
   - 数组变为 `[1, 2, 3, 4, 5, 6, 7, 8, 9]`。
8. **第八趟排序：**
   - 从未排序的部分 `[8, 9]` 中选择最小的元素（8）并将其与第八个元素（8）交换位置（无需实际交换）。
   - 数组仍然是 `[1, 2, 3, 4, 5, 6, 7, 8, 9]`。
9. **第九趟排序：**
   - 剩下的最后一个元素已经是最小的，因此不需要做任何交换。

```C++
#include <stdio.h>
#include <stdlib.h>

int main() 
{
    int arr[] = {2, 3, 5, 4, 6, 7, 1, 9};
    
    for(int i = 0;i < sizeof(arr) / sizeof(arr[i]);i ++)
        printf("%d ", arr[i]);
    printf("\n");
    
    for (int i = 0; i < sizeof(arr) / sizeof(int); i ++) 
    {
        // 这个的意思是搜索到最小值放到a[i]这个位置，minIndex是用来索引当前最小的数字
        int minIndex = i;
        // 因为i是放最小数字的位置，那么就需要从i+1开始比较
        for (int j = i+1; j < sizeof(arr)/sizeof(int); j ++) 
        {
            if (arr[j] < arr[minIndex]) 
            {
                minIndex = j;
            }
        }
        // 交换最小值和当前位置的元素
        if (minIndex != i) 
        {
            int tmp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = tmp;
        }
    }
    for (int i = 0; i < sizeof(arr) / sizeof(int); i ++) 
    {
        printf("%d ", arr[i]); 
    }
}

```

**快速排序**

```C++
// 这个老师并没有讲，但是也贴在这里用于参考，快速排序也是非常重要的一种算法
#include <stdio.h>
#include <stdlib.h>

void quickSort(int arr[], int low, int high) 
{
    if (low < high) 
    {
        int pivot = arr[high];
        int i = low - 1;
        for (int j = low; j < high; j++) 
        {
            if (arr[j] < pivot) 
            {
                i++;
                int tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
        int tmp = arr[i + 1];
        arr[i + 1] = arr[high];
        arr[high] = tmp;

        int pivotIndex = i + 1;

        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

int main() 
{
    int arr[] = {2, 3, 5, 4, 6, 7, 1, 9};
    int size = sizeof(arr) / sizeof(int);
    quickSort(arr, 0, size - 1);
    for (int i = 0; i < size; i++) 
    {
        printf("%d ", arr[i]); 
    }
}

```

这个还是选择排序，不知道有什么区别

``` c++
#include <stdio.h>
#include <stdlib.h>

int main() 
{
    int arr[] = {3, 2, 5, 4, 9, 7, 1, 6};
    for (int i = 0;i < sizeof(arr)/sizeof(int);i++) 
    {
        int m = i;
        for (int j = i+1;j < sizeof(arr)/sizeof(int);j++) 
   	 	{
      		if(arr[j] < arr[m]) 
      		{
        		m = j;
      		}
        }
    	if (m != i) 
    	{
          int tmp = arr[i];
          arr[i] = arr[m];
          arr[m] = tmp;
    	}
    }
    for (int i = 0; i < sizeof(arr) / sizeof(int); i++) 
    {
    	printf("%d ", arr[i]);
    }
}

```

#### 3.进制转换 在终端输入待转换的值，然后输入想转换为几进制数

```C++
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num, base;
    int n[128], i = 0;
    
    printf("Please enter the converted num:");
    scanf("%d", &num);
    printf("Please enter the base:");
    scanf("%d", &base);
    
    do
    {
        n[i] = num % base;
        num = num / base;
        i++;
    }while(num != 0);
    
    // 因为i在余数为零之后又进行了一次i++
    // 此时的i指向的是下一块待存放空间，所以要先进行一次自减
    for(i --;i >= 0;i --)
    {
        if(n[i] >= 10)
            // 减去10的原因是A就是代表的10
            printf("%c",n[i] - 10 + 'A');
        else
            printf("%d",n[i]);
    }
    printf("\n");
   	
    exit(0);
}
```



#### 4.删除法求质数

**定义**：
 删除法是一种通过逐步删除合数来筛选质数的方法，适用于求某个范围内所有质数。

### 基本步骤：

1. **列出范围内所有大于1的整数**。
2. **从最小的质数2开始**，保留它，并删除它的所有倍数。
3. 找到下一个未被删除的数（下一个质数），**保留它并删除它的所有倍数**。
4. **重复这个过程**，直到处理到不超过这个范围平方根的数为止。
5. **剩下的未被删除的数就是质数**。

```c++
#include <stdio.h>
#include <stdlib.h>

// 使用状态的思想，可以定义1001大小的数组，然后在下表为2对应实际的2
// 此外数组中并不定义实际的数字，而是0/1这样的状态
int main()
{
    char primer[1001] = {0};
    
    for(int i = 2;i < 1001;i ++)
    {
        if(primer[i] == 0)
        	for(int j = i * 2;j < 1001;j += i)
            	primer[j] = -1;
    }
    
    for(int i = 2;i < 1001;i ++)
        if(primer[i] == 0)
            printf("%d is a primer.\n", i);
    
    exit(0);
}
```



## 二维数组

#### 1.定义、初始化

​	

```
[存储类型] 数据类型 标识符[行下标][列下标]
```

```c++
#include <stdio.h>
#include <stdlib.h>

// C语言编程中最后不要直接出现突兀的数字，纯数字常量用define宏来表示
/*
                    内存地址 ↑
                    ───────────────
                    |  a12       |
                    |  a02       |
                    |  a11       |
                    |  a01       |
                    |  a10       |
                    |  a00       |
                    ───────────────
                    内存地址 ↓
*/
#define M 2
#define N 3

int main()
{
    // 两行三列的数组，第一个是a[0][0]，最后一个是a[M - 1][N - 1]
    // 因为二维数组虽然名义上是二维的，但是在内存中还是连续存放的，所以可以把大括号给去掉
    int a[M][N] = {1, 2, 3, 4, 5};
    int a[M][N] = {{1, 2, 3}, {4, 5, 6}};
    // 其它元素自动置为0值
    int a[M][N] = {{1, 2, 3}};
    // 第一行前两个元素
    int a[M][N] = {{1, 3}，{4}};
    // 行可以省略，但是列知道，可以计算出行，也就是计算出空间大小
    int b[][N] = {1, 2, 3, 4, 5};
    // 这样是错误的，计算不出所需要的空间大小，列不能省略
    int c[M][] = {1, 2, 3, 4, 5}; // 错误
    
#ifdef DEBUG
    for(int i = 0;i < M;i ++)
        for(int j = 0;j < N;j ++)
            scanf("%d", &a[i][j]);
#endif
    
    for (int i = 0;i < M;i++)
    {
   		for (int j = 0;j < N;j++) 
    	{
      		printf("%p --> %d\n", &a[i][j], a[i][j]);
    	}
    }
}
```



#### 2.元素引用

数组名【行标】【列标】

#### 3.存储形式

顺序存储，具体形式是按行存储

#### 4.深入理解二维数组





练习题

1.行列互换

```C++
#include <stdio.h>
#include <stdlib.h>

#define M 2
#define N 3

int main()
{
    int a[M][N] = {1, 2, 3, 4, 5, 6}, b[N][M];
    
    for(int i = 0;i < M;i ++)
    {
        for(int j = 0;j < N;j ++)
        {
            printf("%d ", a[i][j]);
            b[j][i] = a[i][j];
        }
    	printf("\n");
    }
    
    for(int i = 0;i < N;i ++)
    {
        for(int j = 0;j < M;j ++)
            printf("%d ",b[i][j]);
        printf("\n");
    }
    
    exit(0);
}
```

2.求最大值及其所在位置

```C++
#include <stdio.h>
#include <stdlib.h>

#define M 2
#define N 3

int main()
{
    int a[M][N] = {43, 4, 23, 89, 9, 7};
    int i, j;
    int max = a[0][0], row = 0, column = 0;
    
    for(int i = 0;i < M;i ++)
    {
        for(int j = 0;j < N;j ++)
            if(max < a[i][j])
            {
                max = a[i][j];
                row = i;
                column = j;
            }
    }
    printf("Max:a[%d][%d] = %d\n", row, column, max);
    
	exit(0);
}
```

3.求各行与各列的和

<img src="images/image-20250602084406130.png" alt="image-20250602084406130" style="zoom:50%;" />

直接在定义的时候就多定义一行一列，然后用来存放和

```C++
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a[5][4] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {10, 11, 12}};
    int i, j;
    
    for(int i =0;i < 4;i ++)
    {
        for(int j = 0;j < 3;j ++)
        {
            a[4][3] += a[i][j];
            a[4][j] += a[i][j];
            a[i][3] += a[i][j];
        }
    }
    for(int i = 0;i < 5;i ++)
    {
        for(int j = 0;j < 4;j ++)
            printf("%4d ", a[i][j]);
        printf("\n");
    }
    
	exit(0);
}
```

4.矩阵乘积

```C++
#include <stdio.h>
#include <stdlib.h>

#define M 2
#define N 3
#define K 2

int main()
{
    int a[M][N] = {1, 2, 3, 4, 5, 6};
    int b[N][K] = {1, 0, 0, 1, 1, 0};
    int c[M][K] = {0};
    
    for(int i = 0;i < M;i ++)
    {
        for(int j = 0;j < K;j ++)
        {
            for(int k = 0;k < N;k ++)
                c[i][j] += a[i][k] * b[k][j];
        }
    }
    
    for(int i = 0;i < M;i ++)
    {

        for(int j = 0;j < K;j ++)
            printf("%d ", c[i][j]);  
        printf("\n");
    }
    
	exit(0);
}
```



#### 深入理解二维数组

二维数组就是多个一维数组组成的连续存放的空间，因为此时的数组名是整个二维数组的地址名，将这个二维数组先当做一维数组来看的话，数组名加一就是直接跳转到了下一行，其实这样理解的话就是深刻理解[]也是运算符，相当于对数组名进行取值运算。

![image-20250602090618122](images/image-20250602090618122.png)

a[2][3] = b[3] + c[3]
a[0] = b[0]
a[1] = c[0]

```C++
#include <stdio.h>
#include <stdlib.h>

#define M 2
#define N 3

int main()
{
    int a[M][N] = {1, 2, 3, 4, 5, 6};
    int i, j;
    
    printf("a = %p\n", a);
    // 相当于是直接跳过了三个int型变量
    printf("a + 1 = %p\n", a + 1);
    
    for(int i = 0;i < M;i ++)
    {
        for(int j = 0;j < N;j ++)
        {
            printf("%p --> %d\n", &a[i][j], a[i][j]);
        }
        printf("\n");
    }
    exit(0);
}
```




## 字符数组

### 1.定义、初始化、存储特点

[存储类型] char 标识符[下标]...

![image-20250602171649773](images/image-20250602171649773.png)

```C++
#include <stdio.h>
#include <stdlib.h>

#define N 3

int main()
{
    // 字符数组赋初值
    char str[N] = {'a', 'b', 'c'};
    // 字符串常量赋初值，区别在于末尾会有一个尾零结束符\0，这个字符就是ASCII码为零的字符
    char string[N] = "a";
    
    // 用户在终端输入一行的时候，其实并没有存放到要存放的空间去，实际存放在当前进程的输入缓冲区中
    // 等输入回车判定输入结束之后，才会把输入缓冲区中的内容拿到指定位置去，顺便再加上尾零
    // 假设这个数组只有3个字节的话，数组就会越界，把后面的内存给覆盖掉了
    // 如果后面的内存有用到的话就会出现段错误
    gets(str);
    puts(str);
    
    for(int i = 0;i < N;i ++)
        printf("%c ", str[i]);
    printf("\n");
    
    exit(0);
}
```

**注意部分初始化的时候，剩余部分会自动初始化为'\0'**

### 2.输入输出

scanf 无法获取带有分隔符的字符串(`\t`, `\n`, ` `)

```C++
#include <stdio.h>
#include <stdlib.h>

#define N 32

int main()
{
    char str[N], str1[N], str2[N];
    // scanf的%s无法获取带有分隔符的字符串(`\t`, `\n`, ` `)
    // 这三个字符会作为字符串的分隔符
    scanf("%s%s%s", str, str1, str2);
    printf("%s\n%s\n%s\n", str, str1, str2);
    
    exit(0);
}
```



### 3.常用函数

之所以要用到函数的原因是字符串除了在初始化的时候，其余时候无法赋值

```C++
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// strlen & sizeof
// strcpy & strncpy
// strcat & strncat
// strcmp & strncmp

#define STRSIZE 32

int main()
{
    char str[] = "hello\0abc";
   	char str1[STRSIZE] = "hello";
    char str2[STRSIZE] = "world";
    
    // 这个函数依然是不对缓冲区进行检查，这样依然可能会导致段错误
    strcpy(str, "abcde");
    strncpy(str, "abcde", STRSIZE)
    puts(str);
    
    strcat(str, " ");
    strcat(str, "world!");
    
    // 这个函数所做的工作相当于是将后一个字符串最多STRSIZE个单元送到前一个字符串的后面
    strncat(str, " ", STRSIZE);
    strncat(str, "world", STRSIZE);
    puts(str);
    
    // 这个比较的是两个字符串是不是相等的
    strcmp(str, "hello world!");
    // 如果str1 - str2是正值就表明str1大，反之就是str2大
    // 如果函数的返回值为零，就表明两个字符串是相等的
    printf("%d\n", strcmp(str1, str2));
    // 这个函数代表只比较这两个字符串的前n位
    printf("%d\n", strncmp(str1, str2));
    
    // 字符串的操作之所以这么麻烦就是因为字符串只能通过操作字符数组的名字，也就是一个地址常量
    
    
#ifdef DEBUG
    // strlen 计算的字符串长度并不包含尾零
    printf("%d\n", strlen(str));
    // 但是sizeof的话就会计算出尾零的大小，也就是字符数组占用的真正空间大小
    printf("%d\n", sizeof(str));
#endif
    exit(0);
}
```



> 单词统计

``` c++
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STRSIZE 1024

int main() 
{
    char str[STRSIZE] = {};
    fgets(str, STRSIZE, stdin);
    int count  = 0, flag = 0;

    for (int i = 0;str[i] != '\0';i++)
    {
    	if (str[i] == ' ') 
    	{
    		flag = 0;
    	} 
    	else if(!flag) 
    	{
            count++;
            flag = 1;
    	}
    }
    printf("count = %d\n", count);
}

```

## 多维数组

![image-20250605122447836](images/image-20250605122447836.png)

```c++
int a[2][3][4]
```



# 指针

64位环境 指针类型占用8个字节也就是64bit
32位环境 指针类型占用4个字节也就是32bit

## 1.变量与地址

变量是对某块内存的抽象表示
指针 == 地址 变量名 == 抽象出来的某块空间的别名，是为了方便用户使用才抽象出来的容易记忆的名字
相当于就是说地址就是经纬度，不管这个地区地名如何变经纬度地址都是不会变的

![image-20250605153651230](images/image-20250605153651230.png)

## 2.指针与指针变量

指针就是一个具有指向作用的地址，使用一个变量将这个地址值存放起来就是指针变量，因此我们通常意义上说的改变指针指向的内容说的不是改变指针本身，而是改变指针变量存储的地址。

``` c++
// 地址的值在一个机器中其实是固定的，其实质就是总线的宽度，那么为什么地址是固定长度，还需要指定指针类型呢？这是因为虽然地址是固定的，但是要指向的变量CPU并不知道其具体大小，赋给具体的类型，CPU就知道在指针后的多少个字节内就都是需要的数据了。
int i = 1;
int *p = &i;
int ** q = &p;
```

## 3.直接访问与间接访问

如果使用i就是直接访问，如果通过指针变量间接访问变量值，就是间接访问

``` c++
// 这个语句相当于自动分配了一个地址是0x2000的房间，然后在其中存放1的补码
i = 1;
// 这个地址的分配是自动的并不一定都是0x2000，但一定是分配了一个有地址的空间
// 因此使用取地址运算符的时候就可以获取到存放i值的地址
// 取地址就是获得某个变量在内存中的房间号，取值就是渠道这个房间号中把里面的东西拿出来
&i = 0x2000;
p = 0x2000; // 这个就是i的地址
&p = 0x3000; // 这个是指针变量p自身的地址
*p = 1; // 这个操作就是和直接操作i没有区别 i == *p 
q = 0x3000; // q这个变量存放的就是p指针变量自身的地址
&q = 0x4000; // 这个是q指针变量自身的地址
*q = 0x2000; // *q == p 得到的是i的地址
**q = 1; // **q == *p == i 这个就相当于直接操作变量i
// &i == p == *q
```

![image-20250605164044232](images/image-20250605164044232.png)

![image-20250605154723582](images/image-20250605154723582.png)

指针的使用类似于，通过key3拿到key2，通过key2拿到key1，再通过key1拿到△

![image-20250605154915435](images/image-20250605154915435.png)

因此使用指针就相当于定一个变量p来存放变量i的地址，那么这个变量p就相当于key

![image-20250605155055845](images/image-20250605155055845.png)

多个抽屉就相当于多个指针嵌套使用

```C++
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i = 1;
    int *p;
    float *q;
    double *d;
    char *c;
    p = &i;
    
    // 可以直接定义，这里的类型是int *这样理解就会好很多
    int *p = &i;
    // 直接给一个地址值的风险太高了，所以一般会是非法操作，因为对其上下文一概不知
    // 这个地址号在哪里，是不是别人有占用
    int *p = 0x7fffa37eac6of;

    printf("i = %d\n", i);
    printf("&i = %p\n", &i);
    printf("p = %p\n", p);
    printf("&p = %p\n", &p);
    printf("*p = %d\n", *p);
    
    // 不管你的指针的类型是什么，只要平台是确定的，指针变量的大小就是确定的
    // 哪怕是一个只有一个字节的变量，64位平台下它的地址也是八个字节
    printf("%d\n", sizeof(p));
    printf("%d\n", sizeof(q));
    printf("%d\n", sizeof(d));
    printf("%d\n", sizeof(c));
    // 举一个反例就是如果指针变量和变量本身的类型不匹配的话，就会发生未定义行为
    c = &i;
    // *c的时候可能取出的就不是1，这相当于将int型变量截短当做了char来使用

    exit(0);
}
```



## 4.空指针与野指针

野指针的意思是当前指针指向的空间是不确定的或者根本没有指向，但却直接使用了这个指针。

```C++
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // 如果在定义指针的时候还不知道要指向什么地方，就可以先指向
    int *p = NULL;
    // 任何类型的指针都可以将自己的值赋值给void * ，它也可以将自己赋值给任意类型的指针
    // 在不确定使用什么数据类型的时候就可以使用void *类型的指针，比如说读取某一段内存
    // 特例就是void *和一个指针函数进行赋值是一个未定义的行为。
    void *q = NULL;
    // NULL就是地址为零的地址，这个地方是不会分配给任何人使用的
    *p = 1;
    
    int *c;
    printf("%p --> %d\n", p, *p);
    exit(0);
}
```



## 5.空类型

``` c++
char *s = "hello";
void *i = s;
```

## 6.定义与初始化的写法

```C++
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i = 1;
    int *p = &i;
    int **q = &p;
    
    printf ("%d\n", sizeof (i));
    printf ("%d\n", sizeof (p));

    printf("i = %d\n", i);
    printf("&i = %p\n", &i);

    printf("p = %p\n", p);
    printf("&p = %p\n", &p);
    printf("*p = %d\n", *p);

    printf("q = %p\n", q);
    printf("*q = %p\n", *q);
    printf("**q = %d\n", **q);
    
    exit(0);
}
```




## 7.指针运算

```
指针的运算常用的就是：&、*、关系运算、++、--
自增和自减在后面用到的时候再讲
```



```c++
#include <stdio.h>
#include <stdlib.h>

int main()
{
    
    exit(0);
}
```



## 8.指针与数组

### 	指针与一维数组

指针和数组为什么关系这么大呢？最根本的原因是数组在内存中是连续存放的，这一点是其他的任何数据类型都难以比拟的，其余任何数据结构的查找速度都是比不上数组的。又因为指针可以进行一些加减运算，其副作用就是指向的地址加减一个数据类型的大小，这样就可以很方便地调用数组了，因此二者的联系相当紧密。其次就是指针的关系运算可以比较的一个前提就是，指针指向的是一个连续的存储空间，这样指针的指向才能够有意义。

a[i]的功能就是从数组起始位置a加上i来进行取值操作，此处的加一不表示一个字节而是一个int类型的大小，具体移动多少的字节需要看当前的数据类型。

![image-20250605224003375](images/image-20250605224003375.png)



``` c++
#include <stdlib.h>
#include <stdio.h>

// 类型可以认为是一个虚的概念，表示的就是数据在内存中如何存放
// 任何定义都可以抽象为
// TYPE NAME = VALUE

int main () 
{
    int a[3] = {1, 2, 3};
    // a是常量 p是变量
    // 因此如果int *p = a；的话其实就是定义了一个相同类型的指针，然后这个指针加一减一的时候就和a加一减一的效果是一样的了。
    // 虽然a和p可以混用，但本质上a是数组名是一个常量，p是指针变量，只是这个变量中存放了a这个数组名所代表的地址。
    int *p = a;
    p++; // 要区分 p++和p+1，前者相当于 p = p + 1，相当于改变了p指针指向的地址
    	// p + 1仅仅是改变了指向的元素，并没有改变p指针的地址
    a++; //不能使用，因为a是一个常量
    
    printf("%p, %p", a, a + 1);
    printf("%p, %p", p, p + 1);

    for (int i = 0;i < sizeof(a)/sizeof(*a);i ++) 
    {
        // printf("%p -> %d\n", a + i, a[i]);
        // a[i]VALUE: a[i] = *(a + i) = *(p + i) = p[i]
        // &a[i]ADDRESS: &a[i] = a + i = p + i = &p[i]
    	printf("%p -> %d\n", p+i, *(p+i));
    }
}

```

**需要注意****`p++` != `p+1`**

``` c++
#include <stdlib.h>
#include <stdio.h>

int main () 
{
    int a[3];
    int *p = a;
    
    for (int i = 0;i < sizeof(a)/sizeof(*a);i++) 
    {
        printf("%p --> %d\n", &a[i], a[i]);
    }

    for (int i = 0;i < sizeof(a)/sizeof(*a);i++) 
    {
    	scanf("%d", p++);
    }
    
    // 因为p++会有副作用，因此在进行下面的循环时，p已经走远了
    p = a; // 重新赋值即可

    for (int i = 0;i < sizeof(a)/sizeof(*a);i++) 
    {
    	printf("%p --> %d\n", p, *(p++));
    }
    
    
    // 还可以这样写，这个相当于匿名数组
    int *p = (int [3]){1, 2, 3}
    for(int i = 0;i < 3;i ++)
        printf("%p --> %d\n", &p[i], p[i]);
    
    int a[] = {5, 1, 7, 2, 8, 3};
    int y;
    int *p = &a[1];

    y = (*--p)++;
    printf("y = %d\n", y);

}

```

### 	指针与二维数组

``` c++
#include <stdlib.h>
#include <stdio.h>

int main() 
{
    // a是这一整个数组的起始位置，相当于是a[2]的起始位置，然后a[0]就是一个int[3]的类型，再展开之后就是3个int类型的变量。
    int a[2][3] = {{1, 2, 3},{ 4, 5, 6}};
    int (*p)[3] = a;
#ifdef DEBUG
    // 之前在一维数组的课程中是直接写的，假设arr是一个int型数组名
    int *p = arr;
    // 这个之所以成立的底层逻辑是因为a是个int类型的一维变量
    // 但是此处的a是一个二维数组名，相当于是一个int[3]类型的一维数组，所以直接写会报错
    // 用李老师的话来说就是我们定义的指针是操作列的，但是数组名仅仅只是一个行指针，所以二者不匹配
    int *p = a;
    // 我的这种写法是错误的
    *(int [3])p = a;
    // 这个是正确的
    int (*p)[3] = a;  // OK：p 是一个指向 int[3] 的指针
    
    // 正确的写法，相当于对a进行取值p  = *a本质上就是p = &a[0][0]
    p = *(a + 0);
    
#endif
    // a + 1就是直接跳转到了&a[1][0]
    printf("%p, %p\n", a, a + 1);

    for (int i = 0;i < sizeof(a)/sizeof(*a);i++) 
    {
    	for (int j = 0;j < sizeof(*a)/sizeof(**a);j++) 
    	{
            printf("%p --> a[%d][%d] = %d ", &a[i][j], i, j, a[i][j]);
            // 所以这一行代码的意思就是先移动i行解引用之后，再移动列，再解引用
      		// printf("%p --> %d ",*(p + i) + j, *(*(p + i) + j));
    	}
        printf("\n");
    }
}

```

``` c++
#include <stdlib.h>
#include <stdio.h>

// 这种写法是将这个二维数组看成了是一个连续的一维数组
int main() 
{
    int a[2][3] = {{1, 2, 3},{ 4, 5, 6}};
    // 这里给的直接就是能够操作单一元素的地址
    int *p = &a[0][0];
    for(int i = 0;i < 6;i ++)
        printf("%d ", p[i]);
	printf("\n");

    for (int i = 0;i < sizeof(a)/sizeof(*a);i++) 
    {
        for (int j = 0;j < sizeof(*a)/sizeof(**a);j++) 
        {
          	printf("%d ",*(p+(i * sizeof(*a)/sizeof(**a))+j));
        }
        printf("\n");
    }
    
    exit(0);
}

```

### 	指针与字符数组

1. 字符数组 `char str[] = "hello";`

- 将字符串全部内容拷贝到缓存或栈上
- 可以修改内容
- 数组名不可被重新赋值

示例

```c
char str[] = "hello";
str[0] = 'H';            // 可修改
strcpy(str, "world");   // 用来替换数组内容，其作用是一个一个替换str的空间
// str = "test";        // 错误，数组名不能被赋值
```

------

2. 字符指针 `char *str = "hello";`

- 指向字符字面量（常存区）
- 不允许修改内容
- 可以更换指针指向

示例

```c
char *str = "hello";
// str[0] = 'H';        // 错误，修改常量内容
str = "world";          // 可以改指向
```

------

3. 动态分配字符串

- 适合需要自由资源的场景
- 需要手动释放

示例

```c
char *str = malloc(32);           // 分配 32 字节
strcpy(str, "hello");
str[0] = 'H';                     // 可修改
free(str);                        // 释放内存
```

------

4. 总结表

   char str[]="hello"是先开辟空间，然后再填充；char* str="hello"str指向常量字符串,常量字符串不能被修改

| 场景                 | 推荐方式                 |
| -------------------- | ------------------------ |
| 需要修改字符串内容   | `char str[] = "..."`     |
| 只读字符串，不需修改 | `char *str = "..."`      |
| 需要动态调整内容     | `malloc + strcpy + free` |

------

小结

- 想改字符内容用数组
- 想改指向用指针
- 需要动态调整内容和存储用 `malloc`

```C++
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    // char str[] = "hello";
    char *str = "hello";
    printf("size of str = %d\nlength of str = %d\n", sizeof(str), strlen(str));
    // str = "world"
    // str是地址常量，不是左值
#ifdef DEBUG
    // 使用*str来定义的时候会产生段错误
    strcpy(str, "world");
    puts(str);
#endif
     
    
#if 0
    char str[] = "hello";
    char *p = str + 7;
    
    puts(str);
    puts(p);
#endif
    
    exit(0);
}
```



## 9.const与指针

**const本身的用法**
const的作用是将某些变量常量化

``` c++
const int a;
int const ;

// define 的好处是一改全改，不好的地方是在预处理阶段不会做语法检查
#define PI 3.14
// const修饰符相当于在pi这个变量中存储3.14这个常量，相对于宏就是检查语法
const float pi = 3.14; // 常量化变量
```

> 先看到指针就是指针 先看到常量就是常量

- 常量指针 指针自身可以变，指向的内存不能通过这个指针修改

``` c++
// 这两种定义是没有区别的
const int* p;
int const *p;

char *strcpy(char *restrict dest, const char *src); // src是源字符串 不应该被修改

int main()
{
    int i = 1;
    int j = 100;
    const int *p = &i;
    
    // 直接写成i = 10是可以的
    // 但是通过*p来进行修饰是错误的
    *p = 10;
    // 但是通过修改地址来间接修改指向的值是可以的
    p = &j;
}
```

- 指针常量 指向的位置不能变，指针自身不能变， 可以通过这个指针修改内存的值

``` c++
int *const p;

// 这个既是指针常量又是常量指针
const int *const p;

int main()
{
    int i = 1;
    int j = 100;
    int *const p = &i;
    // 现在就既不能改变指针自身的值，也不能修改指向的值 
    const int *const p = &i;
    printf("%d\n", *p);
    
    p = &j;
    
    exit(0);
}
```



```C++
#include <stdio.h>
#include <stdlib.h>

#define PI 3.14

int main()
{
    // 约定使用某一个标识符
	const float pi = 3.14;
    // 这样做的话编译器会报一个错误，就是丢弃了指针目标类型的限制
    // 说人话就是你本来const就是不修改的，然后你又修改了这个值
    float *p = &pi;
    // 正确的写法是在float前面也加上一个const
    const float *p = &pi;
    printf("%f\n", pi);
    // pi = 3.14159
    printf("%f\n", pi);
    
    exit(0);
}
```



## 10.指针数组与数组指针

### 指针数组，归根结底是一个数组

``` c++
// 定义了一个数组，数组有3个元素，这三个元素都是指针
[存储类型] 数据类型 * 数组名[长度]
int *arr[3] --> TYPE NAME --> 这里的arr就是三个int指针 int *[3]
```

```C++
#include <stdio.h>
#include <stdlib.h>

int main()
{
          
	exit(0);
}
```

指针数组排序

``` c++
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() 
{
    char *name[5] = {"golang", "java", "c", "dart", "erlang"};

    int k;
    char *tmp;
    for (int i = 0;i < (sizeof(name)/sizeof(*name))-1;i++) 
    {
        k = i;
        for (int j = i+1;j < (sizeof(name)/sizeof(*name));j++) 
        {
        	if (strcmp(name[k], name[j]) > 0) 
            {
            	k = j;
            }
    	}
        if (k != i) 
        {
            tmp = name[i];
            name[i] = name[k];
            name[k] = tmp;
        }
    }

    for (int i = 0;i < (sizeof(name)/sizeof(*name));i++) 
    {
    	printf("%s\n", *(name+i));
    }
    
    exit(0);
}

```

### 数组指针:归根结底是一个指针，这个指针是指向数组的

``` c++
定义：[存储类型] 数据类型 (*指针名)[下标] = 值

int a[2][3] = {{1, 2, 3},{ 4, 5, 6}};
int (*p)[3] = a; -> type name -> int[3] *p;

// 现在p进行加一操作的时候跳过的是3个int数据类型占用空间的大小
// 数组指针名称的由来就是其是在一定大小的数组之间来进行移动的，所以叫做数组指针
// 相当于它就是高维数组和其中包含的低维数组的传令兵

// 少用/* */注释的原因就是你的代码中是有可能存在*/这样的东西的，是有风险导致程序构建的时候崩溃的
```

``` c++
#include <stdlib.h>
#include <stdio.h>

int main() 
{
    int a[2][3] = {{1, 2, 3},{ 4, 5, 6}};
    int (*p)[3] = a;
    
    printf("%p %p", a, a + 1);
    printf("%p %p", p, p + 1);

    for (int i = 0;i < sizeof(a)/sizeof(*a);i++) 
    {
        for (int j = 0;j < sizeof(*a)/sizeof(**a);j++) 
        {
        	printf("%p --> %d ", *(a + i) + j,*(*(p + i) + j));
        }
    }
    
    exit(0);
}

```

## 11.多级指针

没啥好说的

# 函数

## 函数的定义

``` c++
#include <stdlib.h>
#include <stdio.h>

int main() 
{
	exit(printf("Hello!\n"));
}

```

## 函数的传参

- 值传递
- 地址传递
- 全局变量

## 函数的调用

- 嵌套

``` c++
#include <stdlib.h>
#include <stdio.h>

int max(int a, int b, int c) 
{
    int tmp = a > b ? a : b;
    return tmp > c ? tmp : c;
}

int min(int a, int b, int c) 
{
    int tmp = a < b ? a : b;
    return tmp < c ? tmp : c;
}

int dist(int a, int b, int c) 
{
    return max(a, b, c) - min(a, b, c);
}

int main() 
{
    printf("%d\n", dist(8, 5, 10));
}

```

- 递归

``` c++
#include <stdio.h>
#include <stdlib.h>

int func(int n) 
{
    if (n < 0) 
    {
    	return -1;
    }
    if (n == 1 || n == 2) 
    {
    	return 1;
    }
    return func(n-1) + func(n-2);
}

int main() 
{
    int n;
    scanf("%d", &n);
    printf("fib %d = %d", n, func(n));
    exit(0);
}

```


``` c++
#include <stdio.h>
#include <stdlib.h>

int func(int n) {
  if (n < 0) {
    return -1;
  }
  if (n == 0 || n == -1) {
    return 1;
  }
  return n * func(n - 1);
}

int main() {
  int n;
  scanf("%d", &n);
  printf("%d! = %d", n, func(n));
  exit(0);
}

```

## 函数与数组

``` c++
#include <stdlib.h>
#include <stdio.h>

// 注意这里的int *arr 的大小是8个字节 是一个普通的指针不是数组 所以一定要传大小
void printarr(int *arr, int size) {
  for (int i = 0;i < size;i++) {
    printf("%d ", *(arr+i));
  }
  printf("\n");
}

int main() {
  int arr[] = {1, 2, 3, 4, 5};
  printarr(arr, sizeof(arr)/sizeof(*arr));
}

```

``` c++
#include <stdlib.h>
#include <stdio.h>

void printarr(int *arr, int size) {
  for (int i = 0;i < size;i++) {
    printf("%d ", *(arr+i));
  }
  printf("\n");
}

void printarr2(int (*p)[3], int m , int n) {
  for (int i = 0;i < m;i++) {
    for (int j =0;j < n;j++) {
      printf("%4d ", *(*(p+i)+j));
    }
    printf("\n");
  }
}

int main() {
  int arr[][3] = {1, 2, 3, 4, 5, 6};
  printarr2(arr, 2, 3);
}

```

## 函数的指针

- 指针函数

``` c++
#include <stdio.h>
#include <stdlib.h>

#define M 2
#define N 3

int *findnum(int (*p)[N], int num) {
  if (num > M - 1) {
    return NULL;
  }
  return *(p + num);
}

int main() {
  int arr[M][N] = {{1, 2, 3},{ 4, 5, 6}};

  int *res = findnum(arr, 1);

  for (int i = 0; i < N; i++) {
    printf("%d ", *(res + i));
  }
}

```

- 函数指针
  `类型 (*指针名)(形参)`

- 函数指针数组
  `类型 (*数组名[下标]) (形参)`

指向指针函数的函数指针数组

``` c++
int *(*funcp[N])(int)
```

实际例子

``` c++
int pthread_create(pthread_t *restrict thread,
                          const pthread_attr_t *restrict attr,
                          void *(*start_routine)(void *),
                          void *restrict arg);
```

# 构造类型

## 结构体

### 产生及意义

描述复杂的数据类型

### 类型描述

``` c++
struct node_st{
  type1 name1;
  type2 name2;
  ...
};
```

### 嵌套定义

``` c++
struct day {
  int H;
  int M;
  int S;
};

struct student_st{
  char *name;
  struct day day;
};
```

### 定义变量 初始化以及成员引用

- 结构体 .
- 结构体指针 ->

``` c++
struct A {
  int i;
  char c;
  float f;
};

int main() {
  // TYPE NAME = VALUE;
  struct A a = {123, 'A', 2.22}; // 初始化
  struct A a_ = { .c = 'A', .f = 2.22}; // 部分初始化
  struct A *ap = { .c = 'A', .f = 2.22}; // 部分初始化
  
  printf("%d %c %.2f\n",a.i, a.c, a.f); // 成员引用
  // 123 A 2.22
  printf("%d %c %.2f\n",a_.i, a_.c, a_.f); // 成员引用
  // 0 A 2.22
  printf("%d %c %.2f\n",ap->i, ap->c, ap->f); // 成员引用
  // 0 A 2.22
}
```

### 占用内存空间大小

`addr % sizeof(type)` 不能整除的话就要继续往下偏移

``` c++
#include <stdio.h>
#include <stdlib.h>

struct A {
  int i;
  char c;
  float f;
};

// 可以使用下面的方法取消对齐 常用于网络通信
struct B {
  int i;
  char c;
  float f;
}__attribute__((packed));

int main() {
  struct A a;
  struct B b;

  printf("A = %ld\n", sizeof(a));
  printf("B = %ld\n", sizeof(b));
}

```

## 共用体

### 产生及意义

N选一 多个成员共用一块空间 取最大的成员的类型大小作为共用体的类型大小

### 类型描述

``` c++
union test_un{
  int i;
  float f;
  double d;
  char ch;
};
```

### 嵌套定义

同结构体 可以互相嵌套

###  定义变量 初始化以及成员引用

成员引用：

- u.成员名
- up->成员名

> 32位的无符号数的高16位和低16位相加

``` c++
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

int main() {
  uint32_t i = 0x11223344;
  printf("%x\n", (i>>16)+(i&0xFFFF));
}
```

另一种写法

``` c++
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

union {
  struct {
    uint16_t i;
    uint16_t j;
  }x;
  uint32_t y;
}u;

int main() {
  uint32_t i = 0x11223344;
  printf("%x\n", (i>>16)+(i&0xFFFF));

  u.y = 0x11223344;
  printf("%x\n", u.x.i + u.x.j);
}

```

## 枚举

``` c++
enum 标识符{
  成员1;
  ...
};
```

``` c++
enum dar {
  MON = 1,
  TUS,
  WEB,
  THR,
  FRI,
  SAT,
  SUN,
};

int main() {
  enum day a = FRI;
  
  printf("%d\n", a);
}
```

``` c++
enum status {
  RUNNING = 1,
  STOP,
  PAUSE,
};

struct job {
  int id;
  int state;
  time_t start, end;
};

int main() {
  struct job_st job1;
  
  switch(jobs.state) {
    case RUNNING:
      // TODO
      break;
    case STOP:
      // TODO
      break;
    case PAUSE:
      // TODO
      break;
    default:
      // TODO
      abort();
  }
}

```

## typedef

`typedef type typename`

``` c++
typedef int INT

int main() {
  INT i = 9;
}
```

> typedef 和 define 的区别

``` c++
#define IP int *
type int *IP;

int main() {
  // 宏
  IP p, q;
  int *p, q; // 一个int * 一个int
  
  // typedef
  IP p, q;
  int *p, *q; // 两个int *
}
```

> 数组

``` c++
typedef int ARR[6]; // int [6] 改名为 ARR

ARR a; // int a[6];
```

> 结构体

``` c++
typedef struct {
  int i;
  float f;
}NODE, *NODEP;
```

> 函数

``` c++
typedef int *FUNC(int)
```

> 函数指针

``` c++
typedef int* (*FUNCP)(int)
```

# 动态内存管理

- malloc
- calloc
- realloc
- free
  **谁申请谁释放**

``` c++
#include <stdlib.h>
#include <stdio.h>

int main() {
  int *ip = malloc(sizeof(int));

  *ip = 1;

  printf("%d\n", *ip);
  free(ip);
}

```

> 动态数组

``` c++
#include <stdlib.h>
#include <stdio.h>

int main() {
  int *p;
  int num = 5;
  p = malloc(num * sizeof(int));

  for (int i = 0;i < num;i++) {
    scanf("%d", p+i);
  }
  for (int i = 0;i < num; i++) {
    printf("%d ", *(p+i));
  }

  printf("\n");
  exit(0);
}

```

> 内存申请与函数传值

``` c++
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

void func1(void *p, size_t size) {

  if(p == NULL) {
    return;
  }
  p = malloc(size);
}

void func2(int **p, size_t size) {

  if(*p == NULL) {
    return;
  }
  *p = malloc(size);
}

void *func3(void *p, size_t size) {
  if(p == NULL) {
    return NULL;
  }
  p = malloc(size);
  return p;
}

int main() {
  int num = 100;
  int *p = NULL;

  func1(p, num); // 内存会泄露

  func2(&p, num); // 传递二级指针

  p = func3(p, num); // 将申请的内存返回

  free(p);
  exit(0);
}

```


### free的理解

``` c++
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

void func2(int **p, size_t size) {

  if(*p == NULL) {
    return;
  }
  *p = malloc(size);
}

int main() {
  int num = 100;
  int *p = NULL;

  func2(&p, num); // 传递二级指针

  free(p);
  // p = NULL;
  
  *p = 123;
  printf("%d\n", *p); // 这个指针已经是野指针了 
  
  exit(0);
}
```

- free代表着变量p不再拥有原来指向内存空间的引用权限
- free后最好马上将指针置NULL

# Makefile

工程管理 依赖管理

- makefile(用户自定义 更高优先级)
- Makefile(默认)

``` makefile
mytool:main.o tool1.o tool2.o
  gcc main.o tool1.o tool2.o -o mytool

main.o:main.c
  gcc main.c -c -Wall -g -o main.o
tool1.o:tool1.c
  gcc tool1.c -c -Wall -g -o tool1.o
tool2.o:tool2.c
  gcc tool2.c -c -Wall -g -o tool2.o
  
```


``` makefile
OBJS=main.o tool1.o tool2.o
CC=gcc

mytool:$(OBJS)
  $(CC) $(OBJS) -o mytool

main.o:main.c
  $(CC) main.c -c -Wall -g -o main.o
tool1.o:tool1.c
  $(CC) tool1.c -c -Wall -g -o tool1.o
tool2.o:tool2.c
  $(CC) tool2.c -c -Wall -g -o tool2.o
 
clean:
  $(RM) $(OBJS) mytool -r
```

> $^ 表示在上一句依赖关系中被依赖的所有文件
> $@ 表示在上一句依赖关系中依赖项的目标文件

``` makefile
CFLAGS=-Wall -g -c
OBJS=main.o tool1.o tool2.o
CC=gcc

mytool:$(OBJS)
  $(CC) $^ -o $@

main.o:main.c
  $(CC) $^ $(CFLAGS) -o $@
tool1.o:tool1.c
  $(CC) $^ $(CFLAGS) -o $@
tool2.o:tool2.c
  $(CC) $^ $(CFLAGS) -o $@
 
clean:
  $(RM) $(OBJS) mytool -r
```

> % 表示同一个名字

``` makefile
CFLAGS=-Wall -g -c
OBJS=main.o tool1.o tool2.o
CC=gcc

mytool:$(OBJS)
  $(CC) $^ -o $@

%.o:%.c
  $(CC) $^ $(CFLAGS) -o $@
 
clean:
  $(RM) $(OBJS) mytool -r
```





