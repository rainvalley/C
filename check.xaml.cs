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
    /// check.xaml 的交互逻辑
    /// </summary>
    public partial class check : Window
    {
        [DllImport("sys.dll", CallingConvention = CallingConvention.Cdecl)]
        public static extern int Query_stu(int method, string info);
        public check()
        {
            InitializeComponent();
            method.Items.Add("宿舍号");
            method.Items.Add("寝室长学号");
            method.Items.Add("寝室长电话");
            method.Items.Add("学生本人学号");
        }


        private void submit_Click(object sender, RoutedEventArgs e)
        {
            string information = info.Text;
            switch(method.SelectedIndex)
            {
                case 0:
                    Query_stu(1, information);
                    tips.Text = "请于下方输入宿舍号";
                    break;
                case 1:
                    tips.Text = "请于下方输入寝室长学号";
                    Query_stu(2, information);
                    break;
                case 2:
                    tips.Text = "请于下方输入寝室长电话";
                    Query_stu(3, information);
                    break;
                case 3:
                    tips.Text = "请于下方输入学生学号";
                    Query_stu(4, information);
                    break;
            }
            output.Text = "查询学生的具体信息如下：\n";
            FileStream fs = new FileStream(@"log.txt", FileMode.Open, FileAccess.Read, FileShare.None);
            StreamReader sr = new StreamReader(fs);
            string line = sr.ReadLine();
            while (line != null)
            {
                output.AppendText(line + "\n");
                line = sr.ReadLine();
            }
            fs.Close();
        }

        private void TextBox_TextChanged(object sender, TextChangedEventArgs e)
        {

        }
    }
}
