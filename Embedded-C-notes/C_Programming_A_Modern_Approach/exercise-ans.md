# C语言程序设计-现代方法-课后习题

## 第一章 C语言概述

## 第二章 C语言基本概念

### 练习题

1. 建立并运行由 Kernighan 和 Ritchie 编写的著名的“hello, world”程序：

```C
#include <stdio.h> 
int main(void) 
{ 
	printf("hello, world\n"); 
} 
```

在编译时是否有警告信息？如果有，需要如何修改呢？

**ANS：**

```C
// 使用的机器型号和编译器版本如下，在编译过程中即使使用了-Wall选项之后也没有任何报错。
// 但这个程序的“错误”很明显就是没有return或exit(0)语句。
Apple clang version 17.0.0 (clang-1700.3.19.1)
Target: arm64-apple-darwin25.0.0
Thread model: posix
InstalledDir: /Library/Developer/CommandLineTools/usr/bin
```

2. 思考下面的程序：

```C
#include <stdio.h> 
int main(void) 
{ 
  printf("Parkinson's Law:\nWork expands so as to "); 
  printf("fill the time\n"); 
  printf("available for its completion.\n"); 
  return 0; 
} 
```

​	(a) 请指出程序中的指令和语句。
​	(b) 程序的输出是什么？

**ANS:**

(a)程序共有`#include<stdio.h>`一个指令，三条`printf`语句和一条`return`共四条语句。
(b)程序的输出是三行字符串：

```
Parkinson's Law:
Work expands so as to fill the time
available for its completion.
```

3. 通过下列方法缩写程序 dweight.c：

   (1) 用初始化器替换对变量 height、length 和 width 的赋值；
   (2) 去掉变量 weight，在最后的 printf 语句中计算(volume + 165)/ 166。

**ANS：**

```c
/* Computes the dimensional weight of a 12" x 10" x 8" box */ 
#include <stdio.h> 
int main(void) 
{ 
  int height = 8, length = 12, width = 10, volume; 
  volume = height * length * width; 
  printf("Dimensions: %dx%dx%d\n", length, width, height); 
  printf("Volume (cubic inches): %d\n", volume); 
  printf("Dimensional weight (pounds): %d\n", (volume + 165) / 166); 
  return 0; 
}
```

4. 编写一个程序来声明几个 int 型和 float 型变量，不对这些变量进行初始化，然后显示它们的值。
   这些值是否有规律？（通常情况下没有。）

**ANS：**

```C
/*
  本程序演示了局部变量在未初始化时的行为。

  在 C 语言中，未显式初始化的局部变量（如函数内定义的 int 或 float 变量）
  的值是“未定义的”（undefined behavior）。也就是说，变量 a、b、c、d、e、f
  会占用内存中的某个位置，但这些位置可能包含任意残留数据。

  因此：
    - 这些变量不会自动被赋值为 0；
    - 它们的输出结果是不可预测的，可能在不同的编译器、运行环境下变化；
    - 程序虽然能编译通过，但输出没有规律，也不具有参考意义。

  结论：在使用局部变量之前必须先显式初始化，否则会导致不可预期的结果。
*/

#include <stdio.h>
int main(void)
{
    int a, b, c;
    float d, e, f;

    printf("%d, %d, %d\n", a, b, c);
    printf("%f, %f, %f\n", d, e, f);

    return 0;
}

```

5. 下列 C 语言标识符中，哪些是不合法的？
   (a) 100_bottles
   (b) \_100_bottles
   (c) one\_hundred_bottles _
   (d) bottles_by_the_hundred_ 

**ANS：**100_bottles是数字开头的，one\_hundred_bottles _中间含有空格，这两个是不合法的。

6. 为什么说在标识符中使用多个相邻的下划线（如 current___balance）不太合适？

**ANS：**

```C
/*
  在 C 语言中，标识符中虽然可以使用下划线 (_)，
  但不建议在标识符中使用多个相邻的下划线（例如 current___balance），
  原因如下：

  1. **可读性差**  
     多个连续下划线会让标识符在视觉上难以区分，容易与其他变量混淆。
     例如：
         current_balance
         current__balance
         current___balance
     这三者看起来非常相似，不利于代码的可维护性。

  2. **不符合命名规范**  
     在实际编程规范（如 ISO C 标准及各大公司风格指南）中，
     推荐使用一个下划线来分隔单词，而不是多个。
     多个下划线会被认为是命名不规范的“噪声”。

  3. **潜在的可移植性风险**  
     尽管编译器不会报错，但在某些系统库或编译环境中，
     含有多个下划线（特别是以 `__` 开头的）标识符可能被保留用于内部实现，
     从而导致命名冲突或不可预期的行为。

  因此：
     建议使用清晰、规范的命名方式，例如：
         current_balance
     而避免使用：
         current___balance
*/

```

6. 下列哪些是 C 语言的关键字？
   (a) for
   (b) If
   (c) main
   (d) printf
   (e) while

**ANS:**在这些选项中，只有 **for** 和 **while** 是 C 语言关键字。“If” 因为大小写错误不是关键字；“main” 是函数名而非关键字；“printf” 是标准库函数而非关键字。

8. 下面的语句中有多少个记号？

```c
answer=(3*q–p*p)/3; 
```

ANS: 记号分别为 answer、=、(、3、 *、q、-、p、\*、p、)、/、3、；一共14个记号。

9. 在练习题 8 的记号之间插入空格，使该语句更易于阅读。

```C
answer = ( 3 * q – p * p ) / 3; 
```

9. 在 dweight.c 程序（2.4 节）中，哪些空格是必不可少的？

**ANS：**本程序中，只有用于分隔关键字与标识符（如 `int main`、`return 0`、`int height`）的空格是必不可少的；其余空格仅用于增强可读性，可以省略。

```C
/* Computes the dimensional weight of a 12" x 10" x 8" box */ 
#include<stdio.h> 
int main(void) 
{ 
  int height, length, width, volume, weight; 
  height = 8; 
  length = 12; 
  width = 10; 
  volume = height * length * width; 
  weight = (volume + 165) / 166; 
  printf("Dimensions: %dx%dx%d\n", length, width, height); 
  printf("Volume (cubic inches): %d\n", volume); 
  printf("Dimensional weight (pounds): %d\n", weight); 
  return 0; 
}
```



### 编程题

1. 编写一个程序，使用 printf 在屏幕上显示下面的图形：

```
              *  
            *
          *
*       *
  *   * 
    * 
```

**ANS：**

```c
#include<stdio.h>
#include<stdlib.h>
int main(void)
{
    printf("        *\n");
    printf("       *\n");
    printf("      *\n");
    printf("     *\n");
    printf("*   *\n");
    printf(" * *\n");
    printf("  *\n");

    return(0);
}
```

2. 球体的体积计算公式为 $ v = \frac{4}{3}\pi r^3 $，其中 $r$ 为球体半径。在程序中，分数部分应写成 `4.0f / 3.0f`，而不能写作 `4 / 3`，因为在 C 语言中，`4` 和 `3` 都是整型常量，`4 / 3` 会执行整数除法，结果为 `1`，从而导致计算结果偏小约三分之一。使用浮点数除法 `4.0f / 3.0f` 才能得到正确的结果（约为 1.3333）。此外，C 语言没有指数运算符，计算 $r^3$ 时应写作 `r * r * r`。


**ANS：**

```c
#include<stdio.h>
#include<stdlib.h>
int main(void)
{
    float radius = 0.0f, volume = 0.0f, pi = 3.1415926f;
    printf("Please enter the radius:");
    scanf("%f", &radius);

    printf("The volume of the input sphere is:%.2f\n",
        4 / 3 * radius * radius * radius * pi);

    return 0;
}
```

3. 修改上题中的程序，使用户可以自行输入球体的半径。

**ANS:**

```c
#include<stdio.h>
#include<stdlib.h>
int main(void)
{
    float radius = 0.0f, volume = 0.0f, pi = 3.1415926f;
    printf("Please enter the radius:");
    scanf("%f", &radius);

    printf("The volume of the input sphere is:%.2f\n",
        4.0f / 3.0f * radius * radius * radius * pi);

    return 0;
}
```

4. 编写一个程序，要求用户输入一个美元数额，然后显示出增加5%税率后的相应金额。格式如下所示：
   Enter an amount: 100.00
   With tax added: $105.00 

**ANS:**

```c
#include<stdio.h>
#include<stdlib.h>
int main(void)
{
    float amount = 0.0f, tax_rate = 1.05f;

    printf("Enter an amount:");
    scanf("%f", &amount);

    printf("With tax added:%.2f$\n", amount * tax_rate);

    return 0;
}
```

5. 编程要求用户输入 *x* 的值，然后显示如下多项式的值：

多项式表达式为：

$$
3x^5 + 2x^4 - 5x^3 - x^2 + 7x - 6
$$
提示：C语言没有指数运算符，所以需要对*x*进行自乘来计算其幂。（例如，x\*x*x就是x的三次方。）

**ANS:**

```c
#include<stdio.h>
int main(void)
{
    float x = 0.0f;
    printf("Please enter the value of x:");
    scanf("%f", &x);

    printf("%.2f\n", 3 * x * x * x * x * x +
            2 * x * x * x * x - 5 * x * x * x - x * x + 7 * x - 6);

    return 0;
}
```

6. 修改上题，用如下公式对多项式求值：

$$
((((3x + 2)x - 5)x - 1)x + 7)x - 6
$$

注意，修改后的程序所需的乘法次数减少了。这种多项式求值方法即 Horner 法则。

**ANS:**

```c
#include<stdio.h>
int main(void)
{
    float x = 0.0f;
    printf("Please enter the value of x:");

    scanf("%f", &x);

    printf("The value of the polynomial is:%.2f\n",
            ((((3 * x + 2) * x - 5)  * x - 1) * x + 7) * x - 6 );
    return 0;
}
```

7. 编写一个程序，要求用户输入一个美元数额，然后显示出如何用最少张数的 20 美元、10 美元、5 美元和 1 美元钞票来付款：


```
Enter a dollar amount: 93
$20 bills: 4 
$10 bills: 1 
$5 bills: 0 
$1 bills: 3 
```

提示：将付款金额除以 20，确定 20 美元钞票的数量，然后从付款金额中减去 20 美元的总金额。对其他面值的钞票重复这一操作。确保在程序中始终使用整数值，不要用浮点数。

**ANS:**

```c
#include<stdio.h>
int main(void)
{
    int amount = 0;
    printf("Please enter a dollar amount:");
    scanf("%d", &amount);

    printf("$20 bills:%d\n", amount / 20);
    amount -= (amount / 20) * 20;
    printf("$10 bills:%d\n", amount / 10);
    amount -= (amount / 10) * 10;
    printf("$ 5 bills:%d\n", amount / 5);
    amount -= (amount / 5) * 5;
    printf("$ 1 bills:%d\n", amount);

    return 0;
}
```

7. 编程计算第一、第二、第三个月还贷后剩余的贷款金额：

```
Enter amount of loan: 20000.00
Enter interest rate: 6.0
Enter monthly payment: 386.66
Balance remaining after first payment: $19713.34 
Balance remaining after second payment: $19425.25 
Balance remaining after third payment: $19135.71 
```

在显示每次还款后的余额时保留两位小数。提示：每个月的贷款余额减去还款金额后，还需要加上贷款余额与月利率的乘积。月利率的计算方法是把用户输入的利率转换成百分数再除以 12。

**ANS:**

```c
#include<stdio.h>
int main(void)
{
    float loan = 0.0f, rate = 0.0f, payment = 0.0f, left_payment = 0.0f;
    float first = 0.0f, second = 0.0f, third = 0.0f;
    printf("Enter amount of loan:");
    scanf("%f", &loan);
    printf("Enter interest rate:");
    scanf("%f", &rate);
    printf("Enter monthly payment:");
    scanf("%f", &payment);

    first = loan * (1.0 + (rate / 1200)) - payment;
    second = first * (1.0 + (rate / 1200)) - payment;
    third = second * (1.0 + (rate / 1200)) - payment;
    printf("Balance remaining after first payment:%.2f\n", first);
    printf("Balance remaining after second payment:%.2f\n", second);
    printf("Balance remaining after third payment:%.2f\n", third);

    return 0;
}
```

## 第三章 格式化输入/输出

### 练习题

1. 下面的 printf 函数调用产生的输出分别是什么？

```
(a) printf("%6d,%4d", 86, 1040);
(b) printf("%12.5e", 30.253);
(c) printf("%.4f", 83.162);
(d) printf("%-6.2g", .0000009979);
```

```C
#include<stdio.h>
int main(void)
{
	printf("%6d,%4d\n", 86, 1040);
	printf("%12.5e\n", 30.253);
	printf("%.4f\n", 83.162);
	printf("%-6.2g\n", .0000009979);
  
  return 0;
}
```

输出为：

```
    86,1040
 3.02530e+01
83.1620
1e-06
```

2. 编写 printf 函数调用，以下列格式显示 float 型变量 x。

```
(a) 指数表示形式，栏宽 8，左对齐，小数点后保留 1 位数字。
(b) 指数表示形式，栏宽 10，右对齐，小数点后保留 6 位数字。
(c) 定点十进制表示形式，栏宽 8，左对齐，小数点后保留 3 位数字。
(d) 定点十进制表示形式，栏宽 6，右对齐，小数点后无数字。
```

```C
(a)printf("%-8.1e",x);
(b)printf("%10.6e",x);
(c)printf("%-8.3f",x);
(d)printf("%6.f",x);
```

默认情况下printf的输出是右对齐的，%m.pX的的m就是栏宽，也就是输出的总字符数。

3. 说明下列每对 scanf 格式串是否等价？如果不等价，请指出它们的差异。

```
(a) "%d"与" %d"。
(b) "%d-%d-%d"与"%d -%d -%d"。
(c) "%f"与"%f "。
(d) "%f,%f"与"%f, %f"。
```

```
(a)等价。scanf在搜索整数的时候会忽略掉前面一个或多个的空格，所以对于任意的输入，二者等价。
(b)不等价。根据普通字符'-'左右是否有空格一共可分为四种类型的输入：
   1. 1·-·2·-·3
   2. 1·-2·-3
   3. 1-·2-·3
   4. 1-2-3
   对于格式串"%d-%d-%d"来说只有3、4可以接收，但是对于格式串"%d -%d -%d"来说四种类型都可以接收，因此二者并不是对于任意输入都有相同的输出结果，二者并不等价。
(c)等价。对于任意的输入不影响接收到的float类型数据，但是需要注意转换说明后的空格会导致scanf一直在等待下一个非空的字符而一直等待不退出。
(d)等价。道理同(b)，二者都是能够接收3、4类型的输入。
```

*4. 假设 scanf 函数调用的格式如下：`scanf("%d%f%d", &i, &x, &j);` 如果用户输入3 5 6 调用执行后，变量 i、x 和 j 的值分别是多少？（假设变量 i 和变量 j 都是 int 型，变量 x 是 float型。）

```C
#include<stdio.h>
int main(void)
{
  int i, j;
  float x;
	printf("Enter three number: ");
	scanf("%d%f%d", &i, &x, &j);
	printf("%d\n%f\n%d\n", i, x, j);
  
  return 0;
}
```

输出：

```
Enter three number: 3 5 6
3
5.000000
6
```

*5. 假设 scanf 函数调用的格式如下：`scanf("%f%d%f", &x, &i, &y);` 如果用户输入3 45.6 789 调用执行后，变量 x、i 和 y 的值分别是多少？（假设变量 x 和变量 y 都是 float 型，变量 i 是 int型。）

```c
#include<stdio.h>
int main(void)
{
  int i;
  float x, y;
	printf("Enter three number: ");
	scanf("%f%d%f", &x, &i, &y);
	printf("%f\n%i\n%f\n", x, i, y);
  
  return 0;
}
```

输出：

```
Enter three number: 3 45.6 789
3.000000
45
0.600000
```

6. 指出如何修改 3.2 节中的 addfrac.c 程序，使用户可以输入在字符/的前后都有空格的分数。

```C
#include <stdio.h>

int main(void)
{
  int num1, denom1, num2, denom2, result_num, result_denom;

  printf("Enter first fraction: ");
  scanf("%d/%d", &num1, &denom1);

  printf("Enter second fraction: ");
  // 在scanf的格式串中'/'的左右两边增加空格即可，其中前面的空格是必须的，后面的是可选的。
  // 因为格式串中一个空格可以匹配输入任意数量的空格，包括零个。
  // scanf("%d /%d", &i, &j);
  // scanf("%d / %d", &i, &j);
  scanf("%d/%d", &num2, &denom2);

  result_num = num1 * denom2 + num2 * denom1;
  result_denom = denom1 * denom2;
  printf("The sum is %d/%d\n", result_num, result_denom);

  return 0;
}
```

```
*如果想在scanf普通字符前后都能够输入任意的空格就写成形如：
scanf("%d /%d", &i, &j);
scanf("%d / %d", &i, &j);
```

### 编程题

1. 编写一个程序，以月/日/年（即 *mm/dd/yy*）的格式接受用户输入的日期信息，并以年月日（即*yyyymmdd*）的格式将其显示出来：

```
Enter a date (mm/dd/yyyy): 2/17/2011
You entered the date 20110217
```

**ANS:**

```C
#include<stdio.h>
int main(void)
{
    int day = 0, month = 0, year = 0;
    printf("Enter a date (mm/dd/yyyy):");
    scanf("%2d/%2d/%4d", &day, &month, &year);
    
    printf("You entered the date %4d%2d%.2d\n", year, month, day);
    return 0;
}
```

2. 编写一个程序，对用户输入的产品信息进行格式化。程序会话应类似下面这样：

```
Enter item number: 583
Enter unit price: 13.5
Enter purchase date (mm/dd/yyyy): 10/24/2010
Item Unit Purchase 
Price Date 
583 $ 13.50 10/24/2010 
```

其中，产品编号和日期项采用左对齐方式，单位价格采用右对齐方式，允许美元金额最大取值为9999.99。提示：各个列使用制表符控制。

**ANS:**

```C
#include<stdio.h>
#include<stdlib.h>
int main(void)
{
    int number, day, month, year;
    float price;
    printf("Enter item number:");
    scanf("%d", &number);
    printf("Enter unit price:");
    scanf("%f", &price);
    printf("Enter purchase date (mm/dd/yyyy):");
    scanf("%d/%d/%d", &month, &day, &year);

    printf("Item\t\tUnit\t\tPurchase\n");
    printf("\t\tPrice\t\tDate\n");
    printf("%d\t\t$%7.2f\t%.2d\\%.2d\\%4d\n", number, price, month, day, year);

    return 0;
}
```

3. 图书用国际标准书号（ISBN）进行标识。2007 年 1 月 1 日之后分配的 ISBN 包含 13 位数字（旧的 ISBN使用 10 位数字），分为 5 组，如 978-0-393-97950-3。第一组（GS1 前缀）目前为 978 或 979。第二组（组标识）指明语言或者原出版国及地区（如 0 和 1 用于讲英语的国家）。第三组（出版商编号）表示出版商（393 是 W. W. Norton 出版社的编号）。第四组（产品编号）是由出版商分配的用于识别具体哪一本书的编号（97950）。ISBN 的末尾是一个校验数字，用于验证前面数字的准确性。编写一个程序来分解用户输入的 ISBN 信息：

```
Enter ISBN: 978-0-393-97950-3
GS1 prefix: 978 
Group identifier: 0 
Publisher code: 393 
Item number: 97950 
Check digit: 3 
```

注意：每组中数字的个数是可变的，不能认为每组的长度都与示例一样。用实际的 ISBN 值（通常放在书的封底和版权页上）测试你编写的程序。

**ANS:**

```C
#include<stdio.h>
int main(void)
{
    int prefix, group, code, number, digit;
    printf("Enter ISBN:");
    scanf("%d-%d-%d-%d-%d", &prefix, &group, &code, &number, &digit);
    printf("GS1 prefix: %d\n", prefix);
    printf("Group identifier: %d\n", group);
    printf("Publisher code: %d\n", code);
    printf("Item number: %d\n", number);
    printf("Check digit: %d\n", digit);

    return 0;
}
```

4. 编写一个程序，提示用户以(xxx) xxx-xxxx 的格式输入电话号码，并以 xxx.xxx.xxxx 的格式显示该号码：

```
Enter phone number [(xxx) xxx-xxxx]: (404) 817-6900
You entered 404.817.6900 
```

**ANS:**

```C
#include<stdio.h>
int main(void)
{
    int number1, number2, number3;
    printf("Enter phone number [(xxx) xxx-xxxx]:");
    scanf("(%d)%d-%d", &number1, &number2, &number3);
    printf("%d.%d.%d\n", number1, number2, number3);

    return 0;
}
```

5. 编写一个程序，要求用户（按任意次序）输入 1~16 的所有整数，然后用 4×4 矩阵的形式将它们显示出来，再计算出每行、每列和每条对角线上的和：

```
Enter the numbers from 1 to 16 in any order: 
16 3 2 13 5 10 11 8 9 6 7 12 4 15 14 1
16 3  2  13 
 5 10 11 8 
 9 6  7  12 
 4 15 14 1 
Row sums: 34 34 34 34 
Column sums: 34 34 34 34 
Diagonal sums: 34 34
```

如果行、列和对角线上的和都一样（如本例所示），则称这些数组成一个幻方（magic square）。这里给出的幻方出现于艺术家和数学家 Albrecht Dürer 创作于 1514 年的一幅画中。（注意，矩阵的最后一行中间的两个数给出了该画的创作年代。）

**ANS:**

```C
#include<stdio.h>
int main(void)
{
    int a11, a12, a13, a14;
    int a21, a22, a23, a24;
    int a31, a32, a33, a34;
    int a41, a42, a43, a44;

    printf("Enter the numbers from 1 to 16 in any order:");
    scanf("%d%d%d%d %d%d%d%d %d%d%d%d %d%d%d%d",
            &a11,&a12,&a13,&a14,
            &a21,&a22,&a23,&a24,
            &a31,&a32,&a33,&a34,
            &a41,&a42,&a43,&a44);

    printf("%d %d %d %d\n", a11, a12, a13, a14);    
    printf("%d %d %d %d\n", a21, a22, a23, a24);    
    printf("%d %d %d %d\n", a31, a32, a33, a34);    
    printf("%d %d %d %d\n", a41, a42, a43, a44);

    printf("Row sums:%d %d %d %d\n", a11 + a12 + a13 + a14,
                                     a21 + a22 + a23 + a24,
                                     a31 + a32 + a33 + a34,
                                     a41 + a42 + a43 + a44);
    printf("Column sums:%d %d %d %d\n", a11 + a21 + a31 + a41,
                                        a12 + a22 + a32 + a42,
                                        a13 + a23 + a33 + a43,
                                        a14 + a24 + a34 + a44);
    printf("Diagonal sums:%d %d\n", a11 + a22 + a33 + a44,
                                     a14 + a23 + a32 + a41);
    return 0;
}
```

6. 修改 3.2 节的 addfrac.c 程序，使用户可以同时输入两个分数，中间用加号隔开：

```
Enter two fractions separated by a plus sign: 5/6+3/4
The sum is 38/24
```

**ANS:**

```C
/* Adds two fractions */ 
#include <stdio.h> 
int main(void) 
{ 
    int num1, denom1, num2, denom2, result_num, result_denom; 
    printf("Enter two fractions separated by a plus sign: "); 
    scanf("%d/%d+%d/%d", &num1, &denom1, &num2, &denom2); 
    result_num = num1 * denom2 + num2 * denom1; 
    result_denom = denom1 * denom2; 
    printf("The sum is %d/%d\n", result_num, result_denom); 
    return 0; 
}
```

## 第四章 表达式

### 练习题

1. 给出下列程序片段的输出结果。假设 i、j 和 k 都是 int 型变量。

```c
(a) i = 5; 
		j = 3; 
		printf("%d %d", i / j, i % j); 
(b) i = 2; 
		j = 3; 
		printf("%d", (i + 10) % j); 
(c) i = 7; 
		j = 8; 
		k = 9; 
		printf("%d", (i + 10) % k / j); 
(d) i = 1; 
		j = 2; 
		k = 3; 
		printf("%d", (i + 5) % (j + 2) / k); 
```

```C
#include<stdio.h>
int main(void)
{
  int i, j, k;
  i = 5; 
  j = 3; 
  printf("%d %d\n", i / j, i % j);
  i = 2; 
  j = 3; 
  printf("%d\n", (i + 10) % j); 
  i = 7; 
  j = 8; 
  k = 9; 
  printf("%d\n", (i + 10) % k / j);
  i = 1; 
  j = 2; 
  k = 3; 
  printf("%d\n", (i + 5) % (j + 2) / k); 
  
  return 0;
}
```

输出：

```
1 2
0
1
0
```

\*2. 如果 i 和 j 都是正整数，(-i) / j 的值和-(i / j)的值是否总一样？验证你的答案。

**ANS：**这个题我是认为出的有问题的，因为如果这两者的值是不相同的，那只能是在C89标准下不同的CPU环境中才能验证，因为C89标准之下在进行除法和取余运算的时候既可能向上舍入也可能向下舍入，但是在C99标准之下都是趋零截尾的，因此在C99标准之下都是相同的。

```
cc -std=<标准> source.c -o output
c89 / c90 : ANSI C 标准（早期版本）
gnu89     : C89 + GNU 扩展
c99       : ISO C99 标准
gnu99     : C99 + GNU 扩展
c11       : ISO C11 标准
gnu11     : C11 + GNU 扩展
```

3. 下列表达式在 C89 中的值是多少？（如果表达式有多个可能的值，都列出来。）

```c
(a) 8 / 5 
(b) -8 / 5 
(c) 8 / -5 
(d) -8 / -5 
```

**ANS：**

```
8 / 5 对于C89为1。
-8 / 5 对于C89既可能是-1也可能是-2，需要视具体的实现。
8 / -5 对于C89既可能是-1也可能是-2，需要视具体的实现。
-8 / -5 对于C89既可能是-1也可能是-2，需要视具体的实现。
纠正：最后一道题写错了，因为负号的优先级是最高的，因此这个相当于是8 / 5因此是确定性的1。
```

```C
#include<stdio.h>
int main(void)
{
  printf("8 / 5 is %d\n", 8 / 5);
  printf("-8 / 5 is %d\n", -8 / 5);
  printf("8 / -5 is %d\n", 8 / -5);
  printf("-8 / -5 is %d\n", -8 / -5);
  
  return 0;
}
```

**输出：**

```
使用的机器环境是MacbookAir M4
Apple clang version 17.0.0 (clang-1700.3.19.1)
Target: arm64-apple-darwin25.0.0
Thread model: posix
InstalledDir: /Library/Developer/CommandLineTools/usr/bin
8 / 5 is 1
-8 / 5 is -1
8 / -5 is -1
-8 / -5 is 1
```

4. 对 C99 重复上题。

**ANS：**

