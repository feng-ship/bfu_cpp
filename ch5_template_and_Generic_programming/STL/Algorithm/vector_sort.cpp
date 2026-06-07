#include<iostream>
#include<vector>
#include<iterator>
#include<algorithm>
using namespace std;
int main(){
    typedef istream_iterator<int> input;
    typedef vector<int> int_vector;
    typedef ostream_iterator<int> output;
    typedef back_insert_iterator<int_vector> ins;
    cout<<"请输入若干个整型数据:"<<endl;
    int_vector vec;
    copy(input(cin),input(),ins(vec));
    sort(vec.begin(),vec.end());
    copy(vec.begin(),vec.end(),output(cout," "));
    cout<<endl;
    return 0;
}