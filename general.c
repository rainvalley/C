#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"general.h"
#include"admin.h"

//����ͨ��
int Update_info(char* id,char* old_password,char* new_password) 
{
	//����id��old_password,new_password������old_password��ȷʱ�Ż��޸�����
	FILE* fp = fopen("user.txt", "r+");
	FILE* fp_temp = fopen("temp.txt", "w+");
	char id_temp[15];
	char password_temp[32];
	int permission;
	int flag=0;
	while (fscanf(fp, "%s %s %d", id_temp, password_temp, &permission) != -1)
	{
		if (strcmp(id, id_temp) != 0)//��ID��ƥ��ʱ��������д��fp_temp
		{
			fprintf(fp_temp, "%s %s %d\n", id_temp, password_temp, permission);
		}
		else if (strcmp(password_temp,old_password)==0)//����������ȷʱ����������
		{
			fprintf(fp_temp, "%s %s %d\n", id_temp,new_password,permission);
			flag = 1;
		}
		else//�������벻��ȷʱ�����ı�ԭ����
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


//����ͨ��
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
//	int bed_id[6];//��¼���д�λ��Ϣ
//	int blank_bed_id[6];//��¼�մ���Ϣ
//	int count = 0;//ѭ������������¼bed_id����
//	int count_blank = 0;
//	int flag = 0;//ch��bed_idƥ�����
//	int flag_check = 0;
//	FILE* fp = fopen("data.txt", "r+");
//	//���ļ����������ƥ������ݶ���bed_id
//	while (fscanf(fp, "%s %s %s %s %s %s %s %s", stu.id, stu.name, stu.phone, stu.dorm_id, stu.bed_id, stu.head_id, stu.head_name, stu.head_phone) != -1)
//	{
//		if (strcmp(dorm_id, stu.dorm_id) == 0)
//		{
//			sscanf(stu.bed_id, "%d", &bed_id[count]);//�������ض���Ϊint���ͣ������浽bed_id��
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