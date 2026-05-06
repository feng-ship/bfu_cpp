#include<iostream>
using namespace std;
template<typename T>
class Box{
private:
    T data;
public:
    void set(T d);
    T get(){
        return data;
    }
};
template<typename T>
void Box<T>::set(T d){
    data=d;
}
template<class T=int,int N=5>//默认类型
class Array{
private:
    T arr[N];
public:
    Array();
    void set(T base);
    void show();
};
template<class T,int N>
Array<T,N>::Array(){

}
template<class T,int N>
void Array<T,N>::set(T base){
    for(int i=0;i<N;i++){
        arr[i]=base+(T)i;
    }
}
template<class T,int N>
void Array<T,N>::show(){
    for(int i=0;i<N;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main(){
    Box<int> b1;
    b1.set(10);
    cout<<b1.get()<<endl;
    Box<string> b2;
    b2.set("hello world");
    cout<<b2.get()<<endl;
    Array<int,5> arr1;
    arr1.set(0);
    arr1.show();
    Array<char,5> arr2;
    arr2.set(65);
    arr2.show();
    Array<> arr3;
    arr3.set(0);
    arr3.show();
    return 0;
}