#include<iostream>
#include<string>
#include<vector>
#include<functional>
#include<algorithm>
using namespace std;
bool cmp(string x,string y){
        return x>y;
    }
int main(){
    int N;
    cin>>N;
    vector<string> v1;
    while(N--){
        string s;
        cin>>s;
        sort(s.begin(),s.end());
        v1.push_back(s);
    }
    sort(v1.begin(),v1.end(),cmp);
    for(int i=0;i<v1.size();i++){
        cout<<v1[i]<<endl;
    }
    return 0;
}