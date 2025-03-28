# C51学习笔记



# STm32学习笔记

## STm32基础知识

### STm32简介：

•STM32是ST公司基于ARM Cortex-M内核开发的32位微控制器
•STM32常应用在嵌入式领域，如智能车、无人机、机器人、无线通信、物联网、工业控制、娱乐电子产品等
•STM32功能强大、性能优异、片上资源丰富、功耗低，是一款经典的嵌入式微控制器

<img src="images\image-20250320082822991.png" alt="image-20250320082822991" style="zoom:50%;" />

其中的CoreMark是内核跑分的意思

### ARM

•ARM既指ARM公司，也指ARM处理器内核
•ARM公司是全球领先的半导体知识产权（IP）提供商，全世界超过95%的智能手机和平板电脑都采用ARM架构
•ARM公司设计ARM内核，半导体厂商完善内核周边电路并生产芯片



![image-20250320083117286](images\image-20250320083117286.png)

ST公司设计的就是内核之外的存储器和外设

<img src="images\image-20250320083122223.png" alt="image-20250320083122223" style="zoom:50%;" />

### STm32F103C8T6

•系列：主流系列STM32F1
•内核：ARM Cortex-M3
•主频：72MHz
•RAM：20K（SRAM）RAM为存储内存，实际存储介质为SRAM
•ROM：64K（Flash）ROM程序存储器，实际介质为Flash
•供电：2.0~3.6V（标准3.3V）

​	C51为5V供电，USB也是5V供电，所以在使用STm32的时候要加一个稳压芯片，然后将5V电压降至3.3V才能给STm32供电。

•封装：LQFP48 意思是一共有48个引脚 

<img src="images\image-20250320083222836.png" alt="image-20250320083222836" style="zoom:50%;" />

### 片上资源/外设

英文名字为Peripheral 外设，STm32主要学习的就是外设，通过程序配置外设，来完成我们想要的功能。

![image-20250320083240642](images\image-20250320083240642.png)

加绿色的是位于Cortex-M3内核中的外设

NVIC：用于管理中断的设备，配置中断的优先级。
SysTick：STm32是可以加入操作系统的，比如FreeRTOS，UCos等，如果用了这些操作系统，就需要SysTick提供定时来进行任务切换的功能，也可以用于Delay()延时函数的实现。
RCC：对时钟进行控制，使能各模块时钟，在STm32中其它外设在上电情况下默认没有时钟的，不给时钟的情况下，操作时钟是无效的，外设也不会工作，这样的目的是降低功耗，所以在操作外设前要先使能时钟，用RCC完成时钟使能。
GPIO：
AFIO：完成复用功能端口的重定义和中断端口的配置。
EXIT：配置好外部中断后，当引脚电平发生变化时，就可以触发中断，让CPU来处理任务。
TIM：定时器分为高级定时器、通用定时器、基本定时器。常用的是通用定时器，这个定时器除了基本的定时工作外，还可以定时中断、测频率、输出PWM波、配置专用编码器接口。
ADC：STm32中内置了12位的AD转换。
DMA：充当CPU的助手，帮助CPU搬运文件。
USART：同步或异步串口，UART是异步串口。
IIC：
SPI：这两个都是通讯协议。
CAN：主要用于汽车领域。
USB：学习这个协议之后可以用于模拟鼠标，模拟U盘。
RTC：完成年月日时分秒计时功能，可以接外部备用电池，这样即使掉电的情况下也可以正常运行。
CRC：数据的一种校验方式，用于判断数据的正确性。
PWR：可以让芯片进入睡眠状态。
BKP：可由备用电池保持数据
IWDG：
WWDG： 这两个在STm32出现死循环的时候可以及时复位芯片。因为电磁干扰。死机或程序设计不合理导致死循环时，看门狗可以及时复位芯片。
STm32F103C8T6没有下面的四个外设
DAC：
SDIO：读取SD卡。
FSMC：扩展内存或配置成其它总线协议，用于某些硬件的操作。
USB OTG：用OTG功能，让USB作为主机去读取其它的USB设备。

### 命名规则

![image-20250320090017330](images\image-20250320090017330.png)

### 系统结构

![image-20250320090032787](images\image-20250320090032787.png)

​	从图上可以看出，从内核Cortex-M3引出了三条总线，分别是ICode指令总线、DCode数据总线，System系统总线。ICode和DCode总线主要是用来连接Flash闪存的，Flash就是用来存储程序的，ICode总线就是用来加载程序指令的，DCode总监是用来加载数据的，比如常量和调试数据这些。除了DCode和ICode内核还引出了System总线，用来连接余下的设备。
​	内核的下方就是DMA外设，DMA就是内核的小秘书，用来搬运数据减轻数据搬运对CPU资源的占用。比如说模数转换可以设置1ms转换一次，如果不能及时从寄存器中搬运出来的话新的数据就会覆盖。外设通过DMA请求线发送DMA请求，DMA通过DMA总线获得总线控制权，然后访问并转运数据，整个过程不用CPU参与，省下了CPU的时间来做其它事情。图上的DMA总线拥有和CPU一样的总线控制权用于访问外设，也可以说是外设都是小弟。
​	图上的SRAM用于存储程序运行时的变量数据。
​	图上右下角就是AHB总线和挂载的外设，AHB是先进高性能总线，用于挂载主要的设备，一般都是最基本或性能比较高的外设，比如复位和时钟控制这些最基本的电路，AHB总线通过桥接器连接到APB先进外设总线。因为AHB和APB的总线协议和总线速度，还有数据传送格式的差异，所以中间需要加两个桥接来完成数据的转换和缓存。通过桥接1连接到APB2总线，通过桥接2连接到APB1总线。性能的话AHB>APB，APB2>APB1。APB2一般和AHB同频都是72MHz，APB1为36MHz，APB2连接的都是重要外设，当然还有一些外设的一号选手，比如说USART1和SPI1这样的外设，而APB2连接的都是一些次要的外设。

### 引脚定义	

引脚示意图的小黑点的左边为1号引脚，然后逆时针排列。

<img src="images\image-20250320094636272.png" alt="image-20250320094636272" style="zoom: 200%;" />

注意：标为红色为电源相关引脚，蓝色为最小系统相关引脚，绿色为IO口、功能口引脚。
类型：
	S代表电源Source，I代表输入Input，O代表输出Output，I/O代表输入输出Input&Output。
IO口电平：引脚可以容忍的电压，标为FT的可以容忍5V电压，没有标注FT的只能容忍3.3V电压。
主功能：主功能是上电后默认的功能，一般和引脚名称相同，如果不同，引脚的实际功能是主功能而不是引脚名称的功能。
默认复用功能：IO口上同时连接的外设功能引脚，在配置IO口时，可以选择是通用IO口还是复用功能。
重定义功能：如果两个功能定义在了一个IO口上，但却要用到两个功能时，可以把其中一个复用功能重映射到其它端口上，但这样做的前提是重映射表里面有对应的端口。

1.备用电池引脚供电引脚，接3V电池给RTC、备份寄存器供电。
2.IO口、侵入检测、RTC。IO口可以根据程序输出或读取高低电平，是最基本也是最常用的功能了。侵入检测的主要作用是防拆，例如一些产品的外壳上有些防拆触点，通过高低电平检测来控制清空内部数据，保障数据安全，街上电路到这个引脚，如果有人拆开设备的话，触点就会断开，这个引脚的高低电平就会发生变化。RTC引脚可以用来输出RTC校准时钟、RTC闹钟脉冲或者秒脉冲。
3.4. 3号和4号引脚为IO口、接32.768MHz晶振
5.6. 5号和6号引脚接系统主晶振，一般为8MHz，芯片内部有锁相环电路，可以对8MHz进行倍频，最终产生72MHz频率作为芯片的主时钟。
7.NRST是系统复位引脚，N代表它是低电平复位。
8.9.是内部模拟部分的电源，比如ADC、RC振荡器。VSS是负极，接GND，VDD是正极，接3.3V。
10-19.为IO口，PA0，也就是10号引脚兼具WKUP功能，可以用于唤醒处于待机状态的STm32。加粗的IO口推荐优先使用，没有加粗的IO口可能要配置之后才能使用。
20.IO口或者BOOT引脚，BOOT引脚是用来配置启动模式的。
21-22.IO口。
23-24.系统的主电源口，同样的VSS为负极，VDD为正极。
25-33.这些都是IO口。
35-36.主电源口。
34、37-40.这些是IO口或者调试端口，默认功能是调试端口，用来调试和下载程序的。STm32支持SWD和JTAG两种调试方式，SWD要两根线：SWDIO-PA13，SWCLK-PA14，ST-Link用的是SWD方式。JTAG要五根线：JTMS、JTCK、JTDI、JTDO、NJTRST。使用SWD方式时PA15、PB3、PB4可以切换为普通IO口使用，但因为其默认功能是调试端口，所以需要在程序中进行配置。
44.BOOT0和BOOT1一样使用来做启动配置的。
47-48.主电源口。
STm32内部采用分区供电的方式，供电口会比较多，在使用时，把VSS都接GND，VDD都接3.3V即可

### 启动配置

​	启动配置的作用就是指定程序开始运行的位置，一般情况下，程序都是在Flash程序存储器开始执行，但是某些情况下也可以让程序在别的地方开始执行，用来完成特定功能。![image-20250320102507286](images\image-20250320102507286.png)	表格中的X表示无论是高电平还是低电平，1代表的是3.3V高电平。内置SRAM启动模式是调试程序的时候使用的。BOOT引脚的值是在上电一瞬间有效的，后边便无所谓了，例如BOOT1引脚和PB2是同一个引脚，就是在上电一瞬间是BOOT1功能，过后即切换为PB2功能。
​	☆作串口下载用，系统存储器存的即为STm32中的一段BootLoader程序，BootLoader的作用就是接受串口的数据然后刷新到主存中，这样就可以使用串口下载程序了。

### 最小系统电路

![image-20250320113908292](images\image-20250320113908292.png)

​	晶振：20pF的是起振电容，如果要使用RTC功能，则还要接一个32.768kHz晶振在3、4号引脚上，OSC32就是32.768kHz的意思，因为32768是2的15次方，内部的RTC电路经过2的15次方分频，就可以生成1s的时间信号了。
​	复位：低电平复位，按下K1时，NRST接地产生了低电平信号，7号引脚上电时，C3没有充电相当于短路，此时NRST为低电平，上电后C3充满电相当于短路，NRST被电阻R1拉高。其效果就是上电一瞬间，单片机复位完成，一些小的设备用针戳一下就会复位就是这样的原理。
​	STm32及其供电：VBAT备用电池引脚是给RTC和备份寄存器服务的，用到的话就可以接一个纽扣电池，如果用不到的话就悬空或者接上3.3V电源即可。三个供电部分的C4、C5、C6、C7这几个是滤波电容，用于保持供电电压的稳定。从图上可以看到，STm32的供电是分为四个区域单独供电的，但是入门学习阶段可以直接将这四个供电电路接在一起即可。

### 型号分类及缩写

![image-20250320115029156](images\image-20250320115029156.png)

​	这个表主要使用来选择启动文件的，STm32F103C8T6使用的启动文件是.md。
​	STm32的开发方式主要有基于寄存器的方式，基于标准库也就是库函数，这个是ST公司封装好的函数，和基于HAL库的方式，基于寄存器的方式和51单片机的开发方式一样，用程序直接配置寄存器，来达到我们想要的功能，这种方式最底层最直接，效率会高一些。
​	LD-Low Densit、MD-Medium Density、HD-High Density、XL-Extra Density
CL-Connectivity Line(互联型产品)，其中VL后缀代表的是Value Line性价比系列。

### 新建工程步骤

•建立工程文件夹，Keil中新建工程，选择型号
•工程文件夹里建立Start、Library、User等文件夹，复制固件库里面的文件到工程文件夹
•工程里对应建立Start、Library、User等同名称的分组，然后将文件夹内的文件添加到工程分组里
•工程选项，C/C++，Include Paths内声明所有包含头文件的文件夹
•工程选项，C/C++，Define内定义USE_STDPERIPH_DRIVER
•工程选项，Debug，下拉列表选择对应调试器，Settings，Flash Download里勾选Reset and Run

整体的结构：总文件夹--TEST_1-project.μvproj
                                         --TEST_2-project.μvproj
	这里要注意的是.μvproj文件不好改名字，所以可以将存放.μvproj的文件夹的名字用来标识项目的目的，而.μvproj只用一个通用的名字即可。还有就是Keil的文件管理很抽象，新建的工程和你自己创建的文件夹是不会自动同步的，需要自己手动添加组，然后添加文件，最后还要在工程魔法棒里面添加工程的包含目录，不然会找不到头文件，就是相当于C/C++的include path。
	新建main.c文件时，一定要勾选USER文件夹，否则的话会在工程的最外边，默认的，改字体大小的话在扳手工具中点colors&fronts，不想在输入中文的时候有奇怪的？出现的话，就点encoding中的UTF-8即可。其他工程在Define内声明了USE_STDPERIPH_DRIVER还声明了STM32F10X_MD字符串，但Keil是已经自动声明了这个所以不用重复声明。

### 工程架构

![image-20250320132036589](images\image-20250320132036589.png)
STm32的程序就是从启动文件开始执行的
	固件库文件说明：
	htmress 两张图片
	Libraries库函数
	Project示例工程
	Utilities评估程序
	ST公司自己的开发板的程序
	Release_Notes.html 发布页面
	stm32f10x_stdperiph_lib_wm.chm使用手册
启动文件的位置：

```C
STM32F10x_StdPeriph_Lib_V3.5.0\Libraries\CMSIS\CM3\DeviceSupport\ST\STM32F10x\startup\arm
启动文件和前面型号分类是相对应的，对于STm32F103C8T6要选择的就是md.s文件
可以直接全部复制然后放在自己新建的START文件夹中即可
startup_stm32f10x_cl.s
startup_stm32f10x_hd.s
startup_stm32f10x_hd_vl.s
startup_stm32f10x_ld.s
startup_stm32f10x_ld_vl.s
startup_stm32f10x_md.s
startup_stm32f10x_md_vl.s
startup_stm32f10x_xl.s
```
在启动文件中有一个复位中断，在复位中断中就调用了SystemInit和main函数，这个中断就是整个程序的入口。
标准库文件的位置：
```C
STM32F10x_StdPeriph_Lib_V3.5.0\Libraries\CMSIS\CM3\DeviceSupport\ST\STM32F10x
// 一共有三个，把这三个文件放到自己建的START文件夹中
// 外设寄存器描述文件，和C51的REGX52.h一样
stm32f10x.h       
// 用于配置STm32的时钟，STm32主频72MHz就是在这个文件配置的
system_stm32f10x.c
system_stm32f10x.h
```
内核寄存器的描述文件的位置：
```C
STM32F10x_StdPeriph_Lib_V3.5.0\Libraries\CMSIS\CM3\CoreSupport
// 这两个就是内核寄存器描述文件的位置，因为还有一些内核的配置函数，所以有一个.c源文件
// 添加之后文件图标带了一个钥匙，意思就是这是一个只读文件
core_cm3.c
core_cm3.h
```
新建Library文件夹，然后将
```C
STM32F10x_StdPeriph_Lib_V3.5.0\Libraries\STM32F10x_StdPeriph_Driver\inc
STM32F10x_StdPeriph_Lib_V3.5.0\Libraries\STM32F10x_StdPeriph_Driver\src
```
这两个文件夹中的文件都放到Library文件夹中，然后在工程中添加组，然后添加文件，其中的misc.c是内核库函数，其余都是外设库函数。

最后要在示例工程文件夹中的Template中将
```C
STM32F10x_StdPeriph_Lib_V3.5.0\Project\STM32F10x_StdPeriph_Template
// 配置头文件的包含关系
stm32f10x_conf.h
// 用来存放中断函数的
stm32f10x_it.c
stm32f10x_it.h
```
将这三个文件放在USER目录中，再打开stm32f10x.h有一句宏定义，USE_STDPERIPH_DRIVER，C/C++，define中增加这个宏就可以只包含一个库就包含了所有库了。

GPIO简介

•GPIO（General Purpose Input Output）通用输入输出口
•可配置为8种输入输出模式
•引脚电平：0V~3.3V，部分引脚可容忍5V，此处需要注意的是容忍5V的意思是输入电压可以达到5v，但是输出仍然只有3.3V，STm32引脚的最大输出电压就是3.3V。
•输出模式下可控制端口输出高低电平，用以驱动LED、控制蜂鸣器、模拟通信协议输出时序等，例如SPI、IIC通讯协议。
•输入模式下可读取端口的高低电平或电压，用于读取按键输入、外接模块电平信号输入、ADC电压采集、模拟通信协议接收数据等

拓展知识：1.8V、3.3V、5V、12V等常用电压等级是如何确立的？
3.3V是因为当年演进到.35um工艺的时候栅极氧化层厚度减到了7nm左右，能承受的最大源漏电压大概是4V，减去10%安全裕度是3.6V，又因为板级电路的供电网络一般是保证±10%的裕量，所以标准定在了3.6V × 90% = 3.3V。
1.8V同理，.18um节点栅极氧化层厚度进一步降低到了4nm左右，ds耐压极限降低到了大约2.3V，同样的逻辑，先0.9变成2.7，再±10%，定在了1.8V。
早期晶体管电路单管压降0.7v，一个电路里经常多个晶体管串联。比如4管串联，电源至少保证0.7x4=2.8v才能保证电路正常工作。所以早期有3v，5v等标准。后来7805电源IC出来以后，5v成了事实标准。

## GPIO

### GPIO基本结构

![image-20250320132858948](images\image-20250320132858948.png)
在STm32中，所有的外设都是挂载在APB2总线上的
每个GPIO外设总共有16个引脚，编号是从0到15
驱动器是用来增加信号的驱动能力的，寄存器只负责存储数据，如果要进行点灯这样的操作的话，就需要驱动器来增加驱动能力。
寄存器就是一段特殊的存储器，内核可以通过APB2总线对寄存器进行读写，因为STm32是32位的，所以STm32的寄存器也是32位的，但GPIO只有16位，所以GPIO寄存器只有低16位有对应的端口，高16位没有对应的端口，是没有用到的。



### GPIO位结构和模式
![image-20250320142632455](images\image-20250320142632455.png)
	通过配置GPIO的端口配置寄存器，端口可以被配置为以下八种模式。
![image-20250320143352629](images\image-20250320143352629.png)
	从I/O引脚开始看起，输入时电平信号从I/O引脚流入会先经过两个保护二极管，上方二极管正极接VDD也就是3.3V，下方二极管负极接VSS也就是0V，当电压在0-3.3V时上下两个二极管都不导通，如果IO引脚电压大于VDD，则会使得上方二极管导通，电流从VDD流出。如果IO引脚电压小于VSS，则会使得下方二极管导通，电流从VSS流出，从而保护了内部电路不会烧坏。
	输入电流经过保护电路后，向上走会将过两个上拉电阻，上方电阻通过开关接到VDD，下方电阻通过开关接到VSS。如果上面开关导通下面断开，就是上拉输入模式，如果下面开关导通上面断开，就是下拉输入模式，如果两个开关都断开，就是浮空输入模式。在使用浮空输入时端口一定要接上一个连续的驱动源，不能出现引脚悬空的状态。
	这两个电阻的阻值都是比较大的，只是一种弱上拉和弱下拉，目的是尽量不影响正常的输入操作。
	图中的TTL肖特基触发器应该是施密特触发器，其逻辑为：如果输入电压大于某一阈值，输出就会瞬间升为高电平，如果输入电压小于某一阈值，输出就会瞬间降为低电平，用于防止信号失真和硬件消抖。信号经过上拉/下拉电路之后，如果是为了模拟信号采样就会通过触发器前的模拟输入信号线流向ADC上，之所以模拟输入在施密特触发器之前是因为在触发器之后就会变成数字信号了。因此在经过施密特触发器对输入电压进行整形之后就流向了复用功能输入。
	IO控制方法：直接操作寄存器、用来单独控制输出寄存器的某一位而不影响其它位，在消除写1即可将输出的某一位消零，位带，映射地址通过位寻址。
	GPIO输出时：
	一路输入是通过寄存器，另一路是来自其它的片上外设的复用功能输入，输出控制器会控制两个MOS管，用新号控制开关的导通和关闭，开关负责将IO口接到VDD或VSS。推挽输出也叫做强推输出，输出能力强，推完输出模式下P-MOS和N-MOS都有效。数据寄存器为1时上管导通，下管断开，输出接到VDD，输出高电平，为0时上管断开，下管导通输出接到VSS，输出低电平。这种模式下，高低电平均有较强的驱动能力，所以推挽输出模式也叫做强推输出模式。在推挽输出模式下，STm32对IO口有绝对的控制权，高低电平都由STm32说了算。
	如果一个输入什么都不接，那么它的输入就是不确定的，处于一种浮动状态，此时引脚的输入电平极易受外界干扰而变化，就像是一个物体悬浮在太空一样，它的位置是不确定的，受到一点扰动就会发生变化，为了避免引脚悬空导致的输入数据不确定，我们就需要在这里加上，上拉电阻或者下拉电阻来给引脚一个默认电平，就相当于太空中的物体，来到了地球之后，就会因为重力的作用而下坠。上拉和下拉是为了给输入一个默认的输入电平，因为对于一个数字的端口，输入不是高电平就是低电平。

