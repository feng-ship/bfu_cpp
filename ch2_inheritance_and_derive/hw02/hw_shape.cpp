#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
const double pi = acos(-1);
class Shape {
public:
    Shape() {}
    virtual double area() = 0;
    virtual void input() = 0;
    virtual double volume() = 0;
    virtual ~Shape() {}
};
class Cuboid:public Shape{
private:
    int length;
    int width;
    int height;
public:
    void input();
    double volume();
    double area();
    ~Cuboid(){};
};
void Cuboid::input(){
    cin>>length>>width>>height;
}
double Cuboid::volume(){
    return length*width*height;
}
double Cuboid::area(){
    return 2*(length*width+length*height+width*height);
}
class Cylinder:public Shape{
private:
    int r;
    int height;
public:
    void input();
    double volume();
    double area();
};
void Cylinder::input(){
    cin>>r>>height;
};
double Cylinder::volume(){
    return pi*r*r*height;
}
double Cylinder::area(){
    return 2*pi*r*r+2*pi*r*height;
}
class Ball:public Shape{
private:
    int r;
public:
    void input();
    double volume();
    double area();
};
void Ball::input(){
    cin>>r;
}
double Ball::volume(){
    return 4*pi*r*r*r/3;
}
double Ball::area(){
    return 4*pi*r*r;
}
void work(Shape *s) {
    s->input();
    cout << s->area() << " " << s->volume() << endl;
    delete s;
}
int main() {
    char c;
    while (cin >> c) {
        switch (c) {
            case 'y': 
            work(new Cylinder());
            break;
            case 'c':
            work(new Cuboid());
            break;
            case 'q':
            work(new Ball()); 
            break;
            default:
            break;
        }
    }
    return 0;
}