```
8 / 5 对于C99趋向于零截尾，因此是1。
-8 / 5 对于C99趋向于零截尾，因此是-1。
8 / -5 对于C99趋向于零截尾，因此是-1。
-8 / -5 对于C99趋向于零截尾，因此是1。但是注意负号的优先级是最高的，这个相当于是8 / 5。
```

```C
#include<stdio.h>
int main(void)
{
  printf("8 / 5 is %d\n", 8 / 5);
  printf("-8 / 5 is %d\n", -8 / 5);
  printf("8 / -5 is %d\n", 8 / -5);
  printf("-8 / -5 is %d\n", -8 / -5);
  
  return 0;
}
```

**输出：**

```
8 / 5 is 1
-8 / 5 is -1
8 / -5 is -1
-8 / -5 is 1
```

5. 下列表达式在 C89 中的值是多少？（如果表达式有多个可能的值，都列出来。）

```c
(a) 8 % 5 
(b) -8 % 5 
(c) 8 % -5 
(d) -8 % -5 
```

**ANS：**

```
// 答案写错完了
8 % 5 对于C89为3。
-8 % 5 对于C89既可能是-3也可能是3，需要视具体的实现。
8 % -5 对于C89既可能是-3也可能是-3，需要视具体的实现。
-8 % -5 负号的优先级是最高的，因此这个相当于是8 % 5因此对于C89是确定性的3。
```

```C
#include<stdio.h>
int main(void)
{
  printf("8 %% 5 is %d\n", 8 % 5);
  printf("-8 %% 5 is %d\n", -8 % 5);
  printf("8 %% -5 is %d\n", 8 % -5);
  printf("-8 %% -5 is %d\n", -8 % -5);
  
  return 0;
}
```

**输出：**

```
使用的机器环境是MacbookAir M4
Apple clang version 17.0.0 (clang-1700.3.19.1)
Target: arm64-apple-darwin25.0.0
Thread model: posix
InstalledDir: /Library/Developer/CommandLineTools/usr/bin
8 % 5 is 3
-8 % 5 is -3
8 % -5 is 3
-8 % -5 is -3
```

```
更正
在C89标准中，操作数是负数时的除法运算比较容易理解，而操作数是负数时的模运算容易混淆，对此我们可以通过除法进行转换计算。由于C89和C99都要确保（ a / b ）* b + a % b的结果总是等于a，因此我们可以通过除法运算推算出模运算的结果，也就是说a % b == a - （ a / b ）* b，这样更加有利于理解。例如，C89下-9/7的结果可能为-1或者-2 。因此-9%7的值可能是-2或者5。

参考答案
(a) 8 % 5 的运算结果为3，操作数为整数，结果为余数。
(b) -8 % 5 由于在C89下（-8/5）的运算结果为-1或者-2，因此-8%5的运算结果为-3或者2 。
(c) 8 % -5 由于在C89下（8/-5）的运算结果为-1或者-2，因此-8%5的运算结果为-3或者2 。
(d) -8 % -5 C89下（-8/-5）的运算结果为1，因此-8%-5的运算结果为-3 。
```



6. 对 C99 重复上题。

```
#include<stdio.h>
int main(void)
{
  printf("8 %% 5 is %d\n", 8 % 5);
  printf("-8 %% 5 is %d\n", -8 % 5);
  printf("8 %% -5 is %d\n", 8 % -5);
  printf("-8 %% -5 is %d\n", -8 % -5);
  
  return 0;
}
```

```
8 % 5 is 3
-8 % 5 is -3
8 % -5 is 3
-8 % -5 is -3
```

```
在C99标准中，操作数是负数时的除法运算比较容易理解，均是向0取整。此时模运算%的运算结果和运算符和操作数左侧操作数符号相同，可以沿用 a / b ）* b + a % b的结果总是等于a的定义，推测出模运算的结果。
(a) 8 % 5 的运算结果为3，操作数为整数，结果为余数。
(b) -8 % 5 由于在C99下（-8 / 5）的运算结果为-1，因此-8 % 5的运算结果为-3 。
(c) 8 % -5 由于在C99下（8 / -5）的运算结果为-1，因此-8 % 5的运算结果为3
(d) -8 % -5 由于在C99下（-8 / -5）的运算结果为1，因此-8 % 5的运算结果为-3
```

7. 本章计算 UPC 校验位方法的最后几步是：把总的结果减去 1，相减后的结果除以 10 取余数，用 9 减去余数。换成下面的步骤也可以：总的结果除以 10 取余数，用 10 减去余数。这样做为什么可行？

**这道题不会，看的习题解析**

```
该章中的UPC校验方法可以表示为：首先把第1位、第3位、第5位、第7位、第9位和第11位数字相加；然后把第2位、第4位、第6位、第8位和第10位数字相加；接着把第一次加法的结果乘以3，再和第二次加法的结果相加；随后把上述结果减去1；相减后的结果除以10取余数；最后用9减去上一步得到的余数。
检验过程中假设加法运算的结果为total，计算校验位的基本操作步骤可以表示为：9-((total-1)%10)。从公式化简似乎可以得到(10 - total % 10)。但是当我们考虑结果取值范围就会发现，原公式的取值范围是0~9；而化简后公式的取值范围是1~10，即当total为10的整数倍时，两者结果不同。其主要原因是不能将9-((total-1)%10)简单等价于(10 - total % 10)。原算法通过9求补数的方式保证了运算结果0的校验位是0，转换后不能保证该运算结果。

也就是说，修改UPC校验算法为总的结果除以10取余数，用10减去余数的方式与原有方式所生成的校验位在实际应用中可行，但是并不能保证与原有计算方法完全一致。
```

8. 如果把表达式 9 - ((total - 1) % 10)改成(10 - (total % 10)) % 10，upc.c程序是否仍然正确？

**这道题不会，看的习题解析**

```
参考练习题7，UPC校验方法中如果将表达式替换为(10 - (total % 10)) % 10，其运算结果是正确的。先将表达式9 - ((total - 1) % 10)转换成(10 - total % 10)，再对10取模，就可以保证校验位正确地转换。再次取模的目的是按10求补数后，将0的补数转化成最终校验位0 。

也就是说，UPC校验程序使用(10 - (total % 10)) % 10的计算方法可以实现与9 - ((total - 1) % 10)相同的效果，因此是正确的。
```

9. 给出下列程序片段的输出结果。假设 i、j 和 k 都是 int 型变量。

```C
(a) i = 7; 
		j = 8;
		i *= j + 1; 
		printf("%d %d", i, j);
(b) i = j = k = 1;  
		i += j += k; 
		printf("%d %d %d", i, j, k); 
(c) i = 1; 
		j = 2; 
		k = 3; 
		i -= j -= k; 
		printf("%d %d %d", i, j, k); 
(d) i = 2; 
		j = 1; 
		k = 0; 
		i *= j *= k;  
		printf("%d %d %d", i, j, k); 
```

```C
#include<stdio.h>
int main(void)
{
  	int i, j, k;
  	i = 7; 
		j = 8;
		i *= j + 1; 
		printf("%d %d\n", i, j);
		i = j = k = 1;  
		i += j += k; 
		printf("%d %d %d\n", i, j, k); 
		i = 1; 
		j = 2; 
		k = 3; 
		i -= j -= k; 
		printf("%d %d %d\n", i, j, k); 
		i = 2; 
		j = 1; 
		k = 0; 
		i *= j *= k;  
		printf("%d %d %d\n", i, j, k); 
  
  return 0;
}
```

```
63 8
3 2 1
2 -1 3
0 0 0
```

10. 给出下列程序片段的输出结果。假设 i 和 j 都是 int 型变量。

```C
(a) i = 6;  
		j = i += i; 
		printf("%d %d", i, j); 
(b) i = 5; 
		j = (i -= 2) + 1;  
		printf("%d %d", i, j); 
(c) i = 7; 
		j = 6 + (i = 2.5); 
		printf("%d %d", i, j); 
(d) i = 2; 
		j = 8; 
		j = (i = 6) + (j = 3); 
		printf("%d %d", i, j); 
```

```C
#include<stdio.h>
int main(void)
{
  	int i, j;
  	i = 6;  
		j = i += i; 
		printf("%d %d\n", i, j); 
		i = 5; 
		j = (i -= 2) + 1;  
		printf("%d %d\n", i, j); 
		i = 7; 
		j = 6 + (i = 2.5); 
		printf("%d %d\n", i, j); 
		i = 2; 
		j = 8; 
		j = (i = 6) + (j = 3); 
		printf("%d %d\n", i, j); 
  
  	return 0;
}
```

```
12 12
3 4
2.5 8.5 // 这个写错了，注意输出，变量要服从格式符！所以应该是2 8
6 9
```

*11. 给出下列程序片段的输出结果。假设 i、j 和 k 都是 int 型变量。

```C
(a) i = 1; 
		printf("%d ", i++ - 1); 
		printf("%d", i); 
(b) i = 10; 
		j = 5; 
		printf("%d ", i++ - ++j); 
		printf("%d %d", i, j); 
(c) i = 7; 
		j = 8; 	
		printf("%d ", i++ - --j); 
		printf("%d %d", i, j); 
(d) i = 3; 
		j = 4; 
		k = 5; 
		printf("%d ", i++ - j++ + --k); 
		printf("%d %d %d", i, j, k); 
```

```C
#include<stdio.h>
int main(void)
{
		int i, j, k;
		i = 1; 
		printf("%d \n", i++ - 1); 
		printf("%d\n", i); 
		i = 10; 
		j = 5; 
		printf("%d \n", i++ - ++j); 
		printf("%d %d\n", i, j); 
		i = 7; 
		j = 8; 	
		printf("%d \n", i++ - --j); 
		printf("%d %d\n", i, j); 
		i = 3; 
		j = 4; 
		k = 5; 
		printf("%d \n", i++ - j++ + --k); 
		printf("%d %d %d\n", i, j, k); 
		
		return 0;
}
```

```
0
2
4
11 6
0
8 7
3
4 5 4
```

12. 给出下列程序片段的输出结果。假设 i 和 j 都是 int 型变量。

```C
(a) i = 5; 
		j = ++i * 3 – 2; 
		printf("%d %d", i, j); 
(b) i = 5; 
		j = 3 – 2 * i++; 
		printf("%d %d", i, j);
(c) i = 7; 
		j = 3 * i-- + 2; 
		printf("%d %d", i, j); 
(d) i = 7; 
		j = 3 + --i * 2; 
		printf("%d %d", i, j); 
```

```C
#include<stdio.h>
int main(void)
{
	int i, j;
  i = 5; 
  j = ++i * 3 - 2; 
  printf("%d %d\n", i, j);
  i = 5; 
  j = 3 - 2 * i++; 
  printf("%d %d\n", i, j);
  i = 7; 
  j = 3 * i-- + 2; 
  printf("%d %d\n", i, j);
  i = 7; 
  j = 3 + --i * 2; 
  printf("%d %d\n", i, j);
  
  return 0;
}
```

```
6 16
6 -7
6 23
6 15
```

13. 表达式++i 和 i++中只有一个是与表达式(i += 1)完全相同的，是哪一个呢？验证你的答案。


```
// 表达式 ++i和(i += 1)的值相同，因为++i表达式的值为i+1，和(i += 1)相同，但i++表达式的值是1。
```

```C
#include<stdio.h>
int main(void)
{
	int i = 1;
  printf("++i = %d", ++i);
  i = 1;
  printf("i++ = %d", i++);
  i = 1;
  printf("(i += 1) = %d", (i += 1);
  
  return 0;
}
```

```
++i = 2
i++ = 1
(i += 1) = 2
```

14. 添加圆括号，说明 C 语言编译器如何解释下列表达式。

```C
(a) a * b – c * d + e 
(b) a / b % c / d
(c) – a – b + c - + d
(d) a * - b / c - d
```

```
(a) (((a * b) – (c * d)) + e) 
(b) (((a / b) % c) / d)
(c) ((((– a) – b) + c) - (+ d))
(d) (((a * (- b)) / c) - d)
```

15. 给出下列每条表达式语句执行以后 i 和 j 的值。（假设 i 的初始值为 1，j 的初始值为 2。）

```C
(a) i += j; 
(b) i--;
(c) i * j / i; 
(d) i % ++j;
```

```C
#include<stdio.h>
int main(void)
{
	int i, j;
	i = 1, j = 2;
  printf("i += j = %d\n", i += j);
  printf("i-- = %d\n", i--);
  printf("i * j / i = %d\n", i * j / i);
  printf("i %% ++j = %d\n", i % ++j);
  
  return 0;
}
```

```
3
2 // 这个地方是一个陷阱，我写成了i的值，其实要写出表达式的值，i的值在表达式的值算出之后才会产生副作用。
2
2

电脑程序输出结果
i += j = 3
i-- = 3
i * j / i = 2
i % ++j = 2
```

### 编程题

1. 编写一个程序，要求用户输入一个两位数，然后按数位的逆序打印出这个数。程序会话应类似下面这样：

```
Enter a two-digit number: 28
The reversal is: 82 
```

用%d 读入两位数，然后分解成两个数字。提示：如果 n 是整数，那么 n % 10 是个位数，而 n / 10则是移除个位数后剩下的数。

**ANS:**

```c
#include<stdio.h>
int main(void)
{
    int number, first, second;
    printf("Enter a two-digit number:");
    scanf("%d", &number);
    first = number % 10;
    second = (number / 10) % 10;

    printf("The reversal is: %d\n", first * 10 + second);
    return 0;
}
```

2. 扩展上题中的程序，使其可以处理 3 位数。

**ANS:**

```c
#include<stdio.h>
int main(void)
{
    int number, first, second, third;
    printf("Enter a two-digit number:");
    scanf("%d", &number);
    first = number % 10;
    second = (number / 10) % 10;
    third = number / 10 / 10;

    printf("The reversal is: %d\n", first * 100 + second * 10 + third);
    return 0;
}
```

3. 重新编写编程题2中的程序，使新程序不需要利用算术分割就可以显示出3位数的逆序。提示：参考4.1 节的 upc.c 程序。

**ANS:**

```C
#include<stdio.h>
int main(void)
{
    int number, first, second, third;
    printf("Enter a two-digit number: ");
    scanf("%1d%1d%1d", &third, &second, &first);

    printf("The reversal is: %1d%1d%1d\n", first, second, third);
    return 0;
}
```

4. 编写一个程序，读入用户输入的整数并按八进制（基数为 8）显示出来：

```
Enter a number between 0 and 32767: 1953
In octal, your number is: 03641 
```

输出应为 5 位数，即便不需要这么多数位也要如此。提示：要把一个数转换成八进制，首先将其除以 8，所得的余数是八进制数的最后一位（本例中为 1）；然后把原始的数除以 8，对除法结果重复上述过程，得到倒数第二位。（如第 7 章所示，printf 可以显示八进制的数，所以这个程序实际上有更简单的写法。）

**ANS:**

```c
#include<stdio.h>
int main(void)
{
    int number, o1, o2, o3, o4, o5;
    printf("Enter a number between 0 and 32767: ");
    scanf("%d", &number);

    o5 = number % 8;
    number /= 8;
    o4 = number % 8;
    number /= 8;
    o3 = number % 8;
    number /= 8;
    o2 = number % 8;
    number /= 8;
    o1 = number % 8;
    number /= 8;

    printf("In octal, your number is: %1d%1d%1d%1d%1d\n", o1, o2, o3, o4, o5);

    return 0;
}
```

5. 重写 4.1 节的 upc.c 程序，使用户可以一次输入 11 位数字，而不用先输入 1 位，再输入 5 位，最后再输入 5 位。

```
Enter the first 11 digits of a UPC: 01380015173
Check digit: 5 
```

**ANS:**

```c
#include <stdio.h>

int main(void)
{
    int d, i1, i2, i3, i4, i5, j1, j2, j3, j4, j5,
      first_sum, second_sum, total;

    printf("Enter the first 11 digits of a UPC: ");
    scanf("%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d", &d, &i1, &i2, &i3, &i4, &i5,
                                            &j1, &j2, &j3, &j4, &j5);
    first_sum = d + i2 + i4 + j1 + j3 + j5;
    second_sum = i1 + i3 + i5 + j2 + j4;
    total = 3 * first_sum + second_sum;

    printf("Check digit: %d\n", 9 - ((total - 1) % 10));

    return 0;
}
```

6. 欧洲国家及地区不使用北美的 12 位通用产品代码（UPC），而使用 13 位的欧洲商品编码（European Article Number, EAN）。跟 UPC 一样，每个 EAN 码的最后也有一个校验位。计算校验位的方法也类似：首先把第 2位、第 4位、第 6位、第 8位、第 10位和第 12位数字相加；然后把第 1位、第 3位、第 5 位、第 7 位、第 9 位和第 11位数字相加；接着把第一次加法的结果乘以 3，再和第二次加法的结果相加；随后，再把上述结果减去 1；相减后的结果除以 10 取余数；最后用 9 减去上一步骤中得到的余数。

   以 Güllüoglu 牌土耳其软糖（开心果和椰子口味）为例，其 EAN 码为 8691484260008。第一个和为6+1+8+2+0+0=17，第二个和为 8+9+4+4+6+0=31。第一个和乘以 3 再加上第二个和得到 82，减 1 得到 81。这个结果除以 10 的余数是 1，再用 9 减去余数得到 8，与原始编码的最后一位一致。请修改

​	4.1 节的 upc.c 程序以计算 EAN 的校验位。用户把 EAN 的前 12 位当作一个数输入：

```
Enter the first 12 digits of an EAN: 869148426000
Check digit: 8
```

**ANS:**

```c
#include <stdio.h>

int main(void)
{
    int d, i1, i2, i3, i4, i5, j1, j2, j3, j4, j5, j6,
      first_sum, second_sum, total;

    printf("Enter the first 11 digits of an EAN: ");
    scanf("%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d", &d, &i1, &i2, &i3, &i4, &i5,
                                            &j1, &j2, &j3, &j4, &j5, &j6);
    first_sum = d + i2 + i4 + j1 + j3 + j5;
    second_sum = i1 + i3 + i5 + j2 + j4 + j6;
    total =first_sum + second_sum * 3;

    printf("Check digit: %d\n", 9 - ((total - 1) % 10));

    return 0;
}
```

## 第五章 选择语句

### 练习题

1. 下列代码片段给出了关系运算符和判等运算符的示例。假设 i、j 和 k 都是 int 型变量，请给出每道题的输出结果。

```C
(a) i = 2; 
		j = 3; 
		k = i * j == 6; 
		printf("%d", k); 
(b) i = 5; 
		j = 10; 
		k = 1; 
		printf("%d", k > i < j); 
(c) i = 3; 
		j = 2; 
		k = 1; 
		printf("%d", i < j == j < k); 
(d) i = 3; 
		j = 4; 
		k = 5; 
		printf("%d", i % j + i < k); 
```

```C
#include<stdio.h>
int main(void)
{
    int i, j, k;
    i = 2; 
    j = 3; 
    k = i * j == 6; 
    printf("%d\n", k); 
    i = 5; 
    j = 10; 
    k = 1; 
    printf("%d\n", k > i < j); 
    i = 3; 
    j = 2; 
    k = 1; 
    printf("%d\n", i < j == j < k); 
    i = 3; 
    j = 4; 
    k = 5; 
    printf("%d\n", i % j + i < k); 

    return 0;
}
```

```
1
1
1
0
```

2.下列代码片段给出了逻辑运算符的示例。假设 i、j 和 k 都是 int 型变量，请给出每道题的输出结果。

```C
(a) i = 10; 
		j = 5; 
		printf("%d", !i < j); 
(b) i = 2; 
		j = 1; 
		printf("%d", !!i + !j); 
(c) i = 5; 
		j = 0; 
		k = -5; 
		printf("%d", i && j || k); 
(d) i = 1;
		j = 2; 
		k = 3; 
		printf("%d", i < j || k); 
```

```C
#include<stdio.h>
int main(void)
{
    int i, j, k;
    i = 10; 
    j = 5; 
    printf("%d\n", !i < j); 
    i = 2; 
    j = 1; 
    printf("%d\n", !!i + !j); 
    i = 5; 
    j = 0; 
    k = -5; 
    printf("%d\n", i && j || k); 
    i = 1;
    j = 2; 
    k = 3; 
    printf("%d\n", i < j || k);

    return 0;
}
```

```
1
1
1
1
```

*3. 下列代码片段给出了逻辑表达式的短路行为的示例。假设 i、j 和 k 都是 int 型变量，请给出每道题的输出结果。

```C
(a) i = 3; 
		j = 4; 
		k = 5; 
		printf("%d", i < j || ++j < k); 
		printf("%d %d %d", i, j, k);
(b) i = 7; 
		j = 8; 
		k = 9; 
		printf("%d", i – 7 && j++ < k); 
		printf("%d %d %d", i, j, k); 
(c) i = 7; 
		j = 8; 
		k = 9; 
		printf("%d", (i = j) || (j = k)); 
		printf("%d %d %d", i, j, k); 
(d) i = 1; 
		j = 1; 
		k = 1; 
		printf("%d", ++i || ++j && ++k); 
		printf("%d %d %d", i, j, k); 
```

```c
#include<stdio.h>
int main(void)
{
    int i, j, k; 
    i = 3; 
    j = 4; 
    k = 5; 
    printf("%d\n", i < j || ++j < k); 
    printf("%d %d %d\n", i, j, k);
    i = 7; 
    j = 8; 
    k = 9; 
    printf("%d\n", i - 7 && j++ < k); 
    printf("%d %d %d\n", i, j, k); 
    i = 7; 
    j = 8; 
    k = 9; 
    printf("%d\n", (i = j) || (j = k)); 
    printf("%d %d %d\n", i, j, k); 
    i = 1; 
    j = 1; 
    k = 1; 
    printf("%d\n", ++i || ++j && ++k); 
    printf("%d %d %d\n", i, j, k); 

    return 0;
}
```

```
1
3 4 5
0
7 8 9
1
8 8 9
1
2 1 1
```

*4. 编写一个表达式，要求这个表达式根据 i 小于、等于、大于 j 这 3 种情况，分别取值为-1、0、+1。

```c
#include<stdio.h>
int main(void)
{
    int i, j;
    printf("Please enter i:\n");
    scanf("%d %d", &i, &j);

  	// 一共想到了两种写法，一种就是简单的级联。
    (i < j)? (-1) : (i == j ? 0: 1);
  	// 另一种就是通过对非零值取反再取反会得到1或者0的特性。
    i >= j? !!(i - j) : -1;

    return 0;
}
```

```
参考答案：
i > j ? 1 : ( i < j ? - 1 : 0)
```

*5. 下面的 if 语句在 C 语言中是否合法？

```
if (n >= 1 <= 10) 
printf("n is between 1 and 10\n"); 
```

如果合法，那么当 n 等于 0 时会发生什么？

```C
// 程序是合法的但不是合理的，无法得到字面的程序期望。
// 如果为了表示取值在1~10之间，可以使用表达式n>=0 && n<=10的形式。
#include<stdio.h>
int main(void)
{
    int n = 0;
    if(n >= 1 <= 10)
    printf("n is between 1 and 10\n");

    return 0;
}
```

```
n is between 1 and 10
```

*6. 下面的 if 语句在 C 语言中是否合法？

```
if (n == 1 - 10) 
printf("n is between 1 and 10\n"); 
```

如果合法，那么当 n 等于 5 时会发生什么？

```C
// 程序是合法的但不是合理的，无法得到字面的程序期望。
#include<stdio.h>
int main(void)
{
    int n = 5;
    if (n == 1 - 10) 
        printf("n is between 1 and 10\n"); 

    return 0;
}
```

**没有任何的输出**

7. 如果 i 的值为 17，下面的语句显示的结果是什么？如果 i 的值为-17，下面的语句显示的结果又是什么？

`printf("%d\n", i >= 0 ? i : -i);` 

```C
#include<stdio.h>
int main(void)
{
    int i = 17;
    printf("%d\n", i >= 0 ? i : -i);
    i = -17;
    printf("%d\n", i >= 0 ? i : -i);

    return 0;
}
```

```
17
17
```

8. 下面的 if 语句不需要这么复杂，请尽可能地加以简化。

```C
if (age >= 13) 
  if (age <= 19) 
    teenager = true; 
	else 
  	teenager = false; 
else if (age < 13) 
  teenager = false; 
```

```c
#include<stdio.h>
int main(void)
{
    if (13 <= age && age <= 19) 
        teenager = true; 
		else 
  	    teenager = false; 

    return 0;
}
```

9. 下面两个 if 语句是否等价？如果不等价，为什么？

```C
if (score >= 90) 					
	printf("A");  
else if (score >= 80) 
	printf("B");  
else if (score >= 70)
	printf("C"); 
else if (score >= 60) 
	printf("D"); 
else 
  printf("F"); 
```

```c
if (score < 60) 
  printf("F");
else if (score < 70) 
  printf("D"); 
else if (score < 80) 
  printf("C"); 
else if (score < 90) 
  printf("B"); 
else printf("A");
```

这两个是等价的

**答案解析**
两条if级联语句的输出结果相同，但是不能认为它们是等价的，因为两者的逻辑判断顺序和结构不同，只是一种算法的两种实现。

```c
#include <stdio.h>
int main(void)
{
    int score;
    if (score >= 90)
        printf("A");
    else if (score >= 80)
        printf("B");
    else if (score >= 70)
        printf("C");
    else if (score >= 60)
        printf("D");
    else
        printf("F");

    if (score < 60)
        printf("F");
    else if (score < 70)
        printf("D");
    else if (score < 80)
        printf("C");
    else if (score < 90)
        printf("B");
    else
        printf("A");
        
    return 0;
}
```

5.3 节

*10. 下面的代码片段的输出结果是什么？（假设 i 是整型变量。）

```C
i = 1; 
switch (i % 3) { 
 case 0: printf("zero"); 
 case 1: printf("one"); 
 case 2: printf("two"); 
} 
```

```c
#include <stdio.h>
int main(void)
{
    i = 1;
    switch (i % 3)
    {
    case 0:
        printf("zero");
    case 1:
        printf("one");
    case 2:
        printf("two");
    }
    return 0;
}
```

```
onetwo
```

11. 表 5-5 给出了美国佐治亚州的电话区号，以及每个区号所对应地区最大的城市。

**表 5-5 美国佐治亚州电话区号及对应的主要城市**

| 区号 | 主要城市 |
| :--: | :------: |
| 229  |  Albany  |
| 404  | Atlanta  |
| 470  | Atlanta  |
| 478  |  Macon   |
| 678  | Atlanta  |
| 706  | Columbus |
| 762  | Columbus |
| 770  | Atlanta  |
| 912  | Savannah |

编写一个 switch 语句，其控制表达式是变量 area_code。如果 area_code 的值在表中，switch 语句打印出相应的城市名；否则 switch 语句显示消息“Area code not recognized”。使用 5.3 节讨论的方法，使 switch 语句尽可能地简单。