施密特触发器
	施密特触发器是高于上限和低于下限才会有电平的高低变化，所以在输入和输出处有波动的话并不会触发施密特触发器来改变电平，知道下次低于下限时才会触发。
	输出部分：数字部分由输出数据寄存器或片上外设控制，两种控制方式通过数据选择器连接到了输出控制部分，如果选择通过输出数据寄存器进行控制就是普通的IO口输出，写输出数据寄存器的某一位就可以对应操作某个端口了。位设置/清除寄存器可以用来单独操作输出数据寄存器的某一位而不影响其它位，因为输出数据寄存器同时控制16个端口，并且这个寄存器只能整体读写，所以想控制其中一个端口而不影响其他端口的话，就需要一些特殊的操作方式。
	1.限度出这个寄存器，然后用按位与和按位或的方式改变某一位，最后再将更改后的数据写回去，在C语言中就是&=和|=操作。
	2.设置位设置/清除寄存器，对某一位置1的操作，在位设置寄存器的对应位写1即可，其余的位写0，这样它内部的电路就会自动将输出寄存器对应位置为1，而剩下的位则保持不变，如果相对某一位进行清0的操作，就在清除寄存器对应位写1即可，内部电路就会把这一位清0了。
	3.读写STm32中的位带区域，位带的作用和51单片机的位寻址作用差不多，在STm32中，专门分配了一段地址区域，这段地址映射了RAM和外设寄存器所有的位，读写这段地址中的数据，就相当于读写所映射位置中的某一位。
	4.库函数用的方式是读写位设置/清除寄存器的方式
	推挽输出：
	推挽输出也叫做强推输出，输出能力强，推完输出模式下P-MOS和N-MOS都有效。数据寄存器为1时上管导通，下管断开，输出接到VDD，输出高电平，为0时上管断开，下管导通输出接到VSS，输出低电平。这种模式下，高低电平均有较强的驱动能力，所以推挽输出模式也叫做强推输出模式。在推挽输出模式下，STm32对IO口有绝对的控制权，高低电平都由STm32说了算。
	开漏输出：再开漏模式下，P-MOS是无效的，只有N-MOS在工作，数据寄存器为1时下管断开，这时输出相当于断开，也就是高阻模式，数据寄存器为0时，下管导通，输出直接接到VSS，输出低电平，这种模式只有低电平有驱动能力，高电平是没有驱动能力的，因为P-MOS都没有导通根本就驱动不了负载，此时呈现的是高阻态。
	1.开漏模式可以用作通讯协议的驱动方式。比如IIC的通信引脚，就是使用的开漏模式
	2.在多机通讯的情况下，可以避免各个设备的相互干扰，另外开漏模式可以输出5V的电压信号
	3.在IO口接5V的上拉电阻可以输出5V的高电平，当输出低电平时内部N-MOS直接VSS，当输出高电平时，由外部上拉电阻拉高至5V
	关闭模式：
	当引脚配置为输入模式的时候，两个MOS管都无效，也就是输出关闭，端口的信号由外部信号来控制。

```C
// 库函数中GPIO的8种模式定义
GPIO_Mode_AIN            // Analog In 模拟输入
GPIO_Mode_In_Floating    // 浮空输入
GPIO_Mode_IPO            // In Pull Down 下拉输入
GPIO_Mode_IPU            // In Pull Up 上拉输入
GPIO_Mode_OUT_OD         // Out Open Drain 开漏输出
GPIO_Mode_OUT_PP         // Out Push Pull 推挽输出
GPIO_Mode_AF_OD          // Atl Open Drain 复用开漏输出
GPIO_Mode_AF_PP          // Atl Push Pull 复用推挽输出
// 把指定端口设置为高电平
void GPIO_SetBits(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);
// 把指定端口设置为低电平
void GPIO_ResetBits(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);
// 按位写/清除指定GPIO端口的位
// 前两个参数指定端口，根据第三个参数的值来设置端口
// GPIOPin的选择都可以按照按位或的形式选择多个端口 比如GPIOPin1 | GPIOPin2
void GPIO_WriteBit(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin, BitAction BitVal);
// 按位写/清除指定GPIO端口，这个是操作一整个16位的端口
// Write函数是写到了ODR寄存器，也就是Output Data Register输出数据寄存器
void GPIO_Write(GPIO_TypeDef* GPIOx, uint16_t PortVal);
// 读取输入数据寄存器的某一端口的输入值，返回端口的高低电平
uint8_t GPIO_ReadInputDataBit(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);
// 读取整个输入数据寄存器，返回值的每一位代表一个端口的高低电平
uint16_t GPIO_ReadInputData(GPIO_TypeDef* GPIOx);
// 读取输出数据寄存器的某一位，因此原则上并不是用来读取端口的输入数据的，一般用于输出模式下，用来看自己的输出的是什么
uint8_t GPIO_ReadOutputDataBit(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);
// 用于读取整个寄存器的值
uint16_t GPIO_ReadOutputData(GPIO_TypeDef* GPIOx);
```


1
### 浮空/上拉/下拉输入

![image-20250320162834121](images\image-20250320162834121.png)

### 模拟输入

除了在模拟输入模式中会关闭数字的输入功能，其它的七种模式都是开启的

![image-20250320163218615](images\image-20250320163218615.png)

### 开漏/推挽输出

在输出模式下，输入模式也是有效的，在输入模式下，输出模式是无效的，因为一个端口只能有一个输出，但可以有很多个输入，所以当配置成输出模式时，内部也可以顺便输入一下，这是没有什么影响的。

![image-20250320163224402](images\image-20250320163224402.png)




### 复用开漏/推挽输出

用输出数据寄存器可以保证多位数据的同步性，因为是一下子读写整个寄存器



![image-20250320163233873](images\image-20250320163233873.png)



## 硬件电路相关知识

### LED和蜂鸣器介绍

•LED：发光二极管，正向通电点亮，反向通电不亮

|                    图1                     |                             图2                              |
| :----------------------------------------: | :----------------------------------------------------------: |
| ![图1](images\image-20250320171709580.png) | <img src="images\image-20250320171717780.png" alt="图2" style="zoom: 50%;" /> |

三角形的顶点指向的方向是负极，对于实物二极管，如果没有修剪引脚的话，小的是正极，大的是负极，长脚正极，短脚负极。

•有源蜂鸣器：内部自带振荡源，将正负极接上直流电压即可持续发声，频率固定

<img src="images\image-20250320171953829.png" alt="image-20250320171953829" style="zoom: 50%;" />



![image-20250320171959127](images\image-20250320171959127.png)
低电平蜂鸣器响，高电平蜂鸣器不响。
•无源蜂鸣器：内部不带振荡源，需要控制器提供振荡脉冲才可发声，调整提供振荡脉冲的频率，可发出不同频率的声音

### 硬件电路

![image-20250320172016434](images\image-20250320172016434.png)
对于STm32来说，推挽输出在高低电平都有着很强的驱动能力，因此这两种接法都是可以的，但在单片机开发中，一般使用高电平若驱动，低电平强驱动的原则，因为这样可以一定程度上避免高低电平打架，如果高电平驱动能力弱就不能用第二种连接方式了。

功率大时，直接用IO口驱动会导致STm32负载过重，这是可以用一个三极管驱动电路来完成驱动的任务。PNP最好接在上边，NPN的三极管最好接在下边，因为三极管的通断是要在发射极和基极直接产生一定的开启电压，如果把负载接在发射极这边，可能会导致三极管不能开启。
三极管：带箭头的是发射极，中间的是基极，下边是集电极。箭头指向外的是NPN型，箭头指向内的是PNP型。PNP型三极管是低电平导通，高电平截止，NPN型三极管是高电平导通，低电平截止。
### 面包板

![image-20250320172033006](images\image-20250320172033006.png)
中间的五个孔都是导通的，上下横排全部导通。
### 按键介绍

•按键：常见的输入设备，按下导通，松手断开

•按键抖动：由于按键内部使用的是机械式弹簧片来进行通断的，所以在按下和松手的瞬间会伴随有一连串的抖动

<img src="images\image-20250320172039484.png" alt="image-20250320172039484" style="zoom:25%;" />

<img src="images\image-20250320172043397.png" alt="image-20250320172043397" style="zoom:50%;" />

### 传感器模块简介

•传感器模块：传感器元件（光敏电阻/热敏电阻/红外接收管等）的电阻会随外界模拟量的变化而变化，通过与定值电阻分压即可得到模拟电压输出，再通过电压比较器进行二值化即可得到数字电压输出

![image-20250320172158292](images\image-20250320172158292.png)

![image-20250320172202371](images\image-20250320172202371.png)
光线越强，光敏电阻的阻值越小。温度越高，热敏电阻的阻值越小。红外光线越强，红外接收管的阻值越小。
图上所示的LM393就是传感器的二值化芯片，它使用运算放大器来构建的电压比较器。
强上拉，强下拉，弱上拉，弱下拉，此处的强弱就是阻值大小，阻值越小上下拉的能力越强。N1是一个可变电阻，当N1→∞时，AO此时被上拉至VCC，当N1→0时，AO此时被下拉至0V。AO=N1/(N1+R1)，当N1>>R1时，即相当于VCC。R5是一个上拉电阻，用于保证默认输出为高电平。

### 硬件电路

![image-20250321085729178](images\image-20250321085729178.png)

下接按键，当按键按下时PA0被直接下拉到GND，此时读取PA0口的电压就是低电平，当按键松动时，PA0悬空引脚的电压不确定，则此时必须要求PA0为上拉输入的模式否则就会出现引脚电压不确定的情况。上下指的是接VCC还是GND。

![image-20250321085744182](images\image-20250321085744182.png)

PA0必须配置成下拉输入，一般的单片机不一定有下拉输入模式，所以一般还是配成第一种接法。

![image-20250321085755786](images\image-20250321085755786.png)

PA0可以配置为浮空输入或者上拉输入。可以将上拉和下拉想象成弹簧在拉而电阻越小弹簧的拉力越大，当开关没有按下时，K1相当于电阻其阻值是无穷大，此时电路被上拉至3.3V。当开关按下时，电阻无穷小被直接拉至GND。如果是上拉输入，这是高电平就会更强一些，对应高电平就会更加稳定，但这样的话引脚被强行拉低的时候，损耗也就会大一些。

![image-20250321085804899](images\image-20250321085804899.png)

PA0要配成下拉输入或者浮空输入模式。

![image-20250321085814278](images\image-20250321085814278.png)

## C语言相关知识补充
### C语言数据类型



![image-20250320172242050](images\image-20250320172242050.png)

在51单片机中int是占16位的，而在STm32中int是占32位的，如果要用16位的数据就要用short来表示，stdint里面的关键字都是用typedef重命名的。C语言stdint.h文件和ST变量重命之所以有这些重命名是为了解决51，STm32这些不同位长机器变量的不兼容问题。
这张图片需要注意的就是8位是一个字节。

### C语言宏定义

•关键字：#define
•用途：用一个字符串代替一个数字，便于理解，防止出错；提取程序中经常出现的参数，便于快速修改
•定义宏定义：
 \#define ABC 12345
•引用宏定义：
 int a = ABC; //等效于int a = 12345;
 ### C语言typedef
 关键字：typedef
用途：将一个比较长的变量类型名换个名字，便于使用
定义typedef：
	typedef unsigned char uint8_t;
引用typedef：
	 uint8_t a;	//等效于unsigned char a;

对于变量类型重命名而言，使用typedef更加安全，#define只是无脑改名，而typedef会对命名进行检查，如果不是变量类型名，程序就无法进行编译。
### C语言结构体
关键字：struct
用途：数据打包，不同类型变量的集合
定义结构体变量：
	struct{char x; int y; float z;} StructName;
	因为结构体变量类型较长，所以通常用typedef更改变量类型名
引用结构体成员：
	StructName.x = 'A';
	StructName.y = 66;
	StructName.z = 1.23;
或	pStructName->x = 'A';	//pStructName为结构体的地址	pStructName->y = 66;
	pStructName->z = 1.23;



数组是组合数据类型，但其只能够组合相同类型的，组合不同类型时就需要用到结构体了。为什么会有结构体指针对象这样的操作是因为，实际工作中的结构体一般都是占用存储空间很大的变量，通常用地址传递而不是值传递，可以节省存储空间。

### C语言枚举
关键字：enum
用途：定义一个取值受限制的整型变量，用于限制变量取值范围；宏定义的集合
定义枚举变量：
	enum{FALSE = 0, TRUE = 1} EnumName;
	因为枚举变量类型较长，所以通常用typedef更改变量类型名
引用枚举成员：
	EnumName = FALSE;
	EnumName = TRUE;
如果数是按照顺序累加的，那么后面的赋值就可以省略，宏定义的集合意思是可以使用枚举的值来赋值，可以使程序更加安全，防止了非法值破坏程序，这其实就是有限状态机，FSM。
## 调试方式
串口调试：通过串口通信，将调试信息发送到电脑端，电脑使用串口助手显示调试信息

显示屏调试：直接将显示屏连接到单片机，将调试信息打印在显示屏上

Keil调试模式：借助Keil软件的调试模式，可使用单步运行、设置断点、查看寄存器及变量等功能

在Debug选项中，左边的是电脑模拟STm32右边是使用ST-Link在线仿真
Reset复位
Run全速运行
Stop停止全速运行
Step单步运行
Step-over跳过当前行
Step-out跳出当前函数单步运行
Run-to-cursor-line调到光标指定行单步运行
Serials window串口输出窗口
Analysis windows逻辑分析仪
Peripherals查看外设寄存器

## OLED简介
OLED（Organic Light Emitting Diode）：有机发光二极管
OLED显示屏：性能优异的新型显示屏，具有功耗低、相应速度快、宽视角、轻薄柔韧等特点
0.96寸OLED模块：小巧玲珑、占用接口少、简单易用，是电子设计中非常常见的显示屏模块
供电：3~5.5V，通信协议：I2C/SPI，分辨率：128*64

![image-20250321101134696](images\image-20250321101134696.png)

OLED相当于每个像素都是一个LED，是可以自发光的，不需要LCD补光，因此比较省电。图中双色的OLED只是上面的1/4是黄色的，下面的3/4是蓝色的，而并不是所有的区域都是两种颜色。
### 硬件电路

![image-20250321101214795](images\image-20250321101214795.png)

IIC

![image-20250321101233831](images\image-20250321101233831.png)

SPI

### OLED驱动函数

![image-20250321101348690](images\image-20250321101348690.png)

![image-20250321101259879](images\image-20250321101259879.png)

STm32引脚上电之后，默认是浮空输入的模式，在这个模式下，引脚不会输出电平，所以不会有什么影响。虽然可以用GPIO口来对OLED来进行供电，但是这样做并不符合GPIO的使用规范，负载一定要使用电源来供电。

函数中的前两个参数，第一个是起始行，第二个是起始列。

## 中断系统
中断系统是管理和执行中断的逻辑结构，外部中断是众多能够产生中断的外设之一，对于外部中断来说可以是引脚发生了电平跳变，对于定时器来说，可以是定时的时间到了，对于串口通信来说，可以是接收到了数据。当这些时间发生时，情况比较紧急，比如外部中断来了不处理的话下一个跳变信号就跟着来了，串口接收中断来了，如果不读取接受的数据那么下一个数据过来就会把原来的数据覆盖掉。
中断就相当于定闹钟，如果没有定闹钟就需要不停地看时间，防止睡过头，如果没有中断程序，主程序就只能不断地查询是否有这些事情发生，就不能再干别的事情了。
中断：在主程序运行过程中，出现了特定的中断触发条件（中断源），使得CPU暂停当前正在运行的程序，转而去处理中断程序，处理完成后又返回原来被暂停的位置继续运行
中断优先级：当有多个中断源同时申请中断时，CPU会根据中断源的轻重缓急进行裁决，优先响应更加紧急的中断源。中断优先级是在程序设计的时候，用户自己设置的。
中断嵌套：当一个中断程序正在运行时，又有新的更高优先级的中断源申请中断，CPU再次暂停当前中断程序，转而去处理新的中断程序，处理完成后依次进行返回。






### 中断执行流程

![image-20250321101449417](images\image-20250321101449417.png)
为了程序能够在中断返回后继续原来的工作，在中断执行之前会对程序的现场进行保护，终端执行后会再还原现场。用C语言编程并不用做保护现场的工作，编译器自动帮我们做好了。程序被暂停的地方就叫做断点。

### STm32中断

68个可屏蔽中断通道，包含EXTI、TIM、ADC、USART、SPI、I2C、RTC等多个外设

使用NVIC统一管理中断，每个中断通道都拥有16个可编程的优先等级，可对优先级进行分组，进一步设置抢占优先级和响应优先级

F1系统最多有68个，中断通道就是中断源


![image-20250321080822561](images\image-20250321080822561.png)
![image-20250321080842563](images\image-20250321080842563.png)
![image-20250321080907173](images\image-20250321080907173.png)
![image-20250321080910217](images\image-20250321080910217.png)
灰色的是内核中的中断
Reset 复位中断
当复位事件产生时，程序会自动执行复位中断函数，也就是我们复位后程序开始执行的位置
NMI 不可屏蔽中断，硬件失效、存储管理、总线错误

外设电路检测到有什么异常或者事件，需要提示一下CPU时就可以申请中断，让程序跳到对应的中断函数中执行一次。
EXTI0-EXTI4
EXTI9_5
EXTI15_10

中断的地址是干什么的，因为程序中的中断函数，它的地址是由编译器分配的，是不固定的但中断跳转，由于硬件的限制智能跳到固定的地址执行程序，所以为了让硬件跳转到一个不固定的中断函数里就需要在内存中定义一个地址的列表，列表的地址是固定的，中断发生后就跳转到这个固定位置，然后在这个固定位置由编译器再加上一条跳转到中断函数的代码，这样中断跳转就可以跳到任意位置了，这个中断地址的列表就叫做中断向量表，它就相当于中断的一个跳板。但是C语言编程的话并不需要管这个中断向量表，所以了解即可。
### NVIC基本结构
NVIC-嵌套中断向量控制器，是一个内核外设，是CPU的小助手
![image-20250321101540008](images\image-20250321101540008.png)

### NVIC优先级分组
NVIC的中断优先级由优先级寄存器的4位（0~15）决定，这4位可以进行切分，分为高n位的抢占优先级和低4-n位的响应优先级
抢占优先级高的可以中断嵌套，响应优先级高的可以优先排队，抢占优先级和响应优先级均相同的按中断号排队

