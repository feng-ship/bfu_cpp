#include<iostream>
#include<cmath>
using namespace std;
class Point2{
public:
    double x;
    double y;
    Point2(double p1,double p2){
        x=p1;
        y=p2;
    }
};
class Line2{
private:
    Point2 pt1,pt2;
public:
    Line2(Point2 p1,Point2 p2):pt1(p1),pt2(p2){};
    double Length(){
        double temp=0;
        temp+=pow((pt1.x-pt2.x),2)+pow((pt1.y-pt2.y),2);
        return sqrt(temp);
    }
};
int main()
{
    Point2 pt1(1.0, 1.0);
    Point2 pt2(3.0, 4.0);
    Line2 line(pt1, pt2);
    std::cout << line.Length() << std::endl;

    double x1,y1, x2, y2;
    std::cin >> x1 >> y1 >> x2 >> y2;
    Line2 nLine(Point2(x1, y1), Point2(x2, y2));
    std::cout << nLine.Length()<< std::endl;

    return 0;
}
