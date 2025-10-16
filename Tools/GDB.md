# GDB常用命令

| 知识点   | 说明                           | 示例                                     |
| -------- | ------------------------------ | ---------------------------------------- |
| gdb      | 调试工具（设置断点、查看变量） | gdb ./a.out → break main → run           |
| strace   | 跟踪系统调用和信号             | strace -e open,read ./program            |
| valgrind | 内存泄漏检测和性能分析         | valgrind --leak-check=yes ./a.out        |
| perf     | 性能分析工具（CPU、缓存等）    | perf record ./a.out → perf report        |
| lsof     | 列出打开的文件和网络连接       | lsof -i :8080 （查看占用8080端口的进程） |
| netstat  | 查看网络状态                   | netstat -tuln （显示监听中的端口）       |
| vmstat   | 监控系统资源（CPU、内存、IO）  | vmstat 1 （每秒刷新一次）                |
| iostat   | 监控磁盘I/O                    | iostat -x 2 （每2秒显示详细磁盘统计）    |
| tcpdump  | 捕获网络数据包                 | tcpdump -i eth0 port 80                  |