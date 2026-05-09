#include<iostream>
#include<sstream>
#include<string>
using namespace std;
int main(){
    // istringstream：从字符串读取数据
    string s1="123 45.6 hello";
    istringstream iss(s1);
    int a;
    double b;
    string c;
    iss>>a>>b>>c;
    cout<<a<<endl;
    cout<<b<<endl;
    cout<<c<<endl;
    cout << "-------------------" << endl;

    // ostringstream：向字符串写入数据
    ostringstream oss;
    oss<<123<<" hello "<<3.14;
    string s2=oss.str();
    cout<<s2<<endl;
    cout << "-------------------" << endl;

    // stringstream：既能写又能读
    stringstream ss;
    ss<<100<<" "<<200;
    int x,y;
    ss>>x>>y;
    cout<<x+y<<endl;
    cout << "-------------------" << endl;

    // 字符串转数字
    string s3="123";
    stringstream ss2(s3);
    int n;
    ss2>>n;
    cout<<n+1<<endl;
    cout << "-------------------" << endl;

    // 数字转字符串
    int num=456;
    stringstream ss3;
    ss3<<num;
    string s4=ss3.str();
    cout<<s4<<endl;

    cout << "-------------------" << endl;

    // clear() 和 str("")
    stringstream ss4("789");

    int t;

    ss4 >> t;

    cout << t << endl;

    ss4 >> t; // 失败

    ss4.clear();

    ss4.str("999");

    ss4 >> t;

    cout << t << endl;

    return 0;
}