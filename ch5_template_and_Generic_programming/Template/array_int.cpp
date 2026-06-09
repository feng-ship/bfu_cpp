#include<iostream>
using namespace std;
template<class T,int N>
void array_init(T (&parm)[N]){
    for(int i=0;i<N;i++){
        parm[i]=(T)i;
    }
}
int main(){
    int x[5];
    double y[10];
    array_init(x);
    array_init(y);
    for(int i=0;i<5;i++){
        cout<<x[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<10;i++){
        cout<<y[i]<<" ";
    }
    cout<<endl;
    return 0;
}