```C
#include <stdio.h>
int main(void)
{
    int area_code;
    printf("Please enter the area code: ");
    scanf("%d", &area_code);

    switch (area_code)
    {
    case 229:
        printf("Albany");
        break;
    case 404:
    case 470:
    case 678:
    case 770:
        printf("Atlanta");
        break;
    case 478:
        printf("Macon");
        break;
    case 706:
    case 762:
        printf("Columbus");
        break;
    case 912:
        printf("Savannah");
        break;
    default:
        printf("Area code not recognized");
        break;
    }
    return 0;
}
```



### 编程题

```shell
for i in {1..11}; do touch code_5_$i.c; done
```



1. 编写一个程序，确定一个数的位数：

```
Enter a number: 374
The number 374 has 3 digits
```

假设输入的数最多不超过 4 位。提示：利用 if 语句进行数的判定。例如，如果数在 0 和 9 之间，那么位数为 1；如果数在 10 和 99 之间，那么位数为 2。

```C
#include<stdio.h>
int main(void)
{
    int number;
    printf("Enter a number:");
    scanf("%d", &number);

    if(number > 999)
        printf("4\n");
    else if(number > 99)
        printf("3\n");
    else if(number > 9)
        printf("2\n");
    else
        printf("1\n");

    return 0;
}
```

2. 编写一个程序，要求用户输入 24 小时制的时间，然后显示 12 小时制的格式：

```
Enter a 24-hour time: 21:11
Equivalent 12-hour time: 9:11 PM 
```

注意不要把 12:00 显示成 0:00。

```
#include<stdio.h>
int main(void)
{
    int hour, min;
    printf("Enter a 24-hour time:");
    scanf("%d : %d" ,&hour ,&min);

    if(hour <= 12)
        printf("Equivalent 12-hour time:%d:%.2d AM\n", hour, min);
    else if(hour > 12)
        printf("Equivalent 12-hour time:%d:%.2d PM\n", hour - 12, min);

    return 0;
}
```

3. 修改 5.2 节的 broker.c 程序，做出下面两种改变。
   (a) 不再直接输入交易额，而是要求用户输入股票的数量和每股的价格。
   (b) 增加语句用来计算经纪人竞争对手的佣金（少于 2000 股时佣金为每股 33 美元+3 美分，2000 股或更多股时佣金为每股 33 美元+2美分）。在显示原有经纪人佣金的同时，也显示出竞争对手的佣金。

```C
#include <stdio.h>

int main(void)
{
    float stock, number;
    float commission, competitor_comission, value;

    printf("Enter value of trade: ");
    //scanf("%f", &value);
    scanf("%f %f", &stock, &number);
    value = stock * number;

    if (value < 2500.00f)
        commission = 30.00f + .017f * value;
    else if (value < 6250.00f)
        commission = 56.00f + .0066f * value;
    else if (value < 20000.00f)
        commission = 76.00f + .0034f * value;
    else if (value < 50000.00f)
        commission = 100.00f + .0022f * value;
    else if (value < 500000.00f)
        commission = 155.00f + .0011f * value;
    else
        commission = 255.00f + .0009f * value;

    if (commission < 39.00f)
        commission = 39.00f;

    if(stock < 2000)
        competitor_comission = stock * 0.03 + 33;
    else 
        competitor_comission = stock * 0.02 + 33;
    

    printf("Commission: $%.2f\t", commission);
    printf("Competitor: $%.2f\n", competitor_comission);

    return 0;
}
```

3. 表 5-6 中展示了用于测量风力的蒲福风级的简化版本。

**表 5-7  简化的蒲福风级**

| 速度（海里 / 小时） |       描述        |
| :-----------------: | :---------------: |
|       小于 1        |   Calm（无风）    |
|        1 ~ 3        | Light air（轻风） |
|       4 ~ 27        |  Breeze（微风）   |
|       28 ~ 47       |   Gale（大风）    |
|       48 ~ 63       |   Storm（暴风）   |
|       大于 63       | Hurricane（飓风） |

编写一个程序，要求用户输入风速（海里/小时），然后显示相应的描述。

```C
#include<stdio.h>
int main(void)
{
    int speed;
    printf("Enter the speed:");
    scanf("%d", &speed);

    if(speed < 1)
        printf("Calm\n");
    else if(1 <= speed && speed <= 3)
        printf("Light Air\n");
    else if(4 <= speed && speed <= 27)
        printf("Breeze\n");
    else if(28 <= speed && speed <= 47)
        printf("Gale\n");
    else if(48 <= speed && speed <= 63)
        printf("Storm\n");
    else if(speed > 63)
        printf("Hurricane\n");

    return 0;
}
```

5. 在美国的某个州，单身居民需要缴纳表 5-7 中列出的所得税。

**表 5-7 美国某州单身居民个人所得税缴纳标准**

| 收入（美元） |             税金计算方式              |
| ------------ | :-----------------------------------: |
| 未超过 750   |               收入的 1%               |
| 750 ～ 2250  |  7.50 美元 + 超出 750 美元部分的 2%   |
| 2250 ～ 3750 | 37.50 美元 + 超出 2250 美元部分的 3%  |
| 3750 ～ 5250 | 82.50 美元 + 超出 3750 美元部分的 4%  |
| 5250 ～ 7000 | 142.50 美元 + 超出 5250 美元部分的 5% |
| 超过 7000    | 230.00 美元 + 超出 7000 美元部分的 6% |

编写一个程序，要求用户输入应纳税所得额，然后显示税金。

```C
#include<stdio.h>
int main(void)
{
    int income;
    float tax;
    printf("Enter your income:");
    scanf("%d", &income);

  
  	// 同样是犯了没有优化判断结构的问题。
    if(income < 750)
        printf("The tax is:%.2f\n", income * 0.01f);
    else if(750 <= income && income <= 2250)
        printf("The tax is:%.2f\n", (income - 750) * 0.02 + 7.5f);
    else if(2250 <= income && income <= 3750)
        printf("The tax is:%.2f\n", (income - 2250) * 0.03 + 37.5f);
    else if(3750 <= income && income <= 5250)
        printf("The tax is:%.2f\n", (income - 3750) * 0.04 + 82.5f);
    else if(5250 <= income && income <= 7000)
        printf("The tax is:%.2f\n", (income - 5250) * 0.05 + 142.5f);
    else if(income > 7000)
        printf("The tax is:%.2f\n", (income - 7000) * 0.06 + 230.0f);


    return 0;
}
```

```C
#include <stdio.h>

int main(void)
{
    int income;
    float tax;

    printf("Enter your income: ");
    scanf("%d", &income);

    if (income < 750)
        tax = income * 0.01f;
    else if (income <= 2250)
        tax = 7.50f + (income - 750) * 0.02f;
    else if (income <= 3750)
        tax = 37.50f + (income - 2250) * 0.03f;
    else if (income <= 5250)
        tax = 82.50f + (income - 3750) * 0.04f;
    else if (income <= 7000)
        tax = 142.50f + (income - 5250) * 0.05f;
    else
        tax = 230.00f + (income - 7000) * 0.06f; 

    printf("The tax is: %.2f\n", tax);

    return 0;
}

```

6. 修改 4.1 节的 upc.c 程序，使其可以检测 UPC 的有效性。在用户输入 UPC 后，程序将显示 VALID 或NOT VALID。


```C
#include <stdio.h>

int main(void)
{
    int d, i1, i2, i3, i4, i5, j1, j2, j3, j4, j5,
        first_sum, second_sum, total, check_number;

    printf("Enter the first (single) digit: ");
    scanf("%1d", &d);
    printf("Enter first group of five digits: ");
    scanf("%1d%1d%1d%1d%1d", &i1, &i2, &i3, &i4, &i5);
    printf("Enter second group of five digits: ");
    scanf("%1d%1d%1d%1d%1d", &j1, &j2, &j3, &j4, &j5);
    printf("Enter the check number: ");
    scanf("%1d", &check_number);

    first_sum = d + i2 + i4 + j1 + j3 + j5;
    second_sum = i1 + i3 + i5 + j2 + j4;
    total = 3 * first_sum + second_sum;

    if ((9 - ((total - 1) % 10)) == check_number)
        printf("VALID\n");
    else 
        printf("NOT VALID\n");

    printf("Check digit: %d\n", 9 - ((total - 1) % 10));

    return 0;
}
```

6. 编写一个程序，从用户输入的 4 个整数中找出最大值和最小值：

```
Enter four integers: 21 43 10 35
Largest: 43 
Smallest: 10 
```

 要求尽可能少用 if 语句。提示：4 条 if 语句就足够了。

```c
// 我以为我写的不是最优解，但是网上的更加复杂，我的想法就是单次扫描即可完成任务。
#include<stdio.h>
int main(void)
{
    int i, j, k, l, max, min;
    printf("Enter four integers:");
    scanf("%d%d%d%d", &i, &j, &k, &l);

    if(i > j)
    {
        max = i;
        min = j;
    }
    else 
    {
        max = j;
        min = i;
    }
    if(max < k)
        max = k;
    else if(min > k)
        min = k;

    if(max < l)
        max = l;
    else if(min > l)
        min = l;
    
    printf("Largest:%d\n", max);
    printf("Smallest:%d\n", min);

    return 0;
}
```

8. 表 5-8 给出了从一个城市到另一个城市的每日航班信息。

**表 5-8  每日航班信息**

|  起飞时间  |  抵达时间  |
| :--------: | :--------: |
| 8:00 a.m.  | 10:16 a.m. |
| 9:43 a.m.  | 11:52 a.m. |
| 11:19 a.m. | 1:31 p.m.  |
| 12:47 p.m. | 3:00 p.m.  |
| 2:00 p.m.  | 4:08 p.m.  |
| 3:45 p.m.  | 5:55 p.m.  |
| 7:00 p.m.  | 9:20 p.m.  |
| 9:45 p.m.  | 11:58 p.m. |

编写一个程序，要求用户输入一个时间（用 24 小时制的时分表示）。程序选择起飞时间与用户输入最接近的航班，显示出相应的起飞时间和抵达时间。

```
Enter a 24-hour time: 13:15
Closest departure time is 12:47 p.m., arriving at 3:00 p.m. 
```

提示：把输入用从午夜开始的分钟数表示。将这个时间与表格里（也用从午夜开始的分钟数表示）的起飞时间相比。例如，13:15 从午夜开始是 13×60+15 = 795 分钟，与下午 12:47（从午夜开始是767 分钟）最接近。

```c
#include<stdio.h>
int main(void)
{
    int hour, min, cmp;
    int flight1, flight2, flight3, flight4, flight5, flight6, flight7, flight8;
    printf("Enter a 24-hour time: ");
    scanf("%d : %d", &hour, &min);

    flight1 = 8 * 60;
    flight2 = 9 * 60 + 43;
    flight3 = 11 * 60 + 19;
    flight4 = 12 * 60 + 47;
    flight5 = 14 * 60;
    flight6 = 15 * 60 + 45;
    flight7 = 19 * 60;
    flight8 = 21 * 60 + 45;

    cmp = hour * 60 + min;
    if(cmp < (flight1 + flight2) / 2) // 小于第一个航班，那么第一个航班就是最接近的。
        printf("Closest departure time is 8:00 a.m., arriving at 10:16 a.m.\n");
    else if(cmp < (flight2 + flight3) / 2)
         printf("Closest departure time is 9:43 a.m., arriving at 11:52 a.m.\n");
    else if(cmp < (flight3 + flight4) / 2)
         printf("Closest departure time is 11:19 a.m., arriving at 1:31 p.m.\n");
    else if(cmp < (flight4 + flight5) / 2)
         printf("Closest departure time is 12.47 p.m., arriving at 3:00 p.m.\n");
    else if(cmp < (flight5 + flight6) / 2)                  
         printf("Closest departure time is 2:00 p.m., arriving at 4:08 p.m.\n");
    else if(cmp < (flight6 + flight7) / 2)
        printf("Closest departure time is 3:45 p.m., arriving at 5:55 p.m.\n");
    else if(cmp <(flight7 + flight8) / 2)
        printf("Closest departure time is 7:00 p.m., arriving at 9:20 p.m.\n");
    else
        printf("Closest departure time is 9:45 p.m., arriving at 11:58 p.m.\n");
        
    return 0;
}
```

```
alancong@AlanCongdeMacBook-Air chapter_5 % ./a.out 
Enter a 24-hour time: 13:15
Closest departure time is 12.47 p.m., arriving at 3:00 p.m.
```

9. 编写一个程序，提示用户输入两个日期，然后显示哪一个日期更早：

```
Enter first date (mm/dd/yy): 3/6/08
Enter second date (mm/dd/yy): 5/17/07
5/17/07 is earlier than 3/6/08 
```

```C
#include<stdio.h>
int main(void)
{
    int month1, day1, year1;
    int month2, day2, year2;
    printf("Enter first date (mm/dd/yy): ");
    scanf("%d / %d / %d", &month1, &day1, &year1);
    printf("Enter second date (mm/dd/yy): ");
    scanf("%d / %d / %d", &month2, &day2, &year2);


    if((year1 * 10000 + month1 * 100 + day1) > (year2 * 10000 + month2 * 100 + day2))
        printf("%d/%d/%d is earlier than %d/%d/%d\n", month2, day2, year2, month1, day1, year1);
    else
        printf("%d/%d/%d is earlier than %d/%d/%d\n", month1, day1, year1, month2, day2, year2);

    return 0;
}
```

10. 利用 switch 语句编写一个程序，把用数字表示的成绩转换为字母表示的等级。

```
Enter numerical grade: 84
Letter grade: B 
```

使用下面的等级评定规则：A 为 90～100，B 为 80～89，C 为 70～79，D 为 60～69，F 为 0～59。如果成绩高于 100 或低于 0，则显示出错消息。提示：把成绩拆分成 2 个数字，然后使用 switch 语句判定十位上的数字。

```C
#include<stdio.h>
int main(void)
{
    int grade, number;
    printf("Enter numerical grade: ");
    scanf("%d", &grade);

    if(grade < 0 || grade > 100)
    {
        printf("Input Error\n");
        return 0;
    }

    number = grade / 10;

    printf("Letter grade: ");
    switch (number)
    {
    case 10: case 9:
        printf("A\n");
        break;
    case 8:
        printf("B\n");
        break;
    case 7:
        printf("C\n");
        break;
    case 6:
        printf("D\n");
        break;
    case 5: case 4: case 3: case 2: case 1: case 0:
        printf("F\n");
        break;
    default:
        break;
    }

    return 0;
}
```

11. 编写一个程序，要求用户输入一个两位数，然后显示该数的英文单词：

```
Enter a two-digit number: 45
You entered the number forty-five. 
```

提示：把数分解为两个数字。用一个 switch 语句显示第一位数字对应的单词（“twenty”“thirty”等），用第二个 switch 语句显示第二位数字对应的单词。不要忘记 11～19 需要特殊处理。

```c
#include <stdio.h>

int main(void)
{
    int number, ones, tens;

    printf("Enter a two-digit number: ");
    scanf("%d", &number);

    if (number < 10 || number > 99) 
    {
        printf("Error: input must be a two-digit number.\n");
        return 1;
    }

    printf("You entered the number ");

    if (number >= 10 && number < 20)
    {
        switch (number)
        {
            case 10: printf("ten\n"); break;
            case 11: printf("eleven\n"); break;
            case 12: printf("twelve\n"); break;
            case 13: printf("thirteen\n"); break;
            case 14: printf("fourteen\n"); break;
            case 15: printf("fifteen\n"); break;
            case 16: printf("sixteen\n"); break;
            case 17: printf("seventeen\n"); break;
            case 18: printf("eighteen\n"); break;
            case 19: printf("nineteen\n"); break;
        }
    }
    else
    {
        tens = number / 10;
        ones = number % 10;

        switch (tens)
        {
            case 2: printf("twenty"); break;
            case 3: printf("thirty"); break;
            case 4: printf("forty"); break;
            case 5: printf("fifty"); break;
            case 6: printf("sixty"); break;
            case 7: printf("seventy"); break;
            case 8: printf("eighty"); break;
            case 9: printf("ninety"); break;
        }

        switch (ones)
        {
            case 0: printf("\n"); break;
            case 1: printf("-one\n"); break;
            case 2: printf("-two\n"); break;
            case 3: printf("-three\n"); break;
            case 4: printf("-four\n"); break;
            case 5: printf("-five\n"); break;
            case 6: printf("-six\n"); break;
            case 7: printf("-seven\n"); break;
            case 8: printf("-eight\n"); break;
            case 9: printf("-nine\n"); break;
        }
    }

    return 0;
}
```

## 第六章 循环

### 练习题

6.1 节  
1. 下列程序片段的输出是什么？

```c
i = 1;
while (i <= 128) {
    printf("%d ", i);
    i *= 2;
}
```

```C
// 从1 一直输出到 2^128，每个都是2的幂
#include <stdio.h>
int main(void)
{
    int i = 1;
    while (i <= 128)
    {
        printf("%d ", i);
        i *= 2;
    }

    printf("\n");
    return 0;
}
```

```
1 2 4 8 16 32 64 128 
```

6.2 节

2. 下列程序片段的输出是什么？

```c
i = 9384;
do {
    printf("%d ", i);
    i /= 10;
} while (i > 0);
```

```C
#include <stdio.h>
int main(void)
{
    int i = 9384;
    do
    {
        printf("%d ", i);
        i /= 10;
    } while (i > 0);
    printf("\n");
    return 0;
}
```

```
9384 938 93 9 
```

6.3 节

3. 下面这条 for 语句的输出是什么？

```c
for (i = 5, j = i - 1; i > 0, j > 0; --i, j = i - 1)
    printf("%d ", i);
```

```
// 输出5 4 3 2
#include<stdio.h>
int main(void)
{
    for (int i = 5, j = i - 1; i > 0, j > 0; --i, j = i - 1)
    printf("%d ", i);

    printf("\n");
    return  0;
}
```

```
5 4 3 2 
```

4. 下列哪条语句和其他两条语句不等价（假设循环体都是一样的）？

```c
(a)for (i = 0; i < 10; i++) ...
(b)for (i = 0; i < 10; ++i) ...
(c)for (i = 0; i++ < 10; ) ...
```

```C
#include<stdio.h>
int main(void)
{
    for (int i = 0; i < 10; i++) {
        printf("%d ", i);
    }
    printf("\n");
    for (int i = 0; i < 10; ++i) {
        printf("%d ", i);
    }
    printf("\n");
    for (int i = 0; i++ < 10; ) {
        printf("%d ", i);
    }
    printf("\n");
    return 0;
}
```

```
0 1 2 3 4 5 6 7 8 9 
0 1 2 3 4 5 6 7 8 9 
1 2 3 4 5 6 7 8 9 10 
```

5. 下列哪条语句和其他两条语句不等价（假设循环体都是一样的）？

```C
(a) while (i < 10) {...}
(b) for (; i < 10;) {...}
(c) do {...} while (i < 10);
```

```c
// i为0的时候两者其实没有什么区别，但是当i为10的时候，前两个循环不输出但第三个循环仍会输出数据
#include<stdio.h>
int main(void)
{
    int i = 10;
    while (i < 10) {
        printf("%d ", i++);
    }
    printf("\n");
    i = 10;
    for (; i < 10;) {
        printf("%d ", i++);
    }
    printf("\n");
    i = 10;
    do {
        printf("%d ", i++);
    } while (i < 10);
    printf("\n");

    return 0;
}
```

```


10 
```

6. 把练习题 1 中的程序片段改写为一条 for 语句。

```C
#include<stdio.h>
int main(void)
{
    for(int i = 1;i <= 128;i *= 2)
        printf("%d ", i);
    printf("\n");

    return 0;
}
```

```
1 2 4 8 16 32 64 128 
```

7. 把练习题 2 中的程序片段改写为一条 for 语句。

```C
#include<stdio.h>
int main(void)
{
    for(int i = 9384;i > 0;i /= 10)
        printf("%d ", i);
    printf("\n");

    return 0;
}
```

```
9384 938 93 9 
```

8. 下面这条 for 语句的输出是什么？

```c
for (i = 10; i >= 1; i /= 2)
    printf("%d ", i++);
```

```C
// 输出是10 5 3 2 1 1 1 ...
#include<stdio.h>
int main(void)
{
    for (int i = 10; i >= 1; i /= 2)
        printf("%d ", i++);
    printf("\n");

    return 0;
}
```

```
10 5 3 2 1 1 1 1 1 1 1 1 1 ... 
```

9. 把练习题 8 中的 for 语句改写为一条等价的 while 语句。除了 while 循环本身之外，还需要一条语句。

```c
// 输出是10 5 3 2 1 1 1 ...
#include<stdio.h>
int main(void)
{
    int i = 10;
    while(i >= 1)
    {
        printf("%d ", i++);
        i /= 2;
    }
    printf("\n");

    return 0;
}
```

```
10 5 3 2 1 1 1 1 1 1 1 1 1 ... 
```

6.4 节

10. 说明如何用等价的 goto 语句替换 continue 语句。


```c
// 这里需要注意的是如果在复合语句的最末尾增加跳转标记不加分号的话会报错，因为这是C23才有的特性。
#include<stdio.h>
int main(void)
{
    for(int i = 1;i < 10;i ++)
    {
        if(i == 5)
        {
            // continue;
            goto JUMP;
        }
        printf("%d ", i);
    JUMP:;
    }
    printf("\n");
    return 0;
}
```

11. 下列程序片段的输出是什么？

```c
sum = 0;
for (i = 0; i < 10; i++) {
    if (i % 2)
        continue;
    sum += i;
}
printf("%d\n", sum);
```

```C
// 输出的就是0到9之间的全部偶数的和
#include <stdio.h>
int main(void)
{
    int sum = 0;
    for (int i = 0; i < 10; i++)
    {
        if (i % 2)
            continue;
        printf("%d ", i);
        sum += i;
    }
    printf("\n");
    printf("%d\n", sum);
} 
```

```
0 2 4 6 8 
20
```

12. 下面的“素数判定”循环作为示例出现在 6.4 节中：

```c
for (d = 2; d < n; d++)
    if (n % d == 0)
        break;
```

这个循环不是很高效。没有必要用 n 除以 2～n-1 的所有数来判断它是否为素数。事实上，只需要检查不大于 n 的平方根的除数即可。利用这一点来修改循环。提示：不要试图计算出 n 的平方根，用 d*d 和 n 进行比较。

```C
#include<stdio.h>
int main(void)
{
    int n = 100;
    int is_prime = 1;
    for (int d = 2; d * d < n; d++)
        if (n % d == 0)
            is_prime = 0;
    if (is_prime)
        printf("%d is prime\n", n);
    else
        printf("%d is not prime\n", n);
    return 0;
}
```

```
100 is not prime
```

6.5 节

*13. 重写下面的循环，使其循环体为空。

```c
for (n = 0; m > 0; n++)
    m /= 2;
```

```C
#include<stdio.h>
int main(void)
{
    int n = 0, m = 100;
    for(;;)
    {
        if(m > 0)
        {
            m /= 2;
            n ++;
            printf("%d ", m);
        }
        else
        {
            printf("\n");
            break;
        }
    }

    return 0;
}
```

```
50 25 12 6 3 1 0 
```

14. 找出下面程序片段中的错误并修正。

```c
if (n % 2 == 0);
    printf("n is even\n");
```

```
// 在if的控制语句后面多了个分号！确实很不容易察觉。
```

### 编程题

1. 编写程序，找出用户输入的一串数中的最大数。程序需要提示用户一个一个地输入数。当用户输入 0 或负数时，程序必须显示出已输入的最大非负数：

```
Enter a number: 60  
Enter a number: 38.3  
Enter a number: 4.89  
Enter a number: 100.62  
Enter a number: 75.2295  
Enter a number: 0  
The largest number entered was 100.62  
```

注意：输入的数不一定是整数。

```C
#include<stdio.h>
int main(void)
{
    float number, max = 0, sum = 0;
    int abort = 1;
    while(1)
    {
        printf("Enter a number: ");
        scanf("%f", &number);

        if(number <= 0)
            break;
        else if(number > max)
            max = number;
    }
    printf("Max: %.2f\n", max);
    return 0;   
}
```

**注意：**浮点数在计算机中是二进制近似存储的，大多数十进制小数（如0.1）无法被精确表示，因此一般不建议用`==`判断两个浮点数是否相等。不过`0.0`在IEEE 754标准下可以被精确表示，所以像`if (number == 0)`这样的判断是安全的。若要判断一个浮点数“接近0”，更稳妥的写法是使用容差，例如`if (fabs(number) < 1e-6)`。

2. 编写程序，要求用户输入两个整数，然后计算并显示这两个整数的最大公约数（GCD）：

```
Enter two integers: 12 28  
Greatest common divisor: 4  
```

提示：求最大公约数的经典算法是 Euclid 算法，方法如下。分别让变量 m 和 n 存储两个数的值。如果 n 为 0，那么停止操作，m 中的值是 GCD；否则计算 m 除以 n 的余数，把 n 保存到 m 中，并把余数保存到 n 中。然后重复上述过程，每次都先判定 n 是否为 0。

```C
#include<stdio.h>
int main(void)
{
    int m, n, temp, gcd;
    printf("Enter two integers: ");
    scanf("%d %d", &m, &n);
    while(n != 0)
    {
        temp = n;
        n = m % n;
        m = temp;
    }
    gcd = m;

    printf("Greatest common divisor: %d\n", gcd);
    return 0;
}
```

```
Enter two integers: 12 28
Greatest common divisor: 4
```

3. 编写程序，要求用户输入一个分数，然后将其约分为最简分式：

```
Enter a fraction: 6/12  
In lowest terms: 1/2  
```

提示：为了把分数约分为最简分式，首先计算分子和分母的最大公约数，然后分子和分母都除以最大公约数。

```C
#include<stdio.h>
int main(void)
{
    int m, n, a, b, temp, gcd;
    printf("Enter a fraction: ");
    scanf("%d / %d", &m, &n);
 
    a = m;
    b = n;
    while(n != 0)
    {
        temp = n;
        n = m % n;
        m = temp;
    }
    gcd = m;

    printf("In lowest terms: %d/%d\n", a / gcd, b / gcd);

    return 0;
}
```

```C
Enter a fraction: 4/24
In lowest terms: 1/6
```

4. 在 5.2 节的 broker.c 程序中添加循环，以便用户可以输入多笔交易，并且程序可以计算每次的佣金。程序在用户输入的交易额为 0 时终止。

```
Enter value of trade: 30000  
Commission: $166.00  
Enter value of trade: 20000  
Commission: $144.00  
Enter value of trade: 0  
```

```C
/* Calculates a broker's commission */
#include <stdio.h>
int main(void)
{
    float commission, value;

    do    
    {
        printf("Enter value of trade: ");
        scanf("%f", &value);

        if( value == 0)
            break;

        if (value < 2500.00f)
            commission = 30.00f + .017f * value;
        else if (value < 6250.00f)
            commission = 56.00f + .0066f * value;
        else if (value < 20000.00f)
            commission = 76.00f + .0034f * value;
        else if (value < 50000.00f)
            commission = 100.00f + .0022f * value;
        else if (value < 500000.00f)
            commission = 155.00f + .0011f * value;
        else
            commission = 255.00f + .0009f * value;
        if (commission < 39.00f)
            commission = 39.00f;
        printf("Commission: $%.2f\n", commission);
    }while (value != 0);

    return 0;
}
```