每个中断有16个优先级，为了将其分为抢占优先级和响应优先级，就要对其进行分组。相当于插队的优先级，叫响应优先级，即上一个病人看完，下一个即便是后来的也可提前看。情况特别紧急，不等上一个人看完直接冲进去看病，看完了再接着看刚才没看完的，这种优先级叫做抢占优先级，即中断嵌套，抢占优先级高的可以进行嵌套，值越小，优先级越高。即表中的优先级编号，数值小的优先级别越高。因此STm32的中断不存在先来后到的排队方式，在任何时间都是优先级高的优先响应。
![image-20250321101608169](images\image-20250321101608169.png)
分组方式就相当于叫号规则，分法只有5种，抢占多一些还是响应多一些可以由用户自己决定。
### EXIT简介
EXTI（Extern Interrupt）外部中断
EXTI可以监测指定GPIO口的电平信号，当其指定的GPIO口产生电平变化时，EXTI将立即向NVIC发出中断申请，经过NVIC裁决后即可中断CPU主程序，使CPU执行EXTI对应的中断程序
支持的触发方式：上升沿/下降沿/双边沿/软件触发
支持的GPIO口：所有GPIO口，但相同的Pin不能同时触发中断，就是GPIOA_Pin1和 GPIOB_Pin1，不能同时用，因为同一个引脚用的是同一个中断通道。
通道数：16个GPIO_Pin，外加PVD输出、RTC闹钟、USB唤醒、以太网唤醒。加起来一共是20个线路，16个GPIO是主功能，后面的都是来蹭网的，因为外部中断有个功能，就是从低功耗模式下的停止模式唤醒STm32.
触发响应方式：中断响应/事件响应

申请中断让CPU执行中断函数，事件响应是STm32对外部中断增加的一种额外的功能，当外部中断检测到引脚电平变化时，正常的流程是选择触发中断，在STm32中也可以选择触发一个中断，那中断信号就不会通往CPU了而是通向其它外设，用来触发其它外设的操作，比如ADC转换，DMA等外设间的联合工作。
PVD电源电压检测，当电源从电压过低恢复时，就需要PVD借助一下外部中断退出停止模式。对于RTC闹钟来说，有时候为了省电，RTC定一个闹钟之后，STm32会进入停止模式等到闹钟响的时候再唤醒。


上升沿：电平从低电平变到高电平的瞬间。
下降沿：电平从高电平变到低电平的瞬间。
双边沿：上升沿和下降沿。
软件触发：引脚啥事没有，程序里执行一句话就可以触发中断。
### EXIT基本结构

![image-20250321101636772](images\image-20250321101636772.png)
其中EXTI和NVIC不用开时钟，GPIO和AFIO用开时钟，配置STm32的中断就是把从GPIOx到NVIC所涉及的寄存器全部打通。配置流程如下：1.打开RCC时钟(其中EXTI和NVIC不用开时钟，GPIO、AFIO需要打开时钟)。2.配置GPIO为输出模式。3.配置AFIO选择我们用的这一路GPIO连接到后面的EXTI。4.配置EXTI选择边沿触发方式，比如上升沿、下降沿、双边沿，选择触发响应方式，可选择中断响应、事件响应。5.配置NVIC给中断选择一个合适的优先级，最后通过NVIC外部中断信号就可以进入CPU了，这样CPU才能收到中断信号，才能跳转到中断函数里执行中断函数。

3×16通道只能选16个，因此相同的pin不能用，因为只会在3个同pin引脚中选择一个接到后面的通道中去。

本来有20路输出的，但有复用，其中9-5会触发相同的中断函数，15-10也会触发相同的中断函数，在编程时，我们在这两个中断函数需要再根据标志位来区分到底是哪个中断进来的，因为不同的中断其中断标志位还是不一样的。其余的9个通过事件响应通往其他外设。
### AFIO复用IO口
AFIO主要用于引脚复用功能的选择和重定义，数据选择器的作用，图中像一个梯形的

在STM32中，AFIO主要完成两个任务：复用功能引脚重映射、中断引脚选择

![image-20250321101656191](images\image-20250321101656191.png)

```C
// ST公司并没有给AFIO外设单独库文件，是和GPIO放在一起的
// 用来复位AFIO，将AFIO外设的配置全部清除
void GPIO_AFIODeInit(void);
// 用来锁定GPIO配置的，调用这个函数，参数指定某个引脚，那么这个引脚的参数就会被锁定，防止被意外更改
void GPIO_PinLockConfig(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);
// 这两个函数是用来配置AFIO事件输出功能的
void GPIO_EventOutputConfig(uint8_t GPIO_PortSource, uint8_t GPIO_PinSource);
void GPIO_EventOutputCmd(FunctionalState NewState);
// 引脚重映射，第一个参数是重映射的方式，第二个参数是新的状态
void GPIO_PinRemapConfig(uint32_t GPIO_Remap, FunctionalState NewState);
// 调用这个函数，可以配置AFIO的数据选择器，来选择我们想要的中断引脚
void GPIO_EXTILineConfig(uint8_t GPIO_PortSource, uint8_t GPIO_PinSource);
// 和以太网有关，STm32F103C8T6没有以太网相关的外设，用不到
void GPIO_ETH_MediaInterfaceConfig(uint32_t GPIO_ETH_MediaInterface);
```

### EXTI框图

![image-20250321082229619](images\image-20250321082229619.png)

触发信号器通过或门之后就兵分两路，上面一路是触发中断的，下面一路是触发中断事件的，触发中断首先置一个挂起寄存器，这相当于是一个中断标志位了，可以读取这个寄存器判断是哪个通道触发的中断，如果中断挂起寄存器置1，它就会继续向左走，和中断屏蔽寄存器共同进入一个与门然后是到NVIC中断控制器。

触发事件，脉冲发生器用于给一个电平脉冲，用来触发其它外设的动作。

![image-20250321151318790](images/image-20250321151318790.png)
```C
// EXTI库函数
// 清除EXTI的配置，恢复成上电默认的状态
// 因为EXTI只有一个，所以不用指定是哪个EXTI
void EXTI_DeInit(void);
// 根据结构体参数的参数配置EXTI外设
void EXTI_Init(EXTI_InitTypeDef* EXTI_InitStruct);
// 可以把参数传递的结构体变量赋一个默认值
void EXTI_StructInit(EXTI_InitTypeDef* EXTI_InitStruct);
// 用于软件触发外部中断，调用这个函数，参数会给一个指定的中断线，就能软件触发这个外部中断
void EXTI_GenerateSWInterrupt(uint32_t EXTI_Line);
// 1 获取指定的标志位是否置1
FlagStatus EXTI_GetFlagStatus(uint32_t EXTI_Line);
// 2 对置1的标志位进行清除，有的标志位比较紧急，在置标志位后会触发中断
void EXTI_ClearFlag(uint32_t EXTI_Line);
// 3 在中断函数中如果想查看和清除标志位就可以用下面的函数
// 获取中断标志位是否置1
ITStatus EXTI_GetITStatus(uint32_t EXTI_Line);
// 4 清除中断挂起状态位
void EXTI_ClearITPendingBit(uint32_t EXTI_Line);
```

总结：如果想在主程序中查看和清除标志位，就用1、2，如果想在中断函数中查看和清除标志位，用3、4，本质上这4个函数都是对状态寄存器进行读写的，只是3/4函数只能读写与中断有关的标志位，并且对中断是否允许做出了判断。而1、2只是一般的读写标志，没有额外的处理，能不能触发中断的标志位都能读取，所以建议在主程序中用上面两个，中断程序用下面两个，但如果非要在中断中用下面两个也是没有问题的，只不过是库函数针对这两种场景区分了这两类读写函数。
```C
// EXTI的结构体参数
// 相当于选择GPIO的线路
EXTI.line 
// 赋值是Enable、Disable，是否开启
EXTI.lineCmd
// 选择中断模式
// EXTI_Mode_Interrupt 中断模式
// EXTI_Mode_Event 事件模式
EXTI.Mode
// 具体的参数是：
// EXTI_Trigger_Rising 上升沿触发
// EXTI_Trigger_Falling 下降沿触发
// EXTI_Trigger_Rising_Falling 双边沿触发
EXTI.Trigger
```
NVIC在misc.h文件中 
pre-emption 抢占 subpriority 响应优先级
```C
// 用来中断分组的，参数是中断分组的方式
void NVIC_PriorityGroupConfig(uint32_t NVIC_PriorityGroup);
// 根据结构体参数初始化NVIC
void NVIC_Init(NVIC_InitTypeDef* NVIC_InitStruct);
// 设置中断向量表
void NVIC_SetVectorTable(uint32_t NVIC_VectTab, uint32_t Offset);
// 系统低功耗配置
void NVIC_SystemLPConfig(uint8_t LowPowerMode, FunctionalState NewState);
void SysTick_CLKSourceConfig(uint32_t SysTick_CLKSource);


```
在配置中断之前，现制定一个中断的分组，然后使用NVIC_Init初始化一下NVIC就可以了。
```C
typedef struct
{
  // 指定中断通道，名称可以认为是用处
  uint8_t NVIC_IRQChannel;    
  // 指定中断通道是使能还是失能
  uint8_t NVIC_IRQChannel;  
  // 优先级是在多个中断源同时申请，产生拥挤时才有作用，只有一个中断时就随便了
  // 抢占优先级
  uint8_t NVIC_IRQChannelPreemptionPriority;  
  // 响应优先级
  uint8_t NVIC_IRQChannelSubPriority;         
  FunctionalState NVIC_IRQChannelCmd;         
} NVIC_InitTypeDef;
```
中断不多，很难导致中断冲突，对优先级分组来说，就随意了，分组方式整个芯片中只能用一种，因此按理说整个工程只用执行一次，因此如果在模式中进行分组要确保每个模块的分组都是同一个，相互之间不能产生冲突。

中断函数
在STm32中，中断函数的名字都是固定的，每个终端通道都有相对应的中断函数，具体名称可以在启动文件中找到：
```C
// 中断函数的书写格式如下
void NAME(void)
{
	statement;
}
```
中断函数都是无参无返回值的，函数名字不要写错了，如果写错的话就无法进入正确的中断函数中了，最好直接从启动文件复制过来，这样就绝对不会出问题了。在中断函数中，一般都是先进性一个中断标志位判断，确保是我们想要的中断源触发的这个函数，因为只要中断标志位置1了，程序就会跳转到中断函数中，不清除中断标志位，那它就会一直申请中断，程序就会不断响应中断、执行中断函数，那程序就会卡死在中断函数里面了。中断函数不用声明也不需要调用，它是自动执行的。

用的光电对射开关，如果下降沿触发是遮挡物离开时加1，如果是上升沿触发则是进入时加1，双边沿触发的话进入和出去都会触发中断。
```C
void WWDG_IRQHandler(void) {} // 窗口看门狗中断
void PVD_IRQHandler(void) {} // 电源电压检测中断
void TAMPER_IRQHandler(void) {} // 备份寄存器（篡改检测）中断
void RTC_IRQHandler(void) {} // 实时时钟中断
void FLASH_IRQHandler(void) {} // Flash 操作完成中断
void RCC_IRQHandler(void) {} // 时钟控制器 RCC 中断
void EXTI0_IRQHandler(void) {} // 外部中断线0
void EXTI1_IRQHandler(void) {} // 外部中断线1
void EXTI2_IRQHandler(void) {} // 外部中断线2
void EXTI3_IRQHandler(void) {} // 外部中断线3
void EXTI4_IRQHandler(void) {} // 外部中断线4
void DMA1_Channel1_IRQHandler(void) {} // DMA1 通道1 中断
void DMA1_Channel2_IRQHandler(void) {} // DMA1 通道2 中断
void DMA1_Channel3_IRQHandler(void) {} // DMA1 通道3 中断
void DMA1_Channel4_IRQHandler(void) {} // DMA1 通道4 中断
void DMA1_Channel5_IRQHandler(void) {} // DMA1 通道5 中断
void DMA1_Channel6_IRQHandler(void) {} // DMA1 通道6 中断
void DMA1_Channel7_IRQHandler(void) {} // DMA1 通道7 中断
void ADC1_2_IRQHandler(void) {} // ADC1 和 ADC2 的转换完成中断
void USB_HP_CAN1_TX_IRQHandler(void) {} // USB 高优先级或 CAN1 TX 中断
void USB_LP_CAN1_RX0_IRQHandler(void) {} // USB 低优先级或 CAN1 RX0 中断
void CAN1_RX1_IRQHandler(void) {} // CAN1 接收 FIFO1 中断
void CAN1_SCE_IRQHandler(void) {} // CAN1 状态变化错误中断
void EXTI9_5_IRQHandler(void) {} // 外部中断线[9:5]
void TIM1_BRK_IRQHandler(void) {} // TIM1 中断：刹车事件
void TIM1_UP_IRQHandler(void) {} // TIM1 中断：更新事件
void TIM1_TRG_COM_IRQHandler(void) {} // TIM1 中断：触发和通信事件
void TIM1_CC_IRQHandler(void) {} // TIM1 中断：捕获比较事件
void TIM2_IRQHandler(void) {} // 定时器2 更新中断
void TIM3_IRQHandler(void) {} // 定时器3 更新中断
void TIM4_IRQHandler(void) {} // 定时器4 更新中断
void I2C1_EV_IRQHandler(void) {} // I2C1 事件中断（传输、接收等）
void I2C1_ER_IRQHandler(void) {} // I2C1 错误中断
void I2C2_EV_IRQHandler(void) {} // I2C2 事件中断
void I2C2_ER_IRQHandler(void) {} // I2C2 错误中断
void SPI1_IRQHandler(void) {} // SPI1 中断
void SPI2_IRQHandler(void) {} // SPI2 中断
void USART1_IRQHandler(void) {} // USART1 中断
void USART2_IRQHandler(void) {} // USART2 中断
void USART3_IRQHandler(void) {} // USART3 中断
void EXTI15_10_IRQHandler(void) {} // 外部中断线[15:10]
void RTCAlarm_IRQHandler(void) {} // RTC 闹钟中断
void USBWakeUp_IRQHandler(void) {} // USB 唤醒中断
```
中断函数的使用建议：
1.中断函数中不要执行耗时过长的代码，要简短迅速，不要刚一进入中断就延时多少毫秒。
2.最好不要在中断函数中和主函数调用同一个函数或者操作同一个硬件，如果在主函数中调用OLED显示驱动函数，又在中断中调用OLED显示驱动函数，就会出现显示错误，比如说显示一半或者说显示乱码等情况。虽然中断有保护和恢复现场的功能，但这只能保证CPU程序正常返回不出问题，对外部硬件并没有在进入中断的时候进行现场保护。
### 旋转编码器简介

•旋转编码器：用来测量位置、速度或旋转方向的装置，当其旋转轴旋转时，其输出端可以输出与旋转速度和方向对应的方波信号，读取方波信号的频率和相位信息即可得知旋转轴的速度和方向
•类型：机械触点式/霍尔传感器式/光栅式

对于STm32来说，想要获取的信号如果是外部驱动的变化很快的突发信号，比如说编码器、遥控器这些可能很久都不会使用，但是使用的时候又需要迅速响应。要处理这样的信号可以有两种实现方式：1.主程序循环读取引脚的高低电平2.定时器中断读取引脚的高低电平。很显然最好是使用中断的方式，但是按键不要用外部中断来实现，因为不好处理按键抖动和松手检测。

方波的个数代表转过的角度，方波的频率代表转速，因为只有一路输出，因此正转和反转没有办法区分。还有的是一个输出方波信号，一个输出高低电平代表方向。


机械触点式编码器，因为是机械触电，所以不适用于转速过高的场景。霍尔传感器的非接触形式的编码器可以用来测电机转速。  相位相差九十度的波形就是正交波形，输出正交波形编码器可以测方向。




### 硬件电路

<img src="images\image-20250321101830150.png" alt="image-20250321101830150" style="zoom:50%;" />

![image-20250321101834761](images\image-20250321101834761.png)
当触电断开时，P点上拉为VCC，输出到A为VCC导通时的P点，下拉至GND因此A点输出位GND。

![image-20250321101859318](images/image-20250321101859318.png)

对于旋转编码器，在中断函数中初始化PB0和PB1，两个GPIO的外部中断，当然只初始化一个外部中断也是可以的，完成功能的，因为对编码器而言，在上升沿和下降沿时刻可以检测随便一个引脚的高低电平。如果A相引脚触发中断，这样存在的小问题是，正转的情况A相刚开始转就会进入中断，反转A相迟滞，那么编码器已经转到位了，A相才进入中断。因此设计为双中断，只有在B相下降沿和A相低电平的的时候才判断为正转，只有在 A相下降沿和B相低电平时才判断为反转，这样就能保证正转和反转都是转到位了才执行计数变量加减的操作。

## TIM 定时器
### TIM定时器简介

•TIM（Timer）定时器。这是最基本的功能，定一个时间，然后定时器每隔这个时间产生一个中断，来实现每隔一个固定时间执行一段程序的目的。
•定时器可以对输入的时钟进行计数，并在计数值达到设定值时触发中断。当这个计数器的输入是一个准确可靠的基准时钟时，那么在对这个基准时钟计数的时候，实际上就是计时的过程。
•16位计数器、预分频器、自动重装寄存器的时基单元，在72MHz计数时钟下可以实现最大59.65s的定时。STm32的时钟频率是72MHz，如果计72个数，那么时间就是72/72M=1us，如果计72000个数就是72000/72M=1ms，也就是1kHz。
•不仅具备基本的定时中断功能，而且还包含内外时钟源选择、输入捕获、输出比较、编码器接口、主从触发模式等多种功能
•根据复杂度和应用场景分为了高级定时器、通用定时器、基本定时器三种类型


定时器的本质就是一个计数器。
定时器输出比较，常用于产生PWM波形，驱动电机等设备。定时器输入捕获功能，实现测量方波频率。定时器编码器接口，能更加方便地读取正交编码器的输出波形。

计数器：用来执行计数定时的一个寄存器，每来一个时钟，计数器加1。
预分频器：可以对计数器的时钟进行分频，让这个计数更加灵活。
自动重装寄存器：计数的目标值，就是我想计多少个时钟脉冲申请中断。

这三个构成了定时器最核心的部分，我们把这一块电路成为时基单元，时基单元中的寄存器都是16位的，2的16次方是65536，如果预分频器和自动重装寄存器都设置为最大，那定时器最大定时时间就是59.65s，计算方法是72M/65536/65536=1/59.65，得到定时中断的频率，然后取倒数就是最大的定时时间。如果觉得这个定时时间不够长的话，STm32的定时器还支持级联模式，也就是一个定时器的输出当做另一个定时器的输入，这样对打定时时间是59.65s×65536×65536 大概是八千多年，再级联一个的话，大概是34万亿年。
### 定时器类型







![image-20250321101933445](images/image-20250321101933445.png)

主从触发模式，它能让内部的硬件在不受程序的控制下实现自动运行，把这个掌握好就可以在某些情况下极大地减轻CPU负担。

![image-20250321102009783](images/image-20250321102009783.png)
没有基本定时器。不同的型号定时器的数量是不同的，在操作这个外设之前，一定要查看一下它是不是有这个外设操作到了不存在的外设，那样是不会运行的。资源一共是1个高级定时器，3个通用定时器。

初始化定时器的步骤
1.RCC开启时钟
打开时钟后，定时器的基准时钟和整个外设的工作时钟就都同时打开了。
2.选择时基单元的时钟源
对定时中断，我们选择的是内部时钟源。
3.配置时基单元
包括预分频器、自动重装器、计数模式等，这些参数用一个结构体就可以配置好。
4.配置输出中断控制
允许更新中断输出到NVIC。
5.配置NVIC
在NVIC中打开定时器中断的通道并分配一个优先级。
6.运行控制
整个模块配置完成后，我们还要使能一下计数器，要不然计数器是不会运行的，当定时器使能后，计数器就会开始计数了，当计数器更新时，触发中断。最后再写一个定时器中断函数，这样这个中断函数每隔一段时间就可以重新执行一次了。

