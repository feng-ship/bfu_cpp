#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    int N,Q;
    while(cin>>N>>Q){
        if(N==0&&Q==0){
            break;
        }
        vector<int> num(N);
        for(int i=0;i<N;i++){
            cin>>num[i];
        }
        sort(num.begin(),num.end());
        while(Q--){
            int point;
            cin>>point;
            auto it=lower_bound(num.begin(),num.end(),point);
            if(it!=num.end()&&*it==point){
                cout<<point<<" "<<"found at "<<distance(num.begin(),it)+1<<endl;
            }else{
                cout<<point<<" not found "<<endl;
            }
        }
    }
    return 0;
}