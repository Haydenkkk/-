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
		printf("				  buptУ԰����ϵͳ\n");
		printf("		                                                              \n");
		printf("				<1>�ο͵�¼                                 \n");
		printf("				<2>����Ա��¼                               \n");
		printf("				<3>�˳�ϵͳ                                 \n");
		printf("		                                                             \n");
		printf("		=======================================================\n");
		printf("����������ָ��:  ");
		cin >> mode;
		while (mode != '1' && mode != '2' && mode != '3')
		{
			cout << "�����������������룡" << endl;
			cin >> mode;
		}
		//--------�ο͵�¼����
		while (mode == '1')
		{
			system("cls");
			guide.Visiter();
			exit(0);
		}
		while (mode == '2')
		{
			cout << "�������˺ţ�";
			string account;
			string password;
			cin >> account;
			cout << "���������룺";
			cin >> password;
			while (1)
			{
				if ((account == "2020212789" or account == "2020212242" or account == "2020211674") and password == "buptyyds")
				{
					cout << "\t\t\t��¼�ɹ�......" << endl;
					break;
				}
				else
				{
					cout << "�˺Ż������������������" << endl;
					cout << "�������˺ţ�";
					cin >> account;
					cout << "���������룺";
					cin >> password;
				}
			}
			guide.Administrator();
			exit(0);
			a = 0;
		}
		while (mode == '3')
		{
			cout << "лл���ټ���" << endl;
			a = 0;
			exit(0);
		}
	}
}