TIM库函数
```C
// 恢复缺省配置
void TIM_DeInit(TIM_TypeDef* TIMx);
// 配置时基单元，TIMx选择定时器，结构体包含时基单元参数
void TIM_TimeBaseInit(TIM_TypeDef* TIMx, 
                      TIM_TimeBaseInitTypeDef* TIM_TimeBaseInitStruct);
// 这四个函数就是用来配置输出比较模块的，OC就是OutputCompare输出比较，因为输出比较有4路，所以刚好对应四个配置函数。TIMx选择定时器，TIM_TimeBaseInitStruct输出比较的参数，这个结构体的成员很多，有些是高级定时器才用到的。
// 这里有一个需要注意的问题就是，因为次使用到的是通用定时器而不是高级定时器，因此有一些变量是不用赋值的，因为此时的结构体是局部变量，没有赋初始值时，其值是不确定的，可能会导致问题。比如当想把高级定时器当做通用定时器用时，把TIM2改成TIM1，这样之前的结构体用不到的成员现在要用了，然而这些没有赋值，那就会导致高级定时器输出PWM有奇怪的问题，比如江科协本人遇到的就是将初始化函数在第一行正常，前面有其它的代码就会导致PWM无法正常输出，有3路无法正常输出。原因在于前面有代码的话，栈被用过有参留值使得TIM1配置错误，因此最好的方法就是先调用结构体初始化函数，给结构体一个初始值然后再局部修改值。
void TIM_OC1Init(TIM_TypeDef* TIMx, TIM_OCInitTypeDef* TIM_OCInitStruct);
void TIM_OC2Init(TIM_TypeDef* TIMx, TIM_OCInitTypeDef* TIM_OCInitStruct);
void TIM_OC3Init(TIM_TypeDef* TIMx, TIM_OCInitTypeDef* TIM_OCInitStruct);
void TIM_OC4Init(TIM_TypeDef* TIMx, TIM_OCInitTypeDef* TIM_OCInitStruct);
void TIM_ICInit(TIM_TypeDef* TIMx, TIM_ICInitTypeDef* TIM_ICInitStruct);
void TIM_PWMIConfig(TIM_TypeDef* TIMx, TIM_ICInitTypeDef* TIM_ICInitStruct);
void TIM_BDTRConfig(TIM_TypeDef* TIMx, TIM_BDTRInitTypeDef *TIM_BDTRInitStruct);
// 结构体初始化函数
void TIM_TimeBaseStructInit(TIM_TimeBaseInitTypeDef* TIM_TimeBaseInitStruct);
// 给输出结构体一个默认值
void TIM_OCStructInit(TIM_OCInitTypeDef* TIM_OCInitStruct);
void TIM_ICStructInit(TIM_ICInitTypeDef* TIM_ICInitStruct);
void TIM_BDTRStructInit(TIM_BDTRInitTypeDef* TIM_BDTRInitStruct);
// 对应的是运行控制，TIMx选择定时器，NewState选择使能还是失能
void TIM_Cmd(TIM_TypeDef* TIMx, FunctionalState NewState);
// 仅高级定时器使用，在使用高级定时器，输出PWM时需要调用这个函数使能主输出，否则PWM将不能正常输出
void TIM_CtrlPWMOutputs(TIM_TypeDef* TIMx, FunctionalState NewState);
// 使能中断输出信号，TIMx选择定时器，TIM_IT选择要配置哪个中断输出，NewState选择使能还是失能
void TIM_ITConfig(TIM_TypeDef* TIMx, uint16_t TIM_IT, FunctionalState NewState);
void TIM_GenerateEvent(TIM_TypeDef* TIMx, uint16_t TIM_EventSource);
void TIM_DMAConfig(TIM_TypeDef* TIMx, uint16_t TIM_DMABase, uint16_t TIM_DMABurstLength);
void TIM_DMACmd(TIM_TypeDef* TIMx, uint16_t TIM_DMASource, FunctionalState NewState);
// 选择内部时钟
void TIM_InternalClockConfig(TIM_TypeDef* TIMx);
// 选择ITRx其它定时器的时钟，TIMx选择定时器，TIM_InputTriggerSource选择要接入哪个其它的定时器
void TIM_ITRxExternalClockConfig(TIM_TypeDef* TIMx, uint16_t TIM_InputTriggerSource);
// 选择TIx捕获通道的时钟，TIM_TIxExternalCLKSource选择TIx具体的某个引脚，TIM_ICPolarity、ICFilter输入极性和滤波器。
void TIM_TIxExternalClockConfig(TIM_TypeDef* TIMx, uint16_t TIM_TIxExternalCLKSource,uint16_t TIM_ICPolarity, uint16_t ICFilter);
// 选择ETR通过外部时钟模式1输入的时钟，TIM_ExtTRGPrescaler外部触发预分频器，这里可以对ETR外部时钟提前做一个分频。
void TIM_ETRClockMode1Config(TIM_TypeDef* TIMx, uint16_t TIM_ExtTRGPrescaler, 
                             uint16_t TIM_ExtTRGPolarity,uint16_t ExtTRGFilter);
// 选择ETR通过外部时钟模式2输入的时钟，对于ETR输入的外部时钟，9、10两个函数是等效的，如果不需要触发输入的功能，那两个函数可以互换。
void TIM_ETRClockMode2Config(TIM_TypeDef* TIMx, uint16_t TIM_ExtTRGPrescaler, 
                             uint16_t TIM_ExtTRGPolarity, uint16_t ExtTRGFilter);
// 这个不是用来选择时钟的，就是单独用来配置ETR引脚的预分频器，极性滤波器参数。
void TIM_ETRConfig(TIM_TypeDef* TIMx, uint16_t TIM_ExtTRGPrescaler, 
                   uint16_t TIM_ExtTRGPolarity,uint16_t ExtTRGFilter);
// 单独写预分频值，TIM_PSCReloadMode等更新事件还是立即生效
// 单独写入PSCD额函数，因为还有一个TIM_PSCReloadMode重装模式的参数，所以并不叫SetPrecaler而叫PrescalerConfig，update在更新事件重装，immediate立即重装。立刻生效可能会在值被改变的瞬间产生切断波形的情况。
void TIM_PrescalerConfig(TIM_TypeDef* TIMx, uint16_t Prescaler, 
                         uint16_t TIM_PSCReloadMode);
// 计数器模式
void TIM_CounterModeConfig(TIM_TypeDef* TIMx, uint16_t TIM_CounterMode);
void TIM_SelectInputTrigger(TIM_TypeDef* TIMx, uint16_t TIM_InputTriggerSource);
void TIM_EncoderInterfaceConfig(TIM_TypeDef* TIMx, uint16_t TIM_EncoderMode,
                                uint16_t TIM_IC1Polarity, uint16_t TIM_IC2Polarity);
// 这4个函数是用来配置强输出模式的，如果在运行中想要暂停输出波形，并且强制输出高电平或低电平，可以用这个函数但用的不多，因为强制输出高电平和设置100%占空比一样，强制输出低电平和设置0%占空比也是一样的。
void TIM_ForcedOC1Config(TIM_TypeDef* TIMx, uint16_t TIM_ForcedAction);
void TIM_ForcedOC2Config(TIM_TypeDef* TIMx, uint16_t TIM_ForcedAction);
void TIM_ForcedOC3Config(TIM_TypeDef* TIMx, uint16_t TIM_ForcedAction);
void TIM_ForcedOC4Config(TIM_TypeDef* TIMx, uint16_t TIM_ForcedAction);
// 自动重装器功能配置
void TIM_ARRPreloadConfig(TIM_TypeDef* TIMx, FunctionalState NewState);
void TIM_SelectCOM(TIM_TypeDef* TIMx, FunctionalState NewState);
void TIM_SelectCCDMA(TIM_TypeDef* TIMx, FunctionalState NewState);
// 这4个函数是用来配置CCR寄存器的预装功能的，这个预装功能就是影子寄存器，就是写入的值不会立即生效，而是在更新事件后才会生效。
void TIM_CCPreloadControl(TIM_TypeDef* TIMx, FunctionalState NewState);
void TIM_OC1PreloadConfig(TIM_TypeDef* TIMx, uint16_t TIM_OCPreload);
void TIM_OC2PreloadConfig(TIM_TypeDef* TIMx, uint16_t TIM_OCPreload);
void TIM_OC3PreloadConfig(TIM_TypeDef* TIMx, uint16_t TIM_OCPreload);
void TIM_OC4PreloadConfig(TIM_TypeDef* TIMx, uint16_t TIM_OCPreload);
// 这4个函数是用来配置快速使能的，这个功能在手册中，单脉冲模式有介绍。
void TIM_OC1FastConfig(TIM_TypeDef* TIMx, uint16_t TIM_OCFast);
void TIM_OC2FastConfig(TIM_TypeDef* TIMx, uint16_t TIM_OCFast);
void TIM_OC3FastConfig(TIM_TypeDef* TIMx, uint16_t TIM_OCFast);
void TIM_OC4FastConfig(TIM_TypeDef* TIMx, uint16_t TIM_OCFast);
// 这个功能在手册里，外部事件时清除REF信号
void TIM_ClearOC1Ref(TIM_TypeDef* TIMx, uint16_t TIM_OCClear);
void TIM_ClearOC2Ref(TIM_TypeDef* TIMx, uint16_t TIM_OCClear);
void TIM_ClearOC3Ref(TIM_TypeDef* TIMx, uint16_t TIM_OCClear);
void TIM_ClearOC4Ref(TIM_TypeDef* TIMx, uint16_t TIM_OCClear);
// 这些用来单独设置输出比较的极性，带N的就是高级定时器里的互补通道的配置
void TIM_OC1PolarityConfig(TIM_TypeDef* TIMx, uint16_t TIM_OCPolarity);
void TIM_OC1NPolarityConfig(TIM_TypeDef* TIMx, uint16_t TIM_OCNPolarity);
void TIM_OC2PolarityConfig(TIM_TypeDef* TIMx, uint16_t TIM_OCPolarity);
void TIM_OC2NPolarityConfig(TIM_TypeDef* TIMx, uint16_t TIM_OCNPolarity);
void TIM_OC3PolarityConfig(TIM_TypeDef* TIMx, uint16_t TIM_OCPolarity);
void TIM_OC3NPolarityConfig(TIM_TypeDef* TIMx, uint16_t TIM_OCNPolarity);
// OC4没有互补通道，所以就没有OC4N的函数
// 在函数这里可以设置极性，在结构体函数初始化的地方也可以设置极性，这两个地方设置极性的作用是一样的，只不过用结构体是一体初始化的，在这里是一个单独的函数进行修改的，一般来说，结构体里的参数都会有一个单独的函数进行修改。
void TIM_OC4PolarityConfig(TIM_TypeDef* TIMx, uint16_t TIM_OCPolarity);
// 用来单独修改输出使能参数的
void TIM_CCxCmd(TIM_TypeDef* TIMx, uint16_t TIM_Channel, uint16_t TIM_CCx);
void TIM_CCxNCmd(TIM_TypeDef* TIMx, uint16_t TIM_Channel, uint16_t TIM_CCxN);
// 选择输出比较模式，用来单独更改输出比较模式的函数
void TIM_SelectOCxM(TIM_TypeDef* TIMx, uint16_t TIM_Channel, uint16_t TIM_OCMode);
void TIM_UpdateDisableConfig(TIM_TypeDef* TIMx, FunctionalState NewState);
void TIM_UpdateRequestConfig(TIM_TypeDef* TIMx, uint16_t TIM_UpdateSource);
void TIM_SelectHallSensor(TIM_TypeDef* TIMx, FunctionalState NewState);
void TIM_SelectOnePulseMode(TIM_TypeDef* TIMx, uint16_t TIM_OPMode);
void TIM_SelectOutputTrigger(TIM_TypeDef* TIMx, uint16_t TIM_TRGOSource);
void TIM_SelectSlaveMode(TIM_TypeDef* TIMx, uint16_t TIM_SlaveMode);
void TIM_SelectMasterSlaveMode(TIM_TypeDef* TIMx, uint16_t TIM_MasterSlaveMode);
// 给计数器写入一个值，如果想手动给一个计数值，就用这个函数。
void TIM_SetCounter(TIM_TypeDef* TIMx, uint16_t Counter);
// 给自动重装器写入一个值，如果想手动给自动重装值就用这个。
void TIM_SetAutoreload(TIM_TypeDef* TIMx, uint16_t Autoreload);
// 这4个函数是用来单独设置CCR寄存器值的函数，在运行的时候更改占空比，就用到这四个函数
void TIM_SetCompare1(TIM_TypeDef* TIMx, uint16_t Compare1);
void TIM_SetCompare2(TIM_TypeDef* TIMx, uint16_t Compare2);
void TIM_SetCompare3(TIM_TypeDef* TIMx, uint16_t Compare3);
void TIM_SetCompare4(TIM_TypeDef* TIMx, uint16_t Compare4);
void TIM_SetIC1Prescaler(TIM_TypeDef* TIMx, uint16_t TIM_ICPSC);
void TIM_SetIC2Prescaler(TIM_TypeDef* TIMx, uint16_t TIM_ICPSC);
void TIM_SetIC3Prescaler(TIM_TypeDef* TIMx, uint16_t TIM_ICPSC);
void TIM_SetIC4Prescaler(TIM_TypeDef* TIMx, uint16_t TIM_ICPSC);
void TIM_SetClockDivision(TIM_TypeDef* TIMx, uint16_t TIM_CKD);
uint16_t TIM_GetCapture1(TIM_TypeDef* TIMx);
uint16_t TIM_GetCapture2(TIM_TypeDef* TIMx);
uint16_t TIM_GetCapture3(TIM_TypeDef* TIMx);
uint16_t TIM_GetCapture4(TIM_TypeDef* TIMx);
// 获取当前计数器的值，如果想看当前计数器计到哪里了，就可以调用一下这个函数。
uint16_t TIM_GetCounter(TIM_TypeDef* TIMx);
// 获取当前预分频的值
uint16_t TIM_GetPrescaler(TIM_TypeDef* TIMx);
FlagStatus TIM_GetFlagStatus(TIM_TypeDef* TIMx, uint16_t TIM_FLAG);
void TIM_ClearFlag(TIM_TypeDef* TIMx, uint16_t TIM_FLAG);
ITStatus TIM_GetITStatus(TIM_TypeDef* TIMx, uint16_t TIM_IT);
void TIM_ClearITPendingBit(TIM_TypeDef* TIMx, uint16_t TIM_IT);

```
```C
// 结构体成员
TIM_OCMode
	TIM_OCMode_Timing         // 冻结模式      
    TIM_OCMode_Active         // 相等时置有效电平        
    TIM_OCMode_Inactive       // 相等时置无效电平       
    TIM_OCMode_Toggle         // 相等时电平翻转        
    TIM_OCMode_PWM1           // PWM模式1        
    TIM_OCMode_PWM2           // PWM模式2     
// 下面还有
    TIM_ForcedAction_Active  // 强制输出的两种，这两个参数无法在初始化的时候使用
    TIM_ForcedAction_InActive
TIM_OCPolarity
	High高极性，就是极性不翻转，REF波形直接输出，或者说是有效电平是高电平，REF有效时输出高电平，这两个都是一个意思。
	Low低极性，就是REF电平取反，或者说有效电平为低电平
TIM_OutputState
	Disable 失能
	Enable 使能
TIM_Pulse
	在0x0000和0xFFFF之间就是CCR的值
```

程序设计的具体步骤
1.启动时钟
2.选择时基单元的时钟，上电后默认就是内部时钟，其实不写也行。
3.配置时基单元
结构体成员Clockvision 指定时钟分频
CounterMode计数器模式Period周期ARR自动重装器的值Prescaler预分频器的值RepetionCounter重复计数器的值，这个需要高级定时器才能用到。需要注意的是都在0-65535时间范围之内，不要超过范围。并没有CNT的参数，如果需要的话可以使用SetCounter和GetCounter操作。

在定时器的外部信号输入引脚一般都会有滤波器，它可以绿掉信号的抖动干扰，具体工作方式就是在一个固定的时钟频率下采样，如果连续N个采样点都为相同的电平，那就代表输入信号稳定了，就把这个采样值输出出去，如果N个采样值不全都相同，那就说明信号有抖动，这时就保持上一次的输出，或直接输出低电平也行，这样就能保证输出信号在一定程度上的滤波，这里采样频率f和采样点数N都是滤波器的参数，频率越低采样点越多，那滤波效果就越好，不过相应信号延迟就越大，这个采样频率f可直接由内部时钟直接而来也可由内部时钟加一个时钟分频而来，具体分频多少就是ClockDivison决定。这个参数和时基单元关系不大，随便配置一个即可。

定时一秒钟例子：
PSC给7200，ARR给10000，然后两个参数都再减1，因为预分频器和计数器都有1个数的偏差，所以要再减一个1，注意PSC和ARR的取值都在0-65535之间，不要超过范围，并且PSC和ARR的取值并不唯一，可以预分频器给少一点，自动重装器给多一点，这样就是以比较多的频率计比较多的数，也可以预分频给多点，自动重装给少点，这样就是以比较低的频率计比较少的数，两种方法都可以达到目标定时时间。

4.使能更新中断，就是开启更新中断到NVIC的通路。
extern就是告诉编译器，我现在由Num这个变量，但是它在别的文件定义了，以至于在哪里就你自己去找吧。
对于定时中断而言，中断函数就可以放在使用它的地方。
代码在一开始时复位直接从1开始，意味着代码在一开始时就进入了一次中断，具体原因是因为TimeBaseInit函数中手动产生了一个更新事件用来重新装载值，这样预分频器的值就有效了，但副作用是更新事件和更新中断是同时发生的，更新中断会置更新中断标志位，之后一旦初始化完了，更新中断就会立刻进入，这就是刚一上电就立刻进入中断的原因。解决方法就是在TimeBaseInit后开启中断前手动调用TIM_ClearFlag。
浮空输入一旦悬空，电平就会跳个没完，上拉输入即可，如果外部输入信号功率很小，内部上拉电阻可能会影响到这个输入信号，这时可用浮空输入方式影响外部输入电平信号。

TIM2和GPIO的对应关系
引脚定义表的默认复用功能就是片上外设的端口和GPIO的连接关系
PA0有TIM2_CH1_ETR
也就是说TIM2的CH1和ETR都是共用了GPIOA的Pin0引脚，也就是TIM2的引脚复用在了PA0引脚上，如果使用TIM2的OC1也就是CH1通道输出PWM波，那它就只能在PA0输出。引脚的对应关系是定死的，不能随意更改，不过虽然是定死的，STm32还是给了一次更改的机会，这就是重定义或重映射。比如既要用USART2的Tx引脚，又要用TIM2的CH3通道，那就可以在重映射引脚中找TIM2，CH3的重映射引脚来避免引脚冲突，如果重映射列表找不到，那外设复用的GPIO就不能挪位置，这就是重映射的功能，配置重映射是用AFIO来完成的。
此时的GPIO模式选择的是复用推挽输出，GPIO_Mode_AF_PP，对于普通的开漏/推挽输出，引脚的控制权来自于输出数据寄存器的，那如果想让定时器来控制引脚，那就需要使用复用开漏/推挽输出模式在这里输出数据寄存器将被断开，输出控制权将转移给片上外设，此处的片上外设连接的即是TIM2的CH1通道。所以只有把引脚设置为复用推挽输出，引脚的控制权才能交给片上外设，PWM波形才能通过引脚输出。

复用引脚的步骤
1.开启AFIO时钟，AFIO是APB2的设备
2.GPIO_PinRemapConfig，引脚重映射配置，GPIO PA15 上电后默认是调试端口，要想重映射还需要关闭调试的功能，解除的具体方法也是使用GPIO_PinRemapConfig函数，但需要注意的是其余的端口还是调试端口
函数的参数是：
```C
// SWJ就是SWD-JTAG两种调试方式
// 解除JTRS引脚复用，也就是PB4变为正常GPIO
GPIO_Remap_SWJ_NoJTRST
// 解除JTAG调试端口的复用，也就是PA15，PB3，PB4这三个端口变成普通的GPIO，上面的PA13和PA14仍为SWD端口。
GPIO_Remap_SWJ_JTAGDisable
// 解除JTAG-SWD调试端口的所有引脚，也就是PA13，PA14，PA15，PB3，PB4全部都变成了普通端口，但是需要特别注意的是，一旦调用参数下载程序后调试端口就没有了，ST-Link就下载不进去程序了，这时候就只能用串口下载一个新的没有解除调试端口的程序，这样才能把调试端口弄回来
GPIO_Remap_SWJ_Disable 
```
如果想重映射定时器或者其他外设的引脚，就开启AFIO的时钟，并用AFIO重映射外设复用的引脚，如果重映射的引脚正好是调试端口，就还需要加上GPIO解除调试端口
1.打开AFIO时钟
2.重映射GPIO端口
3.解除调试端口
```C
void GPIO_PinRemapConfig(uint32_t GPIO_Remap, FunctionalState NewState);
void GPIO_EXTILineConfig(uint8_t GPIO_PortSource, 
uint8_t GPIO_PinSource);
void GPIO_ETH_MediaInterfaceConfig(uint32_t GPIO_ETH_MediaInterface);
```
### 高级定时器

