#include<iostream>
#include<cstring>
using namespace std;
class Point{
private:
    double x;
    double y;
public:
    Point(double a,double b);
    void display();
};
Point::Point(double a,double b){
    x=a;
    y=b;
} 
void Point::display(){
    cout<<"x="<<x<<",y="<<y<<endl;
}
int main(){
    Point t1(100,200);
    t1.display();
    return 0;
}
