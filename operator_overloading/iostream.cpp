#include<iostream>
using namespace std;
class Complex{
private:
    int real;
    int imag;
public:
    Complex(int r=0,int i=0){
        real=r;
        imag=i;
    }
    friend istream& operator>>(istream& is,Complex &c1);
    friend ostream& operator<<(ostream& os,const Complex &c2);
};
istream& operator>>(istream& is,Complex &c1){
    is>>c1.real>>c1.imag;
    return is;
}
ostream& operator<<(ostream& os,const Complex &c2){
    os<<c2.real<<"+"<<c2.imag<<"i";
    return os;
}
int main(){
    Complex c;
    cin>>c;
    cout<<c;
    return 0;
}