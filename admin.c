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


//����ͨ����������������ظ����룬�ﵽ�涨����exit����
int Check_permission(char* id, char* password,int type)
{
	/*
	0Ϊ����Ա��1Ϊ��ͨ�û�
	��id��password��ȷ����permissionͨ��У��ʱ������1�����򷵻�0
	*/
	FILE* fp = fopen("user.txt", "r");
	char true_id[15];
	char true_password[65];//����ȷ��id��password���뻺����
	int permission;
	while (!feof(fp))
	{
		fscanf(fp, "%s %s %d", true_id,true_password,&permission);
		if ((!strcmp(id,true_id))&&(!strcmp(password,true_password)))//id��passwordУ����ȷ
		{
			if (permission == type)//Ȩ��У����ȷ
			{
				return 1;
			}
		}
	}
	fclose(fp);
	return 0;
}


//����ͨ��
void Create_general_user(char* id, char* password)
{
	//������ͨ�û�
	FILE* fp = fopen("user.txt", "a");
	fprintf(fp, "%s %s 1\n", id, password);//������ͨ�û�ʱ��Ȩ��Ĭ���趨Ϊ1
	fclose(fp);
}


//����ͨ��
int Delete_general_user(char* id)
{
	//ɾ����ͨ�û�������temp.txt������ɾ����������
	int flag = 0;
	FILE* fp = fopen("user.txt", "r+");
	FILE* fp_temp = fopen("temp.txt", "w+");
	char id_temp[15];
	char password_temp[65];
	int permission;
	//�ļ���β�ظ���ӡ���˴���Ҫ�޸�Ϊ�����ж���������������
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
	fclose(fp_temp);//�ر��ļ�
	remove("user.txt");//ɾ��Դ�ļ�
	rename("temp.txt", "user.txt");//��temp������Ϊuser
}


//����ͨ�����������Ҫ������һ�㣿
void Reset_password(char* id)
{
	//����������ͨ�û����룬Ĭ������Ϊserdtijkhgf�����������ڼ����Ϲ������ģ�
	//ʵ�ַ����ο�Delete_general_user(char* id)����
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


//����ͨ��
void Create_stu(struct student stu)
{
	//������д��ѧ����Ϣ
	FILE* fp = fopen("data.txt", "a+");
	fprintf(fp, "%s %s %s %s %s %s %s %s\n",stu.id,stu.name,stu.phone,stu.dorm_id,stu.bed_id,stu.head_id,stu.head_name,stu.head_phone );
	fclose(fp);
}


//����ͨ��
int Update_stu(struct student stu)
{
	//����ѧ����Ϣ����Ѱ�ҵ���ѧ������1�����򷵻�0
	int flag = 0;
	struct student temp;//�ݴ滺��������
	FILE* fp = fopen("data.txt", "r+");
	FILE* fp_temp = fopen("temp.txt", "w+");
	//��fscanf�ض����ȡ�ĸ���Ϊ-1ʱ������ѭ��
	while (fscanf(fp, "%s %s %s %s %s %s %s %s", temp.id, temp.name, temp.phone, temp.dorm_id, temp.bed_id, temp.head_id, temp.head_name, temp.head_phone) != -1)
	{
		if (strcmp(temp.id, stu.id) != 0)//��������ѧ�����β�ѧ�Ų�ͬʱ����ԭ�ı��ض���fp_temp
		{
			fprintf(fp_temp, "%s %s %s %s %s %s %s %s\n", temp.id, temp.name, temp.phone, temp.dorm_id, temp.bed_id, temp.head_id, temp.head_name, temp.head_phone);
		}
		else if (strcmp(temp.id, stu.id) == 0)//��������ѧ�����β�ѧ����ͬʱ�������µ�����д�뵽fp_temp
		{
			fprintf(fp_temp, "%s %s %s %s %s %s %s %s\n", stu.id, stu.name, stu.phone, stu.dorm_id, stu.bed_id, stu.head_id, stu.head_name, stu.head_phone);
			flag = 1;
		}
	}
	fclose(fp);
	fclose(fp_temp);
	remove("data.txt");//ɾ��Դ�ļ�
	rename("temp.txt", "data.txt");//��temp������Ϊdata
	return flag;
}


//����ͨ��
void Delete_stu(char* id)
{
	//ɾ��ѧ����Ϣ,�����ѧ���������򲻸ı�ԭ����Ϣ
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
		if (strcmp(id, stu.id) != 0)//�����ѯѧ��id�޹ص�ѧ����Ϣд��fp_temp
		{
			fprintf(fp_temp, "%s %s %s %s %s %s %s %s\n", stu.id, stu.name, stu.phone, stu.dorm_id, stu.bed_id, stu.head_id, stu.head_name, stu.head_phone);
		}
	}
	fclose(fp);
	fclose(fp_temp);
	remove("data.txt");
	rename("temp.txt", "data.txt");
}


