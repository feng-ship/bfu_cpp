#include<iostream>
using namespace std;
class Rectangle{
private:
    double length;
    double width;
public:
    Rectangle(double Length=10.,double Width=5.);
    double Area() const;
    double Perimeter() const;
};
Rectangle::Rectangle(double Length,double Width){
    length=Length;
    width=Width;
}
double Rectangle::Area() const{
    return length*width;
}
double Rectangle::Perimeter() const{
    return 2*(length+width);
}
double zhalan_price(double len){
    return len*50;
}
double guodao_price(double area){
    return area*240;
}
int main(){
    double len=0,wid=0;
    cin>>len>>wid;
    Rectangle zhalan(len+3,wid+3);
    Rectangle gym(len,wid);
    double zha_price=0,guo_price=0;
    zha_price=zhalan_price(zhalan.Perimeter());
    guo_price=guodao_price(zhalan.Area()-gym.Area());
    cout<<zha_price<<endl;
    cout<<guo_price<<endl;
    return 0;
}