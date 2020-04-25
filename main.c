#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
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

	/*char id[20];
	char passwd[50];
	scanf("%s %s", id, passwd);*/
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
	struct student stu;
	scanf("%s %s %s %s %s %s %s %s\n", stu.id, stu.name, stu.phone, stu.dorm_id, stu.bed_id, stu.head_id, stu.head_name, stu.head_phone);
	Create_stu(stu);
	//View_data();
}