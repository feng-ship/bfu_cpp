#include<iostream>
using namespace std;
class Base{
public:
    Base(){};
    virtual ~Base(){
        cout<<"执行基类的析构函数"<<endl;
    }
    virtual void show(){
        cout<<"执行基类的show函数"<<endl;
    }
};
class Derived:public Base{
public:
    Derived(){};
    virtual ~Derived(){
        cout<<"执行派生类的析构函数"<<endl;
    }
    void show(){
        cout<<"执行派生类的show函数"<<endl;
    }
};
int main(){
    Base *p=new Derived;
    p->show();
    delete p;
    return 0; 
}