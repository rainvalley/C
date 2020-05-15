![宿舍管理系统](https://pic.rmb.bdstatic.com/bjh/8ae011a070681c37857347d4b731e640.png)
***C语言大作业——基于C/C#的WPF宿舍管理系统***
>	2020.5.13第五版
* 发布一版Release

>	2020.5.10第四版
* WPF页面绘制完毕，部分功能由于函数返回值的关系未成功移植
* 结构体由DLL传入的方法我仍然不会）

>	2020.5.9第三版
* 初步绘制WPF界面
* 整理文件结构，DLL文件位于bin\Debug，C源文件位于C Sources

>   2020.5.8第二版：
* 基本功能已完善，待优化界面，正在开发WPF应用
* 考虑在C#中调用C的DLL库

>	2020.4.25第一版：
* 1，学生住宿信息注册与更改无法使用
* 2，hash函数的实现未添加
* 3，对输入信息的判断未编写完成
* 4，expand文件内的函数未编写

# 实现内容
* 管理员与普通用户的登录
* 普通用户信息的增删改
* 住宿信息的增删查改
* 住宿信息的浏览
* 住宿信息的多种方式查询
* 删除指定年份的学生信息
# 相关技术
* C的多文件编程及与C#结合的调用
* Windows下DLL的生成与调用
* WPF窗口布局与前后端代码绑定
* Hash函数（SHA-256）在用户密码中的使用
#
# 编程环境
* Visual Studio 2019 Community (V142)
* Win10 1809 64bit
* Target Platform: X86 
* Target Framework: .Net Framework 4.7.2
# 测试环境
* Win10 Edu 1809 64bit (3840*2160)
* Win10 Edu 1909 64bit (3840*2160)
* Win7 Pro SP1 32bit (1024*768)，需安装 .Net 4.7.2环境
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
# 函数
* int Check_permission(char* id, char* password,int type) 校验用户权限，不通过返回0，否则返回1。
* int Create_general_user(char* id, char* password) 创建普通用户账号，若账号已存在返回0，创建成功返回1。
* int Delete_general_user(char* id) 删除普通用户账号，若账号不存在返回0，否则删除成功返回1。
* int Reset_password(char* id) 重置普通用户账号，若账号不存在则返回0，否则返回1。
* int Create_stu(struct student stu) 创建学生住宿信息，若该学生已存在则返回0，否则返回1。
* int Update_stu(struct student stu) 更新学生住宿信息，若该学生不存在则返回0，否则返回1。
* int Delete_stu(char* id) 删除学生信息，若该学生不存在则返回0，否则返回1。
* int Query_stu(int method, char* info) 查询学生住宿信息，查询不成功返回0，否则返回1。在C#调用此函数时，将控制流输出到log.txt。
* void View_data() 在Console中打印全部学生的信息，无返回值。
* int Update_info(char* id,char* old_password,char* new_password) 更改用户账号密码，当ID，旧密码正确且匹配时返回1，否则返回0。
* void Check_dorm(char* dorm_id) 以宿舍号查询学生住宿信息，无返回值。
* extern char* hash(const char* str) 用于计算密码的SHA-256值，返回值为SHA-256的字符串指针。