//����ͨ��
int Query_stu(int method, char* info)
{
	/*
	�ݶ����ֲ�ѯ������1-������ž�ȷ���ң�2-�����ҳ�ѧ�Ų��ң�3-�����ҳ��绰���ң�4-����ѧ������ѧ�Ų�ѯ
	��ѯ�ɹ�ʱ��������1�����򷵻�0
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
	//������ž�ȷ����
	case 1:
		while (fscanf(fp, "%s %s %s %s %s %s %s %s", stu.id, stu.name, stu.phone, stu.dorm_id, stu.bed_id, stu.head_id, stu.head_name, stu.head_phone) != -1)
		{
			if (strcmp(info,stu.dorm_id) == 0)
			{
				printf("������ȫ��ѧ����Ϣ���£�\n");
				printf("%s %s %s %s %s %s %s %s\n", stu.id, stu.name, stu.phone, stu.dorm_id, stu.bed_id, stu.head_id, stu.head_name, stu.head_phone);
				flag = 1;
			}
		};
	//�����ҳ�ѧ�Ų���
	case 2:
		while (fscanf(fp, "%s %s %s %s %s %s %s %s", stu.id, stu.name, stu.phone, stu.dorm_id, stu.bed_id, stu.head_id, stu.head_name, stu.head_phone) != -1)
		{
			if (strcmp(info, stu.head_id) == 0)
			{
				printf("������ȫ��ѧ����Ϣ���£�\n");
				printf("%s %s %s %s %s %s %s %s\n", stu.id, stu.name, stu.phone, stu.dorm_id, stu.bed_id, stu.head_id, stu.head_name, stu.head_phone);
				flag = 1;
			}
		};
	//�����ҳ��绰����
	case 3:
		while (fscanf(fp, "%s %s %s %s %s %s %s %s", stu.id, stu.name, stu.phone, stu.dorm_id, stu.bed_id, stu.head_id, stu.head_name, stu.head_phone) != -1)
		{
			if (strcmp(info, stu.head_phone) == 0)
			{
				printf("������ȫ��ѧ����Ϣ���£�\n");
				printf("%s %s %s %s %s %s %s %s\n", stu.id, stu.name, stu.phone, stu.dorm_id, stu.bed_id, stu.head_id, stu.head_name, stu.head_phone);
				flag = 1;
			}
		};
	//����ѧ������ѧ�Ų���
	case 4:
		while (fscanf(fp, "%s %s %s %s %s %s %s %s", stu.id, stu.name, stu.phone, stu.dorm_id, stu.bed_id, stu.head_id, stu.head_name, stu.head_phone) != -1)
		{
			if (strcmp(info, stu.id) == 0)
			{
				printf("��ѧ����Ϣ���£�\n");
				printf("%s %s %s %s %s %s %s %s\n", stu.id, stu.name, stu.phone, stu.dorm_id, stu.bed_id, stu.head_id, stu.head_name, stu.head_phone);
				flag = 1;
			}
		};
	}
	fclose(fp);
	return flag;
}


//����ͨ��
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