```
Enter value of trade: 30000
Commission: $166.00
Enter value of trade: 20000
Commission: $144.00
Enter value of trade: 0
```

5. 第 4 章的编程题 1 要求编写程序显示出两位数的逆序。设计一个更具一般性的程序，可以处理一位、两位、三位或者更多位的数。提示：使用 do 循环将输入的数重复除以 10，直到值达到 0 为止。


```C
#include <stdio.h>
int main(void)
{
    int number, m;
    printf("Enter a number:");
    scanf("%d", &number);
    printf("The reversal is: ");
    do
    {
        m = number % 10;
        number /= 10;
        printf("%d", m);
    } while (number != 0);

    printf("\n");
    return 0;
}
```

```
Enter a number:12345
The reversal is: 54321
```

6. 编写程序，提示用户输入一个数 n，然后显示出 1~n 的所有偶数平方值。例如，如果用户输入 100，那么程序应该显示出下列内容：

```
4  
16  
36  
64  
100  
```

```C
#include <stdio.h>
int main(void)
{
    int number, m = 0;
    printf("Enter a number:");
    scanf("%d", &number);

    if (number < 4)
    {
        printf("False input!");
        return 0;
    }

    int i = 1;
    while(1)
    {
        if (i % 2 == 0)
        {
            m = i * i;
            if (m <= number)
            {
                printf("%d\n", m);
            }
            else
                return 0;
        }
        i++;
    }

    return 0;
}
```

```
Enter a number:100
4
16
36
64
100
```

7. 重新安排程序 square3.c，在 for 循环中对变量 i 进行初始化、判定以及自增操作。不需要重写程序，特别是不要使用任何乘法。


```C
#include <stdio.h>

int main(void)
{
    int n;

    printf("This program prints a table of squares.\n");
    printf("Enter number of entries in table: ");
    scanf("%d", &n);

    for (int i = 1, square = 1, odd = 3; i <= n; odd += 2, ++i)
    {
        printf("%10d%10d\n", i, square);
        square += odd;
    }

    return 0;
}

```

**算法原理：**

- 该程序用于打印一个数字及其平方的表格。
- 在计算平方的过程中，利用了一个数学特性：一个整数的平方可以通过前一个平方加上一个递增的奇数来计算。举个例子：
  - 1^2 = 1
  - 2^2 = 1 + 3
  - 3^2 = 4 + 5
  - 4^2 = 9 + 7
- 因此，从1开始，每次增加的奇数是从3开始，递增2。通过这个方式，可以通过不断地加上这些奇数来得到每个整数的平方。

8. 编写程序显示单月的日历。用户指定这个月的天数和该月起始日是星期几：

```
Enter number of days in month: 31  
Enter starting day of the week (1=Sun, 7=Sat): 3  

       1  2  3  4  5  
 6  7  8  9 10 11 12  
13 14 15 16 17 18 19  
20 21 22 23 24 25 26  
27 28 29 30 31  
```

提示：此程序不像看上去那么难。最重要的部分是一个使用变量 i 从 1 计数到 n 的 for 语句（这里 n 是此月的天数），for 语句中需要显示 i 的每个值。在循环中，用 if 语句判定 i 是否是一个星期的最后一天，如果是，就显示一个换行符。

```C
#include<stdio.h>
int main(void)
{
    int number, start, day;
    printf("Enter number of days in month: ");
    scanf("%d", &number);
    printf("Enter starting day of the week (1=Sun, 7=Sat): ");
    scanf("%d", &start);

    for(int i = 1;i < start; i ++)
        printf("\t");

    day = start;
    for(int i = 1;i <= number;i ++, day ++)
    {
        if(day % 7 == 0)
        {
            printf("%2d\n", i);
        }
        else
        {
            printf("%2d\t", i);
        }
    }

    printf("\n");
    return 0;
}
```

9. 第 2 章的编程题 8 要求编程计算第一、第二、第三个月还贷后剩余的贷款金额。修改该程序，要求用户输入还贷的次数并显示每次还贷后剩余的贷款金额。


```C
#include<stdio.h>
int main(void)
{
    int number;
    float loan = 0.0f, rate = 0.0f, payment = 0.0f;
    printf("Enter amount of loan:");
    scanf("%f", &loan);
    printf("Enter interest rate:");
    scanf("%f", &rate);
    printf("Enter monthly payment:");
    scanf("%f", &payment);
    printf("Enter the number of month:");
    scanf("%d", &number);

    for(int i = 1;i <= number;i ++)
    {
        printf("Balance remaining after %d payment:%.2f\n", i, 
            loan * (1.0 + (rate / 1200)) - payment);
        loan = loan * (1.0 + (rate / 1200)) - payment;
    }

    return 0;
}


```

10. 第 5 章的编程题 9 要求编写程序判断哪个日期更早。泛化该程序，使用户可以输入任意个日期。用 0/0/0 指示输入结束，不再输入日期。

```
Enter a date (mm/dd/yy): 3/6/08  
Enter a date (mm/dd/yy): 5/17/07  
Enter a date (mm/dd/yy): 6/3/07  
Enter a date (mm/dd/yy): 0/0/0  
5/17/07 is the earliest date  
```

```C
#include <stdio.h>
int main(void)
{
    int month1, day1, year1;
    int month2 = 99, day2 = 99, year2 = 99;

    while(1)
    {
        printf("Enter a date (mm/dd/yy): ");
        scanf("%d / %d / %d", &month1, &day1, &year1);

        if ((month1 == 0) && (day1 == 0) && (year1 == 0))
            break;

        if ((year1 * 10000 + month1 * 100 + day1) < (year2 * 10000 + month2 * 100 + day2))
        {
            year2 = year1;
            month2 = month1;
            day2 = day1;
        }
            
    }

    printf("%2d/%2d/%.2d is the earliest date\n", month2, day2, year2);

    return 0;
}
```

11. 数学常量 e 的值可以用一个无穷级数表示：

$$
e = 1 + \frac{1}{1!} + \frac{1}{2!} + \frac{1}{3!} + \cdots
$$

编写程序，用下面的公式计算 e 的近似值：

$$
1 + \frac{1}{1!} + \frac{1}{2!} + \frac{1}{3!} + \cdots + \frac{1}{n!}
$$
这里 n 是用户输入的整数。

```C
#include<stdio.h>
int main(void)
{
    int acc;
    float sum = 1.0, temp = 1.0;
    printf("Please enter the accuracy: ");
    scanf("%d", &acc);

    for(int i = 1;i < acc;i ++)
    {
        temp *= i;
        sum += (1.0 / temp);
    }

    printf("e is: %f\n", sum);
    return 0;
}
```

12. 修改编程题 11，使得程序持续执行加法运算，直到当前项小于 ε 为止，其中 ε 是用户输入的较小的（浮点）数。

```C
#include<stdio.h>
int main(void)
{
    double sum = 1.0, temp = 1.0, acc;
    printf("Please enter the accuracy: ");
    scanf("%le", &acc);

    for(int i = 1;;i ++)
    {
        temp *= i;
        sum += (1.0 / temp);
        if((1.0 / temp) < acc)
            break;
        // 看看循环了多少次
        // printf("%d\n", i);
    }

    printf("e is: %.15lf\n", sum);
    return 0;
}
```



## 第七章 基本类型

### 练习题

7.1 节

1. 给出下列整型常量的十进制值。

```
(a) 077 
(b) 0x77
(c) 0XABC
```

7.2 节

2. 下列哪些常量在 C 语言中不是合法的？区分每一个合法的常量是整数还是浮点数。

```
(a) 010E2
(b) 32.1E+5
(c) 0790
(d) 100_000
(e) 3.978e-2
```

3. 下列哪些类型在 C 语言中不是合法的？

```
(a) short unsigned int
(b) short float
(c) long double
(d) unsigned long
```

7.3 节

4. 如果变量 c 是 char 类型，那么下列哪条语句是非法的？

```
(a) i += c; /* i has type int */ 
(b) c = 2 * c – 1; 
(c) putchar(c); 
(d) printf(c); 
```

5. 下列哪条不是书写数 65 的合法方式？（假设字符集是 ASCII。）

```
(a) 'A' 
(b) 0b1000001 
(c) 0101 
(d) 0x41 
```

6. 对于下面的数据项，指明 char、short、int、long 类型中哪种类型是足以存储数据的最小类型。

```
(a) 一个月的天数
(b) 一年的天数
(c) 一天的分钟数
(d) 一天的秒数
```

7. 对于下面的字符转义，给出等价的八进制转义。（假定字符集是 ASCII。）可以参考附录 E，其中列出了 ASCII 字符的数值码。

```
(a) \b 
(b) \n 
(c) \r 
(d) \t
```

### 编程题

1. 如果 $ i \times i $ 超出了 `int` 类型的最大取值，那么 6.3 节的程序 `square2.c` 将失败（通常会显示奇怪的答案）。运行该程序，并确定导致失败的 $n$ 的最小值。尝试把变量 `i` 的类型改成 `short` 并再次运行该程序。（不要忘记更新 `printf` 函数调用中的转换说明！）然后尝试将其改成 `long`。从这些实验中，你能总结出在你的机器上用于存储整数类型的位数是多少吗？

2. 修改 6.3 节的程序 `square2.c`，每 24 次平方运算后暂停，并显示下列信息：

   ```
   Press Enter to continue...
   ```

   显示完上述消息后，程序应该使用 `getchar` 函数读入一个字符。`getchar` 函数读到用户输入的回车键才允许程序继续。

3. 修改 7.1 节的程序 `sum2.c`，对 `double` 型值组成的数列求和。

4. 编写可以把字母格式的电话号码翻译成数值格式的程序：

   ```
   Enter phone number: CALLATT
   2255288
   ```

   （如果没有电话在身边，参考这里给出的字母在键盘上的对应关系：2=ABC、3=DEF、4=GHI、5=JKL、 6=MNO、7=PQRS、8=TUV、9=WXYZ。）原始电话号码中的非字母字符（例如数字或标点符号）保持不变：

   ```
   Enter phone number: 1-800-COL-LECT
   1-800-265-5328
   ```

   可以假设任何用户输入的字母都是大写字母。

5. 在十字拼字游戏中，玩家利用小卡片组成英文单词，每张卡片包含一个英文字母和面值。面值根据字母稀缺程度的不同而不同。（面值与字母的对应关系如下：1——AEILNORSTU；2——DG；3——BCMP；4——FHVWY；5——K；8——JX；10——QZ。）编写程序，通过对单词中字母的面值求和来计算单词的值：

   ```
   Enter a word: pitfall
   Scrabble value: 12
   ```

   编写的程序应该允许单词中混合出现大小写字母。提示：使用 `toupper` 库函数。

6. 编写程序显示 `sizeof(int)`、`sizeof(short)`、`sizeof(long)`、`sizeof(float)`、`sizeof(double)` 和 `sizeof(long double)` 的值。

7. 修改第 3 章的编程题 6，使得用户可以对两个分数进行加、减、乘、除运算（在两个分数之间输入 +、 −、 * 或 / 符号）。

8. 修改第 5 章的编程题 8，要求用户输入 12 小时制的时间。输入时间的格式为时:分后跟 A、P、AM 或 PM（大小写均可）。数值时间和 AM/PM 之间允许有空白（但不强制要求有空白）。有效输入的示例如下：

   ```
   1:15P
   1:15PM
   1:15p
   1:15pm
   1:15 P
   1:15 PM
   1:15 p
   1:15 pm
   ```

   可以假定输入的格式就是上述之一，不需要进行错误判定。

9. 编写程序，要求用户输入 12 小时制的时间，然后用 24 小时制显示该时间：

   ```
   Enter a 12-hour time: 9:11 PM
   Equivalent 24-hour time: 21:11
   ```

   参考编程题 8 中关于输入格式的描述。

10. 编写程序统计句子中元音字母（a、e、i、o、u）的个数：

    ```
    Enter a sentence: And that's the way it is.
    Your sentence contains 6 vowels.
    ```

11. 编写一个程序，要求用户输入英文名和姓，并根据用户的输入先显示姓，其后跟一个逗号，然后显示名的首字母，最后加一个点：

    ```
    Enter a first and last name: Lloyd Fosdick
    Fosdick, L.
    ```

    用户的输入中可能包含空格（名之前、名和姓之间、姓氏之后）。

12. 编写程序对表达式求值：

    ```
    Enter an expression: 1+2.5*3
    Value of expression: 10.5
    ```

    表达式中的操作数是浮点数，运算符是 +、 −、 * 和 /。表达式从左向右求值（所有运算符的优先级都一样）。

13. 编写程序计算句子的平均词长：

    ```
    Enter a sentence: It was deja vu all over again.
    Average word length: 3.4
    ```

    简单起见，程序中把标点符号看作其前面单词的一部分。平均词长显示一个小数位。

14. 编写程序，用牛顿方法计算正浮点数的平方根：

    ```
    Enter a positive number: 3
    Square root: 1.73205
    ```

    设 $x$ 是用户输入的数。牛顿方法需要先给出 $x$ 平方根的猜测值 $y$（我们使用 1）。后续的猜测值通过计算 $y$ 和 $\frac{x}{y}$ 的平均值得到。表 7-6 中给出了求解 3 的平方根的过程。

    表 7-6 用牛顿方法求解 3 的平方根：

    ```
    x    y    x/y    y 和 x/y 的平均值
    3    1    3      2
    3    2    1.5    1.75
    3    1.75 1.71429 1.73214
    3    1.73214 1.73205 1.73205
    ```

    注意，$y$ 的值逐渐接近 $x$ 的平方根。为了获得更高的精度，程序中应使用 `double` 类型的变量代替 `float` 类型的变量。当 $y$ 的新旧值之差的绝对值小于 0.00001 时程序终止。提示：调用 `fabs` 函数求 `double` 类型数值的绝对值。

15. 编程计算正整数的阶乘：

    ```
    Enter a positive integer: 6
    Factorial of 6: 720
    ```

    (a) 用 `short` 类型变量存储阶乘的值。为了正确打印出 $n$ 的阶乘，$n$ 的最大值是多少？

    (b) 用 `int` 类型变量重复 (a)。

    (c) 用 `long` 类型变量重复 (a)。

    (d) 如果你的编译器支持 `long long` 类型，用 `long long` 类型变量重复 (a)。

    (e) 用 `float` 类型变量重复 (a)。

    (f) 用 `double` 类型变量重复 (a)。

    (g) 用 `long double` 类型变量重复 (a)。

    在 (e)~(g) 这几种情况下，程序会显示阶乘的近似值，不一定是准确值。



## 第八章 数组

### 练习题

1. 修改8.1节的程序 `repdigit.c`，使其可以显示出哪些数字有重复（如果有的话）：

   ```
   Enter a number: 939577
   Repeated digit(s): 7 9
   ```

2. 修改8.1节的程序 `repdigit.c`，使其打印出一份列表，显示出每个数字在数中出现的次数：

   ```
   Enter a number: 41271092
   Digit:        0  1  2  3  4  5  6  7  8  9
   Occurrences:  1  2  2  0  1  0  0  1  0  1
   ```

3. 修改8.1节的程序 `repdigit.c`，使得用户可以输入多个数进行重复数字的判断。当用户输入的数小于或等于0时，程序终止。

4. 修改8.1节的程序 `reverse.c`，利用表达式 `(int)(sizeof(a) / sizeof(a[0]))`（或者具有相同值的宏）来计算数组的长度。

5. 修改8.1节的程序 `interest.c`，使得修改后的程序可以每月整合一次利息，而不是每年整合一次利息。不要改变程序的输出格式，余额仍按每年一次的时间间隔显示。

6. 有一个名叫 B1FF 的人，是典型的网络新手，他有一种独特的编写消息的方式。下面是一条常见的 B1FF公告：

   ```
   H3Y DUD3, C 15 R1LLY C00L!!!!!!!!!!
   ```

   编写一个“B1FF过滤器”，它可以读取用户输入的消息并把此消息翻译成B1FF的表达风格：

   ```
   Enter message: Hey dude, C is rilly cool
   In B1FF-speak: H3Y DUD3, C 15 R1LLY C00L!!!!!!!!!!
   ```

   程序需要把消息转换成大写字母，用数字代替特定的字母（A→4、B→8、E→3、I→1、O→0、S→5），然后添加10个左右的感叹号。

7. 编写程序读取一个5×5的整数数组，然后显示出每行的和与每列的和：

   ```
   Enter row 1:  8 3 9 0 10
   Enter row 2:  3 5 17 1 1
   Enter row 3:  2 8 6 23 1
   Enter row 4:  15 7 3 2 9
   Enter row 5:  6 14 2 6 0
   Row totals:  30 27 40 36 28
   Column totals:  34 37 37 32 21
   ```

8. 修改编程题7，使其提示用户输入每个学生5门测验的成绩，一共有5个学生。然后计算每个学生的总分和平均分，以及每门测验的平均分、高分和低分。

9. 编写程序，生成一种贯穿10×10字符数组（初始时全为字符 '.'）的“随机步法”。程序必须随机地从一个元素“走到”另一个元素，每次都向上、向下、向左或向右移动一个元素位置。已访问过的元素按访问顺序用字母A~Z进行标记。

   - 提示：利用 `srand` 函数和 `rand` 函数生成随机数，并判断其除以4的余数。执行移动前要检查是否超出边界或已经访问过的位置。若四个方向都无法移动，程序终止。

10. 修改第5章的编程题8，用一个数组存储航班起飞时间，另一个数组存储航班抵达时间。（时间用整数表示，表示从午夜开始的分钟数。）程序用一个循环搜索起飞时间数组，以找到与用户输入的时间最接近的起飞时间。

11. 修改第7章的编程题4，给输出加上标签：

```
Enter phone number: 1-800-COL-LECT
In numeric form: 1-800-265-5328
```

在显示电话号码之前，程序需要将其（以原始格式或数值格式）存储在一个字符数组中。可以假定电话号码的长度不超过15个字符。

1. 修改第7章的编程题5，用数组存储字母的面值。数组有26个元素，对应字母表中的26个字母。例如，数组元素0存储1（因为字母A的面值为1），数组元素1存储3（因为字母B的面值为3），等等。每读取输入单词中的一个字母，程序都会利用该数组确定字符的拼字值。使用数组初始化器来建立该数组。
2. 修改第7章的编程题11，给输出加上标签：

```
Enter a first and last name: Lloyd Fosdick
You entered the name: Fosdick, L.
```

在显示姓（不是名）之前，程序需要将其存储在一个字符数组中。可以假定姓的长度不超过20个字符。

1. 编写程序颠倒句子中单词的顺序：

```
Enter a sentence: you can cage a swallow can't you?
Reversal of sentence: you can't swallow a cage can you?
```

提示：用循环逐个读取字符，存储在一维字符数组中。当遇到句号、问号或感叹号时终止循环。然后反向搜索数组，逐个显示单词，直到显示出终止符。

1. 目前已知的最古老的一种加密技术是恺撒加密（得名于Julius Caesar）。编写程序用恺撒加密方法对消息进行加密。

```
Enter message to be encrypted: Go ahead, make my day.
Enter shift amount (1-25): 3
Encrypted message: Jr dkhdg, pdnh pb gdb.
```

可以假定消息的长度不超过80个字符。非字母字符不改动。加密时不改变字母的大小写。

1. 编程测试两个单词是否为变位词（相同字母的重新排列）：

```
Enter first word: smartest
Enter second word: mattress
The words are anagrams.
```

用一个循环逐个字符地读取第一个单词，利用一个26元的数组记录每个字母的出现次数。第二个单词读取后，检查数组是否为全0，若为0则为变位词。

1. 编写程序打印 n×n 的幻方（1, 2, …, n²的方阵排列，且每行、每列和每条对角线上的和都相等）。由用户指定 n 的值：

```
Enter size of magic square: 5
17  24   1   8  15
23   5   7  14  16
 4   6  13  20  22
10  12  19  21   3
11  18  25   2   9
```

幻方存储在二维数组中。起始时数1放在第0行的中间，接下来的数按规则填充，若越界则绕回数组的另一端。

## 第九章 函数

### 练习题

9.1 节

1. 下列计算三角形面积的函数有两处错误，找出这些错误，并且说明修改它们的方法。（提示：公式中没有错误。）

   ```c
   double triangle_area(double base, height) 
   double product;  
   {   
       product = base * height;   
       return product / 2;  
   }
   ```

2. 编写函数 `check(x, y, n)`：如果 `x` 和 `y` 都落在 0~n-1 的闭区间内，那么函数返回 1；否则函数应该返回 0。假设 `x`、`y` 和 `n` 都是 `int` 类型。

3. 编写函数 `gcd(m, n)` 来计算整数 `m` 和 `n` 的最大公约数。（第6章的编程题2描述了计算最大公约数的 Euclid 算法。）

4. 编写函数 `day_of_year(month, day, year)`，使得函数返回由这三个参数确定的那一天是一年中的第几天（1~366范围内的整数）。

5. 编写函数 `num_digits(n)`，使得函数返回正整数 `n` 中数字的个数。提示：为了确定 `n` 中数字的个数，把这个数反复除以10，当 `n` 达到0时，除法运算的次数表明了 `n` 最初拥有的数字的个数。

6. 编写函数 `digit(n, k)`，使得函数返回正整数 `n` 中的第 `k` 位数字（从右边算起）。例如，`digit(829, 1)` 返回 9，`digit(829, 2)` 返回 2，`digit(829, 3)` 返回 8。如果 `k` 大于 `n` 所含有的数字个数，那么函数返回 0。

7. 假设函数 `f` 有如下定义：

   ```c
   int f(int a, int b) { ... }
   ```

   那么下面哪些语句是合法的？（假设 `i` 的类型为 `int` 而 `x` 的类型为 `double`。）

   (a) `i = f(83, 12);`

   (b) `x = f(83, 12);`

   (c) `i = f(3.15, 9.28);`

   (d) `x = f(3.15, 9.28);`

   (e) `f(83, 12);`

9.2 节

1. 对于不返回值且有一个 `double` 类型形式参数的函数，下列哪些函数原型是有效的？

   (a) `void f(double x);`

   (b) `void f(double);`

   (c) `void f(x);`

   (d) `f(double x);`

9.3 节

1. 下列程序的输出是什么？

   ```c
   #include 
   void swap(int a, int b);
   int main(void) {
       int i = 1, j = 2;
       swap(i, j);
       printf("i = %d, j = %d\n", i, j);
       return 0;
   }
   void swap(int a, int b) {
       int temp = a;
       a = b;
       b = temp;
   }
   ```

2. 编写函数，使得函数返回下列值。（假设 `a` 和 `n` 是形式参数，其中 `a` 是 `int` 类型数组，`n` 是数组的长度。）

(a) 数组 `a` 中最大的元素。

(b) 数组 `a` 中所有元素的平均值。

(c) 数组 `a` 中正数元素的数量。

1. 编写下面的函数：

```c
float compute_GPA(char grades[], int n);
```

其中 `grades` 数组包含字母等级（A、B、C、D 或 F，大小写皆可），`n` 是数组的长度。函数应返回等级的平均值（假定 A=4，B=3，C=2，D=1，F=0）。

1. 编写下面的函数：

```c
double inner_product(double a[], double b[], int n);
```

函数应返回 `a[0] * b[0] + a[1] * b[1] + ... + a[n-1] * b[n-1]`。

1. 编写下面的函数，对棋盘位置求值：

```c
int evaluate_position(char board[8][8]);
```

`board` 表示棋盘上方格的配置，其中字母 K、Q、R、B、N、P 表示白色的方格，字母 k、q、r、b、n、p 表示黑色的方格。`evaluate_position` 应计算出白色方格的和（Q=9，R=5，B=3，N=3，P=1），并按类似的方法计算出黑色方格的和，然后返回这两个数的差。如果白子占优则返回值为正数，如果黑子占优则返回值为负数。

9.4 节

1. 如果数组 `a` 中有任一元素的值为 0，那么下列函数返回 `true`；如果数组 `a` 的所有元素都是非零的，则函数返回 `false`。可惜的是，此函数有错误。请找出错误并且说明修改它的方法。

```c
bool has_zero(int a[], int n) {
    int i;
    for (i = 0; i < n; i++)
        if (a[i] == 0)
            return true;
        else
            return false;
}
```

1. 下面这个（相当混乱的）函数找出三个数的中间数。重新编写函数，使得它只有一条 `return` 语句。

```c
double median(double x, double y, double z) {
    if (x <= y)
        if (y <= z) return y;
        else if (x <= z) return z;
        else return x;
    if (z <= y) return y;
    if (x <= z) return x;
    return z;
}
```

9.6 节

1. 请采用精简 `power` 函数的方法来简化 `fact` 函数。
2. 请重新编写 `fact` 函数，使得编写后的函数不再有递归。
3. 编写递归版本的 `gcd` 函数（见练习题3）。下面是用于计算 `gcd(m, n)` 的策略：如果 `n` 为 0，那么返回 `m`；否则，递归地调用 `gcd` 函数，把 `n` 作为第一个实际参数进行传递，而把 `m % n` 作为第二个实际参数进行传递。
4. 思考下面这个“神秘”的函数：

```c
void pb(int n) {
    if (n != 0) {
        pb(n / 2);
        putchar('0' + n % 2);
    }
}
```

手动跟踪函数的执行。然后编写程序调用此函数，把用户输入的数传递给此函数。函数做了什么？

### 编程题

1. 编写程序，要求用户输入一串整数（把这串整数存储在数组中），然后通过调用 `selection_sort` 函数来排序这些整数。在给定 n 个元素的数组后，`selection_sort` 函数必须做下列工作：
    (a) 搜索数组找出最大的元素，然后把它移到数组的最后；
    (b) 递归地调用函数本身来对前 n-1 个数组元素进行排序。

2. 修改第5章的编程题5，用函数计算所得税的金额。在输入应纳税所得额后，函数返回税金。

3. 修改第8章的编程题9，使其包含下列函数：

   ```c
   void generate_random_walk(char walk[10][10]);
   void print_array(char walk[10][10]);
   ```

   main 函数首先调用 `generate_random_walk`，该函数把所有数组元素都初始化为字符 `.`，然后将其中一些字符替换为 A~Z 的字母，详见原题的描述。接着，main 函数调用 `print_array` 函数来显示数组。

4. 修改第8章的编程题16，使其包含下列函数：

   ```c
   void read_word(int counts[26]);
   bool equal_array(int counts1[26], int counts2[26]);
   ```

   main 函数将调用 `read_word` 两次，每次用于读取用户输入的一个单词。读取单词时，`read_word` 用单词中的字母更新 `counts` 数组，详见原题的描述。`main` 将声明两个数组，每个数组用于一个单词。这些数组用于跟踪单词中每个字母出现的次数。接下来，main 函数调用 `equal_array` 函数， 以前面提到的两个数组作为参数。如果两个数组中的元素相同（表明这两个单词是变位词），`equal_array` 返回 `true`，否则返回 `false`。

