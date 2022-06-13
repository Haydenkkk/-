#include "compare.h"

int main() {
    int fun;
   
    Start S;
    printf("		                      请输入文件类型 0bmp/1txt                                       \n");
    cin >> fun;         

    while (fun != 00 && fun != 10 && fun != 01 && fun != 11)
    {
        cout << "输入错误" << endl;
        cin >> fun;
    }

    switch (fun) {
    case 0:S.flag1= S.compare_file("比较文件1.bmp", "比较文件2.bmp");
        break;

    case 1: S.flag2= S.compare_file("比较文件1.txt", "比较文件2.txt");
        break;
    }

    if (S.flag1) {
        cout << "		                      存在重复文件                                       \n";
        if (remove("比较文件2.bmp") == 0)   
            cout << "		                      已删除重复文件                                       \n";
        else cout << "		                      删除重复文件失败                                       \n";
        return 0;
    }

    if (S.flag2) {
        cout << "		                      存在重复文件                                       \n";
        if (remove("比较文件2.txt") == 0)
            cout << "		                      已删除重复文件                                       \n";
        else cout << "		                      删除重复文件失败                                       \n";
        return 0;
    }
    cout << "		                      两文件不重复或已有文件丢失                                       \n";
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
    cout << file2 << ":succeed" << endl;//判断文件是否存在
    
    f1.seekg(0, ios::end);
    int size_f1 = f1.tellg();
    f2.seekg(0, ios::end);
    int size_f2 = f2.tellg();
    if (size_f1 != size_f2) return false;//比较文件中字符长度是否相等

   f1.clear();
   f1.seekg(0, ios::beg);
   f2.clear();
   f2.seekg(0, ios::beg);//回到开头位置

   f1 >> ff;
   f2 >> fs;
    while (!f1.eof())//两文件长度相同，就用f1为例
    {

        if (ff != fs) return false;
        f1 >> ff;
        f2 >> fs;
    }
    f1.close();
    f2.close();

    return true;


}