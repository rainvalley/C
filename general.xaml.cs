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
using System.IO;

namespace 宿舍管理系统_WPF
{
    /// <summary>
    /// general.xaml 的交互逻辑
    /// </summary>

    public partial class general : Window
    {
        [DllImport("sys.dll", CallingConvention = CallingConvention.Cdecl)]
        public static extern int Update_info(string id, string old_password, string new_password);
        [DllImport("sys.dll", CallingConvention = CallingConvention.Cdecl)]
        public static extern void Check_dorm(string dorm_id);
        [DllImport("Kernel32.dll", SetLastError = true)]
        public static extern int SetStdHandle(int device, IntPtr handle);

        public general()
        {
            InitializeComponent();
        }

        private void password_submit_Click(object sender, RoutedEventArgs e)
        {
            if(Update_info(id.Text,old_password.Text,new_password.Text)==1)
            {
                MessageBox.Show("密码已修改");
            }
        }
        private void Button_Click(object sender, RoutedEventArgs e)
        {
            Check_dorm(dorm_id.Text);
            info.Text = "学生住宿信息如下：\n";
            FileStream fs = new FileStream(@"log.txt", FileMode.Open, FileAccess.Read, FileShare.None);
            StreamReader sr = new StreamReader(fs);
            string line = sr.ReadLine();
            while (line != null)
            {
                info.AppendText(line + "\n");
                line = sr.ReadLine();
            }
            fs.Close();
        }

        private void Button_Click_1(object sender, RoutedEventArgs e)
        {
            check newpage = new check();
            newpage.Show();
            this.Close();
        }
    }
}
