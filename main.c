#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"hash.h"
#include"admin.h"
#include"general.h"
#include"expand.h"

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
	Check_blank("A02S412");
	//char str[32];
	//char sha256[65];
	//scanf("%s", str);
	//hash(str, sizeof(str) - 1,sha256);  // sizeof()计算的结果包含了末尾的'\0'应减1
	//puts(sha256);
	//return 0;
	/*char id[20];
	char old_passwd[50];
	char new_passwd[32];
	scanf("%s %s %s", id, old_passwd,new_passwd);
	Update_info(id, old_passwd,new_passwd);*/
	/*Reset_password("2098");*/
	/*while (1)
	{
		scanf("%s %s", id, passwd);
		if (Check_permission(id, passwd, 1))
		{
			printf("Correct!");
		}
		else
		{
			printf("Wrong!");
		}
	}*/
	/*Create_general_user(id, passwd);*/
	/*Delete_general_user(id);*/
	//Reset_password(id);
	//Delete_stu(id);
	/*int method;
	char info[20];
	while (1)
	{
		scanf("%d %s", &method, info);
		Query_stu(method, info);
	}*/
	/*struct student stu;
	scanf("%s %s %s %s %s %s %s %s", stu.id, stu.name, stu.phone, stu.dorm_id, stu.bed_id, stu.head_id, stu.head_name, stu.head_phone);
	Update_stu(stu);*/
	/*Create_stu(stu);*/
	//View_data();
}