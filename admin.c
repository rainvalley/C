#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include"admin.h"

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


//测试通过，建议添加密码重复输入，达到规定次数exit功能
int Check_permission(char* id, char* password,int type)
{
	/*
	0为管理员，1为普通用户
	当id，password正确并且permission通过校验时，返回1，否则返回0
	*/
	FILE* fp = fopen("user.txt", "r");
	char true_id[15];
	char true_password[65];//将正确的id，password存入缓存区
	int permission;
	while (!feof(fp))
	{
		fscanf(fp, "%s %s %d", true_id,true_password,&permission);
		if ((!strcmp(id,true_id))&&(!strcmp(password,true_password)))//id与password校验正确
		{
			if (permission == type)//权限校验正确
			{
				return 1;
			}
		}
	}
	fclose(fp);
	return 0;
}


//测试通过
void Create_general_user(char* id, char* password)
{
	//创建普通用户
	FILE* fp = fopen("user.txt", "a");
	fprintf(fp, "%s %s 1\n", id, password);//创建普通用户时，权限默认设定为1
	fclose(fp);
}


//测试通过
int Delete_general_user(char* id)
{
	//删除普通用户，借助temp.txt拷贝，删除，重命名
	int flag = 0;
	FILE* fp = fopen("user.txt", "r+");
	FILE* fp_temp = fopen("temp.txt", "w+");
	char id_temp[15];
	char password_temp[65];
	int permission;
	//文件结尾重复打印，此处需要修改为其他判定方法，已修正。
	while (fscanf(fp, "%s %s %d", id_temp, password_temp, &permission)!=-1)
	{
		if (strcmp(id,id_temp)!=0)
		{
			fprintf(fp_temp,"%s %s %d\n",id_temp,password_temp,permission);
		}
		else if (strcmp(id,id_temp)==0)
		{
			flag = 1;
		}
	}
	fclose(fp);
	fclose(fp_temp);//关闭文件
	remove("user.txt");//删除源文件
	rename("temp.txt", "user.txt");//将temp重命名为user
}


//测试通过（这个密码要不换长一点？
void Reset_password(char* id)
{
	//用于重置普通用户密码，默认密码为serdtijkhgf（这是我脸在键盘上滚出来的）
	//实现方法参考Delete_general_user(char* id)函数
	FILE* fp = fopen("user.txt", "r+");
	FILE* fp_temp = fopen("temp.txt", "w+");
	char id_temp[15];
	char password_temp[65];
	int permission;
	while (fscanf(fp, "%s %s %d", id_temp, password_temp, &permission) != -1)
	{
		if (strcmp(id, id_temp) != 0)
		{
			fprintf(fp_temp, "%s %s %d\n", id_temp, password_temp, permission);
		}
		else
		{
			fprintf(fp_temp, "%s serdtijkhgf %d\n", id_temp,permission);
		}
	}
	fclose(fp);
	fclose(fp_temp);
	remove("user.txt");
	rename("temp.txt", "user.txt");
	
}


//测试通过
void Create_stu(struct student stu)
{
	//创建并写入学生信息
	FILE* fp = fopen("data.txt", "a+");
	fprintf(fp, "%s %s %s %s %s %s %s %s\n",stu.id,stu.name,stu.phone,stu.dorm_id,stu.bed_id,stu.head_id,stu.head_name,stu.head_phone );
	fclose(fp);
}


//测试通过
int Update_stu(struct student stu)
{
	//更新学生信息，当寻找到该学生返回1，否则返回0
	int flag = 0;
	struct student temp;//暂存缓冲区变量
	FILE* fp = fopen("data.txt", "r+");
	FILE* fp_temp = fopen("temp.txt", "w+");
	//当fscanf重定向读取的个数为-1时，结束循环
	while (fscanf(fp, "%s %s %s %s %s %s %s %s", temp.id, temp.name, temp.phone, temp.dorm_id, temp.bed_id, temp.head_id, temp.head_name, temp.head_phone) != -1)
	{
		if (strcmp(temp.id, stu.id) != 0)//当缓冲区学号与形参学号不同时，将原文本重定向到fp_temp
		{
			fprintf(fp_temp, "%s %s %s %s %s %s %s %s\n", temp.id, temp.name, temp.phone, temp.dorm_id, temp.bed_id, temp.head_id, temp.head_name, temp.head_phone);
		}
		else if (strcmp(temp.id, stu.id) == 0)//当缓冲区学号与形参学号相同时，将更新的内容写入到fp_temp
		{
			fprintf(fp_temp, "%s %s %s %s %s %s %s %s\n", stu.id, stu.name, stu.phone, stu.dorm_id, stu.bed_id, stu.head_id, stu.head_name, stu.head_phone);
			flag = 1;
		}
	}
	fclose(fp);
	fclose(fp_temp);
	remove("data.txt");//删除源文件
	rename("temp.txt", "data.txt");//将temp重命名为data
	return flag;
}


