#pragma once
#include<string>
using namespace std;

const int MAXNUM = 100;
const int building_number = 30;
const int INF = 9999;
class Function {
public:
	void init();//��ʼ��
	void campus_maps();//��ͼȫò
	int find_node(string name);//��λ��
	void Dijkstra(int start, int end);//Dijkstra �����·��������ӡ����
	void Visiter();//�ο�ϵͳ
	void Administrator();//����Աϵͳ
	int path[MAXNUM][MAXNUM]; //������һ�����
	int short_path[MAXNUM][MAXNUM]; //���·���ĳ���
	struct building
	{
		string name;
		int code = 0;
		string information;
	};
	struct building ve[MAXNUM];
	//�ڽӾ���洢����ͱ�
	int weight[MAXNUM][MAXNUM] = { {0} };
};