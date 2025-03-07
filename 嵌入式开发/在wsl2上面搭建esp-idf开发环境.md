# WSL2搭建ESP-IDF开发环境

## WSL环境搭建

### 1.安装

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

### 2.更换源

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



### 3.ssh配置

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

## ESP-IDF

### 1.环境安装

```bash
#编译 ESP-IDF 需要以下软件包
sudo apt-get install git wget flex bison gperf python3 python3-venv python3-setuptools cmake ninja-build ccache libffi-dev libssl-dev dfu-util libusb-1.0-0
```



### 2.获取ESP-IDF

```bash
#用户目录下创建esp文件夹，从git仓库拉取V5.0版本至此目录下
mkdir -p ~/esp
cd ~/esp
git clone -b release/v5.0 --recursive https://github.com/espressif/esp-idf.git
```



### 3.设置工具

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



### 4.设置环境变量

```bash
# 注意设置环境变量后才可以正常使用idf开发
. $HOME/esp/esp-idf/export.sh
```

### 5.hello world工程示例

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



## 常用工具

### Windows usbipd命令

​	因为wsl2无法直接使用Windows下的串口，借助开源usbipd-win项目来实现串口烧录。

#### usbipd介绍

​	usbipd是一个用于管理USB/IP(USB over IP)服务的命令行工具，可以在Windows下使用。USB/IP是一种协议，允许通过网络共享USB设备。usbipd工具允许用户在Windows上共享USB设备，使其他计算机能够通过网络访问这些设备。

#### Windows下安装

​	仓库下载安装或者通过powershell的Windows程序包管理器程序(winget)来安装

```powershell
#使用 winget 工具安装和管理应用程序安装  取消--interactive可能导致立即重启
winget install --interactive --exact dorssel.usbipd-win
```

#### wsl2下安装

https://github.com/dorssel/usbipd-win/wiki/WSL-support 参考链接

在wsl2下面需要下列命令

```powershell
sudo apt install linux-tools-virtual hwdata
sudo update-alternatives --install /usr/local/bin/usbip usbip `ls /usr/lib/linux-tools/*/usbip | tail -n1` 20
```

#### 具体使用

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



#### 基本命令参数

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

