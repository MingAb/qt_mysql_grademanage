# qt_mysql_grademanage
基于qt和mysql数据库写的简单成绩管理系统，能够实现增删改查等功能。。。

需要导入grademanager.sql
注：grademanager.sql 的导入过程
1，将grademanager.sql文件复制到D盘根目录中  
2，进入MySQL命令行界面
3，输入MySQL密码进入
4，(1)创建一个数据库，命名为grademanager.sql具体过程：
   	输入  CREATE DATABASE grademanager;
   (2)导入studentmanager.sql 文件；具体过程：
输入  USE grademanager;
	  SET NAMES utf8;
      SOURCE d:/ grademanager.sql;  (source 后面跟的是sql脚本本文件的全路径，此处该sql文件已被复制到D盘根目录中；）

作者，熊明强
