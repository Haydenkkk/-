#ifndef _COMPRESS_H
#define _COMPRESS_H
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <iostream>
#define _CRT_SECURE_NO_WARNINGS
class tree {
public:

    struct head
    {
        int b;						  //字符
        long count;                   //文件中该字符出现的次数
        long parent, lch, rch;        //make a tree
        char bits[256];               //the huffuman code
    }header[512], tmp;  //节点树
    int compress(const char* filename, const char* outputfile);
    int uncompress(const char* filename, const char* outputfile);
};


#endif