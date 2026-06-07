#include<iostream>
#include<algorithm>
#include<string>
#include<iterator>
#include<vector>
using namespace std;
int main(){
    typedef vector<string> string_vector;
    typedef istream_iterator<string> input;
    typedef back_insert_iterator<string_vector> ins;
    typedef ostream_iterator<string> output;
    string_vector vec(10);
    cout<<"请输入若干个字符串,以-1结束:"<<endl;
    int i;
    for(i=0;i<(int)vec.size();i++){
        cin>>vec[i];
        if(vec[i]=="-1") break;
    }
    cout<<"输入的"<<i<<"个字符串为:"<<endl;
    copy(vec.begin(),vec.end(),output(cout," "));
    cout<<endl;
    cout<<"请输入要查找的字符串:"<<endl;
    string str;
    cin>>str;
    vector<string>::iterator it;
    it=find(vec.begin(),vec.end(),str);
    if(it!=vec.begin()+i){
        cout<<"该字符串存在:"<<*it<<endl;
    }else{
        cout<<"该字符串不存在"<<endl;
    }
    return 0;
}