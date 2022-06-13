#include "compare.h"

int main() {
    int fun;
   
    Start S;
    printf("		                      �������ļ����� 0bmp/1txt                                       \n");
    cin >> fun;         

    while (fun != 00 && fun != 10 && fun != 01 && fun != 11)
    {
        cout << "�������" << endl;
        cin >> fun;
    }

    switch (fun) {
    case 0:S.flag1= S.compare_file("�Ƚ��ļ�1.bmp", "�Ƚ��ļ�2.bmp");
        break;

    case 1: S.flag2= S.compare_file("�Ƚ��ļ�1.txt", "�Ƚ��ļ�2.txt");
        break;
    }

    if (S.flag1) {
        cout << "		                      �����ظ��ļ�                                       \n";
        if (remove("�Ƚ��ļ�2.bmp") == 0)   
            cout << "		                      ��ɾ���ظ��ļ�                                       \n";
        else cout << "		                      ɾ���ظ��ļ�ʧ��                                       \n";
        return 0;
    }

    if (S.flag2) {
        cout << "		                      �����ظ��ļ�                                       \n";
        if (remove("�Ƚ��ļ�2.txt") == 0)
            cout << "		                      ��ɾ���ظ��ļ�                                       \n";
        else cout << "		                      ɾ���ظ��ļ�ʧ��                                       \n";
        return 0;
    }
    cout << "		                      ���ļ����ظ��������ļ���ʧ                                       \n";
    return 0;
}

bool Start:: compare_file(string file1, string file2) {
    ifstream f1(file1, ios::in);
    ifstream f2(file2, ios::in);
    

    if (!f1.good())
    {
        cout << file1 << ": not exist" << endl;
        return false;
    }
    cout << file1 << ":succeed" << endl;
    
    if (!f2.good())
    {
        cout << file2 << ": not exist" << endl;
        return false;
    }
    cout << file2 << ":succeed" << endl;//�ж��ļ��Ƿ����
    
    f1.seekg(0, ios::end);
    int size_f1 = f1.tellg();
    f2.seekg(0, ios::end);
    int size_f2 = f2.tellg();
    if (size_f1 != size_f2) return false;//�Ƚ��ļ����ַ������Ƿ����

   f1.clear();
   f1.seekg(0, ios::beg);
   f2.clear();
   f2.seekg(0, ios::beg);//�ص���ͷλ��

   f1 >> ff;
   f2 >> fs;
    while (!f1.eof())//���ļ�������ͬ������f1Ϊ��
    {

        if (ff != fs) return false;
        f1 >> ff;
        f2 >> fs;
    }
    f1.close();
    f2.close();

    return true;


}