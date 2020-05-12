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

namespace 宿舍管理系统_WPF
{
    /// <summary>
    /// general.xaml 的交互逻辑
    /// </summary>

    public partial class general : Window
    {
        [DllImport("sys.dll", CallingConvention = CallingConvention.Cdecl)]
        public static extern int Update_info(string id, string old_password, string new_password);
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

        }
    }
}
