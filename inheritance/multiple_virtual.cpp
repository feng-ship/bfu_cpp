#include<iostream>
using namespace std;
class B{
protected:
    int b;
public:
    B(int bval);
};
B::B(int bval){
    b=bval;
}
class D1: virtual public B{
protected:
    int d1;
public:
    D1(int bval,int d1val);
};
D1::D1(int bval,int d1val):B(bval){
    d1=d1val;
}
class D2:virtual public B{
protected:
    int d2;
public:
    D2(int bval,int d2val);
};
D2::D2(int bval,int d2val):B(bval){
    d2=d2val;
}
class D3:public D2,public D1{
protected:
    int d3;
public:
    D3(int bval,int d1val,int d2val,int d3val);
    void show();
};
D3::D3(int bval,int d1val,int d2val,int d3val):D2(bval,d2val),D1(bval,d1val),B(bval){
    d3=d3val;
}
void D3::show(){
    cout<<"成员b的值:"<<b<<endl;
    cout<<"成员d1的值:"<<d1<<endl;
    cout<<"成员d2的值:"<<d2<<endl;
    cout<<"成员d3的值:"<<d3<<endl;
}
int main(){
    D3 obj3(3,6,8,9);
    obj3.show();
    return 0;
}