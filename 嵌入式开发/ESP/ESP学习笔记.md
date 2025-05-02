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