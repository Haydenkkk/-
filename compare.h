#ifndef _COMPARE_H
#define _COMPARE_H
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <iostream>
#include <fstream>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;

class Start {
public:
	bool flag1 = 0, flag2 = 0;//�ж��Ƿ�����ظ��ļ���־
	string ff, fs;//�Ƚ��ļ�ʱ��������ȡ��λ
	bool compare_file(string file1, string file2);
};

#endif
