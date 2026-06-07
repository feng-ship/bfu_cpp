#include<iostream>
#include<iterator>
using namespace std;
int main(){
    int a,s=0;
    istream_iterator<int> ins(cin);//定义输入流迭代器ins，并绑定到cin
    istream_iterator<int> eof;
    ostream_iterator<int> out(cout," ");
    while(ins!=eof){
        a=*ins;
        s+=a;
        ins++;
    }
    *out=s;
    cout<<endl;
    return 0;
}