5. 修改第8章的编程题17，使其包含下列函数：

   ```c
   void create_magic_square(int n, int magic_square[n][n]);
   void print_magic_square(int n, int magic_square[n][n]);
   ```

   获得用户输入的数 `n` 之后，main 函数调用 `create_magic_square` 函数，另一个调用参数是在 `main` 内部声明的 `n×n` 的数组。`create_magic_square` 函数用 1, 2, …, n² 填充数组，如原题所述。接下来，main 函数调用 `print_magic_square`，按原题描述的格式显示数组。注意：如果你的编译器不支持变长数组，请把 `main` 中的数组声明为 99×99 而不是 n×n，并使用下面的原型：

   ```c
   void create_magic_square(int n, int magic_square[99][99]);
   void print_magic_square(int n, int magic_square[99][99]);
   ```

6. 编写函数计算下面多项式的值：

   5x4−3x3+2x2−7x+65x^4 - 3x^3 + 2x^2 - 7x + 6

   编写程序要求用户输入 x 的值，调用该函数计算多项式的值并显示函数返回的值。

7. 如果换一种方法计算 $x^n$，9.6节的 `power` 函数速度可以更快。我们注意到，如果 n 是 2 的幂，则可以通过自乘的方法计算 $x^n$。例如， $4^x$ 是 $2^x$ 的平方，所以 $4^x$ 可以用两次乘法计算，而不需要三次乘法。这种方法甚至可以用于 n 不是 2 的幂的情况。如果 n 是偶数，则

   xn=(xn/2)2x^n = (x^{n/2})^2

   如果 n 是奇数，则

   xn=x×xn−1x^n = x \times x^{n-1}

   编写计算 $x^n$ 的递归函数（递归在 n=0 时结束，此时函数返回 1）。为了测试该函数，写一个程序要求用户输入 x 和 n 的值，调用 `power` 计算 $x^n$，然后显示函数的返回值。

8. 编写函数模拟掷骰子的游戏（两个骰子）。第一次掷的时候，如果点数之和为 7 或 11 则获胜；如果点数之和为 2、3 或 12 则落败；其他情况下的点数之和称为“目标”，游戏继续。在后续的投掷中，如果玩家再次掷出“目标”点数则获胜，掷出 7 则落败，其他情况都忽略，游戏继续进行。每局游戏结束时，程序询问用户是否再玩一次，如果用户输入的回答不是 y 或 Y，程序会显示胜败的次数然后终止。

   ```
   You rolled: 8
   Your point is 8
   You rolled: 3
   You rolled: 10
   You rolled: 8
   You win!
   Play again? y
   
   You rolled: 6
   Your point is 6
   You rolled: 5
   You rolled: 12
   You rolled: 3
   You rolled: 7
   You lose!
   Play again? y
   
   You rolled: 11
   You win!
   Play again? n
   
   Wins: 2
   Losses: 1
   ```

   编写三个函数：`main`、`roll_dice` 和 `play_game`。下面给出了后两个函数的原型：

   ```c
   int roll_dice(void);
   bool play_game(void);
   ```

   `roll_dice` 应生成两个随机数（每个都在 1~6 范围内），并返回它们的和。`play_game` 应进行一次掷骰子游戏（调用 `roll_dice` 确定每次掷的点数），如果玩家获胜则返回 `true`，如果玩家落败则返回 `false`。`play_game` 函数还要显示玩家每次掷骰子的结果。`main` 函数反复调用 `play_game` 函数，记录获胜和落败的次数，并显示“you win”和“you lose”消息。提示：使用 `rand` 函数生成随机数。关于如何调用 `rand` 和相关的 `srand` 函数，见 8.2 节 `deal.c` 程序中的例子。

## 第十章 程序结构

### 练习题

10.4 节

1. 下面的程序框架只显示了函数定义和变量声明。

   ```C
   int a;
   void f(int b) {
       int c;
   }
   void g(void) {
       int d;
       {
           int e;
       }
   }
   int main(void) {
       int f;
   }
   ```

   列出下面每种作用域内所有变量的名字和形式参数的名字。

   (a) f 函数。
   (b) g 函数。
   (c) 声明 e 的程序块。
   (d) main 函数。

2. 下面的程序框架只显示了函数定义和变量声明。

   ```
   int b, c;
   void f(void) {
       int b, d;
   }
   void g(int a) {
       int c;
       {
           int a, d;
       }
   }
   int main(void) {
       int c, d;
   }
   ```

   列出下面每种作用域内所有变量的名字和形式参数的名字。如果有多个同名的变量或形式参数，指明具体是哪一个。

   (a) f 函数。
    (b) g 函数。
    (c) 声明 a 和 d 的程序块。
    (d) main 函数。

3. 如果程序只有一个函数（main），那么它最多可以包含多少个名为 i 的不同变量？

### 编程题

1. 改10.2节的栈示例使它存储字符而不是整数。接下来，增加main函数，用来要求用户输入一串圆括号或花括号，然后指出它们之间的嵌套是否正确：

   ```
   Enter parenteses and/or braces: ((){}{()})
   Parenteses/braces are nested properly
   ```

   提示：读入左圆括号或左花括号时，把它们像字符一样压入栈中。当读入右圆括号或右花括号时，把栈顶的项弹出，并且检查弹出项是否是匹配的圆括号或花括号。（如果不是，那么圆括号或花括号嵌套不正确。）当程序读入换行符时，检查栈是否为空。如果为空，那么圆括号或花括号匹配；如果栈不为空（或者如果曾经调用过stack_underflow函数），那么圆括号或花括号不匹配。如果调用stack_overflow函数，程序显示信息Stack overflow，并且立刻终止。

2. 修改10.5节的poker.c程序，把数组num_in_rank和数组num_in_suit移到main函数中。main函数将把这两个数组作为实际参数传递给read_cards函数和analyze_hand函数。

3. 把数组num_in_rank、num_in_suit和card_exists从10.5节的poker.c程序中去掉。程序改用5×2的数组来存储牌。数组的每一行表示一张牌。例如，如果数组名为hand，则hand[0][0]存储第一张牌的点数，hand[0][1]存储第一张牌的花色。

4. 修改10.5节的poker.c程序，使其能识别牌的另一种类别——“同花大顺”（同花色的A、K、Q、J和10）。同花大顺的级别高于其他所有的类别。

5. 修改10.5节的poker.c程序，使其能识别“小A顺”（即A、2、3、4和5）。

6. 有些计算器（尤其是惠普的计算器）使用逆波兰表示法（Reverse Polish Notation，RPN）来书写数学表达式。在这一表示法中，运算符放置在操作数的后面而不是放在操作数中间。例如，在逆波兰表示法中1+2将表示为1 2 +，而1+2*3将表示为1 2 3 * +。逆波兰表达式可以很方便地用栈求值。算法从左向右读取运算符和操作数，并执行下列步骤：

   1. 当遇到操作数时，将其压入栈中。
   2. 当遇到运算符时，从栈中弹出它的操作数，执行运算并把结果压入栈中。

   编写程序对逆波兰表达式求值。操作数都是个位的整数，运算符为+、-、*、/和=。遇到运算符=时，将显示栈顶项，随后清空栈并提示用户计算新的表达式。这一过程持续进行，直到用户输入一个既不是运算符也不是操作数的字符为止：

   ```
   Enter an RPN expression: 1 2 3 * + =
   Value of expression: 7
   Enter an RPN expression: 5 8 * 4 9 - / =
   Value of expression: -8
   Enter an RPN expression: q
   ```

   如果栈出现上溢，程序将显示消息Expression is too complex并终止。如果栈出现下溢（例如遇到表达式1 2 + +），程序将显示消息Not enough operands in expression并终止。提示：把10.2节的栈代码整合到你的程序中。使用scanf(" %c", &ch)读取运算符和操作数。

7. 编写程序，提示用户输入一个数并显示该数，使用字符模拟七段显示器的效果：

   ```
   Enter a number: 491-9014
   ```

   非数字的字符都将被忽略。在程序中用一个名为MAX_DIGITS的宏来控制数的最大位数，MAX_DIGITS的值为10。如果数中包含的数位大于这个数，多出来的数位将被忽略。提示：使用两个外部数组，一个是segments数组（见第8章的练习题6），用于存储表示数字和段之间对应关系的数据；另一个是digits数组，这是一个3行（因为显示出来的每个数字高度都是3个字符）、MAX_DIGITS×4列（数字的宽度是3个字符，但为了可读性需要在数字之间增加一个空格）的字符数组。编写4个函数：main、clear_digits_array、process_digit和print_digits_array。下面是后3个函数的原型：

   ```
   void clear_digits_array(void);
   void process_digit(int digit, int position);
   void print_digits_array(void);
   ```

   clear_digits_array函数在digits数组的所有元素中存储空白字符。process_digit函数把digit的七段表示存储到digits数组的指定位置（位置为0~MAX_DIGITS-1）。print_digits_array函数分行显示digits数组的每一行，产生的输出如示例图所示。

## 第十一章 指针

### 练习题

11.2节

1. 如果i是变量，且p指向i，那么下列哪些表达式是i的别名？
    (a) *p
    (b) &p
    (c) *&p
    (d) &*p
    (e) *i
    (f) &i
    (g) *&i
    (h) &*i

11.3节

1. 如果i是int类型变量，且p和q是指向int的指针，那么下列哪些赋值是合法的？
    (a) p = i;
    (b) *p = &i;
    (c) &p = q;
    (d) p = &q;
    (e) p = *&q;
    (f) p = q;
    (g) *p = q;
    (h) *p = *q;

11.4节

1. 假设下列函数用来计算数组a中元素的和以及平均值，且数组a长度为n。avg和sum指向函数需要修改的变量。但是，这个函数有几个错误，请找出这些错误并修改。

   ```
   void avg_sum(double a[], int n, double *avg, double *sum) {  
       int i;  
       sum = 0.0;  
       for (i = 0; i < n; i++)  
           sum += a[i];  
       avg = sum / n;  
   }
   ```

2. 编写下列函数：

   ```
   void swap(int *p, int *q);  
   ```

   当传递两个变量的地址时，swap函数应该交换两个变量的值：

   ```
   swap(&i, &j);  /* exchange values of i and j */
   ```

3. 编写下列函数：

   ```
   void split_time(long total_sec, int *hr, int *min, int *sec);  
   ```

   total_sec 是以从午夜开始计算的秒数所表示的时间。hr、min 和 sec 都是指向变量的指针，这些变量在函数中将分别存储以小时（0~~23）、分钟（0~~59）和秒（0~59）为单位的等价时间。

4. 编写下列函数：

   ```
   void find_two_largest(int a[], int n, int *largest, int *second_largest);
   ```

   当传递长度为n的数组a时，函数将在数组a中搜寻最大元素和第二大元素，把它们分别存储在由largest和second_largest指向的变量中。

5. 编写下列函数：

   ```
   void split_date(int day_of_year, int year, int *month, int *day);
   ```

   day_of_year 是1~366范围内的整数，表示year指定的那一年中的特定一天。month和day是指向变量的指针，相应的变量在函数中分别存储等价的月份（1~12）和该月中的日期（1~31）。

11.5节

1. 编写下列函数：

   ```
   int *find_largest(int a[], int n);
   ```

   当传入长度为n的数组a时，函数将返回指向数组最大元素的指针。

### 编程题

1. 修改第2章的编程题7，使其包含下列函数：

```
void pay_amount(int dollars, int *twenties, int *tens, int *fives, int *ones);
```

​	函数需要确定：为支付参数 `dollars` 表示的付款金额，所需20美元、10美元、5美元和1美元钞票的最小数目。`twenties` 参数所指向的变量存储所需20美	元钞票的数目，`tens`、`fives` 和 `ones` 参数类似。

2. 修改第5章的编程题8，使其包含下列函数：

```
void find_closest_flight(int desired_time, int *departure_time, int *arrival_time);
```

​	函数需查出起飞时间与 `desired_time`（用从午夜开始的分钟数表示）最接近的航班。该航班的起飞时间和抵达时间（也都用从午夜开始的分钟数表示）将分	别存储在 `departure_time` 和 `arrival_time` 所指向的变量中。

3. 修改第6章的编程题3，使其包含下列函数：

```
void reduce(int numerator, int denominator, int *reduced_numerator, int *reduced_denominator);
```

​	`numerator` 和 `denominator` 分别是分数的分子和分母。`reduced_numerator` 和 `reduced_denominator` 是指向变量的指针，相应变量中分别存储把分	数化为最简形式后的分子和分母。

4. 修改 10.5节的 `poker.c` 程序，把所有的外部变量移到 `main` 函数中，并修改各个函数，使它们通过参数进行通信。`analyze_hand` 函数需要修改变量 `straight`、`flush`、`four`、`three` 和 `pairs`，所以它需要以指向这些变量的指针作为参数。

## 第十二章 指针和数组

### 练习题

12.1 节

1. 假设下列声明是有效的：
    `int a[] = {5, 15, 34, 54, 14, 2, 52, 72}; int *p = &a[1], *q = &a[5];`
    (a) `*(p + 3)`的值是多少？
    (b) `*(q - 3)`的值是多少？
    (c) `q - p` 的值是多少？
    (d) `p < q` 的结果是真还是假？
    (e) `*p < *q` 的结果是真还是假？
2. 假设 `high`、`low` 和 `middle` 是具有相同类型的指针变量，并且 `low` 和 `high` 指向数组元素。下面的语句为什么是不合法的，如何修改它？
    `middle = (low + high) / 2;`

12.2 节

3. 下列语句执行后，数组 `a` 的内容是什么？

 `#define N 10`
 `int a[N] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};`
 `int *p = &a[0], *q = &a[N-1], temp;`
 `while (p < q) { temp = *p; *p++ = *q; *q-- = temp; }`

1. 用指针变量 `top_ptr` 代替整型变量 `top` 来重新编写 10.2 节的函数 `make_empty`、`is_empty` 和 `is_full`。

12.3 节

5. 假设 `a` 是一维数组而 `p` 是指针变量。如果刚执行了赋值操作 `p = a`，下列哪些表达式会因为类型不匹配而不合法？其他的表达式中哪些为真（有非零值）？

 (a) `p == a[0]`
 (b) `p == &a[0]`
 (c) `*p == a[0]`
 (d) `p[0] == a[0]`

1. 用指针算术运算代替数组取下标来重新编写下面的函数。（换句话说，消除变量 `i` 和所有用 `[]` 运算符的地方。）要求改动尽可能少。

   ```
   int sum_array(const int a[], int n)  
   {  
       int i, sum;  
       sum = 0;  
       for (i = 0; i < n; i++)  
           sum += a[i];  
       return sum;  
   }
   ```

2. 编写下列函数：
    `bool search(const int a[], int n, int key);`
    `a` 是待搜索的数组，`n` 是数组中元素的数量，`key` 是搜索键。如果 `key` 与数组 `a` 的某个元素匹配了，那么 `search` 函数返回 `true`；否则返回 `false`。要求使用指针算术运算而不是取下标来访问数组元素。

3. 用指针算术运算代替数组取下标来重新编写下面的函数。（换句话说，消除变量 `i` 和所有用到 `[]` 运算符的地方。）要求改动尽可能少。

   ```
   void store_zeros(int a[], int n)  
   {  
       int i;  
       for (i = 0; i < n; i++)  
           a[i] = 0;  
   }
   ```

4. 编写下列函数：
    `double inner_product(const double *a, const double *b, int n);`
    `a` 和 `b` 都指向长度为 `n` 的数组。函数返回 `a[0] * b[0] + a[1] * b[1] + ... + a[n-1] * b[n-1]`。要求使用指针算术运算而不是取下标来访问数组元素。

5. 修改 11.5 节的 `find_middle` 函数，用指针算术运算计算返回值。

6. 修改 `find_largest` 函数，用指针算术运算（而不是取下标）来访问数组元素。编写下面的函数：

```
void find_two_largest(const int *a, int n, int *largest, int *second_largest);  
```

`a` 指向长度为 `n` 的数组。函数从数组中找出最大和第二大的元素，并把它们分别存储到由 `largest` 和 `second_largest` 指向的变量中。要求使用指针算术运算而不是取下标来访问数组元素。

12.4 节

13. 8.2 节有一个代码段用两个嵌套的 `for` 循环初始化用作单位矩阵的数组 `ident`。请重新编写这段代码，采用一个指针来逐个访问数组中的元素，且每次一个元素。提示：因为不能用 `row` 和 `col` 来索引变量，所以不会很容易知道应该在哪里存储 1。但是，可以利用数组的下列事实：第一个元素必须是 1，接着的 N 个元素都必须是 0，再接下来的元素是 1，以此类推。用变量来记录已经存储的连续的 0 的数量。当计数达到 N 时，就是存储 1 的时候了。

1. 假设下面的数组含有一周 7 天 24 小时的温度读数，数组的每一行是某一天的读数：
    `int temperatures[7][24];`
    编写一条语句，使用 `search` 函数（见练习题 7）在整个 `temperatures` 数组中寻找值 32。
2. 编写一个循环来显示（练习题 14 中的）`temperatures` 数组中第 `i` 行存储的所有温度读数。利用指针来访问该行中的每个元素。
3. 编写一个循环来显示（练习题 14 中的）`temperatures` 数组一星期中每一天的最高温度。循环体应该调用 `find_largest` 函数，且一次传递数组的一行。
4. 用指针算术运算代替数组取下标来重新编写下面的函数。（换句话说，消除变量 `i`、`j` 和所有用到 `[]` 运算符的地方。）要求使用单层循环而不是嵌套循环。

```
int sum_two_dimensional_array(const int a[][LEN], int n)  
{  
    int i, j, sum = 0;  
    for (i = 0; i < n; i++)  
        for (j = 0; j < LEN; j++)  
            sum += a[i][j];  
    return sum;  
}
```

1. 编写第 9 章练习题 13 中描述的 `evaluate_position` 函数，使用指针算术运算而不是取下标来访问数组元素。要求使用单层循环而不是嵌套循环。

### 编程题

1.  (a) 编写程序读一条消息，然后逆序打印出这条消息：

   ```
   Enter a message: Don't get mad, get even.
   Reversal is: .neve teg ,dam teg t'noD
   ```

   提示：一次读取消息中的一个字符（用 `getchar` 函数），并且把这些字符存储在数组中，当数组满了或者读到字符 `'\n'` 时停止读操作。

   (b) 修改上述程序，用指针代替整数来跟踪数组中的当前位置。

   (a) 编写程序读一条消息，然后检查这条消息是否是回文（消息中的字母从左往右读和从右往左读是一样的）：

   ```
   Enter a message: He lived as a devil, eh?
   Palindrome
   ```

   ```
   Enter a message: Madam, I am Adam.
   Not a palindrome
   ```

   忽略所有不是字母的字符。用整型变量来跟踪数组中的位置。

   (b) 修改上述程序，使用指针代替整数来跟踪数组中的位置。

   1. 请利用数组名可以用作指针的事实简化编程题 1(b) 的程序。
   2. 请利用数组名可以用作指针的事实简化编程题 2(b) 的程序。
   3. 修改第 8 章的编程题 14，用指针而不是整数来跟踪包含该语句的数组的当前位置。
   4. 修改 9.6 节的 `qsort.c` 程序，使得 `low`、`high` 和 `middle` 是指向数组元素的指针而不是整数。`split` 函数应返回指针而不再是整数。
   5. 修改 11.4 节的 `maxmin.c` 程序，使得 `max_min` 函数使用指针而不是整数来跟踪数组中的当前位置。

## 第十三章

### 练习题

**13.3节**

1. 下面的函数调用应该只输出一个换行符，但是其中有一些是错误的。请指出哪些调用是错误的，并说明理由。

   (a) `printf("%c", '\n');`
    (b) `printf("%s", '\n');`
    (c) `printf("%s", "\n");`
    (d) `printf("%s", "\n");`
    (e) `printf('\n');`
    (f) `printf("\n");`
    (g) `putchar('\n');`
    (h) `putchar("\n");`
    (i) `puts('\n');`
    (j) `puts("\n");`
    (k) `puts("");`

2. 假设 `p` 的声明如下：
    `char *p = "abc";`
    下列哪些函数调用是合法的？请说明每个合法的函数调用的输出，并解释为什么其他的是非法的。

   (a) `putchar(p);`
    (b) `putchar(*p);`
    (c) `puts(p);`
    (d) `puts(*p);`

3. 假设按如下方式调用 `scanf` 函数：
    `scanf("%d%s%d", &i, s, &j);`
    如果用户输入 `12abc34 56def78`，那么调用后 `i`、`s` 和 `j` 的值分别是多少？（假设 `i` 和 `j` 是 `int` 类型变量，`s` 是字符数组。）

4. 按照下述要求分别修改 `read_line` 函数。

   (a) 在开始存储输入字符前跳过空白字符。
    (b) 在遇到第一个空白字符时停止读入。提示：调用 `isspace` 函数（23.5节）来检查字符是否为空白字符。
    (c) 在遇到第一个换行符时停止读入，然后把换行符存储到字符串中。
    (d) 把没有空间存储的字符留下以备后用。

**13.4节**

1. (a) 编写名为 `capitalize` 的函数，把参数中的字母都改为大写字母。参数是空字符结尾的字符串，且此字符串可以包含任意字符而不仅是字母。使用数组取下标操作访问字符串中的字符。提示：使用 `toupper` 函数（23.5节）把每个字符转换成大写。

   (b) 重写 `capitalize` 函数，这次使用指针算术运算来访问字符串中的字符。

2. 编写名为 `censor` 的函数，把字符串中出现的每一处 `foo` 替换为 `xxx`。例如，字符串 `"food fool"` 会变为 `"xxxd xxxl"`。在不失清晰性的前提下程序越短越好。

**13.5节**

1. 假设 `str` 是字符数组，下面哪条语句与其他 3 条语句不等价？

   (a) `*str = 0;`
    (b) `str[0] = '\0';`
    (c) `strcpy(str, "");`
    (d) `strcat(str, "");`

2. 在执行下列语句后，字符串 `str` 的值是什么？

   ```
   strcpy(str, "tire-bouchon");
   strcpy(&str[4], "d-or-wi");
   strcat(str, "red?");
   ```

3. 在执行下列语句后，字符串 `s1` 的值是什么？

   ```
   strcpy(s1, "computer");
   strcpy(s2, "science");
   if (strcmp(s1, s2) < 0)
       strcat(s1, s2);
   else
       strcat(s2, s1);
   s1[strlen(s1)-6] = '\0';
   ```

4. 下面的函数用于创建字符串的相同副本。请指出这个函数中的错误。

   ```
   char *duplicate(const char *p) {
       char *q;
       strcpy(q, p);
       return q;
   }
   ```

5. 本章的“问与答”部分说明了利用数组取下标操作来编写 `strcmp` 函数的方法。请修改此函数，改用指针算术运算来编写。

6. 编写下面的函数：

   ```
   void get_extension(const char *file_name, char *extension);
   ```

   `file_name` 指向包含文件名的字符串。函数把文件名的扩展存储在 `extension` 指向的字符串中。例如，如果文件名是 `"memo.txt"`，函数将把 `"txt"` 存储到 `extension` 指向的字符串中。如果文件名没有扩展名，函数将在 `extension` 指向的字符串中存储一个空字符串（仅由一个空字符构成）。在函数中使用 `strlen` 函数和 `strcpy` 函数，使其尽可能简单。

7. 编写下面的函数：

   ```
   void build_index_url(const char *domain, char *index_url);
   ```

   `domain` 指向包含因特网域名的字符串，例如 `"knking.com"`。函数应在该字符串的前面加上 `"http://www."`，在后面加上 `"/index.html"`，并把结果存储到 `index_url` 指向的字符串中。（在这个例子中，结果为 `"http://www.knking.com/index.html"`。）可以假定 `index_url` 所指向的变量长度足以装下整个字符串。在函数中使用 `strcat` 函数和 `strcpy` 函数，使其尽可能简单。

**13.6节**

1. 下面程序的输出是什么？

   ```
   #include
   int main(void) {
       char s[] = "Hsjodi", *p;
       for (p = s; *p; p++)
           --*p;
       puts(s);
       return 0;
   }
   ```

2. 函数 `f` 如下所示：

   ```
   int f(char *s, char *t) {
       char *p1, *p2;
       for (p1 = s; *p1; p1++) {
           for (p2 = t; *p2; p2++)
               if (*p1 == *p2) break;
           if (*p2 == '\0') break;
       }
       return p1 - s;
   }
   ```

   (a) `f("abcd", "babc")` 的值是多少？
    (b) `f("abcd", "bcd")` 的值是多少？
    (c) 当传递两个字符串 `s` 和 `t` 时，函数 `f` 的返回值一般是什么？

3. 利用 13.6 节中的方法来精简 13.4 节的 `count_space` 函数。具体而言要用 `while` 循环替换 `for` 语句。

4. 编写下面的函数：

   ```
   bool test_extension(const char *file_name, const char *extension);
   ```

   `file_name` 指向包含文件名的字符串。如果文件的扩展名与 `extension` 指向的字符串匹配（不区分大小写），函数返回 `true`。例如，函数调用 `test_extension("memo.txt", "TXT")` 将返回 `true`。要求在函数中使用“搜索字符串结尾”的惯用法。提示：在比较字符之前使用 `toupper` 函数（23.5节）把字符转换成大写形式。

5. 编写下面的函数：

   ```
   void remove_filename(char *url);
   ```

   `url` 指向一个包含以文件名结尾的统一资源定位器（Uniform Resource Locator, URL）的字符串，例如 `"http://www.knking.com/index.html"`。函数应通过移除文件名和前面的斜杠来修改字符串。（在上面的例子中，结果为 `"http://www.knking.com"`。）要求在函数中使用“搜索字符串结尾”的惯用法。提示：把字符串中的最后一个斜杠替换为空字符。

### 编程题

1. 编写程序找出一组单词中“最小”单词和“最大”单词。用户输入单词后，程序根据字典顺序决定排在最前面和最后面的单词。当用户输入 4 个字母的单词时，程序停止读入。假设所有单词都不超过 20 个字母。程序会话如下：

   ```
   Enter word: dog
   Enter word: zebra
   Enter word: rabbit
   Enter word: catfish
   Enter word: walrus
   Enter word: cat
   Smallest word: cat
   Largest word: zebra
   ```

   提示：使用两个名为 `smallest_word` 和 `largest_word` 的字符串来分别记录所有输入中的“最小”单词和“最大”单词。用户每输入一个新单词，都要用 `strcmp` 函数把它与 `smallest_word` 进行比较。如果新的单词比 `smallest_word`“小”，就用 `strcpy` 函数把新单词保存到 `smallest_word` 中。用类似的方式与 `largest_word` 进行比较。用 `strlen` 函数来判断用户是否输入了 4 个字母的单词。

