# Git

​	首先，需要明确的是，Git和Github并不是一个东西，Git是一个代码版本管理工具，而Github是在网络上提供Git托管任务的一个服务，当然Github能做的事情远不止代码托管，可以认为Github是基于Git之上的。



​	因此使用Github也需要先安装Git，我目前只使用Win11平台，因此

```bash
git config --global user.name "username"
git config --global user.email "emali@example.com"
```

​	使用了这两条命令之后，用户名和邮箱号就会被保存在.gitconfig文件中

​	可以使用vim来进行查看

```bash
vim ~/.gitconfig
```

​	

```bash
ssh-keygen -t res -C "email@example.com"
```

```bash
cat ~/.ssh/id_rsa.pub
```

```bash
ssh -T git@github.com
```

然后就可以查看ssh秘钥，并可以在Github上面添加秘钥