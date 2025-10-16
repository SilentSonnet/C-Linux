# Linux常用命令

| 知识点 | 说明                      | 示例                                |
|--------|---------------------------|-------------------------------------|
| pwd    | 显示当前工作目录           | pwd                                 |
| cd     | 切换目录                   | cd /home/user                       |
| ls     | 列出目录内容               | ls -la （显示详细列表，包括隐藏文件）|
| cp     | 复制文件或目录             | cp src.txt dest.txt                 |
| mv     | 移动或重命名文件           | mv old.txt new.txt                  |
| rm     | 删除文件或目录             | rm -rf dir/ （强制递归删除目录）     |
| cat    | 查看文件内容               | cat file.txt                        |
| grep   | 文本搜索工具               | grep "error" log.txt                |
| find   | 查找文件                   | find / -name "*.cpp"                |
| chmod  | 修改文件权限               | chmod 755 script.sh                 |
| chown  | 修改文件所有者             | chown user:group file.txt           |
| ps     | 查看进程状态               | ps aux |
| top/htop | 实时监控进程和系统资源    | top （监控CPU耗时）                 |
| kill   | 终止进程                   | kill -9 1234 （强制终止PID 1234）    |
| tar    | 打包/解压文件               | tar -czvf archive.tar.gz dir/       |
| ssh    | 远程登录服务器             | ssh user@192.168.1.1                |
| scp    | 安全复制文件               | scp file.txt user@host:/path/       |
| curl/wget | 下载文件或测试HTTP请求   | curl -O http://example.com/file.zip |
| man    | 查看命令手册               | man ls                              |
| \| | （管道） | 将前一个命令的输出传递给下一个命令的输入 |
