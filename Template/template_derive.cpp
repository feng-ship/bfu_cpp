#include<iostream>
using namespace std;
template<class T>
class Point{
private:
    T x;
    T y;
public:
    Point(T a,T b);
    void show();
};
template<class T>
Point<T>::Point(T a,T b){
    x=a;
    y=b;
}
template<class T>
void Point<T>::show(){
    cout<<"("<<x<<","<<y<<")"<<endl;
}
template<class T>
class Rectangle:public Point<T>{
private:
    T length;
    T width;
    T height;
public:
    Rectangle(T a,T b,T c,T x1,T y1);
    void show();
};
template<class T>
Rectangle<T>::Rectangle(T a,T b,T c,T x1,T y1):Point<T>(x1,y1){
    length=a;
    width=b;
    height=c;
}
template<class T>
void Rectangle<T>::show(){
    cout<<"左上角坐标为"<<":";
    Point<T>::show();
    cout<<"长度为:"<<length<<" "<<"宽度为:"<<width<<" "<<"高度为:"<<height<<endl;
}
int main() {
    // 创建一个长宽高为 10.5, 5.2, 2.0，左上角坐标为 (0.0, 0.0) 的矩形/长方体
    Rectangle<double> rect(10.5, 5.2, 2.0, 0.0, 0.0);
    rect.show();
    return 0;
}