#include<iostream>
using namespace std;
template<class T,int N>
class Stack{
private:
    T s[N];
    int top;
public:
    Stack();
    bool isfull();
    bool isempty();
    void push(const T &data);
    void pop();
};
template<class T,int N>
Stack<T,N>::Stack(){
    top=-1;
}
template<class T,int N>
bool Stack<T,N>::isfull(){
    return (top==N-1);
}
template<class T,int N>
bool Stack<T,N>::isempty(){
    return (top<0);
}
template<class T,int N>
void Stack<T,N>::push(const T &data){
    if(!isfull()){
        top=top+1;
        s[top]=data;
    }else{
        cout<<"栈溢出!"<<endl;
    }
}
template<class T,int N>
void Stack<T,N>::pop(){
    if(!isempty()){
        cout<<"出栈元素:"<<s[top]<<endl;
        top=top-1;
    }else{
        cout<<"栈是空的!"<<endl;
    }
}
int main(){
    Stack<string,5>s1;
    s1.push("hello");
    s1.push("world");
    s1.push("!");
    s1.pop();
    s1.pop();
    s1.pop();
    s1.pop();
    return 0;
}