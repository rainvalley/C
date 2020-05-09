***C语言大作业——宿舍管理系统***
>   2020.5.8第二版：
* 基本功能已完善，待优化界面，正在开发WPF应用。
* 考虑在C#中调用C的DLL库。

>	2020.4.25第一版：
* 1，学生住宿信息注册与更改无法使用
* 2，hash函数的实现未添加
* 3，对输入信息的判断未编写完成
* 4，expand文件内的函数未编写

# 环境
* Visual Studio 2019 Community (V142)
* Win10 1809 64bit
* Target Platform:X86 
# 文件
## 源文件
* main.c 主函数位置，程序主体逻辑处理
* admin.c 系统管理员处理模块
* general.c 普通用户管理模块
* hash.c 哈希函数生成模块，使用SHA-256
* expand.c 程序扩展函数模块
## 资源文件
* data.txt 储存学生住宿信息
* user.txt 储存用户信息 0代表管理员，1代表普通用户
## 头文件
储存函数的定义
# 数据结构
住宿信息的数据结构：
```
struct student {
	char id[15];
	char name[5];
	char phone[15];
	char dorm_id[10];
	char bed_id[2];
	char head_id[15];
	char head_name[5];
	char head_phone[15];
};
```
用户数据的数据结构：
```
char id[15];
char passwd[65];
int permission;
```
