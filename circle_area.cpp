#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
const double PI=acos(-1.0);
class Circle
{
private:
    double r;
public:
    void input();
    double area() const;
    void output() const;
};
void Circle::input(){
    cin>>r;
}
double Circle::area() const{
    return PI*r*r;
}
void Circle::output() const{
    cout<<setiosflags(ios::fixed)<<setprecision(2)<<area()<<endl;
}
int main(){
    Circle c1;
    c1.input();
    c1.output();
    return 0;
}