#include<iostream>
using namespace std;
template<typename T>
class Box{
private:
    T data;
public:
    void set(T d){
        data=d;
    }
    T get(){
        return data;
    }
};
int main(){
    Box<int> b1;
    b1.set(10);
    cout<<b1.get()<<endl;
    Box<string> b2;
    b2.set("hello world");
    cout<<b2.get()<<endl;
    return 0;
}