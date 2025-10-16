# C语言程序设计-现代方法-课后习题

## 第二章

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

ANS：

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

8. 编程计算第一、第二、第三个月还贷后剩余的贷款金额：

```c
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

## 第三章

### 练习题

1. 下面的 printf 函数调用产生的输出分别是什么？

```
(a) printf("%6d,%4d", 86, 1040);
(b) printf("%12.5e", 30.253);
(c) printf("%.4f", 83.162);
(d) printf("%-6.2g", .0000009979);
```

2. 编写 printf 函数调用，以下列格式显示 float 型变量 x。

```
(a) 指数表示形式，栏宽 8，左对齐，小数点后保留 1 位数字。
(b) 指数表示形式，栏宽 10，右对齐，小数点后保留 6 位数字。
(c) 定点十进制表示形式，栏宽 8，左对齐，小数点后保留 3 位数字。
(d) 定点十进制表示形式，栏宽 6，右对齐，小数点后无数字。
```

3. 说明下列每对 scanf 格式串是否等价？如果不等价，请指出它们的差异。

```
(a) "%d"与" %d"。
(b) "%d-%d-%d"与"%d -%d -%d"。
(c) "%f"与"%f "。
(d) "%f,%f"与"%f, %f"。
```

 *4. 假设 scanf 函数调用的格式如下：

`scanf("%d%f%d", &i, &x, &j);` 

如果用户输入3 5 6 调用执行后，变量 i、x 和 j 的值分别是多少？（假设变量 i 和变量 j 都是 int 型，变量 x 是 float型。）

*5. 假设 scanf 函数调用的格式如下：

`scanf("%f%d%f", &x, &i, &y);` 

 如果用户输入3 45.6 789 调用执行后，变量 x、i 和 y 的值分别是多少？（假设变量 x 和变量 y 都是 float 型，变量 i 是 int型。）

6. 指出如何修改 3.2 节中的 addfrac.c 程序，使用户可以输入在字符/的前后都有空格的分数。

### 编程题

1. 编写一个程序，以月/日/年（即 *mm/dd/yy*）的格式接受用户输入的日期信息，并以年月日（即*yyyymmdd*）的格式将其显示出来：

```
Enter a date (mm/dd/yyyy): 2/17/2011
You entered the date 20110217
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

4. 编写一个程序，提示用户以(xxx) xxx-xxxx 的格式输入电话号码，并以 xxx.xxx.xxxx 的格式显示该号码：