2. 按如下方式改进 13.5 节的 `remind.c` 程序：

   (a) 如果对应的日期为负数或大于 31，程序显示出错消息，并忽略提醒。提示：使用 `continue` 语句。
    (b) 允许用户输入日期、24 小时格式的时间和提醒。显示的提醒列表必须先按日期排序，然后再按时间排序。（原始的 `remind.c` 程序允许用户输入时间，但是它把时间作为提醒的一部分来处理。）
    (c) 程序显示一年的提醒列表。要求用户按照 `月/日` 的格式输入日期。

3. 修改 8.2 节的 `deal.c` 程序，使它显示出牌的全名：

   ```
   Enter number of cards in hand: 5
   Your hand:
   Seven of clubs
   Two of spades
   Five of diamonds
   Ace of spades
   Two of hearts
   ```

   提示：用指向字符串的指针的数组来替换数组 `rank_code` 和数组 `suit_code`。

4. 编写名为 `reverse.c` 的程序，用来逆序输出命令行参数。如果输入 `reverse void and null` 运行程序，产生的输出应为：

   ```
   null and void
   ```

5. 编写名为 `sum.c` 的程序，用来对命令行参数（假设都是整数）求和。如果输入 `sum 8 24 62` 运行程序，产生的输出应为：

   ```
   Total: 94
   ```

   提示：用 `atoi` 函数（26.2 节）把每个命令行参数从字符串格式转换为整数格式。

6. 改进 13.7 节的程序 `planet.c`，使它在对命令行参数和 `planets` 数组中的字符串进行比较时忽略大小写。

7. 修改第 5 章的编程题 11，用字符串指针数组取代 `switch` 语句。例如，现在不再用 `switch` 语句来显示第一位数字对应的单词，而把该数字用作下标，从包含 `"twenty"`、`"thirty"` 等字符串的数组中搜索。

8. 修改第 7 章的编程题 5，使其包含如下函数：

   ```
   int compute_scrabble_value(const char *word);
   ```

   函数返回 `word` 所指向的字符串的拼字值。

9. 修改第 7 章的编程题 10，使其包含如下函数：

   ```
   int compute_vowel_count(const char *sentence);
   ```

   函数返回 `sentence` 所指向的字符串中元音字母的个数。

10. 修改第 7 章的编程题 11，使其包含如下函数：

    ```
    void reverse_name(char *name);
    ```

    在参数 `name` 指向的字符串中，名在前、姓在后。在修改后的字符串中，姓在前，其后跟一个逗号和一个空格，然后是名的首字母，最后加一个点。原始的字符串中，名的前面、名和姓之间、姓的后面都可以有额外的空格。

11. 修改第 7 章的编程题 13，使其包含如下函数：

    ```
    double compute_average_word_length(const char *sentence);
    ```

    函数返回 `sentence` 所指向的字符串中单词的平均长度。

12. 修改第 8 章的编程题 14，读取句子时把单词存储在一个二维的 `char` 类型数组中，每行存储一个单词。假定句子中的单词数不超过 30，且每个单词的长度都不超过 20 个字符。注意，要在每个单词的后面存储一个空字符，使其可以作为字符串处理。

13. 修改第 8 章的编程题 15，使其包含如下函数：

    ```
    void encrypt(char *message, int shift);
    ```

    参数 `message` 指向一个包含待加密消息的字符串，`shift` 表示消息中每个字母需要移动的位数。

14. 修改第 8 章的编程题 16，使其包含如下函数：

    ```
    bool are_anagrams(const char *word1, const char *word2);
    ```

    如果 `word1` 和 `word2` 指向的字符串是变位词，函数返回 `true`。

15. 修改第 10 章的编程题 6，使其包含如下函数：

    ```
    int evaluate_RPN_expression(const char *expression);
    ```

    函数返回 `expression` 指向的 RPN 表达式的值。

16. 修改第 12 章的编程题 1，使其包含如下函数：

    ```
    void reverse(char *message);
    ```

    函数的作用是反转 `message` 指向的字符串。提示：使用两个指针，初始时一个指向字符串的第一个字符，另一个指向最后一个字符；交换这两个字符，然后让两个指针相向移动；重复这一过程直到两个指针相遇。

17. 修改第 12 章的编程题 2，使其包含如下函数：

    ```
    bool is_palindrome(const char *message);
    ```

    如果 `message` 指向的字符串是回文，函数返回 `true`。

18. 编写程序，按“月/日/年”的格式接受用户输入的日期，然后按“月 日，年”的格式显示，其中“月”用英文全名：

    ```
    Enter a date (mm/dd/yyyy): 2/17/2011
    You entered the date February 17, 2011
    ```

    用字符串指针数组存储月份的名字。

## 第十四章

### 练习题

14.3 节  1.编写宏来计算下面的值。  (a) x 的立方。  (b) n 除以 4的余数。  (c) 如果 x与y的乘积小于100则值为1，否则值为0。  你写的宏始终正常工作吗？如果不是，哪些参数会导致失败呢？  2. 编写一个宏NELEMS(a)来计算一维数组a中元素的个数。提示：见8.1节中有关sizeof运算符的 讨论。  3.假定DOUBLE 是如下宏：  #define DOUBLE(x) 2*x  (a) DOUBLE(1+2)的值是多少？  (b) 4/DOUBLE(2)的值是多少？  (c) 改正 DOUBLE 的定义。 针对下面每一个宏，举例说明宏的问题，并提出修改方法。  (a) #define AVG(x,y)  (x+y)/2  (b) #define AREA(x,y) (x)*(y)  *5. 假定 TOUPPER 定义成下面的宏：  #define TOUPPER(c) ('a'<=(c)&&(c)<='z'?(c)-'a'+'A':(c))  假设s是一个字符串，i是一个int类型变量。给出下面每个代码段产生的输出。  (a) strcpy(s, "abcd");    i = 0;     putchar(TOUPPER(s[++i]));  (b) strcpy(s, "0123");    i = 0;    putchar(TOUPPER(s[++i]));  6. (a) 编写宏 DISP(f,x)，使其扩展为printf 函数的调用，显示函数f在参数为x时的值。例如：  DISP(sqrt, 3.0);  应该扩展为  printf("sqrt(%g) = %g\n", 3.0, sqrt(3.0));  (b) 编写宏DISP2(f,x,y)，类似DISP 但应用于有两个参数的函数。  *7. 假定 GENERIC_MAX 是如下宏：  #define GENERIC_MAX(type)   \  type type##_max(type x, type y) \  {           \  return x > y ? x : y;   }   \  (a) 写出 GENERIC_MAX(long)被预处理器扩展后的形式。  (b) 解释为什么GENERIC_MAX 不能应用于unsigned long 这样的基本类型。  (c) 如何使GENERIC_MAX 可以用于unsigned long 这样的基本类型？提示：不要改变GENERIC_MAX 的定义。  *8. 如果需要一个宏，使它扩展后包含当前行号和文件名。换言之，我们想把  const char *str = LINE_FILE;  扩展为  const char *str = "Line 10 of file foo.c";  其中foo.c是包含程序的文件，10是调用LINE_FILE的行号。警告：这个练习仅针对高级程序员。尝 试编写前请认真阅读“问与答”部分的内容！  9.编写下列带参数的宏。  (a) CHECK(x,y,n)——x 和y 都落在0~n1范围内（包括端点）时值为1。  (b) MEDIAN(x,y,z)——计算x、y 和z的中位数。  (c) POLYNOMIAL(x)——计算多项式3x5+2x45x3x2+7x6。  10. 函数常常（但不总是）可以写为带参数的宏。讨论函数的哪些特性会使其不适合写为宏的形式。  11.  C程序员常用fprintf函数（ 22.3节）来输出出错消息：  345 fprintf(stderr, "Range error: index = %d\n", index);  其中stderr流（22.1节）是C的“标准误差”流。其他参数与printf函数的参数一样，以格式串 开始。编写名为ERROR的宏来生成上面的fprintf调用，宏的参数是格式串和需要显示的项：  ERROR("Range error: index = %d\n", index);   14.4节  12. 假定宏M有如下定义：   #define M 10    下面哪些测试会失败？   (a) #if M   (b) #ifdef M   (c) #ifndef M   (d) #if defined(M)   (e) #if !defined(M)  13. (a) 指出下面的程序在预处理后的形式。因为包含了头而多出来的代码行可以忽略。   #include    #define N 100   void f(void);   int main(void)  {   f();  #ifdef N  #undef N  #endif   return 0;  }   void f(void)  {  #if defined(N)   printf("N is %d\n", N);  #else   printf("N is undefined\n");  #endif  }    (b) 这个程序的输出是什么？  *14.  指出下面的程序在预处理后的形式。其中有几行可能会导致编译错误，请找出这些错误。   #define N = 10  #define INC(x) x+1  #define SUB (x,y) x-y  #define SQR(x) ((x)*(x))  #define CUBE(x) (SQR(x)*(x))  #deflne M1(x,y) x##y  #define M2(x,y) #x #y   int main(void)  {   int a[N], i, j, k, m;   #ifdef N   i = j;\#else   j = i;  #endif   i = 10 * INC(j);   i = SUB(j, k);   i = SQR(SQR(j));   i = CUBE(j);   i = M1(j, k);   puts(M2(i, j));  #undef SQR   i = SQR(j);  #define SQR   i = SQR(j);   return 0;  }  15. 假定程序需要用英语、法语或西班牙语显示消息。使用条件编译编写程序片段，根据指定的宏是否 定义来显示出下列3条消息中的一条。  Insert Disk 1  (如果定义了ENGLISH)  Inserez Le Disque 1 (如果定义了FRENCH)  Inserte El Disco 1  (如果定义了SPANISH)  14.5 节  *16.  假定有下列宏定义：  #define IDENT(x) PRAGMA(ident #x)  #define PRAGMA(x) _Pragma(#x)  下面的代码行在宏扩展之后会变成什么样子？  IDENT(foo)

## 第十五章

### 练习题

15.1节  1. 15.1节列出了把程序分割成多个源程序的几个优点。   (a) 请描述几个其他的优点。   (b) 请描述一些缺点。  15.2节   2. 下面哪个不应该放置在头文件中？为什么？   (a) 函数原型。   (b) 函数定义。   (c) 宏定义。   (d) 类型定义。  3. 我们已经知道，如果文件是我们自己编写的，那么用#include <文件>代替#include "文件"可能无 法工作。如果文件是系统头，那么用#include "文件"代替#include <文件>是否有什么问题？  4. 假设debug.h是具有如下内容的头文件：   #ifdef DEBUG  #define PRINT_DEBUG(n) printf("Value of " #n ": %d\n", n)  #else  #define PRINT_DEBUG(n)  #endif    假定源文件testdebug.c的内容如下：   #include    #define DEBUG  #include "debug.h"   int main(void)  {    int i = 1, j = 2, k = 3;   #ifdef DEBUG   printf("Output if DEBUG is defined:\n");  #else   printf("Output if DEBUG is not defined:\n");  #endif    PRINT_DEBUG(i);   PRINT_DEBUG(j);   PRINT_DEBUG(k);   PRINT_DEBUG(i + j);   PRINT_DEBUG(2 * i + j - k);    return 0;  }     (a) 程序执行时的输出是什么？    (b) 如果从testdebug.c中删去#define指令，输出又是什么？   (c) 解释(a)和(b)中的输出为什么不同。   (d) 为了使PRINT_DEBUG能起到预期的效果，把DEBUG宏的定义放在包含debug.h的指令之前是否有 必要？验证你的结论。 15.4 节  5.假设程序由3个源文件构成，main.c、f1.c和f2.c，此外还包括两个头文件f1.h和f2.h。全部3个源文 件都包含f1.h，但是只有f1.c和f2.c包含f2.h。为此程序编写makefile。假设使用GCC，且可执行文 件命名为demo。  6 .  374  下面的问题涉及练习题5描述的程序。  (a) 当程序第一次构建时，需要对哪些文件进行编译？  (b) 如果在程序构建后对f1.c进行了修改，那么需要对哪个（些）文件进行重新编译？  (c) 如果在程序构建后对f1.h进行了修改，那么需要对哪个（些）文件进行重新编译？  (d) 如果在程序构建后对f2.h进行了修改，那么需要对哪个（些）文件进行重新编译？ 

### 编程题

1. 15.3 节的 justify 程序通过在单词间插入额外的空格来调整行。当前编写的函数writen_line 的工作 方法是，与开始处的单词间隔相比，靠近行末尾单词的间隔略微宽一些。（例如，靠近末尾的单词彼 此之间可能有 3个空格，而靠近开始的单词彼此之间可能只有 2个空格。）请修改函数 write_line 来改进此程序，要求函数能够使较大的间隔交替出现在行的末尾和行的开头。  2.修改15.3节的justify程序，在read_word 函数（而不是main函数）中为被截短的单词的结尾存储* 字符。  3.修改 9.6节的 qsort.c程序，把 quicksort 函数和 split 函数放在一个单独的文件quicksort.c中。 创建一个名为quicksort.h的头文件来包含这两个函数的原型，并让qsort.c和quicksort.c都包含这个 头文件。  375  4.修改 13.5 节的 remind.c 程序，把 read_line 函数放在一个单独的文件 readline.c中。创建一个名为 readline.h 的头文件来包含这个函数的原型，并让remind.c和readline.c都包含这个头文件。  5.修改第10章的编程题6，使其具有独立的stack.h和stack.c文件，如15.2节所述。

## 第十六章

### 练习题

16.1 节  1.在下列声明中，结构x和结构y都拥有名为x和y的成员：struct { int x,  y; } x;  struct { int x,  y; } y;  单独出现时，这两个声明是否合法？两个声明是否可以同时出现在程序中呢？验证你的答案。  2. (a) 声明名为 c1、c2 和c3 的结构变量，每个结构变量都拥有double类型的成员real和imaginary。  (b) 修改(a)中的声明，使c1的成员初始值为0.0和1.0，c2的成员初始值为1.0和0.0。（c3不初始化。）  (c) 编写语句把c2的成员复制给c1。这项操作可以在一条语句中完成，还是必须要两条语句？  (d) 编写语句把c1和c2的对应成员相加，并且把结果存储在c3中。  16.2 节  3. (a) 说明如何为具有double 类型的成员real和imaginary 的结构声明名为complex的标记。  (b) 利用标记complex 来声明名为c1、c2和c3的变量。  (c) 编写名为 make_complex 的函数，此函数用来把两个实际参数（类型都是 double 类型）存储在 complex 结构中，然后返回此结构。  (d) 编写名为add_complex 的函数，此函数用来把两个实际参数（都是complex结构）的对应成员相 加，然后返回结果（另一个complex结构）。  4. 重做练习题3，这次要求使用名为Complex的类型。  5.编写下列函数，假定date结构包含三个成员：month、day和year（都是int类型）。  (a) int day_of_year(struct date d);  返回d是一年中的第多少天（1~366范围内的整数）。  (b) int compare_dates(struct date d1, struct date d2);  如果日期d1在d2之前，返回1；如果d1在d2之后，返回+1；如果d1和d2相等，返回0。  6.编写下列函数，假定time结构包含三个成员：hours、minutes和seconds（都是int类型）。  struct time split_time(long total_seconds);  total_seconds 是从午夜开始的秒数。函数返回一个包含等价时间的结构，等价的时间用小时 （0~23）、分钟（0~59）和秒（0~59）表示。  7.假定fraction 结构包含两个成员：numerator和denominator（都是int类型）。编写函数完成下 列分数运算。  (a) 把分数 f 化为最简形式。提示：为了把分数化为最简形式，首先计算分子和分母的最大公约数 （GCD），然后把分子和分母都除以该最大公约数。  (b) 把分数f1 和f2相加。  (c) 从分数f1 中减去分数f2。  (d) 把分数f1 和f2相乘。  (e) 用分数f1 除以分数f2。  分数f、f1和f2都是struct fraction类型的参数。每个函数返回一个struct fraction类 型的值。(b)~(e)中函数返回的分式应为最简形式。提示：可以使用(a)中的函数辅助编写(b)~(e)中的 函数。  8.设 color 是如下的结构：  struct color {  int red;  int green;  int blue;  };  407 408 (a) 为 struct color 类型的 const 变量MAGENTA 编写声明，成员的值分别为255、0和255。(b)重复上题，但是使用指示器。要求不指定green的值，使其默认为0。  9.编写下列函数。（color结构的定义见练习题8。）  (a) struct color make_color(int red, int green, int blue);  函数返回一个包含指定的red、green和blue值的color结构。如果参数小于0，把结构的对应 成员置为0。如果参数大于255，把结构的对应成员置为255。  (b) int getRed(struct color c);  函数返回c的red成员的值。  (c) bool equal_color(struct color color1, struct color color2);  如果color1 和color2 的对应成员相等，函数返回true。  (d) struct color brighter(struct color c);  函数返回一个表示颜色c的更亮版本的color 结构。该结构等同于c，但每个成员都除以了0.7 （把结果截断为整数）。但是，有３种特殊情形：(1) 如果c的所有成员都为0，函数返回一个所 有成员的值都为3的颜色；(2) 如果c的任意成员比0大且比3小，那么在除以0.7之前将其置为 3；(3) 如果除以0.7之后得到了超过255的成员，将其置为255。  (e) struct color darker(struct color c);  函数返回一个表示颜色c的更暗版本的color 结构。该结构等同于c，但每个成员都乘以了0.7 （把结果截断为整数）。  16.3 节  10. 下列结构用来存储图形屏幕上的对象信息。  struct point { int x,  y; };  struct rectangle { struct point upper_left, lower_right; };  409  结构point 用来存储屏幕上点的x和y坐标，结构rectangle用来存储矩形的左上和右下坐标点。 编写函数，要求可以在rectangle结构变量r上执行下列操作，且r作为实际参数传递。  (a) 计算 r的面积。  (b) 计算r的中心，并且把此中心作为point值返回。如果中心的x或y坐标不是整数，在point结 构中存储截断后的值。  (c) 将 r 沿x轴方向移动x个单位，沿 y 轴移动y个单位，返回r修改后的内容。（x和y是函数的另 外两个实际参数。）  (d) 确定点p是否位于r内，返回true或者false。（p是struct point类型的另外一个实际参数。）  16.4 节  11.  假设s是如下结构：  struct {   double a;   union {     char b[4];     double c;     int d;   } e;   char f[4];  } s;  如果char类型值占1字节，int类型值占4字节，double类型值占8字节，那么C编译器将为s分 配多大的内存空间？（假设编译器没有在成员之间留“空洞”。）  12. 假设u是如下联合：union {   double a;   struct {     char b[4];     double c;     int d;   } e;   char f[4];  } u;  如果char类型值占1字节，int类型值占4字节，double类型值占8字节，那么C编译器将为u分 配多大的内存空间？（假设编译器没有在成员之间留“空洞”。）  13. 假设s是如下结构（point是在练习题10中声明的结构标记）：  struct shape {   int shape_kind;        /* RECTANGLE or CIRCLE */   struct point center;   /* coordinates of center */   union {     struct {       int height, width;     } rectangle;     struct {       int radius;     } circle;   } u;  } s;  如果 shape_kind 的值为 RECTANGLE，那么 height 和 width 成员分别存储矩形的两维。如果 shape_kind的值为CIRCLE，那么radius成员存储圆形的半径。请指出下列哪些语句是合法的，并 说明如何修改不合法的语句。  (a) s.shape_kind = RECTANGLE;  (b) s.center.x = 10;  (c) s.height = 25;  (d) s.u.rectangle.width = 8;  (e) s.u.circle = 5;  (f)  s.u.radius = 5;  14. 假设shape 是练习题13中声明的结构标记。编写函数在shape类型结构变量s上完成下列操作，并 且s作为实际参数传递给函数。  (a) 计算 s 的面积。  (b) 将 s 沿x轴方向移动x个单位，沿 y 轴移动y个单位，返回s修改后的内容。（x和y是函数的另外 两个实际参数。）  (c) 把 s 缩放c倍（c是double 类型的值），返回 s修改后的内容。（c是函数的另外一个实际参数。）  16.5 节  15. (a) 为枚举声明标记，此枚举的值表示一周中的7天。  (b) 用 typedef 定义(a)中枚举的名字。  16. 下列关于枚举常量的叙述，哪些是正确的？  (a) 枚举常量可以表示程序员指定的任何整数。  (b) 枚举常量具有的性质和用#define创建的常量的性质完全一样。  (c) 枚举常量的默认值为0, 1, 2, …。 (d) 枚举中的所有常量必须具有不同的值。   (e) 枚举常量在表达式中可以作为整数使用。  17. 假设b和i以如下形式声明：   enum {FALSE, TRUE} b;  int i;    下列哪些语句是合法的？哪些是“安全的”（始终产生有意义的结果）？   (a) b = FALSE;  (b)  b = i;    (c) b++;   (d)  i = b;    (e) i = 2 * b + 1;  18. (a) 国际象棋棋盘的每个方格中可能有一个棋子，即兵、马、象、车、皇后或国王，也可能为空。每个 棋子可能是黑色的，也可能是白色的。请定义两个枚举类型：Piece用来包含7种可能的值（其 中一种为“空”），Color用来表示2种颜色。   (b) 利用(a)中的类型，定义名为Square的结构类型，使此类型可以存储棋子的类型和颜色。   (c) 利用(b)中的Square类型，声明一个名为board的8×8的数组，使此数组可以用来存储棋盘上的 全部内容。   (d) 给(c)中的声明添加初始化器，使board的初始值对应国际象棋比赛开始时的棋子布局。没有棋子 的方格值为“空”且颜色为黑色。  19. 声明一个具有如下成员的结构，其标记为pinball_machine：   name，字符串，最多有40个字符；   year，整数，表示制造年份；   type，枚举类型的值，可能的取值为EM（机电式的）和SS（固态电路的）；   players，整数，表示玩家的最大数目。  20. 假定direction变量声明如下：   enum {NORTH, SOUTH, EAST, WEST} direction;    设x和y为int类型的变量。编写switch语句测试direction的值，如果值为EAST就使x增1， 如果值为WEST就使x减1，如果值为SOUTH就使y增1，如果值为NORTH就使y减1。  21. 下列声明中，枚举常量的整数值分别是多少？   (a) enum {NUL, SOH, STX, ETX};   (b) enum {VT = 11, FF, CR};   (c) enum {SO = 14, SI, DLE, CAN = 24, EM};   (d) enum {ENQ = 45, ACK, BEL, LF = 37, ETB, ESC};  22. 枚举chess_pieces声明如下：   enum chess_pieces {KING, QUEEN, ROOK, BISHOP, KNIGHT, PAWN};    (a) 为名为piece_value的整数常数数组编写声明（包含一个初始化器），这个数组存储数200、9、 5、3、3和1，分别表示从国王到兵这些棋子。［国王的值实际上是无穷大，因为一旦王被擒（将 死）则游戏结束，但一些象棋软件会给国王分配一个类似200的较大值。］   (b) 重复上题，但是使用指示器来初始化数组。把chess_pieces中的枚举常量作为指示器的下 标使用。（提示：参考“问与答”部分的最后一个问题。）

### 编程题

1. 编写程序要求用户输入国际电话区号，然后在数组country_codes中查找它（见16.3节）。如果找 到对应的区号，程序需要显示相应的国家（地区）名称，否则显示出错消息。  2.修改16.3节的inventory.c程序，使p（显示）操作可以按零件编号的顺序显示零件。  3. 修改16.3节的inventory.c程序，使inventory 和num_parts 局部于main 函数。  4.修改16.3节的inventory.c程序，为结构part添加成员price。insert函数应该要求用户输入新商品 的价格。serach函数和print函数应该显示价格。添加一条新的命令，允许用户修改零件的价格。  5.修改第5章的编程题8，以便用一个单独的数组存储时间。数组的元素都是结构，每个结构包含航班 的起飞时间和抵达时间。（时间都是整数，表示从午夜开始的分钟数。）程序用一个循环从数组中搜 索与用户输入的时间最接近的起飞时间。  6.修改第5章的编程题9，以便用户输入的日期都存储在一个date结构（见练习题5）中。把练习题5 中的compare_dates 函数集成到你的程序中。

## 第十七章

### 练习题

17.1 节  1.每次调用时都检查函数 malloc（或其他任何内存分配函数）的返回值是件很烦人的事情。请编写一 个名为my_malloc 的函数作为malloc 函数的“包装器”。当调用函数my_malloc 并且要求分配n 字节时，它会调用malloc 函数，判断malloc 函数确实没有返回空指针，然后返回来自malloc 的 指针。如果malloc返回空指针，那么函数my_malloc显示出错消息并且终止程序。  17.2 节  452 2. 编写名为duplicate 的函数，此函数使用动态存储分配来创建字符串的副本。例如，调用p = duplicate(str);  将为和str 长度相同的字符串分配内存空间，并且把字符串str的内容复制到新字符串，然后返回 指向新字符串的指针。如果分配内存失败，那么函数duplicate返回空指针。  17.3 节  3.编写下列函数：  int *create_array(int n, int initial_value);  函数应返回一个指向动态分配的 n 元 int 型数组的指针，数组的每个成员都初始化为 initial_  value。如果内存分配失败，返回值为NULL。  17.5 节  4.假设下列声明有效：  struct point { int x, y; };  453  struct rectangle { struct point upper_left, lower_right; };  struct rectangle *p;  假设希望p指向一个rectangle结构，此结构的左上角位于(10, 25)的位置上，而右下角位于(20, 15) 的位置上。请编写一系列语句用来分配这样一个结构，并且像说明的那样进行初始化。  5. 假设f和p的声明如下所示：  struct {    union {     char a, b;     int c;   } d;   int e[5];  } f, *p = &f;  那么下列哪些语句是合法的？  (a) p->b = ' ';  (b) p->e[3] = 10;  (c)(*p).d.a = '*';  (d) p->d->c = 20;  6.请修改函数delete_from_list 使它使用一个指针变量而不是两个（即cur和prev）。  7. 下列循环希望删除链表中的全部结点，并且释放它们占用的内存。但是，此循环有错误。请解释错 误是什么并且说明如何修正错误。  for (p = first; p != NULL; p = p->next)   free(p);  8. 15.2 节描述的文件 stack.c 提供了在栈中存储整数的函数。在那一节中，栈是用数组实现的。请修改 程序stack.c从而使栈现在作为链表来存储。使用单独一个指向链表首结点的指针变量（栈“顶”）来 替换变量contents和变量top。在stack.c中编写的函数要使用此指针。删除函数is_full，用返回 true（如果创建的结点可以获得内存）或false（如果创建的结点无法获得内存）的函数push来 代替。  9.判断：如果x是一个结构而a是该结构的成员，那么(&x)->a与x.a是一样的。验证你的答案。  10. 修改 16.2节的print_part 函数，使得它的形式参数是一个指向part 结构的指针。请使用->运 算符。 编写下列函数：  int count_occurrences(struct node *list, int n);  其中形式参数list指向一个链表。函数应返回n在该链表中出现的次数。node结构的定义见17.5节。  12. 编写下列函数：  struct node *find_last(struct node *list, int n);  其中形式参数list指向一个链表。函数应返回一个指针，该指针指向最后一个包含n的结点，如果 n 不存在则返回NULL。node结构的定义见17.5节。  13. 下面的函数希望在有序链表的适当位置插入一个新结点，并返回指向新链表首结点的指针。但是， 函数无法做到在所有的情况下都正确。解释问题所在，并说明如何修正。node结构的定义见17.5节。  struct node *insert_into_ordered_list(struct node *list, struct node *new_node)  {   struct node *cur = list, *prev = NULL;   while (cur->value <= new_node->value) {     prev = cur;     cur = cur->next;   }   prev->next = new_node;   new_node->next = cur;   return list;  }  17.6 节  14. 修改函数delete_from_list（17.5节），使函数的第一个形式参数是struct node **类型（即指向 链表首结点的指针的指针），并且返回类型是void。在删除了期望的结点后，函数delete_from_list 必须修改第一个实际参数，使其指向该链表。  17.7 节  15. 请说明下列程序的输出结果，并解释程序的功能。  #include   int f1(int (*f)(int));  int f2(int i);  int main(void)  {   printf("Answer: %d\n", f1(f2));   return 0;  }  int f1(int (*f) (int))  {   int n = 0;   while ((*f)(n)) n++;   return n;  }  int f2(int i)  {   return i * i +  i - 12;  }  16. 编写下列函数。调用sum(g, i, j)应该返回g(i) + … + g(j)。  454 int sum(int (*f)(int), int start, int end);设a是有100个整数的数组。请编写函数qsort的调用，只对数组a中的后50个元素进行排序。（不 需要编写比较函数。）  18. 请修改函数compare_parts 使零件根据编号进行降序排列。  19. 请编写一个函数，要求在给定字符串作为实际参数时，此函数搜索下列所示的结构数组寻找匹配的 命令名，然后调用和匹配名称相关的函数：  struct {   char *cmd_name;   void (*cmd_pointer)(void);  } file_cmd[] =  { {"new",        new_cmd},    {"open",       open_cmd},    {"close",      close_cmd},    {"close all",  close_all_cmd},    {"save",       save_cmd},    {"save as",    save_as_cmd},    {"save all",   save_all_cmd},    {"print",      print_cmd},    {"exit" ,      exit_cmd}  };

