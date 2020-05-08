/*
	2020.4.25第一版：
	1，学生住宿信息注册与更改无法使用
	2，hash函数的实现未添加
	3，对输入信息的判断未编写完成
	4，expand文件内的函数未编写
*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"hash.h"
#include"admin.h"
#include"general.h"
#include"expand.h"

void admin_model(char* id);//管理员管理模块
void admin_model_user();//管理员的用户信息管理模块
void admin_model_stu();//管理员的住宿信息管理模块
void general_model(char* id);//普通用户管理模块
void general_model_user(char* id);//普通用户用户信息管理模块
void general_model_stu();//普通用户住宿信息管理模块
char* hash(char* str);//HASH函数处理密码
char sha256[65];//全局变量，储存Hash后的内容


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

int main()
{	
	struct student stu;
	int select;
	char id[15];
	char password[65];
	printf("=============================\n");
	printf("欢迎进入学生宿舍管理系统，请选择您的身份\n");
	printf("0-管理员\t1-普通用户\n");
	printf("=============================\n");
	scanf("%d", &select);
	printf("请输入用户ID与密码\n");
	scanf("%s %s", id, password);
	if (Check_permission(id,hash(password),select))
	{
		printf("密码校验正确\n");
		if (select==0)
		{
			admin_model(id);//进入管理员模块
		}
		else
		{
			general_model(id);//进入普通用户模块
		}
	}
	else
	{
		printf("密码或ID输入错误，请重新输入\n");
	}

}

char* hash(char* str)
{
	return(hash_original(str, sizeof(str) - 1, sha256));
}

void admin_model(char* id)
{
	int select;
	printf("=============================\n");
	printf("欢迎%s\n",id);
	printf("请选择您需要管理的信息：\n1-用户信息\t2-住宿信息\t3-退出程序\n");
	printf("=============================\n");
	scanf("%d", &select);
	if (select==1)
	{
		admin_model_user();//进入管理员的用户管理
	}
	else if (select==2)
	{
		admin_model_stu();//进入管理员的住宿信息管理
	}
	else
	{
		exit(0);
	}
}

void admin_model_user()
{
	int select;
	char id[15];
	char password[65];
	while (1)
	{
		printf("=============================\n");
		printf("请选择您需要管理的信息：\n1-创建普通用户账号\t2-删除普通用户账号\t3-重置普通用户账号\t4-退出程序\n");
		printf("=============================\n");
		scanf("%d", &select);
		switch (select)
		{
		case 1:
			printf("请输入需要创建的用户ID与密码\n");
			scanf("%s %s", id, password);
			Create_general_user(id, password);
			break;
		case 2:
			Delete_general_user("2098");
			printf("请输入需要删除的用户ID\n");
			scanf("%s", id);
			printf("%s", id);
			Delete_general_user(id);
			break;
		case 3:
			printf("请输入需要重置密码的用户ID\n");
			scanf("%s", id);
			Reset_password(id);
			break;
		case 4:
			exit(0);
			break;
		}
	}
	
}
void admin_model_stu()
{
	int select;
	int method;
	char* info[15];
	char id[15];
	char password[65];
	struct student stu;
	while (1)
	{
		printf("=============================\n");
		printf("请选择您需要管理的信息：\n1-输入学生住宿信息\t2-更新学生住宿信息\t3-删除学生住宿信息\t4-查询住宿信息\t5-浏览宿舍信息\t6-退出程序\n");
		printf("=============================\n");
		scanf("%d", &select);
		switch (select)
		{
		//这俩还不能用，已修正，删除\n
		case 1:
			printf("请输入需要创建的学生详细信息，包括学号，姓名，电话号码，宿舍号，床位号，寝室长学号，寝室长姓名，寝室长电话\n");
			scanf("%s %s %s %s %s %s %s %s", stu.id, stu.name, stu.phone, stu.dorm_id, stu.bed_id, stu.head_id, stu.head_name, stu.head_phone);
			Create_stu(stu);
			break;
		case 2:
			printf("请输入需要更新的学生详细信息，包括学号，姓名，电话号码，宿舍号，床位号，寝室长学号，寝室长姓名，寝室长电话\n");
			scanf("%s %s %s %s %s %s %s %s", stu.id, stu.name, stu.phone, stu.dorm_id, stu.bed_id, stu.head_id, stu.head_name, stu.head_phone);
			Update_stu(stu);
			break;
		case 3:
			printf("请输入需要删除的学生学号\n");
			scanf("%s", id);
			Delete_stu(id);
			break;
		case 4:
			printf("请输入查询方法与相关信息：\n暂定四种查询方法：1-按宿舍号精确查找，2-按寝室长学号查找，3-按寝室长电话查找，4-按照学生本人学号查询\n");
			scanf("%d %s",&method,info);
			printf("您查询的学生信息如下：\n");
			Query_stu(method, info);
			break;
		case 5:
			printf("宿舍住宿信息如下：\n");
			View_data();
			break;
		case 6:
			exit(0);
			break;
		}
	}
}




void general_model(char* id)
{
	int select;
	while (1)
	{
		printf("=============================\n");
		printf("欢迎%s\n", id);
		printf("请选择您需要管理的信息：\n1-用户信息\t2-住宿信息\t3-退出程序\n");
		printf("=============================\n");
		scanf("%d", &select);
		if (select == 1)
		{
			general_model_user(id);//进入普通用户的用户管理系统
		}
		else if (select == 2)
		{
			general_model_stu();//进入普通用户的住宿信息管理管理
		}
		else
		{
			exit(0);
		}
		}
	}

void general_model_user(char* id)
{
	char* old_password[65];
	char* new_password[65];
	printf("请输入您的原始密码与新密码\n");
	scanf("%s %s", old_password, new_password);
	if (Update_info(id, old_password, new_password))
	{
		printf("您的密码已修改\n");
	}
	else
	{
		printf("原始密码错误，密码未修改成功\n");
	}
	
}
void general_model_stu()
{
	int select;
	int method;
	char info[15];
	char dorm_id[10];
	printf("=============================\n");
	printf("请选择您需要管理的信息：\n1-查询学生住宿信息\t2-浏览宿舍入住情况\t3-退出程序\n");
	printf("=============================\n");
	scanf("%d", &select);
	switch (select)
	{
	case 1:
		printf("请输入查询方法与相关信息：\n暂定四种查询方法：1-按宿舍号精确查找，2-按寝室长学号查找，3-按寝室长电话查找，4-按照学生本人学号查询\n");
		scanf("%d %s", &method, info);
		printf("您查询的学生信息如下：\n");
		Query_stu(method, info);
		break;
	case 2:
		printf("请输入你需要查找的宿舍信息：\n");
		scanf("%s", dorm_id);
		printf("您查绚的宿舍入住情况如下：\n");
		Check_dorm(dorm_id);
	}
}