#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"general.h"
#include"admin.h"

//测试通过
int Update_info(char* id,char* old_password,char* new_password) 
{
	//输入id，old_password,new_password，仅当old_password正确时才会修改密码
	FILE* fp = fopen("user.txt", "r+");
	FILE* fp_temp = fopen("temp.txt", "w+");
	char id_temp[15];
	char password_temp[32];
	int permission;
	int flag=0;
	while (fscanf(fp, "%s %s %d", id_temp, password_temp, &permission) != -1)
	{
		if (strcmp(id, id_temp) != 0)//当ID不匹配时，将数据写入fp_temp
		{
			fprintf(fp_temp, "%s %s %d\n", id_temp, password_temp, permission);
		}
		else if (strcmp(password_temp,old_password)==0)//当老密码正确时，更新密码
		{
			fprintf(fp_temp, "%s %s %d\n", id_temp,new_password,permission);
			flag = 1;
		}
		else//当老密码不正确时，不改变原密码
		{
			fprintf(fp_temp, "%s %s %d\n", id_temp, password_temp, permission);
		}
	}
	fclose(fp);
	fclose(fp_temp);
	remove("user.txt");
	rename("temp.txt", "user.txt");
	return 1;
}


//测试通过
void Check_dorm(char* dorm_id)
{
	Query_stu(1, dorm_id);
}

//int Check_blank(char* dorm_id)
//{
//	struct student {
//		char id[15];
//		char name[5];
//		char phone[15];
//		char dorm_id[10];
//		char bed_id[2];
//		char head_id[15];
//		char head_name[5];
//		char head_phone[15];
//	};
//	struct student stu;
//	int bed_id[6];//记录已有床位信息
//	int blank_bed_id[6];//记录空床信息
//	int count = 0;//循环计数，并记录bed_id长度
//	int count_blank = 0;
//	int flag = 0;//ch与bed_id匹配与否
//	int flag_check = 0;
//	FILE* fp = fopen("data.txt", "r+");
//	//将文件内与宿舍号匹配的数据读入bed_id
//	while (fscanf(fp, "%s %s %s %s %s %s %s %s", stu.id, stu.name, stu.phone, stu.dorm_id, stu.bed_id, stu.head_id, stu.head_name, stu.head_phone) != -1)
//	{
//		if (strcmp(dorm_id, stu.dorm_id) == 0)
//		{
//			sscanf(stu.bed_id, "%d", &bed_id[count]);//将床号重定向为int类型，并储存到bed_id内
//			flag_check = 1;
//			count++;
//		}
//	};
//
//	if (flag_check==0)
//	{
//		return 0;
//	}
//	else
//	{
//		printf("%d\n", count);
//		for (int i = 1; i <= 6; i++)
//		{
//			for (int j = 0; j < count; j++)
//			{
//				if (bed_id[j] == i)
//				{
//					flag = 1;
//				}
//			}
//			if (flag==0)
//			{
//				blank_bed_id[count_blank] = i;
//				printf("%d\n", bed_id[count_blank]);
//				count_blank++;
//			}
//			flag = 0;
//		}
//		return 1;
//	}
//}