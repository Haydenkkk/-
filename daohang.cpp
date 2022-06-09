#include"daohang.h"

void Function::init1() {
	//组存储相关信息
	//沙河校区
	cout << "1";
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
void Function::init2() {
	//组存储相关信息
	//沙河校区
	cout << "2";
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
	weight[15][16] = weight[16][15] = 204/1.3;
	weight[16][17] = weight[17][16] = 82/(1.3*0.9);
	weight[16][18] = weight[18][16] = 26/(1.3 * 0.9);
	weight[17][18] = weight[18][17] = 64 / (1.3 * 0.7);
	weight[18][27] = weight[27][18] = 81 / (1.3 * 0.6);
	weight[17][19] = weight[19][17] = 72 / (1.3 * 0.5);
	weight[19][27] = weight[27][19] = 81 / (1.3 * 0.4);
	weight[19][20] = weight[20][19] = 49 / (1.3 * 0.7);
	weight[19][26] = weight[26][19] = 64 / (1.3 * 0.6);
	weight[20][21] = weight[21][20] = 59 / (1.3 * 0.8);
	weight[21][26] = weight[26][21] = 98 / (1.3 * 0.8);
	weight[21][22] = weight[22][21] = 95 / (1.3 * 0.9);
	weight[22][28] = weight[28][22] = 55 / (1.3 * 0.75);
	weight[22][24] = weight[24][22] = 48 / (1.3 * 0.9);
	weight[23][24] = weight[24][23] = 78 / (1.3 * 0.8);
	weight[26][28] = weight[28][26] = 61 / (1.3 * 0.7);
	weight[26][25] = weight[25][26] = 73 / (1.3 * 0.7);
	weight[25][27] = weight[27][25] = 71 / (1.3 * 0.6);
	weight[29][27] = weight[27][29] = 93 / (1.3 * 0.8);
	weight[29][18] = weight[18][29] = 73 / (1.3 * 0.9);
}
void Function::init3() {
	//组存储相关信息
	//沙河校区
	cout << "3";
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
	//自行车正常速度为4.1 m/s,在校园内因安全问题应适量降低车速，故取基本正常行驶速度为3m/s.
	//拥挤度高于0.6时可认为自行车速度快，自行车与拥挤度的函数关系为 v = 3*x^3
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
	weight[15][16] = weight[16][15] = 204 / 3;
	weight[16][17] = weight[17][16] = 82 / (3 * pow(0.9,3));
	weight[16][18] = weight[18][16] = 26 / (3 * pow(0.9, 3));
	weight[17][18] = weight[18][17] = 64 / (3 * pow(0.7, 3));
	weight[18][27] = weight[27][18] = 81 / (1.3 * 0.6);
	weight[17][19] = weight[19][17] = 72 / (1.3 * 0.5);
	weight[19][27] = weight[27][19] = 81 / (1.3 * 0.4);
	weight[19][20] = weight[20][19] = 49 / (3 * pow(0.7, 3));
	weight[19][26] = weight[26][19] = 64 / (1.3 * 0.6);
	weight[20][21] = weight[21][20] = 59 / (3 * pow(0.8, 3));
	weight[21][26] = weight[26][21] = 98 / (3 * pow(0.8, 3));
	weight[21][22] = weight[22][21] = 95 / (3 * pow(0.9, 3));
	weight[22][28] = weight[28][22] = 55 / (3 * pow(0.75, 3));
	weight[22][24] = weight[24][22] = 48 / (3 * pow(0.9, 3));
	weight[23][24] = weight[24][23] = 78 / (3 * pow(0.8, 3));
	weight[26][28] = weight[28][26] = 61 / (3 * pow(0.7, 3));
	weight[26][25] = weight[25][26] = 73 / (3 * pow(0.7, 3));
	weight[25][27] = weight[27][25] = 71 / (1.3 * 0.6);
	weight[29][27] = weight[27][29] = 93 / (3 * pow(0.8, 3));
	weight[29][18] = weight[18][29] = 73 / (3 * pow(0.9, 3));
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
void Function::Dijkstra(int start, int end,int mode) {
	int dis[building_number];
	int path[building_number];
	//判断模式并初始化
	/*if (mode == 1) this->init1();
	else if (mode == 2) this->init2();
	else this->init3();*/

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
	if (dis[end] == INF) {
		cout << "从" << ve[start].name << "->" << ve[end].name << "不通" << endl;
		return;
	}
	if (mode == 1) {
		//输出符合策略的最优解
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
	else if (mode == 2) {
		cout << "从" << ve[start].name << "->" << ve[end].name << "的最短时间为：" << dis[end]/60 << "min\n" << "路径为：";
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
	else {
		cout << "从" << ve[start].name << "->" << ve[end].name << "的最短时间为：" << dis[end]/60 << "min\n" << "路径为：";
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
		int tmp = st.top();
		st.pop();
		while (!st.empty())
		{	
			if ((tmp==27 and (st.top()==18 or st.top() == 19 or st.top() == 25))or (tmp == 19 and (st.top() == 16 or st.top() == 17))) {
				cout << "->(步行)" << ve[st.top()].name;
			}
			else {
				cout << "->(自行车)" << ve[st.top()].name;
			}
			tmp = st.top();
			st.pop();
		}
		cout << endl;
	}
}
void Function::Visiter() {
	string start_name;
	cout << "输入起点：";
	cin >> start_name;
	string end_name;
	cout << "输入终点：";
	cin >> end_name;
	cout << "策略1or2or3：";
	int mode;
	cin >> mode;
	if (mode == 1) this->init1();
	else if (mode == 2) this->init2();
	else this->init3();
	while (1)
	{
		int j = find_node(end_name);
		int i = find_node(start_name);
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
				cout << "您可以乘坐校车或者自行选用交通工具前往校本部..." << endl;
				cross_bupt(i,j);
				cout << "到达后的路线选择如下： ";
				Dijkstra(29, j, mode);
			}
			else {
				cout << "您可以乘坐校车或者自行选用交通工具前往沙河本部..." << endl;
				cross_bupt(i, j);
				cout << "到达后的路线选择如下： ";
				Dijkstra(0, j, mode);
			}
		}
		else Dijkstra(i, j, mode);
		break;
	}
}
void Function::cross_bupt(int i,int j) {
	SYSTEMTIME time1;
	GetLocalTime(&time1);
	this->time[0] = time1.wDayOfWeek;
	this->time[1] = time1.wHour;
	this->time[2] = time1.wMinute;
	/*cout << time;*/
	//设定校车60分钟一班，从早上7点钟开始有校车，校车的时长为60分钟，打车为40分钟，地铁为70分钟
	if (time[1] > 21 or time[1] < 6) cout << "校车运营时间在7时-22时，当前距离运营时间较长..." << endl;
	else {
		if (time[2] != 0) {
			cout << "最近的一班校车在" << time[1] + 1 << ":00 " << "您还需等待" << 60 - time[2] << "分钟" << endl;
		}
		else if (time[2] == 0) {
			if (i <= 14)
				cout << "校车现在正在准备出发，请速速前往学活乘坐校车..." << endl;
			else
				cout << "校车现在正在准备出发，请速速前往西门乘坐校车..." << endl;
		}
	}
	if (i <= 14) {
		cout << "您同样可以选择地铁,出校门后左转直走至沙河地铁站，乘坐昌平线至西二旗换乘13号线至大钟寺后出站坐304路公交车到明光桥站，步行至校本部，全程大约70分钟，您需要步行1.0公里" << endl;
	}
	else {
		cout << "您同样可以选择地铁,出校门后至明光桥站,乘坐304路公交车到大钟寺站，乘坐13号线至至西二旗换乘昌平线到沙河地铁站，步行至沙河，全程大约70分钟，您需要步行1.0公里" << endl;
	}
	cout << "土豪请直接打车至本部校区" << endl;
}