![image-20250321102018983](images/image-20250321102018983.png)
输入滤波和边沿检测电路就会检测到上升沿让输入捕获电路产生动作。

刹车输入功能，这个是为了给电机驱动提供安全保障的，如果外部引脚BKIN(Break In)产生了刹车信号，或者内部时钟失效，产生了故障那么控制电路就会自动切断电机的输出防止意外发生。CSS监测到时钟失效就会通过或门，将信号反映到输出比较，让输出控制的电机立刻停止。

和通用定时器不一样的地方：
1.在申请中断的地方增加了一个重复次数计数器，有了之后就可以实现每隔几个计数周期才发生一次更新和更新中断，原来的结构是每隔计数周期完成后就都会发生更新，相当于对输出的更新信号又做了一次分频，对于高级定时器，我们之前的最大定时时间59秒多这里就还需要×65536，提升了定时时间。
2.DTG(Dead Time Generate)死区生成电路
输出电路由一个变成了两个互补的输出，可以输出一对互补的PWM波，这些电路是为了驱动三相无刷电机的，四周飞行器、电动车后轮、电钻等都有可能是这个三项无刷电机，因为三相无刷电机驱动电路一般需要三个桥臂，每个桥臂要用2个大功率开关管来控制，总共要6个大功率开关管来控制，所以输出PWM引脚的前三路就变成了互补输出，而第四路却没有什么变化，因为三相电机只需要三路就够了，为了防止互补输出的PWM驱动桥臂时由于器件的不理想，在切换开关的瞬间造成短路的直通现象，所以就在前面加上了死区生成电路，在开关切换的瞬间，产生一定时长的死区，让桥臂的上下管关断，防止直通现象。
### **通用定时器**

![image-20250321102025989](images/image-20250321102025989.png)
4个通道，对应的也是CH1到CH4引脚，可以用于测输入方波的频率。带阴影的都是有影子寄存器的。定时器主输出模式，把内部事件映射至TRGO引脚，用于触发其它定时器DAC、ADC。定时器的编码器接口可以读取正交编码器输出波形，并且影子寄存器用或者不用是可以自己设置的。输出比较电路，一共有四个通道，分别对应CH1到CH4的引脚，可以用于输出PWM波形，驱动电机。
对于基本定时器而言，只能选择内部时钟，也就是系统频率72MHz，对于通用定时器，时钟源不仅可以选择内部的72Mhz时钟，还可以选择外部时钟，第一个外部时钟就是来自TIMx_ETR引脚上的外部时钟，ETR(External)引脚的位置，参考引脚定义表。因此就可以在TIM2的ETR引脚，也就是PA0上接一个外部方波时钟，然后配置一个内部的极性选择、边沿选择和预分频电路，再配置一下输入滤波电路，这两块电路可以对外部始终进行一定的整形，因为是外部电路时钟，因此难免会有一些毛刺，最后滤波后的信号兵分两路，上面一路ETRF进入触发控制器，紧接着就可以选择作为时基单元的时钟了。如果想在ETR外部引脚提供时钟或者想对ETR时钟进行计数，把定时器当作计数器来用的话，就可以配置这一路电路，在STm32中这一路叫做外部时钟模式2。
除了外部ETR引脚可以提供时钟外，下面还有一路可以提供时钟，就是TRGI(Trigger In)这路主要用作触发输入来使用的，它可以出发定时器的从模式，当TRGI当作外部时钟来使用的时候，这一路叫做外部时钟模式1。通过这一路的外部时钟有1.ETR引脚信号，ETR引脚既可以通过上面一路进来，也可以通过下面的一路来当作时钟，两种情况对于时钟输入而言是等价的，只是通过TRGI会占用触发输入的通道。2.ITR信号，这一部分的时钟信号是来自其它定时器的，从图上可以看出，通向其它定时器的时候，就接到了其它定时器的ITR引脚上来了，ITR0-ITR3分别来自其它4个定时器的TRGO输出，具体连接方式看手册，这就是定时器级联。比如初始化TIM3主模式把更新事件映射到TRGO上，再初始化TIM2选择ITR2对应的TIM3的TRGO，后面再选择时钟模式为外部时钟模式1，这样TIM3的更新事件就可驱动TIM2的时基单元，实现了定时器的级联。
对于通用定时器而言，计数器的计数模式不只向上计数这一种，还支持向下计数模式和中央对齐模式，向下计数模式就是从重装值开始向下自减，减到0之后回到重装值同时申请中断，中央对齐模式，从0开始，先向上自增计到重装值申请中断，然后再向下自减到0，再申请中断。
还可以通过TIF_ED，它连接的是输入捕获单元的CH1引脚，也就是从CH1引脚获得时钟，这里后缀加一个ED(Edge)就是边沿的意思，也就是从这一路输入的时钟，上升沿和下降沿都有效。最后，这个时钟还能通过TI1FP1和TI2FP2获得，其中TI1FP1连接到了CH1引脚时钟，TI2Fp2连接到CH2引脚的时钟。总结：外部时钟模式1的输入可以是ETR引脚，其它定时器，CH1引脚边沿，CH1引脚，CH2引脚。一般情况下外部时钟通过ETR引脚即可，下面设置这么复杂不仅仅是为了扩大时钟输入的范围，更多还是为了某些特殊场景设计的。

三输入异或门的输入接在了通道1、2、3端口，异或门的执行逻辑是当三个输入引脚的任何一个有电平翻转时，输出引脚就产生一次电平翻转。之后输出通过数据选择器，到达输入捕获通道1，数据选择器如果选择上面的一个那输入捕获通道1的输入就是3个引脚的异或值，如果选择下面一个那异或门就没有用，4个通道各用各的引脚。设计这个异或门，其实还是为了三相无刷电机服务的，无刷电机有三个霍尔传感器，检测转子的位置，可以根据转子的位置进行换相，有了这个异或门就可以在前三个通道上接上无刷电机的霍尔传感器，然后定时器就作为无刷电机的接口定时器去驱动换相电路工作。


中间的寄存器是输入捕获和输出比较电路共用的，因为输入捕获和输出比较不能同时使用，所以这里的寄存器是共用的，引脚也是共用的。当使用输入捕获时，它就是捕获寄存器，当使用输出比较时它就是比较寄存器，这块电路会比较CNT和CCR的值，CNT计数自增，CCR使我们给定的一个值，当CNT大于CCR、小于CCR、或者等于CCR时，这里输出就会对应的置1置0置1置0，这样就可以输出一个电平不断跳变的PWM波形了。

输入滤波器可以对输入信号进行滤波，避免一些高频的毛刺信号误触发边沿检测，这就和外部中断那里是一样的，可以选择高电平触发或者低电平触发，当出现指定的电平时，边沿检测电路就会触发后续电路执行动作，另外这里是设计了两套滤波和边沿检测电路，第一套电路经过滤波和极性选择得到。TI1FP1(TI1 Filter Polarity1)输入给通道1的后续电路，第二套电路，经过过另一个滤波和极性选择电路得到TI1FP2(TI1 Filter Polarity2)输入给通道2的后续电路。同理TI2信号进来也经过两套滤波和极性选择，得到TI2FP1和TI2FP2，其中的TI2FP1输出给上面，TI2FP2输出给下面。在这里两个信号进来可以选择各走各的，也可以选择进行一个交叉，让CH2引脚输入给通道1，或者CH1引脚输入给通道2。这里进行交叉连接的目的，江科大认为：1.可以灵活切换后续捕获电路的输入，2.可以把一个引脚的输入同时映射到两个捕获单元，第一个捕获通道，使用上升沿触发，用来捕获周期，第二个捕获通道，使用下降沿触发，用来捕获占空比。两个通道同时对一个引脚进行捕获，就可以同时测量频率和占空比，这就是PWMI模式。另外这里的TRC信号也可以选择作为捕获部分的输入，这样设计也是为了无刷电机的驱动。
经过输入滤波器和边沿检测电路之后就到了预分频器，在预分频器可以对信号进行分频，分频之后的触发信号就可以触发捕获电路进行工作了，每来一个触发信号，CNT的值就会向CCR转运一次，转运一次会发生一个捕获事件，这个时间会在状态寄存器置标志位，同时也可以产生中断，如果需要捕获的瞬间处理一些中断额话就可以开启这个捕获中断。比如可以置上升沿触发捕获，每来一个上升沿CNT转运到CCR一次，又因为CNT计数器是由内部标准时钟驱动的，所以CNT的数值其实就可以用来记录两个上升沿之间的时间间隔，这个时间间隔就是周期再取个倒数，就是测周法测量的频率大小。
### 基本定时器

![image-20250321102032481](images/image-20250321102032481.png)
基本定时器只能选择内部时钟，可以直接认为接的就是内部时钟CK_INT，CK_INT的来源是RCC，TIMxCLK，频率值一般都是72MHz。

预分频器之前连接的就是基准计数时钟的输入，预分频器写0就是不分频，写1就是2分频，写2就是3分频，以此类推，实际分频系数=预分频器+1。预分频器是16位的，最大值可以写65535也就是65536分频，预分频器就是对输入的基准频率进行一个分频的操作。
计数器对预分频后的计数时钟进行计数，计数时钟每来一个上升沿的值就加1，因为计数器是16位的，所以可以从0加到65535，如果再加的话，计数器就会从0重新开始。计数器的值在计时过程中会不断自增运行到目标值时，产生中断，那就完成了定时任务。
自动重装寄存器也是16位的，它存在就是我们写入的目标值，在运行过程中，计数值不断自增，自动重装是固定的目标，当计数值等于自动重装值时，也就是计时时间到了，此时就会产生信号并且清零计数器，计数器自动开始下一次计数计时。
这里图上画的向上的折线箭头，表示这里会产生中断信号，像这种计数值等于自动重装值产生的中断，我们一般把它叫做“更新中断”，这个更新中断之后就会通往NVIC，我们再配置好NVIC的定时器通道，那定时器的更新中断就能得到CPU的响应了。向下的箭头代表的是会产生一个事件，这里对应的事件就叫做更新事件，更新事件不会触发中断，但可以触发内部其它电路工作。


主模式触发DAC用途：在使用DAC的时候，可能用DAC输出一段波形，那就需要每隔一段时间来触发一次DAC，让它输出下一个电压点，如果用正常的思路来实现的话，就是先设置一个定时器产生中断，每隔一段时间中断程序中调用代码手动触发一次DAC转换，然后DAC输出，这样没问题但会使主程序频繁处于被中断的状态，会影响主程序运行和其它中断的响应。使用主模式可以把定时器更新事件映射到触发输出TRGO(Trigger Out)的位置，然后TRGO直接接到DAC的触发转换引脚上 ，这样就不用通过中断来出发转换了。整个过程不需要软件的参与，实现了硬件的自动化，这就是主模式的作用。
### 定时中断基本结构

![image-20250321102049381](images/image-20250321102049381.png)
定时中断，时钟源选择。为时基单元提供时钟的部分
ARR(AutoReloadRegister)
PSC(Prescaler)
CNT(Counter)
计时时间到，产生更新中断后的信号去向。
如果是高级定时器的话，还会多一个重复计数器。

控制寄存器的一些位比如启动停止，向上或向下计数等等，操作这些寄存器就能控制时基单元的运行了。中断信号先在状态寄存器里置一个中断标志位，这个标志位会通过中断输出控制，到NVIC申请中断，之所以需要中断控制，是因为更新触发信号，输入捕获，输出比较，匹配时也会申请中断，所以这些中断都要经过中断输出控制，如果需要这个中断就允许，如果不需要就禁止，中断输出控制就是中断输出的允许位。
### 预分频器时序

![image-20250321102057008](images/image-20250321102057008.png)
开始时，计数器未使能计数器时钟不运行，使能后前半段预分频器系数为1，计数器的时钟等于预分频器前的时钟，后半段预分频器的系数变为2了，计数器的时钟也变为了预分频前时钟的一半了。在计数器时钟的驱动下，下面的计数器寄存器也随着时钟的上升沿不断自增，在中间的这个位置FC之后，计数器变为0了可以推断出ARR自动重装值就是FC，当计数值计数到和重装值相等，并且下一个时钟来临时计数值才清零，同时下面产生一个更新事件。
预分频寄存器的一种缓冲机制，预分频寄存器实际上有两个，一个是预分频寄存器，供我们读写，它并不直接决定分频系数，预分频缓冲寄存器或者说影子寄存器，缓冲寄存器和影子寄存器实际上就是一种说法。因此缓冲寄存器才是真正起作用的寄存器，比如说在某个时刻，把预分频寄存器从0改到1，如果在此时立刻改变时钟的分频系数，那么就会导致在一个计数周期内，前半部分和后半部分的频率不一样，这虽然并不会有什么问题但是STm32的定时器比较严谨，设计了缓冲寄存器，当我们在计数一半的时候改变了分频值，这个变化并不会立刻生效，而是会等到本次计数周期结束时，产生了更新事件预分频器寄存器的值才会被传递到缓冲寄存器里面去才会生效，所以即使在计数中途改变了预分频的值，计数频率仍然会保持为原来的频率，直到本轮计数完成，在下一轮计数时，改变后的分频值才会起作用。
预分频器内部也是靠计数来分频的，当预分频器为0时，计数器就一直为0直接输出原频率，当预分频器为1时，计数器就0,1,0,1这样计数，再回到0的时候，输出一个脉冲，这样输出频率就是输入频率的二分频，预分频器的值和实际的分频器之间有一个数的偏移。

CK_PSC预分频器输入时钟，选内部时钟的话就是72MHz
CNT_EN计数器使能，高电平计数器正常工作，低电平计数器停止
CK_CNT计数器时钟，既是预分频器的时钟输出，也是计数器的时钟输入
### 计数器时序

![image-20250321102103665](images/image-20250321102103665.png)
CK_INT内部时钟72MHz
CNT_EN时钟使能，高电平启动
CK_CNT分频系数为2，所以频率为内部时钟除以2，计数器时钟每隔上升沿自增，增加到0036溢出。
当增加到0036时，发生溢出，计到36之后，再来一个上升沿，计数器清零，计数器溢出产生一个更新事件脉冲，另外还会置一个更新中断标志位UIF，这个标志位只要置1了就会去申请中断，中断响应后，需要在中断程序中手动清零，这就是计数器工作流程。

•计数器溢出频率：
	CK_CNT_OV = CK_CNT / (ARR + 1) = CK_PSC / (PSC + 1) / (ARR + 1)
72MHz/(PSC + 1)/(ARR + 1)就能得到溢出频率，如果想算溢出时间，那就再取个倒数就可以了。
### 计数器无预装时序
就是没有缓冲寄存器的情况
![image-20250321102109931](images/image-20250321102109931.png)
计数器正在进行自增时修改自动加载寄存器，也就是自动重装寄存器，由FF改成了36，那计数的目标值就由FF改成了36，所以这里计到36以后就直接更新进入下一轮计数。
### 计数器有预装时序
就是有缓冲寄存器的情况，通过设置ARPE位就可以选择是否开启。
![image-20250321102116630](images/image-20250321102116630.png)
在这个例子也可以看出，如果在这里不使用影子寄存器的话，F5改到36立刻生效，但此时计数值已经到了F1，超过了36，F1只能增加，但它的目标值却是36，比它还小，这样F1就只能一直加，一直加到FFFF再回到0，再加到36，才能产生更新，这样就会造成一些小问题，但是如果不介意这些问题的话就不用管这些细节了。在计数的中途，我突然把计数目标由F5改成了36，可以看到下面有影子寄存器，这个影子寄存器才是真正起作用的，它还是F5，所以现在计数器的目标值还是计到F5，产生更新事件同时被更改的36才被传递到影子寄存器，在下一个计数周期这个更改的36才有效。所以可以看出，引入影子寄存器的目的实际上是为了同步，就是让值变化和更新事件同步发生，防止在运行途中更改造成错误。
### RCC时钟树
	时钟是所有外设运行的基础，也是最先需要配置的东西，程序中主函数之前还会执行SystemInit函数，它就是用来配置这个时钟树的。这个时钟树就是STm32中用来产生和配置时钟，并且把配置好的时钟信号送到各个外设的系统。这个从这个图中的AHB预分频寄存器可以将RCC时钟树分为左右两个部分，左边就是时钟产生电路，右边就是时钟分配电路。在SystemInit中，STm32会先启动内部时钟，选择内部8MHz为系统时钟，暂时以内部8MHz的时钟运行，然后再启动外部时钟，配置外部时钟进入PLL锁相环进行倍频，8M×9=72MHz，等锁相环稳定输出后，选择锁相环输出为系统时钟，这样就把8MHz切换为了72MHz。这种运行方式可能会出现的问题是，当外部晶振出现问题之后，可能会导致程序的时钟慢了大概十倍，比如定了一个1s中断，结果10s后才进入中断，问题就在于外部晶振出现问题，无法切换到72MHz，就会以内部的8MHz运行。
	在时钟产生电路中，有4个震荡源。1.HSI-RC内部8MHz告诉RC振荡器。2.HSE-OSC外部4-16MHz告诉石英晶体振荡器。3.LSE-OSC外部32.768kHz低速晶振，一般是给RTC提供时钟的。4.LSI-RC内部40kHz低速RC振荡器，可以给看门狗单独提供时钟。CSS(ClockSecuritySystem)时钟安全控制系统，可以监测外部时钟的运行状态，一旦外部时钟失效，自动把外部时钟切换为内部时钟，保证系统时钟运行，防止系统卡死造成事故。
	上面这两个高速晶振是用来提供系统时钟的，AHB，APB2，APB1的时钟都是来源于这两个高速晶振，内部和外部都有8MHz晶振，这两个都是可以用的，但外部的石英振荡器比内部的RC振荡器更加稳定，因此一般都用外部晶振，如果系统很简单而且不需要那么精确的时钟，那也是可以使用内部RC振荡器的，这样就可以省下外部晶振的电路了。
![image-20250321102122636](images/image-20250321102122636.png)
	首先系统时钟进入AHB总线，AHB总线有个预分频器，在SystemInit里配置的分配系数为1，那AHB始终就是72MHz，然后进入APB1总线，这里配置的分频系数是2，所以APB1总线的时钟是72MHz/2 = 36MHz。
	之前说通用定时器和基本定时器都是接在APB1上的，而APB1上的时钟是36MHz，按理说它们的时钟应该是36MHz，但之前在说定时器时都是说所有定时器的时钟都是72MHz，原因在于，APB1预分频器系数等于1，则频率不变，否则×2，这路是单独为定时器2-7开通的。结论：无论是高级定时器、通用定时器、还是基本定时器，它们的内部基准时钟都是72MHz。
	其中外设时钟使能就是程序中写RCC_APB2/ PeriphClockCmd作用的地方。


### 输出比较简介
CC：Capture Compare
IC：Input Capture
CCR：Capture/Compare Register
OC（Output Compare）输出比较
输出比较可以通过比较CNT与CCR寄存器值的关系，来对输出电平进行置1、置0或翻转的操作，用于输出一定频率和占空比的PWM波形。CNT就是时基单元里的计数器，CCR就是捕获/比较寄存器。
每个高级定时器和通用定时器都拥有4个输出比较通道
高级定时器的前3个通道额外拥有死区生成和互补输出的功能

