#include<bits/stdc++.h>
#include<iostream>
#include<string>
#include<stack>
#include<windows.h>
#include<iomanip>
#include"daohang.h"

void Function::init() {
	//��洢�����Ϣ
	//ɳ��У��
	ve[0] = { "У�ſڿ��վ", 0, " " };
	ve[1] = { "�˶���", 1, " " };
	ve[2] = { "�㱱A,B,C,D1��", 2, " " };
	ve[3] = { "�㱱E,D2��", 3, " " };
	ve[4] = { "����S2,S3", 4, " " };
	ve[5] = { "����S4,S5,S6", 5, " " };
	ve[6] = { "�̹�ʳ��", 6, " " };
	ve[7] = { "ѧ��ʳ��", 7, " " };
	ve[8] = { "�ۺϰ칫¥", 8, " " };
	ve[9] = { "ѧ��У��ͣ����", 9, " " };
	ve[10] = { "ͼ���", 10, " " };
	ve[11] = { "����¥", 11, " " };
	ve[12] = { "��ѧʵ���ۺ�¥", 12, " " };
	ve[13] = { "����¥S1", 13, " " };
	ve[14] = { "ʵ��¥S2,S3", 14, " " };
	//У����
	ve[15] = { "�׶�԰", 15, " " };
	ve[16] = { "УҽԺ", 16, " " };
	ve[17] = { "�̶�¥", 17, " " };
	ve[18] = { "����¥", 18, " " };
	ve[19] = { "������Ȫ", 19, " " };
	ve[20] = { "��ѧ����", 20, " " };
	ve[21] = { "������", 21, " " };
	ve[22] = { "����", 22, " " };
	ve[23] = { "����¥", 23, " " };
	ve[24] = { "����ʳ��", 24, " " };
	ve[25] = { "����¥", 25, " " };
	ve[26] = { "��һ¥", 26, " " };
	ve[27] = { "��ϯ��", 27, " " };
	ve[28] = { "����ͼ���", 28, " " };
	ve[29] = { "����У��ͣ��λ", 29, " " };

	//�ڽӾ���洢 
		//ɳ��У��(��ʩ����ԭ���ݲ���������¥�����·������)
	weight[0][1] = weight[1][0] = 376;
	weight[1][2] = weight[2][1] = 79;
	weight[2][3] = weight[3][2] = 85;
	weight[2][7] = weight[7][2] = 95;
	weight[2][9] = weight[9][2] = 148;
	weight[3][6] = weight[6][3] = 71;
	weight[6][7] = weight[7][6] = 40;
	weight[7][9] = weight[9][7] = 68;
	weight[8][9] = weight[9][8] = 74;
	weight[8][10] = weight[10][8] = 137;
	weight[9][10] = weight[10][9] = 135;
	weight[9][12] = weight[12][9] = 122;
	weight[11][10] = weight[10][11] = 20;
	weight[11][13] = weight[13][11] = 213;
	weight[12][10] = weight[10][12] = 128;
	weight[12][13] = weight[13][12] = 147;
	weight[13][14] = weight[14][13] = 97;

	//У����
	weight[15][16] = weight[16][15] = 204;
	weight[16][17] = weight[17][16] = 82;
	weight[16][18] = weight[18][16] = 26;
	weight[17][18] = weight[18][17] = 64;
	weight[18][27] = weight[27][18] = 81;
	weight[17][19] = weight[19][17] = 72;
	weight[19][27] = weight[27][19] = 81;
	weight[19][20] = weight[20][19] = 49;
	weight[19][26] = weight[26][19] = 64;
	weight[20][21] = weight[21][20] = 59;
	weight[21][26] = weight[26][21] = 98;
	weight[21][22] = weight[22][21] = 95;
	weight[22][28] = weight[28][22] = 55;
	weight[22][24] = weight[24][22] = 48;
	weight[23][24] = weight[24][23] = 78;
	weight[26][28] = weight[28][26] = 61;
	weight[26][25] = weight[25][26] = 73;
	weight[25][27] = weight[27][25] = 71;
	weight[29][27] = weight[27][29] = 93;
	weight[29][18] = weight[18][29] = 73;
}

