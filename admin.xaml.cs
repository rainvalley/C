using System;
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

namespace 宿舍管理系统_WPF
{
    /// <summary>
    /// admin.xaml 的交互逻辑
    /// </summary>
    public partial class admin : Window
    {
        [DllImport("sys.dll", CallingConvention = CallingConvention.Cdecl)]
        public static extern void Create_general_user(string id,string password);
        [DllImport("sys.dll", CallingConvention = CallingConvention.Cdecl)]
        public static extern int Delete_general_user(string id);
        [DllImport("sys.dll", CallingConvention = CallingConvention.Cdecl)]
        public static extern void Reset_password(string id);

        string[] user=new string[] {"创建账号","删除账号","重置账号" };
        string[] stu = new string[] { "新建住宿信息", "更新住宿信息", "删除住宿信息", "查询住宿信息", "浏览住宿信息", "删除毕业生信息" };
        public admin()
        {
            InitializeComponent();
            typebox.Items.Add("用户信息");
            typebox.Items.Add("学生住宿信息");
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
                    infobox.Items.Add(user[i]);
                }
            }
            else if (typebox.SelectedIndex == 1)
            {
                infobox.Items.Clear();
                for (int i = 0; i < 6; i++)
                {
                    infobox.Items.Add(stu[i]);
                }
            }
        }

        public void infoboxchanged(object sender, SelectionChangedEventArgs e)
        {
            if (typebox.SelectedIndex == 0)
            {
                if (infobox.SelectedIndex == 0)
                {
                    MessageBox.Show("00");
                }
                else if (infobox.SelectedIndex == 1)
                {
                    MessageBox.Show("01");
                }
                else if (infobox.SelectedIndex == 2)
                {
                    MessageBox.Show("02");
                }
            }
            else if (typebox.SelectedIndex == 1)
            { 
                switch (infobox.SelectedIndex)
                {
                    case 0:
                        MessageBox.Show("10");
                        break;
                    case 1:
                        MessageBox.Show("11");
                        break;
                    case 2:
                        MessageBox.Show("12");
                        break;
                    case 3:
                        MessageBox.Show("13");
                        break;
                    case 4:
                        MessageBox.Show("14");
                        break;
                    case 5:
                        MessageBox.Show("15");
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
    }
}
