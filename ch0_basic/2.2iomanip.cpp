#include<iomanip>
#include<iostream>
using namespace std;
int main(){
    double x=3.1415926;
    cout<<fixed<<setprecision(2)<<x<<endl;
    cout<<setw(5)<<3.14<<endl;//设置宽度，默认右对齐
    int a=21,b=999;
    cout<<setw(3)<<a<<setw(4)<<a<<setw(5)<<a<<endl;
    cout<<setw(3)<<setfill('#')<<a<<setw(4)<<a<<setw(5)<<hex<<a<<endl;
    float pi=3.14159;
    cout<<setw(8)<<setfill('$')<<setprecision(4)<<setiosflags(ios::left)<<pi<<endl;
    return 0;
}