void Function::campus_maps() {
	int count = 0;
	printf(" ==========================================================================\n");
	cout << "                        ***�����ʵ��ѧ��¼�ص�***                                " << endl;
	cout << "                                                                   " << endl;
	cout << "||";
	for (int i = 0; i < building_number; i++)
	{
		printf("%2d��", ve[i].code);
		cout << setiosflags(ios::left) << setw(20) << ve[i].name;
		count++;
		if (count == 3)
		{
			cout << "||" << endl;
			count = 0;
			cout << "||";
		}
	}
	cout << endl;
	printf(" ==========================================================================\n");
}

int Function::find_node(string name) {
	for (int i = 0; i < building_number; i++)
	{
		if (ve[i].name == name)
		{
			return i;
			break;
		}
	}
	return -1;
}

void Function::Dijkstra(int start, int end) {
	int dis[building_number];
	int path[building_number];
	for (int i = 0; i < building_number; i++) //��ʼ��dis path
	{
		if (start != i && weight[start][i] == 0)
			dis[i] = INF;
		else if (weight[start][i] != 0)
			dis[i] = weight[start][i];
		else if (start == i)
			dis[i] = 0;
		path[i] = -1;
	}
	bool visited[building_number] = { false };
	visited[start] = true;
	while (1)
	{
		int j;
		bool flag = false;
		for (j = 0; j < building_number; j++)
		{
			if (visited[j] == false)
			{
				flag = true;
				break;
			}
		}
		int min = j;
		if (flag == false)
			break;
		for (int i = 0; i < building_number; i++)
		{
			if (visited[i] == false)
				if (dis[min] > dis[i])
					min = i;
		}
		visited[min] = true; //��¼����������dis������С��
		for (int i = 0; i < building_number; i++)
		{
			if (weight[min][i] != 0 && visited[i] == false) //i��min���ڽӵ�
				if (dis[i] > dis[min] + weight[min][i])
				{
					dis[i] = dis[min] + weight[min][i];
					//��ʱ�ģ����������룬��ȷ���ǲ���dist��С�ģ����߲�ȷ��������û�и�С��
					path[i] = min; //��ʱ��
				}
		}
	}
	if (dis[end] == INF)
		cout << "��" << ve[start].name << "->" << ve[end].name << "��ͨ" << endl;
	else
	{
		cout << "��" << ve[start].name << "->" << ve[end].name << "�ľ���Ϊ��" << dis[end] << "m\n" << "·��Ϊ��";
		int n = end;
		stack<int> st;
		st.push(end);
		while (path[n] != -1)
		{
			st.push(path[n]);
			n = path[n];
		}
		st.push(start);
		cout << ve[st.top()].name;
		st.pop();
		while (!st.empty())
		{
			cout << "->" << ve[st.top()].name;
			st.pop();
		}
		cout << endl;
	}
}

