#ifndef ADMIN_H
#define ADMIN_H

int Check_permission(char* id, char* password,int type);
int Create_general_user(char* id, char* password);
int Delete_general_user(char* id);
int Reset_password(char* id);
int Create_stu(struct student stu);
int Update_stu(struct student stu);
int Delete_stu(char* id);
int Query_stu(int method, char* info);
void View_data();

#endif