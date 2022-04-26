#include<bits/stdc++.h>
#include<iostream>
#include<string>
#include<stack>
#include<windows.h>
#include<iomanip>

#include"daohang.h"
using namespace std;

int main()
{
	Function guide;
	guide.init();
	char mode;
	int a = 1;
	while (a == 1)
	{
		printf("		=======================================================\n");
		printf("				  bupt校园导航系统\n");
		printf("		                                                              \n");
		printf("				<1>游客登录                                 \n");
		printf("				<2>管理员登录                               \n");
		printf("				<3>退出系统                                 \n");
		printf("		                                                             \n");
		printf("		=======================================================\n");
		printf("请输入您的指令:  ");
		cin >> mode;
		while (mode != '1' && mode != '2' && mode != '3')
		{
			cout << "输入有误，请重新输入！" << endl;
			cin >> mode;
		}
		//--------游客登录界面
		while (mode == '1')
		{
			system("cls");
			guide.Visiter();
			exit(0);
		}
		while (mode == '2')
		{
			cout << "请输入账号：";
			string account;
			string password;
			cin >> account;
			cout << "请输入密码：";
			cin >> password;
			while (1)
			{
				if ((account == "2020212789" or account == "2020212242" or account == "2020211674") and password == "buptyyds")
				{
					cout << "\t\t\t登录成功......" << endl;
					break;
				}
				else
				{
					cout << "账号或密码错误！请重新输入" << endl;
					cout << "请输入账号：";
					cin >> account;
					cout << "请输入密码：";
					cin >> password;
				}
			}
			guide.Administrator();
			exit(0);
			a = 0;
		}
		while (mode == '3')
		{
			cout << "谢谢，再见！" << endl;
			a = 0;
			exit(0);
		}
	}
}