```
Enter phone number [(xxx) xxx-xxxx]: (404) 817-6900
You entered 404.817.6900 
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

6. 修改 3.2 节的 addfrac.c 程序，使用户可以同时输入两个分数，中间用加号隔开：

```
Enter two fractions separated by a plus sign: 5/6+3/4
The sum is 38/24
```

## 第四章

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

\*2. 如果 i 和 j 都是正整数，(-i) / j 的值和-(i / j)的值是否总一样？验证你的答案。*

3. 下列表达式在 C89 中的值是多少？（如果表达式有多个可能的值，都列出来。）

```c
(a) 8 / 5 
(b) -8 / 5 
(c) 8 / -5 
(d) -8 / -5 
```

4. 对 C99 重复上题。
5. 下列表达式在 C89 中的值是多少？（如果表达式有多个可能的值，都列出来。）

```c
(a) 8 % 5 
(b) -8 % 5 
(c) 8 % -5 
(d) -8 % -5 
```

6. 对 C99 重复上题。
7. 本章计算 UPC 校验位方法的最后几步是：把总的结果减去 1，相减后的结果除以 10 取余数，用 9 减去余数。换成下面的步骤也可以：总的结果除以 10 取余数，用 10 减去余数。这样做为什么可行？

8. 如果把表达式 9 - ((total - 1) % 10)改成(10 - (total % 10)) % 10，upc.c程序是否仍然正确？

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

给出下列程序片段的输出结果。假设 i 和 j 都是 int 型变量。

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

13. 表达式++i 和 i++中只有一个是与表达式(i += 1)完全相同的，是哪一个呢？验证你的答案。

14. 添加圆括号，说明 C 语言编译器如何解释下列表达式。

```C
(a) a * b – c * d + e 
(b) a / b % c / d
(c) – a – b + c - + d
(d) a * - b / c - d
```

15. 给出下列每条表达式语句执行以后 i 和 j 的值。（假设 i 的初始值为 1，j 的初始值为 2。）

```C
(a) i += j; 
(b) i--;
(c) i * j / i; 
(d) i % ++j;
```

### 编程题

1. 编写一个程序，要求用户输入一个两位数，然后按数位的逆序打印出这个数。程序会话应类似下面这样：

```
Enter a two-digit number: 28
The reversal is: 82 
```

用%d 读入两位数，然后分解成两个数字。提示：如果 n 是整数，那么 n % 10 是个位数，而 n / 10则是移除个位数后剩下的数。

2. 扩展上题中的程序，使其可以处理 3 位数。
3. 重新编写编程题2中的程序，使新程序不需要利用算术分割就可以显示出3位数的逆序。提示：参考4.1 节的 upc.c 程序。

4. 编写一个程序，读入用户输入的整数并按八进制（基数为 8）显示出来：

```
Enter a number between 0 and 32767: 1953
In octal, your number is: 03641 
```

输出应为 5 位数，即便不需要这么多数位也要如此。提示：要把一个数转换成八进制，首先将其除以 8，所得的余数是八进制数的最后一位（本例中为 1）；然后把原始的数除以 8，对除法结果重复上述过程，得到倒数第二位。（如第 7 章所示，printf 可以显示八进制的数，所以这个程序实际上有更简单的写法。）

5. 重写 4.1 节的 upc.c 程序，使用户可以一次输入 11 位数字，而不用先输入 1 位，再输入 5 位，最后再输入 5 位。

```
Enter the first 11 digits of a UPC: 01380015173
Check digit: 5 
```

6. 欧洲国家及地区不使用北美的 12 位通用产品代码（UPC），而使用 13 位的欧洲商品编码（European Article Number, EAN）。跟 UPC 一样，每个 EAN 码的最后也有一个校验位。计算校验位的方法也类似：首先把第 2位、第 4位、第 6位、第 8位、第 10位和第 12位数字相加；然后把第 1位、第 3位、第 5 位、第 7 位、第 9 位和第 11位数字相加；接着把第一次加法的结果乘以 3，再和第二次加法的结果相加；随后，再把上述结果减去 1；相减后的结果除以 10 取余数；最后用 9 减去上一步骤中得到的余数。

   以 Güllüoglu 牌土耳其软糖（开心果和椰子口味）为例，其 EAN 码为 8691484260008。第一个和为6+1+8+2+0+0=17，第二个和为 8+9+4+4+6+0=31。第一个和乘以 3 再加上第二个和得到 82，减 1 得到 81。这个结果除以 10 的余数是 1，再用 9 减去余数得到 8，与原始编码的最后一位一致。请修改

​	4.1 节的 upc.c 程序以计算 EAN 的校验位。用户把 EAN 的前 12 位当作一个数输入：

```
Enter the first 12 digits of an EAN: 869148426000
Check digit: 8
```

## 第五章

### 练习题

1. 下列代码片段给出了关系运算符和判等运算符的示例。假设 i、j 和 k 都是 int 型变量，请给出每道题的输出结果。

```
(a) i = 2; j = 3; k = i * j == 6; printf("%d", k); 
(b) i = 5; j = 10; k = 1; printf("%d", k > i < j); 
(c) i = 3; j = 2; k = 1; printf("%d", i < j == j < k); 
(d) i = 3; j = 4; k = 5; printf("%d", i % j + i < k); 
```

下列代码片段给出了逻辑运算符的示例。假设 i、j 和 k 都是 int 型变量，请给出每道题的输出结果。

```
(a) i = 10; j = 5; printf("%d", !i < j); 
(b) i = 2; j = 1; printf("%d", !!i + !j); 
(c) i = 5; j = 0; k = -5; printf("%d", i && j || k); 
(d) i = 1; j = 2; k = 3; printf("%d", i < j || k); 
```

 *3. 下列代码片段给出了逻辑表达式的短路行为的示例。假设 i、j 和 k 都是 int 型变量，请给出每道题的输出结果。

```
(a) i = 3; j = 4; k = 5; printf("%d", i < j || ++j < k); printf("%d %d %d", i, j, k);
(b) i = 7; j = 8; k = 9; printf("%d", i – 7 && j++ < k); printf("%d %d %d", i, j, k); 
(c) i = 7; j = 8; k = 9; printf("%d", (i = j) || (j = k)); printf("%d %d %d", i, j, k); 
(d) i = 1; j = 1; k = 1; printf("%d", ++i || ++j && ++k); printf("%d %d %d", i, j, k); 
```

*4. 编写一个表达式，要求这个表达式根据 i 小于、等于、大于 j 这 3 种情况，分别取值为-1、0、+1。

*5. 下面的 if 语句在 C 语言中是否合法？

```
if (n >= 1 <= 10) 
printf("n is between 1 and 10\n"); 
```

如果合法，那么当 n 等于 0 时会发生什么？

*6. 下面的 if 语句在 C 语言中是否合法？

```
if (n == 1 - 10) 
printf("n is between 1 and 10\n"); 
```

如果合法，那么当 n 等于 5 时会发生什么？

7. 如果 i 的值为 17，下面的语句显示的结果是什么？如果 i 的值为-17，下面的语句显示的结果又是什么？

`printf("%d\n", i >= 0 ? i : -i);` 

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

9. 下面两个 if 语句是否等价？如果不等价，为什么？

```C
if (score >= 90) if (score < 60) 
	printf("A"); printf("F"); 
