#include<iostream>
using namespace std;
class Base{
protected:
    int b;
public:
    Base(int n);
    ~Base();
};
Base::Base(int n){
    b=n;
    cout<<"执行基类的构造函数"<<endl;
}
Base::~Base(){
    cout<<"执行基类的析构函数"<<endl;
}
class A{
protected:
    int a;
public:
    A(int m);
    ~A();
};
A::A(int m){
    a=m;
    cout<<"执行子对象的构造函数"<<endl;
}
A::~A(){
    cout<<"执行子对象的析构函数"<<endl;
}
class Derive:public Base{
protected:
    A aobj;
    int d;
public:
    Derive(int p,int q,int k);
    ~Derive();
};
Derive::Derive(int p,int q,int k):aobj(p),Base(q){
    d=k;
    cout<<"执行派生类的构造函数"<<endl;
}
Derive::~Derive(){
    cout<<"执行派生类的析构函数"<<endl;
}
int main(){
    Derive de(3,6,7);
    return 0;
}

