#include<bits/stdc++.h>
#include<iostream>
#include<string>
#include<stack>
#include<windows.h>
#include<iomanip>
#include"daohang.h"

void Function::init() {
	//组存储相关信息
	//沙河校区
	ve[0] = { "校门口快递站", 0, " " };
	ve[1] = { "运动场", 1, " " };
	ve[2] = { "雁北A,B,C,D1区", 2, " " };
	ve[3] = { "雁北E,D2区", 3, " " };
	ve[4] = { "雁南S2,S3", 4, " " };
	ve[5] = { "雁南S4,S5,S6", 5, " " };
	ve[6] = { "教工食堂", 6, " " };
	ve[7] = { "学生食堂", 7, " " };
	ve[8] = { "综合办公楼", 8, " " };
	ve[9] = { "学活校车停靠点", 9, " " };
	ve[10] = { "图书馆", 10, " " };
	ve[11] = { "东配楼", 11, " " };
	ve[12] = { "教学实验综合楼", 12, " " };
	ve[13] = { "教室楼S1", 13, " " };
	ve[14] = { "实验楼S2,S3", 14, " " };
	//校本部
	ve[15] = { "幼儿园", 15, " " };
	ve[16] = { "校医院", 16, " " };
	ve[17] = { "教二楼", 17, " " };
	ve[18] = { "教三楼", 18, " " };
	ve[19] = { "音乐喷泉", 19, " " };
	ve[20] = { "科学会堂", 20, " " };
	ve[21] = { "体育馆", 21, " " };
	ve[22] = { "篮球场", 22, " " };
	ve[23] = { "科研楼", 23, " " };
	ve[24] = { "本部食堂", 24, " " };
	ve[25] = { "教四楼", 25, " " };
	ve[26] = { "教一楼", 26, " " };
	ve[27] = { "主席像", 27, " " };
	ve[28] = { "本部图书馆", 28, " " };
	ve[29] = { "西门校车停车位", 29, " " };

	//邻接矩阵存储 
		//沙河校区(因施工等原因暂不计入雁南楼的相关路径连接)
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

	//校本部
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
	cout << "                        ***北京邮电大学收录地点***                                " << endl;
	cout << "                                                                   " << endl;
	cout << "||";
	for (int i = 0; i < building_number; i++)
	{
		printf("%2d、", ve[i].code);
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
	for (int i = 0; i < building_number; i++) //初始化dis path
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
		visited[min] = true; //收录的条件就是dis里面最小的
		for (int i = 0; i < building_number; i++)
		{
			if (weight[min][i] != 0 && visited[i] == false) //i是min的邻接点
				if (dis[i] > dis[min] + weight[min][i])
				{
					dis[i] = dis[min] + weight[min][i];
					//暂时的，还不能收入，不确定是不是dist最小的，或者不确定后面有没有更小的
					path[i] = min; //暂时的
				}
		}
	}
	if (dis[end] == INF)
		cout << "从" << ve[start].name << "->" << ve[end].name << "不通" << endl;
	else
	{
		cout << "从" << ve[start].name << "->" << ve[end].name << "的距离为：" << dis[end] << "m\n" << "路径为：";
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
		printf("                               bupt校园导航系统                              \n");
		printf("                                                                          \n");
		printf("                               ***管理员系统***                              \n");
		printf("		                                                                   \n");
		printf("                               <1>查询任意地点                                \n");
		printf("                               <2>校园导航                                   \n");
		printf("                               <3>退出系统                                   \n");
		printf("		                                                                   \n");
		printf("            ================================================================ \n");
		printf("请输入您的指令: ");
		cin >> ch;
		if (ch != '1' && ch != '2' && ch != '3')
		{
			cout << "输入不规范，请重新输入" << endl;
			cin >> ch;
		}
		//查询模式
		while (ch == '1')
		{
			string find_name;
			cout << "你想要查询的地点是：";
			cin >> find_name;
			int i = find_node(find_name);
			while (i == -1)
			{
				cout << "无此信息，请重新输入";
				cin >> find_name;
				i = find_node(find_name);
			}
			cout << "所查信息为：" << ve[i].name << endl;
			cout << "简介：" << ve[i].information << endl;
			Sleep(5 * 100);
			break;
		}
		//问路模式
		while (ch == '2')
		{
			string start_name;
			cout << "输入起点：";
			cin >> start_name;
			int i = find_node(start_name);
			string end_name;
			cout << "输入终点：";
			cin >> end_name;
			int j = find_node(end_name);
			while (i == -1 || j == -1)
			{
				cout << "无此信息，请重新输入" << endl;
				cout << "输入起点：";
				cin >> start_name;
				i = find_node(start_name);
				cout << "输入终点：";
				cin >> end_name;
				j = find_node(end_name);
			}
			if ((i <= 14 and j >= 15) or (i >= 15 and j <= 14)) {
				cout << "您所要去的目的点需要跨校区,";
				if (i <= 14) {
					cout << "您可以乘坐校车或者自行选用交通工具前往校本部,到达本部后的路线: " << endl;
					Dijkstra(29, j);
				}
				else {
					cout << "您可以乘坐校车或者自行选用交通工具前往沙河校区,到达沙河后的路线: " << endl;
					Dijkstra(0, j);
				}
			}
			else Dijkstra(i, j);
			Sleep(5 * 100);
			break;
		}
		while (ch == '3')
		{
			cout << "感谢您的使用！" << endl;
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
		printf("	                     bupt校园导航系统             \n");
		printf("	                                                              \n");
		printf("                          ***用户系统***                            \n");
		printf("		                                                           \n");
		printf("                        <1>查询校内任意地点                             \n");
		printf("                        <2>校园导航                                 \n");
		printf("                        <3>退出系统                                 \n");
		printf("	                                                             \n");
		printf("   ================================================================ \n");
		printf("请输入您的指令:  ");
		cin >> ch;
		if (ch != '1' && ch != '2' && ch != '3')
		{
			cout << "输入错误，请重新输入" << endl;
			cin >> ch;
		}
		//查询模式
		while (ch == '1')
		{
			string find_name;
			cout << "输入你想要查询的地点：";
			cin >> find_name;
			int i = find_node(find_name);
			while (i == -1)
			{
				cout << "无此信息，请重新输入: ";
				cin >> find_name;
				i = find_node(find_name);
			}
			cout << "所查地点为：" << ve[i].name << endl;
			cout << "地点简介：" << ve[i].information << endl;
			Sleep(5 * 100);
			break;
		}
		//导航
		while (ch == '2')
		{
			string start_name;
			cout << "输入起点：";
			cin >> start_name;
			int i = find_node(start_name);
			string end_name;
			cout << "输入终点：";
			cin >> end_name;
			int j = find_node(end_name);
			while (i == -1 || j == -1)
			{
				cout << "无此信息，请重新输入" << endl;
				cout << "输入起点：";
				cin >> start_name;
				i = find_node(start_name);
				cout << "输入终点：";
				cin >> end_name;
				j = find_node(end_name);
			}
			if ((i <= 14 and j >= 15) or (i >= 15 and j <= 14)) {
				cout << "您所要去的目的点需要跨校区,";
				if (i <= 14) {
					cout << "您可以乘坐校车或者自行选用交通工具前往校本部,到达本部后的路线: " << endl;
					Dijkstra(29, j);
				}
				else {
					cout << "您可以乘坐校车或者自行选用交通工具前往沙河校区,到达沙河后的路线: " << endl;
					Dijkstra(0, j);
				}
			}
			else Dijkstra(i, j);
			Sleep(5 * 100);
			break;
		}
		while (ch == '3')
		{
			cout << "谢谢，再见！" << endl;
			a = 0;
			break;
			exit(0);
		}
	}
}

