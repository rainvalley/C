   M S B A M L   `   `   `  ����Q  M宿舍管理系统_WPF, Version=1.0.0.0, Culture=neutral, PublicKeyToken=null?$clr-namespace:宿舍管理系统_WPF宿舍管理系统_WPF  5   	   '    !宿舍管理系统_WPF.MainWindow   5   	   \ XPresentationFramework, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35R NWindowsBase, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35W SPresentationCore, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35D 9http://schemas.microsoft.com/winfx/2006/xaml/presentation    5   	   R NSystem.Xaml, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089:x,http://schemas.microsoft.com/winfx/2006/xaml     5   	   @d2http://schemas.microsoft.com/expression/blend/2008     5   	   Jmc;http://schemas.openxmlformats.org/markup-compatibility/2006     5   	   6local$clr-namespace:宿舍管理系统_WPF     5   	     � Title$  宿舍管理系统��5   	   $	��450��6   $	��800��6%    � WindowStyle$ SingleBorderWindow=�61    � 
ResizeMode$ NoResize=�6R   .��5	      �  J� RenderTransformOrigin$ 0.494,0.505&�6    +� FocusedElement 6/   ��  �� ElementName$
 user��.+�5
   
   �� $*��$欢迎使用学生宿舍管理系统��6   $
��Left=�6'   $��
274,28,0,0q�6B   $	��Top=�6V   $	��254��6n   $��37��6z   $
��20px(�6�   �� 5   
   -   5        $��登录
��5      $
��Left=�6(   $��165,335,0,0q�6C   $	��Top=�6X   $	��124��6p   $��39��6|   $
��25px(�6�    �� 	IsDefault . 6�   �� 5   
   -   5        $��退出��5      $
��Left=�6   $��516,335,0,0q�69   $	��Top=�6N   $��124     ��6f   $��39��5      $
��25px(�6'   �� 5   
   $
��Left=�6   $��247,124,0,0q�6/   $
��Wrap=�6D   $��账号��6X   $
��15px(�6b   $	��Top=�6r   $��22��6�   $��42��6�   $ 1.031,0.455&�6�   �� 5   
   $
��Left=�6   $��247,182,0,0q�6/   $
��Wrap=�6D   $��密码��6X   $
��15px(�6b   $	��Top=�6r   $��22��6�   $��42��6�   $ 1.031,0.455&�6�   �� 5   
   -   5         ��Name$
 user��5      $
��Left=�6    $��25��6;   $��315,124,0,0q�6G    �� TextWrapping$
 Wrap=�6\   $	��Top=�6p   $	��199��6�   G� 5   
   -   5        	 G�Name$	 password��5      $
��Left=�6(   $��315,182,0,0q�6C   $	��Top=�6X   $	��199��6p   $��25��6|   $ 0.437,-0.72&�6�   �� 5   
   -   5        $	��box��5      $
��Left=�6   $��315,239,0,0q�69   $	��Top=�6N   $	��140��6f   $ 
0.63,0.887&�6r   .@�5      �� .��6   	管理员6!   �� 5      
 �� 
IsSelected
 . .��6-   用户61   5      �� 5   
   $��身份��6   $
��15px(�6   $
��Left=�6-   $��247,231,0,0q�6H   $	��Top=�6]   5      5      