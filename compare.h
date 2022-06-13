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
	bool flag1 = 0, flag2 = 0;//判断是否存在重复文件标志
	string ff, fs;//比较文件时所单个读取单位
	bool compare_file(string file1, string file2);
};

#endif
