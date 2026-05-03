#include <iostream>
#include<cmath>
using namespace std;
template<typename T>
class Vector
{
private:
    T x, y, z;
public:
    Vector(T a=0,T b=0,T c=0);
    Vector(const Vector<T> &v);
    friend Vector<T> operator+(const Vector<T> &v1,const Vector<T> &v2){
        Vector<T> v3;
        v3.x=v1.x+v2.x;
        v3.y=v1.y+v2.y;
        v3.z=v1.z+v2.z;
        return v3;
    }
    friend Vector<T> operator*(double d,const Vector<T> &v1){
        Vector<T> v3;
        v3.x=d*v1.x;
        v3.y=d*v1.y;
        v3.z=d*v1.z;
        return v3;
    }
    friend bool operator==(const Vector<T> &v1,const Vector<T> &v2){
        double epsilon = 1e-6; 
        return (abs(v1.x - v2.x) < epsilon && 
                abs(v1.y - v2.y) < epsilon && 
                abs(v1.z - v2.z) < epsilon);
    }
    friend istream& operator>>(istream &is,Vector<T> &v1){
        is>>v1.x>>v1.y>>v1.z;
        return is;
    }
    friend ostream& operator<<(ostream &os,const Vector<T> &v1){
        os<<v1.x<<" "<<v1.y<<" "<<v1.z;
        return os;
    }
};
template<typename T>
Vector<T>::Vector(T a,T b,T c){
    x=a;
    y=b;
    z=c;
}
template<typename T>
Vector<T>::Vector(const Vector &v):x(v.x),y(v.y),z(v.z){}
int main()
{
    double a, b, c;
    std::cin >> a >> b >> c;
    Vector<double> v1(a, b, c), v2(v1), v3, v4;
    double d;
    std::cin >> d;
    v4 = d * v1 + v2;

    std::cout << v4 <<std::endl;

    Vector<double>  v;
    std::cin >> v;

    int flag = (v4 == v);
    std::cout << flag << std::endl; 

    return 0;
}