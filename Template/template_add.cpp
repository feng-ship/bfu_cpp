#include<iostream>
#include<string>
using namespace std;
template<typename T>
T add(T a,T b){
    return a+b;
}
template<typename T>
T maxvalue(const T &a,const T &b){
    return a>b?a:b;
}
int main(){
    cout<<add(3,5)<<endl;
    cout<<add(2.5,3.1)<<endl;
    cout<<add<double>(3,2.5)<<endl;
    cout<<maxvalue(string("abf"),string("fds"))<<endl;
    return 0;
}