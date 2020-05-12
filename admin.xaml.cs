﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Shapes;
using System.Runtime.InteropServices;
using System.IO;

namespace 宿舍管理系统_WPF
{
    /// <summary>
    /// admin.xaml 的交互逻辑
    /// </summary>
    public partial class admin : Window
    {
        int type = 0;

        [DllImport("sys.dll", CallingConvention = CallingConvention.Cdecl)]
        public static extern void Create_general_user(string id,string password);
        [DllImport("sys.dll", CallingConvention = CallingConvention.Cdecl)]
        public static extern int Delete_general_user(string id);
        [DllImport("sys.dll", CallingConvention = CallingConvention.Cdecl)]
        public static extern void Reset_password(string id);

        [DllImport("sys.dll", CallingConvention = CallingConvention.Cdecl)]
        public static extern void Create_stu(string id, string name, string phone, string dorm_id, string bed_id, string head_id, string head_name, string head_phone);
        [DllImport("sys.dll", CallingConvention = CallingConvention.Cdecl)]
        public static extern int Update_stu(string id, string name, string phone,string dorm_id, string bed_id,string head_id, string head_name, string head_phone);
        [DllImport("sys.dll", CallingConvention = CallingConvention.Cdecl)]
        public static extern void Delete_stu(string id);
        [DllImport("sys.dll", CallingConvention = CallingConvention.Cdecl)]
        public static extern void Del_graduated(string year);
        //导出C的DLL与函数
        string[] user=new string[] {"创建账号","删除账号","重置账号" };
        string[] stu = new string[] { "新建住宿信息", "更新住宿信息", "删除住宿信息", "删除毕业生信息" ,"浏览宿舍信息"};
        public admin()
        {
            InitializeComponent();
            typebox.Items.Add("用户信息");
            typebox.Items.Add("学生住宿信息");//初始化Combox内容
        }

        public static implicit operator admin(general v)
        {
            throw new NotImplementedException();
        }

        private void typeboxchanged(object sender, SelectionChangedEventArgs e)
        {
            if (typebox.SelectedIndex == 0)
            {
                infobox.Items.Clear();
                for (int i = 0; i < 3; i++)
                {
                    infobox.Items.Add(user[i]);//将typebox内容设定为user[i]的内容
                }
            }
            else if (typebox.SelectedIndex == 1)
            {
                infobox.Items.Clear();
                for (int i = 0; i < 5; i++)
                {
                    infobox.Items.Add(stu[i]);//将内容设定为stu[i]的内容
                }
            }
        }

        public void infoboxchanged(object sender, SelectionChangedEventArgs e)
        {
            if (typebox.SelectedIndex == 0)
            {
                if (infobox.SelectedIndex == 0)
                {
                    info.Text= "请于右侧输入需要创建的用户ID与密码";
                    type = 0;
                }
                else if (infobox.SelectedIndex == 1)
                {
                    info.Text="请于右侧输入需要删除的用户ID";
                    type = 1;
                }
                else if (infobox.SelectedIndex == 2)
                {
                    info.Text = "请于右侧输入需要重置密码的用户ID";
                    type = 2;
                }
            }
            else if (typebox.SelectedIndex == 1)
            { 
                switch (infobox.SelectedIndex)
                {
                    case 0:
                        type = 3;
                        break;
                    case 1:
                        type = 4;
                        break;
                    case 2:
                        type = 5;
                        break;
                    case 3:
                        type = 6;
                        break;
                    case 4:
                        type = 7;
                        break;
                }
            }

        }

        private void TextBox_TextChanged(object sender, TextChangedEventArgs e)
        {

        }

        private void passwd_TextChanged(object sender, TextChangedEventArgs e)
        {

        }

        private void user_submit_Click(object sender, RoutedEventArgs e)
        {
            switch(type)
            {
                case 0:
                    Create_general_user(ID.Text, passwd.Text);
                    info.Text="用户已创建";
                    break;
                case 1:
                    Delete_general_user(ID.Text);
                    info.Text="用户已删除";
                    break;
                case 2:
                    Reset_password(ID.Text);
                    MessageBox.Show("密码已被重置为serdtijkhgf，请注意及时修改。");
                    break;
            }
        }

        private void stu_submit_Click(object sender, RoutedEventArgs e)
        {
            switch(type)
            {
                case 3:
                    Create_stu(id.Text,name.Text,phone.Text,dorm_id.Text,bed_id.Text,head_id.Text,head_name.Text,head_phone.Text);
                    info.Text="该学生已创建";
                    break;
                case 4:
                    Update_stu(id.Text, name.Text, phone.Text, dorm_id.Text, bed_id.Text, head_id.Text, head_name.Text, head_phone.Text);
                    info.Text="该学生信息已修改";
                    break;
                case 5:
                    Delete_stu(id.Text);
                    info.Text = "该学生已删除";
                    break;
                case 6:
                    Del_graduated(year.Text);
                    info.Text = "毕业生已删除";
                    break;
                case 7:
                    info.Text = "学生住宿信息如下：\n";
                    FileStream fs = new FileStream(@"data.txt", FileMode.Open, FileAccess.Read, FileShare.None);
                    StreamReader sr = new StreamReader(fs);
                    string line = sr.ReadLine();
                    while (line != null)
                    {
                        info.AppendText(line+"\n");
                        line = sr.ReadLine();
                    }
                    fs.Close();
                    break;
            }
        }
    }
}
