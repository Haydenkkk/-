#pragma once
#include<string>
#include<iostream>
#include<stack>
#include<windows.h>
#include<iomanip>
#include<time.h>
#include<vector>

using namespace std;

const int MAXNUM = 100;
const int building_number = 69;
const int INF = 9999;
class Function {
public:
	void init1();//初始化，策略1，最短路径
	void init2();//2,最短时间
	void init3();//3，交通混合
	int find_node(string name);//找位置
	void Dijkstra(int start, int end,int);//Dijkstra 求最短路径，并打印出来
	void place_by(int ,int);
	int get_short_path(int,int);
	void put_out(int, int);
	void Visiter();//游客系统
	void cross_bupt(int ,int);
	void perm(vector<int>& vi, vector<int>::iterator begin,
		vector<int>::iterator end, vector<vector<int> >& vvi);
	int path[MAXNUM][MAXNUM]; //保存下一个结点
	int short_path[MAXNUM][MAXNUM]; //最短路径的长度
	struct building
	{
		string name;
		int code = 0;
		string k;
	};
	struct building ve[MAXNUM];
	//邻接矩阵存储顶点和边
	int weight[MAXNUM][MAXNUM] = { {0} };
	int time[3];
};
