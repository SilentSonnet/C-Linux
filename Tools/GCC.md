# GCC常用命令

| 知识点      | 说明                     | 示例                                |
| ----------- | ------------------------ | ----------------------------------- |
| -o          | 指定输出文件名           | gcc -o hello hello.c                |
| -O1/-O2/-O3 | 优化级别（代码性能优化） | gcc -O2 main.c                      |
| -g          | 生成调试信息（用于GDB）  | gcc -g program.c                    |
| -Wall       | 启用所有警告             | gcc -Wall main.c                    |
| -I          | 添加头文件搜索路径       | gcc -I/usr/local/include main.c     |
| -L          | 添加库文件搜索路径       | gcc -L/usr/local/lib -Imylib main.c |
| -l          | 链接库文件               | gcc -lpthread main.c                |
| -D          | 定义宏                   | gcc -DDEBUG main.c                  |
| -S          | 生成汇编代码             | gcc -S main.c                       |
| -E          | 仅执行预处理             | gcc -E main.c > preprocessed.c      |
| -shared     | 生成动态库（.so）        | gcc -shared -o libfoo.so foo.c      |
| -static     | 静态链接                 | gcc -static main.c                  |