### 编程题

1. 修改 16.3节的程序 inventory.c，使其可以对数组 inventory 进行动态内存分配，并且在以后填满时 重新进行内存分配。初始使用malloc为拥有10个part结构的数组分配足够的内存空间。当数组没 有足够的空间给新的零件时，使用realloc 函数来使内存数量加倍。在每次数组变满时重复加倍操 作步骤。  2. 修改16.3节的程序inventory.c，使得p命令在显示零件前调用qsort对inventory数组排序。  3.修改17.5节的程序inventory2.c，增加一个e命令（擦除）以允许用户从数据库中删除一个零件。  4.修改15.3节的程序justify，重新编写line.c文件使其存储链表中的当前行。链表中的每个结点存储一 个单词。用一个指向包含第一个单词的结点的指针变量来替换原有的line数组，当行为空时该变量 存储空指针。  5.编写程序对用户输入的一系列单词排序：  Enter word: foo Enter word: bar Enter word: baz Enter word: quux Enter word:   In sorted order: bar baz foo quux  假设每个单词不超过20个字符。当用户输入空单词（即敲击回车键而没有输入任何单词）时停止读 取。把每个单词存储在一个动态分配的字符串中，像remind2.c程序（17.2节）那样用一个指针数组 来跟踪这些字符串。读完所有的单词后对数组排序（可以使用任何排序算法），然后用一个循环按存 储顺序显示这些单词。提示：像remind2.c那样，使用read_line函数读取每个单词。  6.修改编程题5，用qsort对指针数组排序。  7. 修改17.2节的remind2.c程序，使得 reminders 数组中的每个元素都是指向vstring 结构（见 17.9 节）的指针，而不是指向普通字符串的指针。

## 第十八章

### 练习题

18.1 节  1.请指出下列声明的存储类型、类型限定符、类型指定符、声明符和初始化器。  (a) static char **lookup(int level);  (b) volatile unsigned long io_flags;  (c) extern char *file_name[MAX_FILES], path[];  (d) static const char token_buf[] = "";  18.2 节  2. 用 auto、extern、register 和 static 来回答下列问题。  (a)哪种存储类型主要用于表示能被几个文件共享的变量或函数？  (b)假设变量x需要被一个文件中的几个函数共享，但要对其他文件中的函数隐藏。那么变量x应该 被声明为哪种存储类型呢？  (c)哪些存储类型会影响变量的存储期？  3.列出下列文件中每个变量和形式参数的存储期（静态/自动）、作用域（块/文件）和链接（内部/外部/无）：  extern float a;  void f(register double b)  {   static int c;   auto char d;  }  4. 假设f是下列函数。如果在此之前f从来没有被调用过，那么f(10)的值是多少呢？如果在此之前f 已经被调用过5次，那么f(10)的值又是多少呢？  int f(int i)  {   static int j = 0;   return i * j++;  }  5.指出下列语句是否正确，并验证你的答案。  (a) 具有静态存储期的变量都具有文件作用域。  (b) 在函数内部声明的变量都没有链接。  (c) 具有内部连接的变量都具有静态存储期。  (d) 每个形式参数都具有块作用域。  6.下面的函数希望打印一条出错消息。每条消息的前面有一个整数，表明函数已经被调用了多少次。 但是，消息前面的整数总是 1。找出错误所在，并说明如何在不对函数外部做任何修改的情况下修 正该错误。  void print_error(const char *message)  {   int n = 1;   printf("Error %d: %s\n", n++, message);  }  18.3 节  479 7.假设声明x为const对象，那么下列关于x的陈述哪条是假的呢？(a) 如果 x的类型是int，那么可以把它用作switch语句中分支标号的值。  (b) 编译器将检查是否没有对x进行赋值。  (c) x 遵循和变量一样的作用域规则。  (d) x 可以是任意类型。  18.4 节  8. 请按下列每个声明指定的那样编写x类型的完整描述。  (a) char (*x[10])(int);   (b) int (*x(int))[5];  (c) float *(*x(void))(int);   (d) void (*x(int, void (*y)(int)))(int);  9.请利用一系列的类型定义来简化练习题8中的每个声明。  10. 请为下列变量和函数编写声明。  480  481  (a) p 是指向函数的指针，并且此函数以字符型指针作为实际参数，函数返回的也是字符型指针。  (b) f 是带有两个实际参数的函数：一个参数是指向结构的指针p，且此结构标记为t；另一参数是长 整数n。f返回指向函数的指针，且指向的函数无实际参数也无返回值。  (c) a 是含有 4个元素的数组，且每个元素都是指向函数的指针，而这些函数都是无实际参数且无返 回值的。a的元素初始指向的函数名分别是insert、search、update和print。  (d) b 是含有10个元素的数组，且每个元素都是指向函数的指针，而这些函数都有两个int型实际参 数且返回标记为t的结构。  11. 18.4 节讲过，下列声明是非法的：  int f(int)[];        int g(int)(int);    int a[10](int);     /* functions can't return arrays     */  /* functions can't return functions  */  /* array elements can't be functions */  然而，可以通过使用指针获得相似的效果：函数可以返回指向数组第一个元素的指针，也可以返回 指向函数的指针；数组的元素可以是指向函数的指针。请根据这些描述修订上述每个声明。  * 12. (a) 假设函数f的声明如下，为函数f的类型编写完整的描述：  int (*f(float (*)(long), char *))(double);  (b)给出一个示例，说明如何调用f。  18.5 节  13. 下列哪些声明是合法的？（假设PI是表示3.141 59的宏。）  (a) char c = 65;  (b) static int i = 5, j = i * i;  (c) double d = 2  * PI;   (d) double angles[] = {0, PI / 2, PI, 3 * PI / 2};  14. 下列哪些类型的变量不能被初始化？  (a) 数组变量  (b) 枚举变量  (c) 结构变量  (d) 联合变量  (e) 上述都不能  15. 变量的哪种性质决定了它是否具有默认的初始值？  (a) 存储期   (b) 作用域   (c) 链接    (d) 类型

## 第十九章

### 练习题

19.1 节  1.队列类似于栈，两者的差异是队列的项从一端添加，而从另一端按 FIFO（先进先出）的方式删除。 对于队列的操作可以包括以下几种。   向队列的末端加入项。   从队列的开始删除项。   返回队列第一项（不改变队列）。   返回队列的末项（不改变队列）。   检查队列是否为空。  以头文件queue.h的形式给队列模块定义一个接口。  19.2 节   2. 修改文件stack2.c，以使用PUBLIC 宏和PRIVATE 宏。  3. (a) 按照练习题 1中的描述用数组实现一个队列模块。用三个整数来记录栈的状态，第一个整数存储 数组中的第一个空位置（插入数据项时用到），第二个整数存储待删除的下一项位置，第三个整 数存储队列中数据项的个数。插入或删除操作可能会导致前两个整数超出数组的边界，此时需要 把变量置为0，以“折返”到数组的起始位置。(b) 按照练习题 1中的描述用链表实现一个队列模块。使用两个指针，一个指向链表的首结点，另一 个指向链表的末结点。向队列中插入数据项时，将其加到链表的最后。从队列中删除数据项时， 删除链表中的第一个结点。  19.3 节   4. (a) 编写 Stack 类型的实现，假设Stack 是一个包含定长数组的结构。  (b) 使用链表替换数组，重写上面的Stack类型。（给出stack.h和stack.c。）  5.修改练习题1中的queue.h，使之定义一个Queue类型，其中Queue是包含定长数组的结构（见练习 题3(a)）。同时修改queue.h中的函数，用Queue *作为形式参数。   19.4 节  6. (a) 给 stackADT.c 增加一个 peek 函数，该函数具有Stack 类型的形式参数。调用时该函数返回栈顶 的数据项，但不修改栈的内容。  (b) 重复上一题，这次修改stackADT2.c。  (c) 重复上一题，这次修改stackADT3.c。  7.修改 stackADT2.c，使得栈满时自动加倍容量。要求 push 函数能动态地分配一个大小是原来的两倍 的新数组，并将原数组的内容复制到新数组中。一定要在数据复制结束后用push函数回收原数组所 占的空间。 

### 编程题

1.修改第 10章的编程题1，改用19.4节描述的栈抽象数据类型。允许采用该节描述的任意抽象数据类 型实现。 

 2.修改第 10章的编程题6，改用19.4节描述的栈抽象数据类型。允许采用该节描述的任意抽象数据类 型实现。  

3.修改19.4节的stackADT3.c文件，为stack_type 结构增加一个名为len的int类型成员。该成员记 录当前在栈中存储了多少数据项。增加一个名为length的新函数，要求形式参数的类型为Stack且 返回len成员的值。（stackADT3.c中的一些现有的函数也需要修改。）修改stackclient.c，使其在每次 对栈进行修改后调用length函数（并显示返回的值）。  

4.修改19.4节的stackADT.h和 stackADT3.c文件，使栈存储void *类型的值（如19.5节所述）而不再使 用Item 类型。修改stackclient.c使其存储指向s1 和s2栈中的字符串的指针。  5.从练习题1的queue.h出发，创建一个名为queueADT.h的文件，定义如下的Queue类型：  typedef struct queue_type *Queue;  queue_type 是不完整类型。创建一个名为queueADT.c的文件，其中包含queue_type的完整定义以 及queue.h 中所有函数的定义。使用定长数组来存储队列中的数据项（见练习题 3(a)）。创建一个名 为queueclient.c 的文件（类似于 19.4节的 stackclient.c文件）来创建两个队列并执行队列操作。确保为 你的抽象数据类型提供create和destroy函数。  6.修改编程题 5，用动态分配的数组来存储队列中的数据项。动态分配的数组的长度作为参数传给 create 函数。  7.修改编程题5，用链表来存储队列中的数据项（见练习题3(b)）。

## 第二十章

### 练习题

20.1 节  * 1. 指出下面每一个代码段的输出。假定i、j和k都是unsigned short类型的变量。  (a) i = 8; j = 9;  printf("%d", i >> 1 + j >> 1);  (b) i = 1;  printf("%d", i & ~i);  (c) i = 2; j = 1; k = 0;  printf("%d", ~i & j ^ k);  (d) i = 7; j = 8; k = 9;  printf("%d", i ^ j & k);  2. 请说出如何简便地“切换”一个位（从0改为1或从1改为0）。通过编写一条语句切换变量i的第 4位来说明这种方法。 \*  3. 请解释下面的宏对它的实际参数起什么作用。假设参数具有相同类型。  #define M(x,y) ((x)^=(y),(y)^=(x),(x)^=(y))  4. 在计算机图形学中，颜色通常是用分别代表红、绿、蓝3种颜色的3个数存储的。假定每个数需要8 位来存储，而且我们希望将3个值一起存放在一个长整数中。请编写一个名为MK_COLOR的宏，使其 包含3个参数（红、绿、蓝色的强度）。MK_COLOR 宏应该返回一个long 值，其中后3个字节分别 包含红、绿和蓝色的强度（红作为最后一个字节，绿作为倒数第二个字节）。  5.编写名为GET_RED、GET_GREEN 和GET_BLUE 的宏，并以一个给定的颜色值作为参数（见练习题4）， 返回8位的红、绿、蓝色的强度。  6. (a) 使用位运算符编写如下函数：  unsigned short swap_bytes(unsigned short i);  函数swap_bytes 的返回值是将i的两个字节调换后产生的结果。（在大多数计算机中，短整数占两 个字节。）例如，假设i的值是0x1234（二进制形式为00010010 00110100），那么swap_bytes的 返回值应该为0x3412（二进制形式为00110100 00010010）。编写一个程序来测试你的函数。程序以 十六进制读入数，然后交换两个字节并显示出来：  Enter a hexadecimal number (up to four digits): 1234 Number with bytes swapped: 3412 提示：使用%hx转换来读入和输出十六进制数。  (b) 将swap_bytes 函数的函数体化简为一条语句。  7.编写如下函数：  unsigned int rotate_left(unsigned int i, int n);  unsigned int rotate_right(unsigned int i, int n);  525  函数rotate_left 返回的值应是将i左移n位并将从左侧移出的位移入i右端而产生的结果。（例 如，假定整数占32位，rotate_left(0x12345678, 4)将返回0x23456781。）函数rotate_right 也类似，只是将数字中的位向右循环移位。  8. 假定函数f如下：  unsigned int f(unsigned int i, int m, int n)  {    return (i >> (m + 1 - n)) & ~(~0 << n);   }  (a) ~(~0 << n)的结果是什么？  (b) 函数 f的作用是什么？  9. (a) 编写如下函数：  int count_ones(unsigned char ch);  count_ones 应返回ch 中1的位数。  (b) 编写(a)中的函数，要求不使用循环。  10. 编写如下函数：  unsigned int reverse_bits(unsigned int n);  reverse_bits 应返回一个无符号整数，该整数的数位与n完全相同但顺序相反。下面的每个宏定义了整数内部的单个位的位置：  #define SHIFT_BIT  1  #define CTRL_BIT   2  #define ALT_BIT    4  下面的语句希望测试这3个位中是否至少有一位被设置，但永远无法输出指定的消息。请解释原因，并修正该 语句。假设key_code是int类型的变量。  if (key_code & (SHIFT_BIT | CTRL_BIT | ALT_BIT) == 0)   printf("No modifier keys pressed\n");   12. 下面的函数试图把两个字节组成一个无符号短整数。解释为什么函数不能工作，并给出你的修改 方案。  unsigned short create_short(unsigned char high_byte,                             unsigned char low_byte)  {   return high_byte << 8 + low_byte;  }  * 13. 如果 n 是一个unsigned int 类型的变量，下面的语句会对n中的位有什么影响？  n &= n – 1;  提示：考虑这条语句多次执行后对n的影响。  20.2 节  14. 当按照IEEE浮点标准存储浮点数时，一个float型的值由1个符号位（最左边的位或最高有效位）、 8个指数位以及23个小数位依次组成。请设计一个32位的结构类型，包含与符号、指数和小数相对应 的位域成员。声明位域的类型为unsigned int。请参考你所用编译器的用户手册来决定位域的顺序。  * 15. (a) 假设变量 s 的声明如下：  struct {   int flag: 1;   } s;  在有些编译器下，执行下面的语句会显示1；但在另一些编译器下，输出是1。请解释原因。  s.flag = 1;  printf("%d\n", s.flag);  (b) 如何避免这一问题？  20.3 节  16. 从 386处理器开始，x86的 CPU就有了32位的寄存器EAX、EBX、ECX和EDX。这些寄存器的一 半（最低有效位）分别与AX、BX、CX和DX一样。修改regs 联合，使其既包含原先的寄存器， 也包含这些寄存器。在联合中应进行相应的设置，使得修改EAX也会改动AX，修改AX也会改动 EAX 的低位部分。（其他新寄存器的工作机制也类似。）你需要在 word 和 byte 结构中增加一些 “哑”成员分别对应EAX、EBX、ECX和EDX的另一半。声明新寄存器的类型为DWORD（双字）， 该类型应定义为unsigned long。不要忘记x86体系结构是采用小端方式的。

### 编程题

 1.设计一个联合类型，使一个32位的值既可以看作一个float类型的值，也可以看作练习题14中定义 的结构。写一个程序将1存储在结构的符号字段，将128存储在指数字段，0存储在小数字段，然后 按float 值的形式显示存储在联合中的值。（如果你的位域设置正确的话，结果应该是2.0。） 

## 第二十一章

### 练习题

21.1 节  1.在你的系统中找到存放头文件的位置。找出那些非标准头，并指明每一个的用途。  2.在存放头文件的目录中（见练习题1）找出一个使用宏隐藏函数的标准头。  3.当使用宏隐藏函数时，在头文件中，宏定义和函数原型哪一个必须放在前面？验证你的结论。  4.列出C99标准的“future library directions”部分的所有保留标识符。有的标识符只在具体的头文件被 包含时才被保留，有的标识符被保留用作外部名字。请对这两种标识符加以区分。  * 5. 中的 islower 函数用于测试字符是否为小写字母。下面的宏版本为什么不符合 C标准？ （假定字符集是ASCII。）  #define islower(c) ((c) >= 'a' && (c) <= 'z')  6. 头通常把它的函数也定义为宏。这些宏依赖于一个在中声明但在另一个文件 中定义的静态数组。下面给出了常见的头的一部分。使用这个例子回答下列问题。  (a) 为什么“位”宏（例如_UPPER）和_ctype数组用下划线开头？  (b) 解释_ctype 数组包含什么内容。假设字符集是ASCII，给出位置9（水平制表符）、位置32（空 格符）、位置65（字母A）、位置94（字符^）处的数组元素的值。关于每个宏返回什么值的描 述见23.5节。  (c) 使用数组实现下面这些宏有什么好处？  #define _UPPER    0x01   /* upper-case letter */  #define _LOWER    0x02   /* lower-case letter */  #define _DIGIT    0x04   /* decimal digit */  #define _CONTROL  0x08   /* control character */  #define _PUNCT    0x10   /* punctuation character */  #define _SPACE    0x20   /* white-space character */  #define _HEX      0x40   /* hexadecimal digit */  #define _BLANK    0x80   /* space character */  #define isalnum(c)   (_ctype[c] & (_UPPER|_LOWER|_DIGIT))  #define isalpha(c)   (_ctype[c] & (_UPPER|_LOWER))  #define iscntrl(c)   (_ctype[c] & _CONTROL)  #define isdigit(c)   (_ctype[c] & _DIGIT)  #define isgraph(c)   (_ctype[c] &                       (_PUNCT|_UPPER|_LOWER|_DIGIT))  #define islower(c)   (_ctype[c] & _LOWER)  #define isprint(c)   (_ctype[c] &   (_BLANK|_PUNCT|_UPPER|_LOWER|_DIGIT))  #define ispunct(c)   (_ctype[c] & _PUNCT)  #define isspace(c)   (_ctype[c] & _SPACE)  #define isupper(c)   (_ctype[c] & _UPPER)  #define isxdigit(c)  (_ctype[c] & (_DIGIT|_HEX))  21.2 节  7. 在哪个标准头中可以找到下面描述的函数或宏？  537 (a) 判断当前是星期几的函数。 (b) 判断字符是否是数字的函数。  (c) 给出最大的unsigned int 类型值的宏。  (d) 对浮点数向上舍入的函数。  (e) 指定一个字符包含多少位的宏。  (f) 指定 double 类型值有效位个数的宏。  (g) 在字符串中查找特定字符的函数。  (h) 以读方式打开文件的函数。

### 编程题

 1.编写一个程序声明结构s（见21.4节），并显示成员a、b、c的大小和偏移量。（使用sizeof得到 大小，使用offsetof 得到偏移量。）同时使程序显示整个结构的大小。根据这些信息，判断结构中 是否包含空洞。如果包含空洞，指出每一个空洞的位置和大小。

## 第二十二章

### 练习题

22.1 节  1.指出下列每个文件更可能包含文本数据还是二进制数据。  (a) C 编译器产生的目标代码文件。  (b) C 编译器产生的程序列表。  (c) 从一台计算机发送到另一台计算机的电子邮件消息。  (d) 含有图形图像的文件。  22.2 节  581 2. 指出在下列每种情况下最可能把哪种模式字符串传递给fopen函数。(a) 数据库管理系统打开含有将被更新的记录的文件。  (b) 邮件程序打开存有消息的文件以便在文件末尾添加额外的消息。  (c) 图形程序打开含有将被显示在屏幕上的图片的文件。  (d) 操作系统命令解释器打开含有将被执行的命令的“shell脚本”（或者“批处理文件”）。  3.找出下列程序片段中的错误，并说明如何修正。  FILE *fp;   if (fp = fopen(filename, "r")) {  读取字符直到文件末尾  }  fclose(fp);  22.3 节  4. 如果printf 函数用%#012.5g 作为转换说明来执行显示操作，请指出下列数字显示的形式。  (a) 83.7361  (b) 29748.6607  (c) 1054932234.0  (d) 0.000 023 521 8  582  5. printf 函数的转换说明%.4d 和%04d 有区别吗？如果有，请说明区别是什么。  *6. 编写 printf 函数的调用，要求：如果变量widget（int 类型）的值为1，则显示1 widget；如果 值为n，则显示n widgets。不允许使用 if 语句或任何其他语句，答案必须是一个单独的 printf 调用。  *7. 假设按照下列形式调用scanf函数：  n = scanf("%d%f%d", &i, &x, &j);  （其中，i、j和n都是int类型变量，而x是float类型变量。）假设输入流含有下面所示的字符， 请指出这个调用后i、j、n和x的值。此外，请说明一下这个调用会消耗哪些字符。  (a) 10·20·30¤  (b) 1.0·2.0·3.0¤  (c) 0.1·0.2·0.3¤  (d) .1·.2·.3¤  8. 在前面几章中，当希望跳过空白字符而读取非标准空白字符时，已经使用过scanf函数的" %c"格式 串。而一些程序员用"%1s"来代替。这两种方法等效吗？如果不等效，区别是什么？  22.4 节  9.如果要想从标准输入流中读取一个字符，下列调用方式哪种是无效的？  (a) getch()  (b) getchar()  (c) getc(stdin)  (d) fgetc(stdin)  10. 程序 fcopy有一个小缺陷：当它向目标文件写入时无法检查错误。虽然在写操作过程中错误是极少见 的，但是偶尔会发生（比如，磁盘可能会变满）。假设一旦发生错误，希望程序可以显示一条消息并 立刻终止，请说明如何为fcopy.c添加遗漏的错误检查。在程序fcopy.c中出现了下列循环：  while ((ch = getc(source_fp)) != EOF)   putc(ch, dest_fp);   假设省略表达式ch = getc(source_fp)两边的圆括号：  while (ch = getc(source_fp) != EOF)   putc(ch, dest_fp);  程序可以无错通过编译吗？如果可以，那么运行时程序会做些什么呢？  12. 找出下列函数中的错误，并说明如何修正。  int count_periods(const char *filename)  {   FILE *fp;   int n = 0;   if ((fp = fopen(filename, "r")) != NULL) {     while (fgetc(fp) != EOF)       if (fgetc(fp) == '.')         n++;     fclose(fp);   }   return n;  }  13. 编写下列函数：  int line_length(const char *filename, int n);   函数应返回名为filename的文本文件中第n行的长度（假定文件的第一行是行1）。如果该行不存 在，函数返回0。  22.5 节  14. (a) 编写自己版本的fgets 函数，使此函数的操作尽可能与实际的fgets函数相同。特别是一定要确保 函数具有正确的返回值。为了避免和标准库发生冲突，请不要把自己编写的函数也命名为fgets。  (b) 请编写自己版本的fputs函数，规则和(a)要求的一样。  22.7 节  15. 编写fseek 函数的调用来在二进制文件中执行下列文件定位操作，其中，二进制文件的数据以64字 节“记录”的形式进行排列。采用fp作为下列每种情况中的文件指针。  (a) 移动到记录n的开始处（假设文件中的首记录为记录0）。  (b) 移动到文件中最后一条记录的开始处。  (c) 向前移动一条记录。  (d) 向后移动两条记录。  22.8 节  16. 假设 str 是包含“销售排行”的字符串，它紧跟在符号#的后面（#的前面可能有其他字符，销售排 行的后面也可能有其他字符）。销售排行是一系列的十进制数，可能包含逗号，示例如下：  989  24,675  1,162,620  编写sscanf 的调用，提取出销售排行（不要#号）并将其存储在一个名为sales_rank 的字符串变 量中。 

