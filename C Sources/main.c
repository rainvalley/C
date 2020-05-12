/*
	2020.4.25��һ�棺
	1��ѧ��ס����Ϣע��������޷�ʹ��
	2��hash������ʵ��δ���
	3����������Ϣ���ж�δ��д���
	4��expand�ļ��ڵĺ���δ��д
*/

/*
	2020.5.8�ڶ��棺
	�������������ƣ����Ż����棬���ڿ���WPFӦ�á�
*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"hash.h"
#include"admin.h"
#include"general.h"
#include"expand.h"

void admin_model(char* id);//����Ա����ģ��
void admin_model_user();//����Ա���û���Ϣ����ģ��
void admin_model_stu();//����Ա��ס����Ϣ����ģ��
void general_model(char* id);//��ͨ�û�����ģ��
void general_model_user(char* id);//��ͨ�û��û���Ϣ����ģ��
void general_model_stu();//��ͨ�û�ס����Ϣ����ģ��


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
	printf("%s\n", hash("abc"));
	struct student stu;
	int select;
	char id[15];
	char password[65];
	printf("=============================\n");
	printf("��ӭ����ѧ���������ϵͳ����ѡ���������\n");
	printf("0-����Ա\t1-��ͨ�û�\n");
	printf("=============================\n");
	scanf("%d", &select);
	printf("�������û�ID������\n");
	scanf("%s %s", id, password);
	if (Check_permission(id,hash(password),select))
	{
		printf("����У����ȷ\n");
		if (select==0)
		{
			admin_model(id);//�������Աģ��
		}
		else
		{
			general_model(id);//������ͨ�û�ģ��
		}
	}
	else
	{
		printf("�����ID�����������������\n");
	}

}

void admin_model(char* id)
{
	int select;
	printf("=============================\n");
	printf("��ӭ%s\n",id);
	printf("��ѡ������Ҫ�������Ϣ��\n1-�û���Ϣ\t2-ס����Ϣ\t3-�˳�����\n");
	printf("=============================\n");
	scanf("%d", &select);
	if (select==1)
	{
		admin_model_user();//�������Ա���û�����
	}
	else if (select==2)
	{
		admin_model_stu();//�������Ա��ס����Ϣ����
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
		printf("��ѡ������Ҫ�������Ϣ��\n1-������ͨ�û��˺�\t2-ɾ����ͨ�û��˺�\t3-������ͨ�û��˺�\t4-�˳�����\n");
		printf("=============================\n");
		scanf("%d", &select);
		switch (select)
		{
		case 1:
			printf("��������Ҫ�������û�ID������\n");
			scanf("%s %s", id, password);
			printf("");
			if (Create_general_user(id, hash(password)))
			{
				printf("�˻��Ѵ�������ע�����Ʊ������롣\n");
			}
			else
			{
				printf("���˻��Ѵ��ڣ�����ʧ�ܣ��볢��ʹ������ID��\n");
			}
			break;
		case 2:
			printf("��������Ҫɾ�����û�ID\n");
			scanf("%s", id);
			printf("%s", id);
			if (Delete_general_user(id))
			{
				printf("�û�ɾ���ɹ���\n");
			}
			else
			{
				printf("���û������ڣ�����������û�ID��\n");
			}
			break;
		case 3:
			printf("��������Ҫ����������û�ID\n");
			scanf("%s", id);
			if (Reset_password(id))
			{
				printf("�����ѳɹ�����Ϊserdtijkhgf����ע�⼰ʱ�޸ģ�\n");
			}
			else
			{
				printf("��������ʧ�ܣ������û�ID\n");
			}
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
	char year[5];
	struct student stu;
	while (1)
	{
		printf("=============================\n");
		printf("��ѡ������Ҫ�������Ϣ��\n1-����ѧ��ס����Ϣ\t2-����ѧ��ס����Ϣ\t3-ɾ��ѧ��ס����Ϣ\t4-��ѯס����Ϣ\t5-���������Ϣ\t6-ɾ����ҵ����Ϣ\n7-�˳�����\n");
		printf("=============================\n");
		scanf("%d", &select);
		switch (select)
		{
		//�����������ã���������ɾ��\n
		case 1:
			printf("��������Ҫ������ѧ����ϸ��Ϣ������ѧ�ţ��������绰���룬����ţ���λ�ţ����ҳ�ѧ�ţ����ҳ����������ҳ��绰\n");
			scanf("%s %s %s %s %s %s %s %s", stu.id, stu.name, stu.phone, stu.dorm_id, stu.bed_id, stu.head_id, stu.head_name, stu.head_phone);
			if (Create_stu(stu))
			{
				printf("��ѧ��ס����Ϣ�Ѵ���\n");
			}
			else
			{
				printf("����ʧ�ܣ������ѧ����ѧ�ţ�\n");
			}
			break;
		case 2:
			printf("��������Ҫ���µ�ѧ����ϸ��Ϣ������ѧ�ţ��������绰���룬����ţ���λ�ţ����ҳ�ѧ�ţ����ҳ����������ҳ��绰\n");
			scanf("%s %s %s %s %s %s %s %s", stu.id, stu.name, stu.phone, stu.dorm_id, stu.bed_id, stu.head_id, stu.head_name, stu.head_phone);
			if (Update_stu(stu))
			{
				printf("��ѧ����Ϣ�Ѹ���\n");
			}
			else
			{
				printf("��ѧ�������ڣ����������ѧ�ţ�\n");
			}
			break;
		case 3:
			printf("��������Ҫɾ����ѧ��ѧ��\n");
			scanf("%s", id);
			if (Delete_stu(id))
			{
				printf("��ѧ����ɾ��\n");
			}
			else
			{
				printf("ѧ��ɾ������ʧ�ܣ����������ѧ�ţ�\n");
			}
			break;
		case 4:
			printf("�������ѯ�����������Ϣ��\n�ݶ����ֲ�ѯ������1-������ž�ȷ���ң�2-�����ҳ�ѧ�Ų��ң�3-�����ҳ��绰���ң�4-����ѧ������ѧ�Ų�ѯ\n");
			scanf("%d %s",&method,info);
			printf("����ѯ��ѧ����Ϣ���£�\n");
			Query_stu(method, info);
			break;
		case 5:
			printf("����ס����Ϣ���£�\n");
			View_data();
			break;
		case 6:
			printf("�������ҵ����ѧ��ݣ�ѧ��ǰ��λ��\n");
			scanf("%s", year);
			Del_graduated(year);
			break;
		case 7:
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
		printf("��ӭ%s\n", id);
		printf("��ѡ������Ҫ�������Ϣ��\n1-�û���Ϣ\t2-ס����Ϣ\t3-�˳�����\n");
		printf("=============================\n");
		scanf("%d", &select);
		if (select == 1)
		{
			general_model_user(id);//������ͨ�û����û�����ϵͳ
		}
		else if (select == 2)
		{
			general_model_stu();//������ͨ�û���ס����Ϣ�������
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
	printf("����������ԭʼ������������\n");
	scanf("%s %s", old_password, new_password);
	if (Update_info(id, old_password, new_password))
	{
		printf("�����������޸�\n");
	}
	else
	{
		printf("ԭʼ�����������δ�޸ĳɹ�\n");
	}
	
}
void general_model_stu()
{
	int select;
	int method;
	char info[15];
	char dorm_id[10];
	printf("=============================\n");
	printf("��ѡ������Ҫ�������Ϣ��\n1-��ѯѧ��ס����Ϣ\t2-���������ס���\t3-�˳�����\n");
	printf("=============================\n");
	scanf("%d", &select);
	switch (select)
	{
	case 1:
		printf("�������ѯ�����������Ϣ��\n�ݶ����ֲ�ѯ������1-������ž�ȷ���ң�2-�����ҳ�ѧ�Ų��ң�3-�����ҳ��绰���ң�4-����ѧ������ѧ�Ų�ѯ\n");
		scanf("%d %s", &method, info);
		printf("����ѯ��ѧ����Ϣ���£�\n");
		Query_stu(method, info);
		break;
	case 2:
		printf("����������Ҫ���ҵ�������Ϣ��\n");
		scanf("%s", dorm_id);
		printf("����Ѥ��������ס������£�\n");
		Check_dorm(dorm_id);
	}
}