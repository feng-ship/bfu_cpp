#include<iostream>
#include<algorithm>
#include<list>
#include<vector>
#include<ctime>
using namespace std;
template<class T>
void print(T elem){
    cout<<elem<<" ";
}
int main(){
    srand(time(0));//埋下随机数种子！！
    list<int> l;
    vector<double> v;
    for(int i=10;i<15;i++){
        l.push_back(i);
    }
    for_each(l.begin(),l.end(),print<int>);
    cout<<endl;
    for_each(l.rbegin(),l.rend(),print<int>);
    cout<<endl;
    for(int i=0;i<5;i++){
        v.push_back(rand()%101);//产生a~b的随机是：rand()%(b-a+1)+a;
    }
    for_each(v.begin(),v.end(),print<double>);
    cout<<endl;
    return 0;
}