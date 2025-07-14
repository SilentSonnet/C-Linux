# Makefile常用命令

| 知识点                 | 说明                                         | 示例                                                  |
| ---------------------- | -------------------------------------------- | ----------------------------------------------------- |
| Makefile基础语法       |                                              |                                                       |
| 规则定义               | 目标: 依赖 → 命令                            | app: main.cpp utils.cpp g++ -o app main.cpp utils.cpp |
| 变量定义与引用         | 使用VAR = value和$$VAR                       | CC = g++ CFLAGS = -Wall -O2                           |
| 自动变量               | $@（目标）、$^（所有依赖）、$<（第一个依赖） | app: main.o utils.o $(CC) $^ -o $@                    |
| 伪目标（Phony Target） | 声明不生成文件的命令（如 clean）             | .PHONY: clean clean: rm -f *.o app                    |
| 条件判断               | 使用ifeq/else/endif                          | ifeq ($(DEBUG),1) CFLAGS += -g endif                  |
| 函数调用               | 如$(wildcard *.cpp)获取文件列表              | SRC = $(wildcard src/*.cpp)                           |



# Cmake常用命令



| CMake基础语法  | 说明                                | 示例                                                         |
| -------------- | ----------------------------------- | ------------------------------------------------------------ |
| 项目声明       | project()和cmake_minimum_required() | cmake_minimum_required(VERSION 3.10) project(MyApp)          |
| 生成可执行文件 | add_executable()                    | add_executable(app main.cpp utils.cpp)                       |
| 生成库文件     | add_library()                       | add_library(mylib STATIC mylib.cpp)                          |
| 链接库         | target_link_libraries()             | target_link_libraries(app mylib pthread)                     |
| 设置变量       | set()和option()                     | set(CMAKE_CXX_STANDARD 17) option(BUILD_TESTS "Build tests" ON) |
| 包含目录       | target_include_directories()        | target_include_directories(app PUBLIC include/)              |
| 条件语句       | if()/else()/endif()                 | if(UNIX) add_definitions(-DLINUX) endif()                    |
| 查找依赖包     | find_package()                      | find_package(OpenSSL REQUIRED)                               |
| 安装规则       | install()                           | install(TARGETS app DESTINATION bin)                         |