#ifndef ADMIN_H
#define ADMIN_H

int Check_permission(char* id, char* password,int type);
void Create_general_user(char* id, char* password);
int Delete_general_user(char* id);
void Reset_password(char* id);
void Create_stu(struct student stu);
int Update_stu(struct student stu);
void Delete_stu(char* id);
int Query_stu(int method, char* info);
void View_data();

#endif