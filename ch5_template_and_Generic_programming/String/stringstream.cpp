#include <iostream>
#include <string>
#include<sstream>
using namespace std;
int main(){
    string name;
    int age;
    double height;
    string inputLine;
    cout<<"请在一行内输入您的 姓名、年龄、身高（用空格隔开）:\n";
    // 2. 从键盘读取用户输入的【一整行】字符串
    getline(cin,inputLine);
    // 3. 将这一整行字符串“喂”给 stringstream 做解析
    stringstream ssParse(inputLine);
    // 安全地从流中提取数据
    ssParse>>name>>age>>height;
    // 4. 再次用 stringstream 格式化输出
    stringstream ssOutput;
    ssOutput<<"Name:"<<name<<"\n"<<"Age:"<<age<<"\n"<<"Height:"<<height<<"m"<<"\n";
    cout<<ssOutput.str()<<"\n";
    return 0;
}