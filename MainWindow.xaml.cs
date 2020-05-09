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
using System.Windows.Navigation;
using System.Windows.Shapes;
using System.Runtime.InteropServices;


namespace 宿舍管理系统_WPF
{
    /// <summary>
    /// MainWindow.xaml 的交互逻辑
    /// </summary>
    public partial class MainWindow : Window
    {
        [DllImport("Check.dll", EntryPoint = "Check_permission", CallingConvention = CallingConvention.Cdecl)]
        public static extern int Check_permission(string id, string password, int type);
        public int times = 0;
        public MainWindow()
        {
            InitializeComponent();
        }
        private void Button_Login(object sender, RoutedEventArgs e)
        {
            string username = user.Text;
            string passwd = password.Password;
            int type = box.SelectedIndex;
            if (Check_permission(username, passwd, type)==0)
            {
                MessageBox.Show("账号或密码错误");
                times++;
                if(times>=5)
                {
                    MessageBox.Show("您已累计输入错误5次，请稍后再试。");
                    this.Close();
                    Environment.Exit(0);
                }
            }
            else if (Check_permission(username, passwd, type) == 1)
            {
                admin newpage = new admin();
                newpage.Show();
                this.Close();
            }
            else
            {
                MessageBox.Show("Unknown error!");
            }
            
        }

        private void Button_exit(object sender, RoutedEventArgs e)
        {
            this.Close();
            Environment.Exit(0);
        }

        private void ComboBox_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            
        }
    }
}
