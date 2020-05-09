#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include"expand.h"
void Save_to_csv();
void Del_graduated(char* year)
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
		if (strncmp(year, stu.id,4) != 0)//将与查询学号id无关的学生信息写入fp_temp
		{
			fprintf(fp_temp, "%s %s %s %s %s %s %s %s\n", stu.id, stu.name, stu.phone, stu.dorm_id, stu.bed_id, stu.head_id, stu.head_name, stu.head_phone);
		}
	}
	fclose(fp);
	fclose(fp_temp);
	remove("data.txt");
	rename("temp.txt", "data.txt");
}