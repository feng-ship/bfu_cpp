#include <iostream>
#include <string>
using namespace std;
int main(){
    //容量与大小//
    string str1="Hello";
    cout<<str1.size();
    cout<<str1.length();//两者等价
    cout<<str1.empty();
    str1.clear();
    cout<<str1.size();
    
    //元素访问//
    string str2="Apple";
    char c1=str2[0];//'A'
    char c2=str2.at(1);//'P',会进行边界检查
    str2[0]='a';
    char last=str2.back();
    char front=str2.front();
    
    //内容修改//
    string str3="Hello";
    str3+="World";//追加字符串
    str3.append("World");
    cout<<str3<<endl;
    str3.push_back('!');//追加单个字符

    string ins=" C++";
    str3.insert(5,ins,0,ins.size());//插入//或者：str3.insert(5," C++");

    str3.erase(5,4);//"Hello World!" (删除 " C++")

    str3.replace(6,5,"C++");//"Hello C++!" (将 "World" 替换为 "C++")

    str3.assign("abc");//整个替换
    cout<<str3<<endl;

    
    //查找与子串//
    string text = "I love C++ and C++ loves me.";

    // 1. 查找
    size_t pos1 = text.find("C++"); 
    // pos1 为 7

    // 2. 检查是否找到
    if (text.find("Java") == std::string::npos) {
        cout << "Not found!\n";
    }

    // 3. 提取子串
    string sub = text.substr(7, 3); 
    // sub 为 "C++"
    //典例：提取文件后缀名
    string file="photo.jpg";
    size_t pos=file.find(".");
    string ext=file.substr(pos+1);
    cout<<ext<<endl;
    //比较字符串
    string a="apple";
    string b="banana";
    cout<<a.compare(b)<<endl;

    //交换
    string A="hello";
    string B="world";
    A.swap(B);
    cout<<A<<endl;
    cout<<B<<endl;
}