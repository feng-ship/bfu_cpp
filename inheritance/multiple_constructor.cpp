#include<iostream>
using namespace std;
class Base1{
protected:
    int a;
public:
    Base1(int p);
    ~Base1();
};
Base1::Base1(int p){
    a=p;
    cout<<"执行基类1的构造函数"<<endl;
}

class