void Function::Administrator() {
	int a = 1;
	char ch;
	campus_maps();
	while (a == 1)
	{
		printf("           ================================================================ \n");
		printf("                               buptУ԰����ϵͳ                              \n");
		printf("                                                                          \n");
		printf("                               ***����Աϵͳ***                              \n");
		printf("		                                                                   \n");
		printf("                               <1>��ѯ����ص�                                \n");
		printf("                               <2>У԰����                                   \n");
		printf("                               <3>�˳�ϵͳ                                   \n");
		printf("		                                                                   \n");
		printf("            ================================================================ \n");
		printf("����������ָ��: ");
		cin >> ch;
		if (ch != '1' && ch != '2' && ch != '3')
		{
			cout << "���벻�淶������������" << endl;
			cin >> ch;
		}
		//��ѯģʽ
		while (ch == '1')
		{
			string find_name;
			cout << "����Ҫ��ѯ�ĵص��ǣ�";
			cin >> find_name;
			int i = find_node(find_name);
			while (i == -1)
			{
				cout << "�޴���Ϣ������������";
				cin >> find_name;
				i = find_node(find_name);
			}
			cout << "������ϢΪ��" << ve[i].name << endl;
			cout << "��飺" << ve[i].information << endl;
			Sleep(5 * 100);
			break;
		}
		//��·ģʽ
		while (ch == '2')
		{
			string start_name;
			cout << "������㣺";
			cin >> start_name;
			int i = find_node(start_name);
			string end_name;
			cout << "�����յ㣺";
			cin >> end_name;
			int j = find_node(end_name);
			while (i == -1 || j == -1)
			{
				cout << "�޴���Ϣ������������" << endl;
				cout << "������㣺";
				cin >> start_name;
				i = find_node(start_name);
				cout << "�����յ㣺";
				cin >> end_name;
				j = find_node(end_name);
			}
			if ((i <= 14 and j >= 15) or (i >= 15 and j <= 14)) {
				cout << "����Ҫȥ��Ŀ�ĵ���Ҫ��У��,";
				if (i <= 14) {
					cout << "�����Գ���У����������ѡ�ý�ͨ����ǰ��У����,���ﱾ�����·��: " << endl;
					Dijkstra(29, j);
				}
				else {
					cout << "�����Գ���У����������ѡ�ý�ͨ����ǰ��ɳ��У��,����ɳ�Ӻ��·��: " << endl;
					Dijkstra(0, j);
				}
			}
			else Dijkstra(i, j);
			Sleep(5 * 100);
			break;
		}
		while (ch == '3')
		{
			cout << "��л����ʹ�ã�" << endl;
			a = 0;
			exit(0);
			break;
		}
	}
}

void Function::Visiter() {
	campus_maps();
	int a = 1;
	char ch;
	while (a == 1)
	{
		printf("   ================================================================ \n");
		printf("	                     buptУ԰����ϵͳ             \n");
		printf("	                                                              \n");
		printf("                          ***�û�ϵͳ***                            \n");
		printf("		                                                           \n");
		printf("                        <1>��ѯУ������ص�                             \n");
		printf("                        <2>У԰����                                 \n");
		printf("                        <3>�˳�ϵͳ                                 \n");
		printf("	                                                             \n");
		printf("   ================================================================ \n");
		printf("����������ָ��:  ");
		cin >> ch;
		if (ch != '1' && ch != '2' && ch != '3')
		{
			cout << "�����������������" << endl;
			cin >> ch;
		}
		//��ѯģʽ
		while (ch == '1')
		{
			string find_name;
			cout << "��������Ҫ��ѯ�ĵص㣺";
			cin >> find_name;
			int i = find_node(find_name);
			while (i == -1)
			{
				cout << "�޴���Ϣ������������: ";
				cin >> find_name;
				i = find_node(find_name);
			}
			cout << "����ص�Ϊ��" << ve[i].name << endl;
			cout << "�ص��飺" << ve[i].information << endl;
			Sleep(5 * 100);
			break;
		}
		//����
		while (ch == '2')
		{
			string start_name;
			cout << "������㣺";
			cin >> start_name;
			int i = find_node(start_name);
			string end_name;
			cout << "�����յ㣺";
			cin >> end_name;
			int j = find_node(end_name);
			while (i == -1 || j == -1)
			{
				cout << "�޴���Ϣ������������" << endl;
				cout << "������㣺";
				cin >> start_name;
				i = find_node(start_name);
				cout << "�����յ㣺";
				cin >> end_name;
				j = find_node(end_name);
			}
			if ((i <= 14 and j >= 15) or (i >= 15 and j <= 14)) {
				cout << "����Ҫȥ��Ŀ�ĵ���Ҫ��У��,";
				if (i <= 14) {
					cout << "�����Գ���У����������ѡ�ý�ͨ����ǰ��У����,���ﱾ�����·��: " << endl;
					Dijkstra(29, j);
				}
				else {
					cout << "�����Գ���У����������ѡ�ý�ͨ����ǰ��ɳ��У��,����ɳ�Ӻ��·��: " << endl;
					Dijkstra(0, j);
				}
			}
			else Dijkstra(i, j);
			Sleep(5 * 100);
			break;
		}
		while (ch == '3')
		{
			cout << "лл���ټ���" << endl;
			a = 0;
			break;
			exit(0);
		}
	}
}

