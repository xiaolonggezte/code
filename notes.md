# Linux && shell


## 
- 林纳斯·托瓦兹 Linus Torvalds   贝尔实验室
- 一切皆文件
- FHS 标准：
- chmod
    u   +/- r/w/x
    g
    o
- chown 改变文件所有者，组
- ls -a 包括隐藏文件

- more,less 分页查看大文件

- which 查找可执行文件位置
- whereis 使用数据库 快，不实时
- locate 使用数据库，快，不实时
- find 实时查找

- 重定向 > 
- 管道 | 

- grep 查找
输出含‘root’全部输出
grep root /etc/passwd
正则
grep -E
-o 抽取匹配的部分

抽取上下文多少行
-a
-A
-



- sed 编辑，可以不打开文件进行编辑
sed '2d' example 删除第2行
....
- awk 分析处理
NR 总行
NF 总列
$0 当前行的所有列
$数字第几行

BEGIN{acton}
pattern{action}
……
END{action}

awk -F: 


- $# 传递给函数的参数个数
- $* 所有传递给函数的参数
- $n 第n个参数
- $? 函数的返回值





