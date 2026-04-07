#include<iostream>
using namespace std;
class Rectangle{
protected:
    int length;
    int width;
public:
    Rectangle(int len,int wid):length(len),width(wid){};
};
class Cuboid:public Rectangle{
private:
    int height;
public:
    Cuboid(int le,int wi,int he):Rectangle(le,wi),height(he){};//调用基类的构造函数
    void show();
};
void Cuboid::show(){
    cout<<"长度:"<<length<<endl;
    cout<<"宽度:"<<width<<endl;
    cout<<"高度:"<<height<<endl;
}
int main(){
    Cuboid c1(3,4,6);
    c1.show();
    return 0;
}