### PWM简介
PWM的本质是用PWM波形来等效实现一个模拟信号的输出
PWM（Pulse Width Modulation）脉冲宽度调制
在具有惯性的系统中，可以通过对一系列脉冲的宽度进行调制，来等效地获得所需要的模拟参量，常应用于电机控速等领域
PWM参数：
频率 = 1 / TS            占空比 = TON / TS           分辨率 = 占空比变化步距
TON 高电平时间 TS周期时间
需要注意的是，PWM必须应用在惯性系统，LED在熄灭时，由于余晖和人眼视觉停留现象，LED不会立马熄灭，而是有一定的惯性过渡时间再熄灭，电机也是，当电机断电时，并不会立刻停下来，而是有一定惯性，过会儿才停止。
![image-20250324165715764](images/image-20250324165715764.png)
高低电平跳变的数字信号可以等效为中间这个虚线所表示的模拟量的，ON的多，等效信号上移，OFF的多，等效信号下移。
PWM频率越快，等效模拟的信号就越平稳，不过同时性能开销就会越大，一般来说频率都在几千-几十千Hz，这个频率已经足够快了。占空比决定了等效出来的模拟电压的大小，占空比越大，模拟电压越趋近高电平，反之越趋近低电平，其对应关系是线性的。
数字输出端口控制LED，按理说LED只能有完全亮和完全灭两种状态，通过PWM波不断让LED点亮熄灭点亮熄灭，当这个点亮熄灭的频率足够大时，LED就不会闪烁了，而是呈现一个中等亮度，当我们调控点亮熄灭的比例时，就能让LED呈现出不同的亮度级别，电机用同样的方式就可以控制电机转速。PWM的秘诀就是天下武功唯快不破，只要我闪得足够快，你就发现不了我是闪着的还是一个平稳的亮度。
### 输出比较通道(高级)

![image-20250321102209938](images/image-20250321102209938.png)
右边的电路一般是接两个大功率的MOS管，构成最基本的推挽电路，上管导通，下管断开，输出高电平，下管道通上管断开，输出就是低电平，如果上下管都导通，那就是电源短路，这样是不允许的。如果上下管都断开，那输出就是高阻态。如果有两个这样的推挽电路，那就构成了H桥电路，就可以控制直流电机正反转了，如果有3个这样的推挽电路，就可以用于驱动三相无刷电机了。
这个电路如果直接用单片机来进行控制的话，就需要两个控制极，并且这两个控制极的电平是相反的，也就是互补的，因为上管道通下管就必须断开，下管导通上管就必须断开。所以OC1和OCIN就是两个互补的输出端口，在切换上下管导通状态时，如果在上管关断的瞬间下管就立刻开启，那可能会因为器件的不理想，上管还没有完全关断，下管就已经导通了，出现了短暂的上下管同时导通的现象。这会导致功率损耗，引起器件发热，为了避免这个问题，就有了死区生成电路，它会在上管关闭的时候延迟一小段时间再导通下管，下管关闭的时候延时一段时间再导通上管，这样就可以避免上下管同时导通的现象了，这就是死区生成和互补输出的用途。
### 输出比较通道(通用)

![image-20250321102215215](images/image-20250321102215215.png)
输出模式控制器的左边就是CNT计数器和CCR1第一路的捕获/比较寄存器，它俩进行比较，当CNT>CCR1或CNT=CCR1时，就会给输出模式控制器传一个信号，而后输出模式控制器就会改变它输出OCR1REF的高低电平。REF信号就是OCR1REF的高低电平，REF(reference)是参考信号，ETRF是定时器的小功能。从OCR1REF出来后信号可以向上走至主模式控制器，就可以将REF映射到主模式TRGO输出，但REF主要是去到极性选择器。给TIMx_CCER寄存器写0信号就会往上走，就是电平信号不翻转，进来啥样出去还是啥样，写1信号往下走，经过非门取反后，信号翻转，这就是极性选择电路，即要高电平还是低电平。最后的电路输出口OC1就是CH1通道。
### 输出比较模式
可以认为这个表格就是在描述输出模式控制器。
![image-20250321102221654](images/image-20250321102221654.png)
用处在于正在输出PWM波的时候想暂停一会儿，就可以设置成这个模式，一旦切换为冻结模式输出就暂停了，并且高低电平也为维持暂停时刻状态，保持不变。
匹配时电平翻转模式：可以方便输出一个频率可用，占空比始终为50%的PWM波形，比如设置CCR为0时，那CNT每次更新清0时，就会产生一次CNT=CCR事件，这就会导致输出电平翻转一次，每更新两次，输出为一个周期，并且高电平和低电平时间始终相等，也就是占空比始终为50%，当改变定时器更新频率时，输出波形的频率也会随之改变，输出波形的频率=更新频率/2。
有效电平和无效电平一般是高级定时器里面的说法，是和关断刹车这些功能配合表述的，它说的比较严谨，可以直接理解为置有效电平就是置高电平，置无效电平就是置低电平。这两个模式都是一次性的，如果想输出一次性的信号，可以参考这两个模式。

强制为无效电平和强制为有效电平，这两个模式和冻结模式也差不多，如果想暂停输出，并且在暂停期间保持低电平或者高电平时可以用这两个模式。
PWM模式1和PWM模式2：可以用于输出频率和占空比都可调的PWM波形，PWM模式2实际上就是PWM模式1的取反，输出模式控制器和极性控制器都可以控制PWM输出的极性，所以使用PWM模式1的正极性和PWM模式2的反极性最终的输出结果都是一样的，因此在实际使用过程中，仅使用PWM模式1即可。
### PWM基本结构
输出PWM的基本结构，蓝色线是CNT的值，黄色线是ARR的值，红色线是CCR的值。CNT<CCR置高电平，CNT≥CCR置低电平，CNT溢出清零后CNT<CCR。
<img src="images/image-20250321102328129.png" alt="image-20250321102328129" style="zoom:200%;" />
输出PWM不需要使用中断，配置好时基单元后，CNT就可以开始不断地自增运行了。  文字被擦除了，显示不全。

输出PWM的步骤
1.RCC开启时钟，把我们要用的TIM外设和GPIO外设的时钟打开。
2.配置时基单元，包括这前面的时钟源选择。
3.配置输出比较单元，包括CCR的值，输出比较模块，极性选择，输出使能这些参数，在库函数里也是用结构体统一来配置的。
4.配置GPIO，把PWM对应的GPIO口，初始化为复用推挽输出，GPIO和PWM的对应关系看引脚对应表。
5.运行控制，启动定时器。
### 参数计算
在实际使用中，可以先根据分辨率的要求，先确定ARR，比如分辨率1%，则ARR给100-1这样PSC决定频率，CCR决定占空比，如果要更高的分辨率，0.1%那ARR先固定1000-1这样频率就是72M/预分频器数值/1000占空比就是CCR/1000
当ARR=100-1时，CCR的值本身就是占空比，用起来很直观。PSC和ARR都可以调节频率，但是占空比=CCR/(ARR+1)所以通过调节ARR还会同事影响到占空比，而通过PSC调节频率，不会影响占空比，显然比较方便。
![image-20250321102408745](images/image-20250321102408745.png)
在等于30的瞬间，就已经跳变为低电平了，所以CNT从0到29是高电平，总共是30个数的时间，因为占空比就是30/100=30%。PWM周期，对应的是计数器的一个溢出更新周期，所以PWM的频率等于计数器的更新频率。
PWM频率：	Freq = CK_PSC / (PSC + 1) / (ARR + 1)
PWM占空比：	Duty = CCR / (ARR + 1)由上图可以看书CCR的值应该设置在0到ARR+1这个范围内，CCR=ARR+1时，占空比就正好是100%，如果CCR再大一些，那占空比就始终是100%，没有意义，所以CCR的变化范围取决于ARR的值，ARR越大，CCR的范围就越大，对应的分辨率就越大。
PWM分辨率：	Reso = 1 / (ARR + 1)此时分辨率的定义是占空比最小的变化步距，因此这个值是越小越好，也可以把CCR的范围定义成分辨率，那就是值越大越好，总之就是占空比的变化越细腻越好。

### 舵机介绍
舵机并不是一种单独的电机，它的内部是由直流电机驱动的，其内部有控制电路板，是一个电机的控制系统，大概的执行逻辑是PWM信号输入到控制板，给控制板一个指定的目标角度，然后电位器检测输出轴当前的角度，如果大于目标角度，电机就会反转，如果小于目标角度，电机就会正转，最终使输出轴固定在制定角度，这就是舵机内部的工作流程。


舵机是一种根据输入PWM信号占空比来控制输出角度的装置
输入PWM信号要求：周期为20ms，高电平宽度为0.5ms~2.5ms


![image-20250324164850161](images/image-20250324164850161.png)
3根输入线，两根式电源线VCC和GND，具体的型号是SG90，PWM的确也可以作为常用的通讯协议，因为他只用一根信号线。中间的角度是线性对应的，这里的PWM波形，其实是当作通讯协议来使用的，和之前所说的用PWM等效模拟输出关系不大。
### 硬件电路
舵机使用的是PA1引脚的通道2，一个定时器有4个通道，同一个定时器的不同通道输出PWM它们因为是通道间共用一个计数器的，所以他们的频率是一样的，他们的占空比由各自的CCR决定，所以占空比可以各自设定，还有就是它们的相位，由于计数器更新，所有PWM同时跳变，他们的相位是同步的，这就是同一个定时器不同通道输出PWM的特点。如果驱动多个舵机或直流电机，那使用一个通道的不同PWM即可。
舵机的对应关系的角度换算
0°-500ms
180°-2500ms
pwm=angle/180×(2500-500)+500
![image-20250324164840161](images/image-20250324164840161.png)
这个+5V是要接到ST-Link的5V端口上，因为STm32的输出电压只有3.3V，而且输出功率不大，所以是没有办法带得动电机的。一般点击都是大功率设备，它的驱动电源也必须是一个大功率的输出设备，如果能单独供电最好，如果不能也要看电源的功率能否达标，如果单独供电的话，供电的负极要和STm32共地，然后正极接在5V供电引脚上。因为舵机内部是有驱动电路的，所以单片机的引脚可以直接接到这里来，PWM只是一个通讯线，是不需要特别大功率的。
### 直流电机及驱动简介
因为电机也是磁铁和线圈，所以在PWM的驱动下会发出蜂鸣器的声音，解决的方法是加大PWM频率，人耳听力频率是20Hz-20kHz，因此PWM频率加大到20kHz以上即可。

直流电机是一种将电能转换为机械能的装置，有两个电极，当电极正接时，电机正转，当电极反接时，电机反转
直流电机属于大功率器件，GPIO口无法直接驱动，需要配合电机驱动电路来操作，当前市面上有很多的驱动电路可以选择，还有一些用分离元件MOS管搭建的电路，功率可以更大。常见的型号有TB6612，DRV8833，L9110，L298N等。
TB6612是一款双路H桥型的直流电机驱动芯片，可以驱动两个直流电机并且控制其转速和方向

![image-20250324164802466](images/image-20250324164802466.png)
这个直流电机是一个单独的电机，里面没有驱动电路，因此需要外挂一个驱动电路来控制，这个电机的型号叫作130电机。
TB6612，芯片中有两路驱动电路，可以独立地控制两个电机，又因为它是H桥型电路，里面一路有4个开关管，所以就可以控制正反转。有些芯片如ULN2003它里面一路就只有一个开关管，因此只能控制电机往一个方向转。可以看到外围电路仅需3个滤波电容，芯片的集成度很高。
H桥电路的基本结构，它是由两路推挽电路组成的，O1和O2接电机，右上和左下导通，电流从左上方流到右下方，右上和左下导通，电流从右上方流到左下方，H桥可以控制电流经过，所以它就能控制电机正反装。

### 硬件电路
PWMA引脚要接到PWM信号输出端口，其它两个引脚可以任意接两个普通的GPIO口，那这三个引脚给一个低功率的控制信号，驱动电路就会从VM汲取电流来输出到电机，这样就能完成从低功率的控制信号控制大功率设备的目的了。VM是电机电源的正极和舵机的要求一样，要接一个可以输出大电流的电源。STBY(StandBy)引脚，这个是待机控制引脚，如果接GND，芯片就不工作，处于待机状态，如果接逻辑电源VCC，芯片就正常工作，这个引脚如果不需要待机模式的话，可以直接接VCC3.3V，如果需要的话，可以任意接一个GPIO给高低电平就可以控制了。
在板子内部这三个GND都是连通的，但这三个代表的地并不是一样的，其实分为了功率地、模拟地、数字地，普通应用简单练手都连起来用就可以了。
![image-20250324164735221](images/image-20250324164735221.png)
驱动电压输入端：5V的电机就接5V，7.2V就接7.2V，电压和电机额定电压保持一致。
逻辑电平输入端：这个要和控制器的电源保持一致，STm32是3.3V器件，就接3.3V，C51时5V器件就接5V，这个引脚并不用大功率，可以和控制器共用一个电源。
![image-20250324164740753](images/image-20250324164740753.png)
如果PWM是一个不断翻转的电平信号，那电机就会迅速地反转停止反转停止，如果PWM的频率足够快，那电机就可以连续稳定地反转了，并且速度取决于PWM信号占空比，IN1给低电平，IN2给高电平，PWM高转低不转。这里的PWM就是我们之前讲的使用PWM来等效模拟一个模拟量的功能了。
IN1和IN2全部都接高电平，两个输出都为低电平，这样两个输出没有电压差，电机是不会转的。如果IN1和IN2全部都接低电平，输出直接关闭，这样电机也是不会转的，全高或全低，电机都不会转。IN1高电平IN2低电平，电机处于反转状态，转和不转取决于PWM，如果PWM给高电平，那输出就是一高一低，有电压差了电机就可以转，这时定义的是反转。如果PWM给低电平，那输出两个低电平，电机还是不转。IN1高电平，IN2低电平这样电机就是正转状态，具体转动情况取决于PWM信号，PWM高，正转，PWM低，停止，如果PWM频率足够快，那电机就可以连续稳定地正转了，并且速度取决于PWM信号的占空比。

### 输入捕获简介
IC（Input Capture）输入捕获
输入捕获模式下，当通道输入引脚出现指定电平跳变(上升沿或者下降沿)时，当前CNT的值将被锁存到CCR中，也就是把当前CNT的值读出来写入到CCR中，可用于测量PWM波形的频率、占空比、脉冲间隔、电平持续时间等参数。脉冲间隔和频率就是一个意思，电平持续时间和占空比差不多。
每个高级定时器和通用定时器都拥有4个输入捕获通道
可配置为PWMI模式，同时测量频率和占空比，这个PWMI模式就是PWM的输入模式，是专门测量PWM频率和占空比设计的。
可配合主从触发模式，实现硬件全自动测量，把主从触发模式和PWM2模式结合起来，测量频率和占空比就是硬件全自动执行，软件不需要进行任何干预，也不需要进入中断，需要测量的时候，直接读取CCR寄存器就行了。

输出比较：引脚是输出端口，根据CNT和CCR的关系大小来执行输出动作。
输入捕获：引脚是输入端口，接收到输入信号，执行CNT锁存到CCR的动作。

### 频率测量
这是一个频率逐渐降低的方波波形，越往左频率越高，越往右频率越低，这里信号都是只有高低电平的数字信号，对于STm32测频率而言，它也是只能测量数字信号的，如果需要测量正弦波，那还需要搭建一个信号预处理电路，最简单的就是用运放搭建一个比较器，把正弦波转化为数字信号，再输入给STm32即可。
![image-20250324164715048](images/image-20250324164715048.png)
假设要测量这一块信号的频率，那么就可以定一个闸门时间T，一般是1s，在1s时间内对信号的上升沿进行计次，从0开始计每来一个上升沿，计次+1，每来一个上升沿，计次+1，每来一个上升沿，其实就是来了一个周期的信号，因此在一个周期内来了多少个上升沿，就是多少信号就是多少Hz。频率的定义就是在1s内出现了多少个重复的周期，那频率就是多少Hz，所以在1s的时间闸门时间内对上升沿计次，计次多少，频率值就是多少Hz。
这种直接按频率定义来进行测量的方法就是测频法，另外这个闸门时间也可以是2s，那么计次数除2就是频率也可以是0.5s计次，那么计次数×2就是频率。
当待测信号频率小于中界频率时，测周法误差更小，选用测周法更合适当待测信号频率大于中界频率时，测频发误差更小，选用测频法误差更小，选用测频法更合适。

测周法：捕获信号的两个上升沿，然后测量一下这之间持续的时间，但是实际上并没有一个精度无穷大的秒表来测量时间，测量时间的方法，实际上也是定时器计次。我们使用已知标准频率的计次时钟来驱动计数器，从一个上升沿开始计，计数器从零开始一直计到下一个上升沿，计一个数的时间是1/fc，计N个数时间就是N/fc，周期也就是N/fc，取到数就是fc/N。
测频法和测周法的区别：测频法适合测量高频信号，测周法适合测量低频信号，在闸门时间内，最好要多出现一些上升沿计次数量多一些，这样有助于减小误差，假如定了1s的闸门时间，结果信号频率特别低，1s的时间才只有寥寥无几的上升沿，甚至1个上升沿都没有，那总不能认为频率是0吧，计次N很少时，误差会很大，所以测频法要求信号频率要稍微高一点。测周法就要求信号频率低一些，低频信号周期比较长，计次就会比较多有助于减小误差，否则的话，比如标准频率fc为1MHz，待测信号比较高，比如待测信号500kHz，现在一个周期只能计一两个数，如果待测信号再高一些，甚至一个数也计不到，那总不能认为频率无穷大吧，所以测周法需要待测信号频率低一些，还有就是测频法结果更新慢一些数值相对稳定，测周法更新的快，数据跳变也非常快。
如果测量的信号电压非常高，那还要考虑一下隔离的问题，比如用一些隔离放大器，电压互感等元件，隔离高压端和低压端保证电路的安全，总之经过处理，给STm32的信号必须是由高低电平构成的数字信号，高电平3.3V，低电平0V。

测频法：在闸门时间T内，对上升沿计次，得到N，则频率
𝑓_𝑥=𝑁 / 𝑇
测周法：两个上升沿内，以标准频率fc计次，得到N ，则频率
𝑓_𝑥=𝑓_𝑐  / 𝑁
中界频率：测频法与测周法误差相等的频率点
𝑓_𝑚=√(𝑓_𝑐  / 𝑇)

测频法和测周法的区别：测评法 测量的是在闸门时间内的多个周期，所以它自带一个均值滤波，如果在闸门时间内波形频率有变化，那得到的其实是这一段时间的平均频率，如果闸门时间选为1s，那么每间隔1s才能得到一次结果，所以测频法结果更新慢，数值比较平滑。而测周法，它只测量一个周期就能出一次结果，所以出结果的速度取决于待测信号的频率，一般而言，待测信号都是几百几千Hz，所以一般情况下，测周法结果更新更快，但是由于它只测量一个周期，所以结果值会受噪声影响，波动比较大，这就是这两种方法的基本特征。

那具体而言，频率多高算高，多低算低呢？这就涉及中界频率的概念，中界频率就是测频法和测周法误差相等的频率点，之前说测频法计次和测周法计次，这个计数要大一些N越大，相对误差越小，因为在这些方法中，计次可能会存在正负1误差，比如测频法在闸门时间内并不是每个周期信号都是完整的，比如在最后时间内，可能有一个周期刚好出现一半闸门闸门时间就到了，那这只有半个周期，只能舍弃掉或当作一整个周期来看，因为计数只有整数不可能计数0.5个数，那在这个过程就会出现多计一个数或者少计一个数的情况。测周法也有，标准频率fc计次，在最后时刻，有可能一个数刚好数一般，计时就结束了，那这半个数也只能舍弃掉或者按一整个数来算了，这里也会出现正负1误差，因此正负1误差是这两种方法固有的误差，要想减小正负1误差的影响，就只能尽量多的计数，当计次N比较大的时候，对N的影响就会减小。就想去超市买一瓶水，本来两块钱商家搞错了卖3块钱，这就是黑心商家对吧，但是去买电脑本来5000商家搞错了卖5001，那也就无所谓了是吧。因此当有一个频率，测频法和测周法的计次N相同就说明误差相同，此时这个频率就是中界频率。具体公式就是联立测频法和测周法的方程组。

测频法的实现方式：之前实现过代码，对射式红外传感器计次，定时器外部时钟改动一下这些代码就是测频法，比如对射式红外传感器计次每来一个上升沿+1那我们再用一个定时器，定1个1s的定时中断，在中断里每隔1s取一下计数值，同时清零计次，为下一次做准备，这样每次读取的计次值就直接是频率。对应定时器外部时钟的代码也是如此，每隔1s取一下计次就能实现测频法测量频率的功能。
### 输入捕获通道