//测试通过
void Delete_stu(char* id)
{
	//删除学生信息,如果该学生不存在则不改变原来信息
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
	struct student stu;
	FILE* fp = fopen("data.txt", "r+");
	FILE* fp_temp = fopen("temp.txt", "w+");
	while (fscanf(fp, "%s %s %s %s %s %s %s %s", stu.id, stu.name, stu.phone, stu.dorm_id, stu.bed_id, stu.head_id, stu.head_name, stu.head_phone) != -1)
	{
		if (strcmp(id, stu.id) != 0)//将与查询学号id无关的学生信息写入fp_temp
		{
			fprintf(fp_temp, "%s %s %s %s %s %s %s %s\n", stu.id, stu.name, stu.phone, stu.dorm_id, stu.bed_id, stu.head_id, stu.head_name, stu.head_phone);
		}
	}
	fclose(fp);
	fclose(fp_temp);
	remove("data.txt");
	rename("temp.txt", "data.txt");
}


//测试通过
int Query_stu(int method, char* info)
{
	/*
	暂定四种查询方法：1-按宿舍号精确查找，2-按寝室长学号查找，3-按寝室长电话查找，4-按照学生本人学号查询
	查询成功时函数返回1，否则返回0
	*/
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
	struct student stu;
	int flag = 0;
	FILE* fp = fopen("data.txt", "r+");
	switch (method)
	{
	//按宿舍号精确查找
	case 1:
		while (fscanf(fp, "%s %s %s %s %s %s %s %s", stu.id, stu.name, stu.phone, stu.dorm_id, stu.bed_id, stu.head_id, stu.head_name, stu.head_phone) != -1)
		{
			if (strcmp(info,stu.dorm_id) == 0)
			{
				printf("该寝室全部学生信息如下：\n");
				printf("%s %s %s %s %s %s %s %s\n", stu.id, stu.name, stu.phone, stu.dorm_id, stu.bed_id, stu.head_id, stu.head_name, stu.head_phone);
				flag = 1;
			}
		};
	//按寝室长学号查找
	case 2:
		while (fscanf(fp, "%s %s %s %s %s %s %s %s", stu.id, stu.name, stu.phone, stu.dorm_id, stu.bed_id, stu.head_id, stu.head_name, stu.head_phone) != -1)
		{
			if (strcmp(info, stu.head_id) == 0)
			{
				printf("该寝室全部学生信息如下：\n");
				printf("%s %s %s %s %s %s %s %s\n", stu.id, stu.name, stu.phone, stu.dorm_id, stu.bed_id, stu.head_id, stu.head_name, stu.head_phone);
				flag = 1;
			}
		};
	//按寝室长电话查找
	case 3:
		while (fscanf(fp, "%s %s %s %s %s %s %s %s", stu.id, stu.name, stu.phone, stu.dorm_id, stu.bed_id, stu.head_id, stu.head_name, stu.head_phone) != -1)
		{
			if (strcmp(info, stu.head_phone) == 0)
			{
				printf("该寝室全部学生信息如下：\n");
				printf("%s %s %s %s %s %s %s %s\n", stu.id, stu.name, stu.phone, stu.dorm_id, stu.bed_id, stu.head_id, stu.head_name, stu.head_phone);
				flag = 1;
			}
		};
	//按照学生本人学号查找
	case 4:
		while (fscanf(fp, "%s %s %s %s %s %s %s %s", stu.id, stu.name, stu.phone, stu.dorm_id, stu.bed_id, stu.head_id, stu.head_name, stu.head_phone) != -1)
		{
			if (strcmp(info, stu.id) == 0)
			{
				printf("该学生信息如下：\n");
				printf("%s %s %s %s %s %s %s %s\n", stu.id, stu.name, stu.phone, stu.dorm_id, stu.bed_id, stu.head_id, stu.head_name, stu.head_phone);
				flag = 1;
			}
		};
	}
	fclose(fp);
	return flag;
}


//测试通过
void View_data()
{
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
	struct student stu;
	FILE* fp = fopen("data.txt", "r+");
	while (fscanf(fp, "%s %s %s %s %s %s %s %s", stu.id, stu.name, stu.phone, stu.dorm_id, stu.bed_id, stu.head_id, stu.head_name, stu.head_phone) != -1)
	{
		printf("%s %s %s %s %s %s %s %s\n", stu.id, stu.name, stu.phone, stu.dorm_id, stu.bed_id, stu.head_id, stu.head_name, stu.head_phone);
	}
	fclose(fp);
}