### 编程题

 1.扩展22.2节的canopen.c程序，以便用户把任意数量的文件名放置在命令行中：  canopen foo bar baz  584  这个程序应该为每个文件分别显示出can be opended消息或者can't be opened消息。如果一个 或多个文件无法打开，程序以EXIT_FAILURE状态终止。  2. 编写程序，把文件中的所有字母转换成大写形式（非字母字符不改变）。程序应从命令行获取文件名 并把输出写到stdout中。  3.编写一个名为fcat的程序，通过把任意数量的文件写到标准输出中而把这些文件一个接一个地“拼 接”起来，并且文件之间没有间隙。例如，下列命令将在屏幕上显示文件f1.c、f2.c和f3.c：  fcat f1.c f2.c f3.c  如果任何文件都无法打开，那么程序 fcat 应该发出出错消息。提示：因为每次只可以打开一个文 件，所以程序fcat只需要一个文件指针变量。一旦对一个文件完成操作，程序fcat在打开下一个文件 时可以使用同一个文件指针变量。  4. (a) 编写程序统计文本文件中字符的数量。  (b) 编写程序统计文本文件中单词的数量。（此处“单词”指不含空白字符的任意序列。）  (c) 编写程序统计文本文件中行的数量。  要求每一个程序都通过命令行获得文件名。  5. 20.1 节中的程序 xor.c 拒绝对原始格式或加密格式中是控制字符的字节进行加密。现在可以摆脱这种 限制了。修改此程序，使输入文件名和输出文件名都是命令行参数。以二进制模式打开这两个文 件，并且把用来检查原始字符或加密字符是否是控制字符的判断删除。  6. 编写程序，按字节方式和字符方式显示文件的内容。用户通过命令行指定文件名。程序用于显示2.1 节的pun.c文件时，输出如下：  Offset               Bytes                ------   -----------------------------     Characters ----------      0   23 69 6E 63 6C 75 64 65 20 3C    #include <     10   73 74 64 69 6F 2E 68 3E 0D 0A    stdio.h>..     20   0D 0A 69 6E 74 20 6D 61 69 6E    ..int main     30   28 76 6F 69 64 29 0D 0A 7B 0D    (void)..{.     40   0A 20 20 70 72 69 6E 74 66 28    .  printf(     50   22 64 6F 20 43 2C 20 6F 72 20    "To C, or      60   6E 6F 74 20 74 6F 20 43 3A 20    not to C:      70   74 68 61 74 20 69 73 20 74 68    that is th     80   65 20 71 75 65 73 74 69 6F 6E    e question     90   2E 5C 6E 22 29 3B 0D 0A 20 20    .\n");..    100   72 65 74 75 72 6E 20 30 3B 0D    return 0;.    110   0A 7D                            .}  每行分别以字节方式和字符方式显示文件中的10个字节。Offset一栏中的数值表示该行的第一个字 节在文件中的位置。只显示打印字符（由isprint 函数确定），其他字符显示为点。注意，根据字 符集和操作系统的不同，文本文件的形式可能不同。上面的示例假设pun.c是Windows文件，因此在 每行的最后有0D和0A（ASCII码的回车和回行符）。提示：确保用"rb"模式打开文件。  7.在文件内容压缩的众多方法中，最快捷的方法之一是行程长度编码（run-length encoding）。这种方法 通过用一对字节替换相同的字节序列来压缩文件：第一个字节是重复计数，第二个字节是需要重复 的字节。例如，假设待压缩的文件以下列字节序列开始（以十六进制形式显示）：46 6F 6F 20 62 61 72 21 21 21 20 20 20 20 20  压缩后的文件将包含下列字节：  01 46 02 6F 01 20 01 62 01 61 01 72 03 21 05 20  如果原始文件包含许多相同字节的长序列，那么行程长度编码的方法非常适用。最差的情况（文件中 没有连续的重复字节）下，行程长度编码实际上可能使文件的长度加倍。  (a) 编写名为 compress_file 的程序，此程序使用行程长度编码方法来压缩文件。为了运行程序 compress_file，将使用下列格式的命令：  compress_file 原始文件  程序compress_file 将把原始文件的压缩版本写入到“原始文件.rle”文件中。例如，命令  compress_file foo.txt  将使程序compress_file 把文件 foo.txt的压缩版写到名为 foo.txt.rle的文件中。提示：编程题 6 描述的程序可以用来调试。  (b) 编写名为 uncompress_file 的程序，此程序是程序 compress_file 的反向操作。程序 uncompress_file 的命令格式为  uncompress_file compressed-file  压缩后的文件（compressed-file）扩展名为.rle。例如，命令  uncompress_file foo.txt.rle  会使程序uncompress_file 打开文件 foo.txt.rle，并且把未压缩版的内容写入 foo.txt。如果命令行参 数的扩展名不是.rle，uncompress_file应显示一条出错消息。  8.通过添加两个新的操作来修改16.3节中的inventory.c程序：   在指定文件中保存数据库；   从指定文件中装载数据库。  分别使用代码d（转储）和r（恢复）来表示这两种操作。与用户的交互应该按照下列显示进行：  Enter operation code: d  Enter name of output file: inventory.dat Enter operation code: r  Enter name of input file: inventory.dat 9. 编写程序对由inventory程序存储的含有零件记录的两个文件进行合并（见编程题8）。假设每个文件 中的记录都是根据零件编号进行排序的，且我们希望结果文件也应是排好序的。如果两个文件中存 在编号相同的零件，那么要对记录中存储的数量进行合并。（作为一致性的检查，程序要比较零件的 名称，并且在不匹配时显示出错消息。）程序从命令行获取输入文件名以及合并后的文件名。  * 10. 修改 17.5节中的程序inventory2.c，方法是添加编程题8中描述的d（转储）操作和r（恢复）操作。 因为零件的结构不存储在数组中，所以 d 操作无法通过单独一个 fwrite 调用来保存所有内容。因 而，它需要访问链表中的每个结点，把零件的编号、名称以及现有的零件数量保存到文件中。（不保 存指针next，因为一旦程序终止，这一指针就不再有效。）当程序从文件中读取零件时，r操作将重 新构建列表（每次恢复一个结点）。  11. 编写程序从命令行读取日期，并且按照下列格式显示：  September 13, 2010允许用户以9-13-2010或者9/13/2010的形式输入日期，并假设日期中没有空格。如果没有按照指 定格式输入日期，那么程序显示出错消息。提示：使用sscanf函数从命令行参数中提取月、日和 年的信息。  12. 修改第3章的编程题2，让程序从文件中读取一系列数据项并按列显示数据。文件的每一行具有如下 形式：   数据项,价格,月/日/年    例如，假设文件包含下列两行：   583,13.5,10/24/2005  3912,599.99,7/27/2008    程序的输出形式如下：   Item   Unit   Purchase     Price  Date  583   $  13.50  10/24/2005  3912   $ 599.99  7/27/2008    程序从命令行获取文件名。  13. 修改第5章的编程题8，让程序从名为flights.dat的文件中获取起飞时间和抵达时间。文件的每一行先 给出起飞时间再给出抵达时间，中间用一个或多个空格隔开。时间用24小时制表示。例如，如果文 件包含的是原题中的航班信息，则flights.dat如下：   8:00 10:16  9:43 11:52  11:19 13:31  12:47 15.00  14:00 16:08  15:45 17:55  19:00 21:20  21:45 23:58   14. 修改第8章的编程题15，让程序提示用户输入包含待加密消息的文件名：   Enter name of file to be encrypted: message.txt  Enter shift amount (1-25): 3    接下来，程序把加密后的消息写入另一个文件，该文件在所读取的文件名之后加上扩展名.enc。在 上面的例子中，原始文件名为message.txt，所以加密消息存储在名为message.txt.enc的文件中。待加 密文件的大小不限，文件中每行的长度也不限。  15. 修改15.3节的justify程序，使其从一个文本文件中读取并写入另一个文本文件。程序从命令行获取 这两个文件名。  16. 修改22.4节的fcopy.c程序，使其用fread和fwrite来复制文件，复制时使用512字节的块。（当 然，最后一个块包含的字节数可能少于512。）  17. 编写程序，从文件中读取一系列电话号码并以标准格式显示。文件的每一行只包含一个电话号码， 但可能存在多种格式。可以假定每行包含10个数字，可能夹杂着其他字符（可以忽略）。例如，假定 文件包含如下内容：   404.817.6900  (215) 686-1776  312-746-6000  877 275 5273  6173434200 程序的输出如下：  (404) 817-6900  (215) 686-1776  (312) 746-6000  (877) 275-5273  (617) 343-4200  程序从命令行获取文件名。  18. 编写程序从文本文件中读取整数，文本文件的名字由命令行参数给出。文件的每一行可以包含任意 数量的整数（也可以没有），中间用一个或多个空格隔开。程序显示文件中最大的数、最小的数以及 中位数（整数有序情况下最接近中间的那个数）。如果文件包含偶数个整数，中间会有两个整数，程 序将显示它们的均值（向下舍入）。可以假定文件包含的整数个数不超过10 000。提示：把整数存储 在数组中并对其排序。  19. (a) 编写程序把Windows的文本文件转换成UNIX的文本文件。（见22.1节关于两者区别的讨论。）  (b) 编写程序把UNIX的文本文件转换成Windows的文本文件。  每种情况下都从命令行获取两个文件的名字。提示：以"rb"模式打开输入文件，以"wb"模式打开输 出文件。

## 第二十三章

### 练习题

23.3 节  1. 扩展 round_nearest 函数，使它可以将浮点数x舍入成小数点后n位。例如，调用round_nearest  (3.14159, 3)会返回 3.142。提示：将x乘以10n，舍入成最接近的整数，再除以10n。确保你的函 数在x为正数和负数的情况下都可以正常工作。  23.4 节  2. 编写下列函数：  double evaluate_polynomial(double a[], int n, double x); 函数应返回多项式1 1 0      n n n n ax a x a的值，其中i a存储在数组a的相应元素中，数组a的长度 为n+1。使用Horner法则计算多项式的值：          1 2 1 0 n n n ax a x a x x a x a            使用fma函数执行乘法和加法。  3. 查看你的编译器文档，看它是否对算术表达式进行了紧缩；如果进行了紧缩，看看在什么条件 下这么做。  23.5节  4. 使用isalpha和isalnum编写一个函数，用来检查一个字符串是否符合C语言标识符的语法（由字 母、数字和下划线组成，并以字母或下划线开始）。  5. 使用isxdigit编写一个函数，用来检查一个字符串是否表示有效的十六进制数（只包含十六进制数 字）。如果是，则函数把该数作为long int类型的值返回；否则函数返回1。  23.6节   6. 对于下面列举的每种情况，指出使用memcpy、memmove、strcpy和strncpy中哪一个函数最好。假 定所列举的行为都是由一个函数调用完成的。   (a) 将数组中的每个元素都“下移”一个位置，以便将第0个位置空出给新元素。   (b) 通过将后面的所有字符都前移一个位置，来删除以空字符结尾的字符串中的第一个字符。   (c) 将一个字符串复制到一个字符数组中，这个字符数组的大小可能不够存放整个字符串。如果数组 太小，就将字符串截断，末尾不需要空字符。   (d) 将一个数组变量的内容复制到另一个数组变量中。  7. 在23.6节中阐述了如何反复调用strchr函数在字符串中找到指定字符的所有出现位置。能否通过反 复调用strrchr函数反向找到指定字符的所有出现位置呢？  8. 使用strchr函数编写如下函数：   int numchar(const char *s, char ch);    函数numchar返回字符ch在字符串s中出现的次数。  9. 使用一个strchr函数调用来替换下面if语句中的测试条件：   if (ch == 'a' || ch == 'b' || ch == 'c') ...   10. 使用一个strstr函数调用来替换下面if语句中的测试条件：   if (strcmp(str, "foo") == 0 || strcmp(str, "bar") == 0 ||     strcmp(str, "baz") == 0) ...    提示：将字面串合并到一个字符串中，并使用一个特殊字符分隔它们。你的答案是否需要对str的 内容做一定的假设？  11. 编写一个memset函数的调用，将一个以空字符结尾的字符串s的最后n个字符替换为!字符。  12. 的许多版本提供了额外的（非标准）函数，例如下面列出的一些函数。使用C标准的特 性给出每一个函数的实现。   (a) strdup(s)：返回一个指针，该指针指向通过调用malloc函数获得的内存中保存的s的一个副 本。如果没有足够的内存可分配，则返回空指针。  (b) stricmp(s1, s2)：与strcmp函数类似，但不考虑字母的大小写。  (c) strlwr(s)：将s中的大写字母转换为小写字母，其他字符不变，返回s。 (d) strrev(s)：反转字符串s中的字符顺序（空字符除外），返回s。  (e) strset(s, ch)：将 s 用 ch 的副本填充，返回s。  如果要对这些函数进行测试，需要修改其名字。以str开头的函数名是C标准保留的。  13. 使用strtok 编写下列函数：  int count_words(char *sentence);  count_words 返回字符串 sentence 中单词的数量，其中“单词”是任意的非空白字符序列。允许 count_words 修改字符串。

### 编程题

 1.编写一个程序，使用下面的公式求方程ax2+bx+c=0的根：  2 x      b b ac 2 a 4 程序提示用户输入a、b和c的值，然后显示出x的两个解。（如果b24ac的值小于0，那么程序需 要显示一条消息，指出根是复数。）  2. 编写一个程序，将文本文件从标准输入复制到标准输出，并删除每行开头的空白字符。不要复制仅 包含空白字符的行。  3.编写一个程序，将文本文件从标准输入复制到标准输出，将每个单词的首字母大写。  4.编写一个程序，提示用户输入一系列单词，单词之间用一个空格隔开，然后按相反的顺序显示出 来。将输入按字符串的形式读入，然后使用strtok函数将它们分隔成单词。  625  626  5.假定把钱存入一个储蓄账户t年。设年利率为r，且利息逐年复合。公式A(t)=Pert可以用于计算账户 的最终余额，其中P是初始的存款。例如，按年利率6%把1000美元存10年可以得到1000×e0.06× 10  =1000×e0.6=1000×1.822 118 8≈1822.12 美元。编写程序提示用户输入初始存款、利率和年数，然后 显示计算结果。  6.编写一个程序，将文本文件从标准输入复制到标准输出，将除\n之外的控制字符替换为问号。  7.编写一个程序，统计文本文件（从标准输入获取）中句子的数目。假定每个句子以.、?或!结尾，且 后面有一个空白字符（包括\n）。 

## 第二十四章

### 练习题

24.1 节  1. (a) 断言可以用来检测两种问题：第一种是如果程序正确就不应该发生的问题，第二种是超出程序控 制范围的问题。请解释为什么assert更适用于第一种问题。  (b) 请举出三个超出程序控制范围的问题的例子。   2.编写assert 函数调用，当名为top的变量取值为NULL时使程序终止。  3.修改19.4节的stackADT2.c文件，用assert取代if语句来测试错误。（注意，不再需要terminate 函数了，可以删除它。）  24.2 节  4. (a) 编写一个名为try_math_fcn的“包装”函数来调用数学函数（假定有一个double类型的参数， 并返回一个double类型的值），然后检查调用是否成功。下面是使用try_math_fnc函数的例子：  y = try_math_fcn(sqrt, x, "Error in call of sqrt");如果调用sqrt(x)成功，try_math_fcn 返回 sqrt 函数的计算结果。如果调用失败，try_math_fcn 需要调用perror显示消息Error in call of sqrt，然后调用exit函数终止程序。  (b) 编写一个与try_math_fcn 具有相同效果的宏，但要求使用函数的名字来构造出错消息：  y = TRY_MATH_FCN(sqrt, x);  如果调用sqrt失败，显示的出错消息应该是“Error in call of sqrt”。提示：让TRY_MATH_FCN 调用try_math_fcn。  24.3 节  5. 在 inventory.c 程序（见 16.3节）中，main 函数用一个for 循环来提示用户输入一个操作码，然后读 入码并调用insert、search、update 或print。在main 函数中加入一个setjmp 调用，要求使随 后的longjmp 调用会返回到for循环。（在调用longjmp函数后，提示用户输入一个操作码，随后 程序正常执行。）setjmp需要一个jmp_buf类型的变量，这个变量应该在哪儿声明呢？

### 编程题

## 第二十五章

### 练习题

25.1 节  1.请确定你用的编译器支持哪些地区。  25.2 节  2.用于kanji（日文中的汉字）的Shift-JIS编码要求每个字符是单字节或者是双字节的。如果字符的第 一个字节位于0x81 和0x9f 之间，或者位于0xe0 和0xef 之间，那么就需要第二个字节。（把任何 其他字节看成是整个字符。）第二个字节必须在0x40和0x7e之间，或者在0x80和0xfc之间。 （所有的范围都包含边界值。）请指出以下面的每个字符串作为参数时，25.2节的mbcheck 函数的返 回值。假定多字节字符用当前地区的Shift-JIS编码。  (a) "\x05\x87\x80\x36\xed\xaa"  (b) "\x20\xe4\x50\x88\x3f"  (c) "\xde\xad\xbe\xef"  (d) "\x8a\x60\x92\x74\x41"  3.UTF-8的一个有用的性质是，多字节字符内的字节序列不可能表示其他的有效多字节字符。用于 kanji 的 Shift-JIS 编码（见练习题2）是否具有这一性质？  4.给出表示如下短语的C语言字面串。假设字符à、è、é、ê、î、ô、û和ü用单字节的Latin-1字符表示。 （需要查出这些字符的Latin-1码点。）例如，短语déjà vu可以用字符串"d\xe9j\xe0 vu"表示。  (a) Côte d'Azur(b) crème brûlée  (c) crème fraîche  (d) Fahrvergnügen  (e) tête-à-tête  675  676  5.重复练习题4，这次采用UTF-8多字节编码。例如，短语déjà vu可以用字符串"d\xc3\xa9j\xc3\  xa0 vu"表示。  25.3 节  6. 请通过尽可能多地用三联符替换字符的方法来修改下面的程序段。  while ((orig_char = getchar()) != EOF) {   new_char = orig_char ^ KEY;   if (isprint(orig_char) && isprint(new_char))     putchar(new_char);   else     putchar(orig_char);  }  7. 修改练习题6中的程序段，用双联符和中定义的宏来替换尽可能多的记号。 

### 编程题

1. 编写一个程序，用来测试你用的编译器的""（本地）地区是否和"C"地区一样。  
2. 编写一个程序，从命令行获取地区的名字，然后显示存储在相应的 lconv 结构中的值。例如，如果 地区是"fi_FI"（芬兰），程序的输出可能如下：  decimal_point = ","  thousands_sep = " "  grouping = 3  mon_decimal_point = ","  mon_thousands_sep = " "  mon_grouping = 3  positive_sign = ""  negative_sign = "-"  currency_symbol = "EUR"  frac_digits = 2  p_cs_precedes = 0  n_cs_precedes = 0  p_sep_by_space = 2  n_sep_by_space = 2  p_sign_posn = 1  n_sign_posn = 1  int_curr_symbol = "EUR "  int_frac_digits = 2  int_p_cs_precedes = 0  int_n_cs_precedes = 0  int_p_sep_by_space = 2  int_n_sep_by_space = 2  int_p_sign_posn = 1  int_n_sign_posn = 1  出于可读性的考虑，grouping和mon_grouping中的字符应显示为十进制数。

## 第二十六章

### 练习题

26.1 节  702  1.重新编写 max_int 函数，要求不再把整数的个数作为第一个参数，我们必须采用0作为最后一个参 数。提示：max_int 函数必须至少有一个“正常的”参数，所以不能把参数n移走，可以假设n是 要比较的数之一。  2. 编写printf函数的简化版，要求新函数只有一种转换说明%d，并且第一个参数后边的所有参数都必 须是int 类型的。如果函数遇到的%字符后面没有紧跟着字符d，那么同时忽略这两个字符。函数应 调用putchar 来生成所有的输出。可以假定格式串不包含转义序列。  3.扩展练习题2中的函数，使其允许两种转换说明：%d和%s。格式串中的每个%d表示一个int类型的 参数，每个%s表示一个char *类型的参数（字符串）。  4.编写名为 display 的函数，要求支持任意数量的参数。第一个参数必须是整数，其余参数是字符 串。第一个参数指明调用包含多少个字符串。函数在一行内打印出这些字符串，相邻字符串之间用 一个空格隔开。例如，调用  display(4, "Special", "Agent", "Dale", "Cooper");  将产生下列输出：  Special Agent Dale Cooper  5.编写下列函数：  char *vstrcat(const char *first, ...);  假设vstrcat 函数除最后一个参数必须是空指针（强制转换成char *类型）外，其他参数都是字符 串。函数返回一个指向动态分配的字符串的指针，该字符串包含参数的拼接。如果没有足够的内 存，那么vstrcat 函数应该返回空指针。提示：让vstrcat函数两次遍历参数，一次用来确定返回 字符串需要的内存大小，另一次用来把参数复制到字符串中。  6.编写下列函数：  char *max_pair(int num_pairs, ...);  假设 max_pair 的参数是整数与字符串对，num_pairs 的值表明后面有多少对。（每一对包含一个 int 类型的参数和一个跟随其后的char *类型参数。）函数从整数中搜索出最大的一个，然后返回 它后面的字符串。考虑如下函数调用：  max_pair(5, 180, "Seinfeld", 180, "I Love Lucy",              39, "The Honeymooners", 210, "All in the Family",             86, "The Sopranos")  最大的int类型参数是210，所以函数返回参数列表中跟随其后的"All in the Family"。26.2 节  7. 解释下列语句的含义。假设value是long int类型的变量，p是char *类型的变量。  value = strtol(p, &p, 10);  8.编写一条可以从7、11、15或19中随机取一个数赋值给变量n的语句。  9. 编写一个可以返回随机的double类型值d的函数，d的取值范围为0.0≤d＜1.0。  26.3 节  10. 把下面的atoi、atol 和atoll 调用分别转换为strtol、strtol和strtoll调用。  (a) atoi(str)  (b) atol(str)  (c) atoll(str)  11. bsearch 函数通常用于有序数组，但有时也可以用于部分有序的数组。如果要确保bsearch 能搜到 一个特定的键，数组必须满足什么条件？提示：C标准中有答案。  12. 编写一个函数，要求当向此函数传递年份时，函数返回一个time_t类型的值表示该年第一天的12:00  a.m。  13. 26.3 节描述了一些ISO 8601的日期和时间格式。下面给出了另一些格式。  (a)年份后面跟着月中的第几天：YYYY-DDD，其中DDD是001~366范围内的数。  (b)年份、星期、星期几：YYYY-Www-D，其中ww是01~53范围内的数；D是1~7范围内的数字，以星期 一开始，星期日结束。  (c)结合日期与时间：YYYY-MM-DDThh:mm:ss  给出与上述每种格式相对应的strftime字符串。

### 编程题

1. (a) 编写一个程序，使它可以调用rand函数1000次，并且显示函数返回的每个值的最低位（如果返 回值是偶数，则为0；如果返回值为奇数，则为1）。你发现什么模式了吗？（rand的返回值的 最后几位往往不是特别随机的。）  (b) 如何改进rand 函数的随机性，使它可以在一个小范围内产生数？  2.编写程序测试atexit函数。除main函数外，程序还应包含两个函数。一个函数显示That's all,， 另一个显示folks!。用 atexit 函数来注册这两个函数，使其可以在程序终止时被调用。请一定确 保这两个函数按照正确的顺序进行调用，从而可以在屏幕上看到That's all, folks!。  3. 编写一个程序，用clock函数来度量qsort函数对有1000个整数的数组进行排序所用的时间，这些 整数初始时是逆序的。然后再把完成的程序用于有10 000个整数和100 000个整数的数组。  4. 编写一个程序，提示用户输入一个日期（月、日和年）和一个整数n，然后显示n天后的日期。  5.编写一个程序，提示用户输入两个日期，然后显示两个日期之间相差的天数。提示：使用mktime函 数和difftime 函数。  6. 编写一个程序，分别按照下列每种格式显示当前的日期和时间。使用strftime函数来完成全部或大 部分的格式化工作。  (a) Sunday, June 3, 2007   05:48p  (b) Sun, 3 Jun 07   17:48  (c) 06/03/07   5:48:34 PM

## 第二十七章

### 练习题

27.1 节  1. 2. 在你系统上安装的中，找出intN_t和uintN_t类型的声明。N可以是哪些值？  编写如下带参数的宏：INT32_C(n)、UINT32_C(n)、INT64_C(n)和UINT64_C(n)。假设 int 类型和long int 类型为32位宽，而long long int类型为64位宽。提示：使用##预处理运算符把 一个包含字符L和U的组合的后缀加到n的后面。（7.1节介绍了如何在整型常量中使用后缀L和U。）  27.2 节  3. 在下面的每条语句中，假设变量i的类型是原始类型。用中的宏修改每条语句，使得 i 的类型变为指定的新类型时，语句仍能正常工作。  (a) printf("%d",i);      (b) printf("%12.4d", i);  (c) printf("%-6o", i);     (d) printf("%#x", i);      27.5 节  4. 假设有下列变量声明：  int i;  float f;  double d;  long double ld;  float complex fc;double complex dc;  long double complex ldc;  下面都是中的宏的调用，请给出预处理（用或中的函数替代宏） 之后的形式。  (a) tan(i)  (b) fabs(f)  (c) asin(d)  (d) exp(ld)  (e) log(fc)  (f) acosh(dc)  (g) nexttoward(d,ld)  (h) remainder(f, i)  (i) copysign(d, ld)  (j) carg(i)  (k) cimag(f)  (l) conj(ldc)

### 编程题

1. 对27.4节的quadratic.c程序做如下修改。  (a) 让用户输入多项式的系数（变量a、b、c的值）。  (b) 让程序在显示根的值之前对判别式进行测试。如果判别式为负，按以前的方式显示根的值；如果判别式非 负，以实数（无虚部）的形式显示根的值。例如，如果二次方程为x2+x2=0，那么程序的输出为  root1 = 1  root2 = -2  (c) 修改程序，使得虚部为负的复数的显示形式为abi而不是a+bi。例如，程序使用原始系数的输出将变为  root1 = -0.2 + 0.4i  root2 = -0.2 – 0.4i  2.  编写程序，把用笛卡儿坐标表示的复数转换为极坐标形式。用户输入a和b（复数的实部和虚部），程序 显示r和θ的值。  3. 编写程序，把用极坐标表示的复数转换为笛卡儿形式。用户输入r和θ的值，程序以a+bi的形式显 示该数，其中  a = r cosθ  b = r sin θ  4. 编写程序，当给定正整数n时显示单位元素（unity，幺元）的n次方根。单位元素的n次方根由公式 e2πik/n 给出，其中 k是0~n1范围内的整数。 

## 第二十八章

### 练习题

1. 给定以下代码，主线程main中的断言有可能触发吗？  

   ```C
   # include   
   # include   
   # include   
   # include   
   atomic_int x = 0, y = 0, z = 0;  
   int w_x(void * arg)  
   {   
     atomic_store_explicit(& x, 1, memory_order_relaxed);   
     return 0;  
   }  
   int w_y(void * arg)  
   {   
     atomic_store_explicit(& y, 1, memory_order_relaxed);   return 0;  }int if_x_wz(void * arg)  {   while (! atomic_load_explicit(& x, memory_order_relaxed));   if (atomic_load_explicit(& y, memory_order_relaxed))     z = 1;   return 0;  }  int if_y_wz(void * arg)  {   while (! atomic_load_explicit(& y, memory_order_relaxed));   if (atomic_load_explicit(& x, memory_order_relaxed))     z = 1;   return 0;  }  int main(void)  {   thrd_t t0, t1, t2, t3;   thrd_create(& t0, w_x, 0);   thrd_create(& t1, w_y, 0);   thrd_create(& t2, if_x_wz, 0);   thrd_create(& t3, if_y_wz, 0);   thrd_join(t0, & (int){0});   thrd_join(t1, & (int){0});   thrd_join(t2, & (int){0});   thrd_join(t3, & (int){0});   assert(z == 1);  }  
   ```

   

2. 如果将以上程序中的memory_order_relaxed全部替换为memory_order_seq_cst，主线程main中 的断言有可能触发吗？

### 编程题

1. 用原子操作函数atomic_fetch_add和atomic_fetch_sub改写前面的atomic.c，使之同样能够避免 数据竞争。  

2. 统计1~1 000 000 000的所有整数中，各数位之和为奇数的有几个。要求：先用一个线程来统计并打印 所用的时间，再用10个线程分段各自统计并打印总体所用的时间。 

