#include<iostream>
using namespace std;
class Complex{
private:
    double x;
    double y;
public:
    Complex(double x = 0.0, double y = 0.0);
    Complex & operator+=(const Complex &);
    Complex & operator-=(const Complex &);
    Complex & operator*=(const Complex &);
    Complex & operator/=(const Complex &);
    friend Complex operator+(const Complex &, const Complex &);
    friend Complex operator-(const Complex &, const Complex &);
    friend Complex operator*(const Complex &, const Complex &);
    friend Complex operator/(const Complex &, const Complex &);
    friend bool operator==(const Complex &, const Complex &);
    friend bool operator!=(const Complex &, const Complex &);
    friend ostream & operator<<(ostream &, const Complex &);
    friend istream & operator>>(istream &, Complex &);
};
Complex::Complex(double x, double y){
    this->x=x;
    this->y=y;
}
Complex& Complex::operator+=(const Complex &c2){
    x+=c2.x;
    y+=c2.y;
    return *this;
}
Complex& Complex::operator-=(const Complex &c2){
    x-=c2.x;
    y-=c2.y;
    return *this;
}
Complex& Complex::operator*=(const Complex &c2){
    double temp_x;
    temp_x=x;
    x=x*c2.x-y*c2.y;
    y=temp_x*c2.y+y*c2.x;
    return *this;
}
Complex& Complex::operator/=(const Complex &c2){
    double temp_x;
    temp_x=x;
    x=(x*c2.x+y*c2.y)/(c2.x*c2.x+c2.y*c2.y);
    y=(y*c2.x-temp_x*c2.y)/(c2.x*c2.x+c2.y*c2.y);
    return *this;
}
Complex operator+(const Complex &c1, const Complex &c2){
    Complex c3;
    c3.x=c1.x+c2.x;
    c3.y=c1.y+c2.y;
    return c3;
}
Complex operator-(const Complex &c1, const Complex &c2){
    Complex c3;
    c3.x=c1.x-c2.x;
    c3.y=c1.y-c2.y;
    return c3;
}
Complex operator*(const Complex &c1, const Complex &c2){
    Complex c3;
    c3.x=c1.x*c2.x-c1.y*c2.y;
    c3.y=c1.x*c2.y+c1.y*c2.x;
    return c3;
}
Complex operator/(const Complex &c1, const Complex &c2){
    Complex c3;
    c3.x=(c1.x*c2.x+c1.y*c2.y)/(c2.x*c2.x+c2.y*c2.y);
    c3.y=(c1.y*c2.x-c1.x*c2.y)/(c2.x*c2.x+c2.y*c2.y);
    return c3;
}
bool operator==(const Complex &c1, const Complex &c2){
    return(c1.x==c2.x&&c1.y==c2.y);
}
bool operator!=(const Complex &c1, const Complex &c2){
    return!(c1.x==c2.x&&c1.y==c2.y);
}
istream & operator>>(istream &is, Complex &c1){
    is>>c1.x>>c1.y;
    return is;
}
ostream & operator<<(ostream &os, const Complex &c1){
    os<<c1.x<<" "<<"+"<<" "<<c1.y<<"i";
    return os;
}
int main(){
    Complex c1, c2;
    cin >> c1 >> c2;
    cout << "c1 = " << c1 << "\n" << "c2 = " << c2 << endl;
    cout << "c1+c2 = " << c1 + c2 << endl;
    cout << "c1-c2 = " << c1 - c2 << endl;
    cout << "c1*c2 = " << c1 * c2 << endl;
    cout << "c1/c2 = " << c1 / c2 << endl;
    cout << (c1 += c2) << endl;
    cout << (c1 -= c2) << endl;
    cout << (c1 *= c2) << endl;
    cout << (c1 /= c2) << endl;
    cout << (c1 == c2) << " " << (c1 != c2) << endl;
    return 0;
}



