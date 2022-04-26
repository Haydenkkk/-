#pragma once
#include<string>
using namespace std;

const int MAXNUM = 100;
const int building_number = 30;
const int INF = 9999;
class Function {
public:
	void init();//初始化
	void campus_maps();//地图全貌
	int find_node(string name);//找位置
	void Dijkstra(int start, int end);//Dijkstra 求最短路径，并打印出来
	void Visiter();//游客系统
	void Administrator();//管理员系统
	int path[MAXNUM][MAXNUM]; //保存下一个结点
	int short_path[MAXNUM][MAXNUM]; //最短路径的长度
	struct building
	{
		string name;
		int code = 0;
		string information;
	};
	struct building ve[MAXNUM];
	//邻接矩阵存储顶点和边
	int weight[MAXNUM][MAXNUM] = { {0} };
};