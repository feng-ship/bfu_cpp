#include<iostream>
using namespace std;
class Complex{
private:
    int real;
    int imag;
public:
    Complex(int r,int i);
    Complex operator+(Complex &c){
        return Complex(real+c.real,imag+c.imag);
    }
    void show();
};
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
    c1.show();
    c2.show();
    return 0;
}
