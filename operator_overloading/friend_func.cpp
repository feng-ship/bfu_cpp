#include<iostream>
using namespace std;
class Complex{
private:
    int real;
    int imag;
public:
    Complex(int r=0,int i=0);
    friend Complex operator-(Complex &c1,Complex &c2);
    void show();
};
Complex operator-(Complex &c1,Complex &c2){
    Complex temp;
    temp.real=c1.real-c2.real;
    temp.imag=c1.imag-c2.imag;
    return Complex(temp.real,temp.imag);
    }
Complex::Complex(int r,int i){
    real=r;
    imag=i;
}
void Complex::show(){
    if(imag>=0){
        cout<<real<<"+"<<imag<<"i"<<endl;
    }else{
        cout<<real<<"-"<<-imag<<"i"<<endl;
    }
}
int main(){
    Complex c1(3,-4);
    Complex c2(5,7);
    Complex c3;
    c3=operator-(c1,c2);
    c1.show();
    c2.show();
    c3.show();
    return 0;
}
