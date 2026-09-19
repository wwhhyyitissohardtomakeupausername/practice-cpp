#include <iostream>
#include <string>
/*1.标准流
cin与cout标准输入输出
cerr与clog输出错误信息(区别:无/有缓冲)
grtline(cin,a);读取包括空格的一整行到a
cin.ignore();通常要清除缓冲区中的\n*/
#include <fstream>
/*2.文件流
ofstream outFile("a.txt");
outFile<<b;
outFile.close();
ifstream inFile("a.txt");
inFile>>b;
inFile.close();*/
#include <sstream>
/*3.字符串流
ostringstream a;
a<<tmp;
istringstream b(str);
b>>tmp;
getline();*/
using namespace std;
/*>>会跳过前导空白,读到空白字符停止,并将那个空白字符留在缓冲区中
>>和<<左边为:对象"*/
int main() {
    ofstream outFile("testfile.txt");
    outFile<<"Let's speak English.\n";
    outFile.flush();        //强行把缓冲区写进磁盘,colse也有此效果
    
    ifstream inFile("testfile.txt");
    string b;
    getline(inFile,b);
    inFile.close();
    
    ostringstream oput;
    istringstream iput(b);
    string tmp;
    while(iput>>tmp) {
        oput<<tmp;
        outFile<<tmp<<'\n';
    }
    outFile<<oput.str();
    outFile.close();
    return 0;
}