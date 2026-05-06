#include<iostream>
using namespace std;
class Rectangle{
protected:
    int length;
    int width;
public:
    void set1(int l,int w);
};
void Rectangle::set1(int l,int w){
    length=l;
    width=w;
}
class Cuboid:public Rectangle{
private:
    int height;
public:
    void set2(int h);
    void show();
};
void Cuboid::set2(int h){
    height=h;
}
void Cuboid::show(){
    cout<<"长度:"<<length<<endl;
    cout<<"宽度:"<<width<<endl;
    cout<<"高度:"<<height<<endl;
}
int main(){
    int le=0,wi=0,he=0;
    cin>>le>>wi>>he;
    Cuboid c1;
    c1.set1(le,wi);//注意要对c1操作
    c1.set2(he);
    c1.show();
    return 0;
}