else if (score >= 80) else if (score < 70) 
	printf("B"); printf("D"); 
else if (score >= 70) else if (score < 80) 
printf("C"); printf("C"); 
else if (score >= 60) else if (score < 90) 
printf("D"); printf("B"); 
else else 
printf("F"); printf("A");
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

### 编程题

1. 编写一个程序，确定一个数的位数：

```
Enter a number: 374
The number 374 has 3 digits
```

假设输入的数最多不超过 4 位。提示：利用 if 语句进行数的判定。例如，如果数在 0 和 9 之间，那么位数为 1；如果数在 10 和 99 之间，那么位数为 2。

2. 编写一个程序，要求用户输入 24 小时制的时间，然后显示 12 小时制的格式：

```
Enter a 24-hour time: 21:11
Equivalent 12-hour time: 9:11 PM 
```

注意不要把 12:00 显示成 0:00。

3. 修改 5.2 节的 broker.c 程序，做出下面两种改变。
   (a) 不再直接输入交易额，而是要求用户输入股票的数量和每股的价格。
   (b) 增加语句用来计算经纪人竞争对手的佣金（少于 2000 股时佣金为每股 33 美元+3 美分，2000 股或更多股时佣金为每股 33 美元+2美分）。在显示原有经纪人佣金的同时，也显示出竞争对手的佣金。

4. 表 5-6 中展示了用于测量风力的蒲福风级的简化版本。

### 表 5-6  简化的蒲福风级

| 速度（海里 / 小时） |       描述        |
| :-----------------: | :---------------: |
|       小于 1        |   Calm（无风）    |
|        1 ~ 3        | Light air（轻风） |
|       4 ~ 27        |  Breeze（微风）   |
|       28 ~ 47       |   Gale（大风）    |
|       48 ~ 63       |   Storm（暴风）   |
|       大于 63       | Hurricane（飓风） |

编写一个程序，要求用户输入风速（海里/小时），然后显示相应的描述。

5. 在美国的某个州，单身居民需要缴纳表 5-7 中列出的所得税。

### 表 5-8  每日航班信息

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

编写一个程序，要求用户输入应纳税所得额，然后显示税金。

6. 修改 4.1 节的 upc.c 程序，使其可以检测 UPC 的有效性。在用户输入 UPC 后，程序将显示 VALID 或

NOT VALID。

7. 编写一个程序，从用户输入的 4 个整数中找出最大值和最小值：

Enter four integers: 21 43 10 35

Largest: 43 

Smallest: 10 

 

要求尽可能少用 if 语句。提示：4 条 if 语句就足够了。

8. 表 5-8 给出了从一个城市到另一个城市的每日航班信息。

### 表 5-8  每日航班信息

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

编写一个程序，要求用户输入一个时间（用 24 小时制的时分表示）。程序选择起飞时间与用户输入

最接近的航班，显示出相应的起飞时间和抵达时间。

Enter a 24-hour time: 13:15

Closest departure time is 12:47 p.m., arriving at 3:00 p.m. 

提示：把输入用从午夜开始的分钟数表示。将这个时间与表格里（也用从午夜开始的分钟数表示）

的起飞时间相比。例如，13:15 从午夜开始是 13×60+15 = 795 分钟，与下午 12:47（从午夜开始是

767 分钟）最接近。

9. 编写一个程序，提示用户输入两个日期，然后显示哪一个日期更早：

Enter first date (mm/dd/yy): 3/6/08

Enter second date (mm/dd/yy): 5/17/07

5/17/07 is earlier than 3/6/08 

10. 利用 switch 语句编写一个程序，把用数字表示的成绩转换为字母表示的等级。

Enter numerical grade: 84

Letter grade: B 

 

使用下面的等级评定规则：A 为 90～100，B 为 80～89，C 为 70～79，D 为 60～69，F 为 0～59。如

果成绩高于 100 或低于 0，则显示出错消息。提示：把成绩拆分成 2 个数字，然后使用 switch 语句

判定十位上的数字。

11. 编写一个程序，要求用户输入一个两位数，然后显示该数的英文单词：

Enter a two-digit number: 45

You entered the number forty-five. 

 

提示：把数分解为两个数字。用一个 switch 语句显示第一位数字对应的单词（“twenty”“thirty”等），

用第二个 switch 语句显示第二位数字对应的单词。不要忘记 11～19 需要特殊处理。