![image-20250324164613104](images/image-20250324164613104.png)
TI1也就是CH1引脚，FDTS就是滤波器，是采样时钟来源。这里实际应该还有一套一样的电路，得到TI1FP2触发信号，连通到通道2的后续电路，同样通道2有TI2FP1连通到通道1的后续电路，通道2也还有TI2FP2连通到通道2的后续电路，一共有4种连接方式。CCMR1寄存器的ICF位可以控制滤波器的参数，简单来说这个滤波器的工作原理就是以采样频率对输入信号进行采样，当连续N个值都为高电平，输出才为高电平，连续N个值都是低电平，输出才为低电平，如果信号出现高频率抖动，导致连续N个采样值不全都一样，那输出就不会变化，这样就可以达到滤波的效果，采样频越低，采样个数N越大，滤波效果就越好，在实际应用中，如果波形的噪声很大，就可以把参数调大一点，这样就可以过滤噪声了。TI1F就是滤波之后的电路。边沿检测器就是捕获上升沿或下降沿，用CCER寄存器的CC1P位就可以选择极性了。最终得到的就是TI1FP1触发信号，通过数据选择器进入通道1后续的捕获电路。CC1S位可以对数据选择器进行选择，ICPS位可以配置这里的分频器，可以选择不分频、2分频、4分频、8分频。CC1E位，控制输出使能或失能，如果使能了输出，输入端产生指定边沿信号，经过层层电路，就可以让CNT的值转运到CCR里面来，又因为每捕获一次CNT的值，都要把CNT清零一下，以便下一次捕获，在这里硬件电路就可以在捕获之后自动完成CNT的清零工作。

自动清零CNT的值：这个TI1FP1信号和TI1的边沿信号都可以通向从模式控制器，比如TI1FP1信号的上升沿触发捕获，那通过这里TI1FP1还可以同时触发从模式，这个从模式就有电路，可以自动完成CNT清零。
### 主从触发模式

![image-20250324164604001](images/image-20250324164604001.png)
主从触发模式就是主模式从模式和触发源选择这三个功能的简称，其中主模式可以将定时器内部信号映射到TTRGO引脚用于触发别的外设所以这部分叫做主模式，从模式就是接受其他外设或者自身外设的一些信号，用于控制自身定时器的运行也就是被别的信号控制，所以这部分叫做从模式。
如果想完成刚才所说的硬件自动化的流程，想让TI1FP1信号自动触发CNT清零，那就可以选择TI1FP1触发源，从模式执行的操作就可以选择Reset操作。触发源选择，就是选择从模式的触发信号源，可以认为是从模式的一部分，选择指定的一个信号，得到TRGI，然后TRGI去触发从模式，从模式可以在列表中选择一项操作自动来执行。
### 输入捕获基本结构
然后在一个周期内CNT在标准时钟的驱动下不断自增，并且由于之前清零过了，所以CNT就是从上升沿开始从0开始计数一直自增直到下一次上升沿来临，然后执行相同的操作。
此时信号出现上升沿CCR1=CNT，就是把CNT的值转运到CCR1里去，这是输入捕获自动执行的。从这里输入，然后CNT=0，清零计数器，这是从模式自动执行的。注意第二次捕获的时候，这个CNT就是两个上升沿之间的值，计数值自动放在CCR1里面然后下一个周期继续同样的过程，因此当这个电路工作时，CCR1的值始终保持为最新一个周期的计数值，计算频率时读取CCR1的值得到N，再计算fc/N就行了，不需要读取整个电路，全自动测量不需要占用任何软件资源。
把时基单元配置好，启动定时器，那这个CNT就会在预分频器之后的这个时钟驱动下，不断自增，这个CNT的值就是我们测周法用来计数计时的东西。经过预分频器之后这个位置的时钟频率就是驱动CNT标准频率fc这里不难看出标准频率=72MHz/预分频系数。
在通道1的GPIO输入如上所示的方波信号经过滤波器和边沿检测选择TI1FP1作为上升沿触发，之后选择直连的通道，分频器选择不分频，当TI1FP1出现上升沿之后，CNT的当前计数值转运到CCR1里，同时触发源选中TI1FP1为触发信号，从模式选择复位操作，这样TI11FP1的上升沿也会通过上面这一路去触发CNT清零，当然这里会有先后顺序，肯定先得转运CNT的值到CCR里去，再触发从模式给CNT清零或者是非阻塞同时转移CNT的值转移到CCR，同时0转移到CNT里面去，总之肯定是不会先清零再捕获，要不然捕获值肯定都是0了。
![image-20250324164549090](images/image-20250324164549090.png)
这个结构只使用了一个通道，所以它目前只能测量频率。
注意事项：1.CNT的值是有上限的，ARR一般设置为最大65535那CNT最大也只能计数65535个数，如果信号频率太低，CNT计数值可能溢出。2.从模式触发源选择，只有TI2FP1，TI2FP2，没有TI3和TI4的信号，所以这里如果想用从模式自动清零CNT，就只能用通道1和通道2，对于通道3和通道4就只能开启捕获中断，在中断里手动清零了，但这样程序就会处于频繁中断的状态，比较消耗软件资源。
### PWMI基本结构
PWMI模式，使用两个通道同时捕获一个引脚，可以同时测量周期和占空比。上升沿CCR1捕获同时清零CNT之后CNT一直自增然后在下降沿时刻触发CCR2捕获，所以这时CCR2的值就是CNT从1到2的值，即高电平期间计数值。CCR2捕获并不会触发CNT清零，所以CNT继续自增直到下一次上升沿，CCR捕获周期CNT清零。这样执行之后CCR就是一整个周期的计数值，CCR2就是高电平期间的计数值，用CCR2/CCR1就得到了占空比的数值，这就是PWMI模式使用两个通道来捕捉频率和占空比的思路。
![image-20250324164529007](images/image-20250324164529007.png)
TI1FP1配置上升沿触发捕获和清零CNT，这里可以两个通道同时捕获第一个引脚的输入这样通道2的前一部分就没有用到，当然也可以配置两个通道同时捕获第二个引脚的输入，这样我们就是使用TI2FP1和TI2FP2这两个引脚了，这两个引脚可以灵活切换。TI1FP2配置为下降沿触发通过交叉通道去触发通道2的捕获单元。

### 编码器接口
Encoder Interface 编码器接口
编码器接口可接收增量（正交）编码器的信号，根据编码器旋转产生的正交信号脉冲，自动控制CNT自增或自减，从而指示编码器的位置、旋转方向和旋转速度
每个高级定时器和通用定时器都拥有1个编码器接口
两个输入引脚借用了输入捕获的通道1和通道2
### 正交编码器

![image-20250326101354133](images/image-20250326101354133.png)


# ESP32-IDF

## WSL2搭建ESP-IDF开发环境

### WSL环境搭建

#### 1.安装

1. 管理员运行powershell

2. 启用“适用于Linux的Windows子系统”可选功能

   ```powershell
   dism.exe /online /enable-feature /featurename:Microsoft-Windows-Subsystem-Linux /all
   ```

3. 启用虚拟机可选组件

   ```
   dism.exe /online /enable-feature /featurename:VirtualMachinePlatform /all /norestart
   ```

   

4. 重启电脑重新以管理员运行powershell

   ```
   wsl --set-default-version 2
   ```

   

5. 打开Microsoft Store，选择偏好的Linux分发版获取

6. 安装完成电机启动，在powershell里面执行wsl.exe

7. 设置初始用户名和密码

#### 2.更换源

1. 备份文件

   ```bash
   sudo mv /etc/apt/sources.list /etc/apt/sources.list_bak
   ```

   

2. 新建文件并选择一家写入文件

   ```bash
    sudo vim /etc/apt/sources.list
   ```

   

3. 或选择一键指令配置

   ```bash
   sudo sed -i -r 's#http://(archive|security).ubuntu.com#https://mirrors.aliyun.com#g' /etc/apt/sources.list
   ```

   

4. 获取&更新

   ```bash
   sudo apt-get update
   sudo apt-get upgrade
   ```

   

清华源

```powershell
# 默认注释了源码镜像以提高 apt update 速度，如有需要可自行取消注释
deb https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ jammy main restricted universe multiverse
# deb-src https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ jammy main restricted universe multiverse
deb https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ jammy-updates main restricted universe multiverse
# deb-src https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ jammy-updates main restricted universe multiverse
deb https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ jammy-backports main restricted universe multiverse
# deb-src https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ jammy-backports main restricted universe multiverse
deb https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ jammy-security main restricted universe multiverse
# deb-src https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ jammy-security main restricted universe multiverse

# 预发布软件源，不建议启用
# deb https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ jammy-proposed main restricted universe multiverse
# deb-src https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ jammy-proposed main restricted universe multiverse

```

阿里源

```bash
deb http://mirrors.aliyun.com/ubuntu/ jammy main restricted universe multiverse
deb-src http://mirrors.aliyun.com/ubuntu/ jammy main restricted universe multiverse
deb http://mirrors.aliyun.com/ubuntu/ jammy-security main restricted universe multiverse
deb-src http://mirrors.aliyun.com/ubuntu/ jammy-security main restricted universe multiverse
deb http://mirrors.aliyun.com/ubuntu/ jammy-updates main restricted universe multiverse
deb-src http://mirrors.aliyun.com/ubuntu/ jammy-updates main restricted universe multiverse
deb http://mirrors.aliyun.com/ubuntu/ jammy-proposed main restricted universe multiverse
deb-src http://mirrors.aliyun.com/ubuntu/ jammy-proposed main restricted universe multiverse
deb http://mirrors.aliyun.com/ubuntu/ jammy-backports main restricted universe multiverse
deb-src http://mirrors.aliyun.com/ubuntu/ jammy-backports main restricted universe multiverse

```

中科大源

```bash
deb https://mirrors.ustc.edu.cn/ubuntu/ jammy main restricted universe multiverse
deb-src https://mirrors.ustc.edu.cn/ubuntu/ jammy main restricted universe multiverse
deb https://mirrors.ustc.edu.cn/ubuntu/ jammy-updates main restricted universe multiverse
deb-src https://mirrors.ustc.edu.cn/ubuntu/ jammy-updates main restricted universe multiverse
deb https://mirrors.ustc.edu.cn/ubuntu/ jammy-backports main restricted universe multiverse
deb-src https://mirrors.ustc.edu.cn/ubuntu/ jammy-backports main restricted universe multiverse
deb https://mirrors.ustc.edu.cn/ubuntu/ jammy-security main restricted universe multiverse
deb-src https://mirrors.ustc.edu.cn/ubuntu/ jammy-security main restricted universe multiverse
deb https://mirrors.ustc.edu.cn/ubuntu/ jammy-proposed main restricted universe multiverse
deb-src https://mirrors.ustc.edu.cn/ubuntu/ jammy-proposed main restricted universe multiverse

```

网易163源

```bash
deb http://mirrors.163.com/ubuntu/ jammy main restricted universe multiverse
deb http://mirrors.163.com/ubuntu/ jammy-security main restricted universe multiverse
deb http://mirrors.163.com/ubuntu/ jammy-updates main restricted universe multiverse
deb http://mirrors.163.com/ubuntu/ jammy-proposed main restricted universe multiverse
deb http://mirrors.163.com/ubuntu/ jammy-backports main restricted universe multiverse
deb-src http://mirrors.163.com/ubuntu/ jammy main restricted universe multiverse
deb-src http://mirrors.163.com/ubuntu/ jammy-security main restricted universe multiverse
deb-src http://mirrors.163.com/ubuntu/ jammy-updates main restricted universe multiverse
deb-src http://mirrors.163.com/ubuntu/ jammy-proposed main restricted universe multiverse
deb-src http://mirrors.163.com/ubuntu/ jammy-backports main restricted universe multiverse

```



#### 3.ssh配置

```bash
sudo apt remove openssh-server
sudo apt install openssh-server
sudo vim /etc/ssh/sshd_config 

#找到以下配置并更改
Port 22222                   # 设置端口为22222
ListenAddress 0.0.0.0		
PermitRootLogin yes         # 允许root远程登录
PasswordAuthentication yes  # 密码验证登录

#windows自启动&服务启动
#wsl2下
sudo vim /etc/init.wsl
    #内容如下
    #! /bin/sh
    /etc/init.d/ssh start
#配置权限
sudo chmod +x /etc/init.wsl

#windows下创建 wsl-start.vbs文件添加内容如下
    Set ws = WScript.CreateObject("WScript.Shell")        
    ws.run "wsl -d ubuntu -u root /etc/init.wsl"
    
#Win+R  shell:startup 将上面vbs文件放入打开的文件夹内

```

### ESP-IDF

#### 1.环境安装

```bash
#编译 ESP-IDF 需要以下软件包
sudo apt-get install git wget flex bison gperf python3 python3-venv python3-setuptools cmake ninja-build ccache libffi-dev libssl-dev dfu-util libusb-1.0-0
```



#### 2.获取ESP-IDF

```bash
#用户目录下创建esp文件夹，从git仓库拉取V5.0版本至此目录下
mkdir -p ~/esp
cd ~/esp
git clone -b release/v5.0 --recursive https://github.com/espressif/esp-idf.git
```



#### 3.设置工具

```bash
#进入idf文件夹，设置对应工具
cd ~/esp/esp-idf

#配置esp32项目开发
./install.sh esp32

#配置esp32&esp32s2项目开发
./install.sh esp32,esp32s2

#配置所有项目开发
./install.sh all
```



#### 4.设置环境变量

```bash
# 注意设置环境变量后才可以正常使用idf开发
. $HOME/esp/esp-idf/export.sh
```

#### 5.hello world工程示例

工程示例，从/esp-idf中的example目录下将get-started/hello工程复制到本地的~/esp目录下，进入hello_world目录，设置esp32s3为目标芯片，然后运行工程配置工具menuconfig，使用idf.py set-target esp32s3设置目标芯片时，此操作将清除并初始化项目之前的编译和配置(如果有的话)，也可以直接将目标配置为环境变量。

```bash
cd ~/esp/hello_world
idf.py set-target esp32S3
idf.py menuconfig

# 编译
idf.py build

# 下载运行
idf.py -p PORT [-b BAUD] flash

# 监视输出
idf.py -p PORT monitor
# “Ctrl+]”  退出
```



### 常用工具

#### Windows usbipd命令

​	因为wsl2无法直接使用Windows下的串口，借助开源usbipd-win项目来实现串口烧录。

##### usbipd介绍

​	usbipd是一个用于管理USB/IP(USB over IP)服务的命令行工具，可以在Windows下使用。USB/IP是一种协议，允许通过网络共享USB设备。usbipd工具允许用户在Windows上共享USB设备，使其他计算机能够通过网络访问这些设备。

##### Windows下安装

​	仓库下载安装或者通过powershell的Windows程序包管理器程序(winget)来安装

```powershell
#使用 winget 工具安装和管理应用程序安装  取消--interactive可能导致立即重启
winget install --interactive --exact dorssel.usbipd-win
```

##### wsl2下安装

https://github.com/dorssel/usbipd-win/wiki/WSL-support 参考链接

在wsl2下面需要下列命令

```powershell
sudo apt install linux-tools-virtual hwdata
sudo update-alternatives --install /usr/local/bin/usbip usbip `ls /usr/lib/linux-tools/*/usbip | tail -n1` 20
```

##### 具体使用

```powershell
#管理员打开Powershell，否则会提示没有权限
wsl -l -v
	#我的结果如下：
  	NAME            STATE           VERSION
	* Ubuntu-22.04    Running         2

#列出所有连接到 Windows 的 USB 设备
usbipd list
	#我的结果如下：
Connected:
BUSID  VID:PID    DEVICE                                                        STATE
1-1    1a86:7523  USB-SERIAL CH340 (COM8)                                       Not shared
1-3    046d:c53f  LIGHTSPEED Receiver, USB 输入设备                             Not shared
1-6    0408:4035  ACER HD User Facing, APP Mode                                 Not shared
1-10   8087:0026  英特尔(R) 无线 Bluetooth(R)                                   Not shared

Persisted:
GUID                                  DEVICE
#选择WSL的设备总线ID，然后运行此命令。WSL会提示你输入密码以运行sudo命令。要附加的 Linux 发行版必须是默认分发版

#绑定ID
usbipd bind --busid 4-4
#创建映射
usbipd attach -b 4-4 -w
	# WSL2下使用 sudo /dev/tty* 在绑定前后查询，查看新增设备名
	# 有些为 /dev/ttyUSB0 我的为 /dev/ttyACM0

#WSL2下设置设备读写权限
sudo chmod a+rw /dev/ttyACM0

#解绑映射 注意不解绑可能导致windows下无法使用此COM口
usbipd detach -b 4-4

```



##### 基本命令参数

```powershell
usbipd list
```

**描述**：列出当前系统上所有可用的USB设备

**示例**：

```powershell
PS C:\Users\57117> usbipd list
Connected:
BUSID  VID:PID    DEVICE                                                        STATE
1-1    1a86:7523  USB-SERIAL CH340 (COM8)                                       Not shared
1-3    046d:c53f  LIGHTSPEED Receiver, USB 输入设备                             Not shared
1-6    0408:4035  ACER HD User Facing, APP Mode                                 Not shared
1-10   8087:0026  英特尔(R) 无线 Bluetooth(R)                                   Not shared

Persisted:
GUID                                  DEVICE
```

​	使用usbipd

```powershell
usbipd unbind --guid [GUID]
```

## FreeRTOS学习笔记

在使用idf.py build编译后，编译器会根据我们的代码区分出指令总线和数据总线，指令总线部分是可以执行的，比如说我们定义的函数，数据总线部分不可执行，只能通过字节操作访问，比如说全局变量。
DRAM（数据 RAM）：属于数据总线，非常量静态数据（如 .data 段和 .bss 段，通常是数值为0的全局变量）由链接器放入内部 SRAM 作为数据存储，也可以配置放入外部 RAM。也就是说static变量或者说初始化为0的全局变量就是存放在这里。
"noinit" DRAM： 属于数据总线，未初始化的全局变量数据，链接器接管放入内部 SRAM 作为数据存储，也可配置放入外部 RAM。在这个部分的值，启动的时候是不会被初始化的。
IRAM（指令 RAM）： 属于指令总线，ESP-IDF 将内部 SRAM0（包含3个存储块：SRAM0、SRAM1和SRAM2）的一部分区域（SRAM0 和 SRAM1）分配为指令 RAM。一般来说，编写的中断程序就是放在这个IRAM中的，另外在应用程序用可以通过使用 IRAM_ATTR宏在源代码中指定哪些代码需要放入 IRAM 中。
IROM（代码从 flash 中运行）：指令总线，如果一个函数必须从 flash 中加载，它将被存储在 flash 中，或者存储在 RTC 存储器中。
DROM（数据存储在 flash 中）： 数据总线，用于存储仅读取的数据，就是程序中的常量用const修饰的变量。
RTC Slow memory（RTC 慢速存储器）： 数据总线，RTC_NOINIT_ATTR 属性可以将某些数据存入 RTC Slow memory。存储器中的值在深度睡眠模式中保持不变。
RTC Fast memory（RTC 快速存储器）： 具有双重作用，既可以用作指令存储器，也可以当做数据存储器，RTC Fast memory 也可以在深度睡眠模式下保持数据，并且能够快速存取。从深度睡眠模式唤醒后必须要运行的代码就是要放在RTC存储器中的。

ESP32的启动流程
刚才介绍的所有区域都可以被称为段，app_main()是ESP32的应用入口，但是在启动和到达应用入口中间还有很多的工作，具体而言如下所示：1.一级引导程序，固化在ROM中，不可修改，它是负责加载二级引导程序至RAM中运行，并检查IO0引脚，选择程序模式，当芯片上电检测到IO0引脚是低电平的话，就会进入下载模式，否则就会继续执行二级引导程序。2.二级引导程序，也就是bootloader程序，从0x8000处读取分区表，处理各种段，比如说会将IRAM内容拷贝到内存SRAM中，最后加载应用程序。3.应用程序，硬件外设和基本C语言运行环境的初始化，最后执行app_main()函数。
### FreeRTOS
#### 任务创建
在RTOS系统中每个模块相当于都是独立的工作的，通过时间片的方式，每个模块都可以得到执行的机会，任务运行的基本单位是Tick，也可以叫做系统时钟节拍，在ESP-IDF中一个系统节拍是1ms。使用FreeRTOS的实时应用程序可以被构建为一组独立的任务。每个任务在自己的上下文中执行，不依赖于其他任务或RTOS调度器本身。任务分为四个状态：运行、准备就绪、阻塞、挂起。

运行：当任务实际执行时，它被称为处于运行状态。 任务当前正在使用处理器。 如果运行
RTOS 的处理器只有一个内核， 那么在任何给定时间内都只能有一个任务处于运行状态。

准备就绪：准备就绪任务指那些能够执行（它们不处于阻塞或挂起状态），但目前没有执行的任务，因为同等或更高优先级的不同任务已经处于运行状态。

阻塞：如果任务当前正在等待时间或外部事件，则该任务被认为处于阻塞状态。例如，如果一
个任务调用 vTaskDelay()，它将被阻塞（被置于阻塞状态），直到延迟结束-一个时间事件。任务也可以通过阻塞来等待队列、信号量、事件组、通知或信号量事件。处于阻塞状态的任务通常有一个"超时"期， 超时后任务将被超时，并被解除阻塞，即使该任务所等待的事件没有发生。“阻塞”状态下的任务不使用任何处理时间，不能被选择进入运行状态。

挂起：与“阻塞”状态下的任务一样， “挂起”状态下的任务不能 被选择进入运行状态，但处于挂起状态的任务没有超时。相反，任务只有在分别通过 vTaskSuspend() 和 xTaskResume()API 调用明确命令时 才会进入或退出挂起状态。

优先级：每个任务均被分配了从 0 到 ( configMAX_PRIORITIES - 1 ) 的优先级，其中的configMAX_PRIORITIES 在 FreeRTOSConfig.h 中定义，低优先级数字表示低优先级任务。 空闲任务的优先级为零。
```C++
// 这个函数是原生FreeRTOS中没有的函数，是乐鑫公司自己实现的函数，因为原生的FreeRTOS并没有支持多核CPU情况。但是原生的xTaskCreate()也是在IDF中被支持的，但实质上就是将xTaskCreatePinnedToCore()封装成了xTaskCreate()，并且内核指定为了NO_AFFINITY，来保持的函数接口不变。
BaseType_t xTaskCreatePinnedToCore(
    TaskFunction_t pvTaskCode,          // 任务函数指针，原型是 void fun(void *param)
    const char * constpcName,           // 任务名称，打印调试时可能会用到
    const uint32_t usStackDepth,        // 任务堆栈空间大小（字节），和原生FreeRTOS的单位不同，一般最小就是2048字节
    void * constpvParameters,          // 任务参数
    UBaseType_t uxPriority,             // 任务优先级，数值越大，优先级越高，0到(configMAX_PRIORITIES - 1)这个宏定义的默认值就是25，也就是最高优先级就是24
    TaskHandle_t * constpvCreatedTask, // 返回创建的任务句柄，有了这个句柄就可以对任务进行挂起、恢复、删除操作，如果不需要的话直接置为NULL即可
    const BaseType_t xCoreID           // 指定任务在哪个核心上运行，可以选择0或者1
);

// 如果创建成功，则返回 pdPASS，否则返回相关错误码


// 自己指定栈内存区的版本
TaskHandle_t xTaskCreateStaticPinnedToCore(
    TaskFunction_t pvTaskCode,          // 任务函数指针
    const char * constpcName,           // 任务名称
    const uint32_t ulStackDepth,        // 任务堆栈大小
    void * constpvParameters,           // 任务参数
    UBaseType_t uxPriority,             // 任务优先级
    StackType_t * constpxStackBuffer,   // 指向堆栈内存区域的指针
    StaticTask_t * constpxTaskBuffer,   // 指向任务控制块内存区域的指针
    const BaseType_t xCoreID            // 指定任务在哪个核心上运行
);
// 延时xTickToDelay个周期
void vTaskDelay(const TickType_t xTickToDelay);

//用于表示精确的接触阻塞时间
void vTaskGetTickCount(Ticktype_t *pxPreviousWakeTime, const TickType_t xTimeIncrement);
```

```c++
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/semphr.h"
#include "freertos/event_groups.h"
#include "freertos/queue.h"
#include "esp_log.h"

static const char *TAG = "main";

/** 任务A

 * @param 无
 * @return 无
   */
   void taskA(void *param)
   {
    while(1)
    {
        //每隔500ms打印
        ESP_LOGI(TAG,"this is taskA");
        vTaskDelay(pdMS_TO_TICKS(500));
    }
   }
   /** 任务B
 * @param 无
 * @return 无
   */
   void taskB(void* param)
   {
    while(1)
    {
        //每隔700ms打印
        ESP_LOGI(TAG,"this is taskB");
        vTaskDelay(pdMS_TO_TICKS(700));
    }
   }

/** 任务例程初始化

 * @param 无
 * @return 无
   */
   void rtos_task_sample(void)
   {
    //以下创建两个任务，任务栈大小为2048字节，优先级为3，并设定运行在CORE1上
    xTaskCreatePinnedToCore(taskA,"taskA",2048,NULL,3,NULL,1);
    xTaskCreatePinnedToCore(taskB,"taskB",2048,NULL,3,NULL,1);
   }

//队列句柄
static QueueHandle_t s_testQueue;
//定义一个队列数据内容结构体
typedef struct
{
    int num;    //里面只有一个num成员，用来记录一下数据
}queue_packet;

/** 队列任务A，用于定时向队列发送queue_packet数据

 * @param 无
 * @return 无
   */
   void queue_taskA(void *param)
   {
    int test_cnt = 0;
    while(1)
    {
        queue_packet packet;
        packet.num = test_cnt++;
        //发送queue_packet数据
        xQueueSend(s_testQueue,&packet,pdMS_TO_TICKS(200));
        ESP_LOGI(TAG,"taskA send packet,num:%d",packet.num);
        //延时1000ms
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
   }

/** 队列任务B，用于从队列接收数据

 * @param 无
 * @return 无
   */
   void queue_taskB(void *param)
   {
    while(1)
    {
        queue_packet packet;
        BaseType_t ret = xQueueReceive(s_testQueue,&packet,pdMS_TO_TICKS(200));
        if(ret == pdTRUE)
        {
            //如果收到数据就打印出来
            ESP_LOGI(TAG,"taskB receive packet,num:%d",packet.num);
        }
    }
   }

/** 初始化队列例程

 * @param 无
 * @return 无
   */
   void rtos_queue_sample(void)
   {
    //初始化一个队列，队列单元内容是queue_packet结构体，最大长度是5
    s_testQueue = xQueueCreate(5,sizeof(queue_packet));
    //队列任务A，定时向队列发送数据
    xTaskCreatePinnedToCore(queue_taskA,"queue_taskA",2048,NULL,3,NULL,1);
    //队列任务B，从队列中接收数据
    xTaskCreatePinnedToCore(queue_taskB,"queue_taskB",2048,NULL,3,NULL,1);
   }

//二进制信号量
static SemaphoreHandle_t s_testBinSem;
//计数信号量
static SemaphoreHandle_t s_testCountSem;
//互斥信号量
static SemaphoreHandle_t s_testMuxSem;

/** 信号量任务A，定时向三种信号量句柄释放信号

 * @param 无

 * @return 无
   */
   void sem_taskA(void* param)
   {
    const int count_sem_num = 5;
    while(1)
    {
        //向二值信号量释放信号
        xSemaphoreGive(s_testBinSem);

        //向计数信号量释放5个信号
        for(int i = 0;i < count_sem_num;i++)
        {
            xSemaphoreGive(s_testCountSem);
        }
       
        //向互斥信号量释放信号
        xSemaphoreGiveRecursive(s_testMuxSem);
        vTaskDelay(pdMS_TO_TICKS(2000));

    }
   }

void sem_taskB(void* param)
{
    BaseType_t ret = 0;
    while(1)
    {
        //无限等待二进制信号量，直到获取成功才返回
        ret = xSemaphoreTake(s_testBinSem,portMAX_DELAY);
        if(ret == pdTRUE)
            ESP_LOGI(TAG,"take binary semaphore");


        //接收计数信号量，每次接收200ms，直到接收失败才结束循环
        int sem_count = 0;
        do
        {
            ret = xSemaphoreTake(s_testCountSem,pdMS_TO_TICKS(200));
            if(ret==pdTRUE)
            {
                ESP_LOGI(TAG,"take count semaphore,count:%d\r\n",++sem_count);
            }
        }while(ret ==pdTRUE);
        
        //无限等待互斥信号量，直到获取成功才返回，这里用法和二进制信号量极为类似
        ret = xSemaphoreTakeRecursive(s_testMuxSem,portMAX_DELAY);
        if(ret == pdTRUE)
            ESP_LOGI(TAG,"take Mutex semaphore");
    
    }

}

/** 初始化信号量例程

 * @param 无
 * @return 无
   */
   void rtos_sem_sample(void)
   {
    s_testBinSem = xSemaphoreCreateBinary();
    s_testCountSem = xSemaphoreCreateCounting(5,0);
    s_testMuxSem = xSemaphoreCreateMutex();
    xTaskCreatePinnedToCore(sem_taskA,"sem_taskA",2048,NULL,3,NULL,1);
    xTaskCreatePinnedToCore(sem_taskB,"sem_taskB",2048,NULL,3,NULL,1);
   }

//事件组句柄
static EventGroupHandle_t s_testEvent;

/** 事件任务A，用于定时标记事件

 * @param 无
 * @return 无
   */
   void event_taskA(void* param)
   {
    while(1)
    {
        xEventGroupSetBits(s_testEvent,BIT0);
        vTaskDelay(pdMS_TO_TICKS(1000));
        xEventGroupSetBits(s_testEvent,BIT1);
        vTaskDelay(pdMS_TO_TICKS(1500));
    }
   }

/** 事件任务B，等待事件组中BIT0和BIT1位

 * @param 无
 * @return 无
   */
   void event_taskB(void* param)
   {
    EventBits_t ev;
    while(1)
    {
        ev = xEventGroupWaitBits(s_testEvent,BIT0|BIT1,pdTRUE,pdFALSE,portMAX_DELAY);
        if(ev & BIT0)
        {
            ESP_LOGI(TAG,"Event BIT0 set");
        }
        if(ev& BIT1)
        {
            ESP_LOGI(TAG,"Event BIT1 set");
        }
    }
   }

/** 事件例程初始化

 * @param 无
 * @return 无
   */
   void rtos_event_sample(void)
   {
    s_testEvent = xEventGroupCreate();
    xTaskCreatePinnedToCore(event_taskA,"event_taskA",2048,NULL,3,NULL,1);
    xTaskCreatePinnedToCore(event_taskB,"event_taskB",2048,NULL,3,NULL,1);
   }

//要使用任务通知，需要记录任务句柄
static TaskHandle_t s_notifyTaskAHandle;
static TaskHandle_t s_notifyTaskBHandle;

/** 任务通知A，用于定时向任务通知B直接传输数据

 * @param 无
 * @return 无
   */
   void notify_taskA(void* param)
   {
    uint32_t rec_val = 0;
    while(1)
    {
        if (xTaskNotifyWait(0x00, ULONG_MAX, &rec_val, pdMS_TO_TICKS(1000)) == pdTRUE)
        {
            ESP_LOGI(TAG,"receive notify value:%lu",rec_val);
        }
    }
   }

/** 任务通知B，实时接收任务通知A的数据

 * @param 无
 * @return 无
   */
   void notify_taskB(void* param)
   {
    int notify_val = 0;
    while(1)
    {
        xTaskNotify(s_notifyTaskAHandle, notify_val, eSetValueWithOverwrite);
        notify_val++;
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
   }

/** 任务通知例程初始化

 * @param 无
 * @return 无
   */
   void rtos_notify_sample(void)
   {
    xTaskCreatePinnedToCore(notify_taskA,"notify_taskA",2048,NULL,3,&s_notifyTaskAHandle,1);
    xTaskCreatePinnedToCore(notify_taskB,"notify_taskB",2048,NULL,3,&s_notifyTaskBHandle,1);
   }

//入口函数
void app_main(void)
{
    /*
    以下是每种freeRTOS特性的测试例程的初始化函数，建议每次只开一个，否则有太多打印影响体验
    */
    //rtos_task_sample();
    //rtos_queue_sample();
    rtos_sem_sample();
    //rtos_event_sample();
    //rtos_notify_sample();
}


```

### 原生的FreeRTOS和IDF版本的FreeRTOS的区别

1. 优先级问题，多核情况并不使用，因为有多个任务可同时运行
2. ESP-IDF自动创建空闲、定时器、app_main、IPC、ESP定时器
3. ESP-IDF不适用原生FreeRTOS的内存堆管理，实现了自己的堆
4. 创建任务使用xTaskCreatePinnedToCore()
5. 删除任务避免删除另外一个核的人物
6. 临界区使用自旋锁确保同步
7. 如果任务重用到浮点运算，则创建任务的时候必须指定具体运行在哪个核上，不能由系统自动安排

总的来说，建议如下：

1. 程序应用开发创建任务指定内核，建议不要使用tskNO_AFFINITY
2. 通常，负责处理无线网络的任务(例如WiFi或蓝牙)，将被固定到CPU0(因此名称PRO_CPU)，而处理应用程序其余部分的任务将被固定到CPU1(因此名称为APP_CPU)

# 数据结构

我们可以逐步推导这个公式，来理解如何得到 $D(N) = \frac{2}{N} \left( \sum_{j=0}^{N-1} D(j) \right) + N - 1$。

### 1. 基本设定

首先，$D(N)$ 是指包含 $N$ 个节点的树的内部路径长度。我们定义的递归关系是：

- $D(i)$ 是树中某个节点的左子树的路径长度。
- $D(N - i - 1)$ 是该节点右子树的路径长度。

公式 $D(N) = D(i) + D(N - i - 1) + N - 1$ 的含义是树的总路径长度由左右子树的路径长度之和，加上根节点到两个子树的连接边所需的深度。

### 2. 递归结构

我们将树看作是通过一个根节点分为左右两个子树。根据递归的方式，树的总深度是左右子树深度的和再加上一些常数项。具体来说：

- 左子树有 $i$ 个节点，右子树有 $N - i - 1$ 个节点，树的路径长度等于：

  D(N)=D(i)+D(N−i−1)+(N−1)D(N) = D(i) + D(N - i - 1) + (N - 1)

  其中 $(N - 1)$ 是因为根节点与左右子树之间有一个连接边。

### 3. 期望值的推导

为了得出期望值 $D(N)$，我们需要计算树的总路径长度的期望值。假设所有的 $i$ 值（从 $0$ 到 $N-1$）都可能出现，我们可以对它们进行平均：

$\mathbb{E}[D(N)] = \frac{1}{N} \sum_{i=0}^{N-1} D(i) + N - 1$

这里 $\sum_{i=0}^{N-1} D(i)$ 是所有子树路径长度之和，$\frac{1}{N}$ 是每个子树的平均贡献。

### 4. 求和项的倍数

进一步，我们注意到每个子树的路径长度贡献实际上有一个加权因子。每次递归都会有一个因子 $2$ 乘在期望值上（因为左右子树的深度之和会影响总路径长度），于是得到了：

$D(N) = \frac{2}{N} \left( \sum_{i=0}^{N-1} D(i) \right) + N - 1$

### 5. 解释

- **期望值**：通过将所有子树的深度加权平均后，我们得到了树的总深度的期望值。
- **$N - 1$**：这部分是由于树的根节点与左右子树之间的连接边造成的额外深度。

所以，最终得出的公式 $D(N) = \frac{2}{N} \left( \sum_{j=0}^{N-1} D(j) \right) + N - 1$ 是通过对每个子树的路径长度加权求和，并结合树的结构，得出树的总路径长度的期望值。

### 总结

这个公式的核心是递归关系和平均值的计算，通过对所有子树的深度进行加权求和，得出了树的期望深度。

让我们详细解析每次递归中的 $2$ 和 $N - 1$ 的出现。

### 1. 为什么每次递归有一个系数 2？

首先，公式中的 $D(N) = D(i) + D(N - i - 1) + N - 1$ 表示树的深度是由根节点到左子树和右子树的深度之和，再加上根节点与左右子树之间的连接边。因此，递归过程中涉及到 **左子树和右子树的深度**。

每个树的深度 $D(N)$ 是通过将一个树分为左子树和右子树来计算的。每次递归时，我们考虑到两棵子树的深度，左子树的深度是 $D(i)$，右子树的深度是 $D(N - i - 1)$。由于递归会在每个层次分别处理左子树和右子树，所以最终在期望值计算中会有一个 **2** 的因子。

更具体地说，计算时对于树中每个可能的分支（左子树和右子树），递归会分别计算左右两部分的深度。由于每次递归处理的是树的左右两部分（子树），因此我们最终得到的结果包含了左右两部分的贡献。为了把每个子树的贡献加权平均，最终的期望值有了一个 **2** 的因子，表示每次递归涉及到左右两个部分。

### 2. 为什么有 $N - 1$？

接下来说说公式中的 $N - 1$。

在递归关系中，公式 $D(N) = D(i) + D(N - i - 1) + N - 1$ 代表了树的总深度。这个公式中的 $N - 1$ 其实是 **根节点和左右子树之间的连接边的深度**。

在树的结构中，根节点连接了左右子树。对于一个包含 $N$ 个节点的树：

- **根节点** 是树的最上层节点，它与左子树和右子树之间各有一条边。
- 连接左子树和右子树的这条边的深度为 1（即树的根节点到左、右子树的边）。

因此，根节点到左右子树的两条边总共增加了一个额外的深度值，正好是 **$N - 1$**（即减去 1，因为这条连接边在递归计算的深度中计算了一次）。

### 3. 期望值的推导

在推导期望值时，公式中的 $\frac{2}{N}$ 是通过考虑 **每一个可能的子树** 来计算的。因为每个子树的深度 $D(i)$ 会影响树的整体深度（每个子树的深度在不同的分割点时变化），而我们需要计算这些不同分割点的平均值。

所以，递归的公式中 $2$ 和 $N - 1$ 分别表示：

- **2**：表示每次递归计算时左子树和右子树的深度都被考虑（即左右两个部分都需要计算）。
- **$N - 1$**：表示在树的根节点与左右子树之间的连接边的深度，它会影响树的总深度。

在这段文字中提到的 **$2^k - 1$** 是用来描述一个完全平衡二叉树（perfectly balanced tree）中节点的数量。

### 为什么是 $2^k - 1$？

1. **完全平衡二叉树的定义**：

   - 在一棵完全平衡的二叉树中，所有的叶子节点都位于同一层级，而每个节点都有零个或两个子节点。
   - 树的高度 $k$ 是指从根节点到叶子节点的最大路径长度（不包括根节点）。

2. **节点数量的推导**：

   - 对于高度为 $k$ 的完全平衡二叉树，假设树的每一层都是满的，也就是说每一层都有节点。
   - **第 0 层**（根节点）有 $1$ 个节点。
   - **第 1 层**有 $2$ 个节点。
   - **第 2 层**有 $4$ 个节点。
   - ...
   - **第 $k-1$ 层**有 $2^{k-1}$ 个节点。

   这样，树的总节点数就是所有层的节点数之和：

   1+2+4+8+⋯+2k−11 + 2 + 4 + 8 + \dots + 2^{k-1}

3. **求和公式**： 这个和是一个等比数列的求和。等比数列的求和公式是：

   S=a1⋅(rn−1)r−1S = \frac{a_1 \cdot (r^n - 1)}{r - 1}

   其中：

   - $a_1 = 1$ 是首项，
   - $r = 2$ 是公比，
   - $n = k$ 是项数。

   将这些值代入公式，得到：

   S=1⋅(2k−1)2−1=2k−1S = \frac{1 \cdot (2^k - 1)}{2 - 1} = 2^k - 1

   所以，总的节点数为 $2^k - 1$。

### 结论

在高度为 $k$ 的完全平衡二叉树中，节点的数量为 $2^k - 1$。这是因为每一层的节点数是指数级增长的，最终通过累加得到总节点数。
