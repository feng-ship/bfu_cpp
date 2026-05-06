#include<iostream>
using namespace std;
class Shape{
    //类体内声明纯虚函数的类，称为抽象类
public:
    virtual void tell_shape()=0;
    //纯虚函数
    virtual void area()=0;
};
class Point:public Shape{
private:
    double x;
    double y;
public:
    Point(double a,double b){
        x=a;
        y=b;
    }
    void tell_shape(){
        cout<<"点:"<<"("<<x<<","<<y<<")"<<endl;
    }
    void area(){
        cout<<"点的面积是:0"<<endl;
    }
    double getx(){
        return x;
    }
    double gety(){
        return y;
    }
};
class Circle:public Point{
private:
    double r;
public:
    Circle(double ca,double cb,double cr):Point(ca,cb){
        r=cr;
    }
    void area(){
        cout<<"圆的面积是:"<<3.14*r*r<<endl;
    }
    void tell_shape(){
        cout<<"这是一个圆,圆心坐标为（"<<getx()<<","<<gety()<<")"<<"半径为"<<r<<endl;
    }
};
class Rectangle:public Point{
private:
    double length;
    double width;
public:
    Rectangle(double ra,double rb,double l,double w):Point(ra,rb){
        length=l;
        width=w;
    }
    void area(){
        cout<<"矩形面积为:"<<length*width<<endl;
    }
    void tell_shape(){
        cout<<"这是一个矩形，左上角顶点坐标为("<<getx()<<","<<gety()<<")"<<"长度为:"<<length<<"宽度为:"<<width<<endl;
    }
};
void show(Shape *p){
    //统一接口
    //或者：void show(Shape &s){s.tell_shape()...}
    p->tell_shape();
    p->area();
}
int main(){
    Circle c1(3,4,6);
    Rectangle r1(8,9,4,5);
    show(&c1);
    //或者:show(c1)
    show(&r1);
    return 0;
}