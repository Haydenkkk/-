#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <iostream>
#define _CRT_SECURE_NO_WARNINGS

struct head
{
    int b;						  //�ַ�
    long count;                   //�ļ��и��ַ����ֵĴ���
    long parent, lch, rch;        //make a tree
    char bits[256];               //the huffuman code
}header[512], tmp;  //�ڵ���
//������compress()
//���ã���ȡ�ļ����ݲ�����ѹ��
//��ѹ������д����һ���ĵ�
int compress(const char* filename, const char* outputfile)
{
    char buf[512];
    unsigned char c;
    long i, j, m, n, f;
    long min1, pt1, flength;
    FILE* ifp, * ofp;
    int per = 10;
    ifp = fopen(filename, "rb");                  //��ԭʼ�ļ�
    if (ifp == NULL)
    {
        printf("���ļ�ʧ��:%s\n", filename);
        return 0;                             //�����ʧ�ܣ������������Ϣ
    }
    ofp = fopen(outputfile, "wb");                 //��ѹ����洢��Ϣ���ļ�
    if (ofp == NULL)
    {
        printf("���ļ�ʧ��:%s\n", outputfile);
        return 0;
    }
    flength = 0;
    while (!feof(ifp))
    {
        fread(&c, 1, 1, ifp);
        header[c].count++;                       //���ļ���ͳ���ַ����ִ���
        flength++;                               //��¼�ļ����ַ�����
    }
    flength--;
    header[c].count--;
    for (i = 0; i < 512; i++)                    //HUFFMAN�㷨�г�ʼ�ڵ������
    {
        if (header[i].count != 0)
            header[i].b = (unsigned char)i;
        else
            header[i].b = -1;
        header[i].parent = -1;
        header[i].lch = header[i].rch = -1;
    }

    for (i = 0; i < 256; i++)                    //����㰴���ִ�������
    {
        for (j = i + 1; j < 256; j++)
        {
            if (header[i].count < header[j].count)
            {
                tmp = header[i];
                header[i] = header[j];
                header[j] = tmp;
            }
        }
    }


    for (i = 0; i < 256; i++)                    //ͳ�Ʋ�ͬ�ַ�������
    {
        if (header[i].count == 0)
            break;
    }

    n = i;
    m = 2 * n - 1;
    for (i = n; i < m; i++)
    {
        min1 = 74709999;
        for (j = 0; j < i; j++)
        {
            if (header[j].parent != -1) continue;
            if (min1 > header[j].count)
            {
                pt1 = j;
                min1 = header[j].count;
                continue;
            }
        }
        header[i].count = header[pt1].count;
        header[pt1].parent = i;
        header[i].lch = pt1;
        min1 = 7470999;
        for (j = 0; j < i; j++)
        {
            if (header[j].parent != -1) continue;
            if (min1 > header[j].count)
            {
                pt1 = j;
                min1 = header[j].count;
                continue;
            }
        }
        header[i].count += header[pt1].count;
        header[i].rch = pt1;
        header[pt1].parent = i;
    }

    for (i = 0; i < n; i++)                        //����HUFFMAN���������ַ��ı���
    {
        f = i;
        header[i].bits[0] = 0;
        while (header[f].parent != -1)
        {
            j = f;
            f = header[f].parent;
            if (header[f].lch == j)
            {
                j = strlen(header[i].bits);
                memmove(header[i].bits + 1, header[i].bits, j + 1);
                header[i].bits[0] = '0';
            }
            else
            {
                j = strlen(header[i].bits);
                memmove(header[i].bits + 1, header[i].bits, j + 1);
                header[i].bits[0] = '1';
            }
        }
    }

    //����ľ��Ƕ�ԭ�ļ���ÿһ���ַ����������úõı����滻�ļ��е��ַ�
    fseek(ifp, 0, SEEK_SET);                                                //��ָ�붨���ļ���ʼλ��
    fseek(ofp, 8, SEEK_SET);                                //��8λ��������Ϊ��λ���ж�ȡ
    buf[0] = 0;
    f = 0;
    pt1 = 8;
    printf("��ȡ��Ҫѹ�����ļ�:%s\n", filename);
    while (!feof(ifp))
    {
        c = fgetc(ifp);
        f++;
        for (i = 0; i < n; i++)
        {
            if (c == header[i].b) break;
        }
        strcat(buf, header[i].bits);
        j = strlen(buf);
        c = 0;
        while (j >= 8)                                             //��ʣ���ַ�������С��8��ʱ
        {
            for (i = 0; i < 8; i++)                               //���հ�λ��������ת����ʮ����ASCII��д���ļ�һ�ν���ѹ��
            {
                if (buf[i] == '1') c = (c << 1) | 1;
                else c = c << 1;
            }
            fwrite(&c, 1, 1, ofp);
            pt1++;
            strcpy(buf, buf + 8);
            j = strlen(buf);
        }
        if (f == flength)
            break;
    }

    if (j > 0)                                                      //��ʣ���ַ���������8��ʱ
    {
        strcat(buf, "00000000");
        for (i = 0; i < 8; i++)
        {
            if (buf[i] == '1') c = (c << 1) | 1;
            else c = c << 1;                                        //�Բ����λ�����в���
        }
        fwrite(&c, 1, 1, ofp);
        pt1++;
    }
    fseek(ofp, 0, SEEK_SET);                                        //��������Ϣд��洢�ļ�
    fwrite(&flength, 1, sizeof(flength), ofp);
    fwrite(&pt1, sizeof(long), 1, ofp);
    fseek(ofp, pt1, SEEK_SET);
    fwrite(&n, sizeof(long), 1, ofp);
    for (i = 0; i < n; i++)
    {
        tmp = header[i];

        fwrite(&(header[i].b), 1, 1, ofp);
        pt1++;
        c = strlen(header[i].bits);
        fwrite(&c, 1, 1, ofp);
        pt1++;
        j = strlen(header[i].bits);

        if (j % 8 != 0)                                             //��λ������8ʱ���Ը������в������
        {
            for (f = j % 8; f < 8; f++)
                strcat(header[i].bits, "0");
        }

        while (header[i].bits[0] != 0)
        {
            c = 0;
            for (j = 0; j < 8; j++)
            {
                if (header[i].bits[j] == '1') c = (c << 1) | 1;
                else c = c << 1;
            }
            strcpy(header[i].bits, header[i].bits + 8);
            fwrite(&c, 1, 1, ofp);                                            //�����õı�����Ϣд���ļ�
            pt1++;
        }

        header[i] = tmp;
    }
    fclose(ifp);
    fclose(ofp);                                                              //�ر��ļ�
    printf("ѹ���ɹ�\nѹ�����ļ�Ϊ:%s\n", outputfile);
    return 1;                                       //����ѹ���ɹ���Ϣ
}


//������uncompress()
//���ã���ѹ���ļ���������ѹ�������д�����ļ�
int uncompress(const char* filename, const char* outputfile)
{
    char buf[255], bx[255];
    unsigned char c;
    char out_filename[512];
    long i, j, m, n, f, p, l;
    long flength;
    int per = 10;
    int len = 0;
    FILE* ifp, * ofp;
    char c_name[512] = { 0 };
    ifp = fopen(filename, "rb");                                              //���ļ�
    if (ifp == NULL)
    {
        printf("���ļ�ʧ��:%s\n", filename);
        return 0;
    }
    //��ȡԭ�ļ���
    if (outputfile)
        strcpy(out_filename, outputfile);
    else
        strcpy(out_filename, c_name);

    ofp = fopen(out_filename, "wb");                                            //���ļ�
    if (ofp == NULL)
    {
        printf("���ļ�ʧ��:%s\n", outputfile);
        return 0;
    }

    fseek(ifp, 0, SEEK_END);
    len = ftell(ifp);
    fseek(ifp, 0, SEEK_SET);
    printf("��Ҫ��ȡ��ѹ���ļ�:%s\n", filename);
    fread(&flength, sizeof(long), 1, ifp);                                    //��ȡԭ�ļ���
    fread(&f, sizeof(long), 1, ifp);
    fseek(ifp, f, SEEK_SET);
    fread(&n, sizeof(long), 1, ifp);                                          //��ȡԭ�ļ�������
    for (i = 0; i < n; i++)                                                  //��ȡѹ���ļ����ݲ�ת���ɶ�������
    {
        fread(&header[i].b, 1, 1, ifp);
        fread(&c, 1, 1, ifp);
        p = (long)c;
        header[i].count = p;
        header[i].bits[0] = 0;
        if (p % 8 > 0) m = p / 8 + 1;
        else m = p / 8;
        for (j = 0; j < m; j++)
        {
            fread(&c, 1, 1, ifp);
            f = c;
            _itoa(f, buf, 2);
            f = strlen(buf);
            for (l = 8; l > f; l--)
            {
                strcat(header[i].bits, "0");                                  //λ�����㣬ִ�в������
            }
            strcat(header[i].bits, buf);
        }
        header[i].bits[p] = 0;
    }

    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (strlen(header[i].bits) > strlen(header[j].bits))
            {
                tmp = header[i];
                header[i] = header[j];
                header[j] = tmp;
            }
        }
    }

    p = strlen(header[n - 1].bits);
    fseek(ifp, 8, SEEK_SET);
    m = 0;
    bx[0] = 0;


    while (1)
    {
        while (strlen(bx) < (unsigned int)p)
        {
            fread(&c, 1, 1, ifp);
            f = c;
            _itoa(f, buf, 2);
            f = strlen(buf);
            for (l = 8; l > f; l--)
            {
                strcat(bx, "0");
            }
            strcat(bx, buf);
        }
        for (i = 0; i < n; i++)
        {
            if (memcmp(header[i].bits, bx, header[i].count) == 0) break;
        }
        strcpy(bx, bx + header[i].count);
        c = header[i].b;
        fwrite(&c, 1, 1, ofp);
        m++;

        if (m == flength) break;
    }
    fclose(ifp);
    fclose(ofp);
    printf("��ѹ�ɹ�\n��ѹ���ļ�Ϊ:%s\n", out_filename);
    return 1;                   //����ɹ���Ϣ
}

int main(void)
{
    using namespace std;
    memset(&header, 0, sizeof(header));
    memset(&tmp, 0, sizeof(tmp));

    int fun;
    printf("		                      ��������Ҫ����                                       \n");
    cin >> fun;//fun��ֵ�����ǽ�ѹ�ļ�����ѹ���ļ�
   
    while (fun != 0 && fun != 1)
    {
        cout << "�������" << endl;
        cin >> fun;
    }
    while (fun == 0)
    {
        compress("��ҵ.txt", "ѹ���ļ�.txt.rar");
        return 0;
    }
    while (fun == 1) 
    {
        uncompress("ѹ���ļ�.txt.rar", "��ѹ��.txt"); 